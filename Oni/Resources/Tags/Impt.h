/*
 *  Impt.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _Impt
#define _Impt

struct ImptDataStruct {
	int16_t ignored;
	char unused[6];
	int32_t Impt_link;
	char dead[12];
};

#endif

class Impt : public OniTM {
public:
	ImptDataStruct *data;
};