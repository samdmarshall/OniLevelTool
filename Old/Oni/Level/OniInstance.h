/*
 *  OniInstance.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

#ifndef _OniInstanceStruct
#define _OniInstanceStruct
struct OniInstanceStruct {
	int32_t template_tag;
	int32_t data_offset;
	int32_t name_offset;
	int32_t data_size;
	int32_t flags;
};

typedef enum OniInstanceFlags {
	OIF_None = 0,
	OIF_Unique = (1 << 0),
	OIF_PlaceHolder = (1 << 1),
	OIF_Shared = (1 << 2),
	OIF_Source = (1 << 3)
};

static inline bool hasInstanceFlag(int32_t flags, OniInstanceFlags num) {
	return ((flags & num) & 0xF);
}
#endif