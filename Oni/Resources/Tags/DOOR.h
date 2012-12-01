/*
 *  DOOR.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _DOOR
#define _DOOR

struct DOORHeaderStruct {
	int32_t OFGA_link1;
	int32_t OFGA_link2;
	int32_t OBAN_link;
	float sound_attenuation;
	int32_t passed_sounds;
	int32_t sound_type;
	float sound_volume;
	char open_name[32];
	char close_name[32];
	int32_t runtime1;
	int32_t runtime2;
	char dead[20];
};

class DOOR : public OniTM {
public:
	DOORHeaderStruct *head;
	
	DOOR();
	~DOOR();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif