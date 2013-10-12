/*
 *  AKVA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKVA.h"

AKVA::AKVA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AKVAHeaderStruct *)malloc(sizeof(AKVAHeaderStruct));
}

AKVA::~AKVA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AKVA::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AKVAHeaderStruct));
	
	this->data = (AKVADataStruct *)malloc(sizeof(AKVADataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AKVAHeaderStruct))], sizeof(AKVADataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*0;
}

int32_t* AKVA::GetInstanceIDs() {
	return 0;
}

int32_t AKVA::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKVAHeaderStruct) + (sizeof(AKVADataStruct)*this->head->array_size);
}

char* AKVA::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AKVAHeaderStruct));
	position = position + sizeof(AKVAHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AKVADataStruct));
		position = position + sizeof(AKVADataStruct);
	}
	return edata;
}