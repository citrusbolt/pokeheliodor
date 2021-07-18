#ifndef GUARD_POWER_H
#define GUARD_POWER_H

#define POWER_NONE		0
#define POWER_HATCH		1
#define POWER_BARGAIN	2
#define POWER_PRIZE		3
#define POWER_EXP		4
#define POWER_CAPTURE	5
#define POWER_ENCOUNTER	6
#define POWER_STEALTH	7
#define POWER_FRIEND	8
#define POWER_LUCKY		9

#define POWER_NUM_TYPES	(POWER_LUCKY + 1)

extern EWRAM_DATA u8 gPowerType;
extern EWRAM_DATA u8 gPowerLevel;
extern EWRAM_DATA u8 gPowerTime;

void GivePower(u8, u8, u8);
void DecrementPowerTime(s32);
void ResetPowerTime(void);
bool8 BuyPower(u8, u8);
void GivePowerPoints(void);

#endif