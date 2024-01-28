#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"
#include "constants/species.h"
#include "power.h"
#include "constants/power.h"
#include "item.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

	if (IsMonShiny(&mon))
		IncrementGameStat(GAME_STAT_SHINIES_FOUND);

    // Don't set Pokédex flag for MON_CANT_GIVE
    switch(sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveUnown(u8 level, u16 item)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;
    u8 version;
    u32 personality;
    struct PIDParameters parameters;
    struct IVs ivs;

    parameters.species = SPECIES_UNOWN;
    parameters.pidIVMethod = PIDIV_METHOD_REVERSE_U;
    parameters.shinyLock = GENERATE_SHINY_NORMAL;
    parameters.shinyRolls = 1;
    parameters.forceNature = FALSE;
    parameters.nature = 0;
    parameters.forceGender = FALSE;
    parameters.gender = 0;
    parameters.forceUnownLetter = TRUE;

    if (gSaveBlock2Ptr->playerName[0] >= 0xBB && gSaveBlock2Ptr->playerName[0] <= 0xD4)
        parameters.unownLetter = gSaveBlock2Ptr->playerName[0] - 0xBB;
    else if (gSaveBlock2Ptr->playerName[0] >= 0xD5 && gSaveBlock2Ptr->playerName[0] <= 0xEE)
        parameters.unownLetter = gSaveBlock2Ptr->playerName[0] - 0xD5;
    else if (gSaveBlock2Ptr->playerName[0] == 0xAB)
        parameters.unownLetter = 26;
    else if (gSaveBlock2Ptr->playerName[0] == 0xAC)
        parameters.unownLetter = 27;
    else
        parameters.unownLetter = Random() % 27;

    if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        parameters.shinyRolls += SHINY_CHARM_REROLLS;
    if (gPowerType == POWER_LUCKY && gPowerLevel == 3 && gPowerTime > 0)
        parameters.shinyRolls *= 2;

    if (Random() % 2)
        version = VERSION_FIRERED;
    else
        version = VERSION_LEAFGREEN;

    personality = GeneratePIDMaster(parameters, &ivs);

    CreateMon(&mon, SPECIES_UNOWN, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
    SetMonData(&mon, MON_DATA_HP_IV, &ivs.hp);
    SetMonData(&mon, MON_DATA_ATK_IV, &ivs.atk);
    SetMonData(&mon, MON_DATA_DEF_IV, &ivs.def);
    SetMonData(&mon, MON_DATA_SPEED_IV, &ivs.speed);
    SetMonData(&mon, MON_DATA_SPATK_IV, &ivs.spAtk);
    SetMonData(&mon, MON_DATA_SPDEF_IV, &ivs.spDef);
    SetMonData(&mon, MON_DATA_MET_GAME, &version);

    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(SPECIES_UNOWN);
    personality = GetMonData(&mon, MON_DATA_PERSONALITY);

    if (IsMonShiny(&mon))
        IncrementGameStat(GAME_STAT_SHINIES_FOUND);

    switch(sentToPc)
    {
        case 0:
        case 1:
            GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
            HandleSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT, personality);
            GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
            break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];
    u32 personality;
    struct PIDParameters parameters;
    struct IVs ivs;

    parameters.species = species;
    parameters.pidIVMethod = PIDIV_METHOD_1;
    parameters.shinyLock = GENERATE_SHINY_NORMAL;
    parameters.shinyRolls = 1;
    parameters.forceNature = FALSE;
    parameters.nature = 0;
    parameters.forceGender = FALSE;
    parameters.gender = 0;
    parameters.forceUnownLetter = FALSE;
    parameters.unownLetter = 0;

    if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        parameters.shinyRolls += SHINY_CHARM_REROLLS;
    if (gPowerType == POWER_LUCKY && gPowerLevel == 3 && gPowerTime > 0)
        parameters.shinyRolls *= 2;
    
    personality = GeneratePIDMaster(parameters, &ivs);
    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);

    SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs.hp);
    SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs.atk);
    SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs.def);
    SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs.speed);
    SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs.spAtk);
    SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs.spDef);

    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }

	if (IsMonShiny(&gEnemyParty[0]))
		IncrementGameStat(GAME_STAT_SHINIES_FOUND);
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex >= PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected Pokémon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}

void GiveStarterEgg(void)
{
	switch (Random() % 9)
	{
		case 0:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_BULBASAUR);
			break;
		case 1:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_CHARMANDER);
			break;
		case 2:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_SQUIRTLE);
			break;
		case 3:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_CHIKORITA);
			break;
		case 4:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_CYNDAQUIL);
			break;
		case 5:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_TOTODILE);
			break;
		case 6:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_TREECKO);
			break;
		case 7:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_TORCHIC);
			break;
		case 8:
			gSpecialVar_Result = ScriptGiveEgg(SPECIES_MUDKIP);
			break;
	}
}
