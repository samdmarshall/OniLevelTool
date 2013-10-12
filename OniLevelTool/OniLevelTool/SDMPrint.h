//
//  SDMPrint.h
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMPrint_h
#define SDMPrint_h

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#pragma mark -
#pragma mark Type

enum SDMPrintCodes {
	PrintCode_OK = 1,
	PrintCode_TRY = 2,
	PrintCode_ERR = 3
};

#pragma mark -
#pragma mark Color Codes

#define UseColorCodes 0 // SDM: Xcode console doesn't like these, but they work fine in a terminal

#define COLOR_NRM  "\x1B[0m"
#define COLOR_RED  "\x1B[31m"
#define COLOR_GRN  "\x1B[32m"
#define COLOR_YEL  "\x1B[33m"
#define COLOR_BLU  "\x1B[34m"
#define COLOR_MAG  "\x1B[35m"
#define COLOR_CYN  "\x1B[36m"
#define COLOR_WHT  "\x1B[37m"

#define SDMPrintCodeColor(code) (UseColorCodes ? (code == PrintCode_OK ? COLOR_GRN : (code == PrintCode_TRY ? COLOR_YEL : (code == PrintCode_ERR ? COLOR_RED : COLOR_BLU))) : "")
#define SDMPrintCode(code) (code == PrintCode_OK ? "OK!" : (code == PrintCode_TRY ? "TRY" : (code == PrintCode_ERR ? "ERR" : "???")))

#define SDMPrint(code,...) printf("[%s%s%s] ",SDMPrintCodeColor(code),SDMPrintCode(code),(UseColorCodes ? COLOR_NRM : "")); printf(__VA_ARGS__); printf("\n")

#endif
