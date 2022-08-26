#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/day_night.h"

#include "constants/wild_encounter.h"

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *landMonsMorningInfo;
    const struct WildPokemonInfo *landMonsNightInfo;
    const struct WildPokemonInfo *landMonsNatInfo;
    const struct WildPokemonInfo *landMonsNatMorningInfo;
    const struct WildPokemonInfo *landMonsNatNightInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *waterMonsMorningInfo;
    const struct WildPokemonInfo *waterMonsNightInfo;
    const struct WildPokemonInfo *waterMonsNatInfo;
    const struct WildPokemonInfo *waterMonsNatMorningInfo;
    const struct WildPokemonInfo *waterMonsNatNightInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsMorningInfo;
    const struct WildPokemonInfo *rockSmashMonsNightInfo;
    const struct WildPokemonInfo *rockSmashMonsNatInfo;
    const struct WildPokemonInfo *rockSmashMonsNatMorningInfo;
    const struct WildPokemonInfo *rockSmashMonsNatNightInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *fishingMonsMorningInfo;
    const struct WildPokemonInfo *fishingMonsNightInfo;
    const struct WildPokemonInfo *fishingMonsNatInfo;
    const struct WildPokemonInfo *fishingMonsNatMorningInfo;
    const struct WildPokemonInfo *fishingMonsNatNightInfo;
    const struct WildPokemonInfo *puddleMonsInfo;
    const struct WildPokemonInfo *puddleMonsMorningInfo;
    const struct WildPokemonInfo *puddleMonsNightInfo;
    const struct WildPokemonInfo *puddleMonsNatInfo;
    const struct WildPokemonInfo *puddleMonsNatMorningInfo;
    const struct WildPokemonInfo *puddleMonsNatNightInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];

extern u8 gChainStreak;
extern u16 gLastEncounteredSpecies;

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);

#endif // GUARD_WILD_ENCOUNTER_H
