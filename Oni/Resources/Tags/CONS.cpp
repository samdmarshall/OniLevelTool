/*
 *  CONS.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "CONS.h"

CONS::CONS() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (CONSHeaderStruct *)malloc(sizeof(CONSHeaderStruct));
}

CONS::~CONS() {
	free(this->header);
	free(this->head);
}

void CONS::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(CONSHeaderStruct));
	
	this->instance_count = 2;
}

int32_t* CONS::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	instances[0] = ExtractLinkNumber(this->head->OFGA_link);
	instances[1] = ExtractLinkNumber(this->head->M3GM_link);
	
	return instances;
}

int32_t CONS::DataSize() {
	return sizeof(OniTMStruct) + sizeof(CONSHeaderStruct);
}

char* CONS::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(CONSHeaderStruct));
	return edata;
}