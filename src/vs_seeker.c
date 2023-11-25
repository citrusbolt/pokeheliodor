#include "global.h"
#include "task.h"
#include "event_object_movement.h"
#include "item_use.h"
#include "event_scripts.h"
#include "event_data.h"
#include "script.h"
#include "event_object_lock.h"
#include "field_specials.h"
#include "item.h"
#include "item_menu.h"
#include "field_effect.h"
#include "script_movement.h"
#include "battle.h"
#include "battle_setup.h"
#include "random.h"
#include "field_player_avatar.h"
#include "vs_seeker.h"
#include "menu.h"
#include "string_util.h"
#include "tv.h"
#include "malloc.h"
#include "field_screen_effect.h"
#include "sound.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/trainer_types.h"
#include "constants/field_effects.h"

enum
{
   VSSEEKER_NOT_CHARGED,
   VSSEEKER_NO_ONE_IN_RANGE,
   VSSEEKER_CAN_USE,
};

typedef enum
{
    VSSEEKER_SINGLE_RESP_RAND,
    VSSEEKER_SINGLE_RESP_NO,
    VSSEEKER_SINGLE_RESP_YES
} VsSeekerSingleRespCode;

typedef enum
{
    VSSEEKER_RESPONSE_NO_RESPONSE,
    VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS,
    VSSEEKER_RESPONSE_FOUND_REMATCHES
} VsSeekerResponseCode;

// static types
typedef struct VsSeekerData
{
    u16 trainerIdxs[6];
    u16 mapGroup; // unused
    u16 mapNum; // unused
} VsSeekerData;

struct VsSeekerTrainerInfo
{
    const u8 *script;
    u16 trainerIdx;
    u8 localId;
    u8 objectEventId;
    s16 xCoord;
    s16 yCoord;
    u8 graphicsId;
};

struct VsSeekerStruct
{
    /*0x000*/ struct VsSeekerTrainerInfo trainerInfo[OBJECT_EVENTS_COUNT];
    /*0x100*/ u8 filler_100[0x300];
    /*0x400*/ u16 trainerIdxArray[OBJECT_EVENTS_COUNT];
    /*0x420*/ u8 runningBehaviourEtcArray[OBJECT_EVENTS_COUNT];
    /*0x430*/ u8 numRematchableTrainers;
    /*0x431*/ u8 trainerHasNotYetBeenFought:1;
    /*0x431*/ u8 trainerDoesNotWantRematch:1;
    /*0x431*/ u8 trainerWantsRematch:1;
    u8 responseCode:5;
};

// static declarations
static EWRAM_DATA struct VsSeekerStruct *sVsSeeker = NULL;

static void VsSeekerResetInBagStepCounter(void);
static void VsSeekerResetChargingStepCounter(void);
static void Task_ResetObjectsRematchWantedState(u8 taskId);
static void ResetMovementOfRematchableTrainers(void);
static void Task_VsSeeker_1(u8 taskId);
static void Task_VsSeeker_2(u8 taskId);
static void GatherNearbyTrainerInfo(void);
static void Task_VsSeeker_3(u8 taskId);
static bool8 CanUseVsSeeker(void);
static u8 GetVsSeekerResponseInArea(const VsSeekerData * vsSeekerData);
static u8 GetRematchTrainerIdGivenGameState(const u16 *trainerIdxs, u8 rematchIdx);
static u8 ShouldTryRematchBattleInternal(const VsSeekerData * vsSeekerData, u16 trainerBattleOpponent);
static u8 HasRematchTrainerAlreadyBeenFought(const VsSeekerData * vsSeekerData, u16 trainerBattleOpponent);
static int LookupVsSeekerOpponentInArray(const VsSeekerData * array, u16 trainerId);
static bool8 IsTrainerReadyForRematchInternal(const VsSeekerData * array, u16 trainerIdx);
static u8 GetRunningBehaviorFromGraphicsId(u8 graphicsId);
static u16 GetTrainerFlagFromScript(const u8 * script);
static int GetRematchIdx(const VsSeekerData * vsSeekerData, u16 trainerFlagIdx);
static bool32 IsThisTrainerRematchable(u32 localId);
static void ClearAllTrainerRematchStates(void);
static bool8 IsTrainerVisibleOnScreen(struct VsSeekerTrainerInfo * trainerInfo);
static u8 GetNextAvailableRematchTrainer(const VsSeekerData * vsSeekerData, u16 trainerFlagNo, u8 * idxPtr);
static u8 GetRematchableTrainerLocalId(void);
static void StartTrainerObjectMovementScript(struct VsSeekerTrainerInfo * trainerInfo, const u8 * script);
static u8 GetCurVsSeekerResponse(s32 vsSeekerIdx, u16 trainerIdx);
static void StartAllRespondantIdleMovements(void);
static bool8 ObjectEventIdIsSane(u8 objectEventId);
static u8 GetRandomFaceDirectionMovementType();

