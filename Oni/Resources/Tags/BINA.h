/*
 *  BINA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _BINA
#define _BINA
struct BINAHeaderStruct {
	int32_t data_size;
	int32_t data_offset;
	char unused[16];
};

class BINA : public OniTM {
public:
	BINAHeaderStruct *head;
	char *data;
	
	BINA();
	~BINA();
	void Load(char *data);
	void SetDataPath(char *path);
};
#endif