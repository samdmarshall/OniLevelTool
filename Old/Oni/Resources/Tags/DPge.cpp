/*
 *  DPge.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "DPge.h"

DPge::DPge() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (DPgeHeaderStruct *)malloc(sizeof(DPgeHeaderStruct));
}

DPge::~DPge() {
	free(this->header);
	free(this->head);
}

void DPge::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(DPgeHeaderStruct));
	
	this->instance_count = 1;
}

int32_t* DPge::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t));
	instances[0] = ExtractLinkNumber(this->head->IGPG_link);
	
	return instances;
}

int32_t DPge::DataSize() {
	return sizeof(OniTMStruct) + sizeof(DPgeHeaderStruct);
}

char* DPge::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(DPgeHeaderStruct));
	return edata;
}