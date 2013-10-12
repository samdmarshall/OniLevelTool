/*
 *  M3GA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _M3GA
#define _M3GA

struct M3GAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct M3GADataStruct {
	int32_t M3GM_link;
};


class M3GA : public OniTM {
public:
	M3GAHeaderStruct *head;
	M3GADataStruct *data;
};
#endif
