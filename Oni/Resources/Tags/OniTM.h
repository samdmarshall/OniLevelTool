/*
 *  OniTM.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

#ifndef _OniTM
#define _OniTM
struct OniTMStruct {
	char res_id[4];
	char level_id[4];
};
#endif

class OniTM {
public:
	char type[5];
	OniTMStruct *header;
	OniTM();
	~OniTM();
};