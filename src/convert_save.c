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
#include "convert_save.h"
#include "item.h"
#include "load_save.h"
#include "overworld.h"
#include "constants/heal_locations.h"
#include "berry.h"
#include "roamer.h"
#include "script.h"
#include "mystery_gift.h"

extern const u8 EventScript_ResetAllMapFlags[];
extern bool8 gDifferentSaveFile;

u8 DetectSaveType(void)
{
    u32 i;
    u8 *rawBlock1 = (u8 *)gSaveBlock1Ptr;
    u8 *rawBlock2 = (u8 *)gSaveBlock2Ptr;

    if (rawBlock1[0x31] == 27)
        return SAVE_TYPE_NL;

    if (rawBlock2[0xAC] == 1 && rawBlock2[0xAD] == 0 && rawBlock2[0xAE] == 0 && rawBlock2[0xAF] == 0)
        return SAVE_TYPE_FRLG;

    for (i = 0x890; i < 0xF2C; i++)
    {
        if (rawBlock2[i] != 0)
            return SAVE_TYPE_E;
    }

    return SAVE_TYPE_RS; // Split R/S detection post-game
}

u8 ConvertSaveFileFromRSToNL(void)
{
    u32 i;
    struct SaveBlock1 *nlSaveBlock1Ptr = AllocZeroed(sizeof(struct SaveBlock1));
    struct SaveBlock2 *nlSaveBlock2Ptr = AllocZeroed(sizeof(struct SaveBlock2));
    struct RubySapphireSaveBlock1 *rsSaveBlock1Ptr = (struct RubySapphireSaveBlock1 *)gSaveBlock1Ptr;
    struct RubySapphireSaveBlock2 *rsSaveBlock2Ptr = (struct RubySapphireSaveBlock2 *)gSaveBlock2Ptr;

    memcpy(nlSaveBlock1Ptr, rsSaveBlock1Ptr, 0x560); // Save block structure is the same all the way until the Bag

    nlSaveBlock1Ptr->saveMagic = 27;

    memcpy(nlSaveBlock1Ptr->pokeblocks, rsSaveBlock1Ptr->pokeblocks, 0x140);
    memcpy(nlSaveBlock1Ptr->berryBlenderRecords, rsSaveBlock1Ptr->berryBlenderRecords, 0x6);

    memcpy(nlSaveBlock1Ptr->gameStats, rsSaveBlock1Ptr->gameStats, sizeof(rsSaveBlock1Ptr->gameStats));

    memcpy(nlSaveBlock1Ptr->berryTrees, rsSaveBlock1Ptr->berryTrees, 0xA40);

    TransferItemsToNewPockets(nlSaveBlock1Ptr, SAVE_TYPE_RS);

    memcpy(nlSaveBlock1Ptr->playerRoomDecorations, rsSaveBlock1Ptr->playerRoomDecorations, 0x914);

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

    memcpy(&nlSaveBlock1Ptr->recordMixingGift, &rsSaveBlock1Ptr->recordMixingGift, 0x10); // We don't keep the RAM Script as the script commands don't match between RS and E's languages

    memcpy(gSaveBlock1Ptr, nlSaveBlock1Ptr, sizeof(*nlSaveBlock1Ptr));

    memcpy(nlSaveBlock2Ptr, rsSaveBlock2Ptr, 0xA8); // All of save block 2 is identical until you hit the RS Battle Tower data

    memcpy(gSaveBlock2Ptr, nlSaveBlock2Ptr, sizeof(*nlSaveBlock2Ptr));

    VarSet(VAR_BARBOACH_SIZE_RECORD, rsSaveBlock1Ptr->vars[RS_VAR_BARBOACH_SIZE_RECORD - RS_VARS_START]);
    VarSet(VAR_SHROOMISH_SIZE_RECORD, rsSaveBlock1Ptr->vars[RS_VAR_SHROOMISH_SIZE_RECORD - RS_VARS_START]);
    VarSet(VAR_ASH_GATHER_COUNT, rsSaveBlock1Ptr->vars[RS_VAR_ASH_GATHER_COUNT - RS_VARS_START]);
    VarSet(VAR_DAYS, rsSaveBlock1Ptr->vars[RS_VAR_DAYS - RS_VARS_START]);

    SetEnigmaBerry((u8 *)&rsSaveBlock1Ptr->enigmaBerry);

    gSaveBlock1Ptr->rubySapphireSecretId = gSaveBlock2Ptr->playerTrainerId[2] | (gSaveBlock2Ptr->playerTrainerId[3] << 8);

    FREE_AND_SET_NULL(nlSaveBlock1Ptr);
    FREE_AND_SET_NULL(nlSaveBlock2Ptr);

    LoadFakePockets();

    //Do some clean initializations like new game

    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = 0xFF;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = 0xFF;
    
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    VarSet(VAR_SEEDOT_SIZE_RECORD, 0x8000);
    VarSet(VAR_LOTAD_SIZE_RECORD, 0x8000);
    ClearRoamerData();
    ClearRoamerLocationData();
    SetWarpDestination(MAP_GROUP(INSIDE_OF_TRUCK), MAP_NUM(INSIDE_OF_TRUCK), WARP_ID_NONE, -1, -1);
    WarpIntoMap();
    RunScriptImmediately(EventScript_ResetAllMapFlags);
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    ResetTrainerHillResults();
	VarSet(VAR_SAVE_VER, 6);

    gDifferentSaveFile = TRUE;
}

u8 ConvertSaveFileFromEToNL(void)
{
    u32 i;
    struct SaveBlock1 *nlSaveBlock1Ptr = AllocZeroed(sizeof(struct SaveBlock1));
    struct SaveBlock2 *nlSaveBlock2Ptr = AllocZeroed(sizeof(struct SaveBlock2));
    struct PreNLSaveBlock1 *preNLSaveBlock1Ptr = (struct PreNLSaveBlock1 *)gSaveBlock1Ptr;
    struct PreNLSaveBlock2 *preNLSaveBlock2Ptr = (struct PreNLSaveBlock2 *)gSaveBlock2Ptr;

    memcpy(nlSaveBlock1Ptr, preNLSaveBlock1Ptr, 0x235);
    nlSaveBlock1Ptr->saveMagic = 27;
    memcpy(nlSaveBlock1Ptr->playerParty, preNLSaveBlock1Ptr->playerParty, 0x328);
    nlSaveBlock1Ptr->money = preNLSaveBlock1Ptr->money ^ preNLSaveBlock2Ptr->encryptionKey;
    nlSaveBlock1Ptr->coins = preNLSaveBlock1Ptr->coins ^ preNLSaveBlock2Ptr->encryptionKey;

    TransferItemsToNewPockets(nlSaveBlock1Ptr, SAVE_TYPE_E);

    memcpy(nlSaveBlock1Ptr->pokeblocks, preNLSaveBlock1Ptr->pokeblocks, sizeof(struct Pokeblock) * POKEBLOCKS_COUNT);
    memcpy(nlSaveBlock1Ptr->berryBlenderRecords, preNLSaveBlock1Ptr->berryBlenderRecords, 0x6);
    memcpy(&nlSaveBlock1Ptr->trainerRematchStepCounter, &preNLSaveBlock1Ptr->trainerRematchStepCounter, 0x10D4);

    for (i = 0; i < NUM_USED_GAME_STATS; i++)
        nlSaveBlock1Ptr->gameStats[i] = preNLSaveBlock1Ptr->gameStats[i] ^ preNLSaveBlock2Ptr->encryptionKey;

    memcpy(nlSaveBlock1Ptr->secretBases, preNLSaveBlock1Ptr->secretBases, sizeof(struct SecretBase) * SECRET_BASES_COUNT); // Do we need to select specific ones to preserve?
    memcpy(nlSaveBlock1Ptr->playerRoomDecorations, preNLSaveBlock1Ptr->playerRoomDecorations, 0x166C);

    memcpy(gSaveBlock1Ptr, nlSaveBlock1Ptr, sizeof(struct SaveBlock1));

    memcpy(nlSaveBlock2Ptr, preNLSaveBlock2Ptr, sizeof(struct PreNLSaveBlock2));
    nlSaveBlock2Ptr->berryCrush.berryPowderAmount= preNLSaveBlock2Ptr->berryCrush.berryPowderAmount ^ preNLSaveBlock2Ptr->encryptionKey;

    memcpy(gSaveBlock2Ptr, nlSaveBlock2Ptr, sizeof(struct SaveBlock2));

    FREE_AND_SET_NULL(nlSaveBlock1Ptr);
    FREE_AND_SET_NULL(nlSaveBlock2Ptr);

    LoadFakePockets();
}
