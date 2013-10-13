//
//  OLTTag.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/13/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTTag_h
#define OniLevelTool_OLTTag_h

#include "OLTTypes.h"
#include "OLTLevel.h"
#include "OLTTemplate.h"
#include "OLTPlugin.h"

struct OLTTag {
	struct OLTInstance *instance;
	struct OLTPlugin *plugin;
	struct OLTLevel *level;
} ATR_PACK;

struct OLTTagContainer {
	struct OLTTag *tags;
	uint32_t tagCount;
} ATR_PACK;

struct OLTTagContainer OpenLevelWithPlugins(struct OLTLevel *level, struct OLTKnownTypes *plugins);

#endif
