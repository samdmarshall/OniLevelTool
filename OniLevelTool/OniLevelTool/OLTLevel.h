//
//  OLTLevel.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTLevel_h
#define OniLevelTool_OLTLevel_h

#include "OLTTypes.h"

struct OLTLevelHeader {
	int64_t checkSum;
	int32_t version;
	int64_t signature;
	uint32_t instanceCount;
	uint32_t nameCount;
	uint32_t templateCount;
	struct OLTRegion dataTable;
	struct OLTRegion nameTable;
	struct OLTRegion rawTable;
	struct OLTRegion reserved;
} ATR_PACK;

struct OLTLevel {
	struct OLTBuffer *data;
	struct OLTLevelHeader *header;
	struct OLTInstance *instance;
	struct OLTName *name;
	struct OLTTemplate *template;
} ATR_PACK;

struct OLTLevel* ParseLevelFromFile(char *path);

#endif
