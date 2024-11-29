#ifndef GUARD_POWER_H
#define GUARD_POWER_H

extern EWRAM_DATA u8 gPowerType;
extern EWRAM_DATA u8 gPowerLevel;
extern EWRAM_DATA u16 gPowerTime;

void GivePower(u8, u8, u8);
void DecrementPowerTime(s32);
void ResetPowerTime(void);
void BuyPower(void);
void GivePowerPoints(void);

#endif