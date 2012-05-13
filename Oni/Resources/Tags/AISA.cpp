/*
 *  AISA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AISA.h"

AISA::AISA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AISAHeaderStruct *)malloc(sizeof(AISAHeaderStruct));
}

AISA::~AISA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AISA::Load(char *data) {
	memcpy(this->header, data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AISAHeaderStruct));
	
	this->data = (AISADataStruct *)malloc(sizeof(AISADataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AISAHeaderStruct))], sizeof(AISADataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*2;
}

int32_t* AISA::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[(2*i)] = this->data[i].ONCC_link_id;
		instances[(2*i)+1] = this->data[i].ONWC_link_id;
	}
	return instances;
}

int32_t AISA::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AISAHeaderStruct) + (sizeof(AISADataStruct)*this->head->array_size);
}

char* AISA::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AISAHeaderStruct));
	position = position + sizeof(AISAHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AISADataStruct));
		position = position + sizeof(AISADataStruct);
	}
	return edata;
}