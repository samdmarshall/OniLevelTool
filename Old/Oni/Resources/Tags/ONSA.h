/*
 *  ONSA.h
 *  OniLevelTool
 *
 *  Created by sam on 12/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONSA
#define _ONSA

struct ONSAHeaderStruct {
	char unused1[22];
	int16_t array_size;
};

class ONSA : public OniTM {
public:
	ONSAHeaderStruct *head;
};

#endif