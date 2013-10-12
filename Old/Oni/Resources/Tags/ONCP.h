/*
 *  ONCP.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/11/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONCP
#define _ONCP

struct ONCPHeaderStruct {
	char unused1[16];
	int8_t is_loaded;
	char unused2[3];
	int32_t array_size;
};

struct ONCPDataStruct {
	char particle_name[16];
	char class_name[64];
	uint16_t bodypart_number;
	int16_t ignored;
	int32_t runtime;
};

class ONCP : public OniTM {
public:
	ONCPHeaderStruct *head;
	ONCPDataStruct *data;
	
	ONCP();
	~ONCP();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};

#endif