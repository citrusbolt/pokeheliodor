#include "global.h"
#include "scanline_effect.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "malloc.h"
#include "link.h"
#include "bg.h"
#include "sound.h"
#include "frontier_pass.h"
#include "overworld.h"
#include "menu.h"
#include "text.h"
#include "event_data.h"
#include "easy_chat.h"
#include "money.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "pokemon_icon.h"
#include "trainer_pokemon_sprites.h"
#include "contest_util.h"
#include "constants/songs.h"
#include "constants/game_stat.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/trainers.h"

struct TrainerCardData
{
    u8 mainState;
    u8 printState;
    u8 gfxLoadState;
    u8 bgPalLoadState;
    u8 flipDrawState;
    bool8 isLink;
    u8 timeColonBlinkTimer;
    bool8 timeColonInvisible;
    bool8 onBack;
    bool8 allowDMACopy;
    bool8 hasPokedex;
    bool8 hasHofResult;
    bool8 hasLinkResults;
    bool8 hasBattleTowerWins;
    bool8 isDX;
    bool8 unused_F;
    bool8 hasTrades;
    u8 badgeCount[NUM_BADGES];
    u8 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH][13];
    u8 textPlayersCard[70];
    u8 textHofTime[70];
    u8 textLinkBattleType[70];
    u8 textLinkBattleWins[70];
    u8 textLinkBattleLosses[70];
    u8 textNumTrades[70];
    u8 textBerryCrushPts[70];
    u8 textUnionRoomStats[70];
    u8 textNumLinkPokeblocks[70];
    u8 textNumLinkContests[70];
    u8 textBattleTowerWins[70];
    u8 textBattleTowerStreak[70];
    u8 textBattlePoints[70];
    u8 textShinyCount[70];
    u8 textPowerPoints[70];
    u16 monIconPal[16 * PARTY_SIZE];
    s8 flipBlendY;
    bool8 timeColonNeedDraw;
    u8 trainerPair;
    u8 cardLayout;
    u16 blendColor;
    void (*callback2)(void);
    struct TrainerCard trainerCard;
    u16 frontTilemap[600];
    u16 backTilemap[600];
    u16 bgTilemap[600];
    u8 badgeTiles[0x80 * NUM_BADGES];
    u8 stickerTiles[0x200];
    u8 hStickerTiles[0x200];
    u8 cardTiles[0x2300];
    u16 cardTilemapBuffer[0x1000];
    u16 bgTilemapBuffer[0x1000];
    u16 cardTop;
    u8 language;
    u8 stats[6];
};

// EWRAM
EWRAM_DATA struct TrainerCard gTrainerCards[4] = {0};
EWRAM_DATA static struct TrainerCardData *sData = NULL;

//this file's functions
static void VblankCb_TrainerCard(void);
static void HblankCb_TrainerCard(void);
static void BlinkTimeColon(void);
static void CB2_TrainerCard(void);
static void CloseTrainerCard(u8 task);
static bool8 PrintAllOnCardFront(void);
static void DrawTrainerCardWindow(u8);
static void CreateTrainerCardTrainerPic(void);
static void DrawCardScreenBackground(u16*);
static void DrawCardFrontOrBack(u16*);
static void DrawStarsAndBadgesOnCard(void);
static void PrintTimeOnCard(void);
static void FlipTrainerCard(void);
static bool8 IsCardFlipTaskActive(void);
static bool8 LoadCardGfx(void);
static void CB2_InitTrainerCard(void);
static u32 GetCappedGameStat(u8 statId, u32 maxValue);
static bool8 HasAllFrontierSymbols(void);
static u16 GetBattleTowerRecordStreak(void);
static u8 CountPlayerTrainerExtraStars(void);
static u16 GetCaughtMonsCount(void);
static void SetPlayerCardData(struct TrainerCard*);
static void SetDataFromTrainerCard(void);
static void InitGpuRegs(void);
static void ResetGpuRegs(void);
static void InitBgsAndWindows(void);
static void SetTrainerCardCb2(void);
static void SetUpTrainerCardTask(void);
static void InitTrainerCardData(void);
static u8 GetSetCardType(void);
static void PrintNameOnCardFront(void);
static void PrintIdOnCard(void);
static void PrintMoneyOnCard(void);
static void PrintPokedexOnCard(void);
static void PrintProfilePhraseOnCard(void);
static void PrintBarcodeOnCard(void);
static const u8 *ConvertDigitToBarcodeSymbol(u8 digit);
static const u8 *ConvertLetterToBarcodeSymbol(u8 letter);
static bool8 PrintAllOnCardBack(void);
static void PrintPokemonIconsOnCard(void);
static void PrintStickersOnCard(void);
static void BufferTextsVarsForCardPage2(void);
static void PrintStatBySlot(u8 slot);
static void BufferNameForCardBack(void);
static void PrintNameOnCardBack(void);
static void BufferHofDebutTime(void);
static void PrintHofDebutTimeOnCard(u8 slot);
static void BufferLinkBattleResults(void);
static void PrintLinkBattleResultsOnCard(u8 slot);
static void BufferNumTrades(void);
static void PrintTradesStringOnCard(u8 slot);
static void BufferLinkPokeblocksNum(void);
static void PrintPokeblockStringOnCard(u8 slot);
static void BufferLinkContestNum(void);
static void PrintContestStringOnCard(u8 slot);
static void BufferBattleTowerWins(void);
static void PrintBattleTowerStringOnCard(u8 slot);
static void BufferUnionRoomStats(void);
static void PrintUnionStringOnCard(u8 slot);
static void BufferBerryCrushPoints(void);
static void PrintBerryCrushStringOnCard(u8 slot);
static void BufferBattlePoints(void);
static void PrintBattlePointsStringOnCard(u8 slot);
static void BufferShinyCount(void);
static void PrintShinyCountStringOnCard(u8 slot);
static void BufferPowerPoints(void);
static void PrintPowerPointsStringOnCard(u8 slot);
static void PrintStatOnBackOfCard(u8 top, const u8* str1, u8* str2, const u8* color);
static void LoadStickerGfx(void);
static u8 SetCardBgsAndPals(void);
static void DrawCardBackStats(void);
static void Task_DoCardFlipTask(u8);
static bool8 Task_BeginCardFlip(struct Task* task);
static bool8 Task_AnimateCardFlipDown(struct Task* task);
static bool8 Task_DrawFlippedCardSide(struct Task* task);
static bool8 Task_SetCardFlipped(struct Task* task);
static bool8 Task_AnimateCardFlipUp(struct Task* task);
static bool8 Task_EndCardFlip(struct Task* task);
static void UpdateCardFlipRegs(u16);
static void LoadMonIconGfx(void);

static const u32 sTrainerCardStickers_Gfx[]      = INCBIN_U32("graphics/trainer_card/stickers_fr.4bpp.lz");
static const u16 sUnused_Pal[]                   = INCBIN_U16("graphics/trainer_card/unused.gbapal");
static const u16 sHoennTrainerCard1Star_Pal[]    = INCBIN_U16("graphics/trainer_card/one_star.gbapal");
static const u16 sKantoTrainerCard1Star_Pal[]    = INCBIN_U16("graphics/trainer_card/one_star_fr.gbapal");
static const u16 sHoennTrainerCard2Star_Pal[]    = INCBIN_U16("graphics/trainer_card/two_stars.gbapal");
static const u16 sKantoTrainerCard2Star_Pal[]    = INCBIN_U16("graphics/trainer_card/two_stars_fr.gbapal");
static const u16 sHoennTrainerCard3Star_Pal[]    = INCBIN_U16("graphics/trainer_card/three_stars.gbapal");
static const u16 sKantoTrainerCard3Star_Pal[]    = INCBIN_U16("graphics/trainer_card/three_stars_fr.gbapal");
static const u16 sHoennTrainerCard4Star_Pal[]    = INCBIN_U16("graphics/trainer_card/four_stars.gbapal");
static const u16 sKantoTrainerCard4Star_Pal[]    = INCBIN_U16("graphics/trainer_card/four_stars_fr.gbapal");
static const u16 sHoennTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg.gbapal");
static const u16 sKantoTrainerCardFemaleBg_Pal[] = INCBIN_U16("graphics/trainer_card/female_bg_fr.gbapal");
static const u16 sHoennTrainerCardBadges_Pal[]   = INCBIN_U16("graphics/trainer_card/badges.gbapal");
static const u16 sKantoTrainerCardBadges_Pal[]   = INCBIN_U16("graphics/trainer_card/badges_fr.gbapal");
static const u16 sTrainerCardGold_Pal[]          = INCBIN_U16("graphics/trainer_card/gold.gbapal");
static const u16 sTrainerCardSticker1_Pal[]      = INCBIN_U16("graphics/trainer_card/stickers_fr1.gbapal");
static const u16 sTrainerCardSticker2_Pal[]      = INCBIN_U16("graphics/trainer_card/stickers_fr2.gbapal");
static const u16 sTrainerCardSticker3_Pal[]      = INCBIN_U16("graphics/trainer_card/stickers_fr3.gbapal");
static const u16 sTrainerCardSticker4_Pal[]      = INCBIN_U16("graphics/trainer_card/stickers_fr4.gbapal");
static const u32 sHoennTrainerCardBadges_Gfx[]   = INCBIN_U32("graphics/trainer_card/badges.4bpp.lz");
static const u32 sKantoTrainerCardBadges_Gfx[]   = INCBIN_U32("graphics/trainer_card/badges_fr.4bpp.lz");
static const u16 sTrainerCardGoldRS_Pal[]        = INCBIN_U16("graphics/trainer_card/gold_rs.gbapal");
static const u32 sHoennTrainerCardBadges1_Gfx[]  = INCBIN_U32("graphics/trainer_card/badges1.4bpp.lz");
static const u32 sHoennTrainerCardBadges2_Gfx[]  = INCBIN_U32("graphics/trainer_card/badges2.4bpp.lz");
static const u16 sHoennTrainerCardBadges1_Pal[]  = INCBIN_U16("graphics/trainer_card/badges1.gbapal");
static const u16 sHoennTrainerCardBadges2_Pal[]  = INCBIN_U16("graphics/trainer_card/badges2.gbapal");
static const u16 sHeliodorTrainerCard5Star_Pal[] = INCBIN_U16("graphics/trainer_card/five_stars_h.gbapal");
static const u32 sTrainerCardHStickers_Gfx[]     = INCBIN_U32("graphics/trainer_card/stickers_h.4bpp.lz");

static const struct BgTemplate sTrainerCardBgTemplates[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 192
    },
};

static const struct WindowTemplate sTrainerCardWindowTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x253,
    },
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    {
        .bg = 3,
        .tilemapLeft = 19,
        .tilemapTop = 5,
        .width = 9,
        .height = 10,
        .paletteNum = 8,
        .baseBlock = 0x150,
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 *const sHoennTrainerCardStarPals[] =
{
    gHoennTrainerCard0Star_Pal,
    sHoennTrainerCard1Star_Pal,
    sHoennTrainerCard2Star_Pal,
    sHoennTrainerCard3Star_Pal,
    sHoennTrainerCard4Star_Pal,
};

static const u16 *const sKantoTrainerCardStarPals[] =
{
    gKantoTrainerCard0Star_Pal,
    sKantoTrainerCard1Star_Pal,
    sKantoTrainerCard2Star_Pal,
    sKantoTrainerCard3Star_Pal,
    sKantoTrainerCard4Star_Pal,
    sHeliodorTrainerCard5Star_Pal,
};

static const u8 sTrainerCardTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTrainerCardStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED};
static const u8 sTrainerCardRSTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2};
static const u8 sTrainerCardRSContentColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_3, TEXT_DYNAMIC_COLOR_4};
static const u8 sTrainerCardRSStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_6};
static const u8 sTimeColonInvisibleTextColors[6] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_TRANSPARENT};
static const u8 sTrainerCard5StarPhraseTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_4};
static const u8 sTrainerCard5StarStatColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTrainerCard5StarIDColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_3, TEXT_DYNAMIC_COLOR_4};
static const u8 sTrainerCard5StarNameColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_1};
static const u8 sTrainerCardHNameColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_6};

