#ifndef GUARD_OTHER_SAVES_H
#define GUARD_OTHER_SAVES_H

#include "global.h"
#include "constants/rs_flags.h"
#include "constants/rs_vars.h"
#include "constants/rs_game_stat.h"
#include "constants/prenl_flags.h"
#include "constants/prenl_vars.h"
#include "constants/prenl_game_stat.h"

struct RubySapphireDayCareMail
{
    /*0x00*/ struct Mail message;
    /*0x24*/ u8 names[19];
};

struct RubySapphireDayCareStepCountersEtc {
    u32 steps[DAYCARE_MON_COUNT];
    u16 pendingEggPersonality;
    u8 eggCycleStepsRemaining;
};

struct RubySapphireDayCareMisc
{
    struct RubySapphireDayCareMail mail[DAYCARE_MON_COUNT];
    struct RubySapphireDayCareStepCountersEtc countersEtc;
};

struct RubySapphireDayCare {
    struct BoxPokemon mons[DAYCARE_MON_COUNT];
    struct RubySapphireDayCareMisc misc;
};

struct RubySapphireEnigmaBerry
{
    /*0x000*/ struct Berry berry;
    /*0x01B*/ u8 pic[(6 * 6) * TILE_SIZE_4BPP];
    /*0x49C*/ u16 palette[16];
    /*0x4BC*/ u8 description1[45];
    /*0x4E9*/ u8 description2[45];
    /*0x516*/ u8 itemEffect[18];
    /*0x528*/ u8 holdEffect;
    /*0x529*/ u8 holdEffectParam;
    /*0x52C*/ u32 checksum;
};

struct RubySapphireBattleTowerRecord
{
    /*0x00*/ u8 lvlMode; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 rsFacilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x10*/ u16 greeting[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x1C*/ struct BattleTowerPokemon party[MAX_FRONTIER_PARTY_SIZE];
    /*0xA0*/ u32 checksum;
};

struct RubySapphireBattleTowerData
{
    struct RubySapphireBattleTowerRecord playerRecord;
    struct RubySapphireBattleTowerRecord records[BATTLE_TOWER_RECORD_COUNT]; // from Record Mixing
    u16 playerSpecies;
    u16 opponentSpecies;
    u8 opponentName[PLAYER_NAME_LENGTH + 1];
    u8 firstMonNickname[POKEMON_NAME_LENGTH];
    struct BattleTowerEReaderTrainer ereaderTrainer;
    u8 lvlmode:1; // 0 = level 50; 1 = level 100
    u8 unk_554:1;
    u8 battleOutcome;
    u8 var_4AE[2];
    u16 curChallengeBattleNum[2]; // 1-based index of battle in the current challenge. (challenges consist of 7 battles)
    u16 curStreakChallengesNum[2]; // 1-based index of the current challenge in the current streak.
    u16 recordWinStreaks[2];
    u8 battleTowerTrainerId; // index for gBattleTowerTrainers table
    u8 selectedPartyMons[MAX_FRONTIER_PARTY_SIZE]; // indices of the 3 selected player party mons.
    u16 prizeItem;
    u8 battledTrainerIds[6];
    u16 totalBattleTowerWins;
    u16 bestBattleTowerWinStreak;
    u16 currentWinStreaks[2];
    u8 lastStreakLevelType; // 0 = level 50, 1 = level 100.  level type of the last streak. Used by tv to report the level mode.
    u8 filler_4D1[0x317];
};

#define BAG_ITEMS_COUNT_RS      20
#define BAG_KEYITEMS_COUNT_RS   20
#define BAG_POKEBALLS_COUNT_RS  16
#define BAG_TMHM_COUNT_RS       64
#define BAG_BERRIES_COUNT_RS    46
#define NUM_FLAG_BYTES_RS       288

struct RubySapphireSaveBlock1
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
    /*0x0C*/ struct WarpData warp1;
    /*0x14*/ struct WarpData dynamicWarp;
    /*0x1C*/ struct WarpData lastHealLocation;
    /*0x24*/ struct WarpData escapeWarp;
    /*0x2C*/ u16 savedMusic;
    /*0x2E*/ u8 weather;
    /*0x2F*/ u8 weatherCycleStage;
    /*0x30*/ u8 flashLevel;
    /*0x32*/ u16 mapLayoutId;
    /*0x34*/ u16 mapView[0x100];
    /*0x234*/ u8 playerPartyCount;
    /*0x238*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x490*/ u32 money;
    /*0x494*/ u16 coins;
    /*0x496*/ u16 registeredItemSelect;
    /*0x498*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x560*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT_RS];
    /*0x5B0*/ struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT_RS];
    /*0x600*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT_RS];
    /*0x640*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT_RS];
    /*0x740*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT_RS];
    /*0x7F8*/ struct Pokeblock pokeblocks[POKEBLOCKS_COUNT];
    /*0x938*/ u8 seen1[NUM_DEX_FLAG_BYTES];
    /*0x96C*/ u16 berryBlenderRecords[3];
    /*0x972*/ u8 filler_972[0x6];
    /*0x978*/ u16 trainerRematchStepCounter;
    /*0x97A*/ u8 trainerRematches[MAX_REMATCH_ENTRIES];
    /*0x9E0*/ struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    /*0xC20*/ struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    /*0x1220*/ u8 flags[NUM_FLAG_BYTES_RS];
    /*0x1340*/ u16 vars[VARS_COUNT];
    /*0x1540*/ u32 gameStats[RS_NUM_GAME_STATS];
    /*0x1608*/ struct BerryTree berryTrees[BERRY_TREES_COUNT];
    /*0x1A08*/ struct SecretBase secretBases[SECRET_BASES_COUNT];
    /*0x2688*/ u8 playerRoomDecorations[DECOR_MAX_PLAYERS_HOUSE];
    /*0x2694*/ u8 playerRoomDecorationPositions[DECOR_MAX_PLAYERS_HOUSE];
    /*0x26A0*/ u8 decorationDesks[10];
    /*0x26AA*/ u8 decorationChairs[10];
    /*0x26B4*/ u8 decorationPlants[10];
    /*0x26BE*/ u8 decorationOrnaments[30];
    /*0x26DC*/ u8 decorationMats[30];
    /*0x26FA*/ u8 decorationPosters[10];
    /*0x2704*/ u8 decorationDolls[40];
    /*0x272C*/ u8 decorationCushions[10];
    /*0x2736*/ u8 padding_2736[2];
    /*0x2738*/ TVShow tvShows[TV_SHOWS_COUNT];
    /*0x2ABC*/ PokeNews pokeNews[POKE_NEWS_COUNT];
    /*0x2AFC*/ u16 outbreakPokemonSpecies;
    /*0x2AFE*/ u8 outbreakLocationMapNum;
    /*0x2AFF*/ u8 outbreakLocationMapGroup;
    /*0x2B00*/ u8 outbreakPokemonLevel;
    /*0x2B01*/ u8 outbreakUnk1;
    /*0x2B02*/ u16 outbreakUnk2;
    /*0x2B04*/ u16 outbreakPokemonMoves[MAX_MON_MOVES];
    /*0x2B0C*/ u8 outbreakUnk4;
    /*0x2B0D*/ u8 outbreakPokemonProbability;
    /*0x2B0E*/ u16 outbreakUnk5;
    /*0x2B10*/ struct GabbyAndTyData gabbyAndTyData;
    /*0x2B1C*/ u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2B28*/ u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2B34*/ u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2B40*/ u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2B4C*/ struct Mail mail[MAIL_COUNT];
    /*0x2D8C*/ u8 unk2D8C[4];  // What is this? Apparently it's supposed to be 64 bytes in size.
    /*0x2D90*/ u8 filler_2D90[0x4];
    /*0x2D94*/ OldMan oldMan;
    /*0x2DD4*/ struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    /*0x2DFC*/ struct ContestWinner contestWinners[NUM_CONTEST_WINNERS];
    /*0x2F9C*/ struct RubySapphireDayCare daycare;
    /*0x30B8*/ struct LinkBattleRecord linkBattleRecords[LINK_B_RECORDS_COUNT];
    /*0x3108*/ u8 filler_3108[8];
    /*0x3110*/ u8 giftRibbons[GIFT_RIBBONS_COUNT];
    /*0x311B*/ struct ExternalEventData externalEventData;
    /*0x312F*/ struct ExternalEventFlags externalEventFlags;
    /*0x3144*/ struct Roamer roamer;
    /*0x3160*/ struct RubySapphireEnigmaBerry enigmaBerry;
    /*0x3690*/ struct RamScript ramScript;
    /*0x3A7C*/ struct RecordMixingGift recordMixingGift;
    /*0x3A8C*/ u8 seen2[NUM_DEX_FLAG_BYTES];
};

struct RubySapphireSaveBlock2
{
    /*0x00*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarp;
    /*0x0A*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;         // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3;       // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1;           // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1;     // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1;  // whether battle animations are disabled
             u16 regionMapZoom:1;          // whether the map is zoomed in
    /*0x18*/ struct Pokedex pokedex;
    /*0x90*/ u8 filler_90[0x8];
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ struct RubySapphireBattleTowerData battleTower;
};

#define BAG_ITEMS_COUNT_PRENL       30
#define BAG_KEYITEMS_COUNT_PRENL    30
#define BAG_POKEBALLS_COUNT_PRENL   16
#define BAG_TMHM_COUNT_PRENL        64
#define BAG_BERRIES_COUNT_PRENL     46
#define NUM_FLAG_BYTES_PRENL        ROUND_BITS_TO_BYTES(PRENL_FLAGS_COUNT)
#define SECRET_BASES_COUNT_PRENL    20

struct PreNLSaveBlock1
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
    /*0x0C*/ struct WarpData continueGameWarp;
    /*0x14*/ struct WarpData dynamicWarp;
    /*0x1C*/ struct WarpData lastHealLocation; // used by white-out and teleport
    /*0x24*/ struct WarpData escapeWarp; // used by Dig and Escape Rope
    /*0x2C*/ u16 savedMusic;
    /*0x2E*/ u8 weather;
    /*0x2F*/ u8 weatherCycleStage;
    /*0x30*/ u8 flashLevel;
    /*0x31*/ u8 unused_31;
    /*0x32*/ u16 mapLayoutId;
    /*0x34*/ u16 mapView[0x100];
    /*0x234*/ u8 playerPartyCount;
    /*0x235*/ u8 unused_235[3];
    /*0x238*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x490*/ u32 money;
    /*0x494*/ u16 coins;
    /*0x496*/ u16 registeredItemSelect;
    /*0x498*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x560*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT_PRENL];
    /*0x5D8*/ struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT_PRENL];
    /*0x650*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT_PRENL];
    /*0x690*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT_PRENL];
    /*0x790*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT_PRENL];
    /*0x848*/ struct Pokeblock pokeblocks[POKEBLOCKS_COUNT];
    /*0x988*/ u8 seen1[NUM_DEX_FLAG_BYTES];
    /*0x9BC*/ u16 berryBlenderRecords[3];
    /*0x9C2*/ u8 unused_9C2[6];
    /*0x9C8*/ u16 trainerRematchStepCounter;
    /*0x9CA*/ u8 trainerRematches[MAX_REMATCH_ENTRIES];
    /*0xA2E*/ u8 unused_A2E[2];
    /*0xA30*/ struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    /*0xC70*/ struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    /*0x1270*/ u8 flags[NUM_FLAG_BYTES_PRENL];
    /*0x139C*/ u16 vars[PRENL_VARS_COUNT];
    /*0x159C*/ u32 gameStats[PRENL_NUM_GAME_STATS];
    /*0x169C*/ struct BerryTree berryTrees[BERRY_TREES_COUNT];
    /*0x1A9C*/ struct SecretBase secretBases[SECRET_BASES_COUNT_PRENL];
    /*0x271C*/ u8 playerRoomDecorations[DECOR_MAX_PLAYERS_HOUSE];
    /*0x2728*/ u8 playerRoomDecorationPositions[DECOR_MAX_PLAYERS_HOUSE];
    /*0x2734*/ u8 decorationDesks[10];
    /*0x273E*/ u8 decorationChairs[10];
    /*0x2748*/ u8 decorationPlants[10];
    /*0x2752*/ u8 decorationOrnaments[30];
    /*0x2770*/ u8 decorationMats[30];
    /*0x278E*/ u8 decorationPosters[10];
    /*0x2798*/ u8 decorationDolls[40];
    /*0x27C0*/ u8 decorationCushions[10];
    /*0x27CA*/ u8 unused_27CA[2];
    /*0x27CC*/ TVShow tvShows[TV_SHOWS_COUNT];
    /*0x2B50*/ PokeNews pokeNews[POKE_NEWS_COUNT];
    /*0x2B90*/ u16 outbreakPokemonSpecies;
    /*0x2B92*/ u8 outbreakLocationMapNum;
    /*0x2B93*/ u8 outbreakLocationMapGroup;
    /*0x2B94*/ u8 outbreakPokemonLevel;
    /*0x2B95*/ u8 outbreakEncounterType;
    /*0x2B96*/ u16 outbreakUnused2;
    /*0x2B98*/ u16 outbreakPokemonMoves[MAX_MON_MOVES];
    /*0x2BA0*/ u8 outbreakUnused3;
    /*0x2BA1*/ u8 outbreakPokemonProbability;
    /*0x2BA2*/ u16 outbreakDaysLeft;
    /*0x2BA4*/ struct GabbyAndTyData gabbyAndTyData;
    /*0x2BB0*/ u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BBC*/ u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BC8*/ u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BD4*/ u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BE0*/ struct Mail mail[MAIL_COUNT];
    /*0x2E20*/ u8 unlockedTrendySayings[NUM_TRENDY_SAYING_BYTES]; // bitfield for 33 additional phrases in easy chat system
    /*0x2E25*/ u8 unused_2E25[3];
    /*0x2E28*/ OldMan oldMan;
    /*0x2e64*/ struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    /*0x2e90*/ struct ContestWinner contestWinners[NUM_CONTEST_WINNERS]; // see CONTEST_WINNER_*
    /*0x3030*/ struct DayCare daycare;
    /*0x3150*/ struct LinkBattleRecords linkBattleRecords;
    /*0x31A8*/ u8 giftRibbons[GIFT_RIBBONS_COUNT];
    /*0x31B3*/ struct ExternalEventData externalEventData;
    /*0x31C7*/ struct ExternalEventFlags externalEventFlags;
    /*0x31DC*/ struct Roamer roamer;
    /*0x31F8*/ struct EnigmaBerry enigmaBerry;
    /*0x322C*/ struct MysteryGiftSave mysteryGift;
	/*0x3598*/ struct Incubator incubator;
	/*0x3604*/ struct EnigmaBerryDesc enigmaBerryDesc;
    /*0x3660*/ u16 registeredItemL;
    /*0x3662*/ u16 registeredItemR;
	/*0x3664*/ u8 trainerCardLayout;
	/*0x3665*/ u8 trainerCardStickers[6];
	/*0x366B*/ u8 trainerClass;
	/*0x366C*/ u32 trainerCardStat0:4;
	           u32 trainerCardStat1:4;
	           u32 trainerCardStat2:4;
	           u32 trainerCardStat3:4;
	           u32 trainerCardStat4:4;
	           u32 filler:12;
    /*0x3670*/ u16 rubySapphireSecretId;
    /*0x3672*/ u8 mainUnused[0xA6];
    /*0x3718*/ u32 trainerHillTimes[NUM_TRAINER_HILL_MODES];
    /*0x3728*/ struct RamScript ramScript;
    /*0x3B14*/ struct RecordMixingGift recordMixingGift;
    /*0x3B24*/ u8 seen2[NUM_DEX_FLAG_BYTES];
    /*0x3B58*/ LilycoveLady lilycoveLady;
    /*0x3B98*/ struct TrainerNameRecord trainerNameRecords[20];
    /*0x3C88*/ u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    /*0x3D5A*/ u8 unused_3D5A[10];
    /*0x3D64*/ struct TrainerHillSave trainerHill;
    /*0x3D70*/ struct WaldaPhrase waldaPhrase;
    // sizeof: 0x3D88
};

struct PreNLSaveBlock2
{
    /*0x00*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarpFlags;
    /*0x0A*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1; // whether battle animations are disabled
             u16 regionMapZoom:1; // whether the map is zoomed in
			 u16 options24HourClock:1;
			 u16 optionsUnitSystem:1;
			 u16 optionsMessageColor:2;
    /*0x16*/ u16 optionsFont:3;
             u16 optionsPartyBox:1;
             u16 optionsNickname:1;
             u16 optionsRumble:1;
             u16 optionsUnused:10;
    /*0x18*/ struct Pokedex pokedex;
	/*0x90*/ u16 lastUsedBall;
	/*0x92*/ u16 powerPoints;
	/*0x94*/ u32 totalEarnedPowerPoints;
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ u32 gcnLinkFlags; // Read by Pokemon Colosseum/XD
    /*0xAC*/ u32 encryptionKey;
    /*0xB0*/ struct PlayersApprentice playerApprentice;
    /*0xDC*/ struct Apprentice apprentices[APPRENTICE_COUNT];
    /*0x1EC*/ struct BerryCrush berryCrush;
    /*0x1FC*/ struct PokemonJumpRecords pokeJump;
    /*0x20C*/ struct BerryPickingResults berryPick;
    /*0x21C*/ struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
    /*0x57C*/ struct RankingHall2P hallRecords2P[FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
}; // sizeof=0xF2C

#endif // GUARD_OTHER_SAVES_H
