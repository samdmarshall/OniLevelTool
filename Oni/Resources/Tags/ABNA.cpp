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
}