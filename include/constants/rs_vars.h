#ifndef GUARD_CONSTANTS_RS_VARS_H
#define GUARD_CONSTANTS_RS_VARS_H

#define RS_VARS_START 0x4000

// temporary vars
// The first 0x10 vars are are temporary--they are cleared every time a map is loaded.
#define RS_VAR_TEMP_0                 0x4000
#define RS_VAR_TEMP_1                 0x4001
#define RS_VAR_TEMP_2                 0x4002
#define RS_VAR_TEMP_3                 0x4003
#define RS_VAR_TEMP_4                 0x4004
#define RS_VAR_TEMP_5                 0x4005
#define RS_VAR_TEMP_6                 0x4006
#define RS_VAR_TEMP_7                 0x4007
#define RS_VAR_TEMP_8                 0x4008
#define RS_VAR_TEMP_9                 0x4009
#define RS_VAR_TEMP_A                 0x400A
#define RS_VAR_TEMP_B                 0x400B
#define RS_VAR_TEMP_C                 0x400C
#define RS_VAR_TEMP_D                 0x400D
#define RS_VAR_TEMP_E                 0x400E
#define RS_VAR_TEMP_F                 0x400F

// object gfx id vars
// These 0x10 vars are used to dynamically control an object event's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define RS_VAR_OBJ_GFX_ID_0           0x4010
#define RS_VAR_OBJ_GFX_ID_1           0x4011
#define RS_VAR_OBJ_GFX_ID_2           0x4012
#define RS_VAR_OBJ_GFX_ID_3           0x4013
#define RS_VAR_OBJ_GFX_ID_4           0x4014
#define RS_VAR_OBJ_GFX_ID_5           0x4015
#define RS_VAR_OBJ_GFX_ID_6           0x4016
#define RS_VAR_OBJ_GFX_ID_7           0x4017
#define RS_VAR_OBJ_GFX_ID_8           0x4018
#define RS_VAR_OBJ_GFX_ID_9           0x4019
#define RS_VAR_OBJ_GFX_ID_A           0x401A
#define RS_VAR_OBJ_GFX_ID_B           0x401B
#define RS_VAR_OBJ_GFX_ID_C           0x401C
#define RS_VAR_OBJ_GFX_ID_D           0x401D
#define RS_VAR_OBJ_GFX_ID_E           0x401E
#define RS_VAR_OBJ_GFX_ID_F           0x401F

// general purpose vars
#define RS_VAR_RECYCLE_GOODS          0x4020
#define RS_VAR_REPEL_STEP_COUNT       0x4021
#define RS_VAR_ICE_STEP_COUNT         0x4022
#define RS_VAR_STARTER_MON            0x4023 // 0=Treecko, 1=Torchic, 2=Mudkip
#define RS_VAR_MIRAGE_RND_H           0x4024
#define RS_VAR_MIRAGE_RND_L           0x4025
#define RS_VAR_SECRET_BASE_MAP        0x4026
#define RS_VAR_CYCLING_ROAD_RECORD_COLLISIONS 0x4027
#define RS_VAR_CYCLING_ROAD_RECORD_TIME_L     0x4028
#define RS_VAR_CYCLING_ROAD_RECORD_TIME_H     0x4029
#define RS_VAR_HAPPINESS_STEP_COUNTER 0x402A
#define RS_VAR_POISON_STEP_COUNTER    0x402B
#define RS_VAR_RESET_RTC_ENABLE       0x402C
#define RS_VAR_ENIGMA_BERRY_AVAILABLE 0x402D

#define RS_VAR_DAYS                   0x4040
#define RS_VAR_FANCLUB_UNKNOWN_1      0x4041 // TODO: document these two fanclub vars
#define RS_VAR_FANCLUB_UNKNOWN_2      0x4042
#define RS_VAR_DEPT_STORE_FLOOR       0x4043
#define RS_VAR_TRICK_HOUSE_ROOMS_COMPLETED 0x4044
#define RS_VAR_LOTTERY_PRIZE          0x4045
#define RS_VAR_NATIONAL_DEX           0x4046
#define RS_VAR_SHROOMISH_SIZE_RECORD  0x4047
#define RS_VAR_ASH_GATHER_COUNT       0x4048
#define RS_VAR_BIRCH_STATE            0x4049
#define RS_VAR_CRUISE_STEP_COUNT      0x404A
#define RS_VAR_LOTTERY_RND_L          0x404B
#define RS_VAR_LOTTERY_RND_H          0x404C

#define RS_VAR_BARBOACH_SIZE_RECORD   0x404F
#define RS_VAR_LITTLEROOT_STATE       0x4050
#define RS_VAR_ROUTE102_ACCESSIBLE    0x4051

#define RS_VAR_LAVARIDGE_RIVAL_STATE  0x4053
#define RS_VAR_CURRENT_SECRET_BASE    0x4054

#define RS_VAR_PETALBURG_STATE        0x4057
#define RS_VAR_SLATEPORT_STATE        0x4058

#define RS_VAR_RUSTBORO_STATE         0x405A

#define RS_VAR_SOOTOPOLIS_STATE       0x405E

#define RS_VAR_ROUTE101_STATE         0x4060

#define RS_VAR_ROUTE103_STATE         0x4062

#define RS_VAR_ROUTE110_STATE         0x4069

#define RS_VAR_ROUTE116_STATE         0x406F

