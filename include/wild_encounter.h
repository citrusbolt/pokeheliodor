#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/day_night.h"

#include "constants/wild_encounter.h"

struct WildPokemon
{
    u32 minLevel;
    u32 maxLevel;
    u32 species;
    u32 originGame;
    u32 encounterRate;
};

struct WildPokemonInfo
{
    u32 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u32 mapGroup;
    u32 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *puddleMonsInfo;
};

extern const struct WildPokemonHeader gWildMonHeadersRS[];
extern const struct WildPokemonHeader gWildMonHeadersFRLG[];
extern const struct WildPokemonHeader gWildMonHeadersE[];
extern const struct WildPokemonHeader gWildMonHeaders[];

extern u32 gChainStreak;
extern u32 gLastEncounteredSpecies;
extern u32 gEncounterMode;

void DisableWildEncounters(bool32 disabled);
bool32 StandardWildEncounter(u32 currMetaTileBehavior, u32 previousMetaTileBehavior);
bool32 SweetScentWildEncounter(void);
bool32 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u32 rod);
u32 GetLocalWildMon(bool32 *isWaterMon);
u32 GetLocalWaterMon(void);
bool32 UpdateRepelCounter(void);

#endif // GUARD_WILD_ENCOUNTER_H
