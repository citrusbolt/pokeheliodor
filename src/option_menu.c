#include "global.h"
#include "option_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "graphics.h"
#include "event_data.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"

enum
{
    MENU_GAME,
    MENU_SOUND,
    MENU_BATTLE,
    MENU_BREEDING,
    MENU_COUNT,
};

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLE_SCENE,
    MENUITEM_BATTLE_STYLE,
    MENUITEM_SOUND_MODE,
    MENUITEM_BUTTON_MODE,
    MENUITEM_FRAME_TYPE,
    MENUITEM_MESSAGE_COLOR,
    MENUITEM_FONT,
    MENUITEM_UNIT_SYSTEM,
    MENUITEM_CLOCK,
    //MENUITEM_PARTY_BOX,
    MENUITEM_NICKNAME,
    MENUITEM_CONFIRM,
    MENUITEM_COUNT
};

// Window Ids
enum
{
    WIN_TOPBAR_LEFT,
    WIN_TOPBAR_RIGHT,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {//WIN_TOPBAR_LEFT
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {//WIN_TOPBAR_RIGHT
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 0,
        .width = 15,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 31
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
    },
};

struct OptionMenu
{
    u8 submenu;
    u8 sel[MENUITEM_COUNT];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
};

#define Y_DIFF                      16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN           5
#define NUM_OPTIONS_FROM_BORDER     1
#define LAST_MENU                   MENU_BREEDING

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 choosen, bool8 active);
static void DrawOptionMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionMenuItem(void);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int ProcessInput_Options_Two(int selection);
static int ProcessInput_Options_Three(int selection);
static int ProcessInput_Options_Four(int selection);
static int ProcessInput_Options_Font(int selection);
static int ProcessInput_Options_Eleven(int selection);
static int ProcessInput_Sound(int selection);
static int ProcessInput_FrameType(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static u8 MenuItemCount(void);
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active);
static void ReDrawAll(void);
static void DrawChoices_TextSpeed(int selection, int y);
static void DrawChoices_BattleScene(int selection, int y);
static void DrawChoices_BattleStyle(int selection, int y);
static void DrawChoices_Sound(int selection, int y);
static void DrawChoices_ButtonMode(int selection, int y);
static void DrawChoices_MessageColor(int selection, int y);
static void DrawChoices_PartyBox(int selection, int y);
static void DrawChoices_UnitSystem(int selection, int y);
static void DrawChoices_Nickname(int selection, int y);
static void DrawChoices_Font(int selection, int y);
static void DrawChoices_FrameType(int selection, int y);
static void DrawChoices_OnOff(int selection, int y);
static void DrawBgWindowFramesOptions(void);
static int ProcessInput_Options_MessageColor(int selection);
static void DrawBgWindowFramesDescription(void);
static const u16 * GetWindowPal(int selection);
static void DrawChoices_Challenges_ExpMultiplier(int selection, int y);
static void DrawChoices_Challenges_ScalingIVs(int selection, int y);
static void DrawChoices_Challenges_ScalingEVs(int selection, int y);

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const data
static const u16 sOptionMenuBg_Pal[] = {RGB(25, 25, 0)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

// Options names
static const u8 sText_TextSpeed[]       = _("TEXT SPEED");
static const u8 sText_BattleScene[]     = _("BATTLE SCENE");
static const u8 sText_BattleStyle[]     = _("BATTLE STYLE");
static const u8 sText_SoundMode[]       = _("SOUND");
static const u8 sText_ButtonMode[]      = _("BUTTON MODE");
static const u8 sText_Frame[]           = _("MENU FRAME");
static const u8 sText_MessageColor[]    = _("MESSAGE COLOR");
static const u8 sText_Font[]            = _("FONT");
static const u8 sText_UnitSystem[]      = _("UNIT SYSTEM");
static const u8 sText_Clock[]           = _("12 HOUR CLOCK");
static const u8 sText_PartyBox[]        = _("PARTY/BOX");
static const u8 sText_Nickname[]        = _("GIVE NICKNAMES");
static const u8 sText_Confirm[]         = _("CLOSE");

static const u8 sText_FollowerPkmn[]    = _("FOLLOWER {PKMN}");
static const u8 sText_StartMenu[]       = _("START MENU");
static const u8 sText_OverworldCalls[]  = _("OVERWORLD CALLS");
static const u8 sText_FishReeling[]     = _("FISHING STYLE");
static const u8 sText_Surf[]            = _("SURF BGM");
static const u8 sText_Bike[]            = _("BIKE BGM");
static const u8 sText_Wild[]            = _("WILD {PKMN} BGM");
static const u8 sText_Trainer[]         = _("TRAINER BGM");
static const u8 sText_Grass[]           = _("GRASS SOUND");
static const u8 sText_BattleIntro[]     = _("BATTLE INTRO");
static const u8 sText_HpBar[]           = _("HP BAR SPEED");
static const u8 sText_ExpBar[]          = _("EXP BAR SPEED");
static const u8 sText_LastBall[]        = _("LAST BALL");
static const u8 sText_FriendshipBonus[] = _("FRIENDSHIP BONUS");
static const u8 sText_ExpMultiplier[]   = _("EXP MULTIPLIER");
static const u8 sText_Pss[]             = _("PSS SPLIT");
static const u8 sText_NewShiny[]        = _("NEW SHINY");
static const u8 sText_Difficulty[]      = _("CHALLENGE MODE");
static const u8 sText_TypeIcons[]       = _("TYPE ICONS");
static const u8 sText_SummaryScreen[]   = _("SUMMARY SCREEN");
static const u8 sText_BreedingIvs[] = _("IV TO INHERIT");
static const u8 sText_Masuda[]      = _("MASUDA METHOD");
static const u8 sText_ShinyCharm[]  = _("SHINY CHARM");
static const u8 sText_OvalCharm[]   = _("OVAL CHARM");
static const u8 sText_Everstone[]   = _("EVERSTONE");
static const u8 sText_GlobalExp[]   = _("GLOBAL EXP.SHARE");

// Posible options
static const u8 sText_TextSpeedSlow[]       = _("SLOW");
static const u8 sText_TextSpeedMid[]        = _("MEDIUM");
static const u8 sText_TextSpeedFast[]       = _("FAST");
static const u8 sText_BattleStyleShift[]    = _("SHIFT");
static const u8 sText_BattleStyleSet[]      = _("SET");
static const u8 sText_ButtonTypeNormal[]    = _("NORMAL");
static const u8 sText_SoundMono[]           = _("MONO");
static const u8 sText_SoundStereo[]         = _("STEREO");
static const u8 sText_ButtonTypeLR[]        = _("LR");
static const u8 sText_ButtonTypeLEqualsA[]  = _("L=A");
static const u8 sText_FrameType[]           = _("TYPE");
static const u8 sText_OptionEmerald[]       = _("EMERALD");
static const u8 sText_OptionFRLG[]          = _("FRLG");
static const u8 sText_UnitSystemImperial[]  = _("IMPERIAL");
static const u8 sText_UnitSystemMetric[]    = _("METRIC");
static const u8 sText_OptionOff[]           = _("OFF");
static const u8 sText_OptionOn[]            = _("ON");
static const u8 sText_OptionManual[]        = _("MANUAL");
static const u8 sText_OptionAutomatic[]     = _("AUTOMATIC");
static const u8 sText_OptionGive[]          = _("GIVE");
static const u8 sText_OptionDontGive[]      = _("DON'T GIVE");
static const u8 sText_OptionPlayer[]        = _("PLAYER");
static const u8 sText_OptionMenuSave[]      = _("SAVE");
static const u8 sText_OptionGreen[]         = _("GREEN");
static const u8 sText_OptionRed[]           = _("RED");
static const u8 sText_OptionBlue[]          = _("BLUE");
static const u8 sText_OptionYellow[]        = _("YELLOW");
static const u8 sText_OptionHard[]          = _("HARD");
static const u8 sText_OptionCustom[]        = _("CUSTOM");
static const u8 sText_FrameTypeNumber[]     = _("");
static const u8 sText_Option3[]             = _("3");
static const u8 sText_Option5[]             = _("5");

// Header text
static const u8 sText_TopBar_Options[]     = _("OPTIONS");
static const u8 sText_TopBar_Sound[]    = _("{OPTION_SMALL_DOT} {OPTION_BIG_DOT} {OPTION_SMALL_DOT} {OPTION_SMALL_DOT} SOUND OPTIONS");
static const u8 sText_TopBar_Battle[]   = _("{OPTION_SMALL_DOT} {OPTION_SMALL_DOT} {OPTION_BIG_DOT} {OPTION_SMALL_DOT} BATTLE OPTIONS");
static const u8 sText_TopBar_Breeding[] = _("{OPTION_SMALL_DOT} {OPTION_SMALL_DOT} {OPTION_SMALL_DOT} {OPTION_BIG_DOT} BREEDING OPTIONS");
static const u8 sText_TopBar_Right[]    = _("{L_BUTTON}{R_BUTTON} PAGE {B_BUTTON} SAVE");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

// Menu draw and input functions
struct
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
}

