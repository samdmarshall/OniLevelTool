/*
 *  OniTag.cpp
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 4/30/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTag.h"
#include <typeinfo>

OniTag::OniTag() {
}

OniTag::~OniTag() {
}

void OniTag::LoadFrom(OniInstanceStruct *data_struct, char *data_buffer, char *name_buffer) {
	memcpy(this->type, &data_struct->template_tag, 4);
	
	this->flags = data_struct->flags;
	
	if (!hasInstanceFlag(this->flags, OIF_Unique))
		memcpy(this->name, &name_buffer[data_struct->name_offset],64);
	else
		strncpy(this->name, "unnamed\0", 64);
		
	char *instance_data = (char *)malloc(sizeof(char)*(data_struct->data_size+8));
	memcpy(instance_data, &data_buffer[data_struct->data_offset-8],data_struct->data_size+8);
	this->FormatTag(instance_data);
	free(instance_data);
}

void OniTag::FormatTag(char *i_data) {
	int32_t i;
	for (i = 0; i < 98; i++) {
		if (isTagOfType(this->type, tm_types[i]))
			break;
	}
	this->external_data = false;
	switch (i) {
		case  0: { this->tm_tag = dynamic_cast<ABNA*>(new ABNA); break; }
		case  1: { this->tm_tag = dynamic_cast<AGQC*>(new AGQC); break; }
		case  2: { this->tm_tag = dynamic_cast<AGQG*>(new AGQG); break; }
		case  3: { this->tm_tag = dynamic_cast<AGQR*>(new AGQR); break; }
		case  4: { this->tm_tag = dynamic_cast<AISA*>(new AISA); break; }
		case  5: { this->tm_tag = dynamic_cast<AKAA*>(new AKAA); break; }
		case  6: { this->tm_tag = dynamic_cast<AKBA*>(new AKBA); break; }
		case  7: { this->tm_tag = dynamic_cast<AKBP*>(new AKBP); break; }
		case  8: { this->tm_tag = dynamic_cast<AKEV*>(new AKEV); break; }
		case  9: { this->tm_tag = dynamic_cast<AKOT*>(new AKOT); break; }
		case 10: { this->tm_tag = dynamic_cast<AKVA*>(new AKVA); break; }
		case 11: { this->tm_tag = dynamic_cast<BINA*>(new BINA); this->external_data = true; break; }
		case 12: { this->tm_tag = dynamic_cast<CBPI*>(new CBPI); break; }
		case 13: { this->tm_tag = dynamic_cast<CBPM*>(new CBPM); break; }
		case 14: { this->tm_tag = dynamic_cast<CONS*>(new CONS); break; }
		case 15: { this->tm_tag = dynamic_cast<CRSA*>(new CRSA); break; }
		case 16: { this->tm_tag = dynamic_cast<DOOR*>(new DOOR); break; }
		case 17: { this->tm_tag = dynamic_cast<DPge*>(new DPge); break; }
		case 18: { this->tm_tag = dynamic_cast<ENVP*>(new ENVP); break; }
		case 19: { this->tm_tag = dynamic_cast<FILM*>(new FILM); break; }
		case 20: { this->tm_tag = dynamic_cast<HPge*>(new HPge); break; }
		case 21: { this->tm_tag = dynamic_cast<IDXA*>(new IDXA); break; }
		case 22: { this->tm_tag = dynamic_cast<IGHH*>(new IGHH); break; }
		case 23: { this->tm_tag = dynamic_cast<IGPA*>(new IGPA); break; }
		case 24: { this->tm_tag = dynamic_cast<IGPG*>(new IGPG); break; }
		case 25: { this->tm_tag = dynamic_cast<IGSA*>(new IGSA); break; }
		case 26: { this->tm_tag = dynamic_cast<IGSt*>(new IGSt); break; }
		case 27: { this->tm_tag = dynamic_cast<Impt*>(new Impt); break; }
		case 28: { this->tm_tag = dynamic_cast<IPge*>(new IPge); break; }
		case 29: { this->tm_tag = dynamic_cast<KeyI*>(new KeyI); break; }
		case 30: { this->tm_tag = dynamic_cast<M3GA*>(new M3GA); break; }
		case 31: { this->tm_tag = dynamic_cast<M3GM*>(new M3GM); break; }
		case 32: { this->tm_tag = dynamic_cast<Mtrl*>(new Mtrl); break; }
		case 33: { this->tm_tag = dynamic_cast<OBAN*>(new OBAN); break; }
		case 34: { this->tm_tag = dynamic_cast<OBOA*>(new OBOA); break; }
		case 35: { this->tm_tag = dynamic_cast<OFGA*>(new OFGA); break; }
		case 36: { this->tm_tag = dynamic_cast<ONCC*>(new ONCC); break; }
	  	case 37: { this->tm_tag = dynamic_cast<ONCP*>(new ONCP); break; }
		/*case 38: { this->tm_tag = dynamic_cast<ONCV*>(new ONCV); break; }
		case 39: { this->tm_tag = dynamic_cast<ONGS*>(new ONGS); break; }
		case 40: { this->tm_tag = dynamic_cast<ONIA*>(new ONIA); break; }
		case 41: { this->tm_tag = dynamic_cast<ONLD*>(new ONLD); break; }
		case 42: { this->tm_tag = dynamic_cast<ONLV*>(new ONLV); break; }
		case 43: { this->tm_tag = dynamic_cast<ONOA*>(new ONOA); break; }
		case 44: { this->tm_tag = dynamic_cast<ONSK*>(new ONSK); break; }
		case 45: { this->tm_tag = dynamic_cast<ONVL*>(new ONVL); break; }
		case 46: { this->tm_tag = dynamic_cast<ONWC*>(new ONWC); break; }
		case 47: { this->tm_tag = dynamic_cast<OPge*>(new OPge); break; }
		case 48: { this->tm_tag = dynamic_cast<OSBD*>(new OSBD); break; }
		case 49: { this->tm_tag = dynamic_cast<OTIT*>(new OTIT); break; }
		case 50: { this->tm_tag = dynamic_cast<OTLF*>(new OTLF); break; }
		case 51: { this->tm_tag = dynamic_cast<PLEA*>(new PLEA); break; }
		case 52: { this->tm_tag = dynamic_cast<PNTA*>(new PNTA); break; }
		case 53: { this->tm_tag = dynamic_cast<PSpc*>(new PSpc); break; }
		case 54: { this->tm_tag = dynamic_cast<PSpL*>(new PSpL); break; }
		case 55: { this->tm_tag = dynamic_cast<PSUI*>(new PSUI); break; }
		case 56: { this->tm_tag = dynamic_cast<QTNA*>(new QTNA); break; }
		case 57: { this->tm_tag = dynamic_cast<SNDD*>(new SNDD); break; }
		case 58: { this->tm_tag = dynamic_cast<SUBT*>(new SUBT); break; }
		case 59: { this->tm_tag = dynamic_cast<TRAC*>(new TRAC); break; }
		case 60: { this->tm_tag = dynamic_cast<TRAM*>(new TRAM); break; }
		case 61: { this->tm_tag = dynamic_cast<TRAS*>(new TRAS); break; }
		case 62: { this->tm_tag = dynamic_cast<TRBS*>(new TRBS); break; }
		case 63: { this->tm_tag = dynamic_cast<TRCM*>(new TRCM); break; }
		case 64: { this->tm_tag = dynamic_cast<TRGA*>(new TRGA); break; }
		case 65: { this->tm_tag = dynamic_cast<TRGE*>(new TRGE); break; }
		case 66: { this->tm_tag = dynamic_cast<TRIA*>(new TRIA); break; }
		case 67: { this->tm_tag = dynamic_cast<TRIG*>(new TRIG); break; }
		case 68: { this->tm_tag = dynamic_cast<TRMA*>(new TRMA); break; }
		case 69: { this->tm_tag = dynamic_cast<TRSC*>(new TRSC); break; }
		case 70: { this->tm_tag = dynamic_cast<TRTA*>(new TRTA); break; }
		case 71: { this->tm_tag = dynamic_cast<TSFF*>(new TSFF); break; }
		case 72: { this->tm_tag = dynamic_cast<TSFL*>(new TSFL); break; }
		case 73: { this->tm_tag = dynamic_cast<TSFT*>(new TSFT); break; }
		case 74: { this->tm_tag = dynamic_cast<TSGA*>(new TSGA); break; }
		case 75: { this->tm_tag = dynamic_cast<TURR*>(new TURR); break; }
		case 76: { this->tm_tag = dynamic_cast<TXAN*>(new TXAN); break; }
		case 77: { this->tm_tag = dynamic_cast<TXCA*>(new TXCA); break; }
		case 78: { this->tm_tag = dynamic_cast<TXMA*>(new TXMA); break; }
		case 79: { this->tm_tag = dynamic_cast<TXMB*>(new TXMB); break; }
		case 80: { this->tm_tag = dynamic_cast<TXMP*>(new TXMP); break; }
		case 81: { this->tm_tag = dynamic_cast<TxtC*>(new TxtC); break; }
		case 82: { this->tm_tag = dynamic_cast<VCRA*>(new VCRA); break; }
		case 83: { this->tm_tag = dynamic_cast<WMCL*>(new WMCL); break; }
		case 84: { this->tm_tag = dynamic_cast<WMDD*>(new WMDD); break; }
		case 85: { this->tm_tag = dynamic_cast<WMM_*>(new WMM_); break; }
		case 86: { this->tm_tag = dynamic_cast<WMMB*>(new WMMB); break; }
		case 87: { this->tm_tag = dynamic_cast<WPge*>(new WPge); break; }
		case 88: { this->tm_tag = dynamic_cast<AGDB*>(new AGDB); break; }
		case 89: { this->tm_tag = dynamic_cast<AITR*>(new AITR); break; }
		case 90: { this->tm_tag = dynamic_cast<AKDA*>(new AKDA); break; }
		case 91: { this->tm_tag = dynamic_cast<OBDC*>(new OBDC); break; }
		case 92: { this->tm_tag = dynamic_cast<ONFA*>(new ONFA); break; }
		case 93: { this->tm_tag = dynamic_cast<ONMA*>(new ONMA); break; }
		case 94: { this->tm_tag = dynamic_cast<ONSA*>(new ONSA); break; }
		case 95: { this->tm_tag = dynamic_cast<ONTA*>(new ONTA); break; }
		case 96: { this->tm_tag = dynamic_cast<StNA*>(new StNA); break; }
		case 97: { this->tm_tag = dynamic_cast<TStr*>(new TStr); break; }*/
		default: { this->tm_tag = new OniTM; break; }
	}
	
	this->tm_tag->Load(i_data);
	this->tm_tag->remap = (ResIDMapper){GetResID(this->tm_tag->header->res_id), 0};
}

int32_t OniTag::GetDataLength() {
	return this->tm_tag->DataSize();
}

char* OniTag::GetExportData() {
	return this->tm_tag->ExportData();;
}
