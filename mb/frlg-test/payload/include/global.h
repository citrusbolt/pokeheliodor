#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"
#include "constants/vars.h"

// IDE support
#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__INTELLISENSE__)
// We define these when using certain IDEs to fool preproc
#define _(x)        (x)
#define __(x)       (x)
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#endif // IDE support

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define RomHeaderGameTitle       ((const char *)0x080000A0)
#define RomHeaderGameCode        ((const char *)0x080000AC)
#define RomHeaderMakerCode       ((const char *)0x080000B0)
#define RomHeaderMagic           ((const u8 *)  0x080000B2)
#define RomHeaderSoftwareVersion ((const u8 *)  0x080000BC)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

enum
{
    VERSION_SAPPHIRE = 1,
    VERSION_RUBY = 2,
    VERSION_EMERALD = 3,
    VERSION_FIRERED = 4,
    VERSION_LEAFGREEN = 5,
};

enum LanguageId
{
    LANGUAGE_JAPANESE = 1,
    LANGUAGE_ENGLISH = 2,
    LANGUAGE_GERMAN = 5,
};

struct Time
{
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct Roamer
{
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool8 active;
    /*0x14*/ u8 filler[0x8];
};

// Dummy Ruby/Sapphire save structs.
// Only vars, localTimeOffset, and lastBerryTreeUpdate are needed.

struct SaveBlock1
{
    u8 dummy_0[0x30D0];
    struct Roamer roamer;
    u16 vars[VARS_COUNT];
    u8 dummy_1[0xC7C];
};
extern struct SaveBlock1 gSaveBlock1;

struct SaveBlock2
{
    u8 playerName[8];
    u8 dummy_0[0xF24];
    struct Time localTimeOffset;
    struct Time lastBerryTreeUpdate;
};
extern struct SaveBlock2 gSaveBlock2;

struct PokemonStorage
{
    u8 dummy[0x83D0];
};
extern struct PokemonStorage gPokemonStorage;

#endif //GUARD_GLOBAL_H