#define RS_VAR_ROUTE118_STATE         0x4071
#define RS_VAR_ROUTE119_STATE         0x4072

#define RS_VAR_ROUTE121_STATE         0x4074
#define RS_VAR_ROUTE128_STATE         0x407B

#define RS_VAR_LITTLEROOT_HOUSES_STATE 0x4082 // TODO: needs more investigation

#define RS_VAR_BIRCH_LAB_STATE         0x4084
#define RS_VAR_PETALBURG_GYM_STATE     0x4085
#define RS_VAR_LINK_CONTEST_ROOM_STATE 0x4086
#define RS_VAR_CABLE_CLUB_STATE        0x4087
#define RS_VAR_CONTEST_LOCATION        0x4088
#define RS_VAR_SECRET_BASE_INITIALIZED 0x4089
#define RS_VAR_CONTEST_PRIZE_PICKUP    0x408A

#define RS_VAR_LITTLEROOT_HOUSES_STATE_2 0x408C // TODO: needs more investigation
#define RS_VAR_LITTLEROOT_RIVAL_STATE    0x408D
#define RS_VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE 0x408E
#define RS_VAR_DEVON_CORP_3F_STATE       0x408F
#define RS_VAR_BRINEY_HOUSE_STATE        0x4090

#define RS_VAR_LITTLEROOT_INTRO_STATE   0x4092
#define RS_VAR_MAUVILLE_GYM_STATE       0x4093
#define RS_VAR_LILYCOVE_MUSEUM_2F_STATE 0x4094
#define RS_VAR_LILYCOVE_FAN_CLUB_STATE  0x4095
#define RS_VAR_BRINEY_LOCATION          0x4096
#define RS_VAR_INIT_SECRET_BASE         0x4097
#define RS_VAR_PETALBURG_WOODS_STATE    0x4098
#define RS_VAR_LILYCOVE_CONTEST_LOBBY_STATE 0x4099
#define RS_VAR_RUSTURF_TUNNEL_STATE     0x409a
#define RS_VAR_CAVE_OF_ORIGIN_B4F_STATE 0x409B
#define RS_VAR_ELITE_4_STATE            0x409C

#define RS_VAR_SLATEPORT_HARBOR_STATE   0x40A0

#define RS_VAR_SEAFLOOR_CAVERN_STATE         0x40A2
#define RS_VAR_CABLE_CAR_STATION_STATE       0x40A3
#define RS_VAR_SAFARI_ZONE_STATE             0x40A4
#define RS_VAR_TRICK_HOUSE_ENTRANCE_STATE    0x40A5
#define RS_VAR_TRICK_HOUSE_ENTRANCE_STATE_2  0x40A6
#define RS_VAR_TRICK_HOUSE_ENTRANCE_STATE_3  0x40A7

#define RS_VAR_CYCLING_CHALLENGE_STATE       0x40A9
#define RS_VAR_SLATEPORT_MUSEUM_1F_STATE     0x40AA
#define RS_VAR_TRICK_HOUSE_PUZZLE_1_STATE    0x40AB
#define RS_VAR_TRICK_HOUSE_PUZZLE_2_STATE    0x40AC
#define RS_VAR_TRICK_HOUSE_PUZZLE_3_STATE    0x40AD
#define RS_VAR_TRICK_HOUSE_PUZZLE_4_STATE    0x40AE
#define RS_VAR_TRICK_HOUSE_PUZZLE_5_STATE    0x40AF
#define RS_VAR_TRICK_HOUSE_PUZZLE_6_STATE    0x40B0
#define RS_VAR_TRICK_HOUSE_PUZZLE_7_STATE    0x40B1
#define RS_VAR_TRICK_HOUSE_PUZZLE_8_STATE    0x40B2
#define RS_VAR_WEATHER_INSTITUTE_STATE       0x40B3
#define RS_VAR_PORTHOLE_STATE                0x40B4
#define RS_VAR_TRICK_HOUSE_STATE             0x40B5 // TODO: needs some further investigation
#define RS_VAR_TRICK_HOUSE_PUZZLE_7_STATE_2  0x40B6
#define RS_VAR_SLATEPORT_FAN_CLUB_STATE      0x40B7

#define RS_VAR_MT_PYRE_STATE                 0x40B9
#define RS_VAR_NEW_MAUVILLE_STATE            0x40BA

#define RS_VAR_BRAVO_TRAINER_BATTLE_TOWER_ON 0x40BC
#define RS_VAR_JAGGED_PASS_ASH_WEATHER       0x40BD
#define RS_VAR_GLASS_WORKSHOP_STATE          0x40BE
#define RS_VAR_METEOR_FALLS_STATE            0x40BF
#define RS_VAR_GAME_CORNER_STATE             0x40C0
#define RS_VAR_TRICK_HOUSE_PRIZE_PICKUP      0x40C1
#define RS_VAR_PACIFIDLOG_TM_RECEIVED_DAY    0x40C2
#define RS_VAR_VICTORY_ROAD_1F_STATE         0x40C3
#define RS_VAR_FOSSIL_RESURRECTION_STATE     0x40C4
#define RS_VAR_WHICH_FOSSIL_REVIVED          0x40C5
#define RS_VAR_STEVENS_HOUSE_STATE           0x40C6
#define RS_VAR_OLDALE_STATE                  0x40C7

#define RS_VARS_END                          0x40FF

#endif // GUARD_CONSTANTS_RS_VARS_H
