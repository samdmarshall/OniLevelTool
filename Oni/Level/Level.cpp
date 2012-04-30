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
}

OniLevel::~OniLevel() {
	free(this->name);
	free(this->header);
	free(this->instance_descriptors);
	free(this->name_descriptors);
	free(this->template_descriptors);
	free(this->data_table);
	free(this->names_table);
}

bool OniLevel::LoadPath(char *path) {
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
		
		fread(this->header,sizeof(LevelHeader),1,file_);
		
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
		
		fclose(file_);
		return true;
	} else {
		return false;
	}
}