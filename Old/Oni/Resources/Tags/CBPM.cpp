/*
 *  CBPM.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "CBPM.h"

CBPM::CBPM() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
}

CBPM::~CBPM() {
	free(this->header);
	free(this->data);
}

void CBPM::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	
	this->data = (CBPMDataStruct *)malloc(sizeof(CBPMDataStruct));
	memcpy(this->data, &data[sizeof(OniTMStruct)], sizeof(CBPMDataStruct));
	
	this->instance_count = 19;
}

int32_t* CBPM::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < 19; i++) {
		instances[i] = ExtractLinkNumber(this->data->material[i].Mtrl_link);
	}
	return instances;
}

int32_t CBPM::DataSize() {
	return sizeof(OniTMStruct) + sizeof(CBPMDataStruct);
}

char* CBPM::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[sizeof(OniTMStruct)], this->data, sizeof(CBPMDataStruct));
	return edata;
}