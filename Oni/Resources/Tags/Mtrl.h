/*
 *  Mtrl.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _Mtrl
#define _Mtrl

struct MtrlDataStruct {
	int16_t runtime;
	char unused[6];
	int32_t Mtrl_link;
	char dead[12];
};


class Mtrl : public OniTM {
public:
	MtrlDataStruct *data;
};
#endif
