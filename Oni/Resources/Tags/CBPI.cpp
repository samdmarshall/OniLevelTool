/*
 *  CBPI.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "CBPI.h"

CBPI::CBPI() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
}

CBPI::~CBPI() {
	free(this->header);
	free(this->data);
}

void CBPI::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	
	this->data = (CBPIDataStruct *)malloc(sizeof(CBPIDataStruct));
	memcpy(this->data, &data[sizeof(OniTMStruct)], sizeof(CBPIDataStruct));
	
	this->instance_count = 19*3;
}

int32_t* CBPI::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < 19; i++) {
		instances[(3*i)] = this->data->hit[i].Impt_link;
		instances[(3*i)+1] = this->data->block[i].Impt_link;
		instances[(3*i)+2] = this->data->killed[i].Impt_link;
	}
	return instances;
}

int32_t CBPI::DataSize() {
	return sizeof(OniTMStruct)+ sizeof(CBPIDataStruct);
}

char* CBPI::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[sizeof(OniTMStruct)], this->data, sizeof(CBPIDataStruct));
	return edata;
}