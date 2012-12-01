/*
 *  ENVP.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ENVP
#define _ENVP

struct ENVPHeaderStruct {
	char unused[22];
	int16_t array_size;
};

struct ENVPParticleMatrix {
	float a1;
	float a2;
	float a3;
	
	float b1;
	float b2;
	float b3;
	
	float c1;
	float c2;
	float c3;
	float c4;
	
	float d1;
	float d2;
	float d3;
	float d4;
};

struct ENVPDataStruct {
	char particle_type_name[64];
	char particle_name[48];
	ENVPParticleMatrix transform;
	float x_scale;
	float y_scale;
	int32_t runtime[10];
};

class ENVP : public OniTM {
public:
	ENVPHeaderStruct *head;
	ENVPDataStruct *data;
	
	ENVP();
	~ENVP();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};

#endif
