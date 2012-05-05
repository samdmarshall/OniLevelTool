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

class OniTM {
public:
	char type[5];
	OniTMStruct *header;
	
	int32_t instance_count;
	
	OniTM() { this->instance_count = 0; };
	~OniTM() {};
	virtual void Load(char *data) {};
	virtual int32_t* GetInstanceIDs() { return 0; };
	virtual uint64_t DataSize() { return 0; };
	virtual char* ExportData() { return 0; };
};
#endif