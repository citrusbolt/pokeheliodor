#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "constants/maps.h"
#include "pokedex.h"
#include "overworld.h"
#include "constants/game_stat.h"

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 0
#define ROAMER_MAP_GROUP 0

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

#define ROAMER (&gSaveBlock1Ptr->roamer)
EWRAM_DATA static u8 sLocationHistory[3][2] = {0};
EWRAM_DATA static u8 sRoamerLocation[2] = {0};

#define ___ MAP_NUM(UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][6] =
{
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), MAP_NUM(ROUTE134), ___ },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), ___, ___ },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE118), ___, ___ },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), ___, ___, ___ },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), ___, ___, ___ },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), MAP_NUM(ROUTE122), MAP_NUM(ROUTE123), ___, ___ },
    { MAP_NUM(ROUTE122), MAP_NUM(ROUTE121), MAP_NUM(ROUTE123), ___, ___, ___ },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE122), MAP_NUM(ROUTE118), ___, ___, ___ },
    { MAP_NUM(ROUTE124), MAP_NUM(ROUTE121), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), ___, ___ },
    { MAP_NUM(ROUTE125), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE126), MAP_NUM(ROUTE124), MAP_NUM(ROUTE127), ___, ___, ___ },
    { MAP_NUM(ROUTE127), MAP_NUM(ROUTE125), MAP_NUM(ROUTE126), MAP_NUM(ROUTE128), ___, ___ },
    { MAP_NUM(ROUTE128), MAP_NUM(ROUTE127), MAP_NUM(ROUTE129), ___, ___, ___ },
    { MAP_NUM(ROUTE129), MAP_NUM(ROUTE128), MAP_NUM(ROUTE130), ___, ___, ___ },
    { MAP_NUM(ROUTE130), MAP_NUM(ROUTE129), MAP_NUM(ROUTE131), ___, ___, ___ },
    { MAP_NUM(ROUTE131), MAP_NUM(ROUTE130), MAP_NUM(ROUTE132), ___, ___, ___ },
    { MAP_NUM(ROUTE132), MAP_NUM(ROUTE131), MAP_NUM(ROUTE133), ___, ___, ___ },
    { MAP_NUM(ROUTE133), MAP_NUM(ROUTE132), MAP_NUM(ROUTE134), ___, ___, ___ },
    { MAP_NUM(ROUTE134), MAP_NUM(ROUTE133), MAP_NUM(ROUTE110), ___, ___, ___ },
    { ___, ___, ___, ___, ___, ___ },
};

static const u8 sLandRoamerLocations[][6] =
{
    { MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE103), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE102), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE104), 0xFF, 0xFF },
    { MAP_NUM(ROUTE103), MAP_NUM(ROUTE101), MAP_NUM(ROUTE102), MAP_NUM(ROUTE110), 0xFF, 0xFF },
    { MAP_NUM(ROUTE104), MAP_NUM(ROUTE102), MAP_NUM(ROUTE115), MAP_NUM(ROUTE116), 0xFF, 0xFF },
    { MAP_NUM(ROUTE110), MAP_NUM(ROUTE103), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118), 0xFF },
    { MAP_NUM(ROUTE111), MAP_NUM(ROUTE110), MAP_NUM(ROUTE112), MAP_NUM(ROUTE113), MAP_NUM(ROUTE117), MAP_NUM(ROUTE118) },
    { MAP_NUM(ROUTE112), MAP_NUM(ROUTE111), 0xFF, 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE113), MAP_NUM(ROUTE111), MAP_NUM(ROUTE114), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE114), MAP_NUM(ROUTE113), MAP_NUM(ROUTE115), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE115), MAP_NUM(ROUTE104), MAP_NUM(ROUTE114), MAP_NUM(ROUTE116), 0xFF, 0xFF },
    { MAP_NUM(ROUTE116), MAP_NUM(ROUTE104), MAP_NUM(ROUTE115), MAP_NUM(ROUTE117), 0xFF, 0xFF },
    { MAP_NUM(ROUTE117), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE116), MAP_NUM(ROUTE118), 0xFF },
    { MAP_NUM(ROUTE118), MAP_NUM(ROUTE110), MAP_NUM(ROUTE111), MAP_NUM(ROUTE117), MAP_NUM(ROUTE119), MAP_NUM(ROUTE123) },
    { MAP_NUM(ROUTE119), MAP_NUM(ROUTE118), MAP_NUM(ROUTE120), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE120), MAP_NUM(ROUTE119), MAP_NUM(ROUTE121), 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE121), MAP_NUM(ROUTE120), 0xFF, 0xFF, 0xFF, 0xFF },
    { MAP_NUM(ROUTE123), MAP_NUM(ROUTE118), 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
};
#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

