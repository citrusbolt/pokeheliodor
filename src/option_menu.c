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
    MENUITEM_GAME_TEXTSPEED,
    MENUITEM_GAME_BUTTONMODE,
    MENUITEM_GAME_FRAMETYPE,
    MENUITEM_GAME_FAVCOLOR,
    MENUITEM_GAME_FONT,
    MENUITEM_GAME_UNIT_SYSTEM,
    MENUITEM_GAME_FOLLOWER_PKMN,
    MENUITEM_GAME_SUMMARY_SCREEN,
    MENUITEM_GAME_START_MENU,
    MENUITEM_GAME_MATCHCALL,
    MENUITEM_GAME_FISHREELING,
    MENUITEM_GAME_SHINY,
    MENUITEM_DIFFICULTY_SCALING_IVS,
    MENUITEM_DIFFICULTY_SCALING_EVS,
    MENUITEM_GAME_CANCEL,
    MENUITEM_GAME_COUNT
};

enum
{
    MENUITEM_SOUND_MODE,
    MENUITEM_SOUND_SURF,
    MENUITEM_SOUND_BIKE,
    MENUITEM_SOUND_WILD,
    MENUITEM_SOUND_TRAINER,
    MENUITEM_SOUND_GRASS,
    MENUITEM_SOUND_CANCEL,
    MENUITEM_SOUND_COUNT
};

enum
{
    MENUITEM_BATTLE_PSS,
    //MENUITEM_BATTLE_DIFFICULTY,
    MENUITEM_BATTLE_FRIENSHIP_BONUS,
    MENUITEM_BATTLE_GLOBAL_EXP,
    MENUITEM_BATTLE_EXP_MULTIPLIER,
    MENUITEM_BATTLE_LAST_BALL,
    MENUITEM_BATTLE_TYPE_ICONS,
    MENUITEM_BATTLE_SCENE,
    MENUITEM_BATTLE_STYLE,
    MENUITEM_BATTLE_INTRO,
    MENUITEM_BATTLE_HP_BAR,
    MENUITEM_BATTLE_EXP_BAR,
    MENUITEM_BATTLE_CANCEL,
    MENUITEM_BATTLE_COUNT,
};

enum
{
    MENUITEM_BREEDING_IVS,
    MENUITEM_BREEDING_MASUDA,
    MENUITEM_BREEDING_SHINY_CHARM,
    MENUITEM_BREEDING_OVAL_CHARM,
    MENUITEM_BREEDING_EVERSTONE,
    MENUITEM_BREEDING_CANCEL,
    MENUITEM_BREEDING_COUNT
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
    u8 sel[MENUITEM_GAME_COUNT];
    u8 sel_sound[MENUITEM_SOUND_COUNT];
    u8 sel_battle[MENUITEM_BATTLE_COUNT];
    u8 sel_breeding[MENUITEM_BREEDING_COUNT];
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
static void DrawChoices_WindowColor(int selection, int y);
static void DrawChoices_SurfBikeBGM(int selection, int y);
static void DrawChoices_UnitSystem(int selection, int y);
static void DrawChoices_FollowerPkmn(int selection, int y);
static void DrawChoices_StartMenu(int selection, int y);
static void DrawChoices_EmeraldFRLG(int selection, int y);
static void DrawChoices_HoennKanto(int selection, int y);
static void DrawChoices_GrassSound(int selection, int y);
static void DrawChoices_ChallengeMode(int selection, int y);
static void DrawChoices_FrameType(int selection, int y);
static void DrawChoices_OnOff(int selection, int y);
static void DrawChoices_OffOn(int selection, int y);
static void DrawChoices_35(int selection, int y);
static void DrawChoices_NormalFast(int selection, int y);
static void DrawBgWindowFramesOptions(void);
static int ProcessInput_Options_FavColor(int selection);
static void DrawBgWindowFramesDescription(void);
static const u16 * GetWindowPal(int selection);
static void DrawChoices_Challenges_ExpMultiplier(int selection, int y);
static void DrawChoices_Challenges_ScalingIVs(int selection, int y);
static void DrawChoices_Challenges_ScalingEVs(int selection, int y);

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;

// const data
static const u16 sOptionMenuBg_Pal[] = {RGB(15, 22, 15)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

// Options names
static const u8 sText_TextSpeed[]       = _("TEXT SPEED");
static const u8 sText_ButtonMode[]      = _("BUTTON MODE");
static const u8 sText_Frame[]           = _("MENU FRAME");
static const u8 sText_FavColor[]        = _("FAV COLOR");
static const u8 sText_Font[]            = _("FONT");
static const u8 sText_UnitSystem[]      = _("UNIT SYSTEM");
static const u8 sText_FollowerPkmn[]    = _("FOLLOWER {PKMN}");
static const u8 sText_StartMenu[]       = _("START MENU");
static const u8 sText_OverworldCalls[]  = _("OVERWORLD CALLS");
static const u8 sText_FishReeling[]     = _("FISHING STYLE");
static const u8 sText_Sound[]           = _("SOUND");
static const u8 sText_Surf[]            = _("SURF BGM");
static const u8 sText_Bike[]            = _("BIKE BGM");
static const u8 sText_Wild[]            = _("WILD {PKMN} BGM");
static const u8 sText_Trainer[]         = _("TRAINER BGM");
static const u8 sText_Grass[]           = _("GRASS SOUND");
static const u8 sText_BattleScene[]     = _("BATTLE SCENE");
static const u8 sText_BattleStyle[]     = _("BATTLE STYLE");
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
static const u8 sText_TextSpeedMid[]        = _("MID");
static const u8 sText_TextSpeedFast[]       = _("FAST");
static const u8 sText_Faster[]              = _("FASTER");
static const u8 sText_ButtonTypeNormal[]    = _("NORMAL");
static const u8 sText_ButtonTypeLR[]        = _("LR");
static const u8 sText_ButtonTypeLEqualsA[]  = _("L=A");
static const u8 sText_FrameType[]           = _("TYPE");
static const u8 sText_OptionEmerald[]       = _("EMERALD");
static const u8 sText_OptionFRLG[]          = _("FRLG");
static const u8 sText_UnitSystemImperial[]  = _("IMPERIAL");
static const u8 sText_UnitSystemMetric[]    = _("METRIC");
static const u8 sText_OptionOff[]           = _("OFF");
static const u8 sText_OptionOn[]            = _("ON");
static const u8 sText_OptionKanto[]         = _("KANTO");
static const u8 sText_OptionHoenn[]         = _("HOENN");
static const u8 sText_OptionPlayer[]        = _("PLAYER");
static const u8 sText_OptionMenuSave[]      = _("SAVE");
static const u8 sText_BattleStyleShift[]    = _("SHIFT");
static const u8 sText_BattleStyleSet[]      = _("SET");
static const u8 sText_SoundMono[]           = _("MONO");
static const u8 sText_SoundStereo[]         = _("STEREO");
static const u8 sText_OptionGreen[]         = _("GREEN");
static const u8 sText_OptionRed[]           = _("RED");
static const u8 sText_OptionBlue[]          = _("BLUE");
static const u8 sText_OptionHard[]          = _("HARD");
static const u8 sText_OptionCustom[]        = _("CUSTOM");
static const u8 sText_FrameTypeNumber[]     = _("");
static const u8 sText_Option3[]             = _("3");
static const u8 sText_Option5[]             = _("5");

// Header text
static const u8 sText_TopBar_Game[]     = _("{OPTION_BIG_DOT} {OPTION_SMALL_DOT} {OPTION_SMALL_DOT} {OPTION_SMALL_DOT} GAME OPTIONS");
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

static const u8 sText_ScalingIVsEVs_Scaling[]   = _("SCALE");
static const u8 sText_ScalingIVsEVs_Hard[]      = _("HARD");
static const u8 sText_OptionYes[] = _("YES");

static void DrawChoices_Challenges_ScalingIVs(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_OptionOff, sText_ScalingIVsEVs_Scaling, sText_ScalingIVsEVs_Hard);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionYes, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_ScalingIVsEVs_Scaling, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_ScalingIVsEVs_Hard, GetStringRightAlignXOffset(1, sText_ScalingIVsEVs_Hard, 198), y, styles[2], TRUE);
}

