/*
 *  AGQR.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AGQR.h"

AGQR::AGQR() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AGQRHeaderStruct *)malloc(sizeof(AGQRHeaderStruct));
}

AGQR::~AGQR() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AGQR::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AGQRHeaderStruct));
	
	this->data = (AGQRDataStruct *)malloc(sizeof(AGQRDataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AGQRHeaderStruct))], sizeof(AGQRDataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size;
}

int32_t* AGQR::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[i] = ExtractLinkNumber(this->data[i].TXMA_id);
	}
	return instances;
}

int32_t AGQR::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AGQRHeaderStruct) + (sizeof(AGQRDataStruct)*this->head->array_size);
}

char* AGQR::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AGQRHeaderStruct));
	position = position + sizeof(AGQRHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AGQRDataStruct));
		position = position + sizeof(AGQRDataStruct);
	}
	return edata;
}