void ClearRoamerData(void)
{
    memset(ROAMER, 0, sizeof(*ROAMER));
    ROAMER->species = SPECIES_LATIAS;
}

void ClearRoamerLocationData(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sLocationHistory); i++)
    {
        sLocationHistory[i][MAP_GRP] = 0;
        sLocationHistory[i][MAP_NUM] = 0;
    }

    sRoamerLocation[MAP_GRP] = 0;
    sRoamerLocation[MAP_NUM] = 0;
}

static void CreateInitialRoamerMon(bool16 createRoamer)
{
    switch (createRoamer)
	{
	case 0:
		ROAMER->species = SPECIES_LATIAS;
		break;
    case 1:
		ROAMER->species = SPECIES_LATIOS;
		break;
    case 2:
		ROAMER->species = SPECIES_ARTICUNO;
		break;
    case 3:
		ROAMER->species = SPECIES_MOLTRES;
		break;
    case 4:
		ROAMER->species = SPECIES_RAIKOU;
		break;
    case 5:
		ROAMER->species = SPECIES_ENTEI;
		break;
    case 6:
		ROAMER->species = SPECIES_SUICUNE;
		break;
	case 7:
		switch (Random() % 10)
		{
		case 0:
			ROAMER->species = SPECIES_ARTICUNO;
			break;
		case 1:
			ROAMER->species = SPECIES_ZAPDOS;
			break;
		case 2:
			ROAMER->species = SPECIES_MOLTRES;
			break;
		case 3:
			ROAMER->species = SPECIES_RAIKOU;
			break;
		case 4:
			ROAMER->species = SPECIES_ENTEI;
			break;
		case 5:
			ROAMER->species = SPECIES_SUICUNE;
			break;
		case 6:
			ROAMER->species = SPECIES_LUGIA;
			break;
		case 7:
			ROAMER->species = SPECIES_HO_OH;
			break;
		case 8:
			ROAMER->species = SPECIES_LATIAS;
			break;
		case 9:
			ROAMER->species = SPECIES_LATIOS;
			break;
		}
		break;
	default: //error case
		ROAMER->species = SPECIES_ZIGZAGOON;
		break;
	}

	if (ROAMER->species == SPECIES_LATIAS || ROAMER->species == SPECIES_LATIOS)
	{
		CreateMon(&gEnemyParty[0], ROAMER->species, 40, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
		ROAMER->level = 40;
	}
	else if (ROAMER->species == SPECIES_LUGIA || ROAMER->species == SPECIES_HO_OH)
	{
		CreateMon(&gEnemyParty[0], ROAMER->species, 70, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
		ROAMER->level = 70;
	}
	else
	{
		CreateMon(&gEnemyParty[0], ROAMER->species, 50, 0x20, 0, 0, OT_ID_PLAYER_ID, 0);
		ROAMER->level = 50;
	}
    ROAMER->status = 0;
    ROAMER->active = TRUE;
    ROAMER->ivs = GetMonData(&gEnemyParty[0], MON_DATA_IVS);
    ROAMER->personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);
    ROAMER->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
    ROAMER->cool = GetMonData(&gEnemyParty[0], MON_DATA_COOL);
    ROAMER->beauty = GetMonData(&gEnemyParty[0], MON_DATA_BEAUTY);
    ROAMER->cute = GetMonData(&gEnemyParty[0], MON_DATA_CUTE);
    ROAMER->smart = GetMonData(&gEnemyParty[0], MON_DATA_SMART);
    ROAMER->tough = GetMonData(&gEnemyParty[0], MON_DATA_TOUGH);
    sRoamerLocation[MAP_GRP] = 0;
	if (ROAMER->species == SPECIES_RAIKOU || ROAMER->species == SPECIES_ENTEI || ROAMER->species == SPECIES_SUICUNE)
		sRoamerLocation[MAP_NUM] = sLandRoamerLocations[Random() % (ARRAY_COUNT(sLandRoamerLocations) - 1)][0];
	else
		sRoamerLocation[MAP_NUM] = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
	if (IsMonShiny(&gEnemyParty[0]))
		IncrementGameStat(GAME_STAT_SHINIES_FOUND);
}

// gSpecialVar_0x8004 here corresponds to the options in the multichoice MULTI_TV_LATI (0 for 'Red', 1 for 'Blue')
void InitRoamer(void)
{
    ClearRoamerData();
    ClearRoamerLocationData();
	if (gSpecialVar_0x8004 == 0)
	{
		VarSet(VAR_ROAMER_POKEMON, 1);
		CreateInitialRoamerMon(1);
	}
	else if (gSpecialVar_0x8004 == 1)
	{
		FlagSet(FLAG_ROAMER_QUEST);
		VarSet(VAR_ROAMER_POKEMON, 0);
		CreateInitialRoamerMon(0);
	}
	else if (gSpecialVar_0x8004 == 2)
	{
		CreateInitialRoamerMon(7);
	}
		
}

void UpdateLocationHistoryForRoamer(void)
{
    sLocationHistory[2][MAP_GRP] = sLocationHistory[1][MAP_GRP];
    sLocationHistory[2][MAP_NUM] = sLocationHistory[1][MAP_NUM];

    sLocationHistory[1][MAP_GRP] = sLocationHistory[0][MAP_GRP];
    sLocationHistory[1][MAP_NUM] = sLocationHistory[0][MAP_NUM];

    sLocationHistory[0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
    sLocationHistory[0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
}

void RoamerMoveToOtherLocationSet(void)
{
    u8 mapNum = 0;
    
    if (!ROAMER->active)
        return;

    sRoamerLocation[MAP_GRP] = ROAMER_MAP_GROUP;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    while (1)
    {
		if (ROAMER->species == SPECIES_RAIKOU || ROAMER->species == SPECIES_ENTEI || ROAMER->species == SPECIES_SUICUNE)
			mapNum = sLandRoamerLocations[Random() % (ARRAY_COUNT(sLandRoamerLocations) - 1)][0];
		else
			
			mapNum = sRoamerLocations[Random() % (ARRAY_COUNT(sRoamerLocations) - 1)][0];
        if (sRoamerLocation[MAP_NUM] != mapNum)
        {
            sRoamerLocation[MAP_NUM] = mapNum;
            return;
        }
    }
}

void RoamerMove(void)
{
    u8 locSet = 0;

    if ((Random() % 16) == 0)
    {
        RoamerMoveToOtherLocationSet();
    }
    else
    {
        if (!ROAMER->active)
            return;

		if (ROAMER->species == SPECIES_RAIKOU || ROAMER->species == SPECIES_ENTEI)
		{
			while (locSet < (ARRAY_COUNT(sLandRoamerLocations) - 1))
			{
				if (sRoamerLocation[MAP_NUM] == sLandRoamerLocations[locSet][0])
				{
					u8 mapNum;
					while (1)
					{
						mapNum = sLandRoamerLocations[locSet][(Random() % 5) + 1];
						if (!(sLocationHistory[2][MAP_GRP] == 0 && sLocationHistory[2][MAP_NUM] == mapNum) && mapNum != 0xFF)
							break;
					}
					sRoamerLocation[MAP_NUM] = mapNum;
					return;
				}
				locSet++;
			}
		}
		else
		{
			while (locSet < (ARRAY_COUNT(sRoamerLocations) - 1))
			{
				if (sRoamerLocation[MAP_NUM] == sRoamerLocations[locSet][0])
				{
					u8 mapNum;
					while (1)
					{
						mapNum = sRoamerLocations[locSet][(Random() % 5) + 1];
						if (!(sLocationHistory[2][MAP_GRP] == 0 && sLocationHistory[2][MAP_NUM] == mapNum) && mapNum != 0xFF)
							break;
					}
					sRoamerLocation[MAP_NUM] = mapNum;
					return;
				}
				locSet++;
			}
		}
    }
}

bool8 IsRoamerAt(u8 mapGroup, u8 mapNum)
{
    if (ROAMER->active && mapGroup == sRoamerLocation[MAP_GRP] && mapNum == sRoamerLocation[MAP_NUM])
        return TRUE;
    else
        return FALSE;
}

void CreateRoamerMonInstance(void)
{
    struct Pokemon *mon;
    u32 status;
	bool8 fatefulEncounter = TRUE;

    mon = &gEnemyParty[0];
    ZeroEnemyPartyMons();
	status = ROAMER->status;
    CreateMonWithIVsPersonality(mon, ROAMER->species, ROAMER->level, ROAMER->ivs, ROAMER->personality);
    SetMonData(mon, MON_DATA_STATUS, &status);
    SetMonData(mon, MON_DATA_HP, &ROAMER->hp);
    SetMonData(mon, MON_DATA_COOL, &ROAMER->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &ROAMER->beauty);
    SetMonData(mon, MON_DATA_CUTE, &ROAMER->cute);
    SetMonData(mon, MON_DATA_SMART, &ROAMER->smart);
    SetMonData(mon, MON_DATA_TOUGH, &ROAMER->tough);
	if (ROAMER->species == SPECIES_LUGIA || ROAMER->species == SPECIES_HO_OH)
		SetMonData(mon, MON_DATA_EVENT_LEGAL, &fatefulEncounter);
}

bool8 TryStartRoamerEncounter(void)
{
    if (IsRoamerAt(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum) == TRUE && (Random() % 4) == 0)
    {
        CreateRoamerMonInstance();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    ROAMER->hp = GetMonData(mon, MON_DATA_HP);
    ROAMER->status = GetMonData(mon, MON_DATA_STATUS);
	
	if (ROAMER->hp == 0)
	{
		ROAMER->hp = GetMonData(&gEnemyParty[0], MON_DATA_MAX_HP);
		ROAMER->status = 0;
	}

    RoamerMoveToOtherLocationSet();
}

void SetRoamerInactive(void)
{
	if (VarGet(VAR_ROAMER_POKEMON) == 0)
	{
		FlagSet(FLAG_ROAMER_QUEST);
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 2);
		CreateInitialRoamerMon(2);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 1)
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 3);
		CreateInitialRoamerMon(3);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 2 && FlagGet(FLAG_ROAMER_QUEST))
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 3);
		CreateInitialRoamerMon(3);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 2 && !FlagGet(FLAG_ROAMER_QUEST))
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 4);
		CreateInitialRoamerMon(4);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 3 && FlagGet(FLAG_ROAMER_QUEST))
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 4);
		CreateInitialRoamerMon(4);
	} else if (VarGet(VAR_ROAMER_POKEMON) == 3 && !FlagGet(FLAG_ROAMER_QUEST))
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 2);
		CreateInitialRoamerMon(2);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 4)
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 5);
		CreateInitialRoamerMon(5);
	}
	else if (VarGet(VAR_ROAMER_POKEMON) == 5)
	{
		ClearRoamerData();
		ClearRoamerLocationData();
		VarSet(VAR_ROAMER_POKEMON, 6);
		CreateInitialRoamerMon(6);
	}
	else
	{
		struct Roamer *roamer = &gSaveBlock1Ptr->roamer;
		roamer->active = FALSE;
	}
}

