/*
 *  DPge.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _DPge
#define _DPge

struct DPgeHeaderStruct {
	int16_t level;
	int16_t page;
	int8_t page_type;
	char dead1[3];
	int32_t key_icons[12];
	int32_t IGPG_link;
	char dead2[28];
};

class DPge : public OniTM {
public:
	DPgeHeaderStruct *head;
	
	DPge();
	~DPge();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif