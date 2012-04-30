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

struct LevelHeader {
	int64_t checksum;
	int32_t version;
	int64_t signature;
	
	int32_t instance_count;
	int32_t name_count;
	int32_t template_count;
	
	int32_t data_offset;
	int32_t data_size;
	
	int32_t names_offset;
	int32_t names_size;
	
	int32_t unused_1;
	int32_t unused_2;
	int32_t unused_3;
	int32_t unused_4;
};

class OniLevel {
	public:
	char *name;
	
	LevelHeader *header;
	
	OniInstanceStruct *instance_descriptors;
	OniNameStruct *name_descriptors;
	OniTemplateStruct *template_descriptors;
	
	char *data_table;
	char *names_table;
	
	OniLevel();
	~OniLevel();
	bool LoadPath(char *path);
};