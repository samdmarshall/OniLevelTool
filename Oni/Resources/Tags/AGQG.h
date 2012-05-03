/*
 *  AGQG.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AGQG
#define _AGQG
struct AGQGHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct AGQGDataStruct {
	int32_t PNTA_id_v1;
	int32_t PNTA_id_v2;
	int32_t PNTA_id_v3;
	int32_t PNTA_id_v4;
	
	int32_t TXCA_id_v1;
	int32_t TXCA_id_v2;
	int32_t TXCA_id_v3;
	int32_t TXCA_id_v4;
	
	char color_v1[4];
	char color_v2[4];
	char color_v3[4];
	char color_v4[4];
	
	int32_t flags;
	int32_t object_id;
};

class AGQG : public OniTM {
public:
	AGQGHeaderStruct *head;
	AGQGDataStruct *data;
	AGQG();
	~AGQG();
	void Load(char *data);
};
#endif
