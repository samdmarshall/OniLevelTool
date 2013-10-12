/*
 *  IGSt.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IGSt
#define _IGSt

struct IGStDataStruct {
	int32_t TSFF_link;
	int32_t font_family_type;
	char color[4];
	int16_t font_size;
	int16_t flags;
	char text[384];
	char unused[8];
};


class IGSt : public OniTM {
public:
	IGStDataStruct *data;
};
#endif
