/*
 *  OFGA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/2/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _OFGA
#define _OFGA

struct OFGAHeaderStruct {
	char unused[16];
	int32_t ENVP_link;
	int32_t array_size;
};

struct OFGADataStruct {
	int32_t flags;
	int32_t M3GM_link;
	int32_t OBLS_link;
};

class OFGA : public OniTM {
public:
	OFGAHeaderStruct *head;
	OFGADataStruct *data;
};
#endif
