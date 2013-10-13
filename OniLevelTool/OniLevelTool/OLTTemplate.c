//
//  OLTTemplate.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTTemplate_c
#define OniLevelTool_OLTTemplate_c

#include "OLTTemplate.h"

bool ValidTagType(struct OLTInstance *instance, struct OLTLevel *level) {
	bool result = false;
	uint32_t index = TagTemplateIndex(instance);
	if (result) {
		for (uint32_t i = 0; i < level->header->templateCount; i++) {
			result = (level->template[i].checkSum == OLTTemplate_types[index].checkSum);
			if (result) {
				break;
			}
		}
	}
	return result;
}

uint32_t TagTemplateIndex(struct OLTInstance *instance) {
	uint32_t i;
	for (i = 0; i < OLTTemplateCount; i++) {
		if (IsTypeOfTag(instance->tagType, OLTTemplate_types[i].template)) {
			break;
		}
	}
	return i;
}

#endif