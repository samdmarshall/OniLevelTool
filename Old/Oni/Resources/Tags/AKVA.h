/*
 *  AKVA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKVA
#define _AKVA
struct AKVAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AKVADataStruct {
	int32_t AKBP_index;
	int32_t BNV_id1;
	int32_t AKBA_start;
	int32_t AKBA_end;
	int32_t BNV_child_index;
	int32_t BNV_sibling_index;
	int32_t runtime1;
	int32_t pathfinding_x;
	int32_t pathfinding_z;
	int32_t pathfinding_offset;
	int32_t pathfinding_size;
	float tile_size;
	float neg_x;
	float neg_y;
	float neg_z;
	float pos_x;
	float pos_y;
	float pos_z;
	int16_t x_origin;
	int16_t z_origin;
	int32_t BNV_id2;
	int32_t runtime2;
	int32_t path_debug_size;
	int32_t path_debug_offset;
	int32_t flags;
	float x_sloped;
	float y_sloped;
	float z_sloped;
	float slope_distance;
	float slope_height;
};

class AKVA : public OniTM {
public:
	AKVAHeaderStruct *head;
	AKVADataStruct *data;
	
	AKVA();
	~AKVA();
	void Load(char *data);
	int32_t* GetInstanceIDs();
	int32_t DataSize();
	char* ExportData();
};
#endif