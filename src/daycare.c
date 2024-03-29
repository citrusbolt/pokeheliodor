#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "daycare.h"
#include "string_util.h"
#include "mail.h"
#include "pokemon_storage_system.h"
#include "event_data.h"
#include "random.h"
#include "main.h"
#include "egg_hatch.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "script.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "party_menu.h"
#include "list_menu.h"
#include "overworld.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "rtc.h"
#include "pokedex.h"
#include "item.h"
#include "power.h"
#include "constants/power.h"

extern const struct Evolution gEvolutionTable[][EVOS_PER_MON];

static void ClearDaycareMonMail(struct DaycareMail *mail);
static void SetInitialEggData(struct Pokemon *mon, u16 species, struct DayCare *daycare);
static u8 GetDaycareCompatibilityScore(struct DayCare *daycare);
static void DaycarePrintMonInfo(u8 windowId, u32 daycareSlotId, u8 y);

// RAM buffers used to assist with BuildEggMoveset()
EWRAM_DATA static u16 sHatchedEggLevelUpMoves[EGG_LVL_UP_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sHatchedEggFatherMoves[MAX_MON_MOVES] = {0};
EWRAM_DATA static u16 sHatchedEggFinalMoves[MAX_MON_MOVES] = {0};
EWRAM_DATA static u16 sHatchedEggEggMoves[EGG_MOVES_ARRAY_COUNT] = {0};
EWRAM_DATA static u16 sHatchedEggMotherMoves[MAX_MON_MOVES] = {0};
EWRAM_DATA static u16 sHatchedEggFatherEggMoves[EGG_MOVES_ARRAY_COUNT] = {0};

#include "data/pokemon/egg_moves.h"

static const struct WindowTemplate sDaycareLevelMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 15,
    .tilemapTop = 1,
    .width = 14,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 8
};

// Indices here are assigned by Task_HandleDaycareLevelMenuInput to VAR_RESULT,
// which is copied to VAR_0x8004 and used as an index for GetDaycareCost
static const struct ListMenuItem sLevelMenuItems[] =
{
    {gText_ExpandedPlaceholder_Empty, 0},
    {gText_ExpandedPlaceholder_Empty, 1},
    {gText_Exit, DAYCARE_LEVEL_MENU_EXIT}
};

static const struct ListMenuTemplate sDaycareListMenuLevelTemplate =
{
    .items = sLevelMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = DaycarePrintMonInfo,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_OPTION,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const u8 *const sCompatibilityMessages[] =
{
    gDaycareText_GetAlongVeryWell,
    gDaycareText_GetAlong,
    gDaycareText_DontLikeOther,
    gDaycareText_PlayOther
};

static const u8 sJapaneseEggNickname[] = _("タマゴ"); // "tamago" ("egg" in Japanese)

u8 *GetMonNickname2(struct Pokemon *mon, u8 *dest)
{
    u8 nickname[POKEMON_NAME_BUFFER_SIZE];
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    return StringCopy_Nickname(dest, nickname);
}

u8 *GetBoxMonNickname(struct BoxPokemon *mon, u8 *dest)
{
    u8 nickname[POKEMON_NAME_BUFFER_SIZE];
    GetBoxMonData(mon, MON_DATA_NICKNAME, nickname);
    return StringCopy_Nickname(dest, nickname);
}

u8 CountPokemonInDaycare(struct DayCare *daycare)
{
    u8 i, count;
    count = 0;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) != 0)
            count++;
    }

    return count;
}

void InitDaycareMailRecordMixing(struct DayCare *daycare, struct RecordMixingDaycareMail *mixMail)
{
    u8 i;
    u8 numDaycareMons = 0;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) != SPECIES_NONE)
        {
            numDaycareMons++;
            if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_HELD_ITEM) == ITEM_NONE)
                mixMail->cantHoldItem[i] = FALSE;
            else
                mixMail->cantHoldItem[i] = TRUE;
        }
        else
        {
            // Daycare slot empty
            mixMail->cantHoldItem[i] = TRUE;
        }
    }

    mixMail->numDaycareMons = numDaycareMons;
}

static s8 Daycare_FindEmptySpot(struct DayCare *daycare)
{
    u8 i;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES) == SPECIES_NONE)
            return i;
    }

    return -1;
}

static void StorePokemonInDaycare(struct Pokemon *mon, struct DaycareMon *daycareMon)
{
    if (MonHasMail(mon))
    {
        u8 mailId;

        StringCopy(daycareMon->mail.otName, gSaveBlock2Ptr->playerName);
        GetMonNickname2(mon, daycareMon->mail.monName);
        StripExtCtrlCodes(daycareMon->mail.monName);
        daycareMon->mail.gameLanguage = GAME_LANGUAGE;
        daycareMon->mail.monLanguage = GetMonData(mon, MON_DATA_LANGUAGE);
        mailId = GetMonData(mon, MON_DATA_MAIL);
        daycareMon->mail.message = gSaveBlock1Ptr->mail[mailId];
        TakeMailFromMon(mon);
    }

    daycareMon->mon = mon->box;
    BoxMonRestorePP(&daycareMon->mon);
    daycareMon->steps = 0;
    ZeroMonData(mon);
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

static void StorePokemonInEmptyDaycareSlot(struct Pokemon *mon, struct DayCare *daycare)
{
	if (Daycare_FindEmptySpot(daycare) == 1)
	{
		daycare->mons[1].mon = daycare->mons[0].mon;
        daycare->mons[1].mail = daycare->mons[0].mail;
        daycare->mons[1].steps = daycare->mons[0].steps;
	}

    StorePokemonInDaycare(mon, &daycare->mons[0]);
}

void StoreSelectedPokemonInDaycare(void)
{
    u8 monId = GetCursorSelectionMonId();
    StorePokemonInEmptyDaycareSlot(&gPlayerParty[monId], &gSaveBlock1Ptr->daycare);
}

// Shifts the second daycare Pokémon slot into the first slot.
static void ShiftDaycareSlots(struct DayCare *daycare)
{
    // This condition is only satisfied when the player takes out the first Pokémon from the daycare.
    if (GetBoxMonData(&daycare->mons[1].mon, MON_DATA_SPECIES) != SPECIES_NONE
        && GetBoxMonData(&daycare->mons[0].mon, MON_DATA_SPECIES) == SPECIES_NONE)
    {
        daycare->mons[0].mon = daycare->mons[1].mon;
        ZeroBoxMonData(&daycare->mons[1].mon);

        daycare->mons[0].mail = daycare->mons[1].mail;
        daycare->mons[0].steps = daycare->mons[1].steps;
        daycare->mons[1].steps = 0;
        ClearDaycareMonMail(&daycare->mons[1].mail);
    }
}

static void ApplyDaycareExperience(struct Pokemon *mon)
{
    s32 i;
    bool8 firstMove;
    u16 learnedMove;

    for (i = 0; i < MAX_LEVEL; i++)
    {
        // Add the mon's gained daycare experience level by level until it can't level up anymore.
        if (TryIncrementMonLevel(mon))
        {
            // Teach the mon new moves it learned while in the daycare.
            firstMove = TRUE;
            while ((learnedMove = MonTryLearningNewMove(mon, firstMove)) != 0)
            {
                firstMove = FALSE;
                if (learnedMove == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(mon, gMoveToLearn);
            }
        }
        else
        {
            break;
        }
    }

    // Re-calculate the mons stats at its new level.
    CalculateMonStats(mon);
}

static u16 TakeSelectedPokemonFromDaycare(struct DaycareMon *daycareMon)
{
    u16 species;
    u32 experience;
    struct Pokemon pokemon;

    GetBoxMonNickname(&daycareMon->mon, gStringVar1);
    species = GetBoxMonData(&daycareMon->mon, MON_DATA_SPECIES);
    BoxMonToMon(&daycareMon->mon, &pokemon);

    if (GetMonData(&pokemon, MON_DATA_LEVEL) != MAX_LEVEL)
    {
        experience = GetMonData(&pokemon, MON_DATA_EXP) + daycareMon->steps;
        SetMonData(&pokemon, MON_DATA_EXP, &experience);
        ApplyDaycareExperience(&pokemon);
    }

    gPlayerParty[PARTY_SIZE - 1] = pokemon;
    if (daycareMon->mail.message.itemId)
    {
        GiveMailToMon(&gPlayerParty[PARTY_SIZE - 1], &daycareMon->mail.message);
        ClearDaycareMonMail(&daycareMon->mail);
    }

    ZeroBoxMonData(&daycareMon->mon);
    daycareMon->steps = 0;
    CompactPartySlots();
    CalculatePlayerPartyCount();
    return species;
}

static u16 TakeSelectedPokemonMonFromDaycareShiftSlots(struct DayCare *daycare, u8 slotId)
{
    u16 species = TakeSelectedPokemonFromDaycare(&daycare->mons[slotId]);
    ShiftDaycareSlots(daycare);
    return species;
}

u16 TakePokemonFromDaycare(void)
{
    return TakeSelectedPokemonMonFromDaycareShiftSlots(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

static u8 GetLevelAfterDaycareSteps(struct BoxPokemon *mon, u32 steps)
{
    struct BoxPokemon tempMon = *mon;

    u32 experience = GetBoxMonData(mon, MON_DATA_EXP) + steps;
    SetBoxMonData(&tempMon, MON_DATA_EXP,  &experience);
    return GetLevelFromBoxMonExp(&tempMon);
}

static u8 GetNumLevelsGainedFromSteps(struct DaycareMon *daycareMon)
{
    u8 levelBefore;
    u8 levelAfter;

    levelBefore = GetLevelFromBoxMonExp(&daycareMon->mon);
    levelAfter = GetLevelAfterDaycareSteps(&daycareMon->mon, daycareMon->steps);
    return levelAfter - levelBefore;
}

static u8 GetNumLevelsGainedForDaycareMon(struct DaycareMon *daycareMon)
{
    u8 numLevelsGained = GetNumLevelsGainedFromSteps(daycareMon);
    ConvertIntToDecimalStringN(gStringVar2, numLevelsGained, STR_CONV_MODE_LEFT_ALIGN, 2);
    GetBoxMonNickname(&daycareMon->mon, gStringVar1);
    return numLevelsGained;
}

static u32 GetDaycareCostForSelectedMon(struct DaycareMon *daycareMon)
{
    u32 cost;

    u8 numLevelsGained = GetNumLevelsGainedFromSteps(daycareMon);
    GetBoxMonNickname(&daycareMon->mon, gStringVar1);
    cost = 100 + 100 * numLevelsGained;
    ConvertIntToDecimalStringN(gStringVar2, cost, STR_CONV_MODE_LEFT_ALIGN, 5);
    return cost;
}

static u16 GetDaycareCostForMon(struct DayCare *daycare, u8 slotId)
{
    return GetDaycareCostForSelectedMon(&daycare->mons[slotId]);
}

void GetDaycareCost(void)
{
    gSpecialVar_0x8005 = GetDaycareCostForMon(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

static void UNUSED Debug_AddDaycareSteps(u16 numSteps)
{
    gSaveBlock1Ptr->daycare.mons[0].steps += numSteps;
    gSaveBlock1Ptr->daycare.mons[1].steps += numSteps;
}

u8 GetNumLevelsGainedFromDaycare(void)
{
    if (GetBoxMonData(&gSaveBlock1Ptr->daycare.mons[gSpecialVar_0x8004].mon, MON_DATA_SPECIES) != 0)
        return GetNumLevelsGainedForDaycareMon(&gSaveBlock1Ptr->daycare.mons[gSpecialVar_0x8004]);

    return 0;
}

static void ClearDaycareMonMail(struct DaycareMail *mail)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
        mail->otName[i] = 0;
    for (i = 0; i < POKEMON_NAME_LENGTH + 1; i++)
        mail->monName[i] = 0;

    ClearMail(&mail->message);
}

static void ClearDaycareMon(struct DaycareMon *daycareMon)
{
    ZeroBoxMonData(&daycareMon->mon);
    daycareMon->steps = 0;
    ClearDaycareMonMail(&daycareMon->mail);
}

static void UNUSED ClearAllDaycareData(struct DayCare *daycare)
{
    u8 i;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
        ClearDaycareMon(&daycare->mons[i]);

    daycare->offspringPersonality = 0;
    daycare->stepCounter = 0;
}

// Determines what the species of an Egg would be based on the given species.
// It determines this by working backwards through the evolution chain of the
// given species.
static u16 GetEggSpecies(u16 species)
{
    int i, j, k;
    bool8 found;

    // Working backwards up to 5 times seems arbitrary, since the maximum number
    // of times would only be 3 for 3-stage evolutions.
    for (i = 0; i < EVOS_PER_MON; i++)
    {
        found = FALSE;
        for (j = 1; j < NUM_SPECIES; j++)
        {
            for (k = 0; k < EVOS_PER_MON; k++)
            {
                if (gEvolutionTable[j][k].targetSpecies == species)
                {
                    species = j;
                    found = TRUE;
                    break;
                }
            }

            if (found)
                break;
        }

        if (j == NUM_SPECIES)
            break;
    }

    return species;
}

static s32 GetParentToInheritNature(struct DayCare *daycare)
{
    //u32 species[DAYCARE_MON_COUNT];
    //s32 i;
    //s32 dittoCount;
    u8 parent = 2;

    // search for female gender
    //for (i = 0; i < DAYCARE_MON_COUNT; i++)
    //{
    //    if (GetBoxMonGender(&daycare->mons[i].mon) == MON_FEMALE)
    //        parent = i;
    //}

    // search for ditto
    //for (dittoCount = 0, i = 0; i < DAYCARE_MON_COUNT; i++)
    //{
    //    species[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES);
    //    if (species[i] == SPECIES_DITTO)
    //        dittoCount++, parent = i;
    //}

    // coin flip on ...two Dittos
    //if (dittoCount == DAYCARE_MON_COUNT)
    //{
    //    if (Random() >= USHRT_MAX / 2)
    //        parent = 0;
    //    else
    //        parent = 1;
    //}

    // Don't inherit nature if not holding Everstone
    //if (GetBoxMonData(&daycare->mons[parent].mon, MON_DATA_HELD_ITEM) != ITEM_EVERSTONE
    //    || Random() >= USHRT_MAX / 2)
    //{
    //    return -1;
    //}

    //return parent;
	
	// Either parent can pass nature with Everstone
	if (GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM) == ITEM_EVERSTONE)
		parent = 0;
	if (GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM) == ITEM_EVERSTONE)
	{
		if (parent == 0)
			parent = Random() / 3 & 1;
		else
			parent = 1;
	}
	return parent;
}

static void _TriggerPendingDaycareEgg(struct DayCare *daycare)
{
    u8 parent;
	u32 personality;
	u32 shinyValue;
    u16 i = 0;
	u8 rolls = 1;

    SeedRng2(gMain.vblankCounter2);
    parent = GetParentToInheritNature(daycare);

	if (GetBoxMonData(&daycare->mons[0].mon, MON_DATA_LANGUAGE) != GetBoxMonData(&daycare->mons[1].mon, MON_DATA_LANGUAGE))
		rolls += MASUDA_METHOD_REROLLS;
	if (HasAllMons())
		rolls += SHINY_CHARM_REROLLS;
	if (gPowerType == POWER_LUCKY && gPowerLevel == 3 && gPowerTime > 0)
		rolls *= 2;

    // don't inherit nature
    if (parent > 1)
    {
		do
		{
			personality = (Random2() << 16) | ((Random() % 0xfffe) + 1);
			shinyValue = HIHALF(*gSaveBlock2Ptr->playerTrainerId) ^ LOHALF(*gSaveBlock2Ptr->playerTrainerId) ^ HIHALF(personality) ^ LOHALF(personality);
			if (shinyValue < SHINY_ODDS)
				break;
			i++;
		} while (i < rolls);

        daycare->offspringPersonality = personality;
    }
    // inherit nature
    else
    {
        u8 wantedNature = GetNatureFromPersonality(GetBoxMonData(&daycare->mons[parent].mon, MON_DATA_PERSONALITY, NULL));
		u16 j = 0;
		i = 0;

		do
		{
			do
			{
				personality = (Random2() << 16) | (Random());
				if (wantedNature == GetNatureFromPersonality(personality) && personality != 0)
					break; // found a personality with the same nature
				i++;
			} while (i <= 0xFFFF);
			shinyValue = HIHALF(*gSaveBlock2Ptr->playerTrainerId) ^ LOHALF(*gSaveBlock2Ptr->playerTrainerId) ^ HIHALF(personality) ^ LOHALF(personality);
			if (shinyValue < SHINY_ODDS)
				break;
			j++;
		} while (j < rolls);

        daycare->offspringPersonality = personality;
    }

    FlagSet(FLAG_PENDING_DAYCARE_EGG);
}

// Functionally unused
static void _TriggerPendingDaycareMaleEgg(struct DayCare *daycare)
{
    daycare->offspringPersonality = (Random()) | (EGG_GENDER_MALE);
    FlagSet(FLAG_PENDING_DAYCARE_EGG);
}

void TriggerPendingDaycareEgg(void)
{
    _TriggerPendingDaycareEgg(&gSaveBlock1Ptr->daycare);
}

static void UNUSED TriggerPendingDaycareMaleEgg(void)
{
    _TriggerPendingDaycareMaleEgg(&gSaveBlock1Ptr->daycare);
}

// Removes the selected index from the given IV list and shifts the remaining
// elements to the left.
static void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv)
{
    s32 i, j;
    u8 temp[NUM_STATS];

    ivs[selectedIv] = 0xFF;
    for (i = 0; i < NUM_STATS; i++)
    {
        temp[i] = ivs[i];
    }

    j = 0;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (temp[i] != 0xFF)
            ivs[j++] = temp[i];
    }
}

static void InheritIVs(struct Pokemon *egg, struct DayCare *daycare)
{
    u8 i;
    u8 selectedIvs[INHERITED_IV_COUNT];
    u8 availableIVs[NUM_STATS];
    u8 whichParents[INHERITED_IV_COUNT];
    u8 iv;

    // Initialize a list of IV indices.
    for (i = 0; i < NUM_STATS; i++)
    {
        availableIVs[i] = i;
    }

    // Select the 3 IVs that will be inherited.
    for (i = 0; i < INHERITED_IV_COUNT; i++)
    {
        // Randomly pick an IV from the available list and stop from being chosen again.
        selectedIvs[i] = availableIVs[Random() % (NUM_STATS - i)];
        RemoveIVIndexFromList(availableIVs, i);
    }

    // Determine which parent each of the selected IVs should inherit from.
    for (i = 0; i < INHERITED_IV_COUNT; i++)
    {
        whichParents[i] = Random() % DAYCARE_MON_COUNT;
    }

    // Set each of inherited IVs on the egg mon.
    for (i = 0; i < INHERITED_IV_COUNT; i++)
    {
        switch (selectedIvs[i])
        {
            case 0:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_HP_IV);
                SetMonData(egg, MON_DATA_HP_IV, &iv);
                break;
            case 1:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_ATK_IV);
                SetMonData(egg, MON_DATA_ATK_IV, &iv);
                break;
            case 2:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_DEF_IV);
                SetMonData(egg, MON_DATA_DEF_IV, &iv);
                break;
            case 3:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPEED_IV);
                SetMonData(egg, MON_DATA_SPEED_IV, &iv);
                break;
            case 4:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPATK_IV);
                SetMonData(egg, MON_DATA_SPATK_IV, &iv);
                break;
            case 5:
                iv = GetBoxMonData(&daycare->mons[whichParents[i]].mon, MON_DATA_SPDEF_IV);
                SetMonData(egg, MON_DATA_SPDEF_IV, &iv);
                break;
        }
    }
}

// Counts the number of egg moves a Pokémon learns and stores the moves in
// the given array.
static u8 GetEggMoves(struct Pokemon *pokemon, u16 *eggMoves)
{
    u16 eggMoveIdx;
    u16 numEggMoves;
    u16 species;
    u16 i;

    numEggMoves = 0;
    eggMoveIdx = 0;
    species = GetMonData(pokemon, MON_DATA_SPECIES);
    for (i = 0; i < ARRAY_COUNT(gEggMoves) - 1; i++)
    {
        if (gEggMoves[i] == species + EGG_MOVES_SPECIES_OFFSET)
        {
            eggMoveIdx = i + 1;
            break;
        }
    }

    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
    {
        if (gEggMoves[eggMoveIdx + i] > EGG_MOVES_SPECIES_OFFSET)
            break;

        eggMoves[i] = gEggMoves[eggMoveIdx + i];
        numEggMoves++;
    }

    return numEggMoves;
}

static void BuildEggMoveset(struct Pokemon *egg, struct BoxPokemon *father, struct BoxPokemon *mother)
{
    u16 numSharedParentMoves;
    u32 numLevelUpMoves;
    u16 numEggMoves;
	u16 numFatherEggMoves;
    u16 i, j, k;

    numSharedParentMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sHatchedEggMotherMoves[i] = MOVE_NONE;
        sHatchedEggFatherMoves[i] = MOVE_NONE;
        sHatchedEggFinalMoves[i] = MOVE_NONE;
    }
    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
        sHatchedEggEggMoves[i] = MOVE_NONE;
    for (i = 0; i < EGG_LVL_UP_MOVES_ARRAY_COUNT; i++)
        sHatchedEggLevelUpMoves[i] = MOVE_NONE;

    numLevelUpMoves = GetLevelUpMovesBySpecies(GetMonData(egg, MON_DATA_SPECIES), sHatchedEggLevelUpMoves);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sHatchedEggFatherMoves[i] = GetBoxMonData(father, MON_DATA_MOVE1 + i);
        sHatchedEggMotherMoves[i] = GetBoxMonData(mother, MON_DATA_MOVE1 + i);
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (sHatchedEggFatherMoves[i] == sHatchedEggMotherMoves[j] && sHatchedEggFatherMoves[i] != MOVE_NONE)
                sHatchedEggFinalMoves[numSharedParentMoves++] = sHatchedEggFatherMoves[i];
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            {
                if (sHatchedEggFatherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01 + j) && CanMonLearnTMHM(egg, j))
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                }
            }
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggMotherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            {
                if (sHatchedEggMotherMoves[i] == ItemIdToBattleMoveId(ITEM_TM01 + j) && CanMonLearnTMHM(egg, j))
                {
                    if (GiveMoveToMon(egg, sHatchedEggMotherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggMotherMoves[i]);
                }
            }
        }
    }

    numEggMoves = GetEggMoves(egg, sHatchedEggEggMoves);
    numFatherEggMoves = GetEggMoves(egg, sHatchedEggFatherEggMoves);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < numEggMoves; j++)
            {
                if (sHatchedEggFatherMoves[i] == sHatchedEggEggMoves[j])
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
		
	for (i = 0; i < MAX_MON_MOVES; i++)
    {
		if (sHatchedEggMotherMoves[i] != MOVE_NONE)
		{
			for (j = 0; j < numEggMoves; j++)
			{
				if (sHatchedEggMotherMoves[i] == sHatchedEggEggMoves[j])
				{
					for (k = 0; k < numFatherEggMoves; k++)
					{
						if (sHatchedEggMotherMoves[i] == sHatchedEggFatherEggMoves[k])
						{
							if (GiveMoveToMon(egg, sHatchedEggMotherMoves[i]) == MON_HAS_MAX_MOVES)
								DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggMotherMoves[i]);
						}
					}
					break;
				}
			}
		}
        else
        {
            break;
        }
    }
	
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFinalMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numLevelUpMoves; j++)
        {
            if (sHatchedEggLevelUpMoves[j] != MOVE_NONE && sHatchedEggFinalMoves[i] == sHatchedEggLevelUpMoves[j])
            {
                GiveMoveToMon(egg, sHatchedEggFinalMoves[i]);
                break;
            }
        }
    }
}

static void RemoveEggFromDayCare(struct DayCare *daycare)
{
    daycare->offspringPersonality = 0;
    daycare->stepCounter = 0;
}

void RejectEggFromDayCare(void)
{
    RemoveEggFromDayCare(&gSaveBlock1Ptr->daycare);
}

static void AlterEggSpeciesWithIncenseItem(u16 *species, struct DayCare *daycare)
{
    u16 motherItem, fatherItem;
    if (*species == SPECIES_WYNAUT || *species == SPECIES_AZURILL)
    {
        motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
        fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);
        if (*species == SPECIES_WYNAUT && motherItem != ITEM_LAX_INCENSE && fatherItem != ITEM_LAX_INCENSE)
        {
            *species = SPECIES_WOBBUFFET;
        }

        if (*species == SPECIES_AZURILL && motherItem != ITEM_SEA_INCENSE && fatherItem != ITEM_SEA_INCENSE)
        {
            *species = SPECIES_MARILL;
        }
    }
}

static void GiveVoltTackleIfLightBall(struct Pokemon *mon, struct DayCare *daycare)
{
    u32 motherItem = GetBoxMonData(&daycare->mons[0].mon, MON_DATA_HELD_ITEM);
    u32 fatherItem = GetBoxMonData(&daycare->mons[1].mon, MON_DATA_HELD_ITEM);

    if (motherItem == ITEM_LIGHT_BALL || fatherItem == ITEM_LIGHT_BALL)
    {
        if (GiveMoveToMon(mon, MOVE_VOLT_TACKLE) == MON_HAS_MAX_MOVES)
            DeleteFirstMoveAndGiveMoveToMon(mon, MOVE_VOLT_TACKLE);
    }
}

static u16 DetermineEggSpeciesAndParentSlots(struct DayCare *daycare, u8 *parentSlots)
{
    u16 i;
    u16 species[DAYCARE_MON_COUNT];
    u16 eggSpecies;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        species[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES);
        if (species[i] == SPECIES_DITTO)
        {
            parentSlots[0] = i ^ 1;
            parentSlots[1] = i;
        }
        else if (GetBoxMonGender(&daycare->mons[i].mon) == MON_FEMALE)
        {
            parentSlots[0] = i;
            parentSlots[1] = i ^ 1;
        }
    }

    eggSpecies = GetEggSpecies(species[parentSlots[0]]);
    if (eggSpecies == SPECIES_NIDORAN_F && daycare->offspringPersonality & EGG_GENDER_MALE)
    {
        eggSpecies = SPECIES_NIDORAN_M;
    }
    if (eggSpecies == SPECIES_ILLUMISE && daycare->offspringPersonality & EGG_GENDER_MALE)
    {
        eggSpecies = SPECIES_VOLBEAT;
    }

    // Make Ditto the "mother" slot if the other daycare mon is male.
    if (species[parentSlots[1]] == SPECIES_DITTO && GetBoxMonGender(&daycare->mons[parentSlots[0]].mon) != MON_FEMALE)
    {
        u8 ditto = parentSlots[1];
        parentSlots[1] = parentSlots[0];
        parentSlots[0] = ditto;
    }

    return eggSpecies;
}

static void _GiveEggFromDaycare(struct DayCare *daycare)
{
    struct Pokemon egg;
    u16 species;
    u8 parentSlots[DAYCARE_MON_COUNT];
    bool8 isEgg;

    species = DetermineEggSpeciesAndParentSlots(daycare, parentSlots);
    AlterEggSpeciesWithIncenseItem(&species, daycare);
    SetInitialEggData(&egg, species, daycare);
    InheritIVs(&egg, daycare);
    BuildEggMoveset(&egg, &daycare->mons[parentSlots[1]].mon, &daycare->mons[parentSlots[0]].mon);

    if (species == SPECIES_PICHU)
        GiveVoltTackleIfLightBall(&egg, daycare);

    isEgg = TRUE;
    SetMonData(&egg, MON_DATA_IS_EGG, &isEgg);
    gPlayerParty[PARTY_SIZE - 1] = egg;
    CompactPartySlots();
    CalculatePlayerPartyCount();
    RemoveEggFromDayCare(daycare);
}

void CreateEgg(struct Pokemon *mon, u16 species, bool8 setHotSpringsLocation)
{
    u8 metLevel;
    u16 ball;
    u8 language;
    u8 metLocation;
    u8 isEgg;
	u32 personality;
	u32 shinyValue;
	u16 i = 0;
	u8 rolls = 1;
	
	if (HasAllMons())
		rolls += SHINY_CHARM_REROLLS;
	if (gPowerType == POWER_LUCKY && gPowerLevel == 3 && gPowerTime > 0)
		rolls *= 2;
	
	do
	{
		personality = (Random2() << 16) | ((Random() % 0xfffe) + 1);
		shinyValue = HIHALF(*gSaveBlock2Ptr->playerTrainerId) ^ LOHALF(*gSaveBlock2Ptr->playerTrainerId) ^ HIHALF(personality) ^ LOHALF(personality);
		if (shinyValue < SHINY_ODDS)
			break;
		i++;
	} while (i < rolls);
	
	if (species == SPECIES_WYNAUT)
		CreateMon(mon, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
	else
		CreateMon(mon, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);
    metLevel = 0;
    ball = ITEM_POKE_BALL;
    language = LANGUAGE_JAPANESE;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    SetMonData(mon, MON_DATA_NICKNAME, sJapaneseEggNickname);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].eggCycles);
    SetMonData(mon, MON_DATA_MET_LEVEL, &metLevel);
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
	SetMonData(mon, MON_DATA_MET_GAME, &gGameVersion);
    if (setHotSpringsLocation)
    {
        metLocation = METLOC_SPECIAL_EGG;
        SetMonData(mon, MON_DATA_MET_LOCATION, &metLocation);
    }

    isEgg = TRUE;
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);
}

static void SetInitialEggData(struct Pokemon *mon, u16 species, struct DayCare *daycare)
{
    u32 personality;
    u16 ball;
    u8 metLevel;
    u8 language;
	u8 version;

    personality = daycare->offspringPersonality;
    CreateMon(mon, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);
    metLevel = 0;
    ball = ITEM_POKE_BALL;
    language = LANGUAGE_JAPANESE;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    SetMonData(mon, MON_DATA_NICKNAME, sJapaneseEggNickname);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].eggCycles);
    SetMonData(mon, MON_DATA_MET_LEVEL, &metLevel);
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
	if (FlagGet(FLAG_GEN_KANTO_EGGS))
	{
		if (CheckBagHasItem(ITEM_SAPPHIRE, 1))
			version = VERSION_LEAFGREEN;
		else
			version = VERSION_FIRERED;
	}
	else
	{
		version = gGameVersion;
	}
	SetMonData(mon, MON_DATA_MET_GAME, &version);
}

void GiveEggFromDaycare(void)
{
    _GiveEggFromDaycare(&gSaveBlock1Ptr->daycare);
}

static bool8 TryProduceOrHatchEgg(struct DayCare *daycare)
{
    u32 i, validEggs = 0;
	u8 cycleLength = 255;

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        if (GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SANITY_HAS_SPECIES))
            daycare->mons[i].steps++, validEggs++;
    }

    // Check if an egg should be produced
    if (daycare->offspringPersonality == 0 && validEggs == DAYCARE_MON_COUNT && (daycare->mons[1].steps & 0xFF) == 0xFF)
    {
        u8 compatibility = GetDaycareCompatibilityScore(daycare);
		if (HasAllHoennMons())
		{
			switch (compatibility)
			{
			case PARENTS_LOW_COMPATIBILITY:
				compatibility = 40;
				break;
			case PARENTS_MED_COMPATIBILITY:
				compatibility = 80;
				break;
			case PARENTS_MAX_COMPATIBILITY:
				compatibility = 88;
				break;
			default:
				break;
			}
		}
        if (compatibility > (Random() * 100u) / USHRT_MAX)
            TriggerPendingDaycareEgg();
    }

	if (gPowerType == POWER_HATCH && gPowerTime > 0)
	{
		switch (gPowerLevel)
		{
			case 1:
				cycleLength = 205;
				break;
			case 2:
				cycleLength = 171;
				break;
			case 3:
				cycleLength = 129;
				break;
		}
	}

    // Try to hatch Egg
    if (++daycare->stepCounter == cycleLength)
    {
        u32 eggCycles;
        u8 toSub = GetEggCyclesToSubtract();

        for (i = 0; i < gPlayerPartyCount; i++)
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                continue;
            if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG))
                continue;

            eggCycles = GetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP);
            if (eggCycles != 0)
            {
                if (eggCycles >= toSub)
                    eggCycles -= toSub;
                else
                    eggCycles -= 1;

                SetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP, &eggCycles);
            }
            else
            {
                gSpecialVar_0x8004 = i;
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool8 ShouldEggHatch(void)
{
    return TryProduceOrHatchEgg(&gSaveBlock1Ptr->daycare);
}

static bool8 IsEggPending(struct DayCare *daycare)
{
    return (daycare->offspringPersonality != 0);
}

// gStringVar1 = first mon's nickname
// gStringVar2 = second mon's nickname
// gStringVar3 = first mon trainer's name
static void _GetDaycareMonNicknames(struct DayCare *daycare)
{
    u8 otName[max(12, PLAYER_NAME_LENGTH + 1)];
    if (GetBoxMonData(&daycare->mons[0].mon, MON_DATA_SPECIES) != 0)
    {
        GetBoxMonNickname(&daycare->mons[0].mon, gStringVar1);
        GetBoxMonData(&daycare->mons[0].mon, MON_DATA_OT_NAME, otName);
        StringCopy(gStringVar3, otName);
    }

    if (GetBoxMonData(&daycare->mons[1].mon, MON_DATA_SPECIES) != 0)
    {
        GetBoxMonNickname(&daycare->mons[1].mon, gStringVar2);
    }
}

u16 GetSelectedMonNicknameAndSpecies(void)
{
    GetBoxMonNickname(&gPlayerParty[GetCursorSelectionMonId()].box, gStringVar1);
    return GetBoxMonData(&gPlayerParty[GetCursorSelectionMonId()].box, MON_DATA_SPECIES);
}

void GetDaycareMonNicknames(void)
{
    _GetDaycareMonNicknames(&gSaveBlock1Ptr->daycare);
}

u8 GetDaycareState(void)
{
    u8 numMons;
    if (IsEggPending(&gSaveBlock1Ptr->daycare))
    {
        return DAYCARE_EGG_WAITING;
    }

    numMons = CountPokemonInDaycare(&gSaveBlock1Ptr->daycare);
    if (numMons != 0)
    {
        return numMons + 1; // DAYCARE_ONE_MON or DAYCARE_TWO_MONS
    }

    return DAYCARE_NO_MONS;
}

static u8 UNUSED GetDaycarePokemonCount(void)
{
    u8 ret = CountPokemonInDaycare(&gSaveBlock1Ptr->daycare);
    if (ret)
        return ret;

    return 0;
}

// Determine if the two given egg group lists contain any of the
// same egg groups.
static bool8 EggGroupsOverlap(u16 *eggGroups1, u16 *eggGroups2)
{
    s32 i, j;

    for (i = 0; i < EGG_GROUPS_PER_MON; i++)
    {
        for (j = 0; j < EGG_GROUPS_PER_MON; j++)
        {
            if (eggGroups1[i] == eggGroups2[j])
                return TRUE;
        }
    }

    return FALSE;
}

static u8 GetDaycareCompatibilityScore(struct DayCare *daycare)
{
    u32 i;
    u16 eggGroups[DAYCARE_MON_COUNT][EGG_GROUPS_PER_MON];
    u16 species[DAYCARE_MON_COUNT];
    u32 trainerIds[DAYCARE_MON_COUNT];
    u32 genders[DAYCARE_MON_COUNT];

    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        u32 personality;

        species[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_SPECIES);
        trainerIds[i] = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_OT_ID);
        personality = GetBoxMonData(&daycare->mons[i].mon, MON_DATA_PERSONALITY);
        genders[i] = GetGenderFromSpeciesAndPersonality(species[i], personality);
        eggGroups[i][0] = gSpeciesInfo[species[i]].eggGroups[0];
        eggGroups[i][1] = gSpeciesInfo[species[i]].eggGroups[1];
    }

    // check unbreedable egg group
    if (eggGroups[0][0] == EGG_GROUP_NO_EGGS_DISCOVERED || eggGroups[1][0] == EGG_GROUP_NO_EGGS_DISCOVERED)
        return PARENTS_INCOMPATIBLE;
    // two Ditto can't breed
    if (eggGroups[0][0] == EGG_GROUP_DITTO && eggGroups[1][0] == EGG_GROUP_DITTO)
        return PARENTS_INCOMPATIBLE;

    // one parent is Ditto
    if (eggGroups[0][0] == EGG_GROUP_DITTO || eggGroups[1][0] == EGG_GROUP_DITTO)
    {
        if (trainerIds[0] == trainerIds[1])
            return PARENTS_LOW_COMPATIBILITY;

        return PARENTS_MED_COMPATIBILITY;
    }
    // neither parent is Ditto
    else
    {
        if (genders[0] == genders[1])
            return PARENTS_INCOMPATIBLE;
        if (genders[0] == MON_GENDERLESS || genders[1] == MON_GENDERLESS)
            return PARENTS_INCOMPATIBLE;
        if (!EggGroupsOverlap(eggGroups[0], eggGroups[1]))
            return PARENTS_INCOMPATIBLE;

        if (species[0] == species[1])
        {
            if (trainerIds[0] == trainerIds[1])
                return PARENTS_MED_COMPATIBILITY; // same species, same trainer

            return PARENTS_MAX_COMPATIBILITY; // same species, different trainers
        }
        else
        {
            if (trainerIds[0] != trainerIds[1])
                return PARENTS_MED_COMPATIBILITY; // different species, different trainers

            return PARENTS_LOW_COMPATIBILITY; // different species, same trainer
        }
    }
}

static u8 GetDaycareCompatibilityScoreFromSave(void)
{
    return GetDaycareCompatibilityScore(&gSaveBlock1Ptr->daycare);
}

void SetDaycareCompatibilityString(void)
{
    u8 whichString;
    u8 relationshipScore;

    relationshipScore = GetDaycareCompatibilityScoreFromSave();
    whichString = 0;
    if (relationshipScore == PARENTS_INCOMPATIBLE)
        whichString = 3;
    if (relationshipScore == PARENTS_LOW_COMPATIBILITY)
        whichString = 2;
    if (relationshipScore == PARENTS_MED_COMPATIBILITY)
        whichString = 1;
    if (relationshipScore == PARENTS_MAX_COMPATIBILITY)
        whichString = 0;

    StringCopy(gStringVar4, sCompatibilityMessages[whichString]);
}

bool8 NameHasGenderSymbol(const u8 *name, u8 genderRatio)
{
    u8 i;
    u8 symbolsCount[GENDER_COUNT];
    symbolsCount[MALE] = symbolsCount[FEMALE] = 0;

    for (i = 0; name[i] != EOS; i++)
    {
        if (name[i] == CHAR_MALE)
            symbolsCount[MALE]++;
        if (name[i] == CHAR_FEMALE)
            symbolsCount[FEMALE]++;
    }

    if (genderRatio == MON_MALE   && symbolsCount[MALE] != 0 && symbolsCount[FEMALE] == 0)
        return TRUE;
    if (genderRatio == MON_FEMALE && symbolsCount[FEMALE] != 0 && symbolsCount[MALE] == 0)
        return TRUE;

    return FALSE;
}

static u8 *AppendGenderSymbol(u8 *name, u8 gender)
{
    if (gender == MON_MALE)
    {
        if (!NameHasGenderSymbol(name, MON_MALE))
            return StringAppend(name, gText_MaleSymbol4);
    }
    else if (gender == MON_FEMALE)
    {
        if (!NameHasGenderSymbol(name, MON_FEMALE))
            return StringAppend(name, gText_FemaleSymbol4);
    }

    return StringAppend(name, gText_GenderlessSymbol);
}

static u8 *AppendMonGenderSymbol(u8 *name, struct BoxPokemon *boxMon)
{
    return AppendGenderSymbol(name, GetBoxMonGender(boxMon));
}

static void UNUSED GetDaycareLevelMenuText(struct DayCare *daycare, u8 *dest)
{
    u8 monNames[DAYCARE_MON_COUNT][POKEMON_NAME_BUFFER_SIZE];
    u8 i;

    *dest = EOS;
    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        GetBoxMonNickname(&daycare->mons[i].mon, monNames[i]);
        AppendMonGenderSymbol(monNames[i], &daycare->mons[i].mon);
    }

    StringCopy(dest, monNames[0]);
    StringAppend(dest, gText_NewLine2);
    StringAppend(dest, monNames[1]);
    StringAppend(dest, gText_NewLine2);
    StringAppend(dest, gText_Exit4);
}

static void UNUSED GetDaycareLevelMenuLevelText(struct DayCare *daycare, u8 *dest)
{
    u8 i;
    u8 level;
    u8 text[20];

    *dest = EOS;
    for (i = 0; i < DAYCARE_MON_COUNT; i++)
    {
        StringAppend(dest, gText_Lv);
        level = GetLevelAfterDaycareSteps(&daycare->mons[i].mon, daycare->mons[i].steps);
        ConvertIntToDecimalStringN(text, level, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(dest, text);
        StringAppend(dest, gText_NewLine2);
    }
}

static void DaycareAddTextPrinter(u8 windowId, const u8 *text, u32 x, u32 y)
{
    struct TextPrinterTemplate printer;

    printer.currentChar = text;
    printer.windowId = windowId;
    printer.fontId = FONT_OPTION;
    printer.x = x;
    printer.y = y;
    printer.currentX = x;
    printer.currentY = y;
    printer.unk = 0;
    gTextFlags.useAlternateDownArrow = 0;
    printer.letterSpacing = 0;
    printer.lineSpacing = 1;
    printer.fgColor = 2;
    printer.bgColor = 1;
    printer.shadowColor = 3;

    AddTextPrinter(&printer, TEXT_SKIP_DRAW, NULL);
}

static void DaycarePrintMonNickname(struct DayCare *daycare, u8 windowId, u32 daycareSlotId, u32 y)
{
    u8 nickname[POKEMON_NAME_BUFFER_SIZE];
    GetBoxMonNickname(&daycare->mons[daycareSlotId].mon, nickname);
    AppendMonGenderSymbol(nickname, &daycare->mons[daycareSlotId].mon);
    DaycareAddTextPrinter(windowId, nickname, 8, y);
}

static void DaycarePrintMonLvl(struct DayCare *daycare, u8 windowId, u32 daycareSlotId, u32 y)
{
    u8 level;
    u32 x;
    u8 lvlText[12];
    u8 intText[8];

    StringCopy(lvlText, gText_Lv);
    level = GetLevelAfterDaycareSteps(&daycare->mons[daycareSlotId].mon, daycare->mons[daycareSlotId].steps);
    ConvertIntToDecimalStringN(intText, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(lvlText, intText);
    x = GetStringRightAlignXOffset(FONT_OPTION, lvlText, 112);
    DaycareAddTextPrinter(windowId, lvlText, x, y);
}

static void DaycarePrintMonInfo(u8 windowId, u32 daycareSlotId, u8 y)
{
    if (daycareSlotId < (unsigned) DAYCARE_MON_COUNT)
    {
        DaycarePrintMonNickname(&gSaveBlock1Ptr->daycare, windowId, daycareSlotId, y);
        DaycarePrintMonLvl(&gSaveBlock1Ptr->daycare, windowId, daycareSlotId, y);
    }
}

#define tMenuListTaskId     data[0]
#define tWindowId           data[1]

static void Task_HandleDaycareLevelMenuInput(u8 taskId)
{
    u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuListTaskId);

    if (JOY_NEW(A_BUTTON))
    {
        switch (input)
        {
        case 0:
        case 1:
            gSpecialVar_Result = input;
            break;
        case DAYCARE_LEVEL_MENU_EXIT:
            gSpecialVar_Result = DAYCARE_EXITED_LEVEL_MENU;
            break;
        }
        DestroyListMenuTask(gTasks[taskId].tMenuListTaskId, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tWindowId);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gSpecialVar_Result = DAYCARE_EXITED_LEVEL_MENU;
        DestroyListMenuTask(gTasks[taskId].tMenuListTaskId, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tWindowId);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

void ShowDaycareLevelMenu(void)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId;
    u8 listMenuTaskId;
    u8 daycareMenuTaskId;

    windowId = AddWindow(&sDaycareLevelMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    menuTemplate = sDaycareListMenuLevelTemplate;
    menuTemplate.windowId = windowId;
    listMenuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    CopyWindowToVram(windowId, COPYWIN_FULL);

    daycareMenuTaskId = CreateTask(Task_HandleDaycareLevelMenuInput, 3);
    gTasks[daycareMenuTaskId].tMenuListTaskId = listMenuTaskId;
    gTasks[daycareMenuTaskId].tWindowId = windowId;
}

#undef tMenuListTaskId
#undef tWindowId

void ChooseSendDaycareMon(void)
{
    ChooseMonForDaycare();
    gMain.savedCallback = CB2_ReturnToField;
}

u8 PutEggInIncubator(struct Pokemon *egg)
{
	if (FlagGet(FLAG_EGG_IN_INCUBATOR))
		return 0xFF;
	
	(&gSaveBlock1Ptr->incubator)->egg = *egg;
	(&gSaveBlock1Ptr->incubator)->timeEntered = gLocalTime;
	ZeroMonData(egg);
	CompactPartySlots();
	CalculatePlayerPartyCount();
	FlagSet(FLAG_EGG_IN_INCUBATOR);
	return 0;
}

u8 CheckIncubator()
{
	struct Pokemon egg;
	struct Time timeElapsed;
	u32 eggCycles;
	u32 eggCyclesDepleted;
	u32 eggCyclesNew;
	u32 minutesPassedCycle;
	u32 minutesLeft;
	
	if (!FlagGet(FLAG_EGG_IN_INCUBATOR))
		return 0xFF;
	
	egg = (&gSaveBlock1Ptr->incubator)->egg;
	RtcCalcLocalTime();
	CalcTimeDifference(&timeElapsed, &(&gSaveBlock1Ptr->incubator)->timeEntered, &gLocalTime);
	eggCycles = GetMonData(&egg, MON_DATA_FRIENDSHIP);
	eggCyclesDepleted = (24 * 60 * timeElapsed.days + 60 * timeElapsed.hours + timeElapsed.minutes) / 36;
	minutesPassedCycle = (24 * 60 * timeElapsed.days + 60 * timeElapsed.hours + timeElapsed.minutes) % 36;
	
	if (eggCyclesDepleted > eggCycles)
	{
		eggCyclesNew = 0;
	}
	else if (eggCyclesDepleted != 0)
	{
		eggCyclesNew = eggCycles - eggCyclesDepleted;
		SetMonData(&(&gSaveBlock1Ptr->incubator)->egg, MON_DATA_FRIENDSHIP, &eggCyclesNew);
		(&gSaveBlock1Ptr->incubator)->timeEntered = gLocalTime;
		(&gSaveBlock1Ptr->incubator)->timeEntered.minutes -= minutesPassedCycle;
		if ((&gSaveBlock1Ptr->incubator)->timeEntered.minutes < 0)
		{
			(&gSaveBlock1Ptr->incubator)->timeEntered.minutes += 60;
			--(&gSaveBlock1Ptr->incubator)->timeEntered.hours;
		}
		if ((&gSaveBlock1Ptr->incubator)->timeEntered.hours < 0)
		{
			(&gSaveBlock1Ptr->incubator)->timeEntered.hours += 24;
			--(&gSaveBlock1Ptr->incubator)->timeEntered.days;
		}
	}
	else
	{
		eggCyclesNew = eggCycles;
	}
	
	minutesLeft = eggCyclesNew * 36 - minutesPassedCycle;
	
	if (minutesLeft > 1380)
	{
		StringCopy(gStringVar1, gText_2324);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1320)
	{
		StringCopy(gStringVar1, gText_2223);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1260)
	{
		StringCopy(gStringVar1, gText_2122);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1200)
	{
		StringCopy(gStringVar1, gText_2021);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1140)
	{
		StringCopy(gStringVar1, gText_1920);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1080)
	{
		StringCopy(gStringVar1, gText_1819);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1020)
	{
		StringCopy(gStringVar1, gText_1718);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 960)
	{
		StringCopy(gStringVar1, gText_1617);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 900)
	{
		StringCopy(gStringVar1, gText_1516);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 840)
	{
		StringCopy(gStringVar1, gText_1415);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 780)
	{
		StringCopy(gStringVar1, gText_1314);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 720)
	{
		StringCopy(gStringVar1, gText_1213);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 660)
	{
		StringCopy(gStringVar1, gText_1112);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 600)
	{
		StringCopy(gStringVar1, gText_1011);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 540)
	{
		StringCopy(gStringVar1, gText_910);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 480)
	{
		StringCopy(gStringVar1, gText_89);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 420)
	{
		StringCopy(gStringVar1, gText_78);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 360)
	{
		StringCopy(gStringVar1, gText_67);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 300)
	{
		StringCopy(gStringVar1, gText_56);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 240)
	{
		StringCopy(gStringVar1, gText_45);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 180)
	{
		StringCopy(gStringVar1, gText_34);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 120)
	{
		StringCopy(gStringVar1, gText_23);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 60)
	{
		StringCopy(gStringVar1, gText_12);
		StringCopy(gStringVar2, gText_Hours);
	}
	else if (minutesLeft > 1)
	{
		ConvertIntToDecimalStringN(gStringVar1, minutesLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
		StringCopy(gStringVar2, gText_Minutes);
	}
	else
	{
		ConvertIntToDecimalStringN(gStringVar1, minutesLeft, STR_CONV_MODE_LEFT_ALIGN, 4);
		StringCopy(gStringVar2, gText_Minute);
	}
	
	if (eggCyclesNew == 0)
	{
		return 0;
	}
	else
	{
		return eggCyclesNew;
	}
}

u8 RemoveEggFromIncubator()
{
	struct Pokemon egg;
	u32 eggStatus;
	
	egg = (&gSaveBlock1Ptr->incubator)->egg;
	eggStatus = CheckIncubator();
	
	if (eggStatus != 0)
	{
		gPlayerParty[PARTY_SIZE - 1] = egg;
		ZeroMonData(&(&gSaveBlock1Ptr->incubator)->egg);
		CompactPartySlots();
		CalculatePlayerPartyCount();
		FlagClear(FLAG_EGG_IN_INCUBATOR);
		return 0;
	}
	else if (eggStatus == 0xFF)
	{
		return 0xFF;
	}
	else
	{
		return 0;
	}
}

void ChooseEggForIncubator()
{
    SelectEggForIncubator();
    gMain.savedCallback = CB2_ReturnToField;
}

void PutSelectedEggInIncubator()
{
    u8 monId = GetCursorSelectionMonId();
    PutEggInIncubator(&gPlayerParty[monId]);
}

void HatchEggInIncubator()
{
	struct Pokemon egg;
	
	egg = (&gSaveBlock1Ptr->incubator)->egg;
	
	gPlayerParty[PARTY_SIZE - 1] = egg;
	ZeroMonData(&(&gSaveBlock1Ptr->incubator)->egg);
	CompactPartySlots();
	CalculatePlayerPartyCount();
	FlagClear(FLAG_EGG_IN_INCUBATOR);
	gSpecialVar_0x8004 = gPlayerPartyCount - 1;
	IncrementGameStat(GAME_STAT_HATCHED_EGGS);
	EggHatch();
}

void GiveEventEgg(void)
{
	struct Pokemon mon;
	u16 species, iv1, iv2, value;
	u32 personality;
	u32 shinyValue;
	u8 metLevel = 0;
	u16 ball = ITEM_POKE_BALL;
	u8 language = LANGUAGE_JAPANESE;
	u8 metLocation = METLOC_FATEFUL_ENCOUNTER;
	bool8 isEgg = TRUE;
	u8 version = gGameVersion;
	bool8 isFRLG = FALSE;
	bool8 fatefulEncounter = TRUE;
	u16 move0 = 0;
	u16 move1 = 0;
	u16 move2 = 0;
	u16 move3 = 0;
	u16 i = 0;
	u8 rolls = 1;
	
	if (gSpecialVar_0x8004 > 28)
		gSpecialVar_0x8004 = Random() % 29;
	
	switch (gSpecialVar_0x8004)
	{
		case 0:		//Egg Pokémon Present Eggs
			species = SPECIES_ODDISH;
			move0 = MOVE_ABSORB;
			move1 = MOVE_LEECH_SEED;
			isFRLG = TRUE;
			break;
		case 1:
			species = SPECIES_MEOWTH;
			move0 = MOVE_SCRATCH;
			move1 = MOVE_GROWL;
			move2 = MOVE_PETAL_DANCE;
			isFRLG = TRUE;
			break;
		case 2:
			species = SPECIES_POLIWAG;
			move0 = MOVE_BUBBLE;
			move1 = MOVE_SWEET_KISS;
			isFRLG = TRUE;
			break;
		case 3:
			species = SPECIES_BELLSPROUT;
			move0 = MOVE_VINE_WHIP;
			move1 = MOVE_TEETER_DANCE;
			isFRLG = TRUE;
			break;
		case 4:		//PokéPark Eggs
			species = SPECIES_PSYDUCK;
			move0 = MOVE_WATER_SPORT;
			move1 = MOVE_SCRATCH;
			move2 = MOVE_TAIL_WHIP;
			move3 = MOVE_MUD_SPORT;
			break;
		case 5:
			species = SPECIES_PICHU;
			move0 = MOVE_THUNDER_SHOCK;
			move1 = MOVE_CHARM;
			move2 = MOVE_FOLLOW_ME;
			break;
		case 6:
			species = SPECIES_IGGLYBUFF;
			move0 = MOVE_SING;
			move1 = MOVE_CHARM;
			move2 = MOVE_DEFENSE_CURL;
			move3 = MOVE_TICKLE;
			break;
		case 7:
			species = SPECIES_CORSOLA;
			move0 = MOVE_TACKLE;
			move1 = MOVE_MUD_SPORT;
			break;
		case 8:
			species = SPECIES_TAILLOW;
			move0 = MOVE_PECK;
			move1 = MOVE_GROWL;
			move2 = MOVE_FOCUS_ENERGY;
			move3 = MOVE_FEATHER_DANCE;
			break;
		case 9:
			species = SPECIES_SURSKIT;
			move0 = MOVE_BUBBLE;
			move1 = MOVE_MUD_SPORT;
			break;
		case 10:
			species = SPECIES_WHISMUR;
			move0 = MOVE_POUND;
			move1 = MOVE_UPROAR;
			move2 = MOVE_TEETER_DANCE;
			break;
		case 11:
			species = SPECIES_SKITTY;
			move0 = MOVE_GROWL;
			move1 = MOVE_TACKLE;
			move2 = MOVE_TAIL_WHIP;
			move3 = MOVE_ROLLOUT;
			break;
		case 12:
			species = SPECIES_PLUSLE;
			move0 = MOVE_GROWL;
			move1 = MOVE_THUNDER_WAVE;
			move2 = MOVE_WATER_SPORT;
			break;
		case 13:
			species = SPECIES_MINUN;
			move0 = MOVE_GROWL;
			move1 = MOVE_THUNDER_WAVE;
			move2 = MOVE_MUD_SPORT;
			break;
		case 14:
			species = SPECIES_SPOINK;
			move0 = MOVE_SPLASH;
			move1 = MOVE_UPROAR;
			break;
		case 15:
			species = SPECIES_SPINDA;
			move0 = MOVE_TACKLE;
			move1 = MOVE_UPROAR;
			move2 = MOVE_SING;
			break;
		case 16:
			species = SPECIES_CACNEA;
			move0 = MOVE_POISON_STING;
			move1 = MOVE_LEER;
			move2 = MOVE_ABSORB;
			move3 = MOVE_ENCORE;
			break;
		case 17:
			species = SPECIES_CORPHISH;
			move0 = MOVE_BUBBLE;
			move1 = MOVE_WATER_SPORT;
			break;
		case 18:
			species = SPECIES_WYNAUT;
			move0 = MOVE_SPLASH;
			move1 = MOVE_CHARM;
			move2 = MOVE_ENCORE;
			move3 = MOVE_TICKLE;
			break;
		case 19:	//PCNY Wish Eggs
			species = SPECIES_FARFETCHD;
			move0 = MOVE_YAWN;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 20:
			species = SPECIES_DROWZEE;
			move0 = MOVE_BELLY_DRUM;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 21:
			species = SPECIES_EXEGGCUTE;
			move0 = MOVE_SWEET_SCENT;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 22:
			species = SPECIES_LICKITUNG;
			move0 = MOVE_HEAL_BELL;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 23:
			species = SPECIES_CHANSEY;
			move0 = MOVE_SWEET_SCENT;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 24:
			species = SPECIES_KANGASKHAN;
			move0 = MOVE_YAWN;
			move1 = MOVE_WISH;
			isFRLG = TRUE;
			break;
		case 25:	//Pokémon Box Ruby & Sapphire Eggs
			species = SPECIES_SWABLU;
			move0 = MOVE_PECK;
			move1 = MOVE_GROWL;
			move2 = MOVE_FALSE_SWIPE;
			fatefulEncounter = FALSE;
			break;
		case 26:
			species = SPECIES_ZIGZAGOON;
			move0 = MOVE_TACKLE;
			move1 = MOVE_GROWL;
			move2 = MOVE_TAIL_WHIP;
			move3 = MOVE_EXTREME_SPEED;
			fatefulEncounter = FALSE;
			break;
		case 27:
			species = SPECIES_SKITTY;
			move0 = MOVE_TACKLE;
			move1 = MOVE_GROWL;
			move2 = MOVE_TAIL_WHIP;
			move3 = MOVE_PAY_DAY;
			fatefulEncounter = FALSE;
			break;
		case 28:
			species = SPECIES_PICHU;
			move0 = MOVE_THUNDER_SHOCK;
			move1 = MOVE_CHARM;
			move2 = MOVE_SURF;
			fatefulEncounter = FALSE;
			break;
	}
	
	if (isFRLG)
	{
		if (CheckBagHasItem(ITEM_SAPPHIRE, 1))
			version = VERSION_LEAFGREEN;
		else
			version = VERSION_FIRERED;
	}
	
	if (HasAllMons())
		rolls += SHINY_CHARM_REROLLS;
	if (gPowerType == POWER_LUCKY && gPowerLevel == 3 && gPowerTime > 0)
		rolls *= 2;

	gDisableVBlankRNGAdvance = TRUE;

	do
	{
		if (gSpecialVar_0x8004 < 25)
		{
			personality = Random32();					//ABDE - "Method 2"
			Random();
		}
		else
		{
			personality = Random() << 16 | Random();	//BACD_U - "Reverse Method 1"
		}
		shinyValue = HIHALF(*gSaveBlock2Ptr->playerTrainerId) ^ LOHALF(*gSaveBlock2Ptr->playerTrainerId) ^ HIHALF(personality) ^ LOHALF(personality);
		if (shinyValue < SHINY_ODDS)
			break;
		i++;
	} while (i < rolls);

	gDisableVBlankRNGAdvance = FALSE;

	iv1 = Random();
	iv2 = Random();
	
	CreateMon(&mon, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);
	
	value = iv1 & MAX_IV_MASK;
	SetMonData(&mon, MON_DATA_HP_IV, &value);
	value = (iv1 & (MAX_IV_MASK << 5)) >> 5;
	SetMonData(&mon, MON_DATA_ATK_IV, &value);
	value = (iv1 & (MAX_IV_MASK << 10)) >> 10;
	SetMonData(&mon, MON_DATA_DEF_IV, &value);
	value = iv2 & MAX_IV_MASK;
	SetMonData(&mon, MON_DATA_SPEED_IV, &value);
	value = (iv2 & (MAX_IV_MASK << 5)) >> 5;
	SetMonData(&mon, MON_DATA_SPATK_IV, &value);
	value = (iv2 & (MAX_IV_MASK << 10)) >> 10;
	SetMonData(&mon, MON_DATA_SPDEF_IV, &value);
	
	SetMonData(&mon, MON_DATA_POKEBALL, &ball);
	SetMonData(&mon, MON_DATA_NICKNAME, sJapaneseEggNickname);
	SetMonData(&mon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].eggCycles);
	SetMonData(&mon, MON_DATA_MET_LEVEL, &metLevel);
	SetMonData(&mon, MON_DATA_LANGUAGE, &language);
	SetMonData(&mon, MON_DATA_MET_GAME, &version);
	SetMonData(&mon, MON_DATA_MET_LOCATION, &metLocation);
	SetMonData(&mon, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &fatefulEncounter);
	SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);
	SetMonMoveSlot(&mon, move0, 0);
	SetMonMoveSlot(&mon, move1, 1);
	SetMonMoveSlot(&mon, move2, 2);
	SetMonMoveSlot(&mon, move3, 3);
	
    gSpecialVar_Result = GiveMonToPlayer(&mon);
}
