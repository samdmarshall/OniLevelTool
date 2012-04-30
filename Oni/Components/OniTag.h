/*
 *  OniTag.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/30/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"
#include "OniInstance.h"

class OniTag {
public:
	char type[5];
	char name[64];
	int32_t flags;
	char *data;
	
	OniTag();
	void LoadFrom(OniInstanceStruct *data_struct, char *data_buffer, char *name_buffer);
};