/*
 *  ONOA.h
 *  OniLevelTool
 *
 *  Created by sam on 11/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONOA
#define _ONOA

struct ONOAHeaderStruct {
	char unused1[20];
	int32_t array_size;
};

struct ONOADataStruct {
	int32_t object_id;
	int32_t IDXA_link;
};


class ONOA : public OniTM {
public:
	ONOAHeaderStruct *head;
	ONOADataStruct *data;
};

#endif