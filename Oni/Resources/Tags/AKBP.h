/*
 *  AKBP.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKBP
#define _AKBP
struct AKBPHeaderStruct {
	char unused[22];
	int16_t array_size;
};

struct AKBPDataStruct {
	int32_t plane_index;
	int32_t AKBP_back;
	int32_t AKBP_front;
};

class AKBP : public OniTM {
public:
	AKBPHeaderStruct *head;
	AKBPDataStruct *data;	
};
#endif
