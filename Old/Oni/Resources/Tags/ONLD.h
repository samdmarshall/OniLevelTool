/*
 *  ONLD.h
 *  OniLevelTool
 *
 *  Created by sam on 11/26/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONLD
#define _ONLD

struct ONLDHeaderStruct {
	int16_t this_level;
	int16_t next_level;
	char level_name[64];
	char unused1[20];
};

class ONLD : public OniTM {
public:
	ONLDHeaderStruct *head;	
};

#endif