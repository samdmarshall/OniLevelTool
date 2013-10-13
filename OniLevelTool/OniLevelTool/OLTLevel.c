//
//  OLTLevel.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTLevel_c
#define OniLevelTool_OLTLevel_c

#include "OLTLevel.h"

struct OLTBuffer* LoadFileToBuffer(char *path) {
	struct OLTBuffer *data = calloc(sizeof(struct OLTBuffer), 0x1);
	if (path) {
		FILE *levelFile = fopen(path, "r");
		if (levelFile) {
			fseek(levelFile, 0x0, SEEK_END);
			data->region.size = (uint32_t)ftell(levelFile);
			fseek(levelFile, 0x0, SEEK_SET);
			data->buffer = calloc(data->region.size, 0x1);
			fread(data->buffer, data->region.size, 0x1, levelFile);
		}
		fclose(levelFile);
	}
	return data;
}

struct OLTLevel* ParseLevelFromFile(char *path) {
	struct OLTLevel *level = calloc(sizeof(struct OLTLevel), 0x1);
	level->data = LoadFileToBuffer(path);
	if (level->data) {
		level->header = (struct OLTLevelHeader *)(&(level->data->buffer[level->data->region.offset]));
		level->data->region.offset += sizeof(struct OLTLevelHeader);
		if (level->header) {
			SDMPrint(PrintCode_OK, "Loading level data:");
			
			if (level->header->instanceCount) {
				level->instance = (struct OLTInstance *)(&(level->data->buffer[level->data->region.offset]));
				level->data->region.offset += sizeof(struct OLTInstance)*(level->header->instanceCount);
				SDMPrint(PrintCode_OK, "Found %i tag instances...",level->header->instanceCount);
			} else {
				SDMPrint(PrintCode_ERR, "No tag instances");
			}
			
			if (level->header->nameCount) {
				level->name = (struct OLTName *)(&(level->data->buffer[level->data->region.offset]));
				level->data->region.offset += sizeof(struct OLTName)*(level->header->nameCount);
				SDMPrint(PrintCode_OK, "Found %i names...",level->header->nameCount);
			} else {
				SDMPrint(PrintCode_ERR, "No tag names");
			}
			
			if (level->header->templateCount) {
				level->template = (struct OLTTemplate *)(&(level->data->buffer[level->data->region.offset]));
				level->data->region.offset += sizeof(struct OLTTemplate)*(level->header->templateCount);
				SDMPrint(PrintCode_OK, "Found %i templates...",level->header->templateCount);
			} else {
				SDMPrint(PrintCode_ERR, "No tag templates");
			}
			
		} else {
			SDMPrint(PrintCode_ERR, "Could not load header for level");
		}
	}
	return level;
}

#endif