static const u8 sTrainerPicOffset[][GENDER_COUNT][2] =
{
    [CARD_LAYOUT_RS] = 
    {
        [MALE]   = {0, 0},
        [FEMALE] = {0, 0}
    },
	[CARD_LAYOUT_FRLG] = 
    {
        [MALE]   = {13, 4},
        [FEMALE] = {13, 4}
    },
    [CARD_LAYOUT_EMERALD] = 
    {
        [MALE]   = {1, 0},
        [FEMALE] = {1, 0}
    },
    [CARD_LAYOUT_HELIODOR] = 
    {
        [MALE]   = {13, 4},
        [FEMALE] = {13, 4}
    }
};

static const u8 sTrainerPicFacilityClass[][GENDER_COUNT] = 
{
    [TRAINER_FRLG] = 
    {
        [MALE]   = FACILITY_CLASS_RED, 
        [FEMALE] = FACILITY_CLASS_LEAF
    }, 
    [TRAINER_RS] = 
    {
        [MALE]   = FACILITY_CLASS_RS_BRENDAN, 
        [FEMALE] = FACILITY_CLASS_RS_MAY
    }, 
    [TRAINER_EMERALD] = 
    {
        [MALE]   = FACILITY_CLASS_E_BRENDAN, 
        [FEMALE] = FACILITY_CLASS_E_MAY
    }, 
    [TRAINER_HELIODOR] = 
    {
        [MALE]   = FACILITY_CLASS_BRENDAN, 
        [FEMALE] = FACILITY_CLASS_MAY
    },
    [TRAINER_CRYSTALDUST] = 
    {
        [MALE]   = FACILITY_CLASS_GOLD, 
        [FEMALE] = FACILITY_CLASS_KRIS
    },
    [TRAINER_TEST] = 
    {
        [MALE]   = FACILITY_CLASS_WALLY, 
        [FEMALE] = FACILITY_CLASS_STEVEN
    }
};

static bool8 (*const sTrainerCardFlipTasks[])(struct Task *) =
{
    Task_BeginCardFlip,
    Task_AnimateCardFlipDown,
    Task_DrawFlippedCardSide,
    Task_SetCardFlipped,
    Task_AnimateCardFlipUp,
    Task_EndCardFlip,
};

static void VblankCb_TrainerCard(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    BlinkTimeColon();
    if (sData->allowDMACopy)
        DmaCopy16(3, &gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 0x140);
}

static void HblankCb_TrainerCard(void)
{
    u16 backup;
    u16 bgVOffset;

    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

static void CB2_TrainerCard(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CloseTrainerCard(u8 taskId)
{
    SetMainCallback2(sData->callback2);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sData);
    DestroyTask(taskId);
}

// States for Task_TrainerCard. Skips the initial states, which are done once in order
#define STATE_HANDLE_INPUT_FRONT  10
#define STATE_HANDLE_INPUT_BACK   11
#define STATE_WAIT_FLIP_TO_BACK   12
#define STATE_WAIT_FLIP_TO_FRONT  13
#define STATE_CLOSE_CARD          14
#define STATE_WAIT_LINK_PARTNER   15
#define STATE_CLOSE_CARD_LINK     16

static void Task_TrainerCard(u8 taskId)
{
    switch (sData->mainState)
    {
    // Draw card initially
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            sData->mainState++;
        }
        break;
    case 1:
        if (PrintAllOnCardFront())
            sData->mainState++;
        break;
    case 2:
        DrawTrainerCardWindow(1);
        sData->mainState++;
        break;
    case 3:
        FillWindowPixelBuffer(2, PIXEL_FILL(0));
        CreateTrainerCardTrainerPic();
        DrawTrainerCardWindow(2);
        sData->mainState++;
        break;
    case 4:
        DrawCardScreenBackground(sData->bgTilemap);
        sData->mainState++;
        break;
    case 5:
        DrawCardFrontOrBack(sData->frontTilemap);
        sData->mainState++;
        break;
    case 6:
        DrawStarsAndBadgesOnCard();
        sData->mainState++;
        break;
    // Fade in
    case 7:
        if (gWirelessCommType == 1 && gReceivedRemoteLinkPlayers == TRUE)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(230, 150);
        }
        BlendPalettes(PALETTES_ALL, 16, sData->blendColor);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, sData->blendColor);
        SetVBlankCallback(VblankCb_TrainerCard);
        sData->mainState++;
        break;
    case 8:
        if (!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_FRONT;
        }
        break;
    case 9:
        if (!IsSEPlaying())
            sData->mainState++;
        break;
    case STATE_HANDLE_INPUT_FRONT:
        // Blink the : in play time
        if (!gReceivedRemoteLinkPlayers && sData->timeColonNeedDraw)
        {
            PrintTimeOnCard();
            DrawTrainerCardWindow(1);
            sData->timeColonNeedDraw = FALSE;
        }
        if (JOY_NEW(A_BUTTON))
        {
            FlipTrainerCard();
            PlaySE(SE_RG_CARD_FLIP);
            sData->mainState = STATE_WAIT_FLIP_TO_BACK;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->mainState = STATE_WAIT_LINK_PARTNER;
            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
                sData->mainState = STATE_CLOSE_CARD;
            }
        }
        break;
    case STATE_WAIT_FLIP_TO_BACK:
        if (IsCardFlipTaskActive() && Overworld_LinkRecvQueueLengthMoreThan2() != TRUE)
        {
            PlaySE(SE_RG_CARD_OPEN);
            sData->mainState = STATE_HANDLE_INPUT_BACK;
        }
        break;
    case STATE_HANDLE_INPUT_BACK:
        if (JOY_NEW(B_BUTTON))
        {
            if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
            {
                sData->mainState = STATE_WAIT_LINK_PARTNER;
            }
            else if (gReceivedRemoteLinkPlayers)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
                sData->mainState = STATE_CLOSE_CARD;
            }
            else
            {
                FlipTrainerCard();
                sData->mainState = STATE_WAIT_FLIP_TO_FRONT;
                PlaySE(SE_RG_CARD_FLIP);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
           if (gReceivedRemoteLinkPlayers && sData->isLink && InUnionRoom() == TRUE)
           {
               sData->mainState = STATE_WAIT_LINK_PARTNER;
           }
           else
           {
               BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
               sData->mainState = STATE_CLOSE_CARD;
           }
        }
        break;
    case STATE_WAIT_LINK_PARTNER:
        SetCloseLinkCallback();
        DrawDialogueFrame(0, 1);
        AddTextPrinterParameterized(0, 1, gText_WaitingTrainerFinishReading, 0, 1, 255, 0);
        CopyWindowToVram(0, 3);
        sData->mainState = STATE_CLOSE_CARD_LINK;
        break;
    case STATE_CLOSE_CARD_LINK:
        if (!gReceivedRemoteLinkPlayers)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, sData->blendColor);
            sData->mainState = STATE_CLOSE_CARD;
        }
        break;
    case STATE_CLOSE_CARD:
        if (!UpdatePaletteFade())
            CloseTrainerCard(taskId);
        break;
    case STATE_WAIT_FLIP_TO_FRONT:
        if (IsCardFlipTaskActive() && Overworld_LinkRecvQueueLengthMoreThan2() != TRUE)
        {
            sData->mainState = STATE_HANDLE_INPUT_FRONT;
            PlaySE(SE_RG_CARD_OPEN);
        }
        break;
   }
}

static bool8 LoadCardGfx(void)
{
    switch (sData->gfxLoadState)
    {
    case 0:
        if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
            LZ77UnCompWram(gHoennTrainerCardBg_Tilemap, sData->bgTilemap);
        else if (sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_HELIODOR)
            LZ77UnCompWram(gKantoTrainerCardBg_Tilemap, sData->bgTilemap);
        break;
    case 1:
        if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
            LZ77UnCompWram(gHoennTrainerCardBack_Tilemap, sData->backTilemap);
        else if (sData->cardLayout == CARD_LAYOUT_FRLG)
            LZ77UnCompWram(gKantoTrainerCardBack_Tilemap, sData->backTilemap);
        else if (sData->cardLayout == CARD_LAYOUT_HELIODOR && sData->trainerCard.displayDotCode)
            LZ77UnCompWram(gHeliodorDotCodeTrainerCardBack_Tilemap, sData->backTilemap);
        else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
            LZ77UnCompWram(gHeliodorTrainerCardBack_Tilemap, sData->backTilemap);
        break;
    case 2:
        if (!sData->isLink)
        {
            if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
                LZ77UnCompWram(gHoennTrainerCardFront_Tilemap, sData->frontTilemap);
            else if (sData->cardLayout == CARD_LAYOUT_FRLG)
                LZ77UnCompWram(gKantoTrainerCardFront_Tilemap, sData->frontTilemap);
            else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
                LZ77UnCompWram(gHeliodorTrainerCardFront_Tilemap, sData->frontTilemap);
        }
        else
        {
            if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
                LZ77UnCompWram(gHoennTrainerCardFrontLink_Tilemap, sData->frontTilemap);
            else if (sData->cardLayout == CARD_LAYOUT_FRLG)
                LZ77UnCompWram(gKantoTrainerCardFrontLink_Tilemap, sData->frontTilemap);
            else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
                LZ77UnCompWram(gHeliodorTrainerCardFrontLink_Tilemap, sData->frontTilemap);
        }
        break;
    case 3:
        if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_EMERALD)
		{
            LZ77UnCompWram(sHoennTrainerCardBadges_Gfx, sData->badgeTiles);
		}
		else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
		{
            LZ77UnCompWram(sHoennTrainerCardBadges1_Gfx, sData->badgeTiles);
            LZ77UnCompWram(sHoennTrainerCardBadges2_Gfx, &sData->badgeTiles[0x200]);
		}
        break;
    case 4:
        if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
            LZ77UnCompWram(gHoennTrainerCard_Gfx, sData->cardTiles);
        else if (sData->cardLayout == CARD_LAYOUT_FRLG)
            LZ77UnCompWram(gKantoTrainerCard_Gfx, sData->cardTiles);
        else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
            LZ77UnCompWram(gHeliodorTrainerCard_Gfx, sData->cardTiles);
        break;
    case 5:
        if (sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_HELIODOR)
            LZ77UnCompWram(sTrainerCardStickers_Gfx, sData->stickerTiles);
        break;
	case 6:
        if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
            LZ77UnCompWram(sTrainerCardHStickers_Gfx, sData->hStickerTiles);
		break;
    default:
        sData->gfxLoadState = 0;
        return TRUE;
    }
    sData->gfxLoadState++;
    return FALSE;
}

static void CB2_InitTrainerCard(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetGpuRegs();
        SetUpTrainerCardTask();
        gMain.state++;
        break;
    case 1:
        DmaClear32(3, (void *)OAM, OAM_SIZE);
        gMain.state++;
        break;
    case 2:
        if (!sData->blendColor)
            DmaClear16(3, (void *)PLTT, PLTT_SIZE);
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        gMain.state++;
    case 4:
        InitBgsAndWindows();
        gMain.state++;
        break;
    case 5:
        LoadMonIconGfx();
        gMain.state++;
        break;
    case 6:
        if (LoadCardGfx() == TRUE)
            gMain.state++;
        break;
    case 7:
        LoadStickerGfx();
        gMain.state++;
        break;
    case 8:
        InitGpuRegs();
        gMain.state++;
        break;
    case 9:
        BufferTextsVarsForCardPage2();
        gMain.state++;
        break;
    case 10:
        if (SetCardBgsAndPals() == TRUE)
            gMain.state++;
        break;
    default:
        SetTrainerCardCb2();
        break;
    }
}

static u32 GetCappedGameStat(u8 statId, u32 maxValue)
{
    u32 statValue = GetGameStat(statId);

    return min(maxValue, statValue);
}

static bool8 HasAllFrontierSymbols(void)
{
    u8 i;
    for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
    {
        if (!FlagGet(FLAG_SYS_TOWER_SILVER + 2 * i) || !FlagGet(FLAG_SYS_TOWER_GOLD + 2 * i))
            return FALSE;
    }
    return TRUE;
}

static u16 GetBattleTowerRecordStreak(void)
{
    u8 i, j;
	u16 streak = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j] > streak)
				streak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j];
		}
	}
	return streak;
}

u32 CountPlayerTrainerStars(void)
{
    u8 stars = 0;
	u8 extraStars = 0;

	if (gSaveBlock1Ptr->trainerCardLayout == CARD_LAYOUT_RS)
	{
		if (GetGameStat(GAME_STAT_ENTERED_HOF))
			stars++;
		if (HasAllHoennMons())
			stars++;
		if (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT)
			stars++;
		if (GetBattleTowerRecordStreak() >= 50)
			stars++;
	}
	else if (gSaveBlock1Ptr->trainerCardLayout == CARD_LAYOUT_FRLG)
	{
		if (GetGameStat(GAME_STAT_ENTERED_HOF))
			stars++;
		if (HasAllHoennMons())	//In FRLG, this is actually HasAllKantoMons(), but this makes more sense for this case.
			stars++;
		if (HasAllMons())
			stars++;
		if (gSaveBlock2Ptr->berryPick.berriesPicked >= 200 && gSaveBlock2Ptr->pokeJump.jumpsInRow >= 200)
			stars++;
	}
	else if (gSaveBlock1Ptr->trainerCardLayout == CARD_LAYOUT_EMERALD)
	{
		if (GetGameStat(GAME_STAT_ENTERED_HOF))
			stars++;
		if (HasAllHoennMons())
			stars++;
		if (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT)
			stars++;
		if (HasAllFrontierSymbols())
			stars++;
	}
	else if (gSaveBlock1Ptr->trainerCardLayout == CARD_LAYOUT_HELIODOR)
	{
		if (GetGameStat(GAME_STAT_ENTERED_HOF))
			stars++;
		if (HasAllHoennMons())
			stars++;
		if (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT)
			stars++;
		if (HasAllFrontierSymbols())
			stars++;
		stars += CountPlayerTrainerExtraStars();
	}

    return stars;
}

static u8 CountPlayerTrainerExtraStars(void)
{
    u8 stars = 0;

	if (gSaveBlock2Ptr->berryPick.berriesPicked >= 200 && gSaveBlock2Ptr->pokeJump.jumpsInRow >= 200)
		stars++;
    if (GetCaughtMonsCount() == 386)
        stars++;
    if (gSaveBlock1Ptr->externalEventFlags.usedBoxRS && gSaveBlock1Ptr->externalEventFlags.boxRSEggsUnlocked == 3)
        stars++;
    if (gSaveBlock1Ptr->externalEventData.totalEarnedPokeCoupons >= 30000)
        stars++;

    return stars;
}

static const u8 sName[] = _("HELIO");

static void SetPlayerCardData(struct TrainerCard *trainerCard)
{
	u32 hofDebut;
	u8 i;

	trainerCard->cardLayout = gSaveBlock1Ptr->trainerCardLayout;

	trainerCard->gender = gSaveBlock2Ptr->playerGender;
	trainerCard->stars = CountPlayerTrainerStars();

	if (trainerCard->stars > 4)
	{
		trainerCard->extraStars = trainerCard->stars - 4;
		trainerCard->stars = 4;
	}

	trainerCard->hasPokedex = FlagGet(FLAG_SYS_POKEDEX_GET);
	trainerCard->caughtAllHoenn = HasAllHoennMons();
	//trainerCard->hasAllPaintings = (CountPlayerMuseumPaintings() >= CONTEST_CATEGORIES_COUNT);

	hofDebut = GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME);
	if (!GetGameStat(GAME_STAT_ENTERED_HOF))
		hofDebut = 0;

	trainerCard->hofDebutHours = hofDebut >> 16;
	trainerCard->hofDebutMinutes = (hofDebut >> 8) & 0xFF;
	trainerCard->hofDebutSeconds = hofDebut & 0xFF;

	if ((hofDebut >> 16) > 999)
	{
		trainerCard->hofDebutHours = 999;
		trainerCard->hofDebutMinutes = 59;
		trainerCard->hofDebutSeconds = 59;
	}

	trainerCard->caughtMonsCount = GetCaughtMonsCount();
	trainerCard->trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0];
	trainerCard->playTimeHours = gSaveBlock2Ptr->playTimeHours;
	trainerCard->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes;
	trainerCard->linkBattleWins = GetCappedGameStat(GAME_STAT_LINK_BATTLE_WINS, 9999);
	trainerCard->linkBattleLosses = GetCappedGameStat(GAME_STAT_LINK_BATTLE_LOSSES, 9999);
	trainerCard->battleTowerWins = gSaveBlock2Ptr->frontier.towerNumWins;
	trainerCard->battleTowerStraightWins = GetBattleTowerRecordStreak();
	trainerCard->contestsWithFriends = GetCappedGameStat(GAME_STAT_WON_LINK_CONTEST, 999);
	trainerCard->pokeblocksWithFriends = GetCappedGameStat(GAME_STAT_POKEBLOCKS_WITH_FRIENDS, 0xFFFF);
	trainerCard->pokemonTrades = GetCappedGameStat(GAME_STAT_POKEMON_TRADES, 0xFFFF);
	trainerCard->shinies = GetCappedGameStat(GAME_STAT_SHINIES_FOUND, 0xFFFF);
	trainerCard->money = GetMoney(&gSaveBlock1Ptr->money);

	for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
		trainerCard->easyChatProfile[i] = gSaveBlock1Ptr->easyChatProfile[i];

	StringCopy(trainerCard->playerName, gSaveBlock2Ptr->playerName);

	trainerCard->version = GAME_VERSION;
	trainerCard->secretId = (gSaveBlock2Ptr->playerTrainerId[3] << 8) | gSaveBlock2Ptr->playerTrainerId[2];
	//trainerCard->hasAllFrontierSymbols = HasAllFrontierSymbols();
	trainerCard->berryCrushPoints = GetCappedGameStat(GAME_STAT_PLAYED_BERRY_CRUSH, 0xFFFF);
	trainerCard->unionRoomNum = GetCappedGameStat(GAME_STAT_NUM_UNION_ROOM_BATTLES, 0xFFFF);
	trainerCard->berriesPicked = gSaveBlock2Ptr->berryPick.berriesPicked;
	trainerCard->jumpsInRow = gSaveBlock2Ptr->pokeJump.jumpsInRow;
	trainerCard->shouldDrawStickers = FALSE;
	trainerCard->hasAllMons = (trainerCard->caughtMonsCount == 386);
	trainerCard->monIconTint = VarGet(VAR_TRAINER_CARD_MON_ICON_TINT);

	if (trainerCard->gender == FEMALE)
		trainerCard->facilityClass = gLinkPlayerFacilityClasses[(trainerCard->trainerId % NUM_FEMALE_LINK_FACILITY_CLASSES) + NUM_MALE_LINK_FACILITY_CLASSES];
	else
		trainerCard->facilityClass = gLinkPlayerFacilityClasses[trainerCard->trainerId % NUM_MALE_LINK_FACILITY_CLASSES];

	for (i = 0; i < TRAINER_CARD_STICKER_TYPES; i++)
	{
		trainerCard->stickers[i] = gSaveBlock1Ptr->trainerCardStickers[i];
		if (trainerCard->stickers[i])
			trainerCard->shouldDrawStickers = TRUE;
	}

	trainerCard->versionModifier = VERSION_MODIFIER;
	trainerCard->monSpecies[0] = VarGet(VAR_TRAINER_CARD_MON_ICON_0);
	trainerCard->monSpecies[1] = VarGet(VAR_TRAINER_CARD_MON_ICON_1);
	trainerCard->monSpecies[2] = VarGet(VAR_TRAINER_CARD_MON_ICON_2);
	trainerCard->monSpecies[3] = VarGet(VAR_TRAINER_CARD_MON_ICON_3);
	trainerCard->monSpecies[4] = VarGet(VAR_TRAINER_CARD_MON_ICON_4);
	trainerCard->monSpecies[5] = VarGet(VAR_TRAINER_CARD_MON_ICON_5);
	trainerCard->hasAllSymbols = HasAllFrontierSymbols();
	trainerCard->frontierBP = gSaveBlock2Ptr->frontier.cardBattlePoints;
	trainerCard->monForm0 = 0;
	trainerCard->monForm1 = 0;
	trainerCard->monForm2 = 0;
	trainerCard->monForm3 = 0;
	trainerCard->monForm4 = 0;
	trainerCard->monForm5 = 0;
	trainerCard->stat0 = gSaveBlock1Ptr->trainerCardStat0;
	trainerCard->stat1 = gSaveBlock1Ptr->trainerCardStat1;
	trainerCard->stat2 = gSaveBlock1Ptr->trainerCardStat2;
	trainerCard->stat3 = gSaveBlock1Ptr->trainerCardStat3;
	trainerCard->stat4 = gSaveBlock1Ptr->trainerCardStat4;
	trainerCard->powerPoints = gSaveBlock2Ptr->totalEarnedPowerPoints;

	if (gSaveBlock2Ptr->totalEarnedPowerPoints > 0xFFFF)
		trainerCard->powerPoints = 0xFFFF;

	trainerCard->hSticker0 = gSaveBlock1Ptr->trainerCardStickers[3];
	trainerCard->hSticker1 = gSaveBlock1Ptr->trainerCardStickers[4];
	trainerCard->hSticker2 = gSaveBlock1Ptr->trainerCardStickers[5];
	trainerCard->displayDotCode = FlagGet(FLAG_DISPLAY_DOT_CODE);
}

void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    SetPlayerCardData(trainerCard);
}

void CopyTrainerCardData(struct TrainerCard *dst, u16 *src, u8 gameVersion, u8 versionModifier)
{
	memset(dst, 0, sizeof(struct TrainerCard));
	memcpy(dst, src, sizeof(struct TrainerCard));
}

static void SetDataFromTrainerCard(void)
{
    u8 i;
    u32 badgeFlag;

    sData->hasPokedex = FALSE;
    sData->hasHofResult = FALSE;
    sData->hasLinkResults = FALSE;
    sData->hasBattleTowerWins = FALSE;
    sData->unused_F = FALSE;
    sData->hasTrades = FALSE;
    memset(sData->badgeCount, 0, sizeof(sData->badgeCount));
    if (sData->trainerCard.hasPokedex)
        sData->hasPokedex++;

    if (sData->trainerCard.hofDebutHours
     || sData->trainerCard.hofDebutMinutes
     || sData->trainerCard.hofDebutSeconds)
        sData->hasHofResult++;

    if (sData->trainerCard.linkBattleWins || sData->trainerCard.linkBattleLosses)
        sData->hasLinkResults++;
    if (sData->trainerCard.pokemonTrades)
        sData->hasTrades++;
    if (sData->trainerCard.battleTowerWins || sData->trainerCard.battleTowerStraightWins)
        sData->hasBattleTowerWins++;

    for (i = 0, badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++, i++)
    {
        if (FlagGet(badgeFlag))
            sData->badgeCount[i]++;
    }
}

static void InitGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, DISPLAY_HEIGHT);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    if (gReceivedRemoteLinkPlayers)
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    else
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

static void UpdateCardFlipRegs(u16 cardTop)
{
    s8 blendY = (cardTop + 40) / 10;

    if (blendY <= 4)
        blendY = 0;
    sData->flipBlendY = blendY;
    SetGpuReg(REG_OFFSET_BLDY, sData->flipBlendY);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(sData->cardTop, DISPLAY_HEIGHT - sData->cardTop));
}