static const sItemFunctionsGame[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]     = {DrawChoices_TextSpeed,    ProcessInput_Options_Three},
    [MENUITEM_BATTLE_SCENE]  = {DrawChoices_BattleScene,  ProcessInput_Options_Two},
    [MENUITEM_BATTLE_STYLE]  = {DrawChoices_BattleStyle,  ProcessInput_Options_Two},
    [MENUITEM_SOUND_MODE]    = {DrawChoices_Sound,        ProcessInput_Options_Two},
    [MENUITEM_BUTTON_MODE]   = {DrawChoices_ButtonMode,   ProcessInput_Options_Three},
    [MENUITEM_FRAME_TYPE]    = {DrawChoices_FrameType,    ProcessInput_FrameType},
    [MENUITEM_MESSAGE_COLOR] = {DrawChoices_MessageColor, ProcessInput_Options_MessageColor},
    [MENUITEM_FONT]          = {DrawChoices_Font,         ProcessInput_Options_Font}, 
    [MENUITEM_UNIT_SYSTEM]   = {DrawChoices_UnitSystem,   ProcessInput_Options_Two},
    [MENUITEM_CLOCK]         = {DrawChoices_OnOff,        ProcessInput_Options_Two},
    //[MENUITEM_PARTY_BOX]     = {DrawChoices_PartyBox,     ProcessInput_Options_Two},
    [MENUITEM_NICKNAME]      = {DrawChoices_Nickname,     ProcessInput_Options_Two},
    [MENUITEM_CONFIRM]       = {NULL,                     NULL}
};

