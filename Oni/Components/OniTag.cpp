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
	free(this->data);
}

void OniTag::LoadFrom(OniInstanceStruct *data_struct, char *data_buffer, char *name_buffer) {
	memcpy(this->type, &data_struct->template_tag, 4); this->type[5] = '\0';
	memcpy(this->name, &name_buffer[data_struct->name_offset],64);
	this->flags = data_struct->flags;
	this->data = (char *)malloc(sizeof(char)*data_struct->data_size);
	memcpy(this->data, &data_buffer[data_struct->data_offset],data_struct->data_size);
}