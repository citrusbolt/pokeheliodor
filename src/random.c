#include "global.h"
#include "random.h"

EWRAM_DATA static u32 sRandCount = 0;

// IWRAM common
COMMON_DATA u32 gRngValue = 0;
COMMON_DATA u32 gRng2Value = 0;
COMMON_DATA u32 gRngCXDValue = 0;

u16 Random(void)
{
    gRngValue = ISO_RANDOMIZE1(gRngValue);
    sRandCount++;
    return gRngValue >> 16;
}

void SeedRng(u16 seed)
{
    gRngValue = seed;
}

void SeedRng2(u16 seed)
{
    gRng2Value = seed;
}

void SeedRngCXD(u16 seed)
{
    gRngCXDValue = seed;
}

u16 Random2(void)
{
    gRng2Value = ISO_RANDOMIZE1(gRng2Value);
    return gRng2Value >> 16;
}

u16 RandomCXD(void)
{
    gRngCXDValue = ISO_RANDOMIZECXD(gRngCXDValue);
    sRandCount++;
    return gRngCXDValue >> 16;
}
