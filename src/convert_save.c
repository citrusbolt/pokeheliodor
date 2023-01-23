#include "global.h"
#include "other_saves.h"
#include "save.h"
#include "union_room_chat.h"
#include "lilycove_lady.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "match_call.h"
#include "trainer_hill.h"
#include "event_data.h"
#include "malloc.h"

/*
Need to look into
FLAG_MET_TEAM_AQUA_HARBOR
FLAG_WHITEOUT_TO_LAVARIDGE
RS_FLAG_LEGENDARY_BATTLE_COMPLETED
FLAG_SCOTT_CALL_BATTLE_FRONTIER
FLAG_DEFEATED_MAGMA_SPACE_CENTER
FLAG_LANDMARK_MIRAGE_TOWER
FLAG_REGISTER_RIVAL_POKENAV
FLAG_DEFEATED_RIVAL_ROUTE_104
FLAG_ENABLE_ROXANNE_FIRST_CALL
FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
FLAG_SCOTT_CALL_FORTREE_GYM
RS_FLAG_RECEIVED_CONTEST_PASS
FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
FLAG_HIDE_SECRET_BASE_TRAINER
FLAG_DECORATION_*
FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_*
FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
FLAG_MET_ARCHIE_METEOR_FALLS
FLAG_DEFEATED_RIVAL_RUSTBORO
FLAG_RECEIVED_RED_OR_BLUE_ORB
RS_FLAG_ROUTE104_PROTOTYPE_COMPLETED_*
FLAG_ENABLE_WALLY_MATCH_CALL
FLAG_ENABLE_SCOTT_MATCH_CALL
FLAG_ENABLE_MOM_MATCH_CALL
FLAG_NEVER_SET_0x0DC
FLAG_ENABLE_RIVAL_MATCH_CALL
FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
FLAG_HAS_MATCH_CALL
FLAG_ADDED_MATCH_CALL_TO_POKENAV
FLAG_REGISTERED_STEVEN_POKENAV
FLAG_ENABLE_NORMAN_MATCH_CALL
FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
FLAG_MET_ARCHIE_SOOTOPOLIS
FLAG_MET_MAXIE_SOOTOPOLIS
FLAG_MET_SCOTT_RUSTBORO
FLAG_WALLACE_GOES_TO_SKY_PILLAR
FLAG_RECEIVED_HM07
FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
FLAG_RECEIVED_POWDER_JAR
FLAG_ENTERED_CONTEST
FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
FLAG_ENABLE_MR_STONE_POKENAV
FLAG_MATCH_CALL_REGISTERED
FLAG_SHOWN_EON_TICKET
FLAG_DEFEATED_*
FLAG_MET_SCOTT_IN_*
FLAG_ENABLE_*_MATCH_CALL
FLAG_HIDE_APPRENTICE
FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
RS_FLAG_HIDE_STEVENS_LETTER
FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION
FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER
FLAG_HIDE_SLATEPORT_CITY_SCOTT
FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
FLAG_HIDE_MAUVILLE_CITY_SCOTT
FLAG_HIDE_VERDANTURF_TOWN_SCOTT
FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
FLAG_HIDE_MARINE_CAVE_KYOGRE
FLAG_HIDE_TERRA_CAVE_GROUDON
FLAG_HIDE_ROUTE_119_SCOTT
FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
FLAG_HIDE_MOSSDEEP_CITY_SCOTT
FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
RS_FLAG_HIDE_CONTEST_REPORTER_FALLARBOR
RS_FLAG_HIDE_CONTEST_REPORTER_VERDANTURF
FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT
RS_FLAG_HIDE_WALLY_FATHER_PETALBURG
FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
RS_FLAG_HIDE_WALLY_MOTHER_PETALBURG
FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
RS_FLAG_HIDE_WALLACE_SOOTOPOLIS_GYM
FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE
FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
FLAG_HIDE_ROUTE_110_BIRCH
FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA
FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP
FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON
RS_FLAG_HIDE_CAVE_OF_ORIGIN_ENTRANCE_WOMAN_1
RS_FLAG_HIDE_CAVE_OF_ORIGIN_ENTRANCE_WOMAN_2
FLAG_HIDE_SKY_PILLAR_WALLACE
FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
FLAG_UNKNOWN_0x363
FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
FLAG_HIDE_ROUTE_111_PLAYER_DESCENT
FLAG_HIDE_ROUTE_111_DESERT_FOSSIL
FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
RS_FLAG_HIDE_LATIOS_OR_LATIAS_FLYING
FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE
RS_FLAG_HIDE_LATIOS_OR_LATIAS_STATIONARY
FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON
FLAG_UNKNOWN_0x393
RS_FLAG_HIDE_AWARD_MAN_BATTLE_TOWER
FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
FLAG_HIDE_PETALBURG_CITY_SCOTT
FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA
FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
FLAG_DEFEATED_METEOR_FALLS_STEVEN
FLAG_IS_CHAMPION
FLAG_NURSE_UNION_ROOM_REMINDER
RS_FLAG_SYS_NATIONAL_DEX


Reset all items?
Trainer flag convert
Vars




static const u16 sRSFlagsToNLFlags[] = {
    [RS_FLAG_TEMP_1]                                     = FLAG_TEMP_1,
    [RS_FLAG_TEMP_2]                                     = FLAG_TEMP_2,
    [RS_FLAG_TEMP_3]                                     = FLAG_TEMP_3,
    [RS_FLAG_TEMP_4]                                     = FLAG_TEMP_4,
    [RS_FLAG_TEMP_5]                                     = FLAG_TEMP_5,
    [RS_FLAG_TEMP_6]                                     = FLAG_TEMP_6,
    [RS_FLAG_TEMP_7]                                     = FLAG_TEMP_7,
    [RS_FLAG_TEMP_8]                                     = FLAG_TEMP_8,
    [RS_FLAG_TEMP_9]                                     = FLAG_TEMP_9,
    [RS_FLAG_TEMP_A]                                     = FLAG_TEMP_A,
    [RS_FLAG_TEMP_B]                                     = FLAG_TEMP_B,
    [RS_FLAG_TEMP_C]                                     = FLAG_TEMP_C,
    [RS_FLAG_TEMP_D]                                     = FLAG_TEMP_D,
    [RS_FLAG_TEMP_E]                                     = FLAG_TEMP_E,
    [RS_FLAG_TEMP_F]                                     = FLAG_TEMP_F,
    [RS_FLAG_TEMP_10]                                    = FLAG_TEMP_10,
    [RS_FLAG_TEMP_11]                                    = FLAG_TEMP_11,
    [RS_FLAG_TEMP_12]                                    = FLAG_TEMP_12,
    [RS_FLAG_TEMP_13]                                    = FLAG_TEMP_13,
    [RS_FLAG_TEMP_14]                                    = FLAG_TEMP_14,
    [RS_FLAG_TEMP_15]                                    = FLAG_TEMP_15,
    [RS_FLAG_TEMP_16]                                    = FLAG_TEMP_16,
    [RS_FLAG_TEMP_17]                                    = FLAG_TEMP_17,
    [RS_FLAG_TEMP_18]                                    = FLAG_TEMP_18,
    [RS_FLAG_TEMP_19]                                    = FLAG_TEMP_19,
    [RS_FLAG_TEMP_1A]                                    = FLAG_TEMP_1A,
    [RS_FLAG_TEMP_1B]                                    = FLAG_TEMP_1B,
    [RS_FLAG_TEMP_1C]                                    = FLAG_TEMP_1C,
    [RS_FLAG_TEMP_1D]                                    = FLAG_TEMP_1D,
    [RS_FLAG_TEMP_1E]                                    = FLAG_TEMP_1E,
    [RS_FLAG_TEMP_1F]                                    = FLAG_TEMP_1F,
    [RS_FLAG_TEMP_20]                                    = FLAG_TEMP_15,
    [RS_FLAG_SET_WALL_CLOCK]                             = FLAG_SET_WALL_CLOCK,
    [RS_FLAG_RESCUED_BIRCH]                              = FLAG_RESCUED_BIRCH,
    [RS_FLAG_LINK_CONTEST_ROOM_POKEBALL]                 = FLAG_HIDE_CONTEST_POKE_BALL,
    [RS_FLAG_MET_RIVAL_MOM]                              = FLAG_MET_RIVAL_MOM,
    [RS_FLAG_BIRCH_AIDE_MET]                             = FLAG_BIRCH_AIDE_MET,
    [RS_FLAG_DECLINED_BIKE]                              = FLAG_DECLINED_BIKE,
    [RS_FLAG_RECEIVED_BIKE]                              = FLAG_RECEIVED_BIKE,
    [RS_FLAG_RECEIVED_WAILMER_PAIL]                      = FLAG_RECEIVED_WAILMER_PAIL,
    [RS_FLAG_RECEIVED_POKEBLOCK_CASE]                    = FLAG_RECEIVED_POKEBLOCK_CASE,
    [RS_FLAG_RECEIVED_SECRET_POWER]                      = FLAG_RECEIVED_SECRET_POWER,
    [RS_FLAG_TV_EXPLAINED]                               = FLAG_TV_EXPLAINED,
    [RS_FLAG_MAUVILLE_GYM_BARRIERS_STATE]                = FLAG_MAUVILLE_GYM_BARRIERS_STATE,
    [RS_FLAG_MOSSDEEP_GYM_SWITCH_1]                      = FLAG_MOSSDEEP_GYM_SWITCH_1,
    [RS_FLAG_MOSSDEEP_GYM_SWITCH_2]                      = FLAG_MOSSDEEP_GYM_SWITCH_2,
    [RS_FLAG_MOSSDEEP_GYM_SWITCH_3]                      = FLAG_MOSSDEEP_GYM_SWITCH_3,
    [RS_FLAG_MOSSDEEP_GYM_SWITCH_4]                      = FLAG_MOSSDEEP_GYM_SWITCH_4,
    [RS_FLAG_OCEANIC_MUSEUM_MET_REPORTER]                = FLAG_OCEANIC_MUSEUM_MET_REPORTER,
    [RS_FLAG_RECEIVED_HM04]                              = FLAG_RECEIVED_HM04
    [RS_FLAG_RECEIVED_HM06]                              = 
    [RS_FLAG_RECEIVED_HM05]                              = 
    [RS_FLAG_RECEIVED_HM02]                              = 
    [RS_FLAG_MT_PYRE_ORB_STOLEN]                         = 
    [RS_FLAG_EVIL_TEAM_ESCAPED_IN_SUBMARINE]             = 
    [RS_FLAG_LEGENDARY_BATTLE_COMPLETED]                 = 
    [RS_FLAG_RECEIVED_METEORITE]                         = 
    [RS_FLAG_ADVENTURE_STARTED]                          = 
    [RS_FLAG_MET_HIDDEN_POWER_GIVER]                     = 
    [RS_FLAG_RECEIVED_TM31]                              = 
    [RS_FLAG_RECEIVED_HM03]                              = 
    [RS_FLAG_RECEIVED_HM08]                              = 
    [RS_FLAG_DEFEATED_WALLY_VICTORY_ROAD]                = 
    [RS_FLAG_MET_PRETTY_PETAL_SHOP_OWNER]                = 
    [RS_FLAG_LEGEND_ESCAPED_SEAFLOOR_CAVERN]             = 
    [RS_FLAG_DEFEATED_RIVAL_ROUTE103]                    = 
    [RS_FLAG_RECEIVED_DOLL_LANETTE]                      = 
    [RS_FLAG_RECEIVED_POTION_OLDALE]                     = 
    [RS_FLAG_RECEIVED_AMULET_COIN]                       = 
    [RS_FLAG_PENDING_DAYCARE_EGG]                        = 
    [RS_FLAG_THANKED_FOR_PLAYING_WITH_WALLY]             = 
    [RS_FLAG_RECEIVED_HM01]                              = 
    [RS_FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY]              = 
    [RS_FLAG_RECEIVED_6_SODA_POP]                        = 
    [RS_FLAG_DEFEATED_SEASHORE_HOUSE_TRAINERS]           = 
    [RS_FLAG_DEVON_GOODS_STOLEN]                         = 
    [RS_FLAG_RECOVERED_DEVON_GOODS]                      = 
    [RS_FLAG_RETURNED_DEVON_GOODS]                       = 
    [RS_FLAG_MR_BRINEY_SAILING_INTRO]                    = 
    [RS_FLAG_DOCK_REJECTED_DEVON_GOODS]                  = 
    [RS_FLAG_DELIVERED_DEVON_GOODS]                      = 
    [RS_FLAG_RECEIVED_CONTEST_PASS]                      = 
    [RS_FLAG_RECEIVED_CASTFORM]                          = 
    [RS_FLAG_RECEIVED_SUPER_ROD]                         = 
    [RS_FLAG_RUSTBORO_NPC_TRADE_COMPLETED]               = 
    [RS_FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED]             = 
    [RS_FLAG_FORTREE_NPC_TRADE_COMPLETED]                = 
    [RS_FLAG_UNKNOWN_9F]                                 = 
    [RS_FLAG_COOL_PAINTING_MADE]                         = 
    [RS_FLAG_BEAUTY_PAINTING_MADE]                       = 
    [RS_FLAG_CUTE_PAINTING_MADE]                         = 
    [RS_FLAG_SMART_PAINTING_MADE]                        = 
    [RS_FLAG_TOUGH_PAINTING_MADE]                        = 
    [RS_FLAG_RECEIVED_TM39]                              = 
    [RS_FLAG_RECEIVED_TM08]                              = 
    [RS_FLAG_RECEIVED_TM34]                              = 
    [RS_FLAG_RECEIVED_TM50]                              = 
    [RS_FLAG_RECEIVED_TM42]                              = 
    [RS_FLAG_RECEIVED_TM40]                              = 
    [RS_FLAG_RECEIVED_TM04]                              = 
    [RS_FLAG_RECEIVED_TM03]                              = 
    [RS_FLAG_DECORATION_1]                               = 
    [RS_FLAG_DECORATION_2]                               = 
    [RS_FLAG_DECORATION_3]                               = 
    [RS_FLAG_DECORATION_4]                               = 
    [RS_FLAG_DECORATION_5]                               = 
    [RS_FLAG_DECORATION_6]                               = 
    [RS_FLAG_DECORATION_7]                               = 
    [RS_FLAG_DECORATION_8]                               = 
    [RS_FLAG_DECORATION_9]                               = 
    [RS_FLAG_DECORATION_10]                              = 
    [RS_FLAG_DECORATION_11]                              = 
    [RS_FLAG_DECORATION_12]                              = 
    [RS_FLAG_DECORATION_13]                              = 
    [RS_FLAG_DECORATION_14]                              = 
    [RS_FLAG_DECORATION_15]                              = 
    [RS_FLAG_RECEIVED_POKENAV]                           = 
    [RS_FLAG_DELIVERED_STEVEN_LETTER]                    = 
    [RS_FLAG_DEFEATED_WALLY_MAUVILLE]                    = 
    [RS_FLAG_RECEIVED_SUN_STONE_MOSSDEEP]                = 
    [RS_FLAG_WALLY_SPEECH]                               = 
    [RS_FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1]              = 
    [RS_FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2]              = 
    [RS_FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3]              = 
    [RS_FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4]              = 
    [RS_FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5]              = 
    [RS_FLAG_RUSTURF_TUNNEL_OPENED]                      = 
    [RS_FLAG_RECEIVED_RED_SCARF]                         = 
    [RS_FLAG_RECEIVED_BLUE_SCARF]                        = 
    [RS_FLAG_RECEIVED_PINK_SCARF]                        = 
    [RS_FLAG_RECEIVED_GREEN_SCARF]                       = 
    [RS_FLAG_RECEIVED_YELLOW_SCARF]                      = 
    [RS_FLAG_ENCOUNTERED_LATIAS_OR_LATIOS]               = 
    [RS_FLAG_RECEIVED_BASEMENT_KEY]                      = 
    [RS_FLAG_RECEIVED_TM24]                              = 
    [RS_FLAG_RECEIVED_RED_OR_BLUE_ORB]                   = 
    [RS_FLAG_RECEIVED_PREMIER_BALL_RUSTBORO]             = 
    [RS_FLAG_ROUTE104_PROTOTYPE_COMPLETED_1]             = 
    [RS_FLAG_ROUTE104_PROTOTYPE_COMPLETED_2]             = 
    [RS_FLAG_MET_DIVING_TREASURE_HUNTER]                 = 
    [RS_FLAG_MET_WAILMER_TRAINER]                        = 
    [RS_FLAG_EVIL_LEADER_PLEASE_STOP]                    = 
    [RS_FLAG_RECEIVED_GO_GOGGLES]                        = 
    [RS_FLAG_WINGULL_SENT_ON_ERRAND]                     = 
    [RS_FLAG_RECEIVED_MENTAL_HERB]                       = 
    [RS_FLAG_WINGULL_DELIVERED_MAIL]                     = 
    [RS_FLAG_RECEIVED_20_COINS]                          = 
    [RS_FLAG_RECEIVED_STARTER_DOLL]                      = 
    [RS_FLAG_RECEIVED_GOOD_ROD]                          = 
    [RS_FLAG_REGI_DOORS_OPENED]                          = 
    [RS_FLAG_RECEIVED_TM27]                              = 
    [RS_FLAG_RECEIVED_TM36]                              = 
    [RS_FLAG_RECEIVED_TM05]                              = 
    [RS_FLAG_RECEIVED_TM19]                              = 
    [RS_FLAG_RECEIVED_TM44]                              = 
    [RS_FLAG_RECEIVED_TM45]                              = 
    [RS_FLAG_RECEIVED_GLASS_ORNAMENT]                    = 
    [RS_FLAG_RECEIVED_SILVER_SHIELD]                     = 
    [RS_FLAG_RECEIVED_GOLD_SHIELD]                       = 
    [RS_FLAG_USED_STORAGE_KEY]                           = 
    [RS_FLAG_USED_ROOM_1_KEY]                            = 
    [RS_FLAG_USED_ROOM_2_KEY]                            = 
    [RS_FLAG_USED_ROOM_4_KEY]                            = 
    [RS_FLAG_USED_ROOM_6_KEY]                            = 
    [RS_FLAG_MET_PROF_COSMO]                             = 
    [RS_FLAG_RECEIVED_WAILMER_DOLL]                      = 
    [RS_FLAG_RECEIVED_CHESTO_BERRY_ROUTE104]             = 
    [RS_FLAG_DEFEATED_SS_TIDAL_TRAINERS]                 = 
    [RS_FLAG_RECEIVED_SPELON_BERRY]                      = 
    [RS_FLAG_RECEIVED_PAMTRE_BERRY]                      = 
    [RS_FLAG_RECEIVED_WATMEL_BERRY]                      = 
    [RS_FLAG_RECEIVED_DURIN_BERRY]                       = 
    [RS_FLAG_RECEIVED_BELUE_BERRY]                       = 
    [RS_FLAG_RECEIVED_CHARCOAL]                          = 
    [RS_FLAG_LATIOS_OR_LATIAS_ROAMING]                   = 
    [RS_FLAG_RECEIVED_REPEAT_BALL]                       = 
    [RS_FLAG_RECEIVED_OLD_ROD]                           = 
    [RS_FLAG_RECEIVED_COIN_CASE]                         = 
    [RS_FLAG_RETURNED_RED_OR_BLUE_ORB]                   = 
    [RS_FLAG_RECEIVED_TM49]                              = 
    [RS_FLAG_RECEIVED_TM28]                              = 
    [RS_FLAG_RECEIVED_TM09]                              = 
    [RS_FLAG_ENTERED_ELITE_FOUR]                         = 
    [RS_FLAG_RECEIVED_TM10]                              = 
    [RS_FLAG_RECEIVED_TM41]                              = 
    [RS_FLAG_RECEIVED_LAVARIDGE_EGG]                     = 
    [RS_FLAG_RECEIVED_FOSSIL_MON]                        = 
    [RS_FLAG_SECRET_BASE_REGISTRY_ENABLED]               = 
    [RS_FLAG_RECEIVED_TM46]                              = 
    [RS_FLAG_CONTEST_SKETCH_CREATED]                     = 
    [RS_FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE]              = 
    [RS_FLAG_RECEIVED_EXP_SHARE]                         = 
    [RS_FLAG_POKERUS_EXPLAINED]                          = 
    [RS_FLAG_RECEIVED_RUNNING_SHOES]                     = 
    [RS_FLAG_RECEIVED_QUICK_CLAW]                        = 
    [RS_FLAG_RECEIVED_KINGS_ROCK]                        = 
    [RS_FLAG_RECEIVED_MACHO_BRACE]                       = 
    [RS_FLAG_RECEIVED_SOOTHE_BELL]                       = 
    [RS_FLAG_RECEIVED_WHITE_HERB]                        = 
    [RS_FLAG_RECEIVED_SOFT_SAND]                         = 
    [RS_FLAG_RECEIVED_CLEANSE_TAG]                       = 
    [RS_FLAG_RECEIVED_FOCUS_BAND]                        = 
    [RS_FLAG_DECLINED_WALLY_BATTLE_MAUVILLE]             = 
    [RS_FLAG_RECEIVED_DEVON_SCOPE]                       = 
    [RS_FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE]             = 
    [RS_FLAG_MET_DEVON_EMPLOYEE]                         = 
    [RS_FLAG_MET_RIVAL_RUSTBORO]                         = 
    [RS_FLAG_RECEIVED_SILK_SCARF]                        = 
    [RS_FLAG_NOT_READY_FOR_BATTLE_ROUTE120]              = 
    [RS_FLAG_RECEIVED_SS_TICKET]                         = 
    [RS_FLAG_MET_RIVAL_LILYCOVE]                         = 
    [RS_FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE]          = 
    [RS_FLAG_EXCHANGED_SCANNER]                          = 
    [RS_FLAG_KECLEON_FLED_FORTREE]                       = 
    [RS_FLAG_PETALBURG_MART_EXPANDED_ITEMS]              = 
    [RS_FLAG_RECEIVED_MIRACLE_SEED]                      = 
    [RS_FLAG_RECEIVED_BELDUM]                            = 
    [RS_FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK]              = 
    [RS_FLAG_MET_FANCLUB_YOUNGER_BROTHER]                = 
    [RS_FLAG_RIVAL_LEFT_FOR_ROUTE103]                    = 
    [RS_FLAG_OMIT_DIVE_FROM_STEVEN_LETTER]               = 
    [RS_FLAG_HIDDEN_ITEM_0]                              = 
    [RS_FLAG_HIDDEN_ITEM_1]                              = 
    [RS_FLAG_HIDDEN_ITEM_2]                              = 
    [RS_FLAG_HIDDEN_ITEM_3]                              = 
    [RS_FLAG_HIDDEN_ITEM_4]                              = 
    [RS_FLAG_HIDDEN_ITEM_5]                              = 
    [RS_FLAG_HIDDEN_ITEM_6]                              = 
    [RS_FLAG_HIDDEN_ITEM_7]                              = 
    [RS_FLAG_HIDDEN_ITEM_8]                              = 
    [RS_FLAG_HIDDEN_ITEM_9]                              = 
    [RS_FLAG_HIDDEN_ITEM_A]                              = 
    [RS_FLAG_HIDDEN_ITEM_B]                              = 
    [RS_FLAG_HIDDEN_ITEM_C]                              = 
    [RS_FLAG_HIDDEN_ITEM_D]                              = 
    [RS_FLAG_HIDDEN_ITEM_E]                              = 
    [RS_FLAG_HIDDEN_ITEM_F]                              = 
    [RS_FLAG_HIDDEN_ITEM_10]                             = 
    [RS_FLAG_HIDDEN_ITEM_11]                             = 
    [RS_FLAG_HIDDEN_ITEM_12]                             = 
    [RS_FLAG_HIDDEN_ITEM_13]                             = 
    [RS_FLAG_HIDDEN_ITEM_14]                             = 
    [RS_FLAG_HIDDEN_ITEM_15]                             = 
    [RS_FLAG_HIDDEN_ITEM_16]                             = 
    [RS_FLAG_HIDDEN_ITEM_17]                             = 
    [RS_FLAG_HIDDEN_ITEM_18]                             = 
    [RS_FLAG_HIDDEN_ITEM_19]                             = 
    [RS_FLAG_HIDDEN_ITEM_1A]                             = 
    [RS_FLAG_HIDDEN_ITEM_1B]                             = 
    [RS_FLAG_HIDDEN_ITEM_1C]                             = 
    [RS_FLAG_HIDDEN_ITEM_1D]                             = 
    [RS_FLAG_HIDDEN_ITEM_1E]                             = 
    [RS_FLAG_HIDDEN_ITEM_1F]                             = 
    [RS_FLAG_HIDDEN_ITEM_20]                             = 
    [RS_FLAG_HIDDEN_ITEM_21]                             = 
    [RS_FLAG_HIDDEN_ITEM_22]                             = 
    [RS_FLAG_HIDDEN_ITEM_23]                             = 
    [RS_FLAG_HIDDEN_ITEM_24]                             = 
    [RS_FLAG_HIDDEN_ITEM_25]                             = 
    [RS_FLAG_HIDDEN_ITEM_26]                             = 
    [RS_FLAG_HIDDEN_ITEM_27]                             = 
    [RS_FLAG_HIDDEN_ITEM_28]                             = 
    [RS_FLAG_HIDDEN_ITEM_29]                             = 
    [RS_FLAG_HIDDEN_ITEM_2A]                             = 
    [RS_FLAG_HIDDEN_ITEM_2B]                             = 
    [RS_FLAG_HIDDEN_ITEM_2C]                             = 
    [RS_FLAG_HIDDEN_ITEM_2D]                             = 
    [RS_FLAG_HIDDEN_ITEM_2E]                             = 
    [RS_FLAG_HIDDEN_ITEM_2F]                             = 
    [RS_FLAG_HIDDEN_ITEM_30]                             = 
    [RS_FLAG_HIDDEN_ITEM_31]                             = 
    [RS_FLAG_HIDDEN_ITEM_32]                             = 
    [RS_FLAG_HIDDEN_ITEM_33]                             = 
    [RS_FLAG_HIDDEN_ITEM_34]                             = 
    [RS_FLAG_HIDDEN_ITEM_35]                             = 
    [RS_FLAG_HIDDEN_ITEM_36]                             = 
    [RS_FLAG_HIDDEN_ITEM_37]                             = 
    [RS_FLAG_HIDDEN_ITEM_38]                             = 
    [RS_FLAG_HIDDEN_ITEM_39]                             = 
    [RS_FLAG_HIDDEN_ITEM_3A]                             = 
    [RS_FLAG_HIDDEN_ITEM_3B]                             = 
    [RS_FLAG_HIDDEN_ITEM_3C]                             = 
    [RS_FLAG_HIDDEN_ITEM_3D]                             = 
    [RS_FLAG_HIDDEN_ITEM_3E]                             = 
    [RS_FLAG_HIDDEN_ITEM_3F]                             = 
    [RS_FLAG_HIDDEN_ITEM_40]                             = 
    [RS_FLAG_HIDDEN_ITEM_41]                             = 
    [RS_FLAG_HIDDEN_ITEM_42]                             = 
    [RS_FLAG_HIDDEN_ITEM_43]                             = 
    [RS_FLAG_HIDDEN_ITEM_44]                             = 
    [RS_FLAG_HIDDEN_ITEM_45]                             = 
    [RS_FLAG_HIDDEN_ITEM_46]                             = 
    [RS_FLAG_HIDDEN_ITEM_47]                             = 
    [RS_FLAG_HIDDEN_ITEM_48]                             = 
    [RS_FLAG_HIDDEN_ITEM_49]                             = 
    [RS_FLAG_HIDDEN_ITEM_4A]                             = 
    [RS_FLAG_HIDDEN_ITEM_4B]                             = 
    [RS_FLAG_HIDDEN_ITEM_4C]                             = 
    [RS_FLAG_HIDDEN_ITEM_4D]                             = 
    [RS_FLAG_HIDDEN_ITEM_4E]                             = 
    [RS_FLAG_HIDDEN_ITEM_4F]                             = 
    [RS_FLAG_HIDDEN_ITEM_50]                             = 
    [RS_FLAG_HIDDEN_ITEM_51]                             = 
    [RS_FLAG_HIDDEN_ITEM_52]                             = 
    [RS_FLAG_HIDDEN_ITEM_53]                             = 
    [RS_FLAG_HIDDEN_ITEM_54]                             = 
    [RS_FLAG_HIDDEN_ITEM_55]                             = 
    [RS_FLAG_HIDDEN_ITEM_56]                             = 
    [RS_FLAG_HIDDEN_ITEM_57]                             = 
    [RS_FLAG_HIDDEN_ITEM_58]                             = 
    [RS_FLAG_HIDDEN_ITEM_59]                             = 
    [RS_FLAG_HIDDEN_ITEM_5A]                             = 
    [RS_FLAG_HIDDEN_ITEM_5B]                             = 
    [RS_FLAG_HIDDEN_ITEM_5C]                             = 
    [RS_FLAG_HIDDEN_ITEM_5D]                             = 
    [RS_FLAG_HIDDEN_ITEM_5E]                             = 
    [RS_FLAG_HIDDEN_ITEM_5F]                             = 
    [RS_FLAG_HIDDEN_ITEM_BLACK_GLASSES]                  = 
    [RS_FLAG_HIDDEN_ITEM_61]                             = 
    [RS_FLAG_HIDE_BIRCH_STARTERS_BAG]                    = 
    [RS_FLAG_HIDE_BIRCH_BATTLE_POOCHYENA]                = 
    [RS_FLAG_HIDE_BIRCH_IN_LAB]                          = 
    [RS_FLAG_HIDE_MAY_UPSTAIRS]                          = 
    [RS_FLAG_HIDE_RIVAL_ROUTE103]                        = 
    [RS_FLAG_HIDE_DEVON_PETALBURG_WOODS]                 = 
    [RS_FLAG_HIDE_EVIL_TEAM_PETALBURG_WOODS]             = 
    [RS_FLAG_HIDE_WALLY_PETALBURG]                       = 
    [RS_FLAG_HIDE_STEVENS_LETTER]                        = 
    [RS_FLAG_HIDE_WALLY_MOM_PETALBURG_1]                 = 
    [RS_FLAG_HIDE_GRUNT_RUSTBORO]                        = 
    [RS_FLAG_HIDE_DEVON_RUSTBORO]                        = 
    [RS_FLAG_HIDE_SLEEPING_MON_SEAFLOOR_CAVERN]          = 
    [RS_FLAG_HIDE_NORMAN_LITTLEROOT]                     = 
    [RS_FLAG_UNKNOWN_2E1]                                = 
    [RS_FLAG_HIDE_MR_BRINEY_ROUTE104]                    = 
    [RS_FLAG_HIDE_MR_BRINEY_ROUTE104_HOUSE]              = 
    [RS_FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN]                = 
    [RS_FLAG_HIDE_MR_BRINEY_ROUTE109]                    = 
    [RS_FLAG_HIDE_MR_BRINEY_BOAT_ROUTE104]               = 
    [RS_FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD]                = 
    [RS_FLAG_HIDE_MR_BRINEY_BOAT_ROUTE109]               = 
    [RS_FLAG_UNKNOWN_2EB]                                = 
    [RS_FLAG_UNKNOWN_2EC]                                = 
    [RS_FLAG_UNKNOWN_2ED]                                = 
    [RS_FLAG_HIDE_POOCHYENA_ROUTE101]                    = 
    [RS_FLAG_HIDE_WALLY_DEFEATED_VICTORY_ROAD]           = 
    [RS_FLAG_HIDE_MOM_LITTLEROOT]                        = 
    [RS_FLAG_HIDE_MACHOKE_MOVER_1]                       = 
    [RS_FLAG_HIDE_MACHOKE_MOVER_2]                       = 
    [RS_FLAG_UNKNOWN_2F4]                                = 
    [RS_FLAG_HIDE_MOM_UPSTAIRS]                          = 
    [RS_FLAG_HIDE_BRENDAN_MOM_DOWNSTAIRS]                = 
    [RS_FLAG_HIDE_MAY_MOM_DOWNSTAIRS]                    = 
    [RS_FLAG_HIDE_BRENDAN_UPSTAIRS]                      = 
    [RS_FLAG_HIDE_MOVING_TRUCK_BRENDAN]                  = 
    [RS_FLAG_HIDE_MOVING_TRUCK_MAY]                      = 
    [RS_FLAG_HIDE_VICTOR_WINSTRATE]                      = 
    [RS_FLAG_HIDE_VICTORIA_WINSTRATE]                    = 
    [RS_FLAG_HIDE_VIVI_WINSTRATE]                        = 
    [RS_FLAG_HIDE_VICKI_WINSTRATE]                       = 
    [RS_FLAG_HIDE_NORMAN_PETALBURG_GYM]                  = 
    [RS_FLAG_HIDE_RAYQUAZA]                              = 
    [RS_FLAG_HIDE_LILYCOVE_CONTEST_ATTENDENT_1]          = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR]               = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_PAINTING_LADY]         = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_PAINTING_GIRL]         = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_PAINTING_MAN]          = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_PAINTER]               = 
    [RS_FLAG_HIDE_LILYCOVE_MUSEUM_VISITORS]              = 
    [RS_FLAG_HIDE_PETALBURG_GYM_GUIDE]                   = 
    [RS_FLAG_UNKNOWN_30E]                                = 
    [RS_FLAG_UNKNOWN_30F]                                = 
    [RS_FLAG_HIDE_BRENDAN_MOM]                           = 
    [RS_FLAG_HIDE_MAY_MOM]                               = 
    [RS_FLAG_HIDE_FANCLUB_OLD_LADY]                      = 
    [RS_FLAG_HIDE_FANCLUB_BOY]                           = 
    [RS_FLAG_HIDE_FANCLUB_LITTLE_BOY]                    = 
    [RS_FLAG_HIDE_FANCLUB_LADY]                          = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE111_1]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE118_1]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE120_1]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE111_2]               = 
    [RS_FLAG_HIDE_CONTEST_REPORTER_FALLARBOR]            = 
    [RS_FLAG_HIDE_CONTEST_REPORTER_VERDANTURF]           = 
    [RS_FLAG_HIDE_CONTEST_REPORTER_LILYCOVE]             = 
    [RS_FLAG_HIDE_CONTEST_REPORTER_SLATEPORT]            = 
    [RS_FLAG_HIDE_WALLY_MAUVILLE]                        = 
    [RS_FLAG_HIDE_WALLY_FATHER_MAUVILLE]                 = 
    [RS_FLAG_HIDE_WALLY_WANDAS_HOUSE]                    = 
    [RS_FLAG_HIDE_BOYFRIEND_RUSTURF_TUNNEL]              = 
    [RS_FLAG_HIDE_BOYFRIEND_WANDAS_HOUSE]                = 
    [RS_FLAG_HIDE_WALLY_FATHER_WANDAS_HOUSE]             = 
    [RS_FLAG_HIDE_WALLY_FATHER_PETALBURG]                = 
    [RS_FLAG_HIDE_WALLY_MOTHER_PETALBURG]                = 
    [RS_FLAG_HIDE_LOST_GLASSES_MAN]                      = 
    [RS_FLAG_HIDE_RIVAL_RUSTBORO]                        = 
    [RS_FLAG_HIDE_WALLACE_SOOTOPOLIS_GYM]                = 
    [RS_FLAG_HIDE_WALLACE_SOOTOPOLIS]                    = 
    [RS_FLAG_HIDE_GRUNTS_BLOCKING_CABLE_CAR]             = 
    [RS_FLAG_HIDE_GRUNT_1_BLOCKING_HIDEOUT]              = 
    [RS_FLAG_HIDE_GRUNT_2_BLOCKING_HIDEOUT]              = 
    [RS_FLAG_UNKNOWN_337]                                = 
    [RS_FLAG_HIDE_LEGEND_MON_CAVE_OF_ORIGIN]             = 
    [RS_FLAG_HIDE_EVIL_LEADER_SEAFLOOR_CAVERN]           = 
    [RS_FLAG_HIDE_OTHER_LEADER_SEAFLOOR_CAVERN]          = 
    [RS_FLAG_HIDE_OTHER_TEAM_GRUNTS_SEAFLOOR_CAVERN]     = 
    [RS_FLAG_HIDE_STEVEN_GRANITE_CAVE]                   = 
    [RS_FLAG_HIDE_STEVEN_ROUTE128]                       = 
    [RS_FLAG_HIDE_GABBY_AND_TY_SLATEPORT]                = 
    [RS_FLAG_HIDE_STERN_SLATEPORT]                       = 
    [RS_FLAG_HIDE_STERN_SLATEPORT_HARBOR]                = 
    [RS_FLAG_UNKNOWN_34B]                                = 
    [RS_FLAG_UNKNOWN_34C]                                = 
    [RS_FLAG_HIDE_GRUNT_1_SLATEPORT_HARBOR]              = 
    [RS_FLAG_HIDE_GRUNT_2_SLATEPORT_HARBOR]              = 
    [RS_FLAG_UNKNOWN_34F]                                = 
    [RS_FLAG_HIDE_SUBMARINE_SHADOW_SLATEPORT_HARBOR]     = 
    [RS_FLAG_HIDE_MAY_PICHU_DOLL]                        = 
    [RS_FLAG_HIDE_RIVAL_ROUTE119]                        = 
    [RS_FLAG_HIDE_GRUNTS_LILYCOVE]                       = 
    [RS_FLAG_HIDE_SOOTOPOLIS_RESIDENTS]                  = 
    [RS_FLAG_HIDE_CAVE_OF_ORIGIN_ENTRANCE_WOMAN_1]       = 
    [RS_FLAG_HIDE_CAVE_OF_ORIGIN_ENTRANCE_WOMAN_2]       = 
    [RS_FLAG_HIDE_WALLY_BATTLE_VICTORY_ROAD]             = 
    [RS_FLAG_HIDE_AWAKENED_MON_SEAFLOOR_CAVERN]          = 
    [RS_FLAG_HIDE_SS_TIDAL_SLATEPORT_HARBOR]             = 
    [RS_FLAG_HIDE_SS_TIDAL_LILYCOVE_HARBOR]              = 
    [RS_FLAG_HIDE_WALLY_PETALBURG_GYM]                   = 
    [RS_FLAG_UNKNOWN_363]                                = 
    [RS_FLAG_HIDE_FAT_MAN_LITTLEROOT]                    = 
    [RS_FLAG_HIDE_BRINEY_SLATEPORT_SHIPYARD]             = 
    [RS_FLAG_HIDE_LANETTE]                               = 
    [RS_FLAG_HIDE_LANETTE_FALLARBOR]                     = 
    [RS_FLAG_HIDE_TRICKMASTER_ENTRANCE]                  = 
    [RS_FLAG_HIDE_MT_CHIMNEY_PEOPLE]                     = 
    [RS_FLAG_HIDE_GRUNT_RUSTURF_TUNNEL]                  = 
    [RS_FLAG_HIDE_BRINEY_RUSTURF_TUNNEL]                 = 
    [RS_FLAG_HIDE_PEEKO_RUSTURF_TUNNEL]                  = 
    [RS_FLAG_HIDE_PEEKO_BRINEY_HOUSE]                    = 
    [RS_FLAG_HIDE_EVIL_TEAM_SLATEPORT]                   = 
    [RS_FLAG_HIDE_EVIL_TEAM_OCEANIC_MUSEUM]              = 
    [RS_FLAG_HIDE_GRUNT_1_OCEANIC_MUSEUM_2F]             = 
    [RS_FLAG_HIDE_GRUNT_2_OCEANIC_MUSEUM_2F]             = 
    [RS_FLAG_HIDE_EVIL_TEAM_LEADER_OCEANIC_MUSEUM_2F]    = 
    [RS_FLAG_HIDE_STERN_OCEANIC_MUSEUM_2F]               = 
    [RS_FLAG_HIDE_BATTLE_TOWER_OPPONENT]                 = 
    [RS_FLAG_HIDE_RIVAL_BIRCH_LAB]                       = 
    [RS_FLAG_HIDE_EVIL_TEAM_WEATHER_INSTITUTE]           = 
    [RS_FLAG_HIDE_BRINEY_ROUTE116]                       = 
    [RS_FLAG_HIDE_WEATHER_INSTITUTE_WORKERS_1F]          = 
    [RS_FLAG_HIDE_WEATHER_INSTITUTE_WORKERS_2F]          = 
    [RS_FLAG_HIDE_TUNNER_DIGGER_ROUTE116]                = 
    [RS_FLAG_HIDE_ARTIST_LILCOVE_CONTEST]                = 
    [RS_FLAG_UNKNOWN_BIRCH_380]                          = 
    [RS_FLAG_HIDE_BIRCH_ROUTE101]                        = 
    [RS_FLAG_HIDE_BIRCH_ROUTE103]                        = 
    [RS_FLAG_HIDE_TRICKMASTER_END]                       = 
    [RS_FLAG_HIDE_EVIL_TEAM_ROUTE110]                    = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE118_2]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE120_2]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE111_3]               = 
    [RS_FLAG_HIDE_GABBY_AND_TY_ROUTE118_3]               = 
    [RS_FLAG_HIDE_WORKERS_SLATEPORT_HARBOR]              = 
    [RS_FLAG_HIDE_FLOWER_SHOP_WORKER_OUTSIDE]            = 
    [RS_FLAG_HIDE_AZURILL_FALLARBOR]                     = 
    [RS_FLAG_HIDE_FERRY_ATTENDANT_LILYCOVE]              = 
    [RS_FLAG_HIDE_FERRY_SAILOR_LILYCOVE]                 = 
    [RS_FLAG_HIDE_LATIOS_OR_LATIAS_FLYING]               = 
    [RS_FLAG_HIDE_LATIOS_OR_LATIAS_STATIONARY]           = 
    [RS_FLAG_HIDE_WATTSON_MAUVILLE]                      = 
    [RS_FLAG_HIDE_WATTSON_MAUVILLE_GYM]                  = 
    [RS_FLAG_HIDE_GRUNTS_ROUTE121]                       = 
    [RS_FLAG_UNKNOWN_393]                                = 
    [RS_FLAG_HIDE_LEADER_MT_PYRE_SUMMIT]                 = 
    [RS_FLAG_HIDE_GRUNTS_MT_PYRE_SUMMIT]                 = 
    [RS_FLAG_HIDE_REPORTER_BATTLE_TOWER]                 = 
    [RS_FLAG_HIDE_RIVAL_ROUTE110]                        = 
    [RS_FLAG_HIDE_RIVAL_CHAMPIONS_ROOM]                  = 
    [RS_FLAG_HIDE_BIRCH_CHAMPIONS_ROOM]                  = 
    [RS_FLAG_HIDE_RIVAL_ON_BIKE_ROUTE110]                = 
    [RS_FLAG_HIDE_RIVAL_ROUTE119_ON_BIKE]                = 
    [RS_FLAG_HIDE_GRUNTS_HIDEOUTS]                       = 
    [RS_FLAG_HIDE_LILYCOVE_MOTEL_PEOPLE]                 = 
    [RS_FLAG_HIDE_EVIL_TEAM_MT_CHIMNEY]                  = 
    [RS_FLAG_HIDE_OTHER_TEAM_MT_CHIMNEY]                 = 
    [RS_FLAG_HIDE_PROF_COSMO_FALLARBOR]                  = 
    [RS_FLAG_HIDE_RIVAL_LAVARIDGE_1]                     = 
    [RS_FLAG_HIDE_RIVAL_LAVARIDGE_2]                     = 
    [RS_FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1]                 = 
    [RS_FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2]                 = 
    [RS_FLAG_HIDE_WINGULL_FORTREE_HOUSE]                 = 
    [RS_FLAG_HIDE_WINGULL_MOSSDEEP_HOUSE]                = 
    [RS_FLAG_HIDE_REGIROCK]                              = 
    [RS_FLAG_HIDE_REGICE]                                = 
    [RS_FLAG_HIDE_REGISTEEL]                             = 
    [RS_FLAG_HIDE_GRUNTS_METEOR_FALLS_1F]                = 
    [RS_FLAG_HIDE_OTHER_TEAM_METEOR_FALLS_1F]            = 
    [RS_FLAG_HIDE_SLUDGE_BOMB_MAN_DEWFORD_HALL]          = 
    [RS_FLAG_HIDE_AWARD_MAN_BATTLE_TOWER]                = 
    [RS_FLAG_HIDE_PROF_COSMO_METEOR_FALLS]               = 
    [RS_FLAG_HIDE_SUBMARINE_SHADOW_HIDEOUT]              = 
    [RS_FLAG_HIDE_EVIL_LEADER_ROUTE128]                  = 
    [RS_FLAG_HIDE_OTHER_LEADER_ROUTE128]                 = 
    [RS_FLAG_HIDE_EVIL_TEAM_GRUNTS_SEAFLOOR_CAVERN]      = 
    [RS_FLAG_HIDE_DEVON_EMPLOYEE_ROUTE116]               = 
    [RS_FLAG_HIDE_TM_SALESMAN_SLATEPORT]                 = 
    [RS_FLAG_HIDE_EMPLOYEE_DEVON_CORP_3F]                = 
    [RS_FLAG_HIDE_BRINEY_AND_PEEKO_SS_TIDAL]             = 
    [RS_FLAG_HIDE_TM_49_GIVER_SS_TIDAL]                  = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SALT_1]                     = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SALT_2]                     = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SALT_3]                     = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SALT_4]                     = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SHELL_1]                    = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SHELL_2]                    = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SHELL_3]                    = 
    [RS_FLAG_HIDE_TOOK_SHOAL_SHELL_4]                    = 
    [RS_FLAG_HIDE_SECRET_POWER_MAN]                      = 
    [RS_FLAG_HIDE_OCEANIC_MUSEUM_VISITORS]               = 
    [RS_FLAG_HIDE_ROOFTOP_LADY_LILYCOVE_MART]            = 
    [RS_FLAG_HIDE_ROOT_FOSSIL ]                          = 
    [RS_FLAG_HIDE_CLAW_FOSSIL ]                          = 
    [RS_FLAG_HIDE_SCARED_GRUNT_OCEANIC_MUSEUM]           = 
    [RS_FLAG_HIDE_STEVEN_ROUTE118]                       = 
    [RS_FLAG_HIDE_STEVEN_STEVENS_HOUSE]                  = 
    [RS_FLAG_HIDE_BELDUM_BALL_STEVENS_HOUSE]             = 
    [RS_FLAG_HIDE_KECLEON_FORTREE]                       = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_1 ]                   = 
    [RS_FLAG_HIDE_RIVAL_LILYCOVE_MART]                   = 
    [RS_FLAG_HIDE_STEVEN_ROUTE120]                       = 
    [RS_FLAG_HIDE_STEVEN_SOOTOPOLIS]                     = 
    [RS_FLAG_HIDE_VOLTORB_1_NEW_MAUVILLE]                = 
    [RS_FLAG_HIDE_VOLTORB_2_NEW_MAUVILLE]                = 
    [RS_FLAG_HIDE_VOLTORB_3_NEW_MAUVILLE]                = 
    [RS_FLAG_HIDE_ELECTRODE_1_HIDEOUT]                   = 
    [RS_FLAG_HIDE_ELECTRODE_2_HIDEOUT]                   = 
    [RS_FLAG_HIDE_RIVAL_OLDALE_TOWN]                     = 
    [RS_FLAG_HIDE_UNDERWATER_SUBMARINE_INTERACTION]      = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_2]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_3]                    = 
    [RS_FLAG_HIDE_GIRLFRIEND_RUSTURF_TUNNEL]             = 
    [RS_FLAG_HIDE_GIRLFRIEND_WANDAS_HOUSE]               = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_4]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_5]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_6]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE120_7]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE119_1]                    = 
    [RS_FLAG_HIDE_KECLEON_ROUTE119_2]                    = 
    [RS_FLAG_HIDE_BOY_ROUTE101]                          = 
    [RS_FLAG_ITEM_ROUTE102_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE116_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE104_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE105_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE106_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE109_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE110_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE110_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE111_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE111_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE111_3 ]                           = 
    [RS_FLAG_ITEM_ROUTE112_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE113_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE113_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE114_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE114_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE115_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE115_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE115_3 ]                           = 
    [RS_FLAG_ITEM_ROUTE116_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE116_3 ]                           = 
    [RS_FLAG_ITEM_ROUTE116_4 ]                           = 
    [RS_FLAG_ITEM_ROUTE117_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE117_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_3 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_4 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_5 ]                           = 
    [RS_FLAG_ITEM_ROUTE119_6 ]                           = 
    [RS_FLAG_ITEM_ROUTE120_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE120_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE123_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE123_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE127_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE127_2 ]                           = 
    [RS_FLAG_ITEM_ROUTE132_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE133_1 ]                           = 
    [RS_FLAG_ITEM_ROUTE133_2 ]                           = 
    [RS_FLAG_ITEM_PETALBURG_1]                           = 
    [RS_FLAG_ITEM_PETALBURG_2]                           = 
    [RS_FLAG_ITEM_RUSTBORO_1]                            = 
    [RS_FLAG_ITEM_LILYCOVE_1]                            = 
    [RS_FLAG_ITEM_MOSSDEEP_1]                            = 
    [RS_FLAG_ITEM_METEOR_FALLS_1F_1R_1]                  = 
    [RS_FLAG_ITEM_METEOR_FALLS_1F_1R_2]                  = 
    [RS_FLAG_ITEM_METEOR_FALLS_1F_1R_3]                  = 
    [RS_FLAG_ITEM_METEOR_FALLS_1F_1R_4]                  = 
    [RS_FLAG_ITEM_RUSTURF_TUNNEL_1]                      = 
    [RS_FLAG_ITEM_RUSTURF_TUNNEL_2]                      = 
    [RS_FLAG_ITEM_GRANITE_CAVE_1F_1]                     = 
    [RS_FLAG_ITEM_GRANITE_CAVE_B1F_1]                    = 
    [RS_FLAG_ITEM_MT_PYRE_5F_1]                          = 
    [RS_FLAG_ITEM_GRANITE_CAVE_B2F_1]                    = 
    [RS_FLAG_ITEM_GRANITE_CAVE_B2F_2]                    = 
    [RS_FLAG_ITEM_PETALBURG_WOODS_1]                     = 
    [RS_FLAG_ITEM_PETALBURG_WOODS_2]                     = 
    [RS_FLAG_ITEM_ROUTE104_2 ]                           = 
    [RS_FLAG_ITEM_PETALBURG_WOODS_3]                     = 
    [RS_FLAG_ITEM_CAVE_OF_ORIGIN_B3F_1]                  = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_1]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_1]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_2]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_1]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_2]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_1]                = 
    [RS_FLAG_ITEM_ROUTE124_1]                            = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_1]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_1]                = 
    [RS_FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_1]                = 
    [RS_FLAG_ITEM_JAGGED_PASS_1]                         = 
    [RS_FLAG_ITEM_AQUA_HIDEOUT_B1F_1]                    = 
    [RS_FLAG_ITEM_AQUA_HIDEOUT_B2F_1]                    = 
    [RS_FLAG_ITEM_MT_PYRE_EXTERIOR_1]                    = 
    [RS_FLAG_ITEM_MT_PYRE_EXTERIOR_2]                    = 
    [RS_FLAG_ITEM_NEW_MAUVILLE_INSIDE_1]                 = 
    [RS_FLAG_ITEM_NEW_MAUVILLE_INSIDE_2]                 = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_1]   = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_2]   = 
    [RS_FLAG_ITEM_SCORCHED_SLAB_1]                       = 
    [RS_FLAG_ITEM_METEOR_FALLS_B1F_2R_1]                 = 
    [RS_FLAG_ITEM_SHOAL_CAVE_LOW_TIDE_ENTRANCE_1]        = 
    [RS_FLAG_ITEM_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_1]      = 
    [RS_FLAG_ITEM_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM_1]     = 
    [RS_FLAG_ITEM_VICTORY_ROAD_1F_1]                     = 
    [RS_FLAG_ITEM_VICTORY_ROAD_1F_2]                     = 
    [RS_FLAG_ITEM_VICTORY_ROAD_B1F_1]                    = 
    [RS_FLAG_ITEM_VICTORY_ROAD_B1F_2]                    = 
    [RS_FLAG_ITEM_VICTORY_ROAD_B2F_1]                    = 
    [RS_FLAG_ITEM_MT_PYRE_6F_1]                          = 
    [RS_FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_1]              = 
    [RS_FLAG_ITEM_FIERY_PATH_1]                          = 
    [RS_FLAG_ITEM_ROUTE124_2]                            = 
    [RS_FLAG_ITEM_ROUTE124_3]                            = 
    [RS_FLAG_ITEM_SAFARI_ZONE_NORTHWEST_1]               = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_1]             = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_1]            = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_1]          = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_ROOM_B1F_1]             = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_1]           = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_1]      = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_3]   = 
    [RS_FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_4]   = 
    [RS_FLAG_ITEM_ROUTE121_1]                            = 
    [RS_FLAG_ITEM_ROUTE123_3]                            = 
    [RS_FLAG_ITEM_ROUTE126_1]                            = 
    [RS_FLAG_ITEM_ROUTE119_7]                            = 
    [RS_FLAG_ITEM_ROUTE120_3]                            = 
    [RS_FLAG_ITEM_ROUTE120_4]                            = 
    [RS_FLAG_ITEM_ROUTE123_4]                            = 
    [RS_FLAG_ITEM_NEW_MAUVILLE_INSIDE_3]                 = 
    [RS_FLAG_ITEM_FIERY_PATH_2]                          = 
    [RS_FLAG_ITEM_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_1]        = 
    [RS_FLAG_ITEM_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_2]        = 
    [RS_FLAG_ITEM_ROUTE103_1]                            = 
    [RS_FLAG_ITEM_ROUTE104_3]                            = 
    [RS_FLAG_ITEM_MAUVILLE_1]                            = 
    [RS_FLAG_ITEM_PETALBURG_WOODS_4]                     = 
    [RS_FLAG_ITEM_ROUTE115_4]                            = 
    [RS_FLAG_ITEM_SAFARI_ZONE_NORTHEAST_1]               = 
    [RS_FLAG_ITEM_MT_PYRE_3F_1]                          = 
    [RS_FLAG_ITEM_ROUTE118_1]                            = 
    [RS_FLAG_ITEM_NEW_MAUVILLE_INSIDE_4]                 = 
    [RS_FLAG_ITEM_NEW_MAUVILLE_INSIDE_5]                 = 
    [RS_FLAG_ITEM_AQUA_HIDEOUT_B1F_2]                    = 
    [RS_FLAG_ITEM_MAGMA_HIDEOUT_B1F_1]                   = 
    [RS_FLAG_ITEM_MAGMA_HIDEOUT_B1F_2]                   = 
    [RS_FLAG_ITEM_MAGMA_HIDEOUT_B2F_1]                   = 
    [RS_FLAG_ITEM_MT_PYRE_2F_1]                          = 
    [RS_FLAG_ITEM_MT_PYRE_4F_1]                          = 
    [RS_FLAG_ITEM_SAFARI_ZONE_SOUTHWEST]                 = 
    [RS_FLAG_ITEM_AQUA_HIDEOUT_B1F_3]                    = 
    [RS_FLAG_ITEM_MOSSDEEP_STEVENS_HOUSE_HM08]           = 
    [RS_FLAG_ITEM_MAGMA_HIDEOUT_B1F_3]                   = 
    [RS_FLAG_ITEM_ROUTE104_4]                            = 
    [RS_FLAG_DEFEATED_RUSTBORO_GYM]                      = FLAG_DEFEATED_RUSTBORO_GYM,
    [RS_FLAG_DEFEATED_DEWFORD_GYM]                       = FLAG_DEFEATED_DEWFORD_GYM,
    [RS_FLAG_DEFEATED_MAUVILLE_GYM]                      = FLAG_DEFEATED_MAUVILLE_GYM,
    [RS_FLAG_DEFEATED_LAVARIDGE_GYM]                     = FLAG_DEFEATED_LAVARIDGE_GYM,
    [RS_FLAG_DEFEATED_PETALBURG_GYM]                     = FLAG_DEFEATED_PETALBURG_GYM,
    [RS_FLAG_DEFEATED_FORTREE_GYM]                       = FLAG_DEFEATED_FORTREE_GYM,
    [RS_FLAG_DEFEATED_MOSSDEEP_GYM]                      = FLAG_DEFEATED_MOSSDEEP_GYM,
    [RS_FLAG_DEFEATED_SOOTOPOLIS_GYM]                    = FLAG_DEFEATED_SOOTOPOLIS_GYM,
    [RS_FLAG_DEFEATED_ELITE_4_SYDNEY]                    = FLAG_DEFEATED_ELITE_4_SIDNEY,
    [RS_FLAG_DEFEATED_ELITE_4_PHOEBE]                    = FLAG_DEFEATED_ELITE_4_PHOEBE,
    [RS_FLAG_DEFEATED_ELITE_4_GLACIA]                    = FLAG_DEFEATED_ELITE_4_GLACIA,
    [RS_FLAG_DEFEATED_ELITE_4_DRAKE]                     = FLAG_DEFEATED_ELITE_4_DRAKE,
    [RS_FLAG_SYS_POKEMON_GET]                            = FLAG_SYS_POKEMON_GET,
    [RS_FLAG_SYS_POKEDEX_GET]                            = FLAG_SYS_POKEDEX_GET,
    [RS_FLAG_SYS_POKENAV_GET]                            = FLAG_SYS_POKENAV_GET,
    [RS_FLAG_SYS_GAME_CLEAR]                             = FLAG_SYS_GAME_CLEAR,
    [RS_FLAG_SYS_CHAT_USED]                              = FLAG_SYS_CHAT_USED,
    [RS_FLAG_SYS_HIPSTER_MEET]                           = FLAG_SYS_HIPSTER_MEET,
    [RS_FLAG_BADGE01_GET]                                = FLAG_BADGE01_GET,
    [RS_FLAG_BADGE02_GET]                                = FLAG_BADGE02_GET,
    [RS_FLAG_BADGE03_GET]                                = FLAG_BADGE03_GET,
    [RS_FLAG_BADGE04_GET]                                = FLAG_BADGE04_GET,
    [RS_FLAG_BADGE05_GET]                                = FLAG_BADGE05_GET,
    [RS_FLAG_BADGE06_GET]                                = FLAG_BADGE06_GET,
    [RS_FLAG_BADGE07_GET]                                = FLAG_BADGE07_GET,
    [RS_FLAG_BADGE08_GET]                                = FLAG_BADGE08_GET,
    [RS_FLAG_VISITED_LITTLEROOT_TOWN]                    = FLAG_VISITED_LITTLEROOT_TOWN,
    [RS_FLAG_VISITED_OLDALE_TOWN]                        = FLAG_VISITED_OLDALE_TOWN,
    [RS_FLAG_VISITED_DEWFORD_TOWN]                       = FLAG_VISITED_DEWFORD_TOWN,
    [RS_FLAG_VISITED_LAVARIDGE_TOWN]                     = FLAG_VISITED_LAVARIDGE_TOWN,
    [RS_FLAG_VISITED_FALLARBOR_TOWN                      = FLAG_VISITED_FALLARBOR_TOWN,
    [RS_FLAG_VISITED_VERDANTURF_TOWN]                    = FLAG_VISITED_VERDANTURF_TOWN,
    [RS_FLAG_VISITED_PACIFIDLOG_TOWN]                    = FLAG_VISITED_PACIFIDLOG_TOWN,
    [RS_FLAG_VISITED_PETALBURG_CITY]                     = FLAG_VISITED_PETALBURG_CITY,
    [RS_FLAG_VISITED_SLATEPORT_CITY]                     = FLAG_VISITED_SLATEPORT_CITY,
    [RS_FLAG_VISITED_MAUVILLE_CITY]                      = FLAG_VISITED_MAUVILLE_CITY,
    [RS_FLAG_VISITED_RUSTBORO_CITY]                      = FLAG_VISITED_RUSTBORO_CITY,
    [RS_FLAG_VISITED_FORTREE_CITY]                       = FLAG_VISITED_FORTREE_CITY,
    [RS_FLAG_VISITED_LILYCOVE_CITY]                      = FLAG_VISITED_LILYCOVE_CITY,
    [RS_FLAG_VISITED_MOSSDEEP_CITY]                      = FLAG_VISITED_MOSSDEEP_CITY,
    [RS_FLAG_VISITED_SOOTOPOLIS_CITY]                    = FLAG_VISITED_SOOTOPOLIS_CITY,
    [RS_FLAG_VISITED_EVER_GRANDE_CITY]                   = FLAG_VISITED_EVER_GRANDE_CITY,
    [RS_FLAG_SYS_USE_FLASH]                              = FLAG_SYS_USE_FLASH,
    [RS_FLAG_SYS_USE_STRENGTH]                           = FLAG_SYS_USE_STRENGTH,
    [RS_FLAG_SYS_WEATHER_CTRL]                           = FLAG_SYS_WEATHER_CTRL,
    [RS_FLAG_SYS_CYCLING_ROAD]                           = FLAG_SYS_CYCLING_ROAD,
    [RS_FLAG_SYS_SAFARI_MODE]                            = FLAG_SYS_SAFARI_MODE,
    [RS_FLAG_SYS_CRUISE_MODE]                            = FLAG_SYS_CRUISE_MODE,
    [RS_FLAG_SYS_TV_HOME]                                = FLAG_SYS_TV_HOME,
    [RS_FLAG_SYS_TV_WATCH]                               = FLAG_SYS_TV_WATCH,
    [RS_FLAG_SYS_TV_START]                               = FLAG_SYS_TV_START,
    [RS_FLAG_SYS_POPWORD_INPUT]                          = FLAG_SYS_CHANGED_DEWFORD_TREND,
    [RS_FLAG_SYS_MIX_RECORD]                             = FLAG_SYS_MIX_RECORD,
    [RS_FLAG_SYS_CLOCK_SET]                              = FLAG_SYS_CLOCK_SET,
    [RS_FLAG_SYS_NATIONAL_DEX]                           = 
    [RS_FLAG_SYS_CAVE_SHIP]                              = FLAG_SYS_CAVE_SHIP,
    [RS_FLAG_SYS_CAVE_WONDER]                            = FLAG_SYS_CAVE_WONDER,
    [RS_FLAG_SYS_CAVE_BATTLE]                            = FLAG_SYS_CAVE_BATTLE,
    [RS_FLAG_SYS_SHOAL_TIDE]                             = FLAG_SYS_SHOAL_TIDE,
    [RS_FLAG_SYS_RIBBON_GET]                             = FLAG_SYS_RIBBON_GET,
    [RS_FLAG_LANDMARK_FLOWER_SHOP]                       = FLAG_LANDMARK_FLOWER_SHOP
    [RS_FLAG_LANDMARK_MR_BRINEY_HOUSE]                   = FLAG_LANDMARK_MR_BRINEY_HOUSE,
    [RS_FLAG_LANDMARK_ABANDONED_SHIP]                    = FLAG_LANDMARK_ABANDONED_SHIP,
    [RS_FLAG_LANDMARK_SEASHORE_HOUSE]                    = FLAG_LANDMARK_SEASHORE_HOUSE,
    [RS_FLAG_LANDMARK_NEW_MAUVILLE]                      = FLAG_LANDMARK_NEW_MAUVILLE,
    [RS_FLAG_LANDMARK_OLD_LADY_REST_SHOP]                = FLAG_LANDMARK_OLD_LADY_REST_SHOP,
    [RS_FLAG_LANDMARK_TRICK_HOUSE]                       = FLAG_LANDMARK_TRICK_HOUSE,
    [RS_FLAG_LANDMARK_WINSTRATE_FAMILY]                  = FLAG_LANDMARK_WINSTRATE_FAMILY,
    [RS_FLAG_LANDMARK_GLASS_WORKSHOP]                    = FLAG_LANDMARK_GLASS_WORKSHOP,
    [RS_FLAG_LANDMARK_LANETTES_HOUSE]                    = FLAG_LANDMARK_LANETTES_HOUSE,
    [RS_FLAG_LANDMARK_POKEMON_DAYCARE]                   = FLAG_LANDMARK_POKEMON_DAYCARE,
    [RS_FLAG_LANDMARK_SEAFLOOR_CAVERN]                   = FLAG_LANDMARK_SEAFLOOR_CAVERN,
    [RS_FLAG_LANDMARK_BATTLE_TOWER]                      = FLAG_LANDMARK_BATTLE_FRONTIER,
    [RS_FLAG_LANDMARK_SOUTHERN_ISLAND]                   = FLAG_LANDMARK_SOUTHERN_ISLAND,
    [RS_FLAG_LANDMARK_FIERY_PATH]                        = FLAG_LANDMARK_FIERY_PATH,
    [RS_FLAG_SYS_PC_LANETTE]                             = FLAG_SYS_PC_LANETTE,
    [RS_FLAG_SYS_EXDATA_ENABLE]                          = FLAG_SYS_MYSTERY_EVENT_ENABLE,
    [RS_FLAG_SYS_ENC_UP_ITEM]                            = FLAG_SYS_ENC_UP_ITEM,
    [RS_FLAG_SYS_ENC_DOWN_ITEM]                          = FLAG_SYS_ENC_DOWN_ITEM,
    [RS_FLAG_SYS_BRAILLE_DIG]                            = FLAG_SYS_BRAILLE_DIG,
    [RS_FLAG_SYS_BRAILLE_STRENGTH]                       = FLAG_SYS_REGIROCK_PUZZLE_COMPLETED,
    [RS_FLAG_SYS_BRAILLE_WAIT]                           = FLAG_SYS_BRAILLE_REGICE_COMPLETED,
    [RS_FLAG_SYS_BRAILLE_FLY]                            = FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED,
    [RS_FLAG_SYS_HAS_EON_TICKET]                         = FLAG_ENABLE_SHIP_SOUTHERN_ISLAND,
    [RS_FLAG_SYS_POKEMON_LEAGUE_FLY]                     = FLAG_LANDMARK_POKEMON_LEAGUE,
    [RS_FLAG_LANDMARK_ISLAND_CAVE]                       = FLAG_LANDMARK_ISLAND_CAVE,
    [RS_FLAG_LANDMARK_DESERT_RUINS]                      = FLAG_LANDMARK_DESERT_RUINS,
    [RS_FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE]              = FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE,
    [RS_FLAG_LANDMARK_SCORCHED_SLAB]                     = FLAG_LANDMARK_SCORCHED_SLAB,
    [RS_FLAG_LANDMARK_ANCIENT_TOMB]                      = FLAG_LANDMARK_ANCIENT_TOMB,
    [RS_FLAG_LANDMARK_TUNNELERS_REST_HOUSE]              = FLAG_LANDMARK_TUNNELERS_REST_HOUSE,
    [RS_FLAG_LANDMARK_HUNTERS_HOUSE]                     = FLAG_LANDMARK_HUNTERS_HOUSE,
    [RS_FLAG_LANDMARK_SEALED_CHAMBER]                    = FLAG_LANDMARK_SEALED_CHAMBER,
    [RS_FLAG_SYS_TV_LATI]                                = FLAG_SYS_TV_LATIAS_LATIOS
    [RS_FLAG_LANDMARK_SKY_PILLAR]                        = FLAG_LANDMARK_SKY_PILLAR
    [RS_FLAG_SYS_SHOAL_ITEM]                             = FLAG_SYS_SHOAL_ITEM
    [RS_FLAG_SYS_B_DASH]                                 = FLAG_SYS_B_DASH
    [RS_FLAG_SYS_CTRL_OBJ_DELETE]                        = FLAG_SYS_CTRL_OBJ_DELETE
    [RS_FLAG_SYS_RESET_RTC_ENABLE]                       = FLAG_SYS_RESET_RTC_ENABLE
    [RS_FLAG_LANDMARK_BERRY_MASTERS_HOUSE]               = FLAG_LANDMARK_BERRY_MASTERS_HOUSE
    [RS_FLAG_DAILY_RECEIVED_BERRY_FALLARBOR]             = FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY
    [RS_FLAG_DAILY_UNKNOWN_8C2]                          = 
    [RS_FLAG_DAILY_PICKED_LOTTO_TICKET]                  = FLAG_DAILY_PICKED_LOTO_TICKET
    [RS_FLAG_DAILY_RECEIVED_BERRY_ROUTE114]              = FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_ROUTE111]              = FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_FROM_BERRYMASTER]      = FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_ROUTE120]              = FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_LILYCOVE]              = FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_FLOWER_SHOP]           = FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
    [RS_FLAG_DAILY_RECEIVED_BERRY_FROM_BERRYMASTER_WIFE] = FLAG_DAILY_BERRY_MASTERS_WIFE
    [RS_FLAG_DAILY_RECEIVED_BERRY_SOOTOPOLIS]            = FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
};
*/

