//
//  OLTPlugin.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTPlugin_h
#define OniLevelTool_OLTPlugin_h

#include "OLTTypes.h"
#include "OLTTemplate.h"

enum OLTPluginPropertyTypes {
	OLTPluginPropertyType_byte8 = 1,
	OLTPluginPropertyType_byte4 = 2,
	OLTPluginPropertyType_byte2 = 3,
	OLTPluginPropertyType_byte1 = 4,
	OLTPluginPropertyType_array = 5,
	OLTPluginPropertyType_vararray = 6,
	OLTPluginPropertyType_template = 7
};

enum OLTPluginPropertySubtypes {
	OLTPluginPropertySubtype_bitmask = 1,
	OLTPluginPropertySubtype_char = 2,
	OLTPluginPropertySubtype_int8 = 3,
	OLTPluginPropertySubtype_uint8 = 4,
	OLTPluginPropertySubtype_int16 = 5,
	OLTPluginPropertySubtype_uint16 = 6,
	OLTPluginPropertySubtype_float = 7,
	OLTPluginPropertySubtype_int32 = 8,
	OLTPluginPropertySubtype_uint32 = 9,
	OLTPluginPropertySubtype_int64 = 10,
	OLTPluginPropertySubtype_uint64 = 11
};

struct OLTPluginPropertyTypeName {
	enum OLTPluginPropertyTypes type;
	char *name;
};

#define OLTPluginPropertySize(type) OLTPluginPropertySize_##type

static uint32_t OLTPluginPropertySize_byte8 = 8;
static uint32_t OLTPluginPropertySize_byte4 = 4;
static uint32_t OLTPluginPropertySize_byte2 = 2;
static uint32_t OLTPluginPropertySize_byte1 = 1;
static uint32_t OLTPluginPropertySize_array = 0;
static uint32_t OLTPluginPropertySize_vararray = 0;
static uint32_t OLTPluginPropertySize_template = 4;

#endif
