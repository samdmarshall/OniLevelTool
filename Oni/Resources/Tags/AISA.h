/*
 *  AISA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AISA
#define _AISA
struct AISAHeaderStruct {
	char unused[22];
	int32_t array_size;
};

struct AISADataStruct {
	char name[32];
	int16_t character_id;
	int16_t spawn_flag;
	
	int16_t ignored;
	
	int16_t team_id;
	
	int32_t ONCC_link_id;
	
	char unused[32];
	int32_t unused1;
	
	char se_create[32];
	char se_die[32];
	char se_notice[32];
	char se_alarm[32];
	char se_hurt[32];
	char se_neardeath[32];
	char se_noammo[32];
	char se_nopath[32];
	
	int32_t ONWC_link_id;
	
	int16_t ammo;
	
	int16_t unused2;
	int16_t unused3;
	int16_t unused4;
	int16_t unused5;
	int8_t unused6;
	int8_t unused7;
};
#endif

class AISA : public OniTM {
public:
	AISAHeaderStruct *head;
	AISADataStruct *data;
};