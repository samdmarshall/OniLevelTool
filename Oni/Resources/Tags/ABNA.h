/*
 *  ABNA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ABNA
#define _ABNA
struct ABNAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct ABNADataStruct {
	int32_t AGQG_id;
	int32_t PLEA_id;
	int32_t front_index;
	int32_t back_index;
};


class ABNA : public OniTM {
public:
	ABNAHeaderStruct *head;
	ABNADataStruct *data;
	
	ABNA();
	~ABNA();
	void Load(char *data);
	int32_t* GetInstanceIDs();
};
#endif
