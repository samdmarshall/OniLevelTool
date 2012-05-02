/*
 *  AKOT.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKOT
#define _AKOT
struct AKOTDataStruct {
	int32_t OTIT_link;
	int32_t OTLF_link;
	int32_t QTNA_link;
	int32_t IDXA_link1;
	int32_t IDXA_link2;
	char unused[4];
};

class AKOT : public OniTM {
public:
	AKOTDataStruct *data;	
};
#endif
