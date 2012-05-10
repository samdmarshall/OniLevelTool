/*
 *  AGQC.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AGQC.h"

AGQC::AGQC() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AGQCHeaderStruct *)malloc(sizeof(AGQCHeaderStruct));
}

AGQC::~AGQC() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AGQC::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AGQCHeaderStruct));
	
	this->data = (AGQCDataStruct *)malloc(sizeof(AGQCDataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AGQCHeaderStruct))], sizeof(AGQCDataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size;
}

int32_t* AGQC::GetInstanceIDs() {
	int32_t* instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[i] = this->data[i].PLEA_id;
	}
	return instances;
}

uint64_t AGQC::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AGQCHeaderStruct) + (sizeof(AGQCDataStruct)*this->head->array_size);
}

char* AGQC::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AGQCHeaderStruct));
	position = position + sizeof(AGQCHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AGQCDataStruct));
		position = position + sizeof(AGQCDataStruct);
	}
	return edata;
}