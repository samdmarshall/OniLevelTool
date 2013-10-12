/*
 *  AKEV.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AKEV.h"

AKEV::AKEV() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
}

AKEV::~AKEV() {
	free(this->header);
	free(this->data);
}

void AKEV::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	
	this->data = (AKEVDataStruct *)malloc(sizeof(AKEVDataStruct));
	memcpy(this->data, &data[sizeof(OniTMStruct)], sizeof(AKEVDataStruct));
	
	this->instance_count = 17;
}

int32_t* AKEV::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	instances[0] = ExtractLinkNumber(this->data->PNTA_link);
	instances[1] = ExtractLinkNumber(this->data->PLEA_link);
	instances[2] = ExtractLinkNumber(this->data->TXCA_link);
	instances[3] = ExtractLinkNumber(this->data->AGQG_link);
	instances[4] = ExtractLinkNumber(this->data->AGQR_link);
	instances[5] = ExtractLinkNumber(this->data->AGQC_link);
	instances[6] = ExtractLinkNumber(this->data->AGDB_link);
	instances[7] = ExtractLinkNumber(this->data->TXMA_link);
	instances[8] = ExtractLinkNumber(this->data->AKVA_link);
	instances[9] = ExtractLinkNumber(this->data->AKBA_link);
	instances[10] = ExtractLinkNumber(this->data->IDXA_link1);
	instances[11] = ExtractLinkNumber(this->data->IDXA_link2);
	instances[12] = ExtractLinkNumber(this->data->AKBP_link);
	instances[13] = ExtractLinkNumber(this->data->ABNA_link);
	instances[14] = ExtractLinkNumber(this->data->AKOT_link);
	instances[15] = ExtractLinkNumber(this->data->AKAA_link);
	instances[16] = ExtractLinkNumber(this->data->AKDA_link);
	return instances;
}

int32_t AKEV::DataSize() {
	return sizeof(OniTMStruct) + sizeof(AKEVDataStruct);
}

char* AKEV::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[sizeof(OniTMStruct)], this->data, sizeof(AKEVDataStruct));
	return edata;
}