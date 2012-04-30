/*
 *  Level.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

#include "OniInstance.h"
#include "OniName.h"
#include "OniTemplate.h"

class Level {
	char *name[];
	
	int64_t checksum;
	char version[4];
	int64_t signature;
	
	int32_t instance_count;
	int32_t name_count;
	int32_t template_count;
	
	int32_t data_offset;
	int32_t data_size;
	
	int32_t names_offset;
	int32_t names_size;
	
	OniInstance *instance_descriptors[];
	OniName *name_descriptors[];
	OniTemplate *template_descriptors[];
	
};