// rodata
static const VsSeekerData sVsSeekerData[] = {
   {{TRAINER_ROSE_1, TRAINER_ROSE_2, TRAINER_ROSE_3, TRAINER_ROSE_4, TRAINER_ROSE_5}, MAP_GROUP(ROUTE118), MAP_NUM(ROUTE118)},
   {{TRAINER_ANDRES_1, TRAINER_ANDRES_2, TRAINER_ANDRES_3, TRAINER_ANDRES_4, TRAINER_ANDRES_5}, MAP_GROUP(ROUTE105), MAP_NUM(ROUTE105)},
   {{TRAINER_DUSTY_1, TRAINER_DUSTY_2, TRAINER_DUSTY_3, TRAINER_DUSTY_4, TRAINER_ROSE_5}, MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111)},
   {{TRAINER_LOLA_1, TRAINER_LOLA_2, TRAINER_LOLA_3, TRAINER_LOLA_4, TRAINER_LOLA_5}, MAP_GROUP(ROUTE109), MAP_NUM(ROUTE109)},
   {{TRAINER_RICKY_1, TRAINER_RICKY_2, TRAINER_RICKY_3, TRAINER_RICKY_4, TRAINER_RICKY_5}, MAP_GROUP(ROUTE109), MAP_NUM(ROUTE109)},
   {{TRAINER_LILA_AND_ROY_1, TRAINER_LILA_AND_ROY_2, TRAINER_LILA_AND_ROY_3, TRAINER_LILA_AND_ROY_4, TRAINER_LILA_AND_ROY_5}, MAP_GROUP(ROUTE124), MAP_NUM(ROUTE124)},
   {{TRAINER_CRISTIN_1, TRAINER_CRISTIN_2, TRAINER_CRISTIN_3, TRAINER_CRISTIN_4, TRAINER_CRISTIN_5}, MAP_GROUP(ROUTE121), MAP_NUM(ROUTE121)},
   {{TRAINER_BROOKE_1, TRAINER_BROOKE_2, TRAINER_BROOKE_3, TRAINER_BROOKE_4, TRAINER_BROOKE_5}, MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111)},
   {{TRAINER_WILTON_1, TRAINER_WILTON_2, TRAINER_WILTON_3, TRAINER_WILTON_4, TRAINER_WILTON_5}, MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111)},
   {{TRAINER_VALERIE_1, TRAINER_VALERIE_2, TRAINER_VALERIE_3, TRAINER_VALERIE_4, TRAINER_VALERIE_5}, MAP_GROUP(MT_PYRE_6F), MAP_NUM(MT_PYRE_6F)},
   {{TRAINER_CINDY_1, TRAINER_CINDY_3, TRAINER_CINDY_4, TRAINER_CINDY_5, TRAINER_CINDY_6}, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104)},
   {{TRAINER_THALIA_1, TRAINER_THALIA_2, TRAINER_THALIA_3, TRAINER_THALIA_4, TRAINER_THALIA_5}, MAP_GROUP(ABANDONED_SHIP_ROOMS_1F), MAP_NUM(ABANDONED_SHIP_ROOMS_1F)},
   {{TRAINER_JESSICA_1, TRAINER_JESSICA_2, TRAINER_JESSICA_3, TRAINER_JESSICA_4, TRAINER_JESSICA_5}, MAP_GROUP(ROUTE121), MAP_NUM(ROUTE121)},
   {{TRAINER_WINSTON_1, TRAINER_WINSTON_2, TRAINER_WINSTON_3, TRAINER_WINSTON_4, TRAINER_WINSTON_5}, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104)},
   {{TRAINER_STEVE_1, TRAINER_STEVE_2, TRAINER_STEVE_3, TRAINER_STEVE_4, TRAINER_STEVE_5}, MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114)},
   {{TRAINER_TONY_1, TRAINER_TONY_2, TRAINER_TONY_3, TRAINER_TONY_4, TRAINER_TONY_5}, MAP_GROUP(ROUTE107), MAP_NUM(ROUTE107)},
   {{TRAINER_NOB_1, TRAINER_NOB_2, TRAINER_NOB_3, TRAINER_NOB_4, TRAINER_NOB_5}, MAP_GROUP(ROUTE115), MAP_NUM(ROUTE115)},
   {{TRAINER_KOJI_1, TRAINER_KOJI_2, TRAINER_KOJI_3, TRAINER_KOJI_4, TRAINER_KOJI_5}, MAP_GROUP(ROUTE127), MAP_NUM(ROUTE127)},
   {{TRAINER_FERNANDO_1, TRAINER_FERNANDO_2, TRAINER_FERNANDO_3, TRAINER_FERNANDO_4, TRAINER_FERNANDO_5}, MAP_GROUP(ROUTE123), MAP_NUM(ROUTE123)},
   {{TRAINER_DALTON_1, TRAINER_DALTON_2, TRAINER_DALTON_3, TRAINER_DALTON_4, TRAINER_DALTON_5}, MAP_GROUP(ROUTE118), MAP_NUM(ROUTE118)},
   {{TRAINER_BERNIE_1, TRAINER_BERNIE_2, TRAINER_BERNIE_3, TRAINER_BERNIE_4, TRAINER_BERNIE_5}, MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114)},
   {{TRAINER_ETHAN_1, TRAINER_ETHAN_2, TRAINER_ETHAN_3, TRAINER_ETHAN_4, TRAINER_ETHAN_5}, MAP_GROUP(JAGGED_PASS), MAP_NUM(JAGGED_PASS)},
   {{TRAINER_JOHN_AND_JAY_1, TRAINER_JOHN_AND_JAY_2, TRAINER_JOHN_AND_JAY_3, TRAINER_JOHN_AND_JAY_4, TRAINER_JOHN_AND_JAY_5}, MAP_GROUP(METEOR_FALLS_1F_2R), MAP_NUM(METEOR_FALLS_1F_2R)},
   {{TRAINER_JEFFREY_1, TRAINER_JEFFREY_2, TRAINER_JEFFREY_3, TRAINER_JEFFREY_4, TRAINER_JEFFREY_5}, MAP_GROUP(ROUTE120), MAP_NUM(ROUTE120)},
   {{TRAINER_CAMERON_1, TRAINER_CAMERON_2, TRAINER_CAMERON_3, TRAINER_CAMERON_4, TRAINER_CAMERON_5}, MAP_GROUP(ROUTE123), MAP_NUM(ROUTE123)},
   {{TRAINER_JACKI_1, TRAINER_JACKI_2, TRAINER_JACKI_3, TRAINER_JACKI_4, TRAINER_JACKI_5}, MAP_GROUP(ROUTE123), MAP_NUM(ROUTE123)},
   {{TRAINER_WALTER_1, TRAINER_WALTER_2, TRAINER_WALTER_3, TRAINER_WALTER_4, TRAINER_WALTER_5}, MAP_GROUP(ROUTE121), MAP_NUM(ROUTE121)},
   {{TRAINER_KAREN_1, TRAINER_KAREN_2, TRAINER_KAREN_3, TRAINER_KAREN_4, TRAINER_KAREN_5}, MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116)},
   {{TRAINER_JERRY_1, TRAINER_JERRY_2, TRAINER_JERRY_3, TRAINER_JERRY_4, TRAINER_JERRY_5}, MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116)},
   {{TRAINER_ANNA_AND_MEG_1, TRAINER_ANNA_AND_MEG_2, TRAINER_ANNA_AND_MEG_3, TRAINER_ANNA_AND_MEG_4, TRAINER_ANNA_AND_MEG_5}, MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117)},
   {{TRAINER_ISABEL_1, TRAINER_ISABEL_2, TRAINER_ISABEL_3, TRAINER_ISABEL_4, TRAINER_ISABEL_5}, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110)},
   {{TRAINER_MIGUEL_1, TRAINER_MIGUEL_2, TRAINER_MIGUEL_3, TRAINER_MIGUEL_4, TRAINER_MIGUEL_5}, MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103)},
   {{TRAINER_TIMOTHY_1, TRAINER_TIMOTHY_2, TRAINER_TIMOTHY_3, TRAINER_TIMOTHY_4, TRAINER_TIMOTHY_5}, MAP_GROUP(ROUTE115), MAP_NUM(ROUTE115)},
   {{TRAINER_SHELBY_1, TRAINER_SHELBY_2, TRAINER_SHELBY_3, TRAINER_SHELBY_4, TRAINER_SHELBY_5}, MAP_GROUP(MT_CHIMNEY), MAP_NUM(MT_CHIMNEY)},
   {{TRAINER_CALVIN_1, TRAINER_CALVIN_2, TRAINER_CALVIN_3, TRAINER_CALVIN_4, TRAINER_CALVIN_5}, MAP_GROUP(ROUTE102), MAP_NUM(ROUTE102)},
   {{TRAINER_ELLIOT_1, TRAINER_ELLIOT_2, TRAINER_ELLIOT_3, TRAINER_ELLIOT_4, TRAINER_ELLIOT_5}, MAP_GROUP(ROUTE106), MAP_NUM(ROUTE106)},
   {{TRAINER_ISAIAH_1, TRAINER_ISAIAH_2, TRAINER_ISAIAH_3, TRAINER_ISAIAH_4, TRAINER_ISAIAH_5}, MAP_GROUP(ROUTE128), MAP_NUM(ROUTE128)},
   {{TRAINER_MARIA_1, TRAINER_MARIA_2, TRAINER_MARIA_3, TRAINER_MARIA_4, TRAINER_MARIA_5}, MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117)},
   {{TRAINER_ABIGAIL_1, TRAINER_ABIGAIL_2, TRAINER_ABIGAIL_3, TRAINER_ABIGAIL_4, TRAINER_ABIGAIL_5}, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110)},
   {{TRAINER_DYLAN_1, TRAINER_DYLAN_2, TRAINER_DYLAN_3, TRAINER_DYLAN_4, TRAINER_DYLAN_5}, MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117)},
   {{TRAINER_KATELYN_1, TRAINER_KATELYN_2, TRAINER_KATELYN_3, TRAINER_KATELYN_4, TRAINER_KATELYN_5}, MAP_GROUP(ROUTE128), MAP_NUM(ROUTE128)},
   {{TRAINER_BENJAMIN_1, TRAINER_BENJAMIN_2, TRAINER_BENJAMIN_3, TRAINER_BENJAMIN_4, TRAINER_BENJAMIN_5}, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110)},
   {{TRAINER_PABLO_1, TRAINER_PABLO_2, TRAINER_PABLO_3, TRAINER_PABLO_4, TRAINER_PABLO_5}, MAP_GROUP(ROUTE126), MAP_NUM(ROUTE126)},
   {{TRAINER_NICOLAS_1, TRAINER_NICOLAS_2, TRAINER_NICOLAS_3, TRAINER_NICOLAS_4, TRAINER_NICOLAS_5}, MAP_GROUP(METEOR_FALLS_1F_2R), MAP_NUM(METEOR_FALLS_1F_2R)},
   {{TRAINER_ROBERT_1, TRAINER_ROBERT_2, TRAINER_ROBERT_3, TRAINER_ROBERT_4, TRAINER_ROBERT_5}, MAP_GROUP(ROUTE120), MAP_NUM(ROUTE120)},
   {{TRAINER_LAO_1, TRAINER_LAO_2, TRAINER_LAO_3, TRAINER_LAO_4, TRAINER_LAO_5}, MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113)},
   {{TRAINER_CYNDY_1, TRAINER_CYNDY_2, TRAINER_CYNDY_3, TRAINER_CYNDY_4, TRAINER_CYNDY_5}, MAP_GROUP(ROUTE115), MAP_NUM(ROUTE115)},
   {{TRAINER_MADELINE_1, TRAINER_MADELINE_2, TRAINER_MADELINE_3, TRAINER_MADELINE_4, TRAINER_MADELINE_5}, MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113)},
   {{TRAINER_JENNY_1, TRAINER_JENNY_2, TRAINER_JENNY_3, TRAINER_JENNY_4, TRAINER_JENNY_5}, MAP_GROUP(ROUTE124), MAP_NUM(ROUTE124)},
   {{TRAINER_DIANA_1, TRAINER_DIANA_2, TRAINER_DIANA_3, TRAINER_DIANA_4, TRAINER_DIANA_5}, MAP_GROUP(JAGGED_PASS), MAP_NUM(JAGGED_PASS)},
   {{TRAINER_AMY_AND_LIV_1, TRAINER_AMY_AND_LIV_2, TRAINER_AMY_AND_LIV_4, TRAINER_AMY_AND_LIV_5, TRAINER_AMY_AND_LIV_6}, MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103)},
   {{TRAINER_ERNEST_1, TRAINER_ERNEST_2, TRAINER_ERNEST_3, TRAINER_ERNEST_4, TRAINER_ERNEST_5}, MAP_GROUP(ROUTE125), MAP_NUM(ROUTE125)},
   {{TRAINER_CORY_1, TRAINER_CORY_2, TRAINER_CORY_3, TRAINER_CORY_4, TRAINER_CORY_5}, MAP_GROUP(ROUTE108), MAP_NUM(ROUTE108)},
   {{TRAINER_EDWIN_1, TRAINER_EDWIN_2, TRAINER_EDWIN_3, TRAINER_EDWIN_4, TRAINER_EDWIN_5}, MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110)},
   {{TRAINER_LYDIA_1, TRAINER_LYDIA_2, TRAINER_LYDIA_3, TRAINER_LYDIA_4, TRAINER_LYDIA_5}, MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117)},
   {{TRAINER_ISAAC_1, TRAINER_ISAAC_2, TRAINER_ISAAC_3, TRAINER_ISAAC_4, TRAINER_ISAAC_5}, MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117)},
   {{TRAINER_GABRIELLE_1, TRAINER_GABRIELLE_2, TRAINER_GABRIELLE_3, TRAINER_GABRIELLE_4, TRAINER_GABRIELLE_5}, MAP_GROUP(MT_PYRE_3F), MAP_NUM(MT_PYRE_3F)},
   {{TRAINER_CATHERINE_1, TRAINER_CATHERINE_2, TRAINER_CATHERINE_3, TRAINER_CATHERINE_4, TRAINER_CATHERINE_5}, MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119)},
   {{TRAINER_JACKSON_1, TRAINER_JACKSON_2, TRAINER_JACKSON_3, TRAINER_JACKSON_4, TRAINER_JACKSON_5}, MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119)},
   {{TRAINER_HALEY_1, TRAINER_HALEY_2, TRAINER_HALEY_3, TRAINER_HALEY_4, TRAINER_HALEY_5}, MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104)},
   {{TRAINER_JAMES_1, TRAINER_JAMES_2, TRAINER_JAMES_3, TRAINER_JAMES_4, TRAINER_JAMES_5}, MAP_GROUP(PETALBURG_WOODS), MAP_NUM(PETALBURG_WOODS)},
   {{TRAINER_TRENT_1, TRAINER_TRENT_2, TRAINER_TRENT_3, TRAINER_TRENT_4, TRAINER_TRENT_5}, MAP_GROUP(ROUTE112), MAP_NUM(ROUTE112)},
   {{TRAINER_SAWYER_1, TRAINER_SAWYER_2, TRAINER_SAWYER_3, TRAINER_SAWYER_4, TRAINER_SAWYER_5}, MAP_GROUP(MT_CHIMNEY), MAP_NUM(MT_CHIMNEY)},
   {{TRAINER_KIRA_AND_DAN_1, TRAINER_KIRA_AND_DAN_2, TRAINER_KIRA_AND_DAN_3, TRAINER_KIRA_AND_DAN_4, TRAINER_KIRA_AND_DAN_5}, MAP_GROUP(ABANDONED_SHIP_ROOMS2_1F), MAP_NUM(ABANDONED_SHIP_ROOMS2_1F)},
   {{TRAINER_WALLY_VR_2, TRAINER_WALLY_VR_3, TRAINER_WALLY_VR_4, TRAINER_WALLY_VR_5, TRAINER_WALLY_VR_5}, MAP_GROUP(VICTORY_ROAD_1F), MAP_NUM(VICTORY_ROAD_1F)},
   /* Jaizu: Missing this special ones:
    [REMATCH_ROXANNE] = REMATCH(TRAINER_ROXANNE_1, TRAINER_ROXANNE_2, TRAINER_ROXANNE_3, TRAINER_ROXANNE_4, TRAINER_ROXANNE_5, RUSTBORO_CITY),
    [REMATCH_BRAWLY] = REMATCH(TRAINER_BRAWLY_1, TRAINER_BRAWLY_2, TRAINER_BRAWLY_3, TRAINER_BRAWLY_4, TRAINER_BRAWLY_5, DEWFORD_TOWN),
    [REMATCH_WATTSON] = REMATCH(TRAINER_WATTSON_1, TRAINER_WATTSON_2, TRAINER_WATTSON_3, TRAINER_WATTSON_4, TRAINER_WATTSON_5, MAUVILLE_CITY),
    [REMATCH_FLANNERY] = REMATCH(TRAINER_FLANNERY_1, TRAINER_FLANNERY_2, TRAINER_FLANNERY_3, TRAINER_FLANNERY_4, TRAINER_FLANNERY_5, LAVARIDGE_TOWN),
    [REMATCH_NORMAN] = REMATCH(TRAINER_NORMAN_1, TRAINER_NORMAN_2, TRAINER_NORMAN_3, TRAINER_NORMAN_4, TRAINER_NORMAN_5, PETALBURG_CITY),
    [REMATCH_WINONA] = REMATCH(TRAINER_WINONA_1, TRAINER_WINONA_2, TRAINER_WINONA_3, TRAINER_WINONA_4, TRAINER_WINONA_5, FORTREE_CITY),
    [REMATCH_TATE_AND_LIZA] = REMATCH(TRAINER_TATE_AND_LIZA_1, TRAINER_TATE_AND_LIZA_2, TRAINER_TATE_AND_LIZA_3, TRAINER_TATE_AND_LIZA_4, TRAINER_TATE_AND_LIZA_5, MOSSDEEP_CITY),
    [REMATCH_JUAN] = REMATCH(TRAINER_JUAN_1, TRAINER_JUAN_2, TRAINER_JUAN_3, TRAINER_JUAN_4, TRAINER_JUAN_5, SOOTOPOLIS_CITY),
    [REMATCH_SIDNEY] = REMATCH(TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, TRAINER_SIDNEY, EVER_GRANDE_CITY),
    [REMATCH_PHOEBE] = REMATCH(TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, TRAINER_PHOEBE, EVER_GRANDE_CITY),
    [REMATCH_GLACIA] = REMATCH(TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, TRAINER_GLACIA, EVER_GRANDE_CITY),
    [REMATCH_DRAKE] = REMATCH(TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, TRAINER_DRAKE, EVER_GRANDE_CITY),
    [REMATCH_WALLACE] = REMATCH(TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, TRAINER_WALLACE, EVER_GRANDE_CITY),
   */
};

static const u8 sMovementScript_Wait48[] = {
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_DELAY_16,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerUnfought[] = {
    MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerNoRematch[] = {
    MOVEMENT_ACTION_EMOTE_X,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sMovementScript_TrainerRematch[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN,
    MOVEMENT_ACTION_EMOTE_DOUBLE_EXCL_MARK,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sFaceDirectionMovementTypeByFacingDirection[] = {
    MOVEMENT_TYPE_FACE_DOWN,
    MOVEMENT_TYPE_FACE_DOWN,
    MOVEMENT_TYPE_FACE_UP,
    MOVEMENT_TYPE_FACE_LEFT,
    MOVEMENT_TYPE_FACE_RIGHT
};

// text

void VsSeekerFreezeObjectsAfterChargeComplete(void)
{
    CreateTask(Task_ResetObjectsRematchWantedState, 80);
}

static void Task_ResetObjectsRematchWantedState(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 i;

    if (task->data[0] == 0 && IsPlayerStandingStill() == TRUE)
    {
        PlayerFreeze();
        task->data[0] = 1;
    }

    if (task->data[1] == 0)
    {
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            if (ObjectEventIdIsSane(i) == TRUE)
            {
                if (gObjectEvents[i].singleMovementActive)
                    return;
                FreezeObjectEvent(&gObjectEvents[i]);
            }
        }
    }

    task->data[1] = 1;
    if (task->data[0] != 0)
    {
        DestroyTask(taskId);
        StopPlayerAvatar();
        ScriptContext_Enable();
    }
}

void VsSeekerResetObjectMovementAfterChargeComplete(void)
{
    struct ObjectEventTemplate * templates = gSaveBlock1Ptr->objectEventTemplates;
    u8 i;
    u8 movementType;
    u8 objEventId;
    struct ObjectEvent * objectEvent;

    for (i = 0; i < gMapHeader.events->objectEventCount; i++)
    {
        if ((templates[i].trainerType == TRAINER_TYPE_NORMAL
          || templates[i].trainerType == TRAINER_TYPE_BURIED)
         && (templates[i].movementType == MOVEMENT_TYPE_RAISE_HAND_AND_STOP
          || templates[i].movementType == MOVEMENT_TYPE_RAISE_HAND_AND_JUMP
          || templates[i].movementType == MOVEMENT_TYPE_RAISE_HAND_AND_SWIM))
        {
            movementType = GetRandomFaceDirectionMovementType();
            TryGetObjectEventIdByLocalIdAndMap(templates[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId);
            objectEvent = &gObjectEvents[objEventId];
            if (ObjectEventIdIsSane(objEventId) == TRUE)
            {
                SetTrainerMovementType(objectEvent, movementType);
            }
            templates[i].movementType = movementType;
        }
    }
}

bool8 UpdateVsSeekerStepCounter(void)
{
    u8 x = 0;

    if (CheckBagHasItem(ITEM_VS_SEEKER, 1) == TRUE)
    {
        if ((gSaveBlock1Ptr->trainerRematchStepCounter & 0xFF) < 100)
            gSaveBlock1Ptr->trainerRematchStepCounter++;
    }

    if (FlagGet(FLAG_SYS_VS_SEEKER_CHARGING) == TRUE)
    {
        if (((gSaveBlock1Ptr->trainerRematchStepCounter >> 8) & 0xFF) < 100)
        {
            x = (((gSaveBlock1Ptr->trainerRematchStepCounter >> 8) & 0xFF) + 1);
            gSaveBlock1Ptr->trainerRematchStepCounter = (gSaveBlock1Ptr->trainerRematchStepCounter & 0xFF) | (x << 8);
        }
        if (((gSaveBlock1Ptr->trainerRematchStepCounter >> 8) & 0xFF) == 100)
        {
            FlagClear(FLAG_SYS_VS_SEEKER_CHARGING);
            VsSeekerResetChargingStepCounter();
            ClearAllTrainerRematchStates();
            return TRUE;
        }
    }

    return FALSE;
}

void MapResetTrainerRematches(u16 mapGroup, u16 mapNum)
{
    FlagClear(FLAG_SYS_VS_SEEKER_CHARGING);
    VsSeekerResetChargingStepCounter();
    ClearAllTrainerRematchStates();
    ResetMovementOfRematchableTrainers();
}

static void ResetMovementOfRematchableTrainers(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent * objectEvent = &gObjectEvents[i];
        if (objectEvent->movementType == MOVEMENT_TYPE_RAISE_HAND_AND_STOP
                || objectEvent->movementType == MOVEMENT_TYPE_RAISE_HAND_AND_JUMP
                || objectEvent->movementType == MOVEMENT_TYPE_RAISE_HAND_AND_SWIM)
        {
            u8 movementType = GetRandomFaceDirectionMovementType();
            if (objectEvent->active && gSprites[objectEvent->spriteId].data[0] == i)
            {
                gSprites[objectEvent->spriteId].x2 = 0;
                gSprites[objectEvent->spriteId].y2 = 0;
                SetTrainerMovementType(objectEvent, movementType);
            }
        }
    }
}

static void VsSeekerResetInBagStepCounter(void)
{
    gSaveBlock1Ptr->trainerRematchStepCounter &= 0xFF00;
}

static void VsSeekerSetStepCounterInBagFull(void)
{
    gSaveBlock1Ptr->trainerRematchStepCounter &= 0xFF00;
    gSaveBlock1Ptr->trainerRematchStepCounter |= 100;
}

static void VsSeekerResetChargingStepCounter(void)
{
    gSaveBlock1Ptr->trainerRematchStepCounter &= 0x00FF;
}

static void VsSeekerSetStepCounterFullyCharged(void)
{
    gSaveBlock1Ptr->trainerRematchStepCounter &= 0x00FF;
    gSaveBlock1Ptr->trainerRematchStepCounter |= (100 << 8);
}

void Task_VsSeeker_0(u8 taskId)
{
    u8 i;
    u8 respval;

    for (i = 0; i < 16; i++)
        gTasks[taskId].data[i] = 0;

    sVsSeeker = AllocZeroed(sizeof(struct VsSeekerStruct));
    GatherNearbyTrainerInfo();
    respval = CanUseVsSeeker();
    if (respval == VSSEEKER_NOT_CHARGED)
    {
        Free(sVsSeeker);
        DisplayItemMessageOnField(taskId, VSSeeker_Text_BatteryNotChargedNeedXSteps, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
    }
    else if (respval == VSSEEKER_NO_ONE_IN_RANGE)
    {
        Free(sVsSeeker);
        DisplayItemMessageOnField(taskId, VSSeeker_Text_NoTrainersWithinRange, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
    }
    else if (respval == VSSEEKER_CAN_USE)
    {
        FieldEffectStart(FLDEFF_USE_VS_SEEKER);
        gTasks[taskId].func = Task_VsSeeker_1;
        gTasks[taskId].data[0] = 15;
    }
}

static void Task_VsSeeker_1(u8 taskId)
{
    if (--gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].func = Task_VsSeeker_2;
        gTasks[taskId].data[1] = 16;
    }
}

static void Task_VsSeeker_2(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (data[2] != 2 && --data[1] == 0)
    {
        PlaySE(SE_CONTEST_MONS_TURN);
        data[1] = 11;
        data[2]++;
    }

    if (!FieldEffectActiveListContains(FLDEFF_USE_VS_SEEKER))
    {
        data[1] = 0;
        data[2] = 0;
        VsSeekerResetInBagStepCounter();
        sVsSeeker->responseCode = GetVsSeekerResponseInArea(sVsSeekerData);
        ScriptMovement_StartObjectMovementScript(0xFF, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, sMovementScript_Wait48);
        gTasks[taskId].func = Task_VsSeeker_3;
    }
}

static void GatherNearbyTrainerInfo(void)
{
    struct ObjectEventTemplate *templates = gSaveBlock1Ptr->objectEventTemplates;
    u8 objectEventId = 0;
    u8 vsSeekerObjectIdx = 0;
    s32 objectEventIdx;

    for (objectEventIdx = 0; objectEventIdx < gMapHeader.events->objectEventCount; objectEventIdx++)
    {
        if (templates[objectEventIdx].trainerType == TRAINER_TYPE_NORMAL || templates[objectEventIdx].trainerType == TRAINER_TYPE_BURIED)
        {
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].script = templates[objectEventIdx].script;
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].trainerIdx = GetTrainerFlagFromScript(templates[objectEventIdx].script);
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].localId = templates[objectEventIdx].localId;
            TryGetObjectEventIdByLocalIdAndMap(templates[objectEventIdx].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].objectEventId = objectEventId;
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].xCoord = gObjectEvents[objectEventId].currentCoords.x - 7;
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].yCoord = gObjectEvents[objectEventId].currentCoords.y - 7;
            sVsSeeker->trainerInfo[vsSeekerObjectIdx].graphicsId = templates[objectEventIdx].graphicsId;
            vsSeekerObjectIdx++;
        }
    }
    sVsSeeker->trainerInfo[vsSeekerObjectIdx].localId = 0xFF;
}

