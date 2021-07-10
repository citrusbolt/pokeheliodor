#include "global.h"
#include "overworld.h"
#include "power.h"
#include "constants/game_stat.h"
#include "mgba.h"

EWRAM_DATA u8 gPowers[POWER_NUM_TYPES][2] = {0};

static const u8 sPowerPrices[POWER_NUM_TYPES][3] =
{
	[POWER_HATCH]		= {  1,  2,  3 },
	[POWER_BARGAIN]		= {  1,  2,  3 },
	[POWER_PRIZE]		= {  1,  2,  3 },
	[POWER_EXP]			= {  1,  2,  3 },
	[POWER_CAPTURE]		= {  1,  2,  3 },
	[POWER_ENCOUNTER]	= {  1,  2,  3 },
	[POWER_STEALTH]		= {  1,  2,  3 },
	[POWER_FRIEND]		= {  1,  2,  3 },
	[POWER_LUCKY]		= {  5, 10, 15 },
};

void TestPowers(void)
{
	u8 i;
	
	for (i = 0; i < POWER_NUM_TYPES; i++)
	{
		gPowers[i][POWER_LEVEL] = 2;
		gPowers[i][POWER_TIME] = 2;
	}
}

void DecrementPowerTime(s32 minutes)
{
	u8 i;
	s32 newTime;
	
	for (i = 0; i < POWER_NUM_TYPES; i++)
	{
		newTime = gPowers[i][POWER_TIME] - minutes;
			if (newTime < 0)
			gPowers[i][POWER_TIME] = 0;
		else
			gPowers[i][POWER_TIME] = newTime;
	}
}

void ResetPowerTime(void)
{
	u8 i;
	
	for (i = 0; i < POWER_NUM_TYPES; i++)
		gPowers[i][POWER_TIME] = 0;
}

bool8 BuyPower(u8 type, u8 level)
{
	if (gSaveBlock2Ptr->powerPoints < sPowerPrices[type][level])
		return FALSE;
	
	switch (level)
	{
		case 1:
			gPowers[type][POWER_TIME] = 10;
			break;
		case 2:
			gPowers[type][POWER_TIME] = 20;
			break;
		case 3:
			gPowers[type][POWER_TIME] = 60;
			break;
		default:
			return FALSE;
	}
	
	gSaveBlock2Ptr->powerPoints -= sPowerPrices[type][level];
	gPowers[type][POWER_LEVEL] = level;
	return TRUE;
}

void GivePowerPoints(void)
{
	u32 newTotalPoints = 0;
	u32 freshPoints;
	
	newTotalPoints += GetGameStat(GAME_STAT_PLANTED_BERRIES) / 10;
	newTotalPoints += GetGameStat(GAME_STAT_TRAINER_BATTLES) / 5;
	newTotalPoints += GetGameStat(GAME_STAT_ENTERED_HOF) * 5;
	newTotalPoints += GetGameStat(GAME_STAT_POKEMON_CAPTURES) / 10;
	newTotalPoints += GetGameStat(GAME_STAT_HATCHED_EGGS);
	newTotalPoints += GetGameStat(GAME_STAT_EVOLVED_POKEMON);
	newTotalPoints += GetGameStat(GAME_STAT_SLOT_JACKPOTS) * 30;
	newTotalPoints += GetGameStat(GAME_STAT_BATTLE_TOWER_BEST_STREAK);
	newTotalPoints += GetGameStat(GAME_STAT_WON_CONTEST);
	newTotalPoints += GetGameStat(GAME_STAT_RECEIVED_RIBBONS);
	newTotalPoints += GetGameStat(GAME_STAT_WON_POKEMON_LOTTERY) / 5;
	freshPoints = newTotalPoints - gSaveBlock2Ptr->totalEarnedPowerPoints;
	if (gSaveBlock2Ptr->powerPoints + freshPoints > 0xFFFF)
		freshPoints = 0xFFFF - gSaveBlock2Ptr->powerPoints;
	gSaveBlock2Ptr->powerPoints += freshPoints;
	gSaveBlock2Ptr->totalEarnedPowerPoints += freshPoints;
	
	mgba_printf(MGBA_LOG_INFO, "%d", freshPoints);
}
