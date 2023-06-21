#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H
// Invalid Versions show as "----------" in Gen 4 and Gen 5's summary screen.
// In Gens 6 and 7, invalid versions instead show "a distant land" in the summary screen.
// In Gen 4 only, migrated Pokemon with Diamond, Pearl, or Platinum's ID show as "----------".
// Gen 5 and up read Diamond, Pearl, or Platinum's ID as "Sinnoh".
// In Gen 4 and up, migrated Pokemon with HeartGold or SoulSilver's ID show the otherwise unused "Johto" string.
//0 is unused
#define VERSION_SAPPHIRE            1
#define VERSION_RUBY                2
#define VERSION_EMERALD             3
#define VERSION_FIRERED             4
#define VERSION_LEAFGREEN           5
//6 is unused, possibly intended for WaterBlue or LightningYellow?
#define VERSION_HEARTGOLD           7
#define VERSION_SOULSILVER          8
//9 is unused, possibly intended for MindCrystal?
#define VERSION_DIAMOND             10
#define VERSION_PEARL               11
#define VERSION_PLATINUM            12
//13 and 14 are unused
#define VERSION_GAMECUBE            15 //Both Colosseum and XD use this ID
//The rest of these are just for reference.  Origin game is only stored as 4 bits, so they aren't used for anything in this game
//16-19 are unused
#define VERSION_WHITE               20
#define VERSION_BLACK               21
#define VERSION_WHITE_2             22
#define VERSION_BLACK_2             23
#define VERSION_X                   24
#define VERSION_Y                   25
#define VERSION_ALPHA_SAPPHIRE      26
#define VERSION_OMEGA_RUBY          27
//28 and 29 are unused, possibly intended for XZ and YZ?
#define VERSION_SUN                 30
#define VERSION_MOON                31
#define VERSION_ULTRA_SUN           32
#define VERSION_ULTRA_MOON          33
#define VERSION_GO                  34
#define VERSION_VC_RED              35
#define VERSION_VC_GREEN            36 //International versions of Blue use this ID
#define VERSION_VC_BLUE             37
#define VERSION_VC_YELLOW           38
#define VERSION_VC_GOLD             39
#define VERSION_VC_SILVER           40
#define VERSION_VC_CRYSTAL          41
#define VERSION_LETS_GO_PIKACHU     42
#define VERSION_LETS_GO_EEVEE       43
#define VERSION_SWORD               44
#define VERSION_SHIELD              45
//46 is currently unused, but reserved for HOME
#define VERSION_LEGENDS_ARCEUS      47
#define VERSION_BRILLIANT_DIAMOND   48
#define VERSION_SHINING_PEARL       49
#define VERSION_SCARLET             50
#define VERSION_VIOLET              51

//Version ID modifiers used for identifying unofficial games.
//The idea is that each developer will have an ID number that they can use in conjunction with one of the offical origin game IDs
//so that they do not have to requisition a new ID for every project
#define DEV_GAME_FREAK				0
#define DEV_SOLITAIRI				1	//3-1 is Heliodor.  Pokemon are also flagged with 1-1, 2-1, 4-1, 5-1, and 12-1 for legality purposes
#define DEV_SHINY_DRAGON_HUNTER		2	//4-2 is FireRed DX and 5-2 is LeafGreen DX
#define DEV_SOLITAIRI_2				3	//4-3 is modified CrystalDust
#define DEV_TEST					255

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
#define VERSION_MODIFIER (DEV_SOLITAIRI)

// party sizes
#define PARTY_SIZE 6
#define MULTI_PARTY_SIZE (PARTY_SIZE / 2)
#define FRONTIER_PARTY_SIZE         3
#define FRONTIER_DOUBLES_PARTY_SIZE 4
#define FRONTIER_MULTI_PARTY_SIZE   2
#define MAX_FRONTIER_PARTY_SIZE    (max(FRONTIER_PARTY_SIZE,        \
                                    max(FRONTIER_DOUBLES_PARTY_SIZE,\
                                        FRONTIER_MULTI_PARTY_SIZE)))
#define UNION_ROOM_PARTY_SIZE       2

