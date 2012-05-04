/*
 *  ABNA.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "ABNA.h"

ABNA::ABNA() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (ABNAHeaderStruct *)malloc(sizeof(ABNAHeaderStruct));
}

ABNA::~ABNA() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void ABNA::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(ABNAHeaderStruct));
	
	this->data = (ABNADataStruct *)malloc(sizeof(ABNADataStruct)*this->head->array_size);
	memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(ABNAHeaderStruct))], sizeof(ABNADataStruct)*this->head->array_size);
	
	this->instance_count = this->head->array_size*2;
}

int32_t* ABNA::GetInstanceIDs() {
	int32_t *instances = (int32_t *)malloc(sizeof(int32_t)*this->instance_count);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		instances[(2*i)] = this->data[i].AGQG_id;
		instances[(2*i)+1] = this->data[i].PLEA_id;
	}
	return instances;
}