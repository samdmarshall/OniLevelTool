/*
 *  Keyl.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _Keyl
#define _Keyl

struct KeylDataStruct {
	int32_t TXMP_link1;
	int32_t TXMP_link2;
	int32_t TXMP_link3;
	int32_t TXMP_link4;
	int32_t TXMP_link5;
	int32_t TXMP_link6;
	int32_t TXMP_link7;
	int32_t TXMP_link8;
	int32_t TXMP_link9;
	int32_t TXMP_link10;
	char dead[16];
};


class Keyl : public OniTM {
public:
	KeylDataStruct *data;
};
#endif
