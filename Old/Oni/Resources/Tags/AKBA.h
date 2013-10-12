/*
 *  AKBA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKBA
#define _AKBA
struct AKBAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AKBADataStruct {
	int32_t plane_index;
	int32_t AKAA_start;
	int32_t AKAA_end;
	
	int32_t unused;
	int32_t unused1;
	int32_t unused2;
	int32_t unused3;
};


class AKBA : public OniTM {
public:
	AKBAHeaderStruct *head;
	AKBADataStruct *data;	
	
	AKBA();
	~AKBA();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif
