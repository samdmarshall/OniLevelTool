/*
 *  AGQC.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "AGQC.h"

AGQC::AGQC() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
	this->head = (AGQCHeaderStruct *)malloc(sizeof(AGQCHeaderStruct));
}

AGQC::~AGQC() {
	free(this->header);
	free(this->head);
	free(this->data);
}

void AGQC::Load(char *data) {
	memcpy(this->header, &data, sizeof(OniTMStruct));
	memcpy(this->head, &data[sizeof(OniTMStruct)], sizeof(AGQCHeaderStruct));
	
	this->data = (AGQCDataStruct *)malloc(sizeof(AGQCDataStruct)*this->head->array_size);
	for (int32_t i = 0; i < this->head->array_size; i++) {
		memcpy(this->data, &data[(sizeof(OniTMStruct)+sizeof(AGQCHeaderStruct))+(sizeof(AGQCDataStruct)*i)], sizeof(AGQCDataStruct));
	}
}