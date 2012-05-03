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
	free(this->name);
	free(this->level_path);
	if (this->type == DAT) {
		free(this->raw_path);
		if (this->platform == DemoMac)
			free(this->sep_path);
	}
	free(this->header);
	free(this->instance_descriptors);
	free(this->name_descriptors);
	free(this->template_descriptors);
	free(this->data_table);
	free(this->names_table);
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
		
		fread(this->header,sizeof(LevelHeader),1,file_);
		this->platform = ((this->header->checksum == 1052091493724257ULL) ? DemoMac : PC);
		this->type = ((this->header->version == 1448227633) ? DAT : ONI);
		
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
		fread(this->instance_descriptors,sizeof(OniInstanceStruct),this->header->instance_count,file_);
		
		this->name_descriptors = (OniNameStruct *)malloc(sizeof(OniNameStruct)*this->header->name_count);	
		fread(this->name_descriptors,sizeof(OniNameStruct),this->header->name_count,file_);
		
		this->template_descriptors = (OniTemplateStruct *)malloc(sizeof(OniTemplateStruct)*this->header->template_count);
		fread(this->template_descriptors,sizeof(OniTemplateStruct),this->header->template_count,file_);
		
		this->data_table = (char *)malloc(sizeof(char)*this->header->data_size);
		fpos_t data_pos = this->header->data_offset;
		fsetpos(file_,&data_pos);
		fread(this->data_table,sizeof(char)*this->header->data_size,1,file_);
		
		this->names_table = (char *)malloc(sizeof(char)*this->header->names_size);
		fpos_t names_pos = this->header->names_offset;
		fsetpos(file_,&names_pos);
		fread(this->names_table,sizeof(char)*this->header->names_size,1,file_);
		
		status = true;
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

			}
			this->tags.push_back(a_tag);
		}
	}
}

void OniLevel::ExportTagToPath(OniTag *tag, char *path) {
	if (this->platform != OPundefined) {
		
	}
}

void OniLevel::ExportAllTags() {
	if (this->platform != OPundefined) {
		if (!this->tags.empty()) {
			for (int32_t i = 0; i < this->tags.size(); i++) {
				OniTag *a_tag = this->tags.at(i);
				//this->ExportTagToPath(a_tag, "some_path");
				delete a_tag;
			}
		}
	}
}