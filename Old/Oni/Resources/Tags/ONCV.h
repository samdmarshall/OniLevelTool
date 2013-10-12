/*
 *  ONCV.h
 *  OniLevelTool
 *
 *  Created by sam on 11/26/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONCV
#define _ONCV

struct ONCVDataStruct {
	int32_t oncv_link;
	char character_name1[32];
	char character_name2[32];
	char unused1[20];
};

class ONCV : public OniTM {
public:
	ONCVDataStruct *data;
};

#endif