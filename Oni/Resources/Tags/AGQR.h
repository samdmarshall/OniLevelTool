/*
 *  AGQR.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AGQR
#define _AGQR
struct AGQRHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AGQRDataStruct {
	int16_t TXMA_id;
	char dead[2];
};

#endif

class AGQR : public OniTM {
public:
	AGQRHeaderStruct *head;
	AGQRDataStruct *data;
};