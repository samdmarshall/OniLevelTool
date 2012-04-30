/*
 *  OniInstance.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

class OniInstance {
	char *template_tag[4];
	int32_t data_offset;
	int32_t name_offset;
	int32_t data_size;
	int32_t flags;
};