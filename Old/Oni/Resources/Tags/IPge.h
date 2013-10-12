/*
 *  IPge.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IPge
#define _IPge

struct IPgeDataStruct {
	int32_t page_number;
	int32_t IGPG_link;
	char dead[16];
};


class IPge : public OniTM {
public:
	IPgeDataStruct *data;
};
#endif
