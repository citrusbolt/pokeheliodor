#include "global.h"
#include "event_data.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "scanline_effect.h"
#include "bg.h"
#include "window.h"
#include "gpu_regs.h"
#include "constants/rgb.h"
#include "international_string_util.h"

static void CB2_BuildInfoScreen(void);
static void VBlankCB(void);
static void Task_BuildInfoScreen(u8 taskId);
static void InitBuildInfoScreenBgAndWindows(void);

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

void CB2_InitBuildInfoScreen(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetVBlankCallback(NULL);
    DmaClear16(3, PLTT, PLTT_SIZE);
    DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    ResetSpriteData();
    ResetTasks();
    ResetPaletteFade();
    InitBuildInfoScreenBgAndWindows();
    SetVBlankCallback(VBlankCB);
    SetMainCallback2(CB2_BuildInfoScreen);
    CreateTask(Task_BuildInfoScreen, 80);
}

static void InitBuildInfoScreenBgAndWindows(void)
{
    ClearScheduledBgCopiesToVram();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    ScheduleBgCopyTilemapToVram(0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void CB2_BuildInfoScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    ProcessSpriteCopyRequests();
    LoadOam();
    TransferPlttBuffer();
}

#define tState data[0]

#include "data/text/build_info.h"

const u8 sText_BuildInfoHeader[] = _("- Version Info -");
const u8 sText_BuildVersion[] = _("Build Version:");
const u8 sText_SaveVersion[] = _("Save Version:");

static void Task_ShowBuildInfoPrompt(u8 taskId)
{
    u8 saveVer[5];
    u8 colors[3] = { 0, 2, 3, };
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x214, 0xE);

        AddTextPrinterParameterized(0, FONT_NORMAL, sText_BuildInfoHeader, GetStringCenterAlignXOffset(FONT_NORMAL, sText_BuildInfoHeader, 230) - 2, 1, TEXT_SKIP_DRAW, 0);
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_RepoBranch, 0, 33, TEXT_SKIP_DRAW, 0);
        if (gUncommitedChanges)
        {
            colors[1] = 4;
            colors[2] = 5;
        }
        AddTextPrinterParameterized(0, FONT_NORMAL, sText_BuildVersion, 0, 57, TEXT_SKIP_DRAW, 0);
        AddTextPrinterParameterized3(0, FONT_NORMAL, 75, 57, colors, TEXT_SKIP_DRAW, gText_BuildVersion);
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_BuildTime, 0, 73, TEXT_SKIP_DRAW, 0);

        AddTextPrinterParameterized(0, FONT_NORMAL, sText_SaveVersion, 0, 97, TEXT_SKIP_DRAW, 0);
        ConvertIntToDecimalStringN(saveVer, VarGet(VAR_SAVE_VER), STR_CONV_MODE_LEADING_ZEROS, 1);
        AddTextPrinterParameterized(0, FONT_NORMAL, saveVer, 73, 97, TEXT_SKIP_DRAW, 0);

        CopyWindowToVram(0, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        tState++;
    case 1:
        if (JOY_NEW(B_BUTTON) || JOY_NEW(A_BUTTON))
        {
            DestroyTask(taskId);
            DoSoftReset();
        }
        break;
    }
}

#undef tState

// Task states for Task_BuildInfoScreen
enum {
    MAINSTATE_FADE_IN,
    MAINSTATE_CHECK_SAVE,
    MAINSTATE_WAIT_EXIT,
    MAINSTATE_EXIT,
};

#define tState data[0]
#define tSubTaskId data[1]

static void Task_BuildInfoScreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case MAINSTATE_FADE_IN:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 0x10, 0, RGB_WHITEALPHA);
        tState = MAINSTATE_CHECK_SAVE;
        break;
    case MAINSTATE_CHECK_SAVE:
        if (!gPaletteFade.active)
        {
            tSubTaskId = CreateTask(Task_ShowBuildInfoPrompt, 80);
            tState = MAINSTATE_WAIT_EXIT;
        }
        break;
    case MAINSTATE_WAIT_EXIT:
        if (JOY_NEW(A_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 0x10, RGB_WHITEALPHA);
            tState = MAINSTATE_EXIT;
            // fallthrough
        }
        else
        {
            break;
        }
    case MAINSTATE_EXIT:
        if (!gPaletteFade.active)
        {
            DestroyTask(taskId);
            FreeAllWindowBuffers();
            DoSoftReset();
        }
    }
}
