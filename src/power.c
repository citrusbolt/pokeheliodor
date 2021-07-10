#include "global.h"
#include "power.h"

EWRAM_DATA u8 gPowers[POWER_NUM_TYPES][2] = {0};

static const u8 sPowerPrices[POWER_NUM_TYPES][3] =
{
	[POWER_HATCH]		= {  3,  4,  5 },
	[POWER_BARGAIN]		= {  3,  4,  5 },
	[POWER_PRIZE]		= {  2,  3,  4 },
	[POWER_EXP]			= {  2,  3,  4 },
	[POWER_CAPTURE]		= {  4,  5,  6 },
	[POWER_ENCOUNTER]	= {  2,  3,  4 },
	[POWER_STEALTH]		= {  2,  3,  4 },
	[POWER_HP_HEAL]		= {  2,  3,  4 },
	[POWER_PP_HEAL]		= {  2,  3,  4 },
	[POWER_FRIEND]		= {  2,  3,  4 },
	[POWER_LUCKY]		= { 10, 20, 30 },
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
			gPowers[type][POWER_TIME] = 30;
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