static void Task_VsSeeker_3(u8 taskId)
{
    if (ScriptMovement_IsObjectMovementFinished(0xFF, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup))
    {
        if (sVsSeeker->responseCode == VSSEEKER_RESPONSE_NO_RESPONSE)
        {
            DisplayItemMessageOnField(taskId, VSSeeker_Text_TrainersNotReady, Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker);
        }
        else
        {
            if (sVsSeeker->responseCode == VSSEEKER_RESPONSE_FOUND_REMATCHES)
                StartAllRespondantIdleMovements();
            ClearDialogWindowAndFrame(0, TRUE);
            ScriptUnfreezeObjectEvents();
            UnlockPlayerFieldControls();
            DestroyTask(taskId);
        }
        Free(sVsSeeker);
    }
}

static u8 CanUseVsSeeker(void)
{
    u8 vsSeekerChargeSteps = gSaveBlock1Ptr->trainerRematchStepCounter;
    if (vsSeekerChargeSteps == 100)
    {
        if (GetRematchableTrainerLocalId() == 0xFF)
            return VSSEEKER_NO_ONE_IN_RANGE;
        else
            return VSSEEKER_CAN_USE;
    }
    else
    {
        ConvertIntToDecimalString(0, 100 - vsSeekerChargeSteps);
        return VSSEEKER_NOT_CHARGED;
    }
}

static u8 GetVsSeekerResponseInArea(const VsSeekerData * vsSeekerData)
{
    u16 trainerIdx = 0;
    u16 rval = 0;
    u8 rematchTrainerIdx;
    u8 unusedIdx = 0;
    u8 response = 0;
    s32 vsSeekerIdx = 0;

    while (sVsSeeker->trainerInfo[vsSeekerIdx].localId != 0xFF)
    {
        if (IsTrainerVisibleOnScreen(&sVsSeeker->trainerInfo[vsSeekerIdx]) == TRUE)
        {
            trainerIdx = sVsSeeker->trainerInfo[vsSeekerIdx].trainerIdx;
            if (!HasTrainerBeenFought(trainerIdx))
            {
                StartTrainerObjectMovementScript(&sVsSeeker->trainerInfo[vsSeekerIdx], sMovementScript_TrainerUnfought);
                sVsSeeker->trainerHasNotYetBeenFought = 1;
                vsSeekerIdx++;
                continue;
            }
            rematchTrainerIdx = GetNextAvailableRematchTrainer(vsSeekerData, trainerIdx, &unusedIdx);
            if (rematchTrainerIdx == 0)
            {
                StartTrainerObjectMovementScript(&sVsSeeker->trainerInfo[vsSeekerIdx], sMovementScript_TrainerNoRematch);
                sVsSeeker->trainerDoesNotWantRematch = 1;
            }
            else
            {
                rval = Random() % 100; // Even if it's overwritten below, it progresses the RNG.
                response = GetCurVsSeekerResponse(vsSeekerIdx, trainerIdx);
                if (response == VSSEEKER_SINGLE_RESP_YES)
                    rval = 100; // Definitely yes
                else if (response == VSSEEKER_SINGLE_RESP_NO)
                    rval = 0; // Definitely no
                // Otherwise it's a 70% chance to want a rematch
                if (rval < 30)
                {
                    StartTrainerObjectMovementScript(&sVsSeeker->trainerInfo[vsSeekerIdx], sMovementScript_TrainerNoRematch);
                    sVsSeeker->trainerDoesNotWantRematch = 1;
                }
                else
                {
                    gSaveBlock1Ptr->trainerRematches[sVsSeeker->trainerInfo[vsSeekerIdx].localId] = rematchTrainerIdx;
                    ShiftStillObjectEventCoords(&gObjectEvents[sVsSeeker->trainerInfo[vsSeekerIdx].objectEventId]);
                    StartTrainerObjectMovementScript(&sVsSeeker->trainerInfo[vsSeekerIdx], sMovementScript_TrainerRematch);
                    sVsSeeker->trainerIdxArray[sVsSeeker->numRematchableTrainers] = trainerIdx;
                    sVsSeeker->runningBehaviourEtcArray[sVsSeeker->numRematchableTrainers] = GetRunningBehaviorFromGraphicsId(sVsSeeker->trainerInfo[vsSeekerIdx].graphicsId);
                    sVsSeeker->numRematchableTrainers++;
                    sVsSeeker->trainerWantsRematch = 1;
                }
            }
        }
        vsSeekerIdx++;
    }

    if (sVsSeeker->trainerWantsRematch)
    {
        PlaySE(SE_PIN);
        FlagSet(FLAG_SYS_VS_SEEKER_CHARGING);
        VsSeekerResetChargingStepCounter();
        return VSSEEKER_RESPONSE_FOUND_REMATCHES;
    }
    if (sVsSeeker->trainerHasNotYetBeenFought)
        return VSSEEKER_RESPONSE_UNFOUGHT_TRAINERS;
    return VSSEEKER_RESPONSE_NO_RESPONSE;
}

void ClearRematchStateByTrainerId(void)
{
    u8 objEventId = 0;
    struct ObjectEventTemplate *objectEventTemplates = gSaveBlock1Ptr->objectEventTemplates;
    int vsSeekerDataIdx = LookupVsSeekerOpponentInArray(sVsSeekerData, gTrainerBattleOpponent_A);

    if (vsSeekerDataIdx != -1)
    {
        int i;

        for (i = 0; i < gMapHeader.events->objectEventCount; i++)
        {
            if ((objectEventTemplates[i].trainerType == TRAINER_TYPE_NORMAL
              || objectEventTemplates[i].trainerType == TRAINER_TYPE_BURIED)
              && vsSeekerDataIdx == LookupVsSeekerOpponentInArray(sVsSeekerData, GetTrainerFlagFromScript(objectEventTemplates[i].script)))
            {
                struct ObjectEvent *objectEvent;

                TryGetObjectEventIdByLocalIdAndMap(objectEventTemplates[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objEventId);
                objectEvent = &gObjectEvents[objEventId];
                GetRandomFaceDirectionMovementType(&objectEventTemplates[i]); // You are using this function incorrectly.  Please consult the manual.
                TryOverrideTemplateCoordsForObjectEvent(objectEvent, sFaceDirectionMovementTypeByFacingDirection[objectEvent->facingDirection]);
                gSaveBlock1Ptr->trainerRematches[objectEventTemplates[i].localId] = 0;
                if (gSelectedObjectEvent == objEventId)
                    objectEvent->movementType = sFaceDirectionMovementTypeByFacingDirection[objectEvent->facingDirection];
                else
                    objectEvent->movementType = MOVEMENT_TYPE_FACE_DOWN;
            }
        }
    }
}

static void TryGetRematchTrainerIdGivenGameState(const u16 * trainerIdxs, u8 * rematchIdx_p)
{
    switch (*rematchIdx_p)
    {
        case 0:
            break;
        case 1:
            if (!FlagGet(FLAG_GOT_VS_SEEKER))
                *rematchIdx_p = GetRematchTrainerIdGivenGameState(trainerIdxs, *rematchIdx_p);
            break;
         /* Jaizu: Needs to be adapted to Hoenn
        case 2:
            if (!FlagGet(FLAG_WORLD_MAP_CELADON_CITY))
                *rematchIdx_p = GetRematchTrainerIdGivenGameState(trainerIdxs, *rematchIdx_p);
            break;
        case 3:
            if (!FlagGet(FLAG_WORLD_MAP_FUCHSIA_CITY))
                *rematchIdx_p = GetRematchTrainerIdGivenGameState(trainerIdxs, *rematchIdx_p);
            break;
        case 4:
            if (!FlagGet(FLAG_SYS_GAME_CLEAR))
                *rematchIdx_p = GetRematchTrainerIdGivenGameState(trainerIdxs, *rematchIdx_p);
            break;
        case 5:
            if (!FlagGet(FLAG_SYS_CAN_LINK_WITH_RS))
                *rematchIdx_p = GetRematchTrainerIdGivenGameState(trainerIdxs, *rematchIdx_p);
            break;
            */
    }
}

static u8 GetRematchTrainerIdGivenGameState(const u16 *trainerIdxs, u8 rematchIdx)
{
    while (--rematchIdx != 0)
    {
        const u16 *rematch_p = trainerIdxs + rematchIdx;
        if (*rematch_p != 0xFFFF)
            return rematchIdx;
    }
    return 0;
}

// Jaizu: This replaced the Emerald one, probably breaks vanilla ones?
bool8 ShouldTryRematchBattle(void)
{
    if (ShouldTryRematchBattleInternal(sVsSeekerData, gTrainerBattleOpponent_A))
    {
        return TRUE;
    }
    return HasRematchTrainerAlreadyBeenFought(sVsSeekerData, gTrainerBattleOpponent_A);
}

static bool8 ShouldTryRematchBattleInternal(const VsSeekerData *vsSeekerData, u16 trainerBattleOpponent)
{
    s32 rematchIdx = GetRematchIdx(vsSeekerData, trainerBattleOpponent);

    if (rematchIdx == -1)
        return FALSE;
    if (rematchIdx >= 0 && rematchIdx < NELEMS(sVsSeekerData))
    {
        if (IsThisTrainerRematchable(gSpecialVar_LastTalked))
            return TRUE;
    }
    return FALSE;
}

static bool8 HasRematchTrainerAlreadyBeenFought(const VsSeekerData *vsSeekerData, u16 trainerBattleOpponent)
{
    s32 rematchIdx = GetRematchIdx(vsSeekerData, trainerBattleOpponent);

    if (rematchIdx == -1)
        return FALSE;
    if (!HasTrainerBeenFought(vsSeekerData[rematchIdx].trainerIdxs[0]))
        return FALSE;
    return TRUE;
}

void ClearRematchStateOfLastTalked(void)
{
    gSaveBlock1Ptr->trainerRematches[gSpecialVar_LastTalked] = 0;
    SetBattledTrainerFlag();
}

static int LookupVsSeekerOpponentInArray(const VsSeekerData * array, u16 trainerId)
{
    int i, j;

    for (i = 0; i < NELEMS(sVsSeekerData); i++)
    {
        for (j = 0; j < 6; j++)
        {
            u16 testTrainerId;
            if (array[i].trainerIdxs[j] == 0)
                break;
            testTrainerId = array[i].trainerIdxs[j];
            if (testTrainerId == 0xFFFF)
                continue;
            if (testTrainerId == trainerId)
                return i;
        }
    }

    return -1;
}

int GetRematchTrainerIdVSSeeker(u16 trainerId)
{
    u8 i;
    u8 j;
    j = GetNextAvailableRematchTrainer(sVsSeekerData, trainerId, &i);
    if (!j)
        return 0;
    TryGetRematchTrainerIdGivenGameState(sVsSeekerData[i].trainerIdxs, &j);
    return sVsSeekerData[i].trainerIdxs[j];
}

u8 IsTrainerReadyForRematch(void)
{
    return IsTrainerReadyForRematchInternal(sVsSeekerData, gTrainerBattleOpponent_A);
}

static bool8 IsTrainerReadyForRematchInternal(const VsSeekerData * array, u16 trainerId)
{
    int rematchTrainerIdx = LookupVsSeekerOpponentInArray(array, trainerId);

    if (rematchTrainerIdx == -1)
        return FALSE;
    if (rematchTrainerIdx >= NELEMS(sVsSeekerData))
        return FALSE;
    if (!IsThisTrainerRematchable(gSpecialVar_LastTalked))
        return FALSE;
    return TRUE;
}

static bool8 ObjectEventIdIsSane(u8 objectEventId)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];

    if (objectEvent->active && gMapHeader.events->objectEventCount >= objectEvent->localId && gSprites[objectEvent->spriteId].data[0] == objectEventId)
        return TRUE;
    return FALSE;
}