// capacities of various saveblock objects
#define DAYCARE_MON_COUNT 2
#define POKEBLOCKS_COUNT 40
#define OBJECT_EVENTS_COUNT 16
#define MAIL_COUNT (10 + PARTY_SIZE)
#define SECRET_BASES_COUNT 10
#define POKE_NEWS_COUNT 16
#define PC_ITEMS_COUNT 50
#define BAG_ITEMS_COUNT 80
#define BAG_KEYITEMS_COUNT 70
#define BAG_POKEBALLS_COUNT 45
#define BAG_BATTLEITEMS_COUNT 9
#define BAG_TREASURES_COUNT 19
#define BAG_MAIL_COUNT 12
#define BAG_MEDICINE_COUNT 45
#define BAG_TMHM_COUNT 58
#define BAG_BERRIES_COUNT 43
#define OBJECT_EVENT_TEMPLATES_COUNT 64
#define DECOR_MAX_SECRET_BASE 16
#define DECOR_MAX_PLAYERS_HOUSE 12
#define APPRENTICE_COUNT 4
#define APPRENTICE_MAX_QUESTIONS 9
#define MAX_REMATCH_ENTRIES 100 // only REMATCH_TABLE_ENTRIES (78) are used
#define NUM_CONTEST_WINNERS 13
#define UNION_ROOM_KB_ROW_COUNT 10
#define GIFT_RIBBONS_COUNT 11
#define SAVED_TRENDS_COUNT 5
#define PYRAMID_BAG_ITEMS_COUNT 10

// Number of facilities for Ranking Hall.
// 7 facilities for single mode + tower double mode + tower multi mode.
// Excludes link modes. See RANKING_HALL_* in include/constants/battle_frontier.h
#define HALL_FACILITIES_COUNT 9
// Received via record mixing, 1 for each player other than yourself
#define HALL_RECORDS_COUNT 3

// Battle Frontier level modes.
#define FRONTIER_LVL_50         0
#define FRONTIER_LVL_OPEN       1
#define FRONTIER_LVL_MODE_COUNT 2
#define FRONTIER_LVL_TENT       FRONTIER_LVL_MODE_COUNT // Special usage for indicating Battle Tent

#define TRAINER_ID_LENGTH 4
#define MAX_MON_MOVES 4

#define CONTESTANT_COUNT 4
#define CONTEST_CATEGORY_COOL     0
#define CONTEST_CATEGORY_BEAUTY   1
#define CONTEST_CATEGORY_CUTE     2
#define CONTEST_CATEGORY_SMART    3
#define CONTEST_CATEGORY_TOUGH    4
#define CONTEST_CATEGORIES_COUNT  5

// string lengths
#define ITEM_NAME_LENGTH 16
#define ITEM_CLASSIFIED_NAME_LENGTH 20 // 24
#define POKEMON_NAME_LENGTH 10
#define PLAYER_NAME_LENGTH 7
#define MAIL_WORDS_COUNT 9
#define EASY_CHAT_BATTLE_WORDS_COUNT 6
#define MOVE_NAME_LENGTH 12
#define NUM_QUESTIONNAIRE_WORDS 4
#define QUIZ_QUESTION_LEN 9
#define WONDER_CARD_TEXT_LENGTH 40
#define WONDER_NEWS_TEXT_LENGTH 40
#define WONDER_CARD_BODY_TEXT_LINES 4
#define WONDER_NEWS_BODY_TEXT_LINES 10
#define TYPE_NAME_LENGTH 6
#define ABILITY_NAME_LENGTH 12
#define TRAINER_NAME_LENGTH 10
#define MAP_NAME_LENGTH 16
#define TRAINER_CLASS_NAME_LENGTH 12
#define DECORATION_NAME_LENGTH 15
#define POKEDEX_CATEGORY_NAME_LENGTH 12
#define EASY_CHAT_WORD_LENGTH 12

#define MAX_STAMP_CARD_STAMPS 7

#define MALE 0
#define FEMALE 1
#define GENDER_COUNT 2

#define BARD_SONG_LENGTH       6
#define NUM_STORYTELLER_TALES  4
#define NUM_TRADER_ITEMS       4
#define GIDDY_MAX_TALES       10
#define GIDDY_MAX_QUESTIONS    8

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

#define CONNECTION_INVALID -1
#define CONNECTION_NONE     0
#define CONNECTION_SOUTH    1
#define CONNECTION_NORTH    2
#define CONNECTION_WEST     3
#define CONNECTION_EAST     4
#define CONNECTION_DIVE     5
#define CONNECTION_EMERGE   6

#endif // GUARD_CONSTANTS_GLOBAL_H
