/*
 *  AKBP.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKBP.h"

AKBP::AKBP() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AKBPHeaderStruct *)malloc(sizeof(AKBPHeaderStruct));
}

AKBP::~AKBP() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AKBP::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AKBPHeaderStruct));
	
	this->data = (AKBPDataStruct *)malloc(sizeof(AKBPDataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AKBPHeaderStruct))], sizeof(AKBPDataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*0;
}

int32_t* AKBP::GetInstanceIDs() {
	return 0;
}

int32_t AKBP::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKBPHeaderStruct) + (sizeof(AKBPDataStruct)*this->head->array_size);
}

char* AKBP::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AKBPHeaderStruct));
	position = position + sizeof(AKBPHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AKBPDataStruct));
		position = position + sizeof(AKBPDataStruct);
	}
	return edata;
}