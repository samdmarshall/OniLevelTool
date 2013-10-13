//
//  main.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//


#include "OLTTag.h"

int main(int argc, const char * argv[]) {
	struct OLTKnownTypes *tagTypes = LoadPluginsAtPath("/Volumes/Data/Users/sam/git Projects/OniLevelTool/OniLevelTool/Plugins");
	struct OLTLevel *level = ParseLevelFromFile("/Applications/Oni/GameDataFolder/level1_Final.dat");
	struct OLTTagContainer levelData = OpenLevelWithPlugins(level, tagTypes);
	for (uint32_t i = 0; i < levelData.tagCount; i++) {
		printf("%s %s\n",levelData.tags[i].plugin->class,GetNameOfInstanceInLevel(levelData.tags[i].instance, levelData.tags[i].level));
	}
    return 0;
}

