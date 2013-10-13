//
//  OLTPlugin.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTPlugin_c
#define OniLevelTool_OLTPlugin_c

#include "OLTPlugin.h"

bool VerifyTemplateWithPlugin(struct OLTTemplateDefinition *templateDefinition, struct OLTPlugin *plugin);
struct OLTProperty BuildDataTypeWithOffset(xmlNode *node, uint32_t offset);

uint32_t GetTypeForData(xmlAttr *node) {
	uint32_t type = 0x0;
	xmlAttr *nodeAttr = NULL;
	for (nodeAttr = node; nodeAttr; nodeAttr = nodeAttr->next) {
		if (strcmp((char *)nodeAttr->name, "type")==0x0) {
			type = (uint32_t)strtol((char *)nodeAttr->children->content, NULL, 0xa);
		}
	}
	return type;
}

uint32_t GetSizeForData(xmlAttr *node) {
	uint32_t size = 0x0;
	xmlAttr *nodeAttr = NULL;
	for (nodeAttr = node; nodeAttr; nodeAttr = nodeAttr->next) {
		if (strcmp((char *)nodeAttr->name, "size")==0x0) {
			size = (uint32_t)strtol((char *)nodeAttr->children->content, NULL, 0xa);
		}
	}
	return size;
}

uint32_t GetOffsetForData(xmlAttr *node) {
	uint32_t offset = 0x0;
	xmlAttr *nodeAttr = NULL;
	for (nodeAttr = node; nodeAttr; nodeAttr = nodeAttr->next) {
		if (strcmp((char *)nodeAttr->name, "offset")==0x0) {
			offset = (uint32_t)strtol((char *)nodeAttr->children->content, NULL, 0x10);
		}
	}
	return offset;
}

char* GetNameForData(xmlAttr *node) {
	char *name = "unnamed";
	xmlAttr *nodeAttr = NULL;
	for (nodeAttr = node; nodeAttr; nodeAttr = nodeAttr->next) {
		if (strcmp((char *)nodeAttr->name, "name")==0x0) {
			name = calloc(strlen((char *)nodeAttr->children->content), 0x1);
			name = strncpy(name, (char *)nodeAttr->children->content, strlen((char *)nodeAttr->children->content));
		}
	}
	return name;
}

bool HasValidType(xmlNode *node) {
	bool result = false;
	for (uint32_t typeNum = 0x0; typeNum < OLTPluginPropertyTypeCount; typeNum++) {
		if (strcmp((char*)node->name, OLTPluginPropertyType_names[typeNum].name)==0x0) {
			result = true;
			break;
		}
	}
	return result;
}

uint32_t PluginPropertyTypeIndexFromName(char *name) {
	uint32_t typeNum;
	for (typeNum = 0x0; typeNum < OLTPluginPropertyTypeCount; typeNum++) {
		if (strcmp((char*)name, OLTPluginPropertyType_names[typeNum].name)==0x0) break;
	}
	return typeNum;
}

struct OLTProperty BuildDataType(xmlNode *node) {
	return BuildDataTypeWithOffset(node, 0x0);
}

struct OLTProperty BuildDataTypeWithOffset(xmlNode *node, uint32_t offset) {
	struct OLTProperty prop;
	prop.name = GetNameForData(node->properties);
	prop.offset = GetOffsetForData(node->properties)+offset;
	prop.type = PluginPropertyTypeIndexFromName((char*)node->name);
	
	prop.properties = calloc(sizeof(struct OLTProperty), 0x1);
	prop.propertyCount = 0x0;
	prop.value = calloc(sizeof(struct OLTPropertyValue), 0x1);
	prop.valueCount = 0x0;

	switch (prop.type) {
		case OLTPluginPropertyType_byte8:
		case OLTPluginPropertyType_byte4:
		case OLTPluginPropertyType_byte2:
		case OLTPluginPropertyType_byte1: {
			uint32_t subtypeNum = GetTypeForData(node->properties);
			prop.valueCount = OLTPluginPropertyType_names[prop.type].size/OLTPluginPropertySubtype_names[subtypeNum].size;
			for (uint8_t i = 0; i < prop.valueCount; i++) {
				prop.value = realloc(prop.value, (sizeof(struct OLTPropertyValue)*(i+0x1)));
				prop.value[i].subtype = subtypeNum;
			}
		};
		case OLTPluginPropertyType_array: {
			uint32_t size = GetSizeForData(node->properties);
			prop.valueCount = 1;
			prop.value = realloc(prop.value, (sizeof(struct OLTPropertyValue)*prop.valueCount));
			prop.value[0].subtype = GetTypeForData(node->properties);
			for (uint32_t i = 0; i < size; i++) {
				if (node->children) {
					xmlNode *childProps = NULL;
					for (childProps = node->children; childProps; childProps = childProps->next) {
						if (childProps->type == XML_ELEMENT_NODE) {
							if (HasValidType(childProps)) {
								prop.properties = realloc(prop.properties, sizeof(struct OLTProperty)*(prop.propertyCount+0x1));
								prop.properties[prop.propertyCount] = BuildDataTypeWithOffset(childProps, (OLTPluginPropertyType_names[prop.type].size*i));
								prop.propertyCount++;
							}
						}
					}
				}
			}
			break;
		};
		case OLTPluginPropertyType_vararray: {
			prop.valueCount = 1;
			prop.value = realloc(prop.value, (sizeof(struct OLTPropertyValue)*prop.valueCount));
			prop.value[0].subtype = GetTypeForData(node->properties);
			if (node->children) {
				xmlNode *childProps = NULL;
				for (childProps = node->children; childProps; childProps = childProps->next) {
					if (childProps->type == XML_ELEMENT_NODE) {
						if (HasValidType(childProps)) {
							prop.properties = realloc(prop.properties, sizeof(struct OLTProperty)*(prop.propertyCount+0x1));
							prop.properties[prop.propertyCount] = BuildDataType(childProps);
							prop.propertyCount++;
						}
					}
				}
			}
			break;
		};
		case OLTPluginPropertyType_template: {
			prop.valueCount = 1;
			prop.value = realloc(prop.value, (sizeof(struct OLTPropertyValue)*prop.valueCount));
			prop.value[0].subtype = GetTypeForData(node->properties);
			break;
		};
		default: {
			break;
		};
	}
	return prop;
}

struct OLTPlugin GenerateTagFromPlugin(xmlNode *root) {
	struct OLTPlugin tag;
	if (root->properties && root->properties->children) {
		tag.class = calloc(strlen((char*)root->properties->children->content), 0x1);
		tag.class = strncpy(tag.class, (char*)root->properties->children->content, strlen((char*)root->properties->children->content));
		tag.checkSum = strtol((char*)root->properties->next->children->content,NULL,0xa);
		tag.property = calloc(sizeof(struct OLTProperty), 0x1);
		tag.propertyCount = 0x0;
		xmlNode *cur_node = root->children;
		while ((cur_node = cur_node->next)) {
			if (cur_node->type == XML_ELEMENT_NODE) {
				if (HasValidType(cur_node)) {
					tag.property = realloc(tag.property, sizeof(struct OLTProperty)*(tag.propertyCount+1));
					tag.property[tag.propertyCount] = BuildDataType(cur_node);
					tag.propertyCount++;
				}
			}
		}
	}
	return tag;
}

struct OLTKnownTypes* LoadPluginsAtPath(char *path) {
	LIBXML_TEST_VERSION
	struct OLTKnownTypes *loadedTypes = calloc(sizeof(struct OLTKnownTypes), 0x1);
	loadedTypes->count = 0x0;
	loadedTypes->tags = (struct OLTPlugin*)calloc(0x1, sizeof(struct OLTPlugin));
	char *full_file_name = calloc(strlen(path)+0x1, 0x1);
	DIR *dir;
	struct dirent *ent;
	dir = opendir(path);
	while ((ent = readdir(dir)) != NULL) {
		char *file_name = ent->d_name;
		if (file_name[0x0] != '.') {
			full_file_name = realloc(full_file_name, strlen(path)+strlen(file_name)+0x2);
			strncpy(full_file_name, path, strlen(path));
			if (strncmp(&(path[strlen(path)]), "/", 0x1)!=0) {
				strncpy(&(full_file_name[strlen(path)]), "/", 1);
			}
			strncpy(&(full_file_name[strlen(path)+1]), file_name, strlen(file_name)+0x1);
			loadedTypes->tags = realloc(loadedTypes->tags, sizeof(struct OLTPlugin)*(loadedTypes->count+0x1));
			loadedTypes->tags[loadedTypes->count] = BuildTagFromPluginAtPath(full_file_name);
			loadedTypes->count++;
		}
	}
	free(full_file_name);
	xmlCleanupParser();
	closedir(dir);
	return loadedTypes;
}

struct OLTPlugin BuildTagFromPluginAtPath(char *path) {
	struct OLTPlugin loadedTag = (struct OLTPlugin){0x0, 0x0};
	if (path) {
		SDMPrint(PrintCode_TRY, "Attempting to load plugin: %s",path);
		xmlDoc *doc = NULL;
		doc = xmlReadFile(path, NULL, 0x0);
		if (doc != NULL) {
			xmlNode *root_element = xmlDocGetRootElement(doc);
			if (strncmp(&(path[strlen(path)-0x4]), "otag", 0x4)==0) {
				loadedTag = GenerateTagFromPlugin(root_element);
			}
			SDMPrint(PrintCode_OK, "Loaded plugin: %s",loadedTag.class);
		} else {
			SDMPrint(PrintCode_ERR, "Failed to load plugin: %s",path);
		}
		printf("\n");
		xmlFreeDoc(doc);
	}
	return loadedTag;
}

uint32_t TagPluginIndex(struct OLTInstance *instance, struct OLTKnownTypes *plugins) {
	uint32_t i;
	uint32_t index = TagTemplateIndex(instance);
	bool result = false;
	for (i = 0; i < plugins->count; i++) {
		result = VerifyTemplateWithPlugin((struct OLTTemplateDefinition*)&(OLTTemplate_types[index]), &(plugins->tags[i]));
		if (result) {
			break;
		}
	}
	return i;
}

bool VerifyTagTemplate(struct OLTInstance *instance, struct OLTKnownTypes *plugins) {
	bool result = false;
	uint32_t index = TagTemplateIndex(instance);
	for (uint32_t i = 0; i < plugins->count; i++) {
		result = VerifyTemplateWithPlugin((struct OLTTemplateDefinition*)&(OLTTemplate_types[index]), &(plugins->tags[i]));
		if (result) {
			break;
		}
	}
	return result;
}

bool VerifyTemplateWithPlugin(struct OLTTemplateDefinition *templateDefinition, struct OLTPlugin *plugin) {
	return (templateDefinition->checkSum == plugin->checkSum);
}

#endif