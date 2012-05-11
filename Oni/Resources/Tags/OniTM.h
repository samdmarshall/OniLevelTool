/*
 *  OniTM.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

#ifndef _OniTM
#define _OniTM
struct OniTMStruct {
	char res_id[4];
	char level_id[4];
};

struct ResIDMapper {
	int32_t old_id;
	int32_t new_id;
};

class OniTM {
public:
	char type[4];
	OniTMStruct *header;
	
	int32_t instance_count;
	
	char *raw_data;
	int32_t raw_size;
	
	ResIDMapper remap;
		
	OniTM() { this->instance_count = 0; };
	~OniTM() {};
	virtual void Load(char *data) {};
	virtual int32_t* GetInstanceIDs() { return 0; };
	virtual int32_t DataSize() { return 0; };
	virtual char* ExportData() { return 0; };
};
#endif