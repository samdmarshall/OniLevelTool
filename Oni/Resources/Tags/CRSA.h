/*
 *  CRSA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _CRSA
#define _CRSA

struct CRSAHeaderStruct {
	char unused[12];
	int32_t fixed_corpses;
	int32_t used_corpses;
	int32_t array_capacity;
};

struct CRSABoneMatrix {
	float a1;
	float a2;
	float a3;
	
	float b1;
	float b2;
	float b3;
	
	float c1;
	float c2;
	float c3;
};

struct CRSABoundingBox {
	float a1;
	float a2;
	float a3;
	
	float b1;
	float b2;
	float b3;
};

struct CRSADataStruct {
	char file_name[32];
	int8_t runtime[16];
	int32_t ONCC_link;
	CRSABoneMatrix bone[19];
	CRSABoundingBox box;
};

class CRSA : public OniTM {
public:
	CRSAHeaderStruct *head;
	CRSADataStruct *data;
	
	CRSA();
	~CRSA();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif