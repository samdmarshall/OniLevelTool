/*
 *  AKEV.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _AKEV
#define _AKEV
struct AKEVDataStruct {
	int32_t PNTA_link;
	int32_t PLEA_link;
	int32_t TXCA_link;
	int32_t AGQG_link;
	int32_t AGQR_link;
	int32_t AGQC_link;
	int32_t AGDB_link;
	int32_t TXMA_link;
	int32_t AKVA_link;
	int32_t AKBA_link;
	int32_t IDXA_link1;
	int32_t IDXA_link2;
	int32_t AKBP_link;
	int32_t ABNA_link;
	int32_t AKOT_link;
	int32_t AKAA_link;
	int32_t AKDA_link;
	float min_x;
	float min_y;
	float min_z;
	float max_x;
	float max_y;
	float max_z;
	char unused[24];
	float ignored;
};
#endif

class AKEV : public OniTM {
public:
	AKEVDataStruct *data;
};