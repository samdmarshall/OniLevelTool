/*
 *  OniTemplate.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/29/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "headers.h"

#ifndef _OniTemplateStruct
#define _OniTemplateStruct
struct OniTemplateStruct {
	int64_t checksum;
	int32_t name;
	int32_t instances;
};

typedef enum OniTemplateTags {
	tm_ABNA = 0x414e4241, // "ANBA"
	tm_AGQC = 0x43514741, // "CQGA"
	tm_AGQG = 0x47514741, // "GQGA"
	tm_AGQR = 0x52514741, // "RQGA"
	tm_AISA = 0x41534941, // "ASIA"
	tm_AKAA = 0x41414b41, // "AAKA"
	tm_AKBA = 0x41424b41, // "ABKA"
	tm_AKBP = 0x50424b41, // "PBKA"
	tm_AKEV = 0x56454b41, // "VEKA"
	tm_AKOT = 0x544f4b41, // "TOKA"
	tm_AKVA = 0x41564b41, // "AVKA"
	tm_BINA = 0x414e4942, // "ANIB"
	tm_CBPI = 0x49504243, // "IPBC"
	tm_CBPM = 0x4d504243, // "MPBC"
	tm_CONS = 0x534e4f43, // "SNOC"
	tm_CRSA = 0x41535243, // "ASRC"
	tm_DOOR = 0x524f4f44, // "ROOD"
	tm_DPge = 0x65675044, // "egPD"
	tm_ENVP = 0x50564e45, // "PVNE"
	tm_FILM = 0x4d4c4946, // "MLIF"
	tm_HPge = 0x65675048, // "egPH"
	tm_IDXA = 0x41584449, // "AXDI"
	tm_IGHH = 0x48484749, // "HHGI"
	tm_IGPA = 0x41504749, // "APGI"
	tm_IGPG = 0x47504749, // "GPGI"
	tm_IGSA = 0x41534749, // "ASGI"
	tm_IGSt = 0x74534749, // "tSGI"
	tm_Impt = 0x74706d49, // "tpmI"
	tm_IPge = 0x65675049, // "egPI"
	tm_KeyI = 0x4979654b, // "IyeK"
	tm_M3GA = 0x4147334d, // "AG3M"
	tm_M3GM = 0x4d47334d, // "MG3M"
	tm_Mtrl = 0x6c72744d, // "lrtM"
	tm_OBAN = 0x4e41424f, // "NABO"
	tm_OBOA = 0x414f424f, // "AOBO"
	tm_OFGA = 0x4147464f, // "AGFO"
	tm_ONCC = 0x43434e4f, // "CCNO"
	tm_ONCP = 0x50434e4f, // "PCNO"
	tm_ONCV = 0x56434e4f, // "VCNO"
	tm_ONGS = 0x53474e4f, // "SGNO"
	tm_ONIA = 0x41494e4f, // "AINO"
	tm_ONLD = 0x444c4e4f, // "DLNO"
	tm_ONLV = 0x564c4e4f, // "VLNO"
	tm_ONOA = 0x414f4e4f, // "AONO"
	tm_ONSK = 0x4b534e4f, // "KSNO"
	tm_ONVL = 0x4c564e4f, // "LVNO"
	tm_ONWC = 0x43574e4f, // "CWNO"
	tm_OPge = 0x6567504f, // "egPO"
	tm_OSBD = 0x4442534f, // "DBSO"
	tm_OTIT = 0x5449544f, // "TITO"
	tm_OTLF = 0x464c544f, // "FLTO"
	tm_PLEA = 0x41454c50, // "AELP"
	tm_PNTA = 0x41544e50, // "ATNP"
	tm_PSpc = 0x63705350, // "cpSP"
	tm_PSpL = 0x4c705350, // "LpSP"
	tm_PSUI = 0x49555350, // "IUSP"
	tm_QTNA = 0x414e5451, // "ANTQ"
	tm_SNDD = 0x44444e53, // "DDNS"
	tm_SUBT = 0x54425553, // "TBUS"
	tm_TRAC = 0x43415254, // "CART"
	tm_TRAM = 0x4d415254, // "MART"
	tm_TRAS = 0x53415254, // "SART"
	tm_TRBS = 0x53425254, // "SBRT"
	tm_TRCM = 0x4d435254, // "MCRT"
	tm_TRGA = 0x41475254, // "AGRT"
	tm_TRGE = 0x45475254, // "EGRT"
	tm_TRIA = 0x41495254, // "AIRT"
   	tm_TRIG = 0x47495254, // "GIRT"
	tm_TRMA = 0x414d5254, // "AMRT"
	tm_TRSC = 0x43535254, // "CSRT"
	tm_TRTA = 0x41545254, // "ATRT"
	tm_TSFF = 0x46465354, // "FFST"
	tm_TSFL = 0x4c465354, // "LFST"
	tm_TSFT = 0x54465354, // "TFST"
	tm_TSGA = 0x41475354, // "AGST"
	tm_TURR = 0x52525554, // "RRUT"
	tm_TXAN = 0x4e415854, // "NAXT"
	tm_TXCA = 0x41435854, // "ACXT"
	tm_TXMA = 0x414d5854, // "AMXT"
	tm_TXMB = 0x424d5854, // "BMXT"
	tm_TXMP = 0x504d5854, // "PMXT"
	tm_TxtC = 0x43747854, // "CtxT"
	tm_VCRA = 0x41524356, // "ARCV"
	tm_WMCL = 0x4c434d57, // "LCMW"
	tm_WMDD = 0x44444d57, // "DDMW"
	tm_WMM_ = 0x5f4d4d57, // "_MMW"
	tm_WMMB = 0x424d4d57, // "BMMW"
	tm_WPge = 0x65675057, // "egPW"
	
	// Oni Engine does not use these tags
	tm_AGDB = 0x42444741, // "BDGA"
	tm_AITR = 0x52544941, // "RTIA"
	tm_AKDA = 0x41444B41, // "ADKA"
	tm_OBDC = 0x4344424F, // "CDBO"
	tm_ONFA = 0x41464E4F, // "AFNO"
	tm_ONMA = 0x414D4E4F, // "AMNO"
	tm_ONSA = 0x41534E4F, // "ASNO"
	tm_ONTA = 0x41544E4F, // "ATNO"
	tm_StNA = 0x414E7453, // "ANtS"
	tm_TStr = 0x72745354  // "rtST"
};

const static OniTemplateTags tm_types[98] = {tm_ABNA, tm_AGQC, tm_AGQG, tm_AGQR, tm_AISA, tm_AKAA, tm_AKBA, tm_AKBP, tm_AKEV, tm_AKOT, tm_AKVA, tm_BINA, tm_CBPI, tm_CBPM, tm_CONS, tm_CRSA, tm_DOOR, tm_DPge, tm_ENVP, tm_FILM, tm_HPge, tm_IDXA, tm_IGHH, tm_IGPA, tm_IGPG, tm_IGSA, tm_IGSt, tm_Impt, tm_IPge, tm_KeyI, tm_M3GA, tm_M3GM, tm_Mtrl, tm_OBAN, tm_OBOA, tm_OFGA, tm_ONCC, tm_ONCP, tm_ONCV, tm_ONGS, tm_ONIA, tm_ONLD, tm_ONLV, tm_ONOA, tm_ONSK, tm_ONVL, tm_ONWC, tm_OPge, tm_OSBD, tm_OTIT, tm_OTLF, tm_PLEA, tm_PNTA, tm_PSpc, tm_PSpL, tm_PSUI, tm_QTNA, tm_SNDD, tm_SUBT, tm_TRAC, tm_TRAM, tm_TRAS, tm_TRBS, tm_TRCM, tm_TRGA, tm_TRGE, tm_TRIA, tm_TRIG, tm_TRMA, tm_TRSC, tm_TRTA, tm_TSFF, tm_TSFL, tm_TSFT, tm_TSGA, tm_TURR, tm_TXAN, tm_TXCA, tm_TXMA, tm_TXMB, tm_TXMP, tm_TxtC, tm_VCRA, tm_WMCL, tm_WMDD, tm_WMM_, tm_WMMB, tm_WPge, tm_AGDB, tm_AITR, tm_AKDA, tm_OBDC, tm_ONFA, tm_ONMA, tm_ONSA, tm_ONTA, tm_StNA, tm_TStr};

static inline bool isTagOfType(char tag[5], OniTemplateTags tm) {
	char read_tm[5] = { ((tm>>24)&0xFF), ((tm>>16)&0xFF), ((tm>>8)&0xFF), ((tm>>0)&0xFF), '\0'};
	return (strcmp(tag, read_tm)==0);
};

#endif       