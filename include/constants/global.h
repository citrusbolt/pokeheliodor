#ifndef GUARD_CONSTANTS_GLOBAL_H
#define GUARD_CONSTANTS_GLOBAL_H

#define VERSION_0                   0  // a distant land
#define VERSION_SAPPHIRE            1  // the Hoenn region
#define VERSION_RUBY                2  // the Hoenn region
#define VERSION_EMERALD             3  // the Hoenn region
#define VERSION_FIRERED             4  // the Kanto region
#define VERSION_LEAFGREEN           5  // the Kanto region
#define VERSION_6                   6  // a distant land
#define VERSION_HEARTGOLD           7  // the Johto region
#define VERSION_SOULSILVER          8  // the Johto region
#define VERSION_9                   9  // a distant land
#define VERSION_DIAMOND             10 // the Sinnoh region
#define VERSION_PEARL               11 // the Sinnoh region
#define VERSION_PLATINUM            12 // the Sinnoh region
#define VERSION_13                  13 // a distant land
#define VERSION_14                  14 // a distant land
#define VERSION_COLOXD              15 // a distant land

// The rest of these are just for reference.  Origin game is only stored as 4 bits, so they aren't used for anything in this game
#define VERSION_16                  16 // a distant land
#define VERSION_17                  17 // a distant land
#define VERSION_18                  18 // a distant land
#define VERSION_19                  19 // a distant land
#define VERSION_WHITE               20 // the Unova region
#define VERSION_BLACK               21 // the Unova region
#define VERSION_WHITE_2             22 // the Unova region
#define VERSION_BLACK_2             23 // the Unova region
#define VERSION_X                   24 // the Kalos region
#define VERSION_Y                   25 // the Kalos region
#define VERSION_ALPHA_SAPPHIRE      26 // the Hoenn region
#define VERSION_OMEGA_RUBY          27 // the Hoenn region
#define VERSION_28                  28 // the Kalos region
#define VERSION_29                  29 // the Kalos region
#define VERSION_SUN                 30 // the Alola region
#define VERSION_MOON                31 // the Alola region
#define VERSION_ULTRA_SUN           32 // the Alola region
#define VERSION_ULTRA_MOON          33 // the Alola region
#define VERSION_GO                  34 // Pokémon GO
#define VERSION_VC_RED              35 // the Kanto region. How nostalgic!
#define VERSION_VC_GREEN            36 // the Kanto region. How nostalgic!      // International versions of Blue use this ID
#define VERSION_VC_BLUE             37 // the Kanto region. How nostalgic!      // Japanese only
#define VERSION_VC_YELLOW           38 // the Kanto region. How nostalgic!
#define VERSION_VC_GOLD             39 // the Johto region. How nostalgic!
#define VERSION_VC_SILVER           40 // the Johto region. How nostalgic!
#define VERSION_VC_CRYSTAL          41 // the Johto region. How nostalgic!
#define VERSION_LETS_GO_PIKACHU     42 // the Kanto region
#define VERSION_LETS_GO_EEVEE       43 // the Kanto region
#define VERSION_SWORD               44 // the Galar region
#define VERSION_SHIELD              45 // the Galar region
#define VERSION_HOME                46 // Pokémon HOME
#define VERSION_LEGENDS_ARCEUS      47 // the Hisui region
#define VERSION_BRILLIANT_DIAMOND   48 // the Sinnoh region
#define VERSION_SHINING_PEARL       49 // the Sinnoh region
#define VERSION_SCARLET             50 // the Paldea region
#define VERSION_VIOLET              51 // the Paldea region

// Version ID modifiers used for identifying unofficial games.
// The idea is that each developer will have an ID number that they can use in conjunction with one of the offical origin game IDs
// so that they do not have to requisition a new ID for every project
#define DEV_GAME_FREAK              0
#define DEV_CITRUS_BOLT             1	// 3-1 is Heliodor.  Pokemon are also flagged with 1-1, 2-1, 4-1, 5-1, 12-1, and 15-1 for legality purposes
#define DEV_SHINY_DRAGON_HUNTER     2	// 4-2 is FireRed DX and 5-2 is LeafGreen DX
#define DEV_ASPARAGUS_EDUARDO       3	// Reserved.
#define DEV_JAIZU                   4   // 3-4 is Emerald Cross, 4-4 is Recharged Yellow
#define DEV_BOX_RS                  5   // Force this tag upon Box Eggs to track them once they are hatched

#define LINK_VERSION_RUBY               0
#define LINK_VERSION_SAPPHIRE           1
#define LINK_VERSION_COLOXD             2
#define LINK_VERSION_FIRERED            3
#define LINK_VERSION_LEAFGREEN          4
#define LINK_VERSION_EMERALD            5
#define LINK_VERSION_DIAMOND            6
#define LINK_VERSION_PEARL              7
#define LINK_VERSION_PLATINUM           8
#define LINK_VERSION_HEARTGOLD          9
#define LINK_VERSION_SOULSILVER         10
#define LINK_VERSION_HELIODOR           11
#define LINK_VERSION_EMERALD_CROSS      12
#define LINK_VERSION_RECHARGED_YELLOW   13

#define LANGUAGE_UNKNOWN    0
#define LANGUAGE_JAPANESE   1
#define LANGUAGE_ENGLISH    2
#define LANGUAGE_FRENCH     3
#define LANGUAGE_ITALIAN    4
#define LANGUAGE_GERMAN     5
#define LANGUAGE_UNUSED     6
#define LANGUAGE_SPANISH    7

#define NUM_LANGUAGES       7

// Post-Gen 3 languages
#define LANGUAGE_KOREAN                 8
#define LANGUAGE_CHINESE_SIMPLIFIED     9
#define LANGUAGE_CHINESE_TRADITIONAL    10

#define GAME_VERSION        (VERSION_EMERALD)
#define GAME_LANGUAGE       (LANGUAGE_ENGLISH)
#define VERSION_MODIFIER    (DEV_CITRUS_BOLT)

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
#define ALL_MOVES_MASK ((1 << MAX_MON_MOVES) - 1)

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
#define POKEMON_NAME_BUFFER_SIZE max(20, POKEMON_NAME_LENGTH + 1) // Frequently used buffer size. Larger than necessary
#define PLAYER_NAME_LENGTH 7
#define MAIL_WORDS_COUNT 9
#define EASY_CHAT_BATTLE_WORDS_COUNT 6
#define MOVE_NAME_LENGTH 14
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
