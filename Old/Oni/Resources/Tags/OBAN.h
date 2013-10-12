/*
 *  OBAN.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/2/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _OBAN
#define _OBAN

struct OBANTransformMatrix {
	float a1;
	float a2;
	float a3;
	
	float b1;
	float b2;
	float b3;
	
	float c1;
	float c2;
	float c3;
	
	float d1;
	float d2;
	float d3;
};

struct OBANHeaderStruct {
	char padding[12];
	int32_t flags;
	OBANTransformMatrix initial_pos;
	OBANTransformMatrix fixed_pos;
	int16_t frame_length;
	int16_t number_of_frames;
	int16_t stop_frame;
	
	int16_t array_size;
};

struct OBANDataStruct {
	float rotation1;
	float rotation2;
	float rotation3;
	float rotation4;
	
	float v1;
	float v2;
	float v3;
	
	int32_t elapsed_frame;
};

class OBAN : public OniTM {
public:
	OBANHeaderStruct *header;
	OBANDataStruct *data;
};
#endif