static void ResetGpuRegs(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

static void InitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sTrainerCardBgTemplates, ARRAY_COUNT(sTrainerCardBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sTrainerCardWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxAndBorderGfx();
}

static void SetTrainerCardCb2(void)
{
    SetMainCallback2(CB2_TrainerCard);
}

static void SetUpTrainerCardTask(void)
{
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(Task_TrainerCard, 0);
    InitTrainerCardData();
    SetDataFromTrainerCard();
}

static bool8 PrintAllOnCardFront(void)
{
	u16 palette;
    switch (sData->printState)
    {
    case 0:
		if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			palette = RGB(0, 0, 0);
			LoadPalette(&palette, 250, 2);
			palette = RGB(25, 25, 25);
			LoadPalette(&palette, 251, 2);
			palette = RGB(9, 9, 9);
			LoadPalette(&palette, 252, 2);
			palette = RGB(26, 26, 25);
			LoadPalette(&palette, 253, 2);
			palette = RGB(31, 0, 0);
			LoadPalette(&palette, 254, 2);
			palette = RGB(31, 0, 31);
			LoadPalette(&palette, 255, 2);
		}
		else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
		{
			palette = RGB(15, 28, 27);
			LoadPalette(&palette, 250, 2);
			palette = RGB(13, 25, 24);
			LoadPalette(&palette, 251, 2);
			palette = RGB(30, 26, 17);
			LoadPalette(&palette, 252, 2);
			palette = RGB(15, 18, 18);
			LoadPalette(&palette, 253, 2);
			palette = RGB(30, 25, 18);
			LoadPalette(&palette, 254, 2);
			palette = RGB(31, 30, 23);
			LoadPalette(&palette, 255, 2);
		}
        PrintNameOnCardFront();
        break;
    case 1:
        PrintIdOnCard();
        break;
    case 2:
        PrintMoneyOnCard();
        break;
    case 3:
        PrintPokedexOnCard();
        break;
    case 4:
        PrintTimeOnCard();
        break;
    case 5:
        PrintProfilePhraseOnCard();
        break;
	case 6:
		if (sData-> cardLayout == CARD_LAYOUT_HELIODOR)
			PrintBarcodeOnCard();
		break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static bool8 PrintAllOnCardBack(void)
{
    switch (sData->printState)
    {
    case 0:
        PrintNameOnCardBack();
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
	case 6:
		if (sData->stats[sData->printState - 1])
			PrintStatBySlot(sData->printState - 1);
		break;
	case 7:
		PrintPokemonIconsOnCard();
		break;
    case 8:
        PrintStickersOnCard();
        break;
    default:
        sData->printState = 0;
        return TRUE;
    }
    sData->printState++;
    return FALSE;
}

static void BufferTextsVarsForCardPage2(void)
{
    BufferNameForCardBack();
    BufferHofDebutTime();
    BufferLinkBattleResults();
    BufferNumTrades();
    BufferLinkPokeblocksNum();
    BufferLinkContestNum();
    BufferBattleTowerWins();
    BufferUnionRoomStats();
    BufferBerryCrushPoints();
    BufferBattlePoints();
    BufferShinyCount();
    BufferPowerPoints();
}

static void PrintNameOnCardFront(void)
{
    u8 buffer[32];
    u8* txtPtr;
	u8 x, y, font;
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 16;
		y = 32;
		font = 4;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 16;
		y = 33;
		font = 3;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 20;
		y = 29;
		font = 2;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 20;
		y = 28;
		font = 1;
	}
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSTextColors, TEXT_SPEED_FF, gText_RSCardName);
		txtPtr = StringCopy(buffer, sData->trainerCard.playerName);
		x += 32;
	}
	else
	{
		txtPtr = StringCopy(buffer, gText_TrainerCardName);
		StringCopy(txtPtr, sData->trainerCard.playerName);
	}
	ConvertInternationalString(txtPtr, sData->language);
	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, buffer);
	else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
}

static void PrintIdOnCard(void)
{
    u8 buffer[32];
    u8* txtPtr;
    u8 x, y, font;
	if (sData->cardLayout == CARD_LAYOUT_RS)
		txtPtr = StringCopy(buffer, gText_RSCardIDNo);
	else
		txtPtr = StringCopy(buffer, gText_TrainerCardIDNo);
    ConvertIntToDecimalStringN(txtPtr, sData->trainerCard.trainerId, STR_CONV_MODE_LEADING_ZEROS, 5);
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		y = 8;
		font = 4;
		x = GetStringCenterAlignXOffset(font, buffer, 96) + 107;
	}
	if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		y = 9;
		font = 3;
		x = GetStringCenterAlignXOffset(font, buffer, 96) + 120;
	}
    else if (sData->cardLayout == CARD_LAYOUT_FRLG)
    {
		y = 10;
        font = 2;
        x = GetStringCenterAlignXOffset(font, buffer, 80) + 132;
    }
    else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
    {
		y = 9;
        font = 1;
        x = GetStringCenterAlignXOffset(font, buffer, 80) + 130;
    }
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCard5StarIDColors, TEXT_SPEED_FF, buffer);
	else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
}

static void PrintMoneyOnCard(void)
{
    u8 x, y, font;

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 16;
		y = 56;
		font = 4;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 16;
		y = 57;
		font = 3;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 20;
		y = 56;
		font = 2;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 20;
		y = 56;
		font = 1;
	}
	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSTextColors, TEXT_SPEED_FF, gText_TrainerCardMoney);
    else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardMoney);
    ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.money, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
	if (sData->cardLayout == CARD_LAYOUT_RS)
		x = GetStringRightAlignXOffset(font, gStringVar4, 120);
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
		x = GetStringRightAlignXOffset(font, gStringVar4, 128);
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
		x = GetStringRightAlignXOffset(font, gStringVar4, 136);
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
		x = GetStringRightAlignXOffset(font, gStringVar4, 136);
	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, gStringVar4);
	else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gStringVar4);
}

static u16 GetCaughtMonsCount(void)
{
    if (IsNationalPokedexEnabled())
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    else
        return GetHoennPokedexCount(FLAG_GET_CAUGHT);
}

static void PrintPokedexOnCard(void)
{
    u8 x, y, font;
    if (FlagGet(FLAG_SYS_POKEDEX_GET))
    {
		if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			x = 16;
			y = 72;
			font = 4;
		}
		else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
		{
			x = 16;
			y = 73;
			font = 3;
		}
		else if (sData->cardLayout == CARD_LAYOUT_FRLG)
		{
			x = 20;
			y = 72;
			font = 2;
		}
		else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
		{
			x = 20;
			y = 72;
			font = 1;
		}
		if (sData->cardLayout == CARD_LAYOUT_RS)
			AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSTextColors, TEXT_SPEED_FF, gText_TrainerCardPokedex);
        else
			AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardPokedex);
        StringCopy(ConvertIntToDecimalStringN(gStringVar4, sData->trainerCard.caughtMonsCount, STR_CONV_MODE_LEFT_ALIGN, 3), gText_EmptyString6);
		if (sData->cardLayout == CARD_LAYOUT_RS)
			x = GetStringRightAlignXOffset(font, gStringVar4, 120);
		else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
			x = GetStringRightAlignXOffset(font, gStringVar4, 128);
		else if (sData->cardLayout == CARD_LAYOUT_FRLG)
			x = GetStringRightAlignXOffset(font, gStringVar4, 136);
		else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
			x = GetStringRightAlignXOffset(font, gStringVar4, 136);
		if (sData->cardLayout == CARD_LAYOUT_RS)
			AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, gStringVar4);
		else
			AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gStringVar4);
    }
}

static const u8 *const sTimeColonTextColors[] = {sTrainerCardTextColors, sTimeColonInvisibleTextColors};
static const u8 *const sTimeColonRSTextColors[] = {sTrainerCardRSContentColors, sTimeColonInvisibleTextColors};

static void PrintTimeOnCard(void)
{
    u16 hours;
    u16 minutes;
    s32 width;
    u32 x, y, totalWidth;
	u8 font;
	
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 16;
		y = 88;
		font = 4;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 16;
		y = 89;
		font = 3;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 20;
		y = 88;
		font = 2;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 20;
		y = 88;
		font = 1;
	}
	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSTextColors, TEXT_SPEED_FF, gText_RSCardTime);
	else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gText_TrainerCardTime);

    if (sData->isLink)
    {
        hours = sData->trainerCard.playTimeHours;
        minutes = sData->trainerCard.playTimeMinutes;
    }
    else
    {
        hours = gSaveBlock2Ptr->playTimeHours;
        minutes = gSaveBlock2Ptr->playTimeMinutes;
    }

    if (hours > 999)
        hours = 999;
    if (minutes > 59)
        minutes = 59;
	if (sData->cardLayout == CARD_LAYOUT_RS)
		width = GetStringWidth(font, gText_RSCardColon, 0);
	else
		width = GetStringWidth(font, gText_Colon2, 0);

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 124;
		totalWidth = width + 34;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 128;
		totalWidth = width + 30;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 136;
		totalWidth = width + 30;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 136;
		totalWidth = width + 30;
	}
    x -= totalWidth;

    FillWindowPixelRect(1, PIXEL_FILL(0), x, y, totalWidth, 15);
    ConvertIntToDecimalStringN(gStringVar4, hours, STR_CONV_MODE_RIGHT_ALIGN, 3);
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, gStringVar4);
		x += 18;
		AddTextPrinterParameterized3(1, font, x, y, sTimeColonRSTextColors[sData->timeColonInvisible], TEXT_SPEED_FF, gText_RSCardColon);
		x += width;
		ConvertIntToDecimalStringN(gStringVar4, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, gStringVar4);
	}
	else
	{
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gStringVar4);
		x += 18;
		AddTextPrinterParameterized3(1, font, x, y, sTimeColonTextColors[sData->timeColonInvisible], TEXT_SPEED_FF, gText_Colon2);
		x += width;
		ConvertIntToDecimalStringN(gStringVar4, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, gStringVar4);
	}
}

static void PrintProfilePhraseOnCard(void)
{
	u8 x, y1, y2, font, i;
	u8 buffer[32];
	u8 space = 6;

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 8;
		y1 = 104;
		y2 = 120;
		font = 4;
		space = 3;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 8;
		y1 = 104;
		y2 = 120;
		font = 3;
		space = 6;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 10;
		y1 = 115;
		y2 = 130;
		font = 2;
		space = 6;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 10;
		y1 = 114;
		y2 = 129;
		font = 1;
		space = 6;
	}

    if (sData->isLink)
    {
		if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
		{
			AddTextPrinterParameterized3(1, font, x, y1, sTrainerCard5StarPhraseTextColors, TEXT_SPEED_FF, sData->easyChatProfile[0]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[0], 0) + space + x, y1, sTrainerCard5StarPhraseTextColors, TEXT_SPEED_FF, sData->easyChatProfile[1]);
			AddTextPrinterParameterized3(1, font, x, y2, sTrainerCard5StarPhraseTextColors, TEXT_SPEED_FF, sData->easyChatProfile[2]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[2], 0) + space + x, y2, sTrainerCard5StarPhraseTextColors, TEXT_SPEED_FF, sData->easyChatProfile[3]);
		}
		else if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			AddTextPrinterParameterized3(1, font, x, y1, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->easyChatProfile[0]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[0], 0) + space + x, y1, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->easyChatProfile[1]);
			AddTextPrinterParameterized3(1, font, x, y2, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->easyChatProfile[2]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[2], 0) + space + x, y2, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->easyChatProfile[3]);
		}
		else if (sData->isDX)
		{
			StringCopy(buffer, sData->easyChatProfile[0]);
			for (i = 0; i < 32; i++)
			{
				if (buffer[i] == 0)
					buffer[i] = 10;
			}
			AddTextPrinterParameterized3(1, font, x, y1, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
			StringCopy(buffer, sData->easyChatProfile[1]);
			for (i = 0; i < 32; i++)
			{
				if (buffer[i] == 0)
					buffer[i] = 10;
			}
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[0], 0) + space + x, y1, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
			StringCopy(buffer, sData->easyChatProfile[2]);
			for (i = 0; i < 32; i++)
			{
				if (buffer[i] == 0)
					buffer[i] = 10;
			}
			AddTextPrinterParameterized3(1, font, x, y2, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
			StringCopy(buffer, sData->easyChatProfile[3]);
			for (i = 0; i < 32; i++)
			{
				if (buffer[i] == 0)
					buffer[i] = 10;
			}
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[2], 0) + space + x, y2, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
		}
		else
		{
			AddTextPrinterParameterized3(1, font, x, y1, sTrainerCardTextColors, TEXT_SPEED_FF, sData->easyChatProfile[0]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[0], 0) + space + x, y1, sTrainerCardTextColors, TEXT_SPEED_FF, sData->easyChatProfile[1]);
			AddTextPrinterParameterized3(1, font, x, y2, sTrainerCardTextColors, TEXT_SPEED_FF, sData->easyChatProfile[2]);
			AddTextPrinterParameterized3(1, font, GetStringWidth(font, sData->easyChatProfile[2], 0) + space + x, y2, sTrainerCardTextColors, TEXT_SPEED_FF, sData->easyChatProfile[3]);
		}
    }
}

static const u8 sText_BarcodeStart[] = _("{JPV_START}\n");
static const u8 sText_BarcodeEnd[] = _("{JPV_END}\n");
static const u8 sText_Barcode0[] = _("{JPV_0}\n");
static const u8 sText_Barcode1[] = _("{JPV_1}\n");
static const u8 sText_Barcode2[] = _("{JPV_2}\n");
static const u8 sText_Barcode3[] = _("{JPV_3}\n");
static const u8 sText_Barcode4[] = _("{JPV_4}\n");
static const u8 sText_Barcode5[] = _("{JPV_5}\n");
static const u8 sText_Barcode6[] = _("{JPV_6}\n");
static const u8 sText_Barcode7[] = _("{JPV_7}\n");
static const u8 sText_Barcode8[] = _("{JPV_8}\n");
static const u8 sText_Barcode9[] = _("{JPV_9}\n");
static const u8 sText_BarcodeDash[] = _("{JPV_DASH}\n");
static const u8 sText_BarcodeCC1[] = _("{JPV_CC1}\n");
static const u8 sText_BarcodeCC2[] = _("{JPV_CC2}\n");
static const u8 sText_BarcodeCC3[] = _("{JPV_CC3}\n");

static const u8 sText_BarcodeA[] = _("{JPV_CC1}\n{JPV_0}\n");
static const u8 sText_BarcodeB[] = _("{JPV_CC1}\n{JPV_1}\n");
static const u8 sText_BarcodeC[] = _("{JPV_CC1}\n{JPV_2}\n");
static const u8 sText_BarcodeD[] = _("{JPV_CC1}\n{JPV_3}\n");
static const u8 sText_BarcodeE[] = _("{JPV_CC1}\n{JPV_4}\n");
static const u8 sText_BarcodeF[] = _("{JPV_CC1}\n{JPV_5}\n");
static const u8 sText_BarcodeG[] = _("{JPV_CC1}\n{JPV_6}\n");
static const u8 sText_BarcodeH[] = _("{JPV_CC1}\n{JPV_7}\n");
static const u8 sText_BarcodeI[] = _("{JPV_CC1}\n{JPV_8}\n");
static const u8 sText_BarcodeJ[] = _("{JPV_CC1}\n{JPV_9}\n");
static const u8 sText_BarcodeK[] = _("{JPV_CC2}\n{JPV_0}\n");
static const u8 sText_BarcodeL[] = _("{JPV_CC2}\n{JPV_1}\n");
static const u8 sText_BarcodeM[] = _("{JPV_CC2}\n{JPV_2}\n");
static const u8 sText_BarcodeN[] = _("{JPV_CC2}\n{JPV_3}\n");
static const u8 sText_BarcodeO[] = _("{JPV_CC2}\n{JPV_4}\n");
static const u8 sText_BarcodeP[] = _("{JPV_CC2}\n{JPV_5}\n");
static const u8 sText_BarcodeQ[] = _("{JPV_CC2}\n{JPV_6}\n");
static const u8 sText_BarcodeR[] = _("{JPV_CC2}\n{JPV_7}\n");
static const u8 sText_BarcodeS[] = _("{JPV_CC2}\n{JPV_8}\n");
static const u8 sText_BarcodeT[] = _("{JPV_CC2}\n{JPV_9}\n");
static const u8 sText_BarcodeU[] = _("{JPV_CC3}\n{JPV_0}\n");
static const u8 sText_BarcodeV[] = _("{JPV_CC3}\n{JPV_1}\n");
static const u8 sText_BarcodeW[] = _("{JPV_CC3}\n{JPV_2}\n");
static const u8 sText_BarcodeX[] = _("{JPV_CC3}\n{JPV_3}\n");
static const u8 sText_BarcodeY[] = _("{JPV_CC3}\n{JPV_4}\n");
static const u8 sText_BarcodeZ[] = _("{JPV_CC3}\n{JPV_5}\n");

static void PrintBarcodeOnCard(void)
{
	u8 buffer[64];
	u8* barcode;
	u32 i;

	barcode = StringCopy(buffer, sText_BarcodeStart);

	for (i = 10000; i > 0; i /= 10)
		StringAppend(barcode, ConvertDigitToBarcodeSymbol((sData->trainerCard.secretId / i) % 10));
	for (i = 10000; i > 0; i /= 10)
		StringAppend(barcode, ConvertDigitToBarcodeSymbol((sData->trainerCard.trainerId / i) % 10));
	for (i = 0; i < 7; i++)
	{
		sData->trainerCard.playerName[i] = sData->trainerCard.playerName[i];	// Need to figure out why it crashes without doing something like this
		StringAppend(barcode, ConvertLetterToBarcodeSymbol(sData->trainerCard.playerName[i]));
	}

	StringAppend(barcode, sText_BarcodeEnd);

	if ((sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
		AddTextPrinterParameterized4(1, 0, 1, 2, 0, -4, sTrainerCard5StarNameColors, TEXT_SPEED_FF, buffer);
	else
		AddTextPrinterParameterized4(1, 0, 1, 2, 0, -4, sTrainerCardTextColors, TEXT_SPEED_FF, buffer);
}

static const u8 *ConvertDigitToBarcodeSymbol(u8 digit)
{
	switch (digit % 10)
	{
		case 0:
			return sText_Barcode0;
		case 1:
			return sText_Barcode1;
		case 2:
			return sText_Barcode2;
		case 3:
			return sText_Barcode3;
		case 4:
			return sText_Barcode4;
		case 5:
			return sText_Barcode5;
		case 6:
			return sText_Barcode6;
		case 7:
			return sText_Barcode7;
		case 8:
			return sText_Barcode8;
		case 9:
			return sText_Barcode9;
	}
}

static const u8 *ConvertLetterToBarcodeSymbol(u8 letter)
{
	switch (letter)
	{
		case 0xBB:
		case 0xD5:
			return sText_BarcodeA;
		case 0xBC:
		case 0xD6:
			return sText_BarcodeB;
		case 0xBD:
		case 0xD7:
			return sText_BarcodeC;
		case 0xBE:
		case 0xD8:
			return sText_BarcodeD;
		case 0xBF:
		case 0xD9:
			return sText_BarcodeE;
		case 0xC0:
		case 0xDA:
			return sText_BarcodeF;
		case 0xC1:
		case 0xDB:
			return sText_BarcodeG;
		case 0xC2:
		case 0xDC:
			return sText_BarcodeH;
		case 0xC3:
		case 0xDD:
			return sText_BarcodeI;
		case 0xC4:
		case 0xDE:
			return sText_BarcodeJ;
		case 0xC5:
		case 0xDF:
			return sText_BarcodeK;
		case 0xC6:
		case 0xE0:
			return sText_BarcodeL;
		case 0xC7:
		case 0xE1:
			return sText_BarcodeM;
		case 0xC8:
		case 0xE2:
			return sText_BarcodeN;
		case 0xC9:
		case 0xE3:
			return sText_BarcodeO;
		case 0xCA:
		case 0xE4:
			return sText_BarcodeP;
		case 0xCB:
		case 0xE5:
			return sText_BarcodeQ;
		case 0xCC:
		case 0xE6:
			return sText_BarcodeR;
		case 0xCD:
		case 0xE7:
			return sText_BarcodeS;
		case 0xCE:
		case 0xE8:
			return sText_BarcodeT;
		case 0xCF:
		case 0xE9:
			return sText_BarcodeU;
		case 0xD0:
		case 0xEA:
			return sText_BarcodeV;
		case 0xD1:
		case 0xEB:
			return sText_BarcodeW;
		case 0xD2:
		case 0xEC:
			return sText_BarcodeX;
		case 0xD3:
		case 0xED:
			return sText_BarcodeY;
		case 0xD4:
		case 0xEE:
			return sText_BarcodeZ;
		default:
			return sText_BarcodeDash;
	}
}

static void BufferNameForCardBack(void)
{
    StringCopy(sData->textPlayersCard, sData->trainerCard.playerName);
    ConvertInternationalString(sData->textPlayersCard, sData->language);
    if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
    {
        StringCopy(gStringVar1, sData->textPlayersCard);
        StringExpandPlaceholders(sData->textPlayersCard, gText_Var1sTrainerCard);
    }
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		StringCopy(gStringVar1, sData->textPlayersCard);
		StringExpandPlaceholders(sData->textPlayersCard, gText_HCardTrainerName);
	}
}

static void PrintNameOnCardBack(void)
{
	u8 x, y, font;
    u8 buffer[32];
    u8* txtPtr;

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		y = 8;
		font = 4;
		x = GetStringRightAlignXOffset(font, sData->textPlayersCard, 216);
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		y = 9;
		font = 3;
		x = GetStringRightAlignXOffset(font, sData->textPlayersCard, 216);
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 138;
		y = 11;
		font = 2;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		txtPtr = StringCopy(buffer, sData->textPlayersCard);
		y = 9;
		font = 0;
		x = GetStringCenterAlignXOffset(font, buffer, 240) - 7;
	}
	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->textPlayersCard);
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCard5StarNameColors, TEXT_SPEED_FF, sData->textPlayersCard);
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardHNameColors, TEXT_SPEED_FF, sData->textPlayersCard);
	else
		AddTextPrinterParameterized3(1, font, x, y, sTrainerCardTextColors, TEXT_SPEED_FF, sData->textPlayersCard);
}

static void PrintStatOnBackOfCard(u8 top, const u8* statName, u8* stat, const u8* color)
{
	u8 x, y, font;

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		x = 16;
		y = 32;
		font = 4;
	}
	else if (sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		x = 16;
		y = 33;
		font = 3;
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		x = 10;
		y = 35;
		font = 2;
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		x = 10;
		y = 35;
		font = 1;
	}

	if (sData->cardLayout == CARD_LAYOUT_RS)
		AddTextPrinterParameterized3(1, font, x, top * 16 + y, sTrainerCardRSContentColors, TEXT_SPEED_FF, statName);
	else
		AddTextPrinterParameterized3(1, font, x, top * 16 + y, sTrainerCardTextColors, TEXT_SPEED_FF, statName);
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
		AddTextPrinterParameterized3(1, font, GetStringRightAlignXOffset(font, stat, 216), top * 16 + y, sTrainerCard5StarStatColors, TEXT_SPEED_FF, stat);
	else
		AddTextPrinterParameterized3(1, font, GetStringRightAlignXOffset(font, stat, 216), top * 16 + y, color, TEXT_SPEED_FF, stat);
}

static void PrintStatBySlot(u8 slot)
{
	switch (sData->stats[slot])
	{
		case CARD_STAT_HOF_DEBUT:
			PrintHofDebutTimeOnCard(slot);
			break;
		case CARD_STAT_LINK_BATTLES:
			PrintLinkBattleResultsOnCard(slot);
			break;
		case CARD_STAT_TRADES:
			PrintTradesStringOnCard(slot);
			break;
		case CARD_STAT_POKEBLOCKS:
			PrintPokeblockStringOnCard(slot);
			break;
		case CARD_STAT_CONTESTS:
			PrintContestStringOnCard(slot);
			break;
		case CARD_STAT_BATTLE_TOWER:
			PrintBattleTowerStringOnCard(slot);
			break;
		case CARD_STAT_UNION_ROOM:
			PrintUnionStringOnCard(slot);
			break;
		case CARD_STAT_BERRY_CRUSH:
			PrintBerryCrushStringOnCard(slot);
			break;
		case CARD_STAT_BATTLE_POINTS:
			PrintBattlePointsStringOnCard(slot);
			break;
		case CARD_STAT_SHINIES:
			PrintShinyCountStringOnCard(slot);
			break;
		case CARD_STAT_POWER_POINTS:
			PrintPowerPointsStringOnCard(slot);
			break;
	}
}

static const u8 sText_HofTime[] = _("{STR_VAR_1}:{STR_VAR_2}:{STR_VAR_3}");

static void BufferHofDebutTime(void)
{
	ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.hofDebutHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
	ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.hofDebutMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
	ConvertIntToDecimalStringN(gStringVar3, sData->trainerCard.hofDebutSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
	StringExpandPlaceholders(sData->textHofTime, sText_HofTime);
	if (!sData->hasHofResult)
		StringCopy(sData->textHofTime, gText_HCardNA);
}

static void PrintHofDebutTimeOnCard(u8 slot)
{
	u8 *str;
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		PrintStatOnBackOfCard(slot, gText_HallOfFameDebut, sData->textHofTime, sTrainerCardStatColors);
	}
    else if (sData->hasHofResult)
	{
		if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			str = gStringVar1;
			str = ConvertIntToDecimalStringN(str, sData->trainerCard.hofDebutHours, STR_CONV_MODE_RIGHT_ALIGN, 3);
			str = StringCopy(str, gText_RSCardColon);
			str = ConvertIntToDecimalStringN(str, sData->trainerCard.hofDebutMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
			str = StringCopy(str, gText_RSCardColon);
			str = ConvertIntToDecimalStringN(str, sData->trainerCard.hofDebutSeconds, STR_CONV_MODE_LEADING_ZEROS, 2);
			AddTextPrinterParameterized3(1, 4, 16, slot * 16 + 32, sTrainerCardRSContentColors, TEXT_SPEED_FF, gText_RSCardHallOfFame);
			AddTextPrinterParameterized3(1, 4, GetStringRightAlignXOffset(4, gStringVar1, 216), slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, gStringVar1);
		}
		else
		{
			PrintStatOnBackOfCard(slot, gText_HallOfFameDebut, sData->textHofTime, sTrainerCardStatColors);
		}
	}
}

static void BufferLinkBattleResults(void)
{
	if (sData->cardLayout == CARD_LAYOUT_RS)
		StringCopy(sData->textLinkBattleType, gText_RSCardBattles);
	else
		StringCopy(sData->textLinkBattleType, gText_LinkBattles);
	if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		ConvertIntToDecimalStringN(sData->textLinkBattleWins, sData->trainerCard.linkBattleWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
		ConvertIntToDecimalStringN(sData->textLinkBattleLosses, sData->trainerCard.linkBattleLosses, STR_CONV_MODE_RIGHT_ALIGN, 4);
	}
	else
	{
		ConvertIntToDecimalStringN(sData->textLinkBattleWins, sData->trainerCard.linkBattleWins, STR_CONV_MODE_LEFT_ALIGN, 4);
		ConvertIntToDecimalStringN(sData->textLinkBattleLosses, sData->trainerCard.linkBattleLosses, STR_CONV_MODE_LEFT_ALIGN, 4);
	}
}

static void PrintLinkBattleResultsOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
	{
		AddTextPrinterParameterized3(1, 1, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, sData->textLinkBattleType);
		AddTextPrinterParameterized3(1, 1, 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardWinsLosses);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textLinkBattleWins, 168), slot * 16 + 35, sTrainerCard5StarStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textLinkBattleLosses, 216), slot * 16 + 35, sTrainerCard5StarStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
	}
    else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		AddTextPrinterParameterized3(1, 1, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, sData->textLinkBattleType);
		AddTextPrinterParameterized3(1, 1, 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardWinsLosses);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textLinkBattleWins, 168), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textLinkBattleLosses, 216), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
	}
    else if (sData->hasLinkResults)
    {
		if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			AddTextPrinterParameterized3(1, 4, 16, slot * 16 + 32, sTrainerCardRSContentColors, TEXT_SPEED_FF, sData->textLinkBattleType);
			AddTextPrinterParameterized3(1, 4, GetStringRightAlignXOffset(4, sData->textLinkBattleWins, 168), slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
			AddTextPrinterParameterized3(1, 4, GetStringRightAlignXOffset(4, sData->textLinkBattleLosses, 216), slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
		}
		else if (sData->cardLayout == CARD_LAYOUT_FRLG)
		{
			AddTextPrinterParameterized3(1, 2, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, sData->textLinkBattleType);
			AddTextPrinterParameterized3(1, 2, 130, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_FRLGCardWinsLosses);
			AddTextPrinterParameterized3(1, 2, 144, slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleWins);
			AddTextPrinterParameterized3(1, 2, 192, slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textLinkBattleLosses);
		}
		else
		{
			StringCopy(gStringVar1, sData->textLinkBattleWins);
			StringCopy(gStringVar2, sData->textLinkBattleLosses);
			StringExpandPlaceholders(gStringVar4, gText_WinsLosses);
			PrintStatOnBackOfCard(slot, sData->textLinkBattleType, gStringVar4, sTrainerCardTextColors);
		}
    }
}

static void BufferNumTrades(void)
{
	ConvertIntToDecimalStringN(sData->textNumTrades, sData->trainerCard.pokemonTrades, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintTradesStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		PrintStatOnBackOfCard(slot, gText_PokemonTrades, sData->textNumTrades, sTrainerCardStatColors);
	}
    else if (sData->hasTrades)
	{
		if (sData->cardLayout == CARD_LAYOUT_RS)
			PrintStatOnBackOfCard(slot, gText_PokemonTrades, sData->textNumTrades, sTrainerCardRSStatColors);
		else
			PrintStatOnBackOfCard(slot, gText_PokemonTrades, sData->textNumTrades, sTrainerCardStatColors);
	}
}

static void BufferLinkPokeblocksNum(void)
{
	ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.pokeblocksWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 5);
	StringExpandPlaceholders(sData->textNumLinkPokeblocks, gText_NumPokeblocks);
}

static void PrintPokeblockStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		PrintStatOnBackOfCard(slot, gText_PokeblocksWithFriends, sData->textNumLinkPokeblocks, sTrainerCardStatColors);
	}
	else if (sData->trainerCard.pokeblocksWithFriends)
	{
		if (sData->cardLayout == CARD_LAYOUT_RS)
			PrintStatOnBackOfCard(slot, gText_PokeblocksWithFriends, sData->textNumLinkPokeblocks, sTrainerCardRSStatColors);
		else
			PrintStatOnBackOfCard(slot, gText_PokeblocksWithFriends, sData->textNumLinkPokeblocks, sTrainerCardStatColors);
	}
}

static void BufferLinkContestNum(void)
{
	ConvertIntToDecimalStringN(sData->textNumLinkContests, sData->trainerCard.contestsWithFriends, STR_CONV_MODE_RIGHT_ALIGN, 3);
}

static void PrintContestStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		PrintStatOnBackOfCard(slot, gText_WonContestsWFriends, sData->textNumLinkContests, sTrainerCardStatColors);
	}
	else if (sData->trainerCard.contestsWithFriends)
	{
		if (sData->cardLayout == CARD_LAYOUT_RS)
			PrintStatOnBackOfCard(slot, gText_RSCardContests, sData->textNumLinkContests, sTrainerCardRSStatColors);
		else
			PrintStatOnBackOfCard(slot, gText_WonContestsWFriends, sData->textNumLinkContests, sTrainerCardStatColors);
	}
}

static void BufferBattleTowerWins(void)
{
	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.battleTowerWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
		ConvertIntToDecimalStringN(gStringVar2, sData->trainerCard.battleTowerStraightWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
		StringExpandPlaceholders(sData->textBattleTowerWins, gText_RSCardTowerStats);
	}
	else
	{
		ConvertIntToDecimalStringN(sData->textBattleTowerWins, sData->trainerCard.battleTowerWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
		ConvertIntToDecimalStringN(sData->textBattleTowerStreak, sData->trainerCard.battleTowerStraightWins, STR_CONV_MODE_RIGHT_ALIGN, 4);
	}
}

static void PrintBattleTowerStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR && (sData->trainerCard.stars + sData->trainerCard.extraStars) > 4)
	{
		AddTextPrinterParameterized3(1, 1, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTower);
		AddTextPrinterParameterized3(1, 1, 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTowerStats);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerWins, 168), slot * 16 + 35, sTrainerCard5StarStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerStreak, 216), slot * 16 + 35, sTrainerCard5StarStatColors, TEXT_SPEED_FF, sData->textBattleTowerStreak);
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		AddTextPrinterParameterized3(1, 1, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTower);
		AddTextPrinterParameterized3(1, 1, 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTowerStats);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerWins, 168), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
		AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerStreak, 216), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerStreak);
	}
	else if (sData->hasBattleTowerWins)
	{
		if (sData->cardLayout == CARD_LAYOUT_RS)
		{
			AddTextPrinterParameterized3(1, 4, 16, slot * 16 + 32, sTrainerCardRSContentColors, TEXT_SPEED_FF, gText_RSCardTower);
			AddTextPrinterParameterized3(1, 4, 104, slot * 16 + 32, sTrainerCardRSStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
		}
		else
		{
			AddTextPrinterParameterized3(1, 1, 10, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTower);
			AddTextPrinterParameterized3(1, 1, 127, slot * 16 + 35, sTrainerCardTextColors, TEXT_SPEED_FF, gText_HCardTowerStats);
			AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerWins, 168), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerWins);
			AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, sData->textBattleTowerStreak, 216), slot * 16 + 35, sTrainerCardStatColors, TEXT_SPEED_FF, sData->textBattleTowerStreak);
		}
	}
}

static void BufferUnionRoomStats(void)
{
	ConvertIntToDecimalStringN(sData->textUnionRoomStats, sData->trainerCard.unionRoomNum, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintUnionStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR || sData->trainerCard.unionRoomNum)
		PrintStatOnBackOfCard(slot, gText_UnionTradesAndBattles, sData->textUnionRoomStats, sTrainerCardStatColors);
}

static void BufferBerryCrushPoints(void)
{
	ConvertIntToDecimalStringN(sData->textBerryCrushPts, sData->trainerCard.berryCrushPoints, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintBerryCrushStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR || sData->trainerCard.berryCrushPoints)
		PrintStatOnBackOfCard(slot, gText_BERRYCrush, sData->textBerryCrushPts, sTrainerCardStatColors);
}

static void BufferBattlePoints(void)
{
    ConvertIntToDecimalStringN(gStringVar1, sData->trainerCard.frontierBP, STR_CONV_MODE_RIGHT_ALIGN, 5);
	StringExpandPlaceholders(sData->textBattlePoints, gText_NumBP);
}

static void PrintBattlePointsStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR || sData->trainerCard.frontierBP)
		PrintStatOnBackOfCard(slot, gText_BattlePtsWon, sData->textBattlePoints, sTrainerCardStatColors);
}

static void BufferShinyCount(void)
{
	ConvertIntToDecimalStringN(sData->textShinyCount, sData->trainerCard.shinies, STR_CONV_MODE_RIGHT_ALIGN, 5);
}

static void PrintShinyCountStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR || sData->trainerCard.shinies)
		PrintStatOnBackOfCard(slot, gText_HCardShinyCount, sData->textShinyCount, sTrainerCardStatColors);
}

static void BufferPowerPoints(void)
{
	ConvertUIntToDecimalStringN(gStringVar1, sData->trainerCard.powerPoints, STR_CONV_MODE_RIGHT_ALIGN, 5);
	StringExpandPlaceholders(sData->textPowerPoints, gText_HCardNumPowerPoints);
}

static void PrintPowerPointsStringOnCard(u8 slot)
{
	if (sData->cardLayout == CARD_LAYOUT_HELIODOR || sData->trainerCard.powerPoints)
		PrintStatOnBackOfCard(slot, gText_HCardPowerPoints, sData->textPowerPoints, sTrainerCardStatColors);
}

static void PrintPokemonIconsOnCard(void)
{
    u8 i;
    u8 paletteSlots[PARTY_SIZE] = {5, 6, 7, 8, 9, 10};
    u8 xOffsets[PARTY_SIZE] = {0, 4, 8, 12, 16, 20};

    if (sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_HELIODOR)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sData->trainerCard.monSpecies[i])
            {
                u8 monSpecies = GetMonIconPaletteIndexFromSpecies(sData->trainerCard.monSpecies[i]);
				WriteSequenceToBgTilemapBuffer(3, 16 * i + 224, xOffsets[i] + 3, 15, 4, 4, paletteSlots[monSpecies], 1);
            }
        }
    }
}

static void LoadMonIconGfx(void)
{
    u8 i;

    CpuSet(gMonIconPalettes, sData->monIconPal, 0x60);
    switch (sData->trainerCard.monIconTint)
    {
    case MON_ICON_TINT_NORMAL:
        break;
    case MON_ICON_TINT_BLACK:
        TintPalette_CustomTone(sData->monIconPal, 96, 0, 0, 0);
        break;
    case MON_ICON_TINT_PINK:
        TintPalette_CustomTone(sData->monIconPal, 96, 500, 330, 310);
        break;
    case MON_ICON_TINT_SEPIA:
        TintPalette_SepiaTone(sData->monIconPal, 96);
        break;
    }
    LoadPalette(sData->monIconPal, 80, 192);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sData->trainerCard.monSpecies[i])
            LoadBgTiles(3, GetMonIconTiles(sData->trainerCard.monSpecies[i], 0), 512, 16 * i + 32);
    }
}

static void PrintStickersOnCard(void)
{
    u8 i, sticker;
    u8 paletteSlots[4] = {11, 12, 13, 14};

    if ((sData->cardLayout == CARD_LAYOUT_FRLG || sData->cardLayout == CARD_LAYOUT_HELIODOR) && sData->trainerCard.shouldDrawStickers == TRUE)
    {
        for (i = 0; i < TRAINER_CARD_STICKER_TYPES; i++)
        {
            sticker = sData->trainerCard.stickers[i];
            if (sData->trainerCard.stickers[i])
                WriteSequenceToBgTilemapBuffer(3, i * 4 + 320, i * 3 + 2, 2, 2, 2, paletteSlots[sticker - 1], 1);
        }
    }
    if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
    {
		sticker = sData->trainerCard.hSticker0;
		if (sData->trainerCard.hSticker0)
			WriteSequenceToBgTilemapBuffer(3, 336, 20, 2, 2, 2, paletteSlots[sticker - 1], 1);
		sticker = sData->trainerCard.hSticker1;
		if (sData->trainerCard.hSticker1)
			WriteSequenceToBgTilemapBuffer(3, 340, 23, 2, 2, 2, paletteSlots[sticker - 1], 1);
		sticker = sData->trainerCard.hSticker2;
		if (sData->trainerCard.hSticker2)
			WriteSequenceToBgTilemapBuffer(3, 344, 26, 2, 2, 2, paletteSlots[sticker - 1], 1);
    }
}

static void LoadStickerGfx(void)
{
    LoadPalette(sTrainerCardSticker1_Pal, 176, 32);
    LoadPalette(sTrainerCardSticker2_Pal, 192, 32);
    LoadPalette(sTrainerCardSticker3_Pal, 208, 32);
    LoadPalette(sTrainerCardSticker4_Pal, 224, 32);
    LoadBgTiles(3, sData->stickerTiles, 1024, 128);
    LoadBgTiles(3, sData->hStickerTiles, 1024, 144);
}

static void DrawTrainerCardWindow(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static u8 SetCardBgsAndPals(void)
{
	u8 stars;
    switch (sData->bgPalLoadState)
    {
    case 0:
        LoadBgTiles(3, sData->badgeTiles, ARRAY_COUNT(sData->badgeTiles), 0);
        break;
    case 1:
        LoadBgTiles(0, sData->cardTiles, 0x1800, 0);
        break;
    case 2:
        if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
        {
            LoadPalette(sHoennTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sHoennTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sHoennTrainerCardFemaleBg_Pal, 16, 32);
        }
        else if (sData->cardLayout == CARD_LAYOUT_FRLG)
        {
            LoadPalette(sKantoTrainerCardStarPals[sData->trainerCard.stars], 0, 96);
            LoadPalette(sHoennTrainerCardBadges_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sKantoTrainerCardFemaleBg_Pal, 16, 32);
        }
        else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
        {
			stars = sData->trainerCard.stars + sData->trainerCard.extraStars;
			if (stars > 5)
				stars = 5;
            LoadPalette(sKantoTrainerCardStarPals[stars], 0, 96);
            LoadPalette(sHoennTrainerCardBadges1_Pal, 32, 32);
            LoadPalette(sHoennTrainerCardBadges2_Pal, 48, 32);
            if (sData->trainerCard.gender != MALE)
                LoadPalette(sKantoTrainerCardFemaleBg_Pal, 16, 32);
        }
		if (sData->cardLayout == CARD_LAYOUT_RS)
			LoadPalette(sTrainerCardGoldRS_Pal, 64, 32);
		else
			LoadPalette(sTrainerCardGold_Pal, 64, 32);
        break;
    case 3:
        SetBgTilemapBuffer(0, sData->cardTilemapBuffer);
        SetBgTilemapBuffer(2, sData->bgTilemapBuffer);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return 1;
    }
    sData->bgPalLoadState++;
    return 0;
}

static void DrawCardScreenBackground(u16 *ptr)
{
    s16 i, j;
    u16 *dst = sData->bgTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(2);
}

static void DrawCardFrontOrBack(u16* ptr)
{
    s16 i, j;
    u16 *dst = sData->cardTilemapBuffer;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if (j < 30)
                dst[32 * i + j] = ptr[30 * i + j];
            else
                dst[32 * i + j] = ptr[0];
        }
    }
    CopyBgTilemapBufferToVram(0);
}

static void DrawStarsAndBadgesOnCard(void)
{
    s16 i, x, y;
    u16 tileNum = 192;

	if (sData->cardLayout == CARD_LAYOUT_RS)
	{
		FillBgTilemapBufferRect(3, 143, 15, 6, sData->trainerCard.stars, 1, 4);
	}
	else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
	{
		FillBgTilemapBufferRect(3, 143, 18 - (sData->trainerCard.stars + sData->trainerCard.extraStars), 7, sData->trainerCard.stars + sData->trainerCard.extraStars, 1, 4);
	}
	else
	{
		FillBgTilemapBufferRect(3, 143, 15, 7, sData->trainerCard.stars, 1, 4);
	}
    if (!sData->isLink)
    {
        x = 4;
        for (i = 0; i < NUM_BADGES; i++, tileNum += 2, x += 3)
        {
            if (sData->badgeCount[i])
            {
				if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
				{
					FillBgTilemapBufferRect(3, tileNum, x, 15, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 1, x + 1, 15, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 16, x, 16, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 17, x + 1, 16, 1, 1, 3);
				}
				else if (sData->cardLayout == CARD_LAYOUT_FRLG)
				{
					FillBgTilemapBufferRect(3, tileNum, x, 16, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 1, x + 1, 16, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 16, x, 17, 1, 1, 3);
					FillBgTilemapBufferRect(3, tileNum + 17, x + 1, 17, 1, 1, 3);
				}
				else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
				{
					if (i < 4)
					{
						FillBgTilemapBufferRect(3, tileNum, x, 16, 1, 1, 2);
						FillBgTilemapBufferRect(3, tileNum + 1, x + 1, 16, 1, 1, 2);
						FillBgTilemapBufferRect(3, tileNum + 8, x, 17, 1, 1, 2);
						FillBgTilemapBufferRect(3, tileNum + 9, x + 1, 17, 1, 1, 2);
					}
					else
					{
						FillBgTilemapBufferRect(3, tileNum + 8, x, 16, 1, 1, 3);
						FillBgTilemapBufferRect(3, tileNum + 9, x + 1, 16, 1, 1, 3);
						FillBgTilemapBufferRect(3, tileNum + 16, x, 17, 1, 1, 3);
						FillBgTilemapBufferRect(3, tileNum + 17, x + 1, 17, 1, 1, 3);
					}
				}
				
            }
        }
    }
    CopyBgTilemapBufferToVram(3);
}

static void DrawCardBackStats(void)
{
	if (sData->cardLayout == CARD_LAYOUT_RS || sData->cardLayout == CARD_LAYOUT_EMERALD)
	{
		if (sData->hasTrades)
		{
			FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 0);
			FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 0);
		}
		if (sData->trainerCard.contestsWithFriends)
		{
			FillBgTilemapBufferRect(3, 141, 27, 13, 1, 1, 0);
			FillBgTilemapBufferRect(3, 157, 27, 14, 1, 1, 0);
		}
		if (sData->hasBattleTowerWins)
		{
			FillBgTilemapBufferRect(3, 141, 17, 15, 1, 1, 0);
			FillBgTilemapBufferRect(3, 157, 17, 16, 1, 1, 0);
			FillBgTilemapBufferRect(3, 140, 27, 15, 1, 1, 0);
			FillBgTilemapBufferRect(3, 156, 27, 16, 1, 1, 0);
		}
	}
	else if (sData->cardLayout == CARD_LAYOUT_FRLG)
	{
		if (sData->hasTrades)
		{
			FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 1);
			FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 1);
		}
		if (sData->trainerCard.berryCrushPoints)
		{
			FillBgTilemapBufferRect(3, 141, 21, 13, 1, 1, 1);
			FillBgTilemapBufferRect(3, 157, 21, 14, 1, 1, 1);
		}
		if (sData->trainerCard.unionRoomNum)
		{
			FillBgTilemapBufferRect(3, 141, 27, 11, 1, 1, 1);
			FillBgTilemapBufferRect(3, 157, 27, 12, 1, 1, 1);
		}
	}
    CopyBgTilemapBufferToVram(3);
}

static void BlinkTimeColon(void)
{
    if (++sData->timeColonBlinkTimer > 60)
    {
        sData->timeColonBlinkTimer = 0;
        sData->timeColonInvisible ^= 1;
        sData->timeColonNeedDraw = TRUE;
    }
}

u8 GetTrainerCardStars(u8 cardId)
{
	u8 stars;
    struct TrainerCard* trainerCards = gTrainerCards;
	if (trainerCards[cardId].cardLayout == CARD_LAYOUT_HELIODOR)
		stars = trainerCards[cardId].stars + trainerCards[cardId].extraStars;
	else
		stars = trainerCards[cardId].stars;
	if (stars > 5)
		stars = 5;
	return stars;
}

#define tFlipState data[0]
#define tCardTop   data[1]

static void FlipTrainerCard(void)
{
    u8 taskId = CreateTask(Task_DoCardFlipTask, 0);
    Task_DoCardFlipTask(taskId);
    SetHBlankCallback(HblankCb_TrainerCard);
}

static bool8 IsCardFlipTaskActive(void)
{
    if (FindTaskIdByFunc(Task_DoCardFlipTask) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_DoCardFlipTask(u8 taskId)
{
    while(sTrainerCardFlipTasks[gTasks[taskId].tFlipState](&gTasks[taskId]))
        ;
}

static bool8 Task_BeginCardFlip(struct Task* task)
{
    u32 i;

    HideBg(1);
    HideBg(3);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    for (i = 0; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[1][i] = 0;
    task->tFlipState++;
    return FALSE;
}

// Note: Cannot be DISPLAY_HEIGHT / 2, or cardHeight will be 0
#define CARD_FLIP_Y ((DISPLAY_HEIGHT / 2) - 3)

static bool8 Task_AnimateCardFlipDown(struct Task* task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tCardTop = CARD_FLIP_Y;
    else
        task->tCardTop += 7;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 *= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 -= r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop >= CARD_FLIP_Y)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_DrawFlippedCardSide(struct Task* task)
{
    sData->allowDMACopy = FALSE;
    if (Overworld_LinkRecvQueueLengthMoreThan2() == TRUE)
        return FALSE;

    do
    {
        switch (sData->flipDrawState)
        {
        case 0:
            FillWindowPixelBuffer(1, PIXEL_FILL(0));
            FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x20, 0x20);
            break;
        case 1:
            if (!sData->onBack)
            {
                if (!PrintAllOnCardBack())
                    return FALSE;
            }
            else
            {
                if (!PrintAllOnCardFront())
                    return FALSE;
            }
            break;
        case 2:
            if (!sData->onBack)
                DrawCardFrontOrBack(sData->backTilemap);
            else
                DrawTrainerCardWindow(1);
            break;
        case 3:
            if (!sData->onBack)
                DrawCardBackStats();
            else
                FillWindowPixelBuffer(2, PIXEL_FILL(0));
            break;
        case 4:
            if (sData->onBack)
                CreateTrainerCardTrainerPic();
            break;
        default:
            task->tFlipState++;
            sData->allowDMACopy = TRUE;
            sData->flipDrawState = 0;
            return FALSE;
        }
        sData->flipDrawState++;
    } while (gReceivedRemoteLinkPlayers == 0);

    return FALSE;
}

static bool8 Task_SetCardFlipped(struct Task* task)
{
    sData->allowDMACopy = FALSE;

    // If on back of card, draw front of card because its being flipped
    if (sData->onBack)
    {
        DrawTrainerCardWindow(2);
        DrawCardScreenBackground(sData->bgTilemap);
        DrawCardFrontOrBack(sData->frontTilemap);
        DrawStarsAndBadgesOnCard();
    }
    DrawTrainerCardWindow(1);
    sData->onBack ^= 1;
    task->tFlipState++;
    sData->allowDMACopy = TRUE;
    PlaySE(SE_RG_CARD_FLIPPING);
    return FALSE;
}

static bool8 Task_AnimateCardFlipUp(struct Task* task)
{
    u32 cardHeight, r5, r10, cardTop, r6, var_24, cardBottom, var;
    s16 i;

    sData->allowDMACopy = FALSE;
    if (task->tCardTop <= 5)
        task->tCardTop = 0;
    else
        task->tCardTop -= 5;

    sData->cardTop = task->tCardTop;
    UpdateCardFlipRegs(task->tCardTop);

    cardTop = task->tCardTop;
    cardBottom = DISPLAY_HEIGHT - cardTop;
    cardHeight = cardBottom - cardTop;
    r6 = -cardTop << 16;
    r5 = (DISPLAY_HEIGHT << 16) / cardHeight;
    r5 -= 1 << 16;
    var_24 = r6;
    var_24 += r5 * cardHeight;
    r10 = r5 / cardHeight;
    r5 /= 2;

    for (i = 0; i < cardTop; i++)
        gScanlineEffectRegBuffers[0][i] = -i;
    for (; i < (s16)cardBottom; i++)
    {
        var = r6 >> 16;
        r6 += r5;
        r5 += r10;
        gScanlineEffectRegBuffers[0][i] = var;
    }
    var = var_24 >> 16;
    for (; i < DISPLAY_HEIGHT; i++)
        gScanlineEffectRegBuffers[0][i] = var;

    sData->allowDMACopy = TRUE;
    if (task->tCardTop <= 0)
        task->tFlipState++;

    return FALSE;
}

static bool8 Task_EndCardFlip(struct Task *task)
{
    ShowBg(1);
    ShowBg(3);
    SetHBlankCallback(NULL);
    DestroyTask(FindTaskIdByFunc(Task_DoCardFlipTask));
    return FALSE;
}

void ShowPlayerTrainerCard(void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    if (callback == CB2_ReshowFrontierPass)
        sData->blendColor = RGB_WHITE;
    else
        sData->blendColor = RGB_BLACK;

    if (InUnionRoom() == TRUE)
        sData->isLink = TRUE;
    else
        sData->isLink = FALSE;

    sData->language = GAME_LANGUAGE;
    TrainerCard_GenerateCardForPlayer(&sData->trainerCard);
    SetMainCallback2(CB2_InitTrainerCard);
}

void ShowTrainerCardInLink(u8 cardId, void (*callback)(void))
{
    sData = AllocZeroed(sizeof(*sData));
    sData->callback2 = callback;
    sData->isLink = TRUE;
    sData->trainerCard = gTrainerCards[cardId];
    sData->language = gLinkPlayers[cardId].language;
    SetMainCallback2(CB2_InitTrainerCard);
}

static void InitTrainerCardData(void)
{
    u8 i;

    sData->mainState = 0;
    sData->timeColonBlinkTimer = gSaveBlock2Ptr->playTimeVBlanks;
    sData->timeColonInvisible = FALSE;
    sData->onBack = FALSE;
    sData->flipBlendY = 0;
    sData->trainerPair = GetSetCardType();
    for (i = 0; i < TRAINER_CARD_PROFILE_LENGTH; i++)
        CopyEasyChatWord(sData->easyChatProfile[i], sData->trainerCard.easyChatProfile[i]);
}

static u8 GetSetCardType(void)
{
	u8 i;

    if (sData == NULL)
    {
        if (gGameVersion == VERSION_FIRERED || gGameVersion == VERSION_LEAFGREEN)
            return TRAINER_FRLG;
        else if (gGameVersion == VERSION_EMERALD)
            return TRAINER_EMERALD;
        else
            return TRAINER_RS;
    }
    else
    {
		switch (sData->trainerCard.versionModifier)
		{
			case DEV_SOLITAIRI:
				if (sData->trainerCard.version == VERSION_EMERALD)
				{
					sData->cardLayout = sData->trainerCard.cardLayout;
					if (sData->cardLayout == CARD_LAYOUT_RS)
					{
						sData->stats[0] = CARD_STAT_HOF_DEBUT;
						sData->stats[1] = CARD_STAT_LINK_BATTLES;
						sData->stats[2] = CARD_STAT_TRADES;
						sData->stats[3] = CARD_STAT_POKEBLOCKS;
						sData->stats[4] = CARD_STAT_CONTESTS;
						sData->stats[5] = CARD_STAT_BATTLE_TOWER;
					}
					else if (sData->cardLayout == CARD_LAYOUT_FRLG)
					{
						sData->stats[0] = CARD_STAT_HOF_DEBUT;
						sData->stats[1] = CARD_STAT_LINK_BATTLES;
						sData->stats[2] = CARD_STAT_TRADES;
						sData->stats[3] = CARD_STAT_UNION_ROOM;
						sData->stats[4] = CARD_STAT_BERRY_CRUSH;
						sData->stats[5] = CARD_STAT_NONE;
					}
					else if (sData->cardLayout == CARD_LAYOUT_HELIODOR)
					{
						sData->stats[0] = sData->trainerCard.stat0;
						sData->stats[1] = sData->trainerCard.stat1;
						sData->stats[2] = sData->trainerCard.stat2;
						sData->stats[3] = sData->trainerCard.stat3;
						sData->stats[4] = sData->trainerCard.stat4;
						sData->stats[5] = CARD_STAT_NONE;
					}
					else
					{
						sData->stats[0] = CARD_STAT_HOF_DEBUT;
						sData->stats[1] = CARD_STAT_LINK_BATTLES;
						sData->stats[2] = CARD_STAT_TRADES;
						sData->stats[3] = CARD_STAT_POKEBLOCKS;
						sData->stats[4] = CARD_STAT_CONTESTS;
						sData->stats[5] = CARD_STAT_BATTLE_POINTS;
					}
					return TRAINER_HELIODOR;
				}
				break;
			case DEV_SHINY_DRAGON_HUNTER:
				if (sData->trainerCard.version == VERSION_FIRERED || sData->trainerCard.version == VERSION_LEAFGREEN)
				{
					sData->cardLayout = CARD_LAYOUT_FRLG;
					sData->isDX = TRUE;
					sData->stats[0] = CARD_STAT_HOF_DEBUT;
					sData->stats[1] = CARD_STAT_LINK_BATTLES;
					sData->stats[2] = CARD_STAT_TRADES;
					sData->stats[3] = CARD_STAT_UNION_ROOM;
					if (sData->trainerCard.frontierBP)
						sData->stats[4] = CARD_STAT_BATTLE_POINTS;
					else
						sData->stats[4] = CARD_STAT_BERRY_CRUSH;
					sData->stats[5] = CARD_STAT_NONE;
					return TRAINER_FRLG;
				}
				break;
			case DEV_SOLITAIRI_2:
				if (sData->trainerCard.version == VERSION_FIRERED)
				{
					sData->cardLayout = CARD_LAYOUT_FRLG;
					sData->stats[0] = CARD_STAT_HOF_DEBUT;
					sData->stats[1] = CARD_STAT_LINK_BATTLES;
					sData->stats[2] = CARD_STAT_TRADES;
					sData->stats[3] = CARD_STAT_POKEBLOCKS;
					sData->stats[4] = CARD_STAT_CONTESTS;
					sData->stats[5] = CARD_STAT_NONE;
					return TRAINER_CRYSTALDUST;
				}
				break;
			case DEV_TEST:
				sData->cardLayout = CARD_LAYOUT_EMERALD;
				sData->stats[0] = CARD_STAT_HOF_DEBUT;
				sData->stats[1] = CARD_STAT_LINK_BATTLES;
				sData->stats[2] = CARD_STAT_TRADES;
				sData->stats[3] = CARD_STAT_POKEBLOCKS;
				sData->stats[4] = CARD_STAT_CONTESTS;
				sData->stats[5] = CARD_STAT_BATTLE_POINTS;
				return TRAINER_TEST;
		}
		
		if (sData->trainerCard.version == VERSION_FIRERED || sData->trainerCard.version == VERSION_LEAFGREEN)
		{
			sData->cardLayout = CARD_LAYOUT_FRLG;
			sData->stats[0] = CARD_STAT_HOF_DEBUT;
			sData->stats[1] = CARD_STAT_LINK_BATTLES;
			sData->stats[2] = CARD_STAT_TRADES;
			sData->stats[3] = CARD_STAT_UNION_ROOM;
			sData->stats[4] = CARD_STAT_BERRY_CRUSH;
			sData->stats[5] = CARD_STAT_NONE;
			return TRAINER_FRLG;
		}
		else if (sData->trainerCard.version == VERSION_EMERALD)
		{
			sData->cardLayout = CARD_LAYOUT_EMERALD;
			sData->stats[0] = CARD_STAT_HOF_DEBUT;
			sData->stats[1] = CARD_STAT_LINK_BATTLES;
			sData->stats[2] = CARD_STAT_TRADES;
			sData->stats[3] = CARD_STAT_POKEBLOCKS;
			sData->stats[4] = CARD_STAT_CONTESTS;
			sData->stats[5] = CARD_STAT_BATTLE_POINTS;
			return TRAINER_EMERALD;
		}
		else
		{
			sData->cardLayout = CARD_LAYOUT_RS;
			sData->stats[0] = CARD_STAT_HOF_DEBUT;
			sData->stats[1] = CARD_STAT_LINK_BATTLES;
			sData->stats[2] = CARD_STAT_TRADES;
			sData->stats[3] = CARD_STAT_POKEBLOCKS;
			sData->stats[4] = CARD_STAT_CONTESTS;
			sData->stats[5] = CARD_STAT_BATTLE_TOWER;
			return TRAINER_RS;
		}
    }
}

static void CreateTrainerCardTrainerPic(void)
{
    if (InUnionRoom() == TRUE && gReceivedRemoteLinkPlayers == 1)
    {
        CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(sData->trainerCard.facilityClass),
                    TRUE,
                    sTrainerPicOffset[sData->cardLayout][sData->trainerCard.gender][0],
                    sTrainerPicOffset[sData->cardLayout][sData->trainerCard.gender][1],
                    8,
                    2);
    }
    else
    {
        CreateTrainerCardTrainerPicSprite(FacilityClassToPicIndex(sTrainerPicFacilityClass[sData->trainerPair][sData->trainerCard.gender]),
                    TRUE,
                    sTrainerPicOffset[sData->cardLayout][sData->trainerCard.gender][0],
                    sTrainerPicOffset[sData->cardLayout][sData->trainerCard.gender][1],
                    8,
                    2);
    }
}
