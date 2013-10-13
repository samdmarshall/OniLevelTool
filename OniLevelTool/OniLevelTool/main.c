//
//  main.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#include "OLTLevel.h"
#include "OLTTemplate.h"
#include "OLTPlugin.h"

int main(int argc, const char * argv[]) {
	struct OLTKnownTypes *tagTypes = LoadPluginsAtPath("/Volumes/Data/Users/sam/git Projects/OniLevelTool/OniLevelTool/Plugins/");
	struct OLTLevel *level = ParseLevelFromFile("/Applications/Oni/GameDataFolder/level1_Final.dat");
	for (uint32_t i = 0; i < level->header->instanceCount; i++) {
		if (ValidTagType(&level->instance[i], level)) {
			if (VerifyTagTemplate(&level->instance[i], tagTypes)) {
				SDMPrint(PrintCode_OK, "Valid Tag!");
			}
		}
	}

    return 0;
}

