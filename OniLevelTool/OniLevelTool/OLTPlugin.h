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
} ATR_PACK;

#define OLTPluginPropertyTypeCount 7

const static struct OLTPluginPropertyTypeName OLTPluginPropertyType_names[OLTPluginPropertyTypeCount] = {
	{OLTPluginPropertyType_byte8, "byte8"},
	{OLTPluginPropertyType_byte4, "byte4"},
	{OLTPluginPropertyType_byte2, "byte2"},
	{OLTPluginPropertyType_byte1, "byte1"},
	{OLTPluginPropertyType_array, "array"},
	{OLTPluginPropertyType_vararray, "vararray"},
	{OLTPluginPropertyType_template, "template"}
};

#define OLTPluginPropertySize(type) OLTPluginPropertySize_##type

const static uint32_t OLTPluginPropertySize_byte8 = 8;
const static uint32_t OLTPluginPropertySize_byte4 = 4;
const static uint32_t OLTPluginPropertySize_byte2 = 2;
const static uint32_t OLTPluginPropertySize_byte1 = 1;
const static uint32_t OLTPluginPropertySize_array = 0;
const static uint32_t OLTPluginPropertySize_vararray = 0;
const static uint32_t OLTPluginPropertySize_template = 0;

struct OLTDataValue {
	char *name;
	uint32_t value;
} ATR_PACK;

struct OLTDataType {
	char *name;
	uint32_t offset;
	struct OLTPluginPropertyTypeName *format;
	struct OLTDataType *properties;
	uint32_t propCount;
	struct OLTDataValue *values;
	uint32_t valueCount;
} ATR_PACK;

struct OLTPlugin {
	char *class;
	uint64_t checkSum;
	struct OLTDataType *types;
	uint32_t count;
} ATR_PACK;

struct OLTKnownTypes {
	struct OLTPlugin *tags;
	uint32_t count;
} ATR_PACK;

struct OLTKnownTypes* LoadPluginsAtPath(char *path);
struct OLTPlugin BuildTagFromPluginAtPath(char *path);
bool VerifyTagTemplate(struct OLTInstance *instance, struct OLTKnownTypes *plugins);

#endif
