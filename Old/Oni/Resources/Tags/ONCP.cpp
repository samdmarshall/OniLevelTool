/*
 *  ONCP.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/11/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "ONCP.h"

ONCP::ONCP() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (ONCPHeaderStruct *)malloc(sizeof(ONCPHeaderStruct));
}

ONCP::~ONCP() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void ONCP::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(ONCPHeaderStruct));
	
	this->data = (ONCPDataStruct *)malloc(sizeof(ONCPDataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(ONCPHeaderStruct))], sizeof(ONCPDataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*0;
}

int32_t* ONCP::GetInstanceIDs() {
	return 0;
}

int32_t ONCP::DataSize() {
	return sizeof(OniTMStruct) + sizeof(ONCPHeaderStruct) + (sizeof(ONCPDataStruct)*this->head->array_size);
}

char* ONCP::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(ONCPHeaderStruct));
	position = position + sizeof(ONCPHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(ONCPDataStruct));
		position = position + sizeof(ONCPDataStruct);
	}
	return edata;
}