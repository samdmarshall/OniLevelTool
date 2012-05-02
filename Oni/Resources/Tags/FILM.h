/*
 *  FILM.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _FILM
#define _FILM

struct FILMHeaderStruct {
	float x_pos;
	float y_pos;
	float z_pos;
	float body_facing;
	float desired_facing;
	float head_facing;
	float looking;
	int32_t length_frames; // 1 frame = 1/60 of 1 second.
	int32_t cutscene1_animation;
	int32_t cutscene2_animation;
	char dead[12];
	int32_t array_size;
};

struct FILMDataStruct {
	float mouse_x;
	float mouse_z;
	int64_t key_events;
	int32_t frame_number;
	int32_t ignored;
};

#endif

class FILM : public OniTM {
public:
	FILMHeaderStruct *head;
	FILMDataStruct *data;
};