static const u8 sText_ScalingIVsEVs_Extrem[]    = _("HARDER");
static const u8 *const sText_ScalingEVs_Strings[] = {sText_OptionYes, sText_ScalingIVsEVs_Scaling, sText_ScalingIVsEVs_Hard, sText_ScalingIVsEVs_Extrem};
static void DrawChoices_Challenges_ScalingEVs(int selection, int y)
{
    DrawChoices_Options_Four(sText_ScalingEVs_Strings, selection, y, TRUE);
}

// Menu draw and input functions
struct
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
}

static const sItemFunctionsGame[MENUITEM_GAME_COUNT] =
{
    [MENUITEM_GAME_TEXTSPEED]       = {DrawChoices_TextSpeed,       ProcessInput_Options_Four},
    [MENUITEM_GAME_BUTTONMODE]      = {DrawChoices_ButtonMode,      ProcessInput_Options_Three},
    [MENUITEM_GAME_FRAMETYPE]       = {DrawChoices_FrameType,       ProcessInput_FrameType},
    [MENUITEM_GAME_FAVCOLOR]        = {DrawChoices_WindowColor,     ProcessInput_Options_FavColor},
    [MENUITEM_GAME_FONT]            = {DrawChoices_EmeraldFRLG,     ProcessInput_Options_Two}, 
    [MENUITEM_GAME_UNIT_SYSTEM]     = {DrawChoices_UnitSystem,      ProcessInput_Options_Two},
    [MENUITEM_GAME_FOLLOWER_PKMN]   = {DrawChoices_FollowerPkmn,    ProcessInput_Options_Two},
    [MENUITEM_GAME_SUMMARY_SCREEN]  = {DrawChoices_StartMenu,       ProcessInput_Options_Two},
    [MENUITEM_GAME_START_MENU]      = {DrawChoices_StartMenu,       ProcessInput_Options_Two},
    [MENUITEM_GAME_MATCHCALL]       = {DrawChoices_OnOff,           ProcessInput_Options_Two},
    [MENUITEM_GAME_FISHREELING]     = {DrawChoices_EmeraldFRLG,     ProcessInput_Options_Two},
    [MENUITEM_GAME_SHINY]           = {DrawChoices_OffOn,           ProcessInput_Options_Two},
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = {DrawChoices_Challenges_ScalingIVs,       ProcessInput_Options_Three},
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = {DrawChoices_Challenges_ScalingEVs,       ProcessInput_Options_Four},
    [MENUITEM_GAME_CANCEL]          = {NULL,                        NULL},
};

struct
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
}

static const sItemFunctionsSound[MENUITEM_SOUND_COUNT] =
{
    [MENUITEM_SOUND_MODE]       = {DrawChoices_Sound,       ProcessInput_Options_Two},
    [MENUITEM_SOUND_SURF]       = {DrawChoices_SurfBikeBGM, ProcessInput_Options_Three},
    [MENUITEM_SOUND_BIKE]       = {DrawChoices_SurfBikeBGM, ProcessInput_Options_Three},
    [MENUITEM_SOUND_WILD]       = {DrawChoices_HoennKanto,  ProcessInput_Options_Two},
    [MENUITEM_SOUND_TRAINER]    = {DrawChoices_HoennKanto,  ProcessInput_Options_Two},
    [MENUITEM_SOUND_GRASS]      = {DrawChoices_GrassSound,  ProcessInput_Options_Three},
    [MENUITEM_SOUND_CANCEL]     = {NULL, NULL},
};

struct
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
}

static const sItemFunctionsBattle[MENUITEM_BATTLE_COUNT] =
{
    [MENUITEM_BATTLE_SCENE]             = {DrawChoices_BattleScene, ProcessInput_Options_Two},
    [MENUITEM_BATTLE_STYLE]             = {DrawChoices_BattleStyle, ProcessInput_Options_Two},
    [MENUITEM_BATTLE_INTRO]             = {DrawChoices_OffOn,       ProcessInput_Options_Two},
    [MENUITEM_BATTLE_HP_BAR]            = {DrawChoices_NormalFast,  ProcessInput_Options_Two},
    [MENUITEM_BATTLE_EXP_BAR]           = {DrawChoices_NormalFast,  ProcessInput_Options_Two},
    [MENUITEM_BATTLE_LAST_BALL]         = {DrawChoices_OnOff,       ProcessInput_Options_Two},
    [MENUITEM_BATTLE_TYPE_ICONS]        = {DrawChoices_OffOn,       ProcessInput_Options_Two},
    [MENUITEM_BATTLE_FRIENSHIP_BONUS]   = {DrawChoices_OnOff,       ProcessInput_Options_Two},
    [MENUITEM_BATTLE_GLOBAL_EXP]        = {DrawChoices_OffOn,       ProcessInput_Options_Two},
    [MENUITEM_BATTLE_EXP_MULTIPLIER]    = {DrawChoices_Challenges_ExpMultiplier,    ProcessInput_Options_Four},
    [MENUITEM_BATTLE_PSS]               = {DrawChoices_OffOn,       ProcessInput_Options_Two},
    //[MENUITEM_BATTLE_DIFFICULTY]        = {DrawChoices_ChallengeMode,  ProcessInput_Options_Three},
    [MENUITEM_BATTLE_CANCEL]            = {NULL, NULL},
};

struct
{
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
}

static const sItemFunctionsBreeding[MENUITEM_BREEDING_COUNT] =
{
    [MENUITEM_BREEDING_IVS]         = {DrawChoices_35,      ProcessInput_Options_Two},
    [MENUITEM_BREEDING_MASUDA]      = {DrawChoices_OffOn,   ProcessInput_Options_Two},
    [MENUITEM_BREEDING_SHINY_CHARM] = {DrawChoices_OffOn,   ProcessInput_Options_Two},
    [MENUITEM_BREEDING_OVAL_CHARM]  = {DrawChoices_OffOn,   ProcessInput_Options_Two},
    [MENUITEM_BREEDING_EVERSTONE]   = {DrawChoices_OffOn,   ProcessInput_Options_Two},
    [MENUITEM_BREEDING_CANCEL]      = {NULL, NULL},
};

static const u8 sText_ScalingIVs[]          = _("TRAINER IVs");
static const u8 sText_ScalingEVs[]          = _("TRAINER EVs");

// Menu left side option names text
static const u8 *const sOptionMenuItemsNamesGame[MENUITEM_GAME_COUNT] =
{
    [MENUITEM_GAME_TEXTSPEED]       = sText_TextSpeed,
    [MENUITEM_GAME_BUTTONMODE]      = sText_ButtonMode,
    [MENUITEM_GAME_FRAMETYPE]       = sText_Frame,
    [MENUITEM_GAME_FAVCOLOR]        = sText_FavColor,
    [MENUITEM_GAME_FONT]            = sText_Font,
    [MENUITEM_GAME_UNIT_SYSTEM]     = sText_UnitSystem,
    [MENUITEM_GAME_FOLLOWER_PKMN]   = sText_FollowerPkmn,
    [MENUITEM_GAME_SUMMARY_SCREEN]  = sText_SummaryScreen,
    [MENUITEM_GAME_START_MENU]      = sText_StartMenu,
    [MENUITEM_GAME_MATCHCALL]       = sText_OverworldCalls,
    [MENUITEM_GAME_FISHREELING]     = sText_FishReeling,
    [MENUITEM_GAME_SHINY]           = sText_NewShiny,
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = sText_ScalingIVs,
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = sText_ScalingEVs,
    [MENUITEM_GAME_CANCEL]          = sText_OptionMenuSave,
};

static const u8 *const sOptionMenuItemsNamesSound[MENUITEM_SOUND_COUNT] =
{
    [MENUITEM_SOUND_MODE]       = sText_Sound,
    [MENUITEM_SOUND_SURF]       = sText_Surf,
    [MENUITEM_SOUND_BIKE]       = sText_Bike,
    [MENUITEM_SOUND_WILD]       = sText_Wild,
    [MENUITEM_SOUND_TRAINER]    = sText_Trainer,
    [MENUITEM_SOUND_GRASS]      = sText_Grass,
    [MENUITEM_SOUND_CANCEL]     = sText_OptionMenuSave,
};

static const u8 *const sOptionMenuItemsNamesBattle[MENUITEM_BATTLE_COUNT] =
{
    [MENUITEM_BATTLE_SCENE]             = sText_BattleScene,
    [MENUITEM_BATTLE_STYLE]             = sText_BattleStyle,
    [MENUITEM_BATTLE_INTRO]             = sText_BattleIntro,
    [MENUITEM_BATTLE_HP_BAR]            = sText_HpBar,
    [MENUITEM_BATTLE_EXP_BAR]           = sText_ExpBar,
    [MENUITEM_BATTLE_LAST_BALL]         = sText_LastBall,
    [MENUITEM_BATTLE_TYPE_ICONS]        = sText_TypeIcons,
    [MENUITEM_BATTLE_FRIENSHIP_BONUS]   = sText_FriendshipBonus,
    [MENUITEM_BATTLE_GLOBAL_EXP]        = sText_GlobalExp,
    [MENUITEM_BATTLE_EXP_MULTIPLIER]    = sText_ExpMultiplier,
    [MENUITEM_BATTLE_PSS]               = sText_Pss,
    //[MENUITEM_BATTLE_DIFFICULTY] = sText_Difficulty,
    [MENUITEM_BATTLE_CANCEL]    = sText_OptionMenuSave,
};

static const u8 *const sOptionMenuItemsNamesBreeding[MENUITEM_BREEDING_COUNT] =
{
    [MENUITEM_BREEDING_IVS]         = sText_BreedingIvs,
    [MENUITEM_BREEDING_MASUDA]      = sText_Masuda,
    [MENUITEM_BREEDING_SHINY_CHARM] = sText_ShinyCharm,
    [MENUITEM_BREEDING_OVAL_CHARM]  = sText_OvalCharm,
    [MENUITEM_BREEDING_EVERSTONE]   = sText_Everstone,
    [MENUITEM_BREEDING_CANCEL]      = sText_OptionMenuSave,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
        case MENU_GAME:
            return sOptionMenuItemsNamesGame[menuItem];
        case MENU_SOUND:
            return sOptionMenuItemsNamesSound[menuItem];
        case MENU_BATTLE:
            return sOptionMenuItemsNamesBattle[menuItem];
        case MENU_BREEDING:
            return sOptionMenuItemsNamesBreeding[menuItem];     
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
static const u8 sText_Desc_TextSpeed[]               = _("Choose one of the four text-display\nspeeds.");
static const u8 sText_Desc_ButtonMode[]             = _("Choose one of the three sets of\nbutton options.");
static const u8 sText_Desc_FrameType[]              = _("Choose the text-window design.");
static const u8 sText_Desc_UnitSystemImperial[]     = _("Displays BERRY and POKéMON weight\nand size in pounds and inches.");
static const u8 sText_Desc_UnitSystemMetric[]       = _("Displays BERRY and POKéMON weight\nand size in kilograms and meters.");
static const u8 sText_Desc_FontType[]               = _("Choose the font design.");
static const u8 sText_Desc_FollowerPkmn[]           = _("Choose if the POKéMON follows you.\nForced to ON in nuzlocke mode.");
static const u8 sText_Desc_OverworldCallsOn[]       = _("TRAINERs will be able to call you,\noffering rematches and info.");
static const u8 sText_Desc_OverworldCallsOff[]      = _("You will not receive calls.\nSpecial events will still occur.");
static const u8 sText_Desc_FishingStyleEmerald[]    = _("You have to time the pressing of\nthe A button to get the encounter.");
static const u8 sText_Desc_FishingStyleFRLG[]       = _("You will know when the encounter\nis ready. No timing required!");
static const u8 sText_Desc_CustomShiny[]            = _("Choose if you want alternate\nshiny sprites.");
static const u8 sText_Desc_StartMenu[]              = _("Choose which START MENU UI you\nwould like to see.");
static const u8 sText_Desc_SummaryScreen[]          = _("Choose which POKéMON SUMMARY UI\nyou would like to see.");
// Sound
static const u8 sText_Desc_SoundMono[]      = _("Sound is the same in all speakers.\nRecommended for original hardware.");
static const u8 sText_Desc_SoundStereo[]    = _("You will be able to notice the\nleft and right audio channel.");
static const u8 sText_Desc_SurfOff[]        = _("Disables the SURF theme when\nusing SURF.");
static const u8 sText_Desc_SurfOn[]         = _("Enables the HOENN SURF theme\nwhen using SURF.");
static const u8 sText_Desc_SurfFRLG[]       = _("Enables the KANTO SURF theme\nwhen using SURF.");
static const u8 sText_Desc_BikeOff[]        = _("Disables the BIKE theme when\nusing the BIKE.");
static const u8 sText_Desc_BikeOn[]         = _("Enables the HOENN BIKE theme when\nusing the BIKE.");
static const u8 sText_Desc_BikeFRLG[]       = _("Enables the KANTO BIKE theme when\nusing the BIKE.");
static const u8 sText_Desc_WildHoenn[]      = _("Wild encounters will have the\nHOENN battle theme.");
static const u8 sText_Desc_WildKanto[]      = _("Wild encounters will have the\nKANTO battle theme.");
static const u8 sText_Desc_TrainerHoenn[]   = _("TRAINERs will have the HOENN\nbattle theme.");
static const u8 sText_Desc_TrainerKanto[]   = _("TRAINERs will have the KANTO\nbattle theme.");
static const u8 sText_Desc_GrassOff[]       = _("Nothing will make a noise when\nstepping on tall grass.");
static const u8 sText_Desc_GrassOn[]        = _("Everything will make a noise when\nstepping on tall grass.");
static const u8 sText_Desc_GrassPlayer[]    = _("Only you will make a noise when\nstepping on tall grass.");
// Battle
static const u8 sText_Desc_BattleScene[]    = _("Choose between seeing or not\nPOKéMON battle animations.");
static const u8 sText_Desc_BattleStyle[]    = _("Choose between battle rules on\nreplacing a POKéMON.");
static const u8 sText_Desc_BattleIntroOn[]  = _("POKéMON and TRAINERs will have the\nslide animation before battles.");
static const u8 sText_Desc_BattleIntroOff[] = _("POKéMON and TRAINERs will appear\nright away in the battles.");
static const u8 sText_Desc_BattleHPBar[]    = _("Choose how the HP BAR will get\ndrained in battles.");
static const u8 sText_Desc_BattleExpBar[]   = _("Choose how the EXP BAR will get\nfilled in battles.");
static const u8 sText_Desc_BattleLastBall[] = _("Choose if you want a shortcut\nfor the last used BALL.");
static const u8 sText_Desc_FriendshipBonuses_On[] = _("Choose if your POKéMON will be\neligible for friendship bonuses.");
static const u8 sText_Desc_FriendshipBonuses_Off[] = _("Choose if your POKéMON will be\neligible for friendship bonuses.");
static const u8 sText_Desc_WindowColor[] = _("Choose your favorite color.\nIt changes some interfaces.");
static const u8 sText_Description_TXC_ExpMultiplier_1_0[]        = _("POKéMON gain normal EXP. Points.");
static const u8 sText_Description_TXC_ExpMultiplier_1_5[]        = _("POKéMON gain extra half EXP. Points.");
static const u8 sText_Description_TXC_ExpMultiplier_2_0[]        = _("POKéMON gain double EXP. Points.");
static const u8 sText_Description_TXC_ExpMultiplier_0_0[]        = _("POKéMON don't gain EXP Points.");
static const u8 sText_Desc_PSS_Off[]    = _("The move type determines if\nit is Physical or Special.");
static const u8 sText_Desc_PSS_On[] = _("Moves don't depend on types to be\nPhysical or Special, like later gens.");
static const u8 sText_Desc_ChallengeMode[] = _("Makes GYM LEADERs, ELITE 4 members\nand CHAMPION have harder teams.");
static const u8 sText_Desc_TypeIcons[]  = _("Choose if you want to show icons\nfor POKéMON TYPEs in battle.");
static const u8 sText_Desc_GlobalExp[]  = _("Choose if you want all your {PKMN} to\nget EXP. POINTS. No ITEM required.");
// Breeding
static const u8 sText_Desc_BreedingIvs[]    = _("Choose if your {PKMN} inherit 3 or 5 IVS.\nDefeat the CHAMPION to make it work.");
static const u8 sText_Desc_Masuda[]         = _("Choose if you want to enable\nthe MASUDA method.");
static const u8 sText_Desc_ShinyCharm[]     = _("Choose if the SHINY CHARM works.\nITEM required to make it work.");
static const u8 sText_Desc_OvalCharm[]      = _("Choose if the OVAL CHARM works.\nITEM required to make it work.");
static const u8 sText_Desc_Everstone[]      = _("Choose if {PKMN} holding an EVERSTONE\nwill always pass down its nature.");

static const u8 sText_Description_TXC_ScalingIVs_Off[]           = _("The POKéMON of enemy Trainer have\nthe expected IVs.");
static const u8 sText_Description_TXC_ScalingIVs_Scaling[]       = _("The IVs of Trainer POKéMON increase\nwith gym badges!");
static const u8 sText_Description_TXC_ScalingIVs_Hard[]          = _("All Trainer POKéMON have perfect\nIVs!");
static const u8 sText_Description_TXC_ScalingEVs_Off[]           = _("The POKéMON of enemy Trainer have\nthe expected EVs.");
static const u8 sText_Description_TXC_ScalingEVs_Scaling[]       = _("The EVs of Trainer POKéMON increase\nwith gym badges!");
static const u8 sText_Description_TXC_ScalingEVs_Hard[]          = _("All Trainer POKéMON have high EVs!");
static const u8 sText_Description_TXC_ScalingEVs_Extreme[]       = _("All Trainer POKéMON have {COLOR 7}252 EVs!\nVery Hard!");

static const u8 *const sOptionMenuItemDescriptionsGame[MENUITEM_GAME_COUNT][4] =
{
    [MENUITEM_GAME_TEXTSPEED]       = {sText_Desc_TextSpeed,    NULL,   NULL,   NULL},
    [MENUITEM_GAME_BUTTONMODE]      = {sText_Desc_ButtonMode,   NULL,   NULL,   NULL},
    [MENUITEM_GAME_FRAMETYPE]       = {sText_Desc_FrameType,    NULL,   NULL,   NULL},
    [MENUITEM_GAME_FAVCOLOR]        = {sText_Desc_WindowColor,  NULL,   NULL, NULL},
    [MENUITEM_GAME_FONT]            = {sText_Desc_FontType,     NULL,   NULL,   NULL},
    [MENUITEM_GAME_UNIT_SYSTEM]     = {sText_Desc_UnitSystemImperial,   sText_Desc_UnitSystemMetric,    NULL,   NULL},
    [MENUITEM_GAME_FOLLOWER_PKMN]   = {sText_Desc_FollowerPkmn, NULL,     NULL,   NULL},
    [MENUITEM_GAME_SUMMARY_SCREEN]  = {sText_Desc_SummaryScreen,    NULL,     NULL,   NULL},
    [MENUITEM_GAME_START_MENU]      = {sText_Desc_StartMenu,    NULL,     NULL,   NULL},
    [MENUITEM_GAME_MATCHCALL]       = {sText_Desc_OverworldCallsOn,     sText_Desc_OverworldCallsOff,   NULL,   NULL},
    [MENUITEM_GAME_FISHREELING]     = {sText_Desc_FishingStyleEmerald,  sText_Desc_FishingStyleFRLG,    NULL, NULL},
    [MENUITEM_GAME_SHINY]           = {sText_Desc_CustomShiny,   NULL,    NULL, NULL},
    [MENUITEM_DIFFICULTY_SCALING_IVS]           = {sText_Description_TXC_ScalingIVs_Off,            sText_Description_TXC_ScalingIVs_Scaling,       sText_Description_TXC_ScalingIVs_Hard,      sText_Empty},
    [MENUITEM_DIFFICULTY_SCALING_EVS]           = {sText_Description_TXC_ScalingEVs_Off,            sText_Description_TXC_ScalingEVs_Scaling,       sText_Description_TXC_ScalingEVs_Hard,      sText_Description_TXC_ScalingEVs_Extreme},
    [MENUITEM_GAME_CANCEL]          = {sText_Save, NULL, NULL, NULL},
};

static const u8 *const sOptionMenuItemDescriptionsSound[MENUITEM_SOUND_COUNT][4] =
{
    [MENUITEM_SOUND_MODE]       = {sText_Desc_SoundMono,    sText_Desc_SoundStereo,     sText_Empty, NULL},
    [MENUITEM_SOUND_SURF]       = {sText_Desc_SurfOff,      sText_Desc_SurfOn,          sText_Desc_SurfFRLG, NULL},
    [MENUITEM_SOUND_BIKE]       = {sText_Desc_BikeOff,      sText_Desc_BikeOn,          sText_Desc_BikeFRLG, NULL},
    [MENUITEM_SOUND_WILD]       = {sText_Desc_WildHoenn,    sText_Desc_WildKanto,       NULL, NULL},
    [MENUITEM_SOUND_TRAINER]    = {sText_Desc_TrainerHoenn, sText_Desc_TrainerKanto,    NULL, NULL},
    [MENUITEM_SOUND_GRASS]      = {sText_Desc_GrassOff,     sText_Desc_GrassOn,         sText_Desc_GrassPlayer, NULL},
    [MENUITEM_SOUND_CANCEL]     = {sText_Save, NULL, NULL, NULL},
};

static const u8 *const sOptionMenuItemDescriptionsBattle[MENUITEM_BATTLE_COUNT][4] =
{
    [MENUITEM_BATTLE_SCENE]             = {sText_Desc_BattleScene,      NULL, NULL, NULL},
    [MENUITEM_BATTLE_STYLE]             = {sText_Desc_BattleStyle,      NULL, NULL, NULL},
    [MENUITEM_BATTLE_INTRO]             = {sText_Desc_BattleIntroOff,    sText_Desc_BattleIntroOn, NULL, NULL},
    [MENUITEM_BATTLE_HP_BAR]            = {sText_Desc_BattleHPBar,      NULL, NULL, NULL},
    [MENUITEM_BATTLE_EXP_BAR]           = {sText_Desc_BattleExpBar,     NULL, NULL, NULL},
    [MENUITEM_BATTLE_LAST_BALL]         = {sText_Desc_BattleLastBall,   NULL, NULL, NULL},
    [MENUITEM_BATTLE_TYPE_ICONS]        = {sText_Desc_TypeIcons,   NULL, NULL, NULL},
    [MENUITEM_BATTLE_FRIENSHIP_BONUS]   = {sText_Desc_FriendshipBonuses_On,   sText_Desc_FriendshipBonuses_Off, NULL, NULL},
    [MENUITEM_BATTLE_GLOBAL_EXP]        = {sText_Desc_GlobalExp,   NULL, NULL, NULL},
    [MENUITEM_BATTLE_EXP_MULTIPLIER]    = {sText_Description_TXC_ExpMultiplier_1_0,         sText_Description_TXC_ExpMultiplier_1_5,        sText_Description_TXC_ExpMultiplier_2_0,    sText_Description_TXC_ExpMultiplier_0_0},
    [MENUITEM_BATTLE_PSS]               = {sText_Desc_PSS_Off, sText_Desc_PSS_On, NULL, NULL},
    //[MENUITEM_BATTLE_DIFFICULTY]       = {sText_Desc_ChallengeMode, NULL, NULL, NULL},
    [MENUITEM_BATTLE_CANCEL]            = {sText_Save, NULL, NULL, NULL},
};

static const u8 *const sOptionMenuItemDescriptionsBreeding[MENUITEM_BREEDING_COUNT][4] =
{
    [MENUITEM_BREEDING_IVS]         = {sText_Desc_BreedingIvs,  NULL, NULL, NULL},
    [MENUITEM_BREEDING_MASUDA]      = {sText_Desc_Masuda,       NULL, NULL, NULL},
    [MENUITEM_BREEDING_SHINY_CHARM] = {sText_Desc_ShinyCharm,   NULL, NULL, NULL},
    [MENUITEM_BREEDING_OVAL_CHARM]  = {sText_Desc_OvalCharm,    NULL, NULL, NULL},
    [MENUITEM_BREEDING_EVERSTONE]   = {sText_Desc_Everstone,    NULL, NULL, NULL},
    [MENUITEM_BREEDING_CANCEL]      = {sText_Save, NULL, NULL, NULL},
};

static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_GAME:
        selection = sOptions->sel[menuItem];  

        if (menuItem == MENUITEM_GAME_FRAMETYPE
            || menuItem == MENUITEM_GAME_TEXTSPEED
            || menuItem == MENUITEM_GAME_BUTTONMODE
            || menuItem == MENUITEM_GAME_FONT
            || menuItem == MENUITEM_GAME_FOLLOWER_PKMN
            || menuItem == MENUITEM_GAME_START_MENU
            || menuItem == MENUITEM_GAME_SUMMARY_SCREEN
            || menuItem == MENUITEM_GAME_SHINY
            || menuItem == MENUITEM_GAME_FAVCOLOR)
            return sOptionMenuItemDescriptionsGame[menuItem][0];
        else
            return sOptionMenuItemDescriptionsGame[menuItem][selection];
    case MENU_SOUND:
        selection = sOptions->sel_sound[menuItem];
        return sOptionMenuItemDescriptionsSound[menuItem][selection];
    case MENU_BATTLE:
        selection = sOptions->sel_battle[menuItem];

        if (menuItem == MENUITEM_BATTLE_SCENE
            || menuItem == MENUITEM_BATTLE_STYLE
            || menuItem == MENUITEM_BATTLE_HP_BAR
            || menuItem == MENUITEM_BATTLE_EXP_BAR
            || menuItem == MENUITEM_BATTLE_LAST_BALL
            || menuItem == MENUITEM_BATTLE_TYPE_ICONS
            || menuItem == MENUITEM_BATTLE_GLOBAL_EXP
            //|| menuItem == MENUITEM_BATTLE_DIFFICULTY
            )
            return sOptionMenuItemDescriptionsBattle[menuItem][0];
        else
            return sOptionMenuItemDescriptionsBattle[menuItem][selection];
    case MENU_BREEDING:
        selection = sOptions->sel_breeding[menuItem];
        
        return sOptionMenuItemDescriptionsBreeding[menuItem][0]; 
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
        case MENU_GAME:
            return MENUITEM_GAME_COUNT;
        case MENU_SOUND:
            return MENUITEM_SOUND_COUNT;
        case MENU_BATTLE:
            return MENUITEM_BATTLE_COUNT;
        case MENU_BREEDING:
            return MENUITEM_BREEDING_COUNT;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case MENU_GAME:
        return MENUITEM_GAME_CANCEL;
    case MENU_SOUND:
        return MENUITEM_SOUND_CANCEL;
    case MENU_BATTLE:
        return MENUITEM_BATTLE_CANCEL;
    case MENU_BREEDING:
        return MENUITEM_BREEDING_CANCEL;
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
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    u8 x = GetStringRightAlignXOffset(FONT_SMALL, sText_TopBar_Right, 112);

    FillWindowPixelBuffer(WIN_TOPBAR_LEFT, PIXEL_FILL(15));
    FillWindowPixelBuffer(WIN_TOPBAR_RIGHT, PIXEL_FILL(15));
    switch (sOptions->submenu)
    {
        case MENU_GAME:
            AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Game);
            break;
        case MENU_SOUND:
            AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Sound);
            break;
        case MENU_BATTLE:
            AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Battle);
            break;
        case MENU_BREEDING:
            AddTextPrinterParameterized3(WIN_TOPBAR_LEFT, FONT_SMALL, 8, 1, color, 0, sText_TopBar_Breeding);
            break;
    }
    AddTextPrinterParameterized3(WIN_TOPBAR_RIGHT, FONT_SMALL, x, 1, color, 0, sText_TopBar_Right);
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
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
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
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
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
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    switch (sOptions->submenu)
    {
        case MENU_GAME:
            if (sItemFunctionsGame[id].drawChoices != NULL)
                sItemFunctionsGame[id].drawChoices(sOptions->sel[id], y);
            break;
        case MENU_SOUND:
            if (sItemFunctionsSound[id].drawChoices != NULL)
                sItemFunctionsSound[id].drawChoices(sOptions->sel_sound[id], y);
            break;
        case MENU_BATTLE:
            if (sItemFunctionsBattle[id].drawChoices != NULL)
                sItemFunctionsBattle[id].drawChoices(sOptions->sel_battle[id], y);
            break;
        case MENU_BREEDING:
            if (sItemFunctionsBreeding[id].drawChoices != NULL)
                sItemFunctionsBreeding[id].drawChoices(sOptions->sel_breeding[id], y);
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
    //u8 windowColor = gSaveBlock2Ptr->optionsFavColor;
    u8 windowColor = 0;
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
/*
        sOptions->sel[MENUITEM_GAME_TEXTSPEED]          = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel[MENUITEM_GAME_BUTTONMODE]         = gSaveBlock2Ptr->optionsButtonMode;
        sOptions->sel[MENUITEM_GAME_FRAMETYPE]          = gSaveBlock2Ptr->optionsWindowFrameType;
        sOptions->sel[MENUITEM_GAME_FAVCOLOR]           = gSaveBlock2Ptr->optionsFavColor;
        sOptions->sel[MENUITEM_GAME_FONT]               = gSaveBlock2Ptr->optionsCurrentFont;
        sOptions->sel[MENUITEM_GAME_UNIT_SYSTEM]        = gSaveBlock2Ptr->optionsUnitSystem;
        sOptions->sel[MENUITEM_GAME_FOLLOWER_PKMN]      = gSaveBlock2Ptr->optionsShowFollowerPokemon;
        sOptions->sel[MENUITEM_GAME_SUMMARY_SCREEN]     = gSaveBlock2Ptr->optionsSummaryScreenUI;
        sOptions->sel[MENUITEM_GAME_START_MENU]         = gSaveBlock2Ptr->optionsStartMenuStyle;
        sOptions->sel[MENUITEM_GAME_MATCHCALL]          = gSaveBlock2Ptr->optionsDisableMatchCall;
        sOptions->sel[MENUITEM_GAME_FISHREELING]        = gSaveBlock2Ptr->optionsFishReeling;
        sOptions->sel[MENUITEM_GAME_SHINY]              = gSaveBlock2Ptr->optionsNewShiny;
        sOptions->sel[MENUITEM_DIFFICULTY_SCALING_IVS]  = gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs;
        sOptions->sel[MENUITEM_DIFFICULTY_SCALING_EVS]  = gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs;
        
        sOptions->sel_sound[MENUITEM_SOUND_MODE]        = gSaveBlock2Ptr->optionsSound;
        sOptions->sel_sound[MENUITEM_SOUND_SURF]        = gSaveBlock2Ptr->optionsSurfMusic;
        sOptions->sel_sound[MENUITEM_SOUND_BIKE]        = gSaveBlock2Ptr->optionsBikeMusic;
        sOptions->sel_sound[MENUITEM_SOUND_WILD]        = gSaveBlock2Ptr->optionsWildMusic;
        sOptions->sel_sound[MENUITEM_SOUND_TRAINER]     = gSaveBlock2Ptr->optionsTrainerBGM;
        sOptions->sel_sound[MENUITEM_SOUND_GRASS]       = gSaveBlock2Ptr->optionsGrassSound;

        sOptions->sel_battle[MENUITEM_BATTLE_SCENE]             = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel_battle[MENUITEM_BATTLE_STYLE]             = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel_battle[MENUITEM_BATTLE_INTRO]             = gSaveBlock2Ptr->optionsSkipBattleIntro;
        sOptions->sel_battle[MENUITEM_BATTLE_HP_BAR]            = gSaveBlock2Ptr->optionsHpBarSpeed;
        sOptions->sel_battle[MENUITEM_BATTLE_EXP_BAR]           = gSaveBlock2Ptr->optionsExpBarSpeed;
        sOptions->sel_battle[MENUITEM_BATTLE_LAST_BALL]         = gSaveBlock2Ptr->optionsLastBall;
        sOptions->sel_battle[MENUITEM_BATTLE_TYPE_ICONS]        = gSaveBlock2Ptr->showTypeIcons;
        sOptions->sel_battle[MENUITEM_BATTLE_FRIENSHIP_BONUS]   = gSaveBlock2Ptr->optionsFriendshipBonuses;
        sOptions->sel_battle[MENUITEM_BATTLE_GLOBAL_EXP]        = gSaveBlock2Ptr->optionsExpShare;
        sOptions->sel_battle[MENUITEM_BATTLE_EXP_MULTIPLIER]    = gSaveBlock1Ptr->tx_Challenges_ExpMultiplier;
        sOptions->sel_battle[MENUITEM_BATTLE_PSS]               = gSaveBlock2Ptr->optionsPSS;
        //sOptions->sel_battle[MENUITEM_BATTLE_DIFFICULTY]       = gSaveBlock1Ptr->tx_Challenges_HarderTeams;

        sOptions->sel_breeding[MENUITEM_BREEDING_IVS]           = gSaveBlock2Ptr->optionsIVInheritance;
        sOptions->sel_breeding[MENUITEM_BREEDING_MASUDA]        = gSaveBlock2Ptr->optionsMasudaMethod;
        sOptions->sel_breeding[MENUITEM_BREEDING_SHINY_CHARM]   = gSaveBlock2Ptr->optionsShinyCharm;
        sOptions->sel_breeding[MENUITEM_BREEDING_OVAL_CHARM]    = gSaveBlock2Ptr->optionsOvalCharm;
        sOptions->sel_breeding[MENUITEM_BREEDING_EVERSTONE]     = gSaveBlock2Ptr->optionsEverstone;
*/
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
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_GAME_COUNT - 1, 110, 110, 0);

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
        if (sOptions->submenu == MENU_GAME)
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
        else if (sOptions->submenu == MENU_SOUND)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_sound[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsSound[cursor].processInput != NULL)
                {
                    sOptions->sel_sound[cursor] = sItemFunctionsSound[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_sound[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_BATTLE)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_battle[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsBattle[cursor].processInput != NULL)
                {
                    sOptions->sel_battle[cursor] = sItemFunctionsBattle[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_battle[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
        else if (sOptions->submenu == MENU_BREEDING)
        {
            int cursor = sOptions->menuCursor[sOptions->submenu];
            u8 previousOption = sOptions->sel_breeding[cursor];
            if (CheckConditions(cursor))
            {
                if (sItemFunctionsBreeding[cursor].processInput != NULL)
                {
                    sOptions->sel_breeding[cursor] = sItemFunctionsBreeding[cursor].processInput(previousOption);
                    ReDrawAll();
                    DrawDescriptionText();
                }

                if (previousOption != sOptions->sel_breeding[cursor])
                    DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        if (sOptions->submenu != LAST_MENU)
            sOptions->submenu++;
        else
            sOptions->submenu = MENU_GAME;

        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(L_BUTTON))
    {
        if (sOptions->submenu != MENU_GAME)
            sOptions->submenu--;
        else
            sOptions->submenu = LAST_MENU;
        
        DrawTopBarText();
        ReDrawAll();
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    /*
    gSaveBlock2Ptr->optionsTextSpeed            = sOptions->sel[MENUITEM_GAME_TEXTSPEED];
    gSaveBlock2Ptr->optionsButtonMode           = sOptions->sel[MENUITEM_GAME_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType      = sOptions->sel[MENUITEM_GAME_FRAMETYPE];
    gSaveBlock2Ptr->optionsFavColor             = sOptions->sel[MENUITEM_GAME_FAVCOLOR];
    gSaveBlock2Ptr->optionsCurrentFont          = sOptions->sel[MENUITEM_GAME_FONT];
    gSaveBlock2Ptr->optionsUnitSystem           = sOptions->sel[MENUITEM_GAME_UNIT_SYSTEM];
    gSaveBlock2Ptr->optionsShowFollowerPokemon  = sOptions->sel[MENUITEM_GAME_FOLLOWER_PKMN];
    gSaveBlock2Ptr->optionsSummaryScreenUI      = sOptions->sel[MENUITEM_GAME_SUMMARY_SCREEN];
    gSaveBlock2Ptr->optionsStartMenuStyle       = sOptions->sel[MENUITEM_GAME_START_MENU];
    gSaveBlock2Ptr->optionsDisableMatchCall     = sOptions->sel[MENUITEM_GAME_MATCHCALL];
    gSaveBlock2Ptr->optionsFishReeling          = sOptions->sel[MENUITEM_GAME_FISHREELING];
    gSaveBlock2Ptr->optionsNewShiny             = sOptions->sel[MENUITEM_GAME_SHINY];

    gSaveBlock1Ptr->tx_Challenges_TrainerScalingIVs     = sOptions->sel[MENUITEM_DIFFICULTY_SCALING_IVS];
    gSaveBlock1Ptr->tx_Challenges_TrainerScalingEVs     = sOptions->sel[MENUITEM_DIFFICULTY_SCALING_EVS];

    gSaveBlock2Ptr->optionsSound        = sOptions->sel_sound[MENUITEM_SOUND_MODE];
    gSaveBlock2Ptr->optionsSurfMusic    = sOptions->sel_sound[MENUITEM_SOUND_SURF];
    gSaveBlock2Ptr->optionsBikeMusic    = sOptions->sel_sound[MENUITEM_SOUND_BIKE];
    gSaveBlock2Ptr->optionsWildMusic    = sOptions->sel_sound[MENUITEM_SOUND_WILD];
    gSaveBlock2Ptr->optionsTrainerBGM   = sOptions->sel_sound[MENUITEM_SOUND_TRAINER];
    gSaveBlock2Ptr->optionsGrassSound   = sOptions->sel_sound[MENUITEM_SOUND_GRASS];

    gSaveBlock2Ptr->optionsBattleSceneOff       = sOptions->sel_battle[MENUITEM_BATTLE_SCENE];
    gSaveBlock2Ptr->optionsBattleStyle          = sOptions->sel_battle[MENUITEM_BATTLE_STYLE];
    gSaveBlock2Ptr->optionsSkipBattleIntro      = sOptions->sel_battle[MENUITEM_BATTLE_INTRO];
    gSaveBlock2Ptr->optionsHpBarSpeed           = sOptions->sel_battle[MENUITEM_BATTLE_HP_BAR];
    gSaveBlock2Ptr->optionsExpBarSpeed          = sOptions->sel_battle[MENUITEM_BATTLE_EXP_BAR];
    gSaveBlock2Ptr->optionsLastBall             = sOptions->sel_battle[MENUITEM_BATTLE_LAST_BALL];
    gSaveBlock2Ptr->showTypeIcons               = sOptions->sel_battle[MENUITEM_BATTLE_TYPE_ICONS];
    gSaveBlock2Ptr->optionsFriendshipBonuses    = sOptions->sel_battle[MENUITEM_BATTLE_FRIENSHIP_BONUS];
    gSaveBlock2Ptr->optionsExpShare             = sOptions->sel_battle[MENUITEM_BATTLE_GLOBAL_EXP];
    gSaveBlock1Ptr->tx_Challenges_ExpMultiplier = sOptions->sel_battle[MENUITEM_BATTLE_EXP_MULTIPLIER];
    gSaveBlock2Ptr->optionsPSS                  = sOptions->sel_battle[MENUITEM_BATTLE_PSS];
    //gSaveBlock1Ptr->tx_Challenges_HarderTeams   = sOptions->sel_battle[MENUITEM_BATTLE_DIFFICULTY];

    gSaveBlock2Ptr->optionsIVInheritance    = sOptions->sel_breeding[MENUITEM_BREEDING_IVS];
    gSaveBlock2Ptr->optionsMasudaMethod     = sOptions->sel_breeding[MENUITEM_BREEDING_MASUDA];
    gSaveBlock2Ptr->optionsShinyCharm       = sOptions->sel_breeding[MENUITEM_BREEDING_SHINY_CHARM];
    gSaveBlock2Ptr->optionsOvalCharm        = sOptions->sel_breeding[MENUITEM_BREEDING_OVAL_CHARM];
    gSaveBlock2Ptr->optionsEverstone        = sOptions->sel_breeding[MENUITEM_BREEDING_EVERSTONE];
    */
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
    return gMessageBox_Pal;
    /*
    switch (selection)
    {
        default:
        case 0:
            return gMessageBox_Pal;
            break;
        case 1:
            return gMessageBoxRed_Pal;
            break;
        case 2:
            return gMessageBoxBlue_Pal;
            break;
    }
    */
}

static int ProcessInput_Options_FavColor(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (3 - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (3 - 1);
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
}

// Process Input functions ****SPECIFIC****
static const u8 sText_Instant[] = _("INSTANT");
static const u8 *const sTextSpeedStrings[] = {sText_TextSpeedSlow, sText_TextSpeedMid, sText_TextSpeedFast, sText_Faster};
static void DrawChoices_TextSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_TEXTSPEED);
    DrawChoices_Options_Four(sTextSpeedStrings, selection, y, active);
}

static void DrawChoices_BattleScene(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOn, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionOff, GetStringRightAlignXOffset(FONT_NORMAL, sText_OptionOff, 198), y, styles[1], TRUE);
}

static void DrawChoices_BattleStyle(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_BattleStyleShift, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, sText_BattleStyleSet, 198), y, styles[1], TRUE);
}

static void DrawChoices_Sound(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_SoundMono, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, sText_SoundStereo, 198), y, styles[1], TRUE);
}

static void DrawChoices_ButtonMode(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_BUTTONMODE);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_ButtonTypeNormal, sText_ButtonTypeLR, sText_ButtonTypeLEqualsA);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_ButtonTypeNormal, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_ButtonTypeLR, xMid, y, styles[1], active);
    DrawOptionMenuChoice(sText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(1, sText_ButtonTypeLEqualsA, 198), y, styles[2], active);
}

static void DrawChoices_WindowColor(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_OptionGreen, sText_OptionRed, sText_OptionBlue);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionGreen, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionRed, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_OptionBlue, GetStringRightAlignXOffset(1, sText_OptionBlue, 198), y, styles[2], TRUE);
}

static void DrawChoices_SurfBikeBGM(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_OptionOff, sText_OptionHoenn, sText_OptionKanto);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOff, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionHoenn, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_OptionKanto, GetStringRightAlignXOffset(1, sText_OptionKanto, 198), y, styles[2], TRUE);
}

static void DrawChoices_GrassSound(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_OptionOff, sText_OptionOn, sText_OptionPlayer);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOff, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionOn, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_OptionPlayer, GetStringRightAlignXOffset(1, sText_OptionPlayer, 198), y, styles[2], TRUE);
}

static void DrawChoices_ChallengeMode(int selection, int y)
{
    u8 styles[3] = {0};
    int xMid = GetMiddleX(sText_OptionOff, sText_OptionOn, sText_OptionHard);
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOff, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionOn, xMid, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_OptionHard, GetStringRightAlignXOffset(1, sText_OptionHard, 198), y, styles[2], TRUE);
}

