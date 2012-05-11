/*
 *  Exporter.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/11/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTag.h"

#ifndef _Exporter
#define _Exporter

struct ExportResID {
	int32_t res_id;
	OniTag *tag;	
};

struct ExportNames {
	int32_t res_id;
	int32_t name_offset;
};

#endif