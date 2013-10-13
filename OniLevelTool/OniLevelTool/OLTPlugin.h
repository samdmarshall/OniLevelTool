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

#pragma mark -
#pragma mark Plugin Types

enum OLTPluginPropertyTypes {
	OLTPluginPropertyType_invalid = 0,
	OLTPluginPropertyType_byte8 = 1,
	OLTPluginPropertyType_byte4 = 2,
	OLTPluginPropertyType_byte2 = 3,
	OLTPluginPropertyType_byte1 = 4,
	OLTPluginPropertyType_array = 5,
	OLTPluginPropertyType_vararray = 6,
	OLTPluginPropertyType_template = 7
};

struct OLTPluginPropertyTypeName {
	enum OLTPluginPropertyTypes type;
	char *name;
	uint8_t size;
} ATR_PACK;

#define OLTPluginPropertyTypeCount 8

const static struct OLTPluginPropertyTypeName OLTPluginPropertyType_names[OLTPluginPropertyTypeCount] = {
	{OLTPluginPropertyType_invalid, "invalid", 0},
	{OLTPluginPropertyType_byte8, "byte8", 8},
	{OLTPluginPropertyType_byte4, "byte4", 4},
	{OLTPluginPropertyType_byte2, "byte2", 2},
	{OLTPluginPropertyType_byte1, "byte1", 1},
	{OLTPluginPropertyType_array, "array", 0},
	{OLTPluginPropertyType_vararray, "vararray", 0},
	{OLTPluginPropertyType_template, "template", 0}
};

#pragma mark -
#pragma mark Plugin Subtypes

enum OLTPluginPropertySubtypes {
	OLTPluginPropertySubtype_invalid = 0,
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

struct OLTPluginPropertySubtypeName {
	enum OLTPluginPropertySubtypes subtype;
	char *name;
	uint8_t size;
} ATR_PACK;

#define OLTPluginPropertySubtypeCount 12

const static struct OLTPluginPropertySubtypeName OLTPluginPropertySubtype_names[OLTPluginPropertySubtypeCount] = {
	{OLTPluginPropertySubtype_invalid, "invalid", 0},
	{OLTPluginPropertySubtype_bitmask, "bitmask", 1},
	{OLTPluginPropertySubtype_char, "char", 1},
	{OLTPluginPropertySubtype_int8, "int8", 1},
	{OLTPluginPropertySubtype_uint8, "uint8", 1},
	{OLTPluginPropertySubtype_int16, "int16", 2},
	{OLTPluginPropertySubtype_uint16, "uint16", 2},
	{OLTPluginPropertySubtype_float, "float", 4},
	{OLTPluginPropertySubtype_int32, "int32", 4},
	{OLTPluginPropertySubtype_uint32, "uint32", 4},
	{OLTPluginPropertySubtype_int64, "int64", 8},
	{OLTPluginPropertySubtype_uint64, "uint64", 8}
};

#pragma mark -
#pragma mark Types

struct OLTPropertyValue {
	enum OLTPluginPropertySubtypes subtype;
} ATR_PACK;

struct OLTProperty {
	char *name;
	uint32_t offset;
	enum OLTPluginPropertyTypes type;
	struct OLTPropertyValue *value;
	uint32_t valueCount;
	struct OLTProperty *properties;
	uint32_t propertyCount;
} ATR_PACK;

struct OLTPlugin {
	char *class;
	uint64_t checkSum;
	struct OLTProperty *property;
	uint32_t propertyCount;
} ATR_PACK;

struct OLTKnownTypes {
	struct OLTPlugin *tags;
	uint32_t count;
} ATR_PACK;

#pragma mark -
#pragma mark Functions

struct OLTKnownTypes* LoadPluginsAtPath(char *path);
struct OLTPlugin BuildTagFromPluginAtPath(char *path);
uint32_t TagPluginIndex(struct OLTInstance *instance, struct OLTKnownTypes *plugins);
bool VerifyTagTemplate(struct OLTInstance *instance, struct OLTKnownTypes *plugins);

#endif
