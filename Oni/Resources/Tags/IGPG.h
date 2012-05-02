/*
 *  IGPG.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IGPG
#define _IGPG

struct IGPGDataStruct {
	int32_t TSFF_link;
	int32_t font_family_type;
	char color[4];
	int16_t font_size;
	
	int16_t flags;
	int32_t TXMP_PSpc_link;
	int32_t IGSA_link1;
	int32_t IGSA_link2;
	char unused[28];
};

#endif

class IGPG : public OniTM {
public:
	IGPGDataStruct *data;
};