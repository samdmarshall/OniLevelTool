/*
 *  CBPI.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _CBPI
#define _CBPI

struct CBPIHitStruct {
	int32_t Impt_link;
};

struct CBPIBlockStruct {
	int32_t Impt_link;
};

struct CBPIKillStruct {
	int32_t Impt_link;
};

struct CBPIDataStruct {
	CBPIHitStruct hit[19];
	CBPIBlockStruct block[19];
	CBPIKillStruct killed[19];
	char dead[20];
};

class CBPI : public OniTM {
public:
	CBPIDataStruct *data;
	
	CBPI();
	~CBPI();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif