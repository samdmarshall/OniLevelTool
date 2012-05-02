/*
 *  M3GM.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _M3GM
#define _M3GM

struct M3GMDataStruct {
	int32_t runtime;
	int32_t PNTA_link;
	int32_t VCRA_link1;
	int32_t VCRA_link2;
	int32_t TXCA_link;
	int32_t IDXA_link1;
	int32_t IDXA_link2;
	int32_t TXMP_link;
	int32_t unused_link;
	char unused[20];
};


class M3GM : public OniTM {
public:
	M3GMDataStruct *data;
};
#endif
