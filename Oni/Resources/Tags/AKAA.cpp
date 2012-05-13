/*
 *  AKAA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKAA.h"

AKAA::AKAA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AKAAHeaderStruct *)malloc(sizeof(AKAAHeaderStruct));
}

AKAA::~AKAA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AKAA::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AKAAHeaderStruct));
	
	this->data = (AKAADataStruct *)malloc(sizeof(AKAADataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AKAAHeaderStruct))], sizeof(AKAADataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*2;
}

int32_t* AKAA::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[(2*i)] = this->data[i].AKVA_id;
		instances[(2*i)+1] = this->data[i].AGQG_id;
	}
	return instances;
}

int32_t AKAA::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKAAHeaderStruct) + (sizeof(AKAADataStruct)*this->head->array_size);
}

char* AKAA::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AKAAHeaderStruct));
	position = position + sizeof(AKAAHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AKAADataStruct));
		position = position + sizeof(AKAADataStruct);
	}
	return edata;
}