//
//  OLTTypes.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTTypes_h
#define OniLevelTool_OLTTypes_h

#pragma mark -
#pragma mark Includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/xmlschemas.h>

#include "SDMPrint.h"

#pragma mark -
#pragma mark Macros

#define ATR_PACK __attribute__ ((packed))

#pragma mark -
#pragma mark Standard Types

#ifdef _WIN32
	typedef unsigned __int8 uint8_t;
	typedef signed __int8 int8_t;
	typedef unsigned __int16 uint16_t;
	typedef signed __int16 int16_t;
	typedef unsigned __int32 uint32_t;
	typedef signed __int32 int32_t;
	typedef unsigned __int64 uint64_t;
	typedef signed __int64 int64_t;
#else
	#include <stdint.h>
#endif

#pragma mark -
#pragma mark OLT Types

struct OLTRegion {
	uint32_t offset;
	uint32_t size;
} ATR_PACK;

struct OLTBuffer {
	char *buffer;
	struct OLTRegion region;
} ATR_PACK;

struct OLTInstance {
	char tagType[4];
	uint32_t dataOffset;
	uint32_t nameOffset;
	uint32_t dataSize;
	int32_t flags;
} ATR_PACK;

struct OLTName {
	uint32_t instanceNum;
	uint32_t runtimePointer;
} ATR_PACK;

struct OLTTemplate {
	int64_t checkSum;
	char templateTag[4];
	uint32_t useCount;
} ATR_PACK;

#endif
