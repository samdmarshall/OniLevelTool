/*
 *  Level.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"
#include "OniTag.h"

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
	
	int32_t unused[4];
};

typedef enum OniPlatform {
	OPundefined = 0,
	PC = 1,
	DemoMac = 2
};

typedef enum LevelType {
	LTundefined = 0,
	DAT = 1,
	ONI = 2
};

class OniLevel {
	public:
	char *name;
	
	char *level_path;
	char *raw_path;
	char *sep_path;
	
	bool has_raw;
	bool has_sep;
	
	LevelHeader *header;
	
	OniPlatform platform;
	LevelType type;
	
	OniInstanceStruct *instance_descriptors;
	OniNameStruct *name_descriptors;
	OniTemplateStruct *template_descriptors;
	
	char *data_table;
	char *names_table;
	
	std::vector<OniTag *> tags;
	
	OniLevel();
	~OniLevel();
	bool LoadPath(char *path);
	void LoadTags();
	void ExportTagToPath(OniTag *tag, char *path);
	void ExportAllTags();
};