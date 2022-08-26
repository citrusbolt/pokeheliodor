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
    const struct WildPokemonInfo *landMonsRubyInfo;
    const struct WildPokemonInfo *landMonsSapphireInfo;
    const struct WildPokemonInfo *landMonsFireRedInfo;
    const struct WildPokemonInfo *landMonsLeafGreenInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *waterMonsRubyInfo;
    const struct WildPokemonInfo *waterMonsSapphireInfo;
    const struct WildPokemonInfo *waterMonsFireRedInfo;
    const struct WildPokemonInfo *waterMonsLeafGreenInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsRubyInfo;
    const struct WildPokemonInfo *rockSmashMonsSapphireInfo;
    const struct WildPokemonInfo *rockSmashMonsFireRedInfo;
    const struct WildPokemonInfo *rockSmashMonsLeafGreenInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
    const struct WildPokemonInfo *fishingMonsRubyInfo;
    const struct WildPokemonInfo *fishingMonsSapphireInfo;
    const struct WildPokemonInfo *fishingMonsFireRedInfo;
    const struct WildPokemonInfo *fishingMonsLeafGreenInfo;
    const struct WildPokemonInfo *puddleMonsInfo;
    const struct WildPokemonInfo *puddleMonsRubyInfo;
    const struct WildPokemonInfo *puddleMonsSapphireInfo;
    const struct WildPokemonInfo *puddleMonsFireRedInfo;
    const struct WildPokemonInfo *puddleMonsLeafGreenInfo;
};

extern const struct WildPokemonHeader gWildMonHeadersRS[];
extern const struct WildPokemonHeader gWildMonHeadersFRLG[];
extern const struct WildPokemonHeader gWildMonHeadersE[];
extern const struct WildPokemonHeader gWildMonHeaders[];

extern u8 gChainStreak;
extern u16 gLastEncounteredSpecies;
extern u8 gEncounterMode;

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 currMetaTileBehavior, u16 previousMetaTileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);

#endif // GUARD_WILD_ENCOUNTER_H
