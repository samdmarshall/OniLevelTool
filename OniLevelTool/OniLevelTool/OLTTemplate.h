//
//  OLTTemplate.h
//  OniLevelTool
//
//  Created by Sam Marshall on 10/12/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef OniLevelTool_OLTTemplate_h
#define OniLevelTool_OLTTemplate_h

#include "OLTTypes.h"
#include "OLTInstance.h"
#include "OLTLevel.h"
#include "OLTPlugin.h"

typedef enum OLTTemplates {
	OLTTemplate_ABNA = 0x414e4241, // "ANBA"
	OLTTemplate_AGQC = 0x43514741, // "CQGA"
	OLTTemplate_AGQG = 0x47514741, // "GQGA"
	OLTTemplate_AGQR = 0x52514741, // "RQGA"
	OLTTemplate_AISA = 0x41534941, // "ASIA"
	OLTTemplate_AKAA = 0x41414b41, // "AAKA"
	OLTTemplate_AKBA = 0x41424b41, // "ABKA"
	OLTTemplate_AKBP = 0x50424b41, // "PBKA"
	OLTTemplate_AKEV = 0x56454b41, // "VEKA"
	OLTTemplate_AKOT = 0x544f4b41, // "TOKA"
	OLTTemplate_AKVA = 0x41564b41, // "AVKA"
	OLTTemplate_BINA = 0x414e4942, // "ANIB"
	OLTTemplate_CBPI = 0x49504243, // "IPBC"
	OLTTemplate_CBPM = 0x4d504243, // "MPBC"
	OLTTemplate_CONS = 0x534e4f43, // "SNOC"
	OLTTemplate_CRSA = 0x41535243, // "ASRC"
	OLTTemplate_DOOR = 0x524f4f44, // "ROOD"
	OLTTemplate_DPge = 0x65675044, // "egPD"
	OLTTemplate_ENVP = 0x50564e45, // "PVNE"
	OLTTemplate_FILM = 0x4d4c4946, // "MLIF"
	OLTTemplate_HPge = 0x65675048, // "egPH"
	OLTTemplate_IDXA = 0x41584449, // "AXDI"
	OLTTemplate_IGHH = 0x48484749, // "HHGI"
	OLTTemplate_IGPA = 0x41504749, // "APGI"
	OLTTemplate_IGPG = 0x47504749, // "GPGI"
	OLTTemplate_IGSA = 0x41534749, // "ASGI"
	OLTTemplate_IGSt = 0x74534749, // "tSGI"
	OLTTemplate_Impt = 0x74706d49, // "tpmI"
	OLTTemplate_IPge = 0x65675049, // "egPI"
	OLTTemplate_KeyI = 0x4979654b, // "IyeK"
	OLTTemplate_M3GA = 0x4147334d, // "AG3M"
	OLTTemplate_M3GM = 0x4d47334d, // "MG3M"
	OLTTemplate_Mtrl = 0x6c72744d, // "lrtM"
	OLTTemplate_OBAN = 0x4e41424f, // "NABO"
	OLTTemplate_OBOA = 0x414f424f, // "AOBO"
	OLTTemplate_OFGA = 0x4147464f, // "AGFO"
	OLTTemplate_ONCC = 0x43434e4f, // "CCNO"
	OLTTemplate_ONCP = 0x50434e4f, // "PCNO"
	OLTTemplate_ONCV = 0x56434e4f, // "VCNO"
	OLTTemplate_ONGS = 0x53474e4f, // "SGNO"
	OLTTemplate_ONIA = 0x41494e4f, // "AINO"
	OLTTemplate_ONLD = 0x444c4e4f, // "DLNO"
	OLTTemplate_ONLV = 0x564c4e4f, // "VLNO"
	OLTTemplate_ONOA = 0x414f4e4f, // "AONO"
	OLTTemplate_ONSK = 0x4b534e4f, // "KSNO"
	OLTTemplate_ONVL = 0x4c564e4f, // "LVNO"
	OLTTemplate_ONWC = 0x43574e4f, // "CWNO"
	OLTTemplate_OPge = 0x6567504f, // "egPO"
	OLTTemplate_OSBD = 0x4442534f, // "DBSO"
	OLTTemplate_OTIT = 0x5449544f, // "TITO"
	OLTTemplate_OTLF = 0x464c544f, // "FLTO"
	OLTTemplate_PLEA = 0x41454c50, // "AELP"
	OLTTemplate_PNTA = 0x41544e50, // "ATNP"
	OLTTemplate_PSpc = 0x63705350, // "cpSP"
	OLTTemplate_PSpL = 0x4c705350, // "LpSP"
	OLTTemplate_PSUI = 0x49555350, // "IUSP"
	OLTTemplate_QTNA = 0x414e5451, // "ANTQ"
	OLTTemplate_SNDD = 0x44444e53, // "DDNS"
	OLTTemplate_SUBT = 0x54425553, // "TBUS"
	OLTTemplate_TRAC = 0x43415254, // "CART"
	OLTTemplate_TRAM = 0x4d415254, // "MART"
	OLTTemplate_TRAS = 0x53415254, // "SART"
	OLTTemplate_TRBS = 0x53425254, // "SBRT"
	OLTTemplate_TRCM = 0x4d435254, // "MCRT"
	OLTTemplate_TRGA = 0x41475254, // "AGRT"
	OLTTemplate_TRGE = 0x45475254, // "EGRT"
	OLTTemplate_TRIA = 0x41495254, // "AIRT"
   	OLTTemplate_TRIG = 0x47495254, // "GIRT"
	OLTTemplate_TRMA = 0x414d5254, // "AMRT"
	OLTTemplate_TRSC = 0x43535254, // "CSRT"
	OLTTemplate_TRTA = 0x41545254, // "ATRT"
	OLTTemplate_TSFF = 0x46465354, // "FFST"
	OLTTemplate_TSFL = 0x4c465354, // "LFST"
	OLTTemplate_TSFT = 0x54465354, // "TFST"
	OLTTemplate_TSGA = 0x41475354, // "AGST"
	OLTTemplate_TURR = 0x52525554, // "RRUT"
	OLTTemplate_TXAN = 0x4e415854, // "NAXT"
	OLTTemplate_TXCA = 0x41435854, // "ACXT"
	OLTTemplate_TXMA = 0x414d5854, // "AMXT"
	OLTTemplate_TXMB = 0x424d5854, // "BMXT"
	OLTTemplate_TXMP = 0x504d5854, // "PMXT"
	OLTTemplate_TxtC = 0x43747854, // "CtxT"
	OLTTemplate_VCRA = 0x41524356, // "ARCV"
	OLTTemplate_WMCL = 0x4c434d57, // "LCMW"
	OLTTemplate_WMDD = 0x44444d57, // "DDMW"
	OLTTemplate_WMM_ = 0x5f4d4d57, // "_MMW"
	OLTTemplate_WMMB = 0x424d4d57, // "BMMW"
	OLTTemplate_WPge = 0x65675057, // "egPW"
	
	// Oni Engine does not use these tags, but they still exist and are referenced so we need them!
	OLTTemplate_AGDB = 0x42444741, // "BDGA"
	OLTTemplate_AITR = 0x52544941, // "RTIA"
	OLTTemplate_AKDA = 0x41444B41, // "ADKA"
	OLTTemplate_OBDC = 0x4344424F, // "CDBO"
	OLTTemplate_ONFA = 0x41464E4F, // "AFNO"
	OLTTemplate_ONMA = 0x414D4E4F, // "AMNO"
	OLTTemplate_ONSA = 0x41534E4F, // "ASNO"
	OLTTemplate_ONTA = 0x41544E4F, // "ATNO"
	OLTTemplate_StNA = 0x414E7453, // "ANtS"
	OLTTemplate_TStr = 0x72745354  // "rtST"
} OLTTemplates;

#define OLTTemplateCount 98

struct OLTTemplateDefinition {
	int64_t checkSum;
	OLTTemplates template;
} ATR_PACK;

const static struct OLTTemplateDefinition OLTTemplate_types[OLTTemplateCount] = {
	{1207712, OLTTemplate_ABNA},
	{1887121, OLTTemplate_AGQC},
	{1835986, OLTTemplate_AGQG},
	{539195, OLTTemplate_AGQR},
	{180964060137, OLTTemplate_AISA},
	{1171063, OLTTemplate_AKAA},
	{3811460, OLTTemplate_AKBA},
	{848969, OLTTemplate_AKBP},
	{584922226293, OLTTemplate_AKEV},
	{76902095368, OLTTemplate_AKOT},
	{14616032, OLTTemplate_AKVA},
	{89617, OLTTemplate_BINA},
	{51740530370, OLTTemplate_CBPI},
	{10395858207, OLTTemplate_CBPM},
	{85270924253, OLTTemplate_CONS},
	{51896374476, OLTTemplate_CRSA},
	{26599423335, OLTTemplate_DOOR},
	{33194403947, OLTTemplate_DPge},
	{6799811, OLTTemplate_ENVP},
	{48102073005, OLTTemplate_FILM},
	{18441269563, OLTTemplate_HPge},
	{159887, OLTTemplate_IDXA},
	{38211049694, OLTTemplate_IGHH},
	{20900088069, OLTTemplate_IGPA},
	{76477335677, OLTTemplate_IGPG},
	{20900127752, OLTTemplate_IGSA},
	{11318621989, OLTTemplate_IGSt},
	{282390, OLTTemplate_Impt},
	{11064797626, OLTTemplate_IPge},
	{275939547053, OLTTemplate_KeyI},
	{22018728114, OLTTemplate_M3GA},
	{170196001846, OLTTemplate_M3GM},
	{167437, OLTTemplate_Mtrl},
	{5114916, OLTTemplate_OBAN},
	{82938791649, OLTTemplate_OBOA},
	{83566969698, OLTTemplate_OFGA},
	{5109581306351, OLTTemplate_ONCC},
	{3109665, OLTTemplate_ONCP},
	{170485, OLTTemplate_ONCV},
	{36105142, OLTTemplate_ONGS},
	{2830234, OLTTemplate_ONIA},
	{266913, OLTTemplate_ONLD},
	{539951247011, OLTTemplate_ONLV},
	{27043257468, OLTTemplate_ONOA},
	{89156620391, OLTTemplate_ONSK},
	{22619145610, OLTTemplate_ONVL},
	{1733621247669, OLTTemplate_ONWC},
	{18441354235, OLTTemplate_OPge},
	{89660, OLTTemplate_OSBD},
	{676306, OLTTemplate_OTIT},
	{2010123, OLTTemplate_OTLF},
	{506936, OLTTemplate_PLEA},
	{3630956, OLTTemplate_PNTA},
	{534088, OLTTemplate_PSpc},
	{838661, OLTTemplate_PSpL},
	{4180417615611, OLTTemplate_PSUI},
	{421580, OLTTemplate_QTNA},
	{266731, OLTTemplate_SNDD},
	{289896, OLTTemplate_SUBT},
	{65077377839, OLTTemplate_TRAC},
	{70837389592, OLTTemplate_TRAM},
	{8491477296, OLTTemplate_TRAS},
	{11317428793, OLTTemplate_TRBS},
	{152787879246, OLTTemplate_TRCM},
	{22018728184, OLTTemplate_TRGA},
	{36266490172, OLTTemplate_TRGE},
	{705666, OLTTemplate_TRIA},
	{145438592300, OLTTemplate_TRIG},
	{24056327511, OLTTemplate_TRMA},
	{24049642263, OLTTemplate_TRSC},
	{481768, OLTTemplate_TRTA},
	{45272025226, OLTTemplate_TSFF},
	{581161, OLTTemplate_TSFL},
	{97619402474, OLTTemplate_TSFT},
	{2772632, OLTTemplate_TSGA},
	{316893824446, OLTTemplate_TURR},
	{45282968455, OLTTemplate_TXAN},
	{594970, OLTTemplate_TXCA},
	{24056332176, OLTTemplate_TXMA},
	{45283174994, OLTTemplate_TXMB},
	{36794461023, OLTTemplate_TXMP},
	{7376505639, OLTTemplate_TxtC},
	{345913, OLTTemplate_VCRA},
	{643190, OLTTemplate_WMCL},
	{120261047236, OLTTemplate_WMDD},
	{793144, OLTTemplate_WMM_},
	{29293831991, OLTTemplate_WMMB},
	{19047942581, OLTTemplate_WPge},
	{470551, OLTTemplate_AGDB},
	{1763925, OLTTemplate_AITR},
	{3036260, OLTTemplate_AKDA},
	{33246071307, OLTTemplate_OBDC},
	{1772775, OLTTemplate_ONFA},
	{1197945, OLTTemplate_ONMA},
	{280116, OLTTemplate_ONSA},
	{10550464, OLTTemplate_ONTA},
	{24050971936, OLTTemplate_StNA},
	{25760, OLTTemplate_TStr}
};

#define ConvertTagName(c1, c2, c3, c4) (uint32_t)(((uint32_t)(c1) << 24) | ((uint32_t)(c2) << 16) | ((uint32_t)(c3) << 8) | (uint32_t)(c4))

#define IsTypeOfTag(tag, template) (ConvertTagName(tag[0],tag[1],tag[2],tag[3]) == template)

bool ValidTagType(struct OLTInstance *instance, struct OLTLevel *level);

#endif