static u8 GetRandomFaceDirectionMovementType()
{
    u16 r1 = Random() % 4;

    switch (r1)
    {
        case 0:
            return MOVEMENT_TYPE_FACE_UP;
        case 1:
            return MOVEMENT_TYPE_FACE_DOWN;
        case 2:
            return MOVEMENT_TYPE_FACE_LEFT;
        case 3:
            return MOVEMENT_TYPE_FACE_RIGHT;
        default:
            return MOVEMENT_TYPE_FACE_DOWN;
    }
}

static u8 GetRunningBehaviorFromGraphicsId(u8 graphicsId)
{
    switch (graphicsId)
    {
        // Add to ObjectEventGraphicsInfo?
        //case OBJ_EVENT_GFX_TUBER_M:
        //case OBJ_EVENT_GFX_TUBER_F:
        //case OBJ_EVENT_GFX_GENTLEMAN:
        //case OBJ_EVENT_GFX_BEAUTY:
        //case OBJ_EVENT_GFX_BLACK_BELT:
        //case OBJ_EVENT_GFX_BUG_CATCHER:
        //case OBJ_EVENT_GFX_EXPERT_F:
        //case OBJ_EVENT_GFX_EXPERT_M:
        //case OBJ_EVENT_GFX_FISHERMAN:
        //case OBJ_EVENT_GFX_CAMPER:
        //case OBJ_EVENT_GFX_TWIN:
        //case OBJ_EVENT_GFX_LITTLE_BOY:
        //case OBJ_EVENT_GFX_MAN_3:
        //case OBJ_EVENT_GFX_PICNICKER:
        //case OBJ_EVENT_GFX_YOUNGSTER:
        //    return MOVEMENT_TYPE_RAISE_HAND_AND_JUMP;
      /* Jaizu: Needs to be adapted to Hoenn gfx
        case OBJ_EVENT_GFX_LITTLE_GIRL:
        case OBJ_EVENT_GFX_YOUNGSTER:
        case OBJ_EVENT_GFX_BOY:
        case OBJ_EVENT_GFX_BUG_CATCHER:
        case OBJ_EVENT_GFX_LASS:
        case OBJ_EVENT_GFX_WOMAN_1:
        case OBJ_EVENT_GFX_BATTLE_GIRL:
        case OBJ_EVENT_GFX_MAN:
        case OBJ_EVENT_GFX_ROCKER:
        case OBJ_EVENT_GFX_WOMAN_2:
        case OBJ_EVENT_GFX_BEAUTY:
        case OBJ_EVENT_GFX_BALDING_MAN:
        case OBJ_EVENT_GFX_TUBER_F:
        case OBJ_EVENT_GFX_CAMPER:
        case OBJ_EVENT_GFX_PICNICKER:
        case OBJ_EVENT_GFX_COOLTRAINER_M:
        case OBJ_EVENT_GFX_COOLTRAINER_F:
        case OBJ_EVENT_GFX_SWIMMER_M_LAND:
        case OBJ_EVENT_GFX_SWIMMER_F_LAND:
        case OBJ_EVENT_GFX_BLACKBELT:
        case OBJ_EVENT_GFX_HIKER:
        case OBJ_EVENT_GFX_SAILOR:
            return MOVEMENT_TYPE_RAISE_HAND_AND_JUMP;
        case OBJ_EVENT_GFX_TUBER_M_WATER:
        case OBJ_EVENT_GFX_SWIMMER_M_WATER:
        case OBJ_EVENT_GFX_SWIMMER_F_WATER:
            return MOVEMENT_TYPE_RAISE_HAND_AND_SWIM;
         */
        default:
            return MOVEMENT_TYPE_RAISE_HAND_AND_STOP;
    }
}

