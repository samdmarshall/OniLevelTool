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
}