static void DrawChoices_UnitSystem(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_UNIT_SYSTEM);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_UnitSystemImperial, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_UnitSystemMetric, GetStringRightAlignXOffset(1, sText_UnitSystemMetric, 198), y, styles[1], active);
}

static void DrawChoices_FollowerPkmn(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_FOLLOWER_PKMN);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_OptionOff, GetStringRightAlignXOffset(1, sText_OptionOff, 198), y, styles[1], active);
}

static void DrawChoices_StartMenu(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionEmerald, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionCustom, GetStringRightAlignXOffset(1, sText_OptionCustom, 198), y, styles[1], TRUE);
}

static const u8 sText_Challenges_ExpMultiplier_1_0[]   = _("1x");
static const u8 sText_Challenges_ExpMultiplier_1_5[]   = _("1.5x");
static const u8 sText_Challenges_ExpMultiplier_2_0[]   = _("2x");
static const u8 sText_Challenges_ExpMultiplier_0_0[]   = _("0x");
static const u8 *const sText_Challenges_ExpMultiplier_Strings[] = {sText_Challenges_ExpMultiplier_1_0, sText_Challenges_ExpMultiplier_1_5, sText_Challenges_ExpMultiplier_2_0, sText_Challenges_ExpMultiplier_0_0};
static void DrawChoices_Challenges_ExpMultiplier(int selection, int y)
{
    u8 styles[4] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Challenges_ExpMultiplier_1_0, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_Challenges_ExpMultiplier_1_5, 124 + 10 - 7, y, styles[1], TRUE);
    DrawOptionMenuChoice(sText_Challenges_ExpMultiplier_2_0, 144 + 20 - 2, y, styles[2], TRUE);
    DrawOptionMenuChoice(sText_Challenges_ExpMultiplier_0_0, 164 + 22, y, styles[3], TRUE);
}

