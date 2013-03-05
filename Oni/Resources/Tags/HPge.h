/*
 *  HPge.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _HPge
#define _HPge

struct HPgeHeaderStruct {
	char unused[4];
	int32_t IGPG_link;
	char dead[16];
};

class HPge : public OniTM {
public:
	HPgeHeaderStruct *data;
	
	HPge();
	~HPge();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif
