/*
 *  IGSA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IGSA
#define _IGSA

struct IGSAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct IGSADataStruct {
	int32_t IGSt_link;
};


class IGSA : public OniTM {
public:
	IGSAHeaderStruct *head;
	IGSADataStruct *data;
};
#endif
