/*
 *  Level.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "Level.h"
#include "Maths.h"

OniLevel::OniLevel() {
	this->header = (LevelHeader *)malloc(sizeof(LevelHeader));
	this->has_raw = false;
	this->has_sep = false;
}

OniLevel::~OniLevel() {
	free(this->header);
	free(this->name);
	free(this->level_path);
	if (this->platform != OPundefined) {
		if (this->type == DAT) {
			free(this->raw_path);
			if (this->platform == DemoMac)
				free(this->sep_path);
		}
		free(this->instance_descriptors);
		free(this->name_descriptors);
		free(this->template_descriptors);
		free(this->data_table);
		free(this->names_table);
	}
}

bool OniLevel::LoadPath(char *path) {
	bool status = false;
	FILE *file_ = fopen(path,"rb");
	if (file_) {
		char *pos;
		char path_delimiter;
		#ifdef _WIN32
			path_delimiter = '\\';
		#else
			path_delimiter = '/';
		#endif
		pos = strrchr(path, path_delimiter)+1;
		int32_t p_length = (int32_t)(pos-path);
		this->name = (char *)malloc(sizeof(char)*p_length);
		memcpy(this->name, &path[p_length], (strlen(path)-(pos-path)));
		
		this->level_path = (char *)malloc(sizeof(char)*strlen(path));
		strcpy(this->level_path, path);
		
		size_t read_length = fread(this->header,sizeof(LevelHeader),1,file_);
		if (read_length) {
			if (this->header->checksum == DemoMacPlatformChecksum) { this->platform = DemoMac; }
			else if (this->header->checksum == PCPlatformChecksum) { this->platform = PC; }
			else { this->platform = OPundefined; }
			
			if (this->platform != OPundefined) {
				if (this->header->version == DATFileVersion) { this->type = DAT; }
				else if (this->header->version == ONIFileVersion) { this->type = ONI; }
				else { this->type = LTundefined; }
				
				if (this->type == DAT) {
					this->raw_path = (char *)malloc(sizeof(char)*strlen(path));
					strncpy(this->raw_path, path, strlen(path)-3);
					strcat(this->raw_path, "raw");
					FILE *raw_ = fopen(this->raw_path, "rb");
					if (raw_)
						this->has_raw = true;
					fclose(raw_);

					if (this->platform == DemoMac) {
						this->sep_path = (char *)malloc(sizeof(char)*strlen(path));
						strncpy(this->sep_path, path, strlen(path)-3);
						strcat(this->sep_path, "sep");
						FILE *sep_ = fopen(this->sep_path, "rb");
						if (sep_)
							this->has_sep = true;
						fclose(sep_);
					}
				}
				
				this->instance_descriptors = (OniInstanceStruct *)malloc(sizeof(OniInstanceStruct)*this->header->instance_count);
				this->name_descriptors = (OniNameStruct *)malloc(sizeof(OniNameStruct)*this->header->name_count);	
				this->template_descriptors = (OniTemplateStruct *)malloc(sizeof(OniTemplateStruct)*this->header->template_count);
				this->data_table = (char *)malloc(sizeof(char)*this->header->data_size);
				this->names_table = (char *)malloc(sizeof(char)*this->header->names_size);
				
				
				read_length = fread(this->instance_descriptors,sizeof(OniInstanceStruct),this->header->instance_count,file_);
				if (read_length != this->header->instance_count) { return status; }
				
				read_length = fread(this->name_descriptors,sizeof(OniNameStruct),this->header->name_count,file_);
				if (read_length != this->header->name_count) { return status; }				
				
				read_length = fread(this->template_descriptors,sizeof(OniTemplateStruct),this->header->template_count,file_);
				if (read_length != this->header->template_count) { return status; }

				fpos_t data_pos = this->header->data_offset;
				fsetpos(file_,&data_pos);
				read_length = fread(this->data_table,sizeof(char)*this->header->data_size,1,file_);
				if (read_length != 1) { return status; }

				fpos_t names_pos = this->header->names_offset;
				fsetpos(file_,&names_pos);
				read_length = fread(this->names_table,sizeof(char)*this->header->names_size,1,file_);
				if (read_length != 1) { return status; }
				
				status = true;
			}
		}
	}
	fclose(file_);
	return status;
}

void OniLevel::LoadTags() {
	if (this->platform != OPundefined) {
		if (!this->tags.empty())
			this->tags.clear();
			
		for (int32_t i = 0; i < this->header->instance_count; i++) {
			OniTag *a_tag = new OniTag;
			a_tag->LoadFrom(&this->instance_descriptors[i], this->data_table, this->names_table);
			if (a_tag->external_data) {
				//a_tag->LoadExternal(this->raw_path, this->sep_path, )
			}
			this->tags.push_back(a_tag);
		}
	}
}

void OniLevel::ExportTagToPath(OniTag *tag, char *path) {
	if (this->platform != OPundefined) {
		if (strcmp(tag->name, "unnamed\0") != 0) {
			if (!this->export_tags.empty())
				this->export_tags.clear();
			
			char *file_path = (char *)malloc(sizeof(char)*(strlen(path)+strlen(tag->name)+6));
			strcpy(file_path, path);
			#ifdef _WIN32
				strcat(file_path, "\\");
			#else
				strcat(file_path, "/");
			#endif
			strcat(file_path, tag->name);
			strcat(file_path, ".oni\0");
			
			FILE *export_tag_file = fopen(file_path, "w+");
			if (export_tag_file) {
				std::cout << file_path << std::endl;
				
				LevelHeader *output_header = this->CreateOniHeader(tag);
				int64_t file_size = this->ComputeFileSize(output_header);				

				uint64_t pos = 0;
								
				char *write_out = (char *)malloc(sizeof(char)*file_size);
				memcpy(write_out, output_header, sizeof(LevelHeader));
				pos = pos + sizeof(LevelHeader);
				
				// write instance descriptors
				for (int32_t i = 0; i < this->export_tags.size(); i++) {
					OniInstanceStruct an_instance = {CharToInt(this->export_tags.at(i).tag->type), this->export_tags.at(i).data_offset, this->export_tags.at(i).names.new_offset, this->export_tags.at(i).tag->GetDataLength(), this->export_tags.at(i).tag->flags};
					memcpy(&write_out[pos], &an_instance, sizeof(OniInstanceStruct));
					pos = pos + sizeof(OniInstanceStruct);
					this->export_tags.at(i).tag->tm_tag->remap.new_id = i+1;
				}
				
				// we need to alphabetize the names. write names descriptors
				
				// write template descriptors
				
				// write data table
				//for (int32_t i = 0; i < this->export_tags.size(); i++) {	
				//}
				
				// write names table
				for (int32_t i = 0; i < this->export_tags.size(); i++) {
					if (strcmp(this->export_tags.at(i).tag->name, "unnamed") != 0) {
						int32_t name_length = strlen(this->export_tags.at(i).tag->name);
						memcpy(&write_out[pos], &this->export_tags.at(i).tag->name, name_length);
						pos = pos + name_length;
						memcpy(&write_out[pos], "\0", 1);
						pos++;
					}
				}
				
				// write raw
				
				
				// write file
				fwrite(write_out, file_size, 1, export_tag_file);
				free(output_header);
				free(write_out);
			}
			fclose(export_tag_file);
			free(file_path);
			
			this->export_tags.clear();
		}
	}
}

void OniLevel::ExportAllTags() {
	if (this->platform != OPundefined) {
		if (!this->tags.empty()) {
			char *temp_ = (char *)malloc(sizeof(char)*(strlen(this->level_path)-4));
			strncpy(temp_, this->level_path, strlen(this->level_path)-4);
			int32_t mkdir_result;
			#ifdef _WIN32
				mkdir_result = _mkdir(temp_);
			#else
				mkdir_result = mkdir(temp_ ,0777);
			#endif
			if (mkdir_result == 0) {
				for (int32_t i = 0; i < this->tags.size(); i++) {
					OniTag *a_tag = this->tags.at(i);					
					this->ExportTagToPath(a_tag, temp_);
				}
			} else {
				std::cout << "Export directory for \"" << this->name << "\" already exists." << std::endl;
			}
			free(temp_);
		}
	}
}

LevelHeader* OniLevel::CreateOniHeader(OniTag *tag) {
	LevelHeader *new_header = (LevelHeader *)malloc(sizeof(LevelHeader));
	new_header->checksum = this->header->checksum;
	new_header->version = ONIFileVersion;
	new_header->signature = this->header->signature;
	
	new_header->instance_count = this->GetInstanceCount(tag);
	new_header->name_count = this->GetNamedCount(tag);
	new_header->template_count = 0; // always zero
	
	new_header->data_offset = new_header->instance_count*20 + new_header->name_count*8 + new_header->template_count*16; 
	new_header->data_size = this->ComputeDataSize(); 
	
	new_header->names_offset = new_header->data_offset + new_header->data_size;
	new_header->names_size = this->ComputeNamesSize();
			
	new_header->raw_offset = new_header->names_offset+new_header->names_size; // end of normal dat file
	new_header->raw_size = this->ComputeRawSize();
	
	new_header->unused[0] = 0;
	new_header->unused[1] = 0;
	
	return new_header;
}

int64_t OniLevel::ComputeFileSize(LevelHeader *level) {
	int64_t total = sizeof(LevelHeader) + level->instance_count*20 + level->name_count*8 + level->template_count*16 + level->data_size + level->names_size + level->raw_size;
	return total;
}

int32_t OniLevel::GetInstanceCount(OniTag *tag) {
	this->export_tags.push_back((Exporter){ExtractLinkNumber(tag->tm_tag->header->res_id), tag, (NameRemapper){0,0}, 0});
	int32_t count = 1;
	if (tag->tm_tag->instance_count) {
		int32_t *instance_ids = tag->tm_tag->GetInstanceIDs();//(int32_t *)malloc(sizeof(int32_t)*tag->tm_tag->instance_count);
		//instance_ids = tag->tm_tag->GetInstanceIDs();
		for (int32_t i = 0; i < tag->tm_tag->instance_count; i++) {
			if (instance_ids[i] != 0) {
				printf("	looking for instance %i\n",instance_ids[i]);
				for (int32_t j = 0; j < this->tags.size(); j++) {
					if (instance_ids[i] == ExtractLinkNumber(this->tags.at(j)->tm_tag->header->res_id)) {
						printf("Found %i linked to %i\n",instance_ids[i],ExtractLinkNumber(tag->tm_tag->header->res_id));
						count = count + this->GetInstanceCount(this->tags.at(j));
						break;
					}
				}
			}
		}
		free(instance_ids);
	}
	return count;
}

int32_t OniLevel::GetNamedCount(OniTag *tag) {
	int32_t count = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		if (strcmp(this->export_tags.at(i).tag->name, "unnamed") != 0) {
			count++;
		}
	}
	return count;
}

int32_t OniLevel::ComputeDataSize() {
	int32_t total = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		this->export_tags.at(i).data_offset = total;
		total = total + this->export_tags.at(i).tag->GetDataLength();
	}
	return total;
}

int32_t OniLevel::ComputeNamesSize() {	
	int32_t length = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		if (strcmp(this->export_tags.at(i).tag->name, "unnamed") != 0) {
			this->export_tags.at(i).names.old_offset = length;
			length = length + strlen(this->export_tags.at(i).tag->name)+1;
		} else {
			this->export_tags.at(i).names.old_offset = 0;
		}
	}
	return length;
}

int32_t OniLevel::ComputeRawSize() {
	int32_t length = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		length = length + this->export_tags.at(i).tag->tm_tag->raw_size;
	}
	return length;
}