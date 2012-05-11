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
#include "OniTemplate.h"

#include "Tags.h"

#ifndef _OniTag
#define _OniTag


class OniTag {
public:
	char type[4];
	char name[64];
	int32_t flags;
	
	OniTM *tm_tag;
	
	bool external_data;
			
	OniTag();
	~OniTag();
	void LoadFrom(OniInstanceStruct *data_struct, char *data_buffer, char *name_buffer);
	void FormatTag(char *i_data);
	int32_t GetDataLength();
	char* GetExportData();
};
#endif