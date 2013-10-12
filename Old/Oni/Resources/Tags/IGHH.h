/*
 *  IGHH.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IGHH
#define _IGHH
struct IGHHHeaderStruct {
	char unused[28];
	int32_t TXMP_link_left;
	int32_t TXMP_link_right;
	int16_t h_offset_left_left;
	int16_t v_offset_left_bottom;
	int16_t h_offset_right_right;
	int16_t v_offset_right_bottom;
	int32_t left_elements;
	int32_t right_elements;
	int32_t array_size;
};

struct IGHHDataStruct {
	char name[64];
	int16_t px_left;
	int16_t px_top;
};


class IGHH : public OniTM {
public:
	IGHHHeaderStruct *head;
	IGHHDataStruct *data;
};
#endif
