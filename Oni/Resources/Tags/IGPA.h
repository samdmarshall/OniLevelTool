/*
 *  IGPA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IGPA
#define _IGPA

struct IPGAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct IPGADataStruct {
	int32_t IGPG_link;
};

#endif

class IGPA : public OniTM {
public:
	IPGAHeaderStruct *head;
	IPGADataStruct *data;
};