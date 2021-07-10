#ifndef GUARD_POWER_H
#define GUARD_POWER_H

#define POWER_HATCH		0
#define POWER_BARGAIN	1
#define POWER_PRIZE		2
#define POWER_EXP		3
#define POWER_CAPTURE	4
#define POWER_ENCOUNTER	5
#define POWER_STEALTH	6
#define POWER_FRIEND	7
#define POWER_LUCKY		8

#define POWER_NUM_TYPES (POWER_LUCKY + 1)

#define POWER_LEVEL		0
#define POWER_TIME		1

#define POWER_LUCKY_REROLLS	2

extern EWRAM_DATA u8 gPowers[POWER_NUM_TYPES][2];	// Level by Time Remaining

void TestPowers(void);
void DecrementPowerTime(s32);
void ResetPowerTime(void);
bool8 BuyPower(u8, u8);
void GivePowerPoints(void);

#endif