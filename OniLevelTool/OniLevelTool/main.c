//
//  main.c
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//


#include "OLTTag.h"
#include <libxml/schemasInternals.h>


#include <sys/stat.h>
#include <sys/types.h>
u_int32_t get_file_size(const char *file_name) {
    struct stat buf;
    if ( stat(file_name, &buf) != 0 ) return(0);
    return (unsigned int)buf.st_size;
}

void handleValidationError(void *ctx, const char *format, ...) {
    char *errMsg;
    va_list args;
    va_start(args, format);
    vasprintf(&errMsg, format, args);
    va_end(args);
    fprintf(stderr, "Validation Error: %s", errMsg);
    free(errMsg);
}

void BuildTagSchemaFromNode(xmlNode *node) {
    if (node->properties && node->properties->children) {
        xmlNode *cur_node = node->children;
        while ((cur_node = cur_node->next)) {
            if (cur_node->type == XML_ELEMENT_NODE) {
                BuildTagSchemaFromNode(cur_node);
            }
        }
    }
}

void LoadTagSchemaFromPath(char *schemaPath, char *tagPath) {
    const char *xsdPath = schemaPath;
    const char *xmlPath = tagPath;
    
    printf("\n");
    
    printf("XSD File: %s\n", xsdPath);
    printf("XML File: %s\n", xmlPath);
    
    int xmlLength = get_file_size(xmlPath);
    char *xmlSource = (char *)malloc(sizeof(char) * xmlLength);
    
    FILE *p = fopen(xmlPath, "r");
    char c;
    unsigned int i = 0;
    while ((c = fgetc(p)) != EOF) {
        xmlSource[i++] = c;
    }
    printf("\n");
    
    printf("XML Source:\n\n%s\n", xmlSource);
    fclose(p);
    
    printf("\n");
    
    int result = 42;
    xmlSchemaParserCtxtPtr parserCtxt = NULL;
    xmlSchemaPtr schema = NULL;
    xmlSchemaValidCtxtPtr validCtxt = NULL;
    
    xmlDocPtr xmlDocumentPointer = xmlParseMemory(xmlSource, xmlLength);
    parserCtxt = xmlSchemaNewParserCtxt(xsdPath);
    
    if (parserCtxt == NULL) {
        fprintf(stderr, "Could not create XSD schema parsing context.\n");
        goto leave;
    }
    
    schema = xmlSchemaParse(parserCtxt);
    
    if (schema == NULL) {
        fprintf(stderr, "Could not parse XSD schema.\n");
        goto leave;
    }
    
    validCtxt = xmlSchemaNewValidCtxt(schema);
    
    if (!validCtxt) {
        fprintf(stderr, "Could not create XSD schema validation context.\n");
        goto leave;
    }
    
    xmlSetStructuredErrorFunc(NULL, NULL);
    xmlSetGenericErrorFunc(NULL, handleValidationError);
    xmlThrDefSetStructuredErrorFunc(NULL, NULL);
    xmlThrDefSetGenericErrorFunc(NULL, handleValidationError);
    
    result = xmlSchemaValidateDoc(validCtxt, xmlDocumentPointer);
    
leave:
    
    if (parserCtxt) {
        xmlSchemaFreeParserCtxt(parserCtxt);
    }
    
    if (schema) {
        xmlSchemaFree(schema);
    }
    
    if (validCtxt) {
        xmlSchemaFreeValidCtxt(validCtxt);
    }
    printf("\n");
    printf("Validation successful: %s (result: %d)\n", (result == 0) ? "YES" : "NO", result);
}

int main(int argc, const char * argv[]) {
	struct OLTKnownTypes *tagTypes = LoadPluginsAtPath("/Users/sam/Projects/OniLevelTool/OniLevelTool/Plugins");
	struct OLTLevel *level = ParseLevelFromFile("/Applications/Oni/GameDataFolder/level1_Final.dat");
	struct OLTTagContainer levelData = OpenLevelWithPlugins(level, tagTypes);
	for (uint32_t i = 0; i < levelData.tagCount; i++) {
		printf("%s %s\n",levelData.tags[i].plugin->class,GetNameOfInstanceInLevel(levelData.tags[i].instance, levelData.tags[i].level));
    }
    //LoadTagSchemaFromPath("/Users/sam/Desktop/TRAM.schema", "/Users/sam/Desktop/TRAMKONCOMbk_fw_kick.xml");
    return 0;
}

