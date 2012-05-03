/*
 *  IDXA.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/3/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _IDXA
#define _IDXA

struct IDXAHeaderStruct {
	char unused[20];
	int32_t array_size;
};

struct IDXADataAKEV1 {
	int32_t AGQG_id;
};

struct IDXADataAKEV2 {
	int32_t gunk_quad_ref;
};

struct IDXADataAKOT1 {
	int32_t AGQG_id;
};

struct IDXADataAKOT2 {
	int32_t unknown;
};

struct IDXADataM3GM1 {
	int32_t PNTA_id;
};

struct IDXADataM3GM2 {
	int32_t VCRA_id;
};

struct IDXADataONOA {
	int32_t AGQG_id;
};

class IDXA : public OniTM {
public:
	IDXAHeaderStruct *head;
};

#endif
