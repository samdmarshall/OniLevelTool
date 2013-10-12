//
//  OLTInstance.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTInstance_h
#define OniLevelTool_OLTInstance_h

#include "OLTTypes.h"
#include "OLTLevel.h"

typedef enum OLTDescriptorFlags {
	OLTDescriptorFlags_None = 0,
	OLTDescriptorFlags_Unique = (1 << 0),
	OLTDescriptorFlags_PlaceHolder = (1 << 1),
	OLTDescriptorFlags_Shared = (1 << 2),
	OLTDescriptorFlags_Source = (1 << 3)
} OLTDescriptorFlags;

char* GetNameOfInstanceInLevel(struct OLTInstance *instance, struct OLTLevel *level);

#endif
