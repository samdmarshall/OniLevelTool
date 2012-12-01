/*
 *  FILM.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "FILM.h"

FILM::FILM() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (FILMHeaderStruct *)malloc(sizeof(FILMHeaderStruct));
}

FILM::~FILM() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void FILM::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(FILMHeaderStruct));
	
	this->data = (FILMDataStruct *)malloc(sizeof(FILMDataStruct)*this->head->array_size);
	memcpy(this->data, &data[sizeof(OniTMStruct)+sizeof(FILMHeaderStruct)], sizeof(FILMDataStruct)*this->head->array_size);
	
	this->instance_count = 0;
}

int32_t* FILM::GetInstanceIDs() {
	return 0;
}

int32_t FILM::DataSize() {
	return sizeof(OniTMStruct) + sizeof(FILMHeaderStruct) + (sizeof(FILMDataStruct)*this->head->array_size);
}

char* FILM::ExportData() {
	char *edata = (char *)malloc(sizeof(char)*this->DataSize());
	int32_t position = sizeof(OniTMStruct);
	memcpy(edata, this->header, sizeof(OniTMStruct));
	memcpy(&edata[position], this->head, sizeof(FILMHeaderStruct));
	position = position + sizeof(FILMHeaderStruct);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(&edata[position], &this->data[i], sizeof(FILMDataStruct));
		position = position + sizeof(FILMDataStruct);
	}
	return edata;
}