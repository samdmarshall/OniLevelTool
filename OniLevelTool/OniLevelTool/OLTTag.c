//
//  OLTTag.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/13/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTTag_c
#define OniLevelTool_OLTTag_c

#include "OLTTag.h"

struct OLTTagContainer OpenLevelWithPlugins(struct OLTLevel *level, struct OLTKnownTypes *plugins) {
	struct OLTTagContainer container;
	container.tags = calloc(sizeof(struct OLTTag), 0x1);
	container.tagCount = 0;
	for (uint32_t i = 0; i < level->header->instanceCount; i++) {
		if (ValidTagType(&level->instance[i], level)) {
			if (VerifyTagTemplate(&level->instance[i], plugins)) {
				container.tags = realloc(container.tags, container.tagCount+1);
				container.tags[container.tagCount].instance = &level->instance[i];
				container.tags[container.tagCount].plugin = &plugins->tags[TagPluginIndex(&level->instance[i], plugins)];
				container.tags[container.tagCount].level = level;
				container.tagCount++;
			}
		}
	}
	return container;
}

#endif
