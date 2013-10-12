/*
 *  DOOR.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "DOOR.h"

DOOR::DOOR() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (DOORHeaderStruct *)malloc(sizeof(DOORHeaderStruct));
}

DOOR::~DOOR() {
	free(this->header);
	free(this->head);
}

void DOOR::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(DOORHeaderStruct));
	
	this->instance_count = 3;
}

int32_t* DOOR::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	instances[0] = ExtractLinkNumber(this->head->OFGA_link1);
	instances[1] = ExtractLinkNumber(this->head->OFGA_link2);
	instances[2] = ExtractLinkNumber(this->head->OBAN_link);
	
	return instances;
}

int32_t DOOR::DataSize() {
	return sizeof(OniTMStruct) + sizeof(DOORHeaderStruct);
}

char* DOOR::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(DOORHeaderStruct));
	return edata;
}