// Menu left side option names text
static const u8 *const sOptionMenuItemsNamesGame[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]     = sText_TextSpeed,
    [MENUITEM_BATTLE_SCENE]  = sText_BattleScene,
    [MENUITEM_BATTLE_STYLE]  = sText_BattleStyle,
    [MENUITEM_SOUND_MODE]    = sText_SoundMode,
    [MENUITEM_BUTTON_MODE]   = sText_ButtonMode,
    [MENUITEM_FRAME_TYPE]    = sText_Frame,
    [MENUITEM_MESSAGE_COLOR] = sText_MessageColor,
    [MENUITEM_FONT]          = sText_Font,
    [MENUITEM_UNIT_SYSTEM]   = sText_UnitSystem,
    [MENUITEM_CLOCK]         = sText_Clock,
    //[MENUITEM_PARTY_BOX]     = sText_PartyBox,
    [MENUITEM_NICKNAME]      = sText_Nickname,
    [MENUITEM_CONFIRM]       = sText_Confirm
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
        case 0:
            return sOptionMenuItemsNamesGame[menuItem];    
    }
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    return TRUE;
}

// Descriptions
static const u8 sText_Empty[]   = _("Test description.\nDon't mind me!");
static const u8 sText_Save[]    = _("Save the selected options and\nreturn to the previous menu.");
// Game
static const u8 sText_Desc_TextSpeed[]    = _("Choose one of the three\ntext-display speeds.");
static const u8 sText_Desc_BattleScene[]  = _("Choose between seeing or not\n{PKMN} battle animations.");
static const u8 sText_Desc_BattleStyle[]  = _("Choose between battle rules on\nreplacing a fallen {PKMN}.");
static const u8 sText_Desc_SoundMode[]    = _("Choose the game's sound mode.");
static const u8 sText_Desc_ButtonMode[]   = _("Choose one of the three sets of\nbutton settings.");
static const u8 sText_Desc_Frame[]        = _("Choose the menu-window design.");
static const u8 sText_Desc_MessageColor[] = _("Choose the text-window color.");
static const u8 sText_Desc_Font[]         = _("Choose the font style.");
static const u8 sText_Desc_UnitSystem[]   = _("Choose the system of measurement\nfor physical descriptions.");
static const u8 sText_Desc_Clock[]        = _("Choose the menu's clock mode.");
static const u8 sText_Desc_PartyBox[]     = _("Choose to have {PKMN} automatically\nsent to your Boxes or not.");
static const u8 sText_Desc_Nickname[]     = _("Choose whether you wish to\nnickname a {PKMN} when you obtain it.");
static const u8 sText_Desc_Confirm[]      = _("Return to the game.");

static const u8 *const sOptionMenuItemDescriptionsGame[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]     = sText_Desc_TextSpeed,
    [MENUITEM_BATTLE_SCENE]  = sText_Desc_BattleScene,
    [MENUITEM_BATTLE_STYLE]  = sText_Desc_BattleStyle,
    [MENUITEM_SOUND_MODE]    = sText_Desc_SoundMode,
    [MENUITEM_BUTTON_MODE]   = sText_Desc_ButtonMode,
    [MENUITEM_FRAME_TYPE]    = sText_Desc_Frame,
    [MENUITEM_MESSAGE_COLOR] = sText_Desc_MessageColor,
    [MENUITEM_FONT]          = sText_Desc_Font,
    [MENUITEM_UNIT_SYSTEM]   = sText_Desc_UnitSystem,
    [MENUITEM_CLOCK]         = sText_Desc_Clock,
    //[MENUITEM_PARTY_BOX]     = sText_Desc_PartyBox,
    [MENUITEM_NICKNAME]      = sText_Desc_Nickname,
    [MENUITEM_CONFIRM]       = sText_Desc_Confirm
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case 0:
        selection = sOptions->sel[menuItem];  
            return sOptionMenuItemDescriptionsGame[menuItem];
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
        case 0:
            return MENUITEM_COUNT;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case 0:
        return MENUITEM_CONFIRM;
    }
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void DrawTopBarText(void)
{
    const u8 color[3] = { 0, 2, 3 };
    //u8 x = GetStringRightAlignXOffset(FONT_SMALL, sText_TopBar_Right, 112);
    //
    //FillWindowPixelBuffer(WIN_TOPBAR_LEFT, PIXEL_FILL(15));
    //FillWindowPixelBuffer(WIN_TOPBAR_RIGHT, PIXEL_FILL(15));
    //switch (sOptions->submenu)
    //{
    //    case MENU_GAME:
    //        AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Game);
    //        break;
    //    case MENU_SOUND:
    //        AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Sound);
    //        break;
    //    case MENU_BATTLE:
    //        AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Battle);
    //        break;
    //    case MENU_BREEDING:
    //        AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Breeding);
    //        break;
    //}
    //AddTextPrinterParameterized3(WIN_TOPBAR_RIGHT, FONT_SMALL, x, 1, color, 0, sText_TopBar_Right);
    //PutWindowTilemap(WIN_TOPBAR_LEFT);
    //CopyWindowToVram(WIN_TOPBAR_LEFT, COPYWIN_FULL);
    //PutWindowTilemap(WIN_TOPBAR_RIGHT);
    //CopyWindowToVram(WIN_TOPBAR_RIGHT, COPYWIN_FULL);
    
    FillWindowPixelBuffer(WIN_TOPBAR_LEFT, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_TOPBAR_RIGHT, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_OPTION, 16, 1, color, 0, sText_TopBar_Options);
    PutWindowTilemap(WIN_TOPBAR_LEFT);
    CopyWindowToVram(WIN_TOPBAR_LEFT, COPYWIN_FULL);
    PutWindowTilemap(WIN_TOPBAR_RIGHT);
    CopyWindowToVram(WIN_TOPBAR_RIGHT, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void) //left side text
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < MenuItemCount(); i++)
        DrawLeftSideOptionText(i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_OPTION, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
    color_yellow[2] = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_OPTION, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_OPTION, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 choosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_RED_DARK_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_RED_DARK_SHADOW;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }


    if (choosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_OPTION, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_OPTION, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    switch (sOptions->submenu)
    {
        case 0:
            if (sItemFunctionsGame[id].drawChoices != NULL)
                sItemFunctionsGame[id].drawChoices(sOptions->sel[id], y);
            break;
    }
}

static void HighlightOptionMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

void CB2_InitOptionMenu(void)
{
    u8 windowColor = gSaveBlock2Ptr->optionsMessageColor;
    u32 i, taskId;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void*)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ResetBgPositions();
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(GetWindowAttribute(WIN_DESCRIPTION, WINDOW_BG), gMessageBox_Gfx, 0x1C0, 436);
        LoadPalette(GetWindowPal(windowColor), 0x90, 0x20);
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, 0, sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, 16, sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions = AllocZeroed(sizeof(*sOptions));

        sOptions->sel[MENUITEM_TEXTSPEED]     = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENUITEM_BATTLE_SCENE]  = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel[MENUITEM_BATTLE_STYLE]  = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel[MENUITEM_SOUND_MODE]    = gSaveBlock2Ptr->optionsSound;
        sOptions->sel[MENUITEM_BUTTON_MODE]   = gSaveBlock2Ptr->optionsButtonMode;
        sOptions->sel[MENUITEM_FRAME_TYPE]    = gSaveBlock2Ptr->optionsWindowFrameType;
        sOptions->sel[MENUITEM_MESSAGE_COLOR] = gSaveBlock2Ptr->optionsMessageColor;
        sOptions->sel[MENUITEM_FONT]          = gSaveBlock2Ptr->optionsFont;
        sOptions->sel[MENUITEM_UNIT_SYSTEM]   = gSaveBlock2Ptr->optionsUnitSystem;
        sOptions->sel[MENUITEM_CLOCK]         = gSaveBlock2Ptr->options24HourClock;
        //sOptions->sel[MENUITEM_PARTY_BOX]     = gSaveBlock2Ptr->optionsPartyBox;
        sOptions->sel[MENUITEM_NICKNAME]      = gSaveBlock2Ptr->optionsNickname;

        sOptions->submenu = MENU_GAME;

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR_LEFT);
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_TOPBAR_RIGHT);
        DrawTopBarText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 10:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 11:
        taskId = CreateTask(Task_OptionMenuFadeIn, 0);
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_COUNT - 1, 110, 110, 0);

        for (i = 0; i < OPTIONS_ON_SCREEN; i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 12:
        DrawBgWindowFramesOptions();
        gMain.state++;
        break;
    case 13:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    int i, scrollCount = 0, itemsToRedraw;
    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 3;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = 4;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == 3) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = 3;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 4;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        if (sOptions->submenu == 0)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsGame[cursor].processInput != NULL)
                {
                    sOptions->sel[cursor] = sItemFunctionsGame[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        //else if (sOptions->submenu == MENU_SOUND)
        //{
        //    int cursor = sOptions->menuCursor[sOptions->submenu];
        //    u8 previousOption = sOptions->sel_sound[cursor];
        //    if (CheckConditions(cursor))
        //    {
        //        if (sItemFunctionsSound[cursor].processInput != NULL)
        //        {
        //            sOptions->sel_sound[cursor] = sItemFunctionsSound[cursor].processInput(previousOption);
        //            ReDrawAll();
        //            DrawDescriptionText();
        //        }
        //
        //        if (previousOption != sOptions->sel_sound[cursor])
        //            DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
        //    }
        //}
        //else if (sOptions->submenu == MENU_BATTLE)
        //{
        //    int cursor = sOptions->menuCursor[sOptions->submenu];
        //    u8 previousOption = sOptions->sel_battle[cursor];
        //    if (CheckConditions(cursor))
        //    {
        //        if (sItemFunctionsBattle[cursor].processInput != NULL)
        //        {
        //            sOptions->sel_battle[cursor] = sItemFunctionsBattle[cursor].processInput(previousOption);
        //            ReDrawAll();
        //            DrawDescriptionText();
        //        }
        //
        //        if (previousOption != sOptions->sel_battle[cursor])
        //            DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
        //    }
        //}
        //else if (sOptions->submenu == MENU_BREEDING)
        //{
        //    int cursor = sOptions->menuCursor[sOptions->submenu];
        //    u8 previousOption = sOptions->sel_breeding[cursor];
        //    if (CheckConditions(cursor))
        //    {
        //        if (sItemFunctionsBreeding[cursor].processInput != NULL)
        //        {
        //            sOptions->sel_breeding[cursor] = sItemFunctionsBreeding[cursor].processInput(previousOption);
        //            ReDrawAll();
        //            DrawDescriptionText();
        //        }
        //
        //        if (previousOption != sOptions->sel_breeding[cursor])
        //            DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
        //    }
        //}
    }
    //else if (JOY_NEW(R_BUTTON))
    //{
    //    if (sOptions->submenu != LAST_MENU)
    //        sOptions->submenu++;
    //    else
    //        sOptions->submenu = MENU_GAME;
    //
    //    DrawTopBarText();
    //    ReDrawAll();
    //    HighlightOptionMenuItem();
    //    DrawDescriptionText();
    //}
    //else if (JOY_NEW(L_BUTTON))
    //{
    //    if (sOptions->submenu != MENU_GAME)
    //        sOptions->submenu--;
    //    else
    //        sOptions->submenu = LAST_MENU;
    //    
    //    DrawTopBarText();
    //    ReDrawAll();
    //    HighlightOptionMenuItem();
    //    DrawDescriptionText();
    //}
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed       = sOptions->sel[MENUITEM_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff  = sOptions->sel[MENUITEM_BATTLE_SCENE];
    gSaveBlock2Ptr->optionsBattleStyle     = sOptions->sel[MENUITEM_BATTLE_STYLE];
    gSaveBlock2Ptr->optionsSound           = sOptions->sel[MENUITEM_SOUND_MODE];
    gSaveBlock2Ptr->optionsButtonMode      = sOptions->sel[MENUITEM_BUTTON_MODE];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptions->sel[MENUITEM_FRAME_TYPE];
    gSaveBlock2Ptr->optionsMessageColor    = sOptions->sel[MENUITEM_MESSAGE_COLOR];
    gSaveBlock2Ptr->optionsFont            = sOptions->sel[MENUITEM_FONT];
    gSaveBlock2Ptr->optionsUnitSystem      = sOptions->sel[MENUITEM_UNIT_SYSTEM];
    gSaveBlock2Ptr->options24HourClock     = sOptions->sel[MENUITEM_CLOCK];
    //gSaveBlock2Ptr->optionsPartyBox        = sOptions->sel[MENUITEM_PARTY_BOX];
    gSaveBlock2Ptr->optionsNickname     = sOptions->sel[MENUITEM_NICKNAME];

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = OPTIONS_ON_SCREEN - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;

    scrollCount = MenuItemCount() - OPTIONS_ON_SCREEN;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = OPTIONS_ON_SCREEN - scrollCount;
        if (y < 0)
            y = OPTIONS_ON_SCREEN;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = OPTIONS_ON_SCREEN - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int ProcessInput_Options_Two(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ProcessInput_Options_Three(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static const u16 *GetWindowPal(int selection)
{
    switch (selection)
    {
        case 0:
            return gMessageBoxRed_Pal;
            break;
        case 1:
            return gMessageBoxBlue_Pal;
            break;
        case 2:
            return gMessageBoxGreen_Pal;
            break;
        case 3:
        default:
            return gMessageBoxYellow_Pal;
            break;
    }
}

static int ProcessInput_Options_MessageColor(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (4 - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (4 - 1);
    }

    LoadBgTiles(GetWindowAttribute(WIN_DESCRIPTION, WINDOW_BG), gMessageBox_Gfx, 0x1C0, 436);
    LoadPalette(GetWindowPal(selection), 0x90, 0x20);
    DrawBgWindowFramesDescription();
    return selection;
}

static int ProcessInput_Options_Four(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int ProcessInput_Options_Font(int selection)
{
    gSaveBlock2Ptr->optionsFont = XOptions_ProcessInput(4, selection);
    return gSaveBlock2Ptr->optionsFont;
}

static int ProcessInput_Options_Eleven(int selection)
{
    return XOptions_ProcessInput(11, selection);
}

// Process Input functions ****SPECIFIC****
static int ProcessInput_Sound(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }

    return selection;
}

static int ProcessInput_FrameType(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 choosen = FALSE;
    if (style != 0)
        choosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, choosen, active);
}

static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 i;

    if (MenuItemCount() <= 5) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId == TASK_NONE)
            sOptions->arrowTaskId = sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < OPTIONS_ON_SCREEN; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
    DrawTopBarText();
}

// Process Input functions ****SPECIFIC****
static const u8 *const sTextSpeedStrings[] = {sText_TextSpeedSlow, sText_TextSpeedMid, sText_TextSpeedFast};
static void DrawChoices_TextSpeed(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_TextSpeedSlow, sText_TextSpeedMid, sText_TextSpeedFast);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_TextSpeedSlow, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_TextSpeedMid, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_TextSpeedFast, GetStringRightAlignXOffset(1, sText_TextSpeedFast, 198), y, styles[2], TRUE);
}

static void DrawChoices_BattleScene(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOn, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionOff, GetStringRightAlignXOffset(FONT_OPTION, sText_OptionOff, 198), y, styles[1], TRUE);
}

static void DrawChoices_BattleStyle(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_BattleStyleShift, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_BattleStyleSet, GetStringRightAlignXOffset(FONT_OPTION, sText_BattleStyleSet, 198), y, styles[1], TRUE);
}

static void DrawChoices_Sound(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_SoundMono, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_SoundStereo, GetStringRightAlignXOffset(FONT_OPTION, sText_SoundStereo, 198), y, styles[1], TRUE);
}

static void DrawChoices_ButtonMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BUTTON_MODE);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_ButtonTypeNormal, sText_ButtonTypeLR, sText_ButtonTypeLEqualsA);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_ButtonTypeNormal, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_ButtonTypeLR, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(1, sText_ButtonTypeLEqualsA, 198), y, styles[2], active);
}

static void DrawChoices_MessageColor(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_FRAME_TYPE);

    switch (selection)
    {
        case 0:
            DrawOptionMenuChoice(sText_OptionRed, 104, y, 1, active);
            break;
        case 1:
            DrawOptionMenuChoice(sText_OptionBlue, 104, y, 1, active);
            break;
        case 2:
            DrawOptionMenuChoice(sText_OptionGreen, 104, y, 1, active);
            break;
        case 3:
            DrawOptionMenuChoice(sText_OptionYellow, 104, y, 1, active);
            break;
    }
}