static void DrawChoices_FrameType(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_FRAMETYPE);
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

static void DrawChoices_EmeraldFRLG(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionEmerald, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionFRLG, GetStringRightAlignXOffset(1, sText_OptionFRLG, 198), y, styles[1], TRUE);
}

static void DrawChoices_HoennKanto(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionHoenn, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionKanto, GetStringRightAlignXOffset(1, sText_OptionKanto, 198), y, styles[1], TRUE);
}

static void DrawChoices_OffOn(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOff, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_OptionOn, GetStringRightAlignXOffset(1, sText_OptionOn, 198), y, styles[1], TRUE);
}

static void DrawChoices_35(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_Option3, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_Option5, GetStringRightAlignXOffset(1, sText_Option5, 198), y, styles[1], TRUE);
}


static void DrawChoices_OnOff(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_GAME_MATCHCALL);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_OptionOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(sText_OptionOff, GetStringRightAlignXOffset(1, sText_OptionOff, 198), y, styles[1], active);
}

static void DrawChoices_NormalFast(int selection, int y)
{
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(sText_ButtonTypeNormal, 104, y, styles[0], TRUE);
    DrawOptionMenuChoice(sText_TextSpeedFast, GetStringRightAlignXOffset(1, sText_TextSpeedFast, 198), y, styles[1], TRUE);
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
