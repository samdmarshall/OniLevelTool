/*
 *  AGQG.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AGQG.h"

AGQG::AGQG() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AGQGHeaderStruct *)malloc(sizeof(AGQGHeaderStruct));
}

AGQG::~AGQG() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AGQG::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AGQGHeaderStruct));
	
	this->data = (AGQGDataStruct *)malloc(sizeof(AGQGDataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AGQGHeaderStruct))], sizeof(AGQGDataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*9;
}

int32_t* AGQG::GetInstanceIDs() {
	int32_t* instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[(9*i)] = this->data[i].PNTA_id_v1;
		instances[(9*i)+1] = this->data[i].PNTA_id_v2;
		instances[(9*i)+2] = this->data[i].PNTA_id_v3;
		instances[(9*i)+3] = this->data[i].PNTA_id_v4;
		
		instances[(9*i)+4] = this->data[i].TXCA_id_v1;
		instances[(9*i)+5] = this->data[i].TXCA_id_v2;
		instances[(9*i)+6] = this->data[i].TXCA_id_v3;
		instances[(9*i)+7] = this->data[i].TXCA_id_v4;
		
		instances[(9*i)+8] = this->data[i].object_id;
	}
	return instances;
}

int32_t AGQG::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AGQGHeaderStruct) + (sizeof(AGQGDataStruct)*this->head->array_size);
}

char* AGQG::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(AGQGHeaderStruct));
	position = position + sizeof(AGQGHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(AGQGDataStruct));
		position = position + sizeof(AGQGDataStruct);
	}
	return edata;
}