static void DrawChoices_PartyBox(int selection, int y)
{
    u8 styles[3] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionManual, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionAutomatic, GetStringRightAlignXOffset(1, sText_OptionAutomatic, 198), y, styles[1], TRUE);
}

static void DrawChoices_UnitSystem(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_UNIT_SYSTEM);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_UnitSystemImperial, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_UnitSystemMetric, GetStringRightAlignXOffset(1, sText_UnitSystemMetric, 198), y, styles[1], active);
}

static void DrawChoices_FrameType(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_FRAME_TYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; sText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = sText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(sText_FrameType, 104, y, 0, active);
    DrawOptionMenuChoice(text, 131, y, 1, active);
}

static void DrawChoices_Font(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_FRAME_TYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; sText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = sText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(sText_FrameType, 104, y, 0, active);
    DrawOptionMenuChoice(text, 131, y, 1, active);
}

static void DrawChoices_Nickname(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionGive, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionDontGive, GetStringRightAlignXOffset(1, sText_OptionDontGive, 198), y, styles[1], TRUE);
}

static void DrawChoices_OnOff(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_CLOCK);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_OptionOff, GetStringRightAlignXOffset(1, sText_OptionOff, 198), y, styles[1], active);
}

// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

#define WINDOW_NPC_OFFSET (TILE_TOP_CORNER_L + 19)

