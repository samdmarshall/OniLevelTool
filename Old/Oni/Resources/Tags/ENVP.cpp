/*
 *  ENVP.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "ENVP.h"

ENVP::ENVP() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (ENVPHeaderStruct *)malloc(sizeof(ENVPHeaderStruct));
}

ENVP::~ENVP() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void ENVP::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(ENVPHeaderStruct));
	
	this->data = (ENVPDataStruct *)malloc(sizeof(ENVPDataStruct)*this->head->array_size);
	memcpy(this->data, &data[sizeof(OniTMStruct)+sizeof(ENVPHeaderStruct)], sizeof(ENVPDataStruct)*this->head->array_size);
	
	this->instance_count = 0;
}

int32_t* ENVP::GetInstanceIDs() {
	return 0;
}

int32_t ENVP::DataSize() {
	return sizeof(OniTMStruct) + sizeof(ENVPHeaderStruct) + (sizeof(ENVPDataStruct)*this->head->array_size);
}

char* ENVP::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(ENVPHeaderStruct));
	position = position + sizeof(ENVPHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(ENVPDataStruct));
		position = position + sizeof(ENVPDataStruct);
	}
	return edata;
}