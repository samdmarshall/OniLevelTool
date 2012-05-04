/*
 *  Maths.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/4/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include <math>

static inline int32_t CharToInt(char cnum[4]) {
	int32_t num = 0;
	num |= ( cnum[0] << 24 );
	num |= ( cnum[1] << 16 );
	num |= ( cnum[2] <<  8 );
	num |= ( cnum[3]       );
	return num;
};