/*
 *  OniTM.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/1/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

OniTM::OniTM() {
	this->header = (OniTMStruct *)malloc(sizeof(OniTMStruct));
}

OniTM::~OniTM() {
	free(this->header);
}