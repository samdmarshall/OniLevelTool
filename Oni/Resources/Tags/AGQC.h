/*
 *  AGQC.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AGQC
#define _AGQC
struct AGQCHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AGQCDataStruct {
	int32_t PLEA_id;
	float neg_x;
	float neg_y;
	float neg_z;
	float pos_x;
	float pos_y;
	float pos_z;
};

class AGQC : public OniTM {
public:
	AGQCHeaderStruct *head;
	AGQCDataStruct *data;
	
	AGQC();
	~AGQC();
	void Load(char *data);
};
#endif
