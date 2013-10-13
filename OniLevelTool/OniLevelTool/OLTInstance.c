//
//  OLTInstance.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTInstance_c
#define OniLevelTool_OLTInstance_c

#include "OLTInstance.h"

#define EVAL_INSTANCE_FLAG(flags, num) ((flags & num) & 0xF)

char* GetNameOfInstanceInLevel(struct OLTInstance *instance, struct OLTLevel *level) {
	char *name = "unnamed";
	if (!EVAL_INSTANCE_FLAG(instance->flags,OLTDescriptorFlags_Unique)) {
		name = ((&(level->data->buffer[level->header->nameTable.offset]))+instance->nameOffset);
	}
	return name;
}

#endif