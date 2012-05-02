/*
 *  AKAA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKAA
#define _AKAA
struct AKAAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AKAADataStruct {
	int32_t AKVA_id;
	int32_t AGQG_id;
	int32_t unused;
};

class AKAA : public OniTM {
public:
	AKAAHeaderStruct *head;
	AKAADataStruct *data;	
};
#endif
