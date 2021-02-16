#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H
// Invalid Versions show as "----------" in Gen 4 and Gen 5's summary screen.
// In Gens 6 and 7, invalid versions instead show "a distant land" in the summary screen.
// In Gen 4 only, migrated Pokemon with Diamond, Pearl, or Platinum's ID show as "----------".
// Gen 5 and up read Diamond, Pearl, or Platinum's ID as "Sinnoh".
// In Gen 4 and up, migrated Pokemon with HeartGold or SoulSilver's ID show the otherwise unused "Johto" string.
//0 is unused
#define VERSION_SAPPHIRE         1
#define VERSION_RUBY             2
#define VERSION_EMERALD          3
#define VERSION_FIRERED          4
#define VERSION_LEAFGREEN        5
//6 is unused, possibly intended for WaterBlue or LightningYellow?
#define VERSION_HEARTGOLD        7
#define VERSION_SOULSILVER       8
//9 is unused, possibly intended for MindCrystal?
#define VERSION_DIAMOND         10
#define VERSION_PEARL           11
#define VERSION_PLATINUM        12
//13 and 14 are unused
#define VERSION_GAMECUBE        15 //Both Colosseum and XD use this ID
//The rest of these are just for reference.  Origin game is only stored as 4 bits, so they aren't be used for anything in this game
//16-19 are unused
#define VERSION_WHITE           20
#define VERSION_BLACK           21
#define VERSION_WHITE_2         22
#define VERSION_BLACK_2         23
#define VERSION_X               24
#define VERSION_Y               25
#define VERSION_ALPHA_SAPPHIRE  26
#define VERSION_OMEGA_RUBY      27
//28 and 29 are unused, possibly intended for XZ and YZ?
#define VERSION_SUN             30
#define VERSION_MOON            31
#define VERSION_ULTRA_SUN       32
#define VERSION_ULTRA_MOON      33
#define VERSION_GO              34
#define VERSION_VC_RED          35
#define VERSION_VC_GREEN        36 //International versions of Blue use this ID
#define VERSION_VC_BLUE         37
#define VERSION_VC_YELLOW       38
#define VERSION_VC_GOLD         39
#define VERSION_VC_SILVER       40
#define VERSION_VC_CRYSTAL      41
#define VERSION_LETS_GO_PIKACHU 42
#define VERSION_LETS_GO_EEVEE   43
#define VERSION_SWORD           44
#define VERSION_SHIELD          45

#define LANGUAGE_JAPANESE 1
#define LANGUAGE_ENGLISH  2
#define LANGUAGE_FRENCH   3
#define LANGUAGE_ITALIAN  4
#define LANGUAGE_GERMAN   5
#define LANGUAGE_KOREAN   6 // 6 goes unused but the theory is it was meant to be Korean
#define LANGUAGE_SPANISH  7
#define NUM_LANGUAGES     7

#define GAME_VERSION (VERSION_EMERALD)
#define GAME_LANGUAGE (LANGUAGE_ENGLISH)

// capacities of various saveblock objects
#define DAYCARE_MON_COUNT 2
#define POKEBLOCKS_COUNT 40
#define OBJECT_EVENTS_COUNT 16
#define MAIL_COUNT 16
#define SECRET_BASES_COUNT 20
#define TV_SHOWS_COUNT 25
#define POKE_NEWS_COUNT 16
#define PC_ITEMS_COUNT 50
#define BAG_ITEMS_COUNT 30
#define BAG_KEYITEMS_COUNT 30
#define BAG_POKEBALLS_COUNT 16
#define BAG_TMHM_COUNT 64
#define BAG_BERRIES_COUNT 46
#define OBJECT_EVENT_TEMPLATES_COUNT 64
#define DECOR_MAX_SECRET_BASE 16
#define DECOR_MAX_PLAYERS_HOUSE 12
#define APPRENTICE_COUNT 4
#define APPRENTICE_MAX_QUESTIONS 9
#define MAX_REMATCH_ENTRIES 100 // only REMATCH_TABLE_ENTRIES (78) are used
#define NUM_CONTEST_WINNERS 13
#define UNION_ROOM_KB_ROW_COUNT 10

#define PYRAMID_BAG_ITEMS_COUNT 10
#define HALL_FACILITIES_COUNT 9 // 7 facilities for single mode + tower double mode + tower multi mode.

#define TRAINER_ID_LENGTH 4
#define MAX_MON_MOVES 4
#define NUM_STATS 6

#define CONTESTANT_COUNT 4
#define CONTEST_CATEGORY_COOL     0
#define CONTEST_CATEGORY_BEAUTY   1
#define CONTEST_CATEGORY_CUTE     2
#define CONTEST_CATEGORY_SMART    3
#define CONTEST_CATEGORY_TOUGH    4
#define CONTEST_CATEGORIES_COUNT  5

// party sizes
#define PARTY_SIZE 6
#define MULTI_PARTY_SIZE (PARTY_SIZE / 2)
#define FRONTIER_PARTY_SIZE         3
#define FRONTIER_DOUBLES_PARTY_SIZE 4
#define FRONTIER_MULTI_PARTY_SIZE   2
#define MAX_FRONTIER_PARTY_SIZE     FRONTIER_DOUBLES_PARTY_SIZE
#define UNION_ROOM_PARTY_SIZE       2

// string lengths
#define ITEM_NAME_LENGTH 14
#define POKEMON_NAME_LENGTH 10
#define PLAYER_NAME_LENGTH 7
#define MAIL_WORDS_COUNT 9
#define EASY_CHAT_BATTLE_WORDS_COUNT 6
#define MOVE_NAME_LENGTH 12

#define MALE 0
#define FEMALE 1
#define GENDER_COUNT 2

#define BARD_SONG_LENGTH       6
#define NUM_STORYTELLER_TALES  4
#define NUM_TRADER_ITEMS       4

#define OPTIONS_BUTTON_MODE_NORMAL 0
#define OPTIONS_BUTTON_MODE_LR 1
#define OPTIONS_BUTTON_MODE_L_EQUALS_A 2

#define OPTIONS_TEXT_SPEED_SLOW 0
#define OPTIONS_TEXT_SPEED_MID 1
#define OPTIONS_TEXT_SPEED_FAST 2

#define OPTIONS_SOUND_MONO 0
#define OPTIONS_SOUND_STEREO 1

#define OPTIONS_BATTLE_STYLE_SHIFT 0
#define OPTIONS_BATTLE_STYLE_SET 1

#define DIR_NONE        0
#define DIR_SOUTH       1
#define DIR_NORTH       2
#define DIR_WEST        3
#define DIR_EAST        4
#define DIR_SOUTHWEST   5
#define DIR_SOUTHEAST   6
#define DIR_NORTHWEST   7
#define DIR_NORTHEAST   8

#endif // GUARD_CONSTANTS_GLOBAL_H
