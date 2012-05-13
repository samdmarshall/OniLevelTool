/*
 *  AKOT.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKOT.h"

AKOT::AKOT() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
}

AKOT::~AKOT() {
	free(this->header);
	free(this->data);
}

void AKOT::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	
	this->data = (AKOTDataStruct *)malloc(sizeof(AKOTDataStruct));
	memcpy(this->data, &data[sizeof(OniTMStruct)], sizeof(AKOTDataStruct));
	
	this->instance_count = 5;
}

int32_t* AKOT::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	instances[0] = this->data->OTIT_link;
	instances[1] = this->data->OTLF_link;
	instances[2] = this->data->QTNA_link;
	instances[3] = this->data->IDXA_link1;
	instances[4] = this->data->IDXA_link2;
	return instances;
}

int32_t AKOT::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKOTDataStruct);
}

char* AKOT::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[sizeof(OniTMStruct)], this->data, sizeof(AKOTDataStruct));
	return edata;
}