static u16 GetTrainerFlagFromScript(const u8 *script)
/*
 * The trainer flag is a little-endian short located +2 from
 * the script pointer, assuming the trainerbattle command is
 * first in the script.  Because scripts are unaligned, and
 * because the ARM processor requires shorts to be 16-bit
 * aligned, this function needs to perform explicit bitwise
 * operations to get the correct flag.
 *
 * 5c XX YY ZZ ...
 *       -- --
 */
{
    u16 trainerFlag;

    script += 2;
    trainerFlag = script[0];
    trainerFlag |= script[1] << 8;
    return trainerFlag;
}

static int GetRematchIdx(const VsSeekerData * vsSeekerData, u16 trainerFlagIdx)
{
    int i;

    for (i = 0; i < NELEMS(sVsSeekerData); i++)
    {
        if (vsSeekerData[i].trainerIdxs[0] == trainerFlagIdx)
            return i;
    }

    return -1;
}

static bool32 IsThisTrainerRematchable(u32 localId)
{
    if (!gSaveBlock1Ptr->trainerRematches[localId])
        return FALSE;
    return TRUE;
}

static void ClearAllTrainerRematchStates(void)
{
    u8 i;

    for (i = 0; i < NELEMS(gSaveBlock1Ptr->trainerRematches); i++)
        gSaveBlock1Ptr->trainerRematches[i] = 0;
}

static bool8 IsTrainerVisibleOnScreen(struct VsSeekerTrainerInfo * trainerInfo)
{
    s16 x;
    s16 y;

    PlayerGetDestCoords(&x, &y);
    x -= 7;
    y -= 7;

    if (   x - 7 <= trainerInfo->xCoord
        && x + 7 >= trainerInfo->xCoord
        && y - 5 <= trainerInfo->yCoord
        && y + 5 >= trainerInfo->yCoord
        && ObjectEventIdIsSane(trainerInfo->objectEventId) == 1)
        return TRUE;
    return FALSE;
}

static u8 GetNextAvailableRematchTrainer(const VsSeekerData * vsSeekerData, u16 trainerFlagNo, u8 * idxPtr)
{
    int i, j;

    for (i = 0; i < NELEMS(sVsSeekerData); i++)
    {
        if (vsSeekerData[i].trainerIdxs[0] == trainerFlagNo)
        {
            *idxPtr = i;
            for (j = 1; j < 6; j++)
            {
                if (vsSeekerData[i].trainerIdxs[j] == 0)
                    return j - 1;
                if (vsSeekerData[i].trainerIdxs[j] == 0xffff)
                    continue;
                if (HasTrainerBeenFought(vsSeekerData[i].trainerIdxs[j]))
                    continue;
                return j;
            }
            return j - 1;
        }
    }

    *idxPtr = 0;
    return 0;
}

static u8 GetRematchableTrainerLocalId(void)
{
    u8 idx;
    u8 i;

    for (i = 0; sVsSeeker->trainerInfo[i].localId != 0xFF; i++)
    {
        if (IsTrainerVisibleOnScreen(&sVsSeeker->trainerInfo[i]) == 1)
        {
            if (HasTrainerBeenFought(sVsSeeker->trainerInfo[i].trainerIdx) != 1 || GetNextAvailableRematchTrainer(sVsSeekerData, sVsSeeker->trainerInfo[i].trainerIdx, &idx))
                return sVsSeeker->trainerInfo[i].localId;
        }
    }

    return 0xFF;
}

static void StartTrainerObjectMovementScript(struct VsSeekerTrainerInfo * trainerInfo, const u8 * script)
{
    UnfreezeObjectEvent(&gObjectEvents[trainerInfo->objectEventId]);
    ScriptMovement_StartObjectMovementScript(trainerInfo->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, script);
}

static u8 GetCurVsSeekerResponse(s32 vsSeekerIdx, u16 trainerIdx)
{
    s32 i;
    s32 j;

    for (i = 0; i < vsSeekerIdx; i++)
    {
        if (IsTrainerVisibleOnScreen(&sVsSeeker->trainerInfo[i]) == 1 && sVsSeeker->trainerInfo[i].trainerIdx == trainerIdx)
        {
            for (j = 0; j < sVsSeeker->numRematchableTrainers; j++)
            {
                if (sVsSeeker->trainerIdxArray[j] == sVsSeeker->trainerInfo[i].trainerIdx)
                    return VSSEEKER_SINGLE_RESP_YES;
            }
            return VSSEEKER_SINGLE_RESP_NO;
        }
    }
    return VSSEEKER_SINGLE_RESP_RAND;
}

static void StartAllRespondantIdleMovements(void)
{
    u8 dummy = 0;
    s32 i;
    s32 j;

    for (i = 0; i < sVsSeeker->numRematchableTrainers; i++)
    {
        for (j = 0; sVsSeeker->trainerInfo[j].localId != 0xFF; j++)
        {
            if (sVsSeeker->trainerInfo[j].trainerIdx == sVsSeeker->trainerIdxArray[i])
            {
                struct ObjectEvent *objectEvent = &gObjectEvents[sVsSeeker->trainerInfo[j].objectEventId];

                if (ObjectEventIdIsSane(sVsSeeker->trainerInfo[j].objectEventId) == 1)
                    SetTrainerMovementType(objectEvent, sVsSeeker->runningBehaviourEtcArray[i]);
                TryOverrideTemplateCoordsForObjectEvent(objectEvent, sVsSeeker->runningBehaviourEtcArray[i]);
                gSaveBlock1Ptr->trainerRematches[sVsSeeker->trainerInfo[j].localId] = GetNextAvailableRematchTrainer(sVsSeekerData, sVsSeeker->trainerInfo[j].trainerIdx, &dummy);
            }
        }
    }
}