u8 DetectSaveType(void)
{
    u32 i;
    u8 *rawBlock2 = (u8 *)gSaveBlock2Ptr;

    for (i = 0x890; i < 0xF2C; i++)
    {
        if (rawBlock2[i] != 0)
            return 1; // E
    }

    return 2; // RS
}

u8 ConvertSaveFileFromRSToNL(void)
{
    u32 i;
    struct SaveBlock1 *nlSaveBlock1Ptr = AllocZeroed(sizeof(struct SaveBlock1));
    struct SaveBlock2 *nlSaveBlock2Ptr = AllocZeroed(sizeof(struct SaveBlock2));
    struct RubySapphireSaveBlock1 *rsSaveBlock1Ptr = (struct RubySapphireSaveBlock1 *)gSaveBlock1Ptr;
    struct RubySapphireSaveBlock2 *rsSaveBlock2Ptr = (struct RubySapphireSaveBlock2 *)gSaveBlock2Ptr;

    memcpy(nlSaveBlock1Ptr, rsSaveBlock1Ptr, 0x560); // Save block structure is the same all the way until the Bag
    memcpy(nlSaveBlock1Ptr->bagPocket_Items, rsSaveBlock1Ptr->bagPocket_Items, sizeof(rsSaveBlock1Ptr->bagPocket_Items));
    memcpy(nlSaveBlock1Ptr->bagPocket_KeyItems, rsSaveBlock1Ptr->bagPocket_KeyItems, sizeof(rsSaveBlock1Ptr->bagPocket_KeyItems));
    memcpy(nlSaveBlock1Ptr->bagPocket_PokeBalls, rsSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(rsSaveBlock1Ptr->bagPocket_PokeBalls));
    memcpy(nlSaveBlock1Ptr->bagPocket_TMHM, rsSaveBlock1Ptr->bagPocket_TMHM, sizeof(rsSaveBlock1Ptr->bagPocket_TMHM));
    memcpy(nlSaveBlock1Ptr->bagPocket_Berries, rsSaveBlock1Ptr->bagPocket_Berries, sizeof(rsSaveBlock1Ptr->bagPocket_Berries));
    memcpy(nlSaveBlock1Ptr->pokeblocks, rsSaveBlock1Ptr->pokeblocks, 0xA28); // This whole chunk is identical (although offset) until the flags
    // Convert flags and vars
    memcpy(nlSaveBlock1Ptr->gameStats, rsSaveBlock1Ptr->gameStats, sizeof(rsSaveBlock1Ptr->gameStats));

    memcpy(nlSaveBlock1Ptr->berryTrees, rsSaveBlock1Ptr->berryTrees, 0x1994); // This whole chunk is identical (although offset) until the day care

    memcpy(&nlSaveBlock1Ptr->daycare.mons[0].mon, &rsSaveBlock1Ptr->daycare.mons[0], sizeof(rsSaveBlock1Ptr->daycare.mons[0]));
    memcpy(&nlSaveBlock1Ptr->daycare.mons[0].mail, &rsSaveBlock1Ptr->daycare.misc.mail[0], sizeof(rsSaveBlock1Ptr->daycare.misc.mail[0]));

    nlSaveBlock1Ptr->daycare.mons[0].mail.gameLanguage = GAME_LANGUAGE;
    nlSaveBlock1Ptr->daycare.mons[0].mail.monLanguage = GAME_LANGUAGE;

    memcpy(&nlSaveBlock1Ptr->daycare.mons[0].steps, &rsSaveBlock1Ptr->daycare.misc.countersEtc.steps[0], sizeof(rsSaveBlock1Ptr->daycare.misc.countersEtc.steps[0]));
    memcpy(&nlSaveBlock1Ptr->daycare.mons[1].mon, &rsSaveBlock1Ptr->daycare.mons[1], sizeof(rsSaveBlock1Ptr->daycare.mons[1]));
    memcpy(&nlSaveBlock1Ptr->daycare.mons[1].mail, &rsSaveBlock1Ptr->daycare.misc.mail[1], sizeof(rsSaveBlock1Ptr->daycare.misc.mail[1]));

    nlSaveBlock1Ptr->daycare.mons[1].mail.gameLanguage = GAME_LANGUAGE;
    nlSaveBlock1Ptr->daycare.mons[1].mail.monLanguage = GAME_LANGUAGE;

    memcpy(&nlSaveBlock1Ptr->daycare.mons[1].steps, &rsSaveBlock1Ptr->daycare.misc.countersEtc.steps[1], sizeof(rsSaveBlock1Ptr->daycare.misc.countersEtc.steps[1]));
    // Probably gen a new PID here -v
    memcpy(&nlSaveBlock1Ptr->daycare.offspringPersonality, &rsSaveBlock1Ptr->daycare.misc.countersEtc.pendingEggPersonality, sizeof(rsSaveBlock1Ptr->daycare.misc.countersEtc.pendingEggPersonality));
    memcpy(&nlSaveBlock1Ptr->daycare.stepCounter, &rsSaveBlock1Ptr->daycare.misc.countersEtc.eggCycleStepsRemaining, sizeof(rsSaveBlock1Ptr->daycare.misc.countersEtc.eggCycleStepsRemaining));

    memcpy(&nlSaveBlock1Ptr->linkBattleRecords, rsSaveBlock1Ptr->linkBattleRecords, 0xA8); // This whole chunk is (almost) identical (although offset) until the Enigma Berry

    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
        nlSaveBlock1Ptr->linkBattleRecords.languages[i] = GAME_LANGUAGE;

    // Convert Enigma Berry

    memcpy(&nlSaveBlock1Ptr->recordMixingGift, &rsSaveBlock1Ptr->recordMixingGift, 0x44); // Copy Record Mixing Gift and seen2 flags.  Everything else we keep zero as it's new Emerald/Heliodor content.  We don't keep the RAM Script as the script commands don't match between RS and E's languages

    memcpy(gSaveBlock1Ptr, nlSaveBlock1Ptr, sizeof(*nlSaveBlock1Ptr));

    memcpy(nlSaveBlock2Ptr, rsSaveBlock2Ptr, 0xAC); // All of save block 2 is identical until you hit the RS Battle Tower data

    memcpy(gSaveBlock2Ptr, nlSaveBlock2Ptr, sizeof(*nlSaveBlock2Ptr));

    FREE_AND_SET_NULL(nlSaveBlock1Ptr);
    FREE_AND_SET_NULL(nlSaveBlock2Ptr);

    //Do some clean initializations like new game
    
    gSaveBlock2Ptr->frontier.opponentNames[0][0] = 0xFF;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = 0xFF;
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
        gSaveBlock2Ptr->gcnLinkFlags = 0x803F;
    VarSet(VAR_SEEDOT_SIZE_RECORD, 0x8000);
    VarSet(VAR_LOTAD_SIZE_RECORD, 0x8000);
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ResetTrainerHillResults();
	VarSet(VAR_SAVE_VER, 6);
    
}
