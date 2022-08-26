#include "global.h"
#include "task.h"
#include "bg.h"
#include "palette.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "scanline_effect.h"
#include "m4a.h"
#include "dynamic_placeholder_text_util.h"
#include "overworld.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "sound.h"
#include "menu.h"
#include "librfu.h"
#include "link_rfu.h"
#include "union_room.h"
#include "constants/songs.h"
#include "constants/union_room.h"

enum {
    COLORMODE_NORMAL,
    COLORMODE_WHITE_LGRAY,
    COLORMODE_RED,
    COLORMODE_GREEN,
    COLORMODE_WHITE_DGRAY,
};

#define GROUPTYPE_TRADE   0
#define GROUPTYPE_BATTLE  1
#define GROUPTYPE_UNION   2
#define GROUPTYPE_TOTAL   3
#define GROUPTYPE_NONE   -1
#define NUM_GROUPTYPES    4

struct WirelessCommunicationStatusScreen
{
    u32 groupCounts[NUM_GROUPTYPES];
    u32 prevGroupCounts[NUM_GROUPTYPES];
    u32 activities[NUM_TASK_DATA];
    u8 taskId;
    u8 rfuTaskId;
    u8 filler[10];
};

static struct WirelessCommunicationStatusScreen * sStatusScreen;

static void CB2_InitWirelessCommunicationScreen(void);
static void Task_WirelessCommunicationScreen(u8);
static void WCSS_AddTextPrinterParameterized(u8, u8, const u8 *, u8, u8, u8);
static bool32 UpdateCommunicationCounts(u32 *, u32 *, u32 *, u8);

static const u16 sBgTiles_Pal[] = INCBIN_U16("graphics/link/wireless_info_screen.gbapal");
static const u32 sBgTiles_Gfx[] = INCBIN_U32("graphics/link/wireless_info_screen.4bpp.lz");
static const u32 sBgTiles_Tilemap[] = INCBIN_U32("graphics/link/wireless_info_screen.bin.lz");

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .priority = 1
    }
};

static const struct WindowTemplate sWindowTemplates[] = {
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 0,
        .width = 24,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0x0001
    }, {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 4,
        .width = 21,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 0x0049
    }, {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 4,
        .width = 3,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 0x0184
    }, DUMMY_WIN_TEMPLATE
};

static const u8 *const sHeaderTexts[NUM_GROUPTYPES + 1] = {
    [0]                    = gText_WirelessCommStatus,
    [GROUPTYPE_TRADE + 1]  = gText_PeopleTrading,
    [GROUPTYPE_BATTLE + 1] = gText_PeopleBattling,
    [GROUPTYPE_UNION + 1]  = gText_PeopleInUnionRoom,
    [GROUPTYPE_TOTAL + 1]  = gText_PeopleCommunicating
};

// Activity, group type, number of players
// 0 players means the number of players can change and should be counted dynamically
// GROUPTYPE_TOTAL have no unique group and are simply counted in the total of "people communicating"
// UB: GROUPTYPE_NONE (-1) can potentially be used as an index into a u8[4] in CountPlayersInGroupAndGetActivity
static const u8 sActivityGroupInfo[][3] = {
    {ACTIVITY_BATTLE_SINGLE,                 GROUPTYPE_BATTLE, 2},
    {ACTIVITY_BATTLE_DOUBLE,                 GROUPTYPE_BATTLE, 2},
    {ACTIVITY_BATTLE_MULTI,                  GROUPTYPE_BATTLE, 4},
    {ACTIVITY_TRADE,                         GROUPTYPE_TRADE,  2},
    {ACTIVITY_WONDER_CARD_DUP,               GROUPTYPE_TOTAL,  2},
    {ACTIVITY_WONDER_NEWS_DUP,               GROUPTYPE_TOTAL,  2},
    {ACTIVITY_POKEMON_JUMP,                  GROUPTYPE_TOTAL,  0},
    {ACTIVITY_BERRY_CRUSH,                   GROUPTYPE_TOTAL,  0},
    {ACTIVITY_BERRY_PICK,                    GROUPTYPE_TOTAL,  0},
    {ACTIVITY_SEARCH,                        GROUPTYPE_NONE,   0},
    {ACTIVITY_SPIN_TRADE,                    GROUPTYPE_TRADE,  0},
    {ACTIVITY_BERRY_BLENDER,                 GROUPTYPE_TOTAL,  0},
    {ACTIVITY_RECORD_CORNER,                 GROUPTYPE_TOTAL,  0},
    {ACTIVITY_NONE | IN_UNION_ROOM,          GROUPTYPE_UNION,  1},
    {ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM, GROUPTYPE_UNION,  2},
    {ACTIVITY_TRADE | IN_UNION_ROOM,         GROUPTYPE_UNION,  2},
    {ACTIVITY_CHAT | IN_UNION_ROOM,          GROUPTYPE_UNION,  0},
    {ACTIVITY_CARD | IN_UNION_ROOM,          GROUPTYPE_UNION,  2},
    {ACTIVITY_PLYRTALK | IN_UNION_ROOM,      GROUPTYPE_UNION,  1},
    {ACTIVITY_NPCTALK | IN_UNION_ROOM,       GROUPTYPE_UNION,  2},
    {ACTIVITY_ACCEPT | IN_UNION_ROOM,        GROUPTYPE_UNION,  1},
    {ACTIVITY_DECLINE | IN_UNION_ROOM,       GROUPTYPE_UNION,  1},
    {ACTIVITY_WONDER_CARD,                   GROUPTYPE_TOTAL,  2},
    {ACTIVITY_WONDER_NEWS,                   GROUPTYPE_TOTAL,  2},
    {ACTIVITY_CONTEST_COOL,                  GROUPTYPE_TOTAL,  0},
    {ACTIVITY_CONTEST_BEAUTY,                GROUPTYPE_TOTAL,  0},
    {ACTIVITY_CONTEST_CUTE,                  GROUPTYPE_TOTAL,  0},
    {ACTIVITY_CONTEST_SMART,                 GROUPTYPE_TOTAL,  0},
    {ACTIVITY_CONTEST_TOUGH,                 GROUPTYPE_TOTAL,  0},
    {ACTIVITY_BATTLE_TOWER,                  GROUPTYPE_BATTLE, 2},
    {ACTIVITY_BATTLE_TOWER_OPEN,             GROUPTYPE_BATTLE, 2}
};

static void CB2_RunWirelessCommunicationScreen(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        RunTasks();
        RunTextPrinters();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
    }
}

static void VBlankCB_WirelessCommunicationScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void ShowWirelessCommunicationScreen(void)
{
    SetMainCallback2(CB2_InitWirelessCommunicationScreen);
}

static void CB2_InitWirelessCommunicationScreen(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    sStatusScreen = AllocZeroed(sizeof(struct WirelessCommunicationStatusScreen));
    SetVBlankCallback(NULL);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
    DecompressAndLoadBgGfxUsingHeap(1, sBgTiles_Gfx, 0, 0, 0);
    CopyToBgTilemapBuffer(1, sBgTiles_Tilemap, 0, 0);
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    ScanlineEffect_Stop();
    m4aSoundVSyncOn();
    SetVBlankCallback(VBlankCB_WirelessCommunicationScreen);
    sStatusScreen->taskId = CreateTask(Task_WirelessCommunicationScreen, 0);
    sStatusScreen->rfuTaskId = CreateTask_ListenToWireless();
    sStatusScreen->prevGroupCounts[GROUPTYPE_TOTAL] = 1;
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    LoadPalette(sBgTiles_Pal, 0x00, 0x20);
    Menu_LoadStdPalAt(0xF0);
    DynamicPlaceholderTextUtil_Reset();
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0x0F);
    CopyBgTilemapBufferToVram(1);
    SetMainCallback2(CB2_RunWirelessCommunicationScreen);
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_ExitWirelessCommunicationStatusScreen(void)
{
    s32 i;
    FreeAllWindowBuffers();
    for (i = 0; i < (int)ARRAY_COUNT(sBgTemplates); i++)
    {
        Free(GetBgTilemapBuffer(i));
    }
    Free(sStatusScreen);
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void WCSS_CyclePalette(s16 * counter, s16 * palIdx)
{
    if (++(*counter) > 5)
    {
        if (++(*palIdx) == 14)
            *palIdx = 0;

        *counter = 0;
    }
    LoadPalette(sBgTiles_Pal + 16 * (*palIdx + 2), 0, 0x10);
}

static void PrintHeaderTexts(void)
{
    s32 i;
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    WCSS_AddTextPrinterParameterized(0, FONT_NORMAL, sHeaderTexts[0], GetStringCenterAlignXOffset(FONT_NORMAL, sHeaderTexts[0], 0xC0), 6, COLORMODE_GREEN);
    for (i = 0; i < (int)ARRAY_COUNT(*sHeaderTexts) - 1; i++)
    {
        WCSS_AddTextPrinterParameterized(1, FONT_NORMAL, sHeaderTexts[i + 1], 0, 30 * i + 8, COLORMODE_WHITE_LGRAY);
    }
    WCSS_AddTextPrinterParameterized(1, FONT_NORMAL, sHeaderTexts[i + 1], 0, 30 * i + 8, COLORMODE_RED);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_GFX);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_GFX);
}

#define tState data[0]

static void Task_WirelessCommunicationScreen(u8 taskId)
{
    s32 i;
    switch (gTasks[taskId].tState)
    {
    case 0:
        PrintHeaderTexts();
        gTasks[taskId].tState++;
        break;
    case 1:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, 0);
        ShowBg(1);
        CopyBgTilemapBufferToVram(0);
        ShowBg(0);
        gTasks[taskId].tState++;
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tState++;
        }
        break;
    case 3:
        if (UpdateCommunicationCounts(sStatusScreen->groupCounts, sStatusScreen->prevGroupCounts, sStatusScreen->activities, sStatusScreen->rfuTaskId))
        {
            FillWindowPixelBuffer(2, PIXEL_FILL(0));
            for (i = 0; i < NUM_GROUPTYPES; i++)
            {
                ConvertIntToDecimalStringN(gStringVar4, sStatusScreen->groupCounts[i], STR_CONV_MODE_RIGHT_ALIGN, 2);
                if (i != GROUPTYPE_TOTAL)
                    WCSS_AddTextPrinterParameterized(2, FONT_NORMAL, gStringVar4, 12, 30 * i + 8, COLORMODE_WHITE_LGRAY);
                else
                    WCSS_AddTextPrinterParameterized(2, FONT_NORMAL, gStringVar4, 12, 98, COLORMODE_RED);
            }
            PutWindowTilemap(2);
            CopyWindowToVram(2, COPYWIN_FULL);
        }
        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gTasks[sStatusScreen->rfuTaskId].data[15] = 0xFF;
            gTasks[taskId].tState++;
        }
        WCSS_CyclePalette(&gTasks[taskId].data[7], &gTasks[taskId].data[8]);
        break;
    case 4:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, 0);
        gTasks[taskId].tState++;
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_ExitWirelessCommunicationStatusScreen);
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState

static void WCSS_AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 mode)
{
    u8 color[3];

    switch (mode)
    {
    case COLORMODE_NORMAL:
        color[0] = TEXT_COLOR_TRANSPARENT;
        color[1] = TEXT_COLOR_DARK_GRAY;
        color[2] = TEXT_COLOR_LIGHT_GRAY;
        break;
    case COLORMODE_WHITE_LGRAY:
        color[0] = TEXT_COLOR_TRANSPARENT;
        color[1] = TEXT_COLOR_WHITE;
        color[2] = TEXT_COLOR_LIGHT_GRAY;
        break;
    case COLORMODE_RED:
        color[0] = TEXT_COLOR_TRANSPARENT;
        color[1] = TEXT_COLOR_RED;
        color[2] = TEXT_COLOR_LIGHT_RED;
        break;
    case COLORMODE_GREEN:
        color[0] = TEXT_COLOR_TRANSPARENT;
        color[1] = TEXT_COLOR_LIGHT_GREEN;
        color[2] = TEXT_COLOR_GREEN;
        break;
    case COLORMODE_WHITE_DGRAY:
        color[0] = TEXT_COLOR_TRANSPARENT;
        color[1] = TEXT_COLOR_WHITE;
        color[2] = TEXT_COLOR_DARK_GRAY;
        break;
    }

    AddTextPrinterParameterized4(windowId, fontId, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static u32 CountPlayersInGroupAndGetActivity(struct RfuPlayer * player, u32 * groupCounts)
{
    int i, j, k;
    u32 activity = player->rfu.data.activity;

    #define group_activity(i) (sActivityGroupInfo[(i)][0])
    #define group_type(i)     (sActivityGroupInfo[(i)][1])
    #define group_players(i)  (sActivityGroupInfo[(i)][2])

    for (i = 0; i < ARRAY_COUNT(sActivityGroupInfo); i++)
    {
        if (activity == group_activity(i) && player->groupScheduledAnim == UNION_ROOM_SPAWN_IN)
        {
            if (group_players(i) == 0)
            {
                k = 0;
                for (j = 0; j < RFU_CHILD_MAX; j++)
                    if (player->rfu.data.partnerInfo[j] != 0) k++;
                k++;
                groupCounts[group_type(i)] += k;
            }
            else
            {
                groupCounts[group_type(i)] += group_players(i);
            }
        }
    }
    return activity;

    #undef group_activity
    #undef group_type
    #undef group_players
}

static bool32 HaveCountsChanged(u32 * currCounts, u32 * prevCounts)
{
    s32 i;
    for (i = 0; i < NUM_GROUPTYPES; i++)
    {
        if (currCounts[i] != prevCounts[i])
            return TRUE;
    }
    return FALSE;
}

static bool32 UpdateCommunicationCounts(u32 * groupCounts, u32 * prevGroupCounts, u32 * activities, u8 taskId)
{
    bool32 activitiesChanged = FALSE;
    u32 groupCountBuffer[NUM_GROUPTYPES] = {0, 0, 0, 0};
    struct RfuPlayer ** players = (void *)gTasks[taskId].data;
    s32 i;

    for (i = 0; i < NUM_TASK_DATA; i++)
    {
        u32 activity = CountPlayersInGroupAndGetActivity(&(*players)[i], groupCountBuffer);
        if (activity != activities[i])
        {
            activities[i] = activity;
            activitiesChanged = TRUE;
        }
    }

    if (!HaveCountsChanged(groupCountBuffer, prevGroupCounts))
    {
        if (activitiesChanged == TRUE)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        memcpy(groupCounts,     groupCountBuffer, sizeof(groupCountBuffer));
        memcpy(prevGroupCounts, groupCountBuffer, sizeof(groupCountBuffer));

        groupCounts[GROUPTYPE_TOTAL] = groupCounts[GROUPTYPE_TRADE]
                                     + groupCounts[GROUPTYPE_BATTLE]
                                     + groupCounts[GROUPTYPE_UNION]
                                     + groupCounts[GROUPTYPE_TOTAL];
        return TRUE;
    }
}
