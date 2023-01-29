#include "global.h"
#include "overworld.h"
#include "power.h"
#include "constants/power.h"
#include "constants/game_stat.h"
#include "event_data.h"

EWRAM_DATA u8 gPowerType = POWER_NONE;
EWRAM_DATA u8 gPowerLevel = 0;
EWRAM_DATA u8 gPowerTime = 0;

static const u8 sPowerPrices[POWER_NUM_TYPES][4] =
{
	[POWER_HATCH]		= {  0, 1,  2,  3 },
	[POWER_BARGAIN]		= {  0, 1,  2,  3 },
	[POWER_PRIZE]		= {  0, 1,  2,  3 },
	[POWER_EXP]			= {  0, 1,  2,  3 },
	[POWER_CAPTURE]		= {  0, 1,  2,  3 },
	[POWER_ENCOUNTER]	= {  0, 1,  2,  3 },
	[POWER_STEALTH]		= {  0, 1,  2,  3 },
	[POWER_FRIEND]		= {  0, 1,  2,  3 },
	[POWER_ITEM]		= {  0, 1,  2,  3 },
	[POWER_TRAINING]	= {  0, 1,  2,  3 },
	[POWER_LUCKY]		= {  0, 5, 10, 15 },
};

void GivePower(u8 type, u8 level, u8 time)
{
	gPowerType = type;
	gPowerLevel = level;
	gPowerTime = time;
}

void DecrementPowerTime(s32 minutes)
{
	s32 newTime;
	
	newTime = gPowerTime - minutes;
		if (newTime < 0)
		gPowerTime = 0;
	else
		gPowerTime = newTime;
	
}

void ResetPowerTime(void)
{
	gPowerTime = 0;
}

void BuyPower(void)
{
	u8 type = gSpecialVar_0x8004;
	u8 level = gSpecialVar_0x8005;
	u16 time;
	
	if (gSaveBlock2Ptr->powerPoints < sPowerPrices[type][level])
	{
		gSpecialVar_Result = FALSE;
		return;
	}
	
	switch (level)
	{
		case 1:
			time = 10;
			break;
		case 2:
			time = 20;
			break;
		case 3:
			time = 60;
			break;
		default:
			gSpecialVar_Result = FALSE;
			return;
	}
	
	if (gPowerType == type && gPowerTime > 0)
	{
		if (time + gPowerTime > 255)
		{
			gSpecialVar_Result = 2;
			return;
		}
		else
		{
			gPowerTime += time;
		}
		
		if (gPowerLevel < level)
			gPowerLevel = level;
	}
	else
	{
		gPowerType = type;
		gPowerLevel = level;
		gPowerTime = time;
	}
	
	gSaveBlock2Ptr->powerPoints -= sPowerPrices[type][level];
	gSpecialVar_Result = TRUE;
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
	newTotalPoints += GetGameStat(GAME_STAT_BATTLE_TOWER_SINGLES_STREAK);
	newTotalPoints += GetGameStat(GAME_STAT_WON_CONTEST);
	newTotalPoints += GetGameStat(GAME_STAT_RECEIVED_RIBBONS);
	newTotalPoints += GetGameStat(GAME_STAT_WON_POKEMON_LOTTERY) / 5;
	freshPoints = newTotalPoints - gSaveBlock2Ptr->totalEarnedPowerPoints;
	if (gSaveBlock2Ptr->powerPoints + freshPoints > 0xFFFF)
		freshPoints = 0xFFFF - gSaveBlock2Ptr->powerPoints;
	gSaveBlock2Ptr->powerPoints += freshPoints;
	gSaveBlock2Ptr->totalEarnedPowerPoints += freshPoints;
}
