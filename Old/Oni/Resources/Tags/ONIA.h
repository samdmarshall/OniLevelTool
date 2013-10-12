/*
 *  ONIA.h
 *  OniLevelTool
 *
 *  Created by sam on 11/26/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONIA
#define _ONIA

struct ONIAHeaderStruct {
	char unused1[16];
	int8_t is_loaded;
	char unused2[3];
	int32_t array_size;
};

struct ONIADataStruct {
	char impact_name[16];
	char impact_type[128];
	char impact_modifier[16];
	int16_t runtime1;
	int16_t runtime2;
};

class ONIA : public OniTM {
public:
	ONIAHeaderStruct *head;
	ONIADataStruct *data; 	
};

#endif