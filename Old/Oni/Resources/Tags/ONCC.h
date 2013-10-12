/*
 *  ONCC.h
 *  OniLevelTool
 *
 *  Created by Sam Marshall on 5/2/12.
 *  Copyright 2012 Sam Marshall. All rights reserved.
 *
 */

#include "OniTM.h"

#ifndef _ONCC
#define _ONCC

struct ONCCShootingSkillsStruct {
	float recoil_compensation;
	float aiming_angle;
	float grouping_error;
	float grouping_decay;
	float inaccuracy_multiplier;
	uint16_t min_delay;
	uint16_t max_delay;
};

struct ONCCImpactElementsStruct {
	char impact_name[128];
	int16_t runtime;
};

struct ONCCDataStruct {
	float downward_velocity;
	float gravity_acceleration;
	float starting_velocity;
	float velocity_limit;
	float upward_acceleration;
	int16_t gravity_timer;
	int16_t jetpack_timer;
	float no_damage_fall;
	float damage_fall;
	
	// Shadow
	int32_t TXMP_link_shadow;
	float height_no_shadow;
	float diameter_decrease_shadow1;
	float diameter_decrease_shadow2;
	float diameter_decrease_shadow3;
	float diameter_decrease_shadow4;
	int16_t transparency_shadow1;
	int16_t transparency_shadow2;
	
	// Jump
	float distance_jump;
	int8_t height_jump;
	int8_t square_distance_jump;
	char unused_jump[2];
	
	// Cover
	float increment_ray;
	float max_ray;
	float angle_ray;
	float max_angle_ray;
	
	// Autofreeze
	float distance_xz;
	float distance_y;
	
	// Inventory
	int16_t hypo_regeneration;
	char unused_inventory[2];
	
	// LOD
	float LOD1;
	float LOD2;
	float LOD3;
	float LOD4;
	float LOD5;
	
	// Hurt Sound
	int16_t hurt_base_percentage;
	int16_t hurt_max_percentage;
	int16_t hurt_percentage_threshold;
	int16_t hurt_timer;
	int16_t hurt_min_timer;
	int16_t hurt_max_timer;
	int16_t hurt_max_light;
	int16_t hurt_max_medium;
	int16_t hurt_death_chance;
	int16_t hurt_volume_threshold;
	int16_t hurt_medium_threshold;
	int16_t hurt_heavy_threshold;
	int8_t hurt_runtime1;
	char unused_hurt[1];
	float sound_volume;
	char hurt_light_sound_name[32];
	char hurt_medium_sound_name[32];
	char hurt_heavy_sound_name[32];
	char death_sound_name[32];
	int32_t hurt_runtime2;
	int32_t hurt_runtime3;
	int32_t hurt_runtime4;
	int32_t hurt_runtime5;
	
	// AI
	int32_t AI_bitset;
	float AI_rotation_factor;
	int16_t AI_min_fallen_time;
	int16_t AI_max_fallen_time;
	uint32_t AI_frames;
	float min_firing_spread;
	float max_firing_spread;
	
	// AI Targeting
	float AI_target_prediction1;
	float AI_target_prediction2;
	float AI_target_prediction3;
	int32_t AI_target_frame_count1;
	int32_t AI_target_frame_count2;
	int32_t AI_target_frame_count3;
	int32_t AI_target_frame_count4;
	ONCCShootingSkillsStruct skills[13];
	
	int32_t unknown1;
	int32_t unknown2;
	int32_t unknown3;
	int32_t taunt_chance;
	int32_t go_for_gun_chance;
	int32_t running_pickup_chance;
	int16_t combat_profile_id;
	int16_t melee_profile_id;
	int8_t taunt_sound_probability;
	int8_t alert_sound_probability;
	int8_t startle_sound_probability;
	int8_t checkbody_sound_probability;
	int8_t pursue_sound_probability;
	int8_t cower_sound_probability;
	int8_t superpunch_sound_probability;
	int8_t superkick_sound_probability;
	int8_t super3_sound_probability;
	int8_t super4_sound_probability;
	int16_t padding1;
	char taunt_sound_name[32];
	char alert_sound_name[32];
	char startle_sound_name[32];
	char checkbody_sound_name[32];
	char pursue_sound_name[32];
	char cower_sound_name[32];
	char superpunch_sound_name[32];
	char superkick_sound_name[32];
	char super3_sound_name[32];
	char super4_sound_name[32];
	
	float central_distance;
	float peripheral_distance;
	float vertical_range;
	float central_range;
	float central_max;
	float peripheral_range;
	float peripheral_max;
	int32_t hostile_definite_timer;
	int32_t hostile_strong_timer;
	int32_t hostile_weak_timer;
	int32_t friendly_definite_timer;
	int32_t friendly_strong_timer;
	int32_t friendly_weak_timer;
	float earshot_radius;
	
	int32_t ONCV_link;
	int32_t ONCP_link;
	int32_t ONIA_link;
	int8_t runtime1;
	int8_t padding2;
	int8_t runtime2;
	char modifier[16];
	ONCCImpactElementsStruct impact[15];
	
	int16_t padding3;
	char special_death[64];
	int32_t runtime3;
	int32_t runtime4;
	int32_t TRBS_link;
	int32_t TRMA_link;
	int32_t CBPM_link;
	int32_t CBPI_link;
	int32_t fight_mode_timer;
	int32_t idle_animation_timer1;
	int32_t idle_animation_timer2;
	int32_t basic_health;
	int32_t feet_bits;
	float min_body_factor;
	float max_body_factor;
	
	float unknown4;
	float unknown5;
	float stun_timer;
	float unknown6;
	float unknown7;
	float unknown8;
	float unknown9;
	float shield_protect;
	int32_t TRAC_link;
	int32_t TRSC_link;
	int16_t AI_rof;
	int16_t death_to_deletion_frames;
	int32_t TRSC_flags;
	char dead[8];
};

class ONCC : public OniTM {
public:
	ONCCDataStruct *data;
};
#endif