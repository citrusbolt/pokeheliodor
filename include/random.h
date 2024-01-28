#ifndef GUARD_RANDOM_H
#define GUARD_RANDOM_H

extern u32 gRngValue;
extern u32 gRng2Value;
extern u32 gRngCXDValue;

//Returns a 16-bit pseudorandom number
u16 Random(void);
u16 Random2(void);
u16 RandomCXD(void);

//Returns a 32-bit pseudorandom number
#define Random32() (Random() | (Random() << 16))

// The number 1103515245 comes from the example implementation of rand and srand
// in the ISO C standard.
#define ISO_RANDOMIZE1(val)(1103515245 * (val) + 24691)
#define ISO_RANDOMIZE2(val)(1103515245 * (val) + 12345)
#define ISO_RANDOMIZECXD(val)(214013 * (val) + 2531011)

//Sets the initial seed value of the pseudorandom number generator
void SeedRng(u16 seed);
void SeedRng2(u16 seed);
void SeedRngCXD(u16 seed);

#endif // GUARD_RANDOM_H
