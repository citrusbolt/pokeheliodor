#include "global.h"
#include "util.h"
#include "main.h"
#include "event_data.h"
#include "easy_chat.h"
#include "script.h"
#include "battle_tower.h"
#include "wonder_news.h"
#include "string_util.h"
#include "new_game.h"
#include "mystery_gift.h"
#include "constants/mystery_gift.h"
#include "mystery_gift_server.h"

static EWRAM_DATA bool32 sStatsEnabled = FALSE;
EWRAM_DATA u8 gEventTicketToSend = 0xFF;

static void ClearSavedWonderNewsMetadata(void);
static void ClearSavedWonderNews(void);
static void ClearSavedWonderCard(void);
static bool32 ValidateWonderNews(const struct WonderNews *);
static bool32 ValidateWonderCard(const struct WonderCard *);
static void ClearSavedWonderCardMetadata(void);
static void ClearSavedTrainerIds(void);
static void IncrementCardStatForNewTrainer(u32, u32, u32 *, int);

const struct WonderCard gAuroraTicket_Card = {
    .flagId = 1000,
    .iconSpecies = 0xFFFF,
    .idNumber = 0,
    .type = CARD_TYPE_GIFT,
    .bgType = 0,
    .sendType = SEND_TYPE_ALLOWED_ALWAYS,
    .maxStamps = 0,
    .titleText =       _("{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}Aurora{_}Ticket                "),
    .subtitleText =    _("{_}{_}{_}{_}{_}{_}Heliodor{_}Exchange{_}Card           "),
    .bodyText =      { _("Go{_}to{_}the{_}second{_}floor{_}of{_}the{_}Pokémon  "),
                       _("Center{_}and{_}meet{_}the{_}delivery{_}person.   "),
                       _("Receive{_}the{_}Aurora{_}Ticket{_}and          "),
                       _("then{_}board{_}the{_}ferry.                  ") },
    .footerLine1Text = _("This{_}Card{_}can{_}be{_}sent{_}to{_}Pokémon       "),
    .footerLine2Text = _("FireRed,{_}LeafGreen,{_}Emerald{_}or{_}Heliodor")
};

const struct WonderCard gMysticTicket_Card = {
    .flagId = 1001,
    .iconSpecies = 0xFFFF,
    .idNumber = 0,
    .type = CARD_TYPE_GIFT,
    .bgType = 0,
    .sendType = SEND_TYPE_ALLOWED_ALWAYS,
    .maxStamps = 0,
    .titleText =       _("{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}Mystic{_}Ticket                "),
    .subtitleText =    _("{_}{_}{_}{_}{_}{_}Heliodor{_}Exchange{_}Card           "),
    .bodyText =      { _("Go{_}to{_}the{_}second{_}floor{_}of{_}the{_}Pokémon  "),
                       _("Center{_}and{_}meet{_}the{_}delivery{_}person.   "),
                       _("Receive{_}the{_}Mystic{_}Ticket{_}and          "),
                       _("then{_}board{_}the{_}ferry.                  ") },
    .footerLine1Text = _("This{_}Card{_}can{_}be{_}sent{_}to{_}Pokémon       "),
    .footerLine2Text = _("FireRed,{_}LeafGreen,{_}Emerald{_}or{_}Heliodor")
};

const struct WonderCard gEonTicket_Card = {
    .flagId = 1003,
    .iconSpecies = SPECIES_ZAPDOS,
    .idNumber = 0,
    .type = CARD_TYPE_GIFT,
    .bgType = 0,
    .sendType = SEND_TYPE_ALLOWED_ALWAYS,
    .maxStamps = 0,
    .titleText =       _("{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}Eon{_}Ticket                  "),
    .subtitleText =    _("{_}{_}{_}{_}{_}{_}Heliodor{_}Exchange{_}Card           "),
    .bodyText =      { _("Go{_}to{_}the{_}second{_}floor{_}of{_}the{_}Pokémon  "),
                       _("Center{_}and{_}meet{_}the{_}delivery{_}person.   "),
                       _("Receive{_}the{_}Eon{_}Ticket{_}and             "),
                       _("then{_}board{_}the{_}ferry.                  ") },
    .footerLine1Text = _("This{_}Card{_}can{_}be{_}sent{_}to{_}Pokémon       "),
    .footerLine2Text = _("Emerald{_}or{_}Heliodor.                   ")
};
const struct WonderCard gEgg_Card = {
    .flagId = 1004,
    .iconSpecies = SPECIES_EGG,
    .idNumber = 0,
    .type = CARD_TYPE_GIFT,
    .bgType = 0,
    .sendType = SEND_TYPE_ALLOWED_ALWAYS,
    .maxStamps = 0,
    .titleText =       _("{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}{_}Pokémon{_}Egg                 "),
    .subtitleText =    _("{_}{_}{_}{_}{_}{_}Heliodor{_}Exchange{_}Card           "),
    .bodyText =      { _("Go{_}to{_}the{_}second{_}floor{_}of{_}the{_}Pokémon  "),
                       _("Center{_}and{_}meet{_}the{_}delivery{_}person.   "),
                       _("Receive{_}a{_}special{_}Pokémon{_}Egg          "),
                       _("as{_}thanks{_}for{_}playing{_}Pokémon{_}Heliodor.") },
    .footerLine1Text = _("This{_}Card{_}can{_}be{_}sent{_}to{_}Pokémon       "),
    .footerLine2Text = _("FireRed,{_}LeafGreen,{_}Emerald{_}or{_}Heliodor")
};

const struct WonderCardMetadata gEventTicket_Metadata = {
    .battlesWon = 0,
    .battlesLost = 0,
    .numTrades = 0,
    .iconSpecies = SPECIES_EGG,
    .stampData = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}}
};

static const u8 sFooterTextFRLG[] = _("FireRed{_}or{_}LeafGreen.                  ");
static const u8 sFooterTextEH[] =   _("Emerald{_}or{_}Heliodor.                   ");

extern const u8 gRamScript_EonTicket_E[995];
extern const u8 gRamScript_MysticTicket_FRLG[995];
extern const u8 gRamScript_MysticTicket_E[995];
extern const u8 gRamScript_AuroraTicket_FRLG[995];
extern const u8 gRamScript_AuroraTicket_E[995];
extern const u8 gRamScript_Egg_FRLG[995];
extern const u8 gRamScript_Egg_E[995];
extern const u8 gRamScript_Egg_H[995];

#define CALC_CRC(data) CalcCRC16WithTable((void *)&(data), sizeof(data))

void ClearMysteryGift(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift, sizeof(gSaveBlock1Ptr->mysteryGift));
    ClearSavedWonderNewsMetadata(); // Clear is redundant, WonderNews_Reset would be sufficient
    InitQuestionnaireWords();
}

struct WonderNews *GetSavedWonderNews(void)
{
    return &gSaveBlock1Ptr->mysteryGift.news;
}

struct WonderCard *GetSavedWonderCard(void)
{
    return &gSaveBlock1Ptr->mysteryGift.card;
}

struct WonderCardMetadata *GetSavedWonderCardMetadata(void)
{
    return &gSaveBlock1Ptr->mysteryGift.cardMetadata;
}

struct WonderNewsMetadata *GetSavedWonderNewsMetadata(void)
{
    return &gSaveBlock1Ptr->mysteryGift.newsMetadata;
}

u16 *GetQuestionnaireWordsPtr(void)
{
    return gSaveBlock1Ptr->mysteryGift.questionnaireWords;
}

// Equivalent to ClearSavedWonderCardAndRelated, but nothing else to clear
void ClearSavedWonderNewsAndRelated(void)
{
    ClearSavedWonderNews();
}

bool32 SaveWonderNews(const struct WonderNews *news)
{
    if (!ValidateWonderNews(news))
        return FALSE;

    ClearSavedWonderNews();
    gSaveBlock1Ptr->mysteryGift.news = *news;
    gSaveBlock1Ptr->mysteryGift.newsCrc = CALC_CRC(gSaveBlock1Ptr->mysteryGift.news);
    return TRUE;
}

bool32 ValidateSavedWonderNews(void)
{
    if (CALC_CRC(gSaveBlock1Ptr->mysteryGift.news) != gSaveBlock1Ptr->mysteryGift.newsCrc)
        return FALSE;
    if (!ValidateWonderNews(&gSaveBlock1Ptr->mysteryGift.news))
        return FALSE;

    return TRUE;
}

static bool32 ValidateWonderNews(const struct WonderNews *news)
{
    if (news->id == 0)
        return FALSE;

    return TRUE;
}

bool32 IsSendingSavedWonderNewsAllowed(void)
{
    const struct WonderNews *news = &gSaveBlock1Ptr->mysteryGift.news;
    if (news->sendType == SEND_TYPE_DISALLOWED)
        return FALSE;

    return TRUE;
}

static void ClearSavedWonderNews(void)
{
    CpuFill32(0, GetSavedWonderNews(), sizeof(gSaveBlock1Ptr->mysteryGift.news));
    gSaveBlock1Ptr->mysteryGift.newsCrc = 0;
}

static void ClearSavedWonderNewsMetadata(void)
{
    CpuFill32(0, GetSavedWonderNewsMetadata(), sizeof(gSaveBlock1Ptr->mysteryGift.newsMetadata));
    WonderNews_Reset();
}

bool32 IsWonderNewsSameAsSaved(const u8 *news)
{
    const u8 *savedNews = (const u8 *)&gSaveBlock1Ptr->mysteryGift.news;
    u32 i;
    if (!ValidateSavedWonderNews())
        return FALSE;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->mysteryGift.news); i++)
    {
        if (savedNews[i] != news[i])
            return FALSE;
    }

    return TRUE;
}

void ClearSavedWonderCardAndRelated(void)
{
    ClearSavedWonderCard();
    ClearSavedWonderCardMetadata();
    ClearSavedTrainerIds();
    ClearRamScript();
    ClearMysteryGiftFlags();
    ClearMysteryGiftVars();
    ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);
}

bool32 SaveWonderCard(const struct WonderCard *card)
{
    struct WonderCardMetadata *metadata;
    if (!ValidateWonderCard(card))
        return FALSE;

    ClearSavedWonderCardAndRelated();
    memcpy(&gSaveBlock1Ptr->mysteryGift.card, card, sizeof(struct WonderCard));
    gSaveBlock1Ptr->mysteryGift.cardCrc = CALC_CRC(gSaveBlock1Ptr->mysteryGift.card);
    metadata = &gSaveBlock1Ptr->mysteryGift.cardMetadata;
    metadata->iconSpecies = (&gSaveBlock1Ptr->mysteryGift.card)->iconSpecies;
    return TRUE;
}

bool32 ValidateSavedWonderCard(void)
{
    if (gSaveBlock1Ptr->mysteryGift.cardCrc != CALC_CRC(gSaveBlock1Ptr->mysteryGift.card))
        return FALSE;
    if (!ValidateWonderCard(&gSaveBlock1Ptr->mysteryGift.card))
        return FALSE;
    if (!ValidateSavedRamScript())
        return FALSE;

    return TRUE;
}

static bool32 ValidateWonderCard(const struct WonderCard *card)
{
    if (card->flagId == 0)
        return FALSE;
    if (card->type >= CARD_TYPE_COUNT)
        return FALSE;
    if (!(card->sendType == SEND_TYPE_DISALLOWED
       || card->sendType == SEND_TYPE_ALLOWED
       || card->sendType == SEND_TYPE_ALLOWED_ALWAYS))
        return FALSE;
    if (card->bgType >= NUM_WONDER_BGS)
        return FALSE;
    if (card->maxStamps > MAX_STAMP_CARD_STAMPS)
        return FALSE;

    return TRUE;
}

bool32 IsSendingSavedWonderCardAllowed(void)
{
    const struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
    if (card->sendType == SEND_TYPE_DISALLOWED)
        return FALSE;

    return TRUE;
}

static void ClearSavedWonderCard(void)
{
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift.card, sizeof(gSaveBlock1Ptr->mysteryGift.card));
    gSaveBlock1Ptr->mysteryGift.cardCrc = 0;
}

static void ClearSavedWonderCardMetadata(void)
{
    CpuFill32(0, GetSavedWonderCardMetadata(), sizeof(gSaveBlock1Ptr->mysteryGift.cardMetadata));
    gSaveBlock1Ptr->mysteryGift.cardMetadataCrc = 0;
}

u16 GetWonderCardFlagID(void)
{
    if (ValidateSavedWonderCard())
        return gSaveBlock1Ptr->mysteryGift.card.flagId;

    return 0;
}

void DisableWonderCardSending(struct WonderCard *card)
{
    if (card->sendType == SEND_TYPE_ALLOWED)
        card->sendType = SEND_TYPE_DISALLOWED;
}

static bool32 IsWonderCardFlagIDInValidRange(u16 flagId)
{
    if (flagId >= WONDER_CARD_FLAG_OFFSET && flagId < WONDER_CARD_FLAG_OFFSET + NUM_WONDER_CARD_FLAGS)
        return TRUE;

    return FALSE;
}

static const u16 sReceivedGiftFlags[] =
{
    FLAG_RECEIVED_AURORA_TICKET,
    FLAG_RECEIVED_MYSTIC_TICKET,
    FLAG_RECEIVED_OLD_SEA_MAP,
    FLAG_RECEIVED_EON_TICKET_MYSTERY_GIFT,
    FLAG_RECEIVED_HELIODOR_EGG,
    FLAG_WONDER_CARD_UNUSED_3,
    FLAG_WONDER_CARD_UNUSED_4,
    FLAG_WONDER_CARD_UNUSED_5,
    FLAG_WONDER_CARD_UNUSED_6,
    FLAG_WONDER_CARD_UNUSED_7,
    FLAG_WONDER_CARD_UNUSED_8,
    FLAG_WONDER_CARD_UNUSED_9,
    FLAG_WONDER_CARD_UNUSED_10,
    FLAG_WONDER_CARD_UNUSED_11,
    FLAG_WONDER_CARD_UNUSED_12,
    FLAG_WONDER_CARD_UNUSED_13,
    FLAG_WONDER_CARD_UNUSED_14,
    FLAG_WONDER_CARD_UNUSED_15,
    FLAG_WONDER_CARD_UNUSED_16,
    FLAG_WONDER_CARD_UNUSED_17,
};

bool32 IsSavedWonderCardGiftNotReceived(void)
{
    u16 value = GetWonderCardFlagID();
    if (!IsWonderCardFlagIDInValidRange(value))
        return FALSE;

    // If flag is set, player has received gift from this card
    if (FlagGet(sReceivedGiftFlags[value - WONDER_CARD_FLAG_OFFSET]) == TRUE)
        return FALSE;

    return TRUE;
}

static int GetNumStampsInMetadata(const struct WonderCardMetadata *data, int size)
{
    int numStamps = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (data->stampData[STAMP_ID][i] && data->stampData[STAMP_SPECIES][i] != SPECIES_NONE)
            numStamps++;
    }

    return numStamps;
}

static bool32 IsStampInMetadata(const struct WonderCardMetadata *metadata, const u16 *stamp, int maxStamps)
{
    int i;
    for (i = 0; i < maxStamps; i++)
    {
        if (metadata->stampData[STAMP_ID][i] == stamp[STAMP_ID])
            return TRUE;
        if (metadata->stampData[STAMP_SPECIES][i] == stamp[STAMP_SPECIES])
            return TRUE;
    }

    return FALSE;
}

static bool32 ValidateStamp(const u16 *stamp)
{
    if (stamp[STAMP_ID] == 0)
        return FALSE;
    if (stamp[STAMP_SPECIES] == SPECIES_NONE)
        return FALSE;
    if (stamp[STAMP_SPECIES] >= NUM_SPECIES)
        return FALSE;
    return TRUE;
}

static int GetNumStampsInSavedCard(void)
{
    struct WonderCard *card;
    if (!ValidateSavedWonderCard())
        return 0;

    card = &gSaveBlock1Ptr->mysteryGift.card;
    if (card->type != CARD_TYPE_STAMP)
        return 0;

    return GetNumStampsInMetadata(&gSaveBlock1Ptr->mysteryGift.cardMetadata, card->maxStamps);
}

bool32 MysteryGift_TrySaveStamp(const u16 *stamp)
{
    struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
    int maxStamps = card->maxStamps;
    int i;
    if (!ValidateStamp(stamp))
        return FALSE;

    if (IsStampInMetadata(&gSaveBlock1Ptr->mysteryGift.cardMetadata, stamp, maxStamps))
        return FALSE;

    for (i = 0; i < maxStamps; i++)
    {
        if (gSaveBlock1Ptr->mysteryGift.cardMetadata.stampData[STAMP_ID][i] == 0
         && gSaveBlock1Ptr->mysteryGift.cardMetadata.stampData[STAMP_SPECIES][i] == SPECIES_NONE)
        {
            gSaveBlock1Ptr->mysteryGift.cardMetadata.stampData[STAMP_ID][i] = stamp[STAMP_ID];
            gSaveBlock1Ptr->mysteryGift.cardMetadata.stampData[STAMP_SPECIES][i] = stamp[STAMP_SPECIES];
            return TRUE;
        }
    }

    return FALSE;
}

#define GAME_DATA_VALID_VAR 0x101
#define GAME_DATA_VALID_GIFT_TYPE_1 (1 << 2)
#define GAME_DATA_VALID_GIFT_TYPE_2 (1 << 9)

void MysteryGift_LoadLinkGameData(struct MysteryGiftLinkGameData *data, bool32 isWonderNews)
{
    int i;
    CpuFill32(0, data, sizeof(*data));
    data->validationVar = GAME_DATA_VALID_VAR;
    data->validationFlag1 = 1;
    data->validationFlag2 = 1;

    if (isWonderNews)
    {
        // Despite setting these for News, they are
        // only ever checked for Cards
        data->validationGiftType1 = GAME_DATA_VALID_GIFT_TYPE_1 | 1;
        data->validationGiftType2 = GAME_DATA_VALID_GIFT_TYPE_2 | 1;
    }
    else // Wonder Card
    {
        data->validationGiftType1 = GAME_DATA_VALID_GIFT_TYPE_1;
        data->validationGiftType2 = GAME_DATA_VALID_GIFT_TYPE_2;
    }

    if (ValidateSavedWonderCard())
    {
        data->flagId = GetSavedWonderCard()->flagId;
        data->cardMetadata = *GetSavedWonderCardMetadata();
        data->maxStamps = GetSavedWonderCard()->maxStamps;
    }
    else
    {
        data->flagId = 0;
    }

    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
        data->questionnaireWords[i] = gSaveBlock1Ptr->mysteryGift.questionnaireWords[i];

    CopyTrainerId(data->playerTrainerId, gSaveBlock2Ptr->playerTrainerId);
    StringCopy(data->playerName, gSaveBlock2Ptr->playerName);
    for (i = 0; i < EASY_CHAT_BATTLE_WORDS_COUNT; i++)
        data->easyChatProfile[i] = gSaveBlock1Ptr->easyChatProfile[i];

    memcpy(data->romHeaderGameCode, RomHeaderGameCode, GAME_CODE_LENGTH);
    data->romHeaderSoftwareVersion = RomHeaderSoftwareVersion;
}

static bool8 ConvertCardForFRLG(struct MysteryGiftServer *svr)
{
    if (sReceivedGiftFlags[(svr->card)->flagId - WONDER_CARD_FLAG_OFFSET] == FLAG_RECEIVED_MYSTIC_TICKET)
    {
        svr->ramScript = &gRamScript_MysticTicket_FRLG;
        memcpy((svr->card)->footerLine2Text, sFooterTextFRLG, sizeof(sFooterTextFRLG));
        return TRUE;
    }
    else if (sReceivedGiftFlags[(svr->card)->flagId - WONDER_CARD_FLAG_OFFSET] == FLAG_RECEIVED_AURORA_TICKET)
    {
        svr->ramScript = &gRamScript_AuroraTicket_FRLG;
        memcpy((svr->card)->footerLine2Text, sFooterTextFRLG, sizeof(sFooterTextFRLG));
        return TRUE;
    }
    else if (sReceivedGiftFlags[(svr->card)->flagId - WONDER_CARD_FLAG_OFFSET] == FLAG_RECEIVED_HELIODOR_EGG)
    {
        svr->ramScript = &gRamScript_Egg_FRLG;
        memcpy((svr->card)->footerLine2Text, sFooterTextFRLG, sizeof(sFooterTextFRLG));
        return TRUE;
    }
    return FALSE;
}

bool32 MysteryGift_ValidateLinkGameData(struct MysteryGiftServer *svr, bool32 isWonderNews)
{
    if ((svr->linkGameData)->validationVar != GAME_DATA_VALID_VAR)
        return FALSE;

    if (!((svr->linkGameData)->validationFlag1 & 1))
        return FALSE;

    if (!((svr->linkGameData)->validationFlag2 & 1))
        return FALSE;

    if (gEventTicketToSend == (svr->card)->flagId - WONDER_CARD_FLAG_OFFSET)
    {
        if (sReceivedGiftFlags[gEventTicketToSend] == FLAG_RECEIVED_AURORA_TICKET)
            svr->ramScript = &gRamScript_AuroraTicket_E;
        else if (sReceivedGiftFlags[gEventTicketToSend] == FLAG_RECEIVED_MYSTIC_TICKET)
            svr->ramScript = &gRamScript_MysticTicket_E;
        else if (sReceivedGiftFlags[gEventTicketToSend] == FLAG_RECEIVED_EON_TICKET_MYSTERY_GIFT)
            svr->ramScript = &gRamScript_EonTicket_E;
        memcpy((svr->card)->footerLine2Text, sFooterTextEH, sizeof(sFooterTextEH));
    }
    else if (sReceivedGiftFlags[(svr->card)->flagId - WONDER_CARD_FLAG_OFFSET] == FLAG_RECEIVED_HELIODOR_EGG)
    {
        svr->ramScript = &gRamScript_Egg_E;
        memcpy((svr->card)->footerLine2Text, sFooterTextEH, sizeof(sFooterTextEH));
    }

    if (!isWonderNews)
    {
        if ((svr->linkGameData)->validationGiftType1 & 1 && (svr->linkGameData)->validationGiftType2 & 0x0F && ConvertCardForFRLG(svr))
            return TRUE;
        
        if (!((svr->linkGameData)->validationGiftType1 & GAME_DATA_VALID_GIFT_TYPE_1))
            return FALSE;

        if (!((svr->linkGameData)->validationGiftType2 & (GAME_DATA_VALID_GIFT_TYPE_2 | 0x180)))
            return FALSE;
    }

    return TRUE;
}

u32 MysteryGift_CompareCardFlags(const u16 *flagId, const struct MysteryGiftLinkGameData *data, const void *unused)
{
    // Has a Wonder Card already?
    if (data->flagId == 0)
        return HAS_NO_CARD;

    // Has this Wonder Card already?
    if (*flagId == data->flagId)
        return HAS_SAME_CARD;

    // Player has a different Wonder Card
    return HAS_DIFF_CARD;
}

// This is referenced by the Mystery Gift server, but the instruction it's referenced in is never used,
// so the return values here are never checked by anything.
u32 MysteryGift_CheckStamps(const u16 *stamp, const struct MysteryGiftLinkGameData *data, const void *unused)
{
    int stampsMissing = data->maxStamps - GetNumStampsInMetadata(&data->cardMetadata, data->maxStamps);

    // Has full stamp card?
    if (stampsMissing == 0)
        return 1;

    // Already has stamp?
    if (IsStampInMetadata(&data->cardMetadata, stamp, data->maxStamps))
        return 3;

    // Only 1 empty stamp left?
    if (stampsMissing == 1)
        return 4;

    // This is a new stamp
    return 2;
}

bool32 MysteryGift_DoesQuestionnaireMatch(const struct MysteryGiftLinkGameData *data, const u16 *words)
{
    int i;
    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
    {
        if (data->questionnaireWords[i] != words[i])
            return FALSE;
    }

    return TRUE;
}

static int GetNumStampsInLinkData(const struct MysteryGiftLinkGameData *data)
{
    return GetNumStampsInMetadata(&data->cardMetadata, data->maxStamps);
}

u16 MysteryGift_GetCardStatFromLinkData(const struct MysteryGiftLinkGameData *data, u32 stat)
{
    switch (stat)
    {
    case CARD_STAT_BATTLES_WON:
        return data->cardMetadata.battlesWon;
    case CARD_STAT_BATTLES_LOST:
        return data->cardMetadata.battlesLost;
    case CARD_STAT_NUM_TRADES:
        return data->cardMetadata.numTrades;
    case CARD_STAT_NUM_STAMPS:
        return GetNumStampsInLinkData(data);
    case CARD_STAT_MAX_STAMPS:
        return data->maxStamps;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}

static void IncrementCardStat(u32 statType)
{
    struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
    if (card->type == CARD_TYPE_LINK_STAT)
    {
        u16 *stat = NULL;
        switch (statType)
        {
        case CARD_STAT_BATTLES_WON:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.battlesWon;
            break;
        case CARD_STAT_BATTLES_LOST:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.battlesLost;
            break;
        case CARD_STAT_NUM_TRADES:
            stat = &gSaveBlock1Ptr->mysteryGift.cardMetadata.numTrades;
            break;
        case CARD_STAT_NUM_STAMPS: // Unused
        case CARD_STAT_MAX_STAMPS: // Unused
            break;
        }

        if (stat == NULL)
        {
            AGB_ASSERT(0);
        }
        else if (++(*stat) > MAX_WONDER_CARD_STAT)
        {
            *stat = MAX_WONDER_CARD_STAT;
        }
    }
}

u16 MysteryGift_GetCardStat(u32 stat)
{
    switch (stat)
    {
    case CARD_STAT_BATTLES_WON:
    {
        struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
        if (card->type == CARD_TYPE_LINK_STAT)
        {
            struct WonderCardMetadata *metadata = &gSaveBlock1Ptr->mysteryGift.cardMetadata;
            return metadata->battlesWon;
        }
        break;
    }
    case CARD_STAT_BATTLES_LOST:
    {
        struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
        if (card->type == CARD_TYPE_LINK_STAT)
        {
            struct WonderCardMetadata *metadata = &gSaveBlock1Ptr->mysteryGift.cardMetadata;
            return metadata->battlesLost;
        }
        break;
    }
    case CARD_STAT_NUM_TRADES:
    {
        struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
        if (card->type == CARD_TYPE_LINK_STAT)
        {
            struct WonderCardMetadata *metadata = &gSaveBlock1Ptr->mysteryGift.cardMetadata;
            return metadata->numTrades;
        }
        break;
    }
    case CARD_STAT_NUM_STAMPS:
    {
        struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
        if (card->type == CARD_TYPE_STAMP)
            return GetNumStampsInSavedCard();
        break;
    }
    case CARD_STAT_MAX_STAMPS:
    {
        struct WonderCard *card = &gSaveBlock1Ptr->mysteryGift.card;
        if (card->type == CARD_TYPE_STAMP)
            return card->maxStamps;
        break;
    }
    }

    AGB_ASSERT(0);
    return 0;
}

void MysteryGift_DisableStats(void)
{
    sStatsEnabled = FALSE;
}

bool32 MysteryGift_TryEnableStatsByFlagId(u16 flagId)
{
    sStatsEnabled = FALSE;
    if (flagId == 0)
        return FALSE;

    if (!ValidateSavedWonderCard())
        return FALSE;

    if (gSaveBlock1Ptr->mysteryGift.card.flagId != flagId)
        return FALSE;

    sStatsEnabled = TRUE;
    return TRUE;
}

void MysteryGift_TryIncrementStat(u32 stat, u32 trainerId)
{
    if (sStatsEnabled)
    {
        switch (stat)
        {
        case CARD_STAT_NUM_TRADES:
            IncrementCardStatForNewTrainer(CARD_STAT_NUM_TRADES,
                                            trainerId,
                                            gSaveBlock1Ptr->mysteryGift.trainerIds[1],
                                            ARRAY_COUNT(gSaveBlock1Ptr->mysteryGift.trainerIds[1]));
            break;
        case CARD_STAT_BATTLES_WON:
            IncrementCardStatForNewTrainer(CARD_STAT_BATTLES_WON,
                                            trainerId,
                                            gSaveBlock1Ptr->mysteryGift.trainerIds[0],
                                            ARRAY_COUNT(gSaveBlock1Ptr->mysteryGift.trainerIds[0]));
            break;
        case CARD_STAT_BATTLES_LOST:
            IncrementCardStatForNewTrainer(CARD_STAT_BATTLES_LOST,
                                            trainerId,
                                            gSaveBlock1Ptr->mysteryGift.trainerIds[0],
                                            ARRAY_COUNT(gSaveBlock1Ptr->mysteryGift.trainerIds[0]));
            break;
        default:
            AGB_ASSERT(0);
            break;
        }
    }
}

static void ClearSavedTrainerIds(void)
{
    CpuFill32(0, gSaveBlock1Ptr->mysteryGift.trainerIds, sizeof(gSaveBlock1Ptr->mysteryGift.trainerIds));
}

// Returns TRUE if it's a new trainer id, FALSE if an existing one.
// In either case the given trainerId is saved in element 0
static bool32 RecordTrainerId(u32 trainerId, u32 *trainerIds, int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        if (trainerIds[i] == trainerId)
            break;
    }

    if (i == size)
    {
        // New trainer, shift array and insert new id at front
        for (j = size - 1; j > 0; j--)
            trainerIds[j] = trainerIds[j - 1];

        trainerIds[0] = trainerId;
        return TRUE;
    }
    else
    {
        // Existing trainer, shift back to old slot and move id to front
        for (j = i; j > 0; j--)
            trainerIds[j] = trainerIds[j - 1];

        trainerIds[0] = trainerId;
        return FALSE;
    }
}

static void IncrementCardStatForNewTrainer(u32 stat, u32 trainerId, u32 *trainerIds, int size)
{
    if (RecordTrainerId(trainerId, trainerIds, size))
        IncrementCardStat(stat);
}

void GiveEggWonderCard(void)
{
    if (!ValidateSavedWonderCard())
    {
        SaveWonderCard(&gEgg_Card);
        InitRamScript_NoObjectEvent((u8*)gRamScript_Egg_H, 1000);
    }
}
