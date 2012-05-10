/*
 *  Level.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "Level.h"

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
		if (!this->tags.empty()) {
			this->tags.clear();
		}
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
			
			FILE *export_tag_ = fopen(file_path, "w+");
			if (export_tag_) {
				std::cout << file_path << std::endl;
				
				LevelHeader *output_header = this->CreateOniHeader(tag);
				fwrite(output_header, 1, sizeof(LevelHeader), export_tag_);
				free(output_header);
				
				// write names table
				
				// write data table
				/*for (int32_t i = 0; i < this->export_tags.size(); i++) {
					char *data = tag->GetExportData();
					fwrite(data, 1, sizeof(tag->GetDataLength()), export_tag_);
					free(data);
				}*/
				
				// write raw
			}
			fclose(export_tag_);
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
					
					// before we ship to export, remapping has to be done to the instance ids. 
					
					
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
	new_header->name_count = 0; // always zero
	new_header->template_count = 0; // always zero
	
	new_header->names_offset = this->ComputeNamesOffset();
	new_header->names_size = this->ComputeNamesSize();
	
	new_header->data_offset = new_header->names_offset+new_header->names_size; 
	new_header->data_size = this->ComputeDataSize(); 
		
	new_header->raw_offset = new_header->data_offset+new_header->data_size; // end of normal dat file
	new_header->raw_size = this->ComputeRawSize();
	
	new_header->unused[0] = 0;
	new_header->unused[1] = 0;
	
	return new_header;
}

int32_t OniLevel::GetInstanceCount(OniTag *tag) {
	int32_t count = tag->tm_tag->instance_count;
	if (count) {
		this->export_tags.push_back(tag);
		int32_t *instance_ids = (int32_t *)malloc(sizeof(int32_t)*tag->tm_tag->instance_count);
		instance_ids = tag->tm_tag->GetInstanceIDs();
		for (int32_t i = 0; i < tag->tm_tag->instance_count; i++) {
			for (int32_t j = 0; j < this->tags.size(); j++) {
				printf("%i %i\n", instance_ids[i], CharToInt(this->tags.at(j)->tm_tag->header->res_id));
				if (instance_ids[i] == CharToInt(this->tags.at(j)->tm_tag->header->res_id)) {
					printf("Found %i linked to %i\n",instance_ids[i],CharToInt(tag->tm_tag->header->res_id));
					count = count + this->GetInstanceCount(this->tags.at(j));
					break;
				}
			}
		}
		free(instance_ids);
	}
	return count;
}

int32_t OniLevel::ComputeNamesOffset() {
	return 20*this->export_tags.size();
}

int32_t OniLevel::ComputeDataSize() {
	int32_t total = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		total = total + this->export_tags.at(i)->GetDataLength();
	}
	return total;
}

int32_t OniLevel::ComputeNamesSize() {
	int32_t length = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		if (strcmp(this->export_tags.at(i)->name, "unnamed") != 0)
			length = length + strlen(this->export_tags.at(i)->name);
	}
	return length;
}

int32_t OniLevel::ComputeRawSize() {
	int32_t length = 0;
	for (int32_t i = 0; i < this->export_tags.size(); i++) {
		length = length + this->export_tags.at(i)->tm_tag->raw_size;
	}
	return length;
}