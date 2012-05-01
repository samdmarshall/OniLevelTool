/*
 *  OniTag.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/30/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTag.h"

OniTag::OniTag() {}

OniTag::~OniTag() {
	free(this->instance_data);
}

void OniTag::LoadFrom(OniInstanceStruct *data_struct, char *data_buffer, char *name_buffer) {
	memcpy(this->type, &data_struct->template_tag, 4);
	this->type[4]='\0';
	
	this->flags = data_struct->flags;
	
	if (!hasInstanceFlag(this->flags, OIF_Unique))
		memcpy(this->name, &name_buffer[data_struct->name_offset],64);
	else
		strncpy(this->name, "unnamed", 64);
		
	this->instance_data = (char *)malloc(sizeof(char)*data_struct->data_size);
	memcpy(this->instance_data, &data_buffer[data_struct->data_offset],data_struct->data_size);
	
	memcpy(this->instance_id, &data_buffer[data_struct->data_offset-8], 4);
	memcpy(this->file_id, &data_buffer[data_struct->data_offset-4], 4);
}