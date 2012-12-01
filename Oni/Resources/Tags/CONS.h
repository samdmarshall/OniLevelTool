/*
 *  CONS.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _CONS
#define _CONS

struct CONSHeaderStruct {
	int32_t flags;
	float point_x;
	float point_y;
	float point_z;
	float orient_x;
	float orient_y;
	float orient_z;
	int32_t OFGA_link;
	int32_t M3GM_link;
	
	int32_t ignored;
	
	char inactive_name[32];
	char active_name[32];
	char used_name[32];
	
	char dead[16];
};

class CONS : public OniTM {
public:
	CONSHeaderStruct *head;
	
	CONS();
	~CONS();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif