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
		fread(&this->header,sizeof(this->header),1,file_);
		fread(this->instance_descriptors,sizeof(OniInstanceStruct),this->header.instance_count,file_);
		fread(this->name_descriptors,sizeof(OniNameStruct),this->header.name_count,file_);
		fread(this->template_descriptors,sizeof(OniTemplateStruct),this->header.template_count,file_);
		
		data_table = (int *)malloc(sizeof(this->header.data_size));
		fpos_t data_pos = this->header.data_offset;
		fsetpos(file_,&data_pos);
		fread(this->data_table,sizeof(this->data_table),1,file_);
		
		names_table = (int *)malloc(sizeof(this->header.names_size));
		fpos_t names_pos = this->header.names_offset;
		fsetpos(file_,&names_pos);
		fread(this->names_table,sizeof(this->names_table),1,file_);
		
		fclose(file_);
		return true;
	} else {
		return false;
	}
}

