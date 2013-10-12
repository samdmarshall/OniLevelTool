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
	uint32_t i;
	for (i = 0; i < OLTTemplateCount; i++) {
		result = IsTypeOfTag(instance->tagType, OLTTemplate_types[i].template);
		if (result) {
			break;
		}
	}
	if (result) {
		for (uint32_t j = 0; j < level->header->templateCount; j++) {
			result = (level->template[j].checkSum == OLTTemplate_types[i].checkSum);
			if (result) {
				break;
			}
		}
	}
	return result;
}

#endif