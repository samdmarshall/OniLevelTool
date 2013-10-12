/*
 *  ONLV.h
 *  OniLevelTool
 *
 *  Created by sam on 11/26/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONLV
#define _ONLV

struct ONLVHeaderStruct {
	char level_name[64];
	int32_t AKEV_link1;
	int32_t OBOA_link1;
	int32_t ONMA_link1;
	int32_t ONFA_link1;
	int32_t ONTA_link1;
	int32_t ONSK_link1;
	float sky_height;
	int32_t AISA_link1;
	int32_t AITR_link1;
	int32_t ONSA_link1;
	int32_t OBDC_link1;
	int32_t ONOA_link1;
	int32_t ENVP_link1;
	char runtime1[644];
	int32_t CRSA_link1;
	char unused1[28];
};

class ONLV : public OniTM {
public:
	ONLVHeaderStruct *head;
};

#endif