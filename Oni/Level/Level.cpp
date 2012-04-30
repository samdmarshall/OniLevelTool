/*
 *  Level.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "Level.h"

OniLevel::OniLevel() {}

bool OniLevel::LoadPath(char *path) {
	FILE *file_ = fopen(path,"rb");
	if (file_) {
		this->header = (LevelHeader *)malloc(sizeof(LevelHeader)*1);
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