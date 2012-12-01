/*
 *  CRSA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "CRSA.h"

CRSA::CRSA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (CRSAHeaderStruct *)malloc(sizeof(CRSAHeaderStruct));
}

CRSA::~CRSA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void CRSA::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(CRSAHeaderStruct));
	
	this->data = (CRSADataStruct *)malloc(sizeof(CRSADataStruct)*this->head->array_capacity);
	memcpy(this->data, &data[sizeof(OniTMStruct)+sizeof(CRSAHeaderStruct)], sizeof(CRSADataStruct)*this->head->array_capacity);
	
	this->instance_count = this->head->array_capacity;
}

int32_t* CRSA::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_capacity; i++) {
		instances[i] = ExtractLinkNumber(this->data[i].ONCC_link);
	}
	return instances;
}


int32_t CRSA::DataSize() {
	return sizeof(OniTMStruct) + sizeof(CRSAHeaderStruct) + (sizeof(CRSADataStruct)*this->head->array_capacity);	
}

char* CRSA::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(CRSAHeaderStruct));
	position = position + sizeof(CRSAHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(CRSADataStruct));
		position = position + sizeof(CRSADataStruct);
	}
	return edata;
}