void GetRoamerLocation(u8 *mapGroup, u8 *mapNum)
{
    *mapGroup = sRoamerLocation[MAP_GRP];
    *mapNum = sRoamerLocation[MAP_NUM];
}

u8 ResumeRoamerQuest(void)
{
	if (ROAMER->active == FALSE && VarGet(VAR_ROAMER_POKEMON) < 6 && FlagGet(FLAG_LATIOS_OR_LATIAS_ROAMING))
	{
		SetRoamerInactive();
		if (VarGet(VAR_ROAMER_POKEMON) < 4 || FlagGet(FLAG_DEFEATED_ZAPDOS))
		{
			VarSet(VAR_RESULT, 0);
			return 0;
		}
		else
		{
			VarSet(VAR_RESULT, 1);
			return 1;
		}
	}
	else if (ROAMER->active == FALSE && VarGet(VAR_ROAMER_POKEMON) >= 6)
	{
		if (!FlagGet(FLAG_DEFEATED_ZAPDOS) && !FlagGet(FLAG_COMPLETED_ROAMER_QUEST))
		{
			VarSet(VAR_RESULT, 2);
			return 2;
		}
		else
		{
            FlagSet(FLAG_COMPLETED_ROAMER_QUEST);
			VarSet(VAR_RESULT, 3);
			return 3;
		}
	}
	else
	{
		if (VarGet(VAR_ROAMER_POKEMON) < 4 || FlagGet(FLAG_DEFEATED_ZAPDOS))
		{
			VarSet(VAR_RESULT, 0);
			return 0;
		}
		else
		{
			VarSet(VAR_RESULT, 1);
			return 1;
		}
	}
}
		

u16 CurrentRoamer(void)
{
	VarSet(VAR_RESULT, ROAMER->species);
	return ROAMER->species;
}

void MarkRoamerSeen(void)
{
	HandleSetPokedexFlag(SpeciesToNationalPokedexNum(ROAMER->species), FLAG_SET_SEEN, ROAMER->personality);
}