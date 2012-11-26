/*
 *  Maths.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/4/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include <math.h>

#ifndef _MathsHeader
#define _MathsHeader
static inline int32_t CharToInt(char cnum[4]) {
	int32_t num = 0;
	num |= ( cnum[0] << 24 );
	num |= ( cnum[1] << 16 );
	num |= ( cnum[2] <<  8 );
	num |= ( cnum[3]       );
	return num;
};

static inline int32_t GetResID(char res[4]) {
	return (CharToInt(res) & 0x00FFFFFF);
}

static inline uint64_t GetFileSizeDelta(int64_t num) {	
	return (uint64_t)((num < 0) ? 0 : num);
}

#endif