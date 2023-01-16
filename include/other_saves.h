#ifndef GUARD_OTHER_SAVES_H
#define GUARD_OTHER_SAVES_H

struct RubySapphireDayCareMail
{
    /*0x00*/ struct MailStruct message;
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
    struct DayCareMisc misc;
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
#define NUM_FLAG_BYTES_RS       288
#define NUM_GAME_STATS_RS       50

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
    /*0x600*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    /*0x640*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    /*0x740*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
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
    /*0x1540*/ u32 gameStats[NUM_GAME_STATS_RS];
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
    /*0x2ABC*/ struct PokeNews pokeNews[POKE_NEWS_COUNT];
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


#endif // GUARD_OTHER_SAVES_H