static void DrawBgWindowFramesOptions(void)
{
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,   1,   2,  1,  1, 7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,       2,   2, 26,  1, 7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R,   28,  2,  1,  1, 7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE ,      1,   3,  1, 10,7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,     28,  3,  1, 10, 7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,   1,  13,  1,  1, 7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,       2,  13, 26,  1, 7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R,   28, 13,  1,  1, 7);

    DrawBgWindowFramesDescription();
}

static void DrawBgWindowFramesDescription(void)
{
    // Description window
    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET,                       1 , 14,  1, 1, 9);
    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 2,                   2,  14,  1, 1, 9);
    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 3 ,                  3,  14, 24, 1, 9);
    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 4,                   27 , 14,  1, 1, 9);
    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 5,                   28,  14,  1, 1, 9);

    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 6,                    1 , 15,  1, 4, 9);

    FillBgTilemapBufferRect(1, WINDOW_NPC_OFFSET + 9,                    28 , 15,  1, 4, 9);

    FillBgTilemapBufferRect(1, BG_TILE_V_FLIP(WINDOW_NPC_OFFSET + 2),   2,  19, 24, 1, 9);
    FillBgTilemapBufferRect(1, BG_TILE_V_FLIP(WINDOW_NPC_OFFSET + 3),   3,  19, 24, 1, 9);
    FillBgTilemapBufferRect(1, BG_TILE_V_FLIP(WINDOW_NPC_OFFSET),       1 , 19,  1, 1, 9);
    FillBgTilemapBufferRect(1, BG_TILE_V_FLIP(WINDOW_NPC_OFFSET + 4),   27 , 19,  1, 1, 9);
    FillBgTilemapBufferRect(1, BG_TILE_V_FLIP(WINDOW_NPC_OFFSET + 5),   28,  19,  1, 1, 9);

    CopyBgTilemapBufferToVram(1);
}

void SkipNickname(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->optionsNickname;
}
