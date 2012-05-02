/*
 *  OBOA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/2/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _OBOA
#define _OBOA

struct OBOAHeaderStruct {
	char unused[22];
	int16_t array_size;
};

struct OBOADataStruct {
	int32_t M3GA_link;
	int32_t OBAN_link;
	int32_t ENVP_link;
	int32_t flags;
	int32_t unknown;
	int32_t door_id;
	int32_t physics_type;
	int32_t script_id;
	
	float initial_x;
	float initial_y;
	float initial_z;
	
	float rotation_x;
	float rotation_y;
	float rotation_z;
	float rotation_w;
	
	float scale;
	
	float m11;
	float m21;
	float m31;
	
	float m12;
	float m22;
	float m32;
	
	float m13;
	float m23;
	float m33;
	
	float m14;
	float m24;
	float m34;
	
	char object_name[64];
	char file_name[64];
};


class OBOA : public OniTM {
public:
	OBOAHeaderStruct *head;
	OBOADataStruct *data;
};
#endif
