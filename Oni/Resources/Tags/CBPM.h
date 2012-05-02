/*
 *  CBPM.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _CBPM
#define _CBPM
struct CBPMLinkStruct {
	int32_t Mtrl_link;
};

struct CBPMDataStruct {
	CBPMLinkStruct material[19];
	char dead[12];
};

class CBPM : public OniTM {
public:
	CBPMDataStruct *data;
};
#endif
