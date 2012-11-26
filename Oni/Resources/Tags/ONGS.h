/*
 *  ONGS.h
 *  OniLevelTool
 *
 *  Created by sam on 11/26/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONGS
#define _ONGS

struct ONGSMeshName {
	char name[128];
};

struct ONGSGlowName {
	char name[128];
};

struct ONGSSoundName {
	char name[32];
};

struct ONGSDataStruct {
	char notes[32];
	int16_t first_level;
	int16_t last_level;
	char anchor_text[32];
};

struct ONGSHeaderStruct {
	float max_overhealth_factor;
	float normal_hypo_strength;
	float overhealth_hypo_strength;
	float overhealth_min_damage_factor;
	float overhealth_max_damage_factor;
	int32_t used_key_health_values;
	float zero_percent_health;
	float sixtysix_percent_health;
	float nintyeight_percent_health;
	float hundred_percent_health;
	char unused1[48];
	char zero_percent_health_color[4];
	char sixtysix_percent_health_color[4];
	char nintyeight_percent_health_color[4];
	char hundred_percent_health_color[4];
	char unused2[48];
	ONGSMeshName mesh_names[7];
	
	ONGSGlowName glow_names[7];
	
	float red_ammo_glow_x;
	float red_ammo_glow_y;
	float green_ammo_glow_x;
	float green_ammo_glow_y;
	float hypo_glow_x;
	float hypo_glow_y;
	float shield_glow_x;
	float shield_glow_y;
	float cloak_glow_x;
	float cloak_glow_y;
	float lsi_glow_x;
	float lsi_glow_y;
	char unused3[8];
	ONGSSoundName sound_names[23];
	
	float noise_factor_easy;
	float noise_factor_normal;
	float noise_factor_hard;
	float block_factor_easy;
	float block_factor_normal;
	float block_factor_hard;
	float dodge_factor_easy;
	float dodge_factor_normal;
	float dodge_factor_hard;
	float accuaracy_factor_easy;
	float accuaracy_factor_normal;
	float accuaracy_factor_hard;
	float enemy_health_factor_easy;
	float enemy_health_factor_normal;
	float enemy_health_factor_hard;
	float player_health_factor_easy;
	float player_health_factor_normal;
	float player_health_factor_hard;
	int32_t array_size;
};

class ONGS : public OniTM {
public:
	ONGSHeaderStruct *head;
	ONGSDataStruct *data;	
};

#endif