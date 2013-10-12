/*
 *  AKBA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKBA.h"

AKBA::AKBA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AKBAHeaderStruct *)malloc(sizeof(AKBAHeaderStruct));
}

AKBA::~AKBA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AKBA::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AKBAHeaderStruct));
	
	this->data = (AKBADataStruct *)malloc(sizeof(AKBADataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AKBAHeaderStruct))], sizeof(AKBADataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*0;
}

int32_t* AKBA::GetInstanceIDs() {
	return 0;
}

int32_t AKBA::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKBAHeaderStruct) + (sizeof(AKBADataStruct)*this->head->array_size);
}

char* AKBA::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AKBAHeaderStruct));
	position = position + sizeof(AKBAHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AKBADataStruct));
		position = position + sizeof(AKBADataStruct);
	}
	return edata;
}