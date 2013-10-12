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

struct NameRemapper {
	int32_t old_offset;
	int32_t new_offset;
};

struct Exporter {
	int32_t res_id;
	OniTag *tag;
	NameRemapper names;
	int32_t data_offset;
};

#endif