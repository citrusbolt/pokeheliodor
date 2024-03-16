//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/wild_encounters_rs.json and Inja template src/data/wild_encounters_rs.json.txt
//


#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 20 
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 + 20
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 + 10
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 + 5
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 + 4
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_SLOT_11 ENCOUNTER_CHANCE_LAND_MONS_SLOT_10 + 1
#define ENCOUNTER_CHANCE_LAND_MONS_TOTAL (ENCOUNTER_CHANCE_LAND_MONS_SLOT_11)
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 60 
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_WATER_MONS_SLOT_4 ENCOUNTER_CHANCE_WATER_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_WATER_MONS_TOTAL (ENCOUNTER_CHANCE_WATER_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 60 
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_0 + 30
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_1 + 5
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_2 + 4
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4 ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_3 + 1
#define ENCOUNTER_CHANCE_ROCK_SMASH_MONS_TOTAL (ENCOUNTER_CHANCE_ROCK_SMASH_MONS_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 60 
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4 ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 + 20
#define ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 70 
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1 ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0 + 30
#define ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_1)
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 40 
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 + 40
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 + 15
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 + 4
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9 ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 + 1
#define ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL (ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)



const struct WildPokemon PetalburgCity_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
};

const struct WildPokemonInfo PetalburgCity_RubyRS_WaterMonsInfo = { 1, PetalburgCity_RubyRS_WaterMons };
const struct WildPokemon PetalburgCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo PetalburgCity_RubyRS_FishingMonsInfo = { 10, PetalburgCity_RubyRS_FishingMons };

const struct WildPokemon SlateportCity_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo SlateportCity_RubyRS_WaterMonsInfo = { 4, SlateportCity_RubyRS_WaterMons };
const struct WildPokemon SlateportCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SlateportCity_RubyRS_FishingMonsInfo = { 10, SlateportCity_RubyRS_FishingMons };

const struct WildPokemon LilycoveCity_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo LilycoveCity_RubyRS_WaterMonsInfo = { 4, LilycoveCity_RubyRS_WaterMons };
const struct WildPokemon LilycoveCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_STARYU },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo LilycoveCity_RubyRS_FishingMonsInfo = { 10, LilycoveCity_RubyRS_FishingMons };

const struct WildPokemon MossdeepCity_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo MossdeepCity_RubyRS_WaterMonsInfo = { 4, MossdeepCity_RubyRS_WaterMons };
const struct WildPokemon MossdeepCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo MossdeepCity_RubyRS_FishingMonsInfo = { 10, MossdeepCity_RubyRS_FishingMons };

const struct WildPokemon SootopolisCity_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo SootopolisCity_RubyRS_WaterMonsInfo = { 1, SootopolisCity_RubyRS_WaterMons };
const struct WildPokemon SootopolisCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 10, 15, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_GYARADOS },
    { 35, 45, SPECIES_GYARADOS },
    { 5, 45, SPECIES_GYARADOS },
};

const struct WildPokemonInfo SootopolisCity_RubyRS_FishingMonsInfo = { 10, SootopolisCity_RubyRS_FishingMons };

const struct WildPokemon EverGrandeCity_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo EverGrandeCity_RubyRS_WaterMonsInfo = { 4, EverGrandeCity_RubyRS_WaterMons };
const struct WildPokemon EverGrandeCity_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo EverGrandeCity_RubyRS_FishingMonsInfo = { 10, EverGrandeCity_RubyRS_FishingMons };

const struct WildPokemon MeteorFalls_1F_1R_RubyRS_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_ZUBAT },
    { 18, 18, SPECIES_ZUBAT },
    { 15, 15, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 16, 16, SPECIES_SOLROCK },
    { 18, 18, SPECIES_SOLROCK },
    { 14, 14, SPECIES_SOLROCK },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_RubyRS_LandMonsInfo = { 10, MeteorFalls_1F_1R_RubyRS_LandMons };
const struct WildPokemon MeteorFalls_1F_1R_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_RubyRS_WaterMonsInfo = { 4, MeteorFalls_1F_1R_RubyRS_WaterMons };
const struct WildPokemon MeteorFalls_1F_1R_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_RubyRS_FishingMonsInfo = { 30, MeteorFalls_1F_1R_RubyRS_FishingMons };

const struct WildPokemon MeteorFalls_1F_2R_RubyRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_SOLROCK },
    { 33, 33, SPECIES_SOLROCK },
    { 37, 37, SPECIES_SOLROCK },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_RubyRS_LandMonsInfo = { 10, MeteorFalls_1F_2R_RubyRS_LandMons };
const struct WildPokemon MeteorFalls_1F_2R_RubyRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_RubyRS_WaterMonsInfo = { 4, MeteorFalls_1F_2R_RubyRS_WaterMons };
const struct WildPokemon MeteorFalls_1F_2R_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_RubyRS_FishingMonsInfo = { 30, MeteorFalls_1F_2R_RubyRS_FishingMons };

const struct WildPokemon MeteorFalls_B1F_1R_RubyRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_SOLROCK },
    { 33, 33, SPECIES_SOLROCK },
    { 37, 37, SPECIES_SOLROCK },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_RubyRS_LandMonsInfo = { 10, MeteorFalls_B1F_1R_RubyRS_LandMons };
const struct WildPokemon MeteorFalls_B1F_1R_RubyRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_RubyRS_WaterMonsInfo = { 4, MeteorFalls_B1F_1R_RubyRS_WaterMons };
const struct WildPokemon MeteorFalls_B1F_1R_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_RubyRS_FishingMonsInfo = { 30, MeteorFalls_B1F_1R_RubyRS_FishingMons };

const struct WildPokemon MeteorFalls_B1F_2R_RubyRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 30, 30, SPECIES_BAGON },
    { 35, 35, SPECIES_SOLROCK },
    { 35, 35, SPECIES_BAGON },
    { 37, 37, SPECIES_SOLROCK },
    { 25, 25, SPECIES_BAGON },
    { 39, 39, SPECIES_SOLROCK },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_RubyRS_LandMonsInfo = { 10, MeteorFalls_B1F_2R_RubyRS_LandMons };
const struct WildPokemon MeteorFalls_B1F_2R_RubyRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_RubyRS_WaterMonsInfo = { 4, MeteorFalls_B1F_2R_RubyRS_WaterMons };
const struct WildPokemon MeteorFalls_B1F_2R_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_RubyRS_FishingMonsInfo = { 30, MeteorFalls_B1F_2R_RubyRS_FishingMons };

const struct WildPokemon RusturfTunnel_RubyRS_LandMons[] =
{
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
};

const struct WildPokemonInfo RusturfTunnel_RubyRS_LandMonsInfo = { 10, RusturfTunnel_RubyRS_LandMons };

const struct WildPokemon GraniteCave_1F_RubyRS_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_GEODUDE },
    { 8, 8, SPECIES_GEODUDE },
    { 6, 6, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
};

const struct WildPokemonInfo GraniteCave_1F_RubyRS_LandMonsInfo = { 10, GraniteCave_1F_RubyRS_LandMons };

const struct WildPokemon GraniteCave_B1F_RubyRS_LandMons[] =
{
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ARON },
    { 9, 9, SPECIES_ARON },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ZUBAT },
    { 9, 9, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 11, 11, SPECIES_MAKUHITA },
    { 10, 10, SPECIES_MAWILE },
    { 10, 10, SPECIES_MAWILE },
    { 9, 9, SPECIES_MAWILE },
    { 11, 11, SPECIES_MAWILE },
};

const struct WildPokemonInfo GraniteCave_B1F_RubyRS_LandMonsInfo = { 10, GraniteCave_B1F_RubyRS_LandMons };

const struct WildPokemon GraniteCave_B2F_RubyRS_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ARON },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ARON },
    { 10, 10, SPECIES_ABRA },
    { 10, 10, SPECIES_MAWILE },
    { 11, 11, SPECIES_MAWILE },
    { 12, 12, SPECIES_MAWILE },
    { 10, 10, SPECIES_MAWILE },
    { 12, 12, SPECIES_MAWILE },
    { 10, 10, SPECIES_MAWILE },
};

const struct WildPokemonInfo GraniteCave_B2F_RubyRS_LandMonsInfo = { 10, GraniteCave_B2F_RubyRS_LandMons };
const struct WildPokemon GraniteCave_B2F_RubyRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 10, 20, SPECIES_NOSEPASS },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo GraniteCave_B2F_RubyRS_RockSmashMonsInfo = { 20, GraniteCave_B2F_RubyRS_RockSmashMons };

const struct WildPokemon GraniteCave_StevensRoom_RubyRS_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
};

const struct WildPokemonInfo GraniteCave_StevensRoom_RubyRS_LandMonsInfo = { 10, GraniteCave_StevensRoom_RubyRS_LandMons };

const struct WildPokemon PetalburgWoods_RubyRS_LandMons[] =
{
    { 5, 5, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_WURMPLE },
    { 5, 5, SPECIES_SHROOMISH },
    { 6, 6, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_SILCOON },
    { 5, 5, SPECIES_CASCOON },
    { 6, 6, SPECIES_WURMPLE },
    { 6, 6, SPECIES_SHROOMISH },
    { 5, 5, SPECIES_TAILLOW },
    { 5, 5, SPECIES_SLAKOTH },
    { 6, 6, SPECIES_TAILLOW },
    { 6, 6, SPECIES_SLAKOTH },
};

const struct WildPokemonInfo PetalburgWoods_RubyRS_LandMonsInfo = { 20, PetalburgWoods_RubyRS_LandMons };

const struct WildPokemon JaggedPass_RubyRS_LandMons[] =
{
    { 19, 19, SPECIES_NUMEL },
    { 19, 19, SPECIES_NUMEL },
    { 19, 19, SPECIES_MACHOP },
    { 18, 18, SPECIES_NUMEL },
    { 18, 18, SPECIES_SPOINK },
    { 18, 18, SPECIES_MACHOP },
    { 19, 19, SPECIES_SPOINK },
    { 20, 20, SPECIES_MACHOP },
    { 20, 20, SPECIES_NUMEL },
    { 20, 20, SPECIES_SPOINK },
    { 20, 20, SPECIES_NUMEL },
    { 20, 20, SPECIES_SPOINK },
};

const struct WildPokemonInfo JaggedPass_RubyRS_LandMonsInfo = { 20, JaggedPass_RubyRS_LandMons };

const struct WildPokemon FieryPath_RubyRS_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_KOFFING },
    { 16, 16, SPECIES_NUMEL },
    { 15, 15, SPECIES_MACHOP },
    { 15, 15, SPECIES_TORKOAL },
    { 15, 15, SPECIES_SLUGMA },
    { 16, 16, SPECIES_KOFFING },
    { 16, 16, SPECIES_MACHOP },
    { 14, 14, SPECIES_TORKOAL },
    { 16, 16, SPECIES_TORKOAL },
    { 14, 14, SPECIES_GRIMER },
    { 14, 14, SPECIES_GRIMER },
};

const struct WildPokemonInfo FieryPath_RubyRS_LandMonsInfo = { 10, FieryPath_RubyRS_LandMons };

const struct WildPokemon MtPyre_1F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_1F_RubyRS_LandMonsInfo = { 10, MtPyre_1F_RubyRS_LandMons };

const struct WildPokemon MtPyre_2F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_2F_RubyRS_LandMonsInfo = { 10, MtPyre_2F_RubyRS_LandMons };

const struct WildPokemon MtPyre_3F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_3F_RubyRS_LandMonsInfo = { 10, MtPyre_3F_RubyRS_LandMons };

const struct WildPokemon MtPyre_4F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_4F_RubyRS_LandMonsInfo = { 10, MtPyre_4F_RubyRS_LandMons };

const struct WildPokemon MtPyre_5F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_5F_RubyRS_LandMonsInfo = { 10, MtPyre_5F_RubyRS_LandMons };

const struct WildPokemon MtPyre_6F_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 23, 23, SPECIES_DUSKULL },
    { 22, 22, SPECIES_DUSKULL },
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_6F_RubyRS_LandMonsInfo = { 10, MtPyre_6F_RubyRS_LandMons };

const struct WildPokemon MtPyre_Exterior_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_MEDITITE },
    { 28, 28, SPECIES_DUSKULL },
    { 29, 29, SPECIES_MEDITITE },
    { 29, 29, SPECIES_DUSKULL },
    { 27, 27, SPECIES_VULPIX },
    { 29, 29, SPECIES_VULPIX },
    { 25, 25, SPECIES_VULPIX },
    { 27, 27, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
};

const struct WildPokemonInfo MtPyre_Exterior_RubyRS_LandMonsInfo = { 10, MtPyre_Exterior_RubyRS_LandMons };

const struct WildPokemon MtPyre_Summit_RubyRS_LandMons[] =
{
    { 28, 28, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 30, 30, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 24, 24, SPECIES_DUSKULL },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 30, 30, SPECIES_SHUPPET },
    { 28, 28, SPECIES_CHIMECHO },
    { 28, 28, SPECIES_CHIMECHO },
};

const struct WildPokemonInfo MtPyre_Summit_RubyRS_LandMonsInfo = { 10, MtPyre_Summit_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Entrance_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Entrance_RubyRS_WaterMonsInfo = { 4, SeafloorCavern_Entrance_RubyRS_WaterMons };
const struct WildPokemon SeafloorCavern_Entrance_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Entrance_RubyRS_FishingMonsInfo = { 10, SeafloorCavern_Entrance_RubyRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room1_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room1_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room1_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Room2_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room2_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room2_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Room3_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room3_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room3_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Room4_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room4_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room4_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Room5_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room5_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room5_RubyRS_LandMons };

const struct WildPokemon SeafloorCavern_Room6_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room6_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room6_RubyRS_LandMons };
const struct WildPokemon SeafloorCavern_Room6_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room6_RubyRS_WaterMonsInfo = { 4, SeafloorCavern_Room6_RubyRS_WaterMons };
const struct WildPokemon SeafloorCavern_Room6_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Room6_RubyRS_FishingMonsInfo = { 10, SeafloorCavern_Room6_RubyRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room7_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room7_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room7_RubyRS_LandMons };
const struct WildPokemon SeafloorCavern_Room7_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room7_RubyRS_WaterMonsInfo = { 4, SeafloorCavern_Room7_RubyRS_WaterMons };
const struct WildPokemon SeafloorCavern_Room7_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Room7_RubyRS_FishingMonsInfo = { 10, SeafloorCavern_Room7_RubyRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room8_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room8_RubyRS_LandMonsInfo = { 4, SeafloorCavern_Room8_RubyRS_LandMons };

const struct WildPokemon CaveOfOrigin_Entrance_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_Entrance_RubyRS_LandMonsInfo = { 4, CaveOfOrigin_Entrance_RubyRS_LandMons };

const struct WildPokemon CaveOfOrigin_1F_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_MAWILE },
    { 32, 32, SPECIES_MAWILE },
    { 34, 34, SPECIES_MAWILE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_1F_RubyRS_LandMonsInfo = { 4, CaveOfOrigin_1F_RubyRS_LandMons };

const struct WildPokemon CaveOfOrigin_B1F_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_MAWILE },
    { 32, 32, SPECIES_MAWILE },
    { 34, 34, SPECIES_MAWILE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B1F_RubyRS_LandMonsInfo = { 4, CaveOfOrigin_B1F_RubyRS_LandMons };

const struct WildPokemon CaveOfOrigin_B2F_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_MAWILE },
    { 32, 32, SPECIES_MAWILE },
    { 34, 34, SPECIES_MAWILE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B2F_RubyRS_LandMonsInfo = { 4, CaveOfOrigin_B2F_RubyRS_LandMons };

const struct WildPokemon CaveOfOrigin_B3F_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_MAWILE },
    { 32, 32, SPECIES_MAWILE },
    { 34, 34, SPECIES_MAWILE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B3F_RubyRS_LandMonsInfo = { 4, CaveOfOrigin_B3F_RubyRS_LandMons };

const struct WildPokemon VictoryRoad_1F_RubyRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LOUDRED },
    { 36, 36, SPECIES_ZUBAT },
    { 36, 36, SPECIES_MAKUHITA },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
};

const struct WildPokemonInfo VictoryRoad_1F_RubyRS_LandMonsInfo = { 10, VictoryRoad_1F_RubyRS_LandMons };

const struct WildPokemon VictoryRoad_B1F_RubyRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_MEDICHAM },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MEDITITE },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MEDITITE },
};

const struct WildPokemonInfo VictoryRoad_B1F_RubyRS_LandMonsInfo = { 10, VictoryRoad_B1F_RubyRS_LandMons };
const struct WildPokemon VictoryRoad_B1F_RubyRS_RockSmashMons[] =
{
    { 30, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo VictoryRoad_B1F_RubyRS_RockSmashMonsInfo = { 20, VictoryRoad_B1F_RubyRS_RockSmashMons };

const struct WildPokemon VictoryRoad_B2F_RubyRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_MAWILE },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_MEDICHAM },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_MAWILE },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_MAWILE },
    { 42, 42, SPECIES_LAIRON },
    { 42, 42, SPECIES_MEDICHAM },
    { 44, 44, SPECIES_LAIRON },
    { 44, 44, SPECIES_MEDICHAM },
};

const struct WildPokemonInfo VictoryRoad_B2F_RubyRS_LandMonsInfo = { 10, VictoryRoad_B2F_RubyRS_LandMons };
const struct WildPokemon VictoryRoad_B2F_RubyRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 25, 30, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo VictoryRoad_B2F_RubyRS_WaterMonsInfo = { 4, VictoryRoad_B2F_RubyRS_WaterMons };
const struct WildPokemon VictoryRoad_B2F_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo VictoryRoad_B2F_RubyRS_FishingMonsInfo = { 30, VictoryRoad_B2F_RubyRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideEntranceRoom_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_RubyRS_LandMonsInfo = { 10, ShoalCave_LowTideEntranceRoom_RubyRS_LandMons };
const struct WildPokemon ShoalCave_LowTideEntranceRoom_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_RubyRS_WaterMonsInfo = { 4, ShoalCave_LowTideEntranceRoom_RubyRS_WaterMons };
const struct WildPokemon ShoalCave_LowTideEntranceRoom_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_RubyRS_FishingMonsInfo = { 10, ShoalCave_LowTideEntranceRoom_RubyRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideInnerRoom_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_RubyRS_LandMonsInfo = { 10, ShoalCave_LowTideInnerRoom_RubyRS_LandMons };
const struct WildPokemon ShoalCave_LowTideInnerRoom_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_RubyRS_WaterMonsInfo = { 4, ShoalCave_LowTideInnerRoom_RubyRS_WaterMons };
const struct WildPokemon ShoalCave_LowTideInnerRoom_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_RubyRS_FishingMonsInfo = { 10, ShoalCave_LowTideInnerRoom_RubyRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideStairsRoom_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideStairsRoom_RubyRS_LandMonsInfo = { 10, ShoalCave_LowTideStairsRoom_RubyRS_LandMons };

const struct WildPokemon ShoalCave_LowTideLowerRoom_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideLowerRoom_RubyRS_LandMonsInfo = { 10, ShoalCave_LowTideLowerRoom_RubyRS_LandMons };

const struct WildPokemon ShoalCave_LowTideIceRoom_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 26, 26, SPECIES_SNORUNT },
    { 32, 32, SPECIES_SPHEAL },
    { 30, 30, SPECIES_GOLBAT },
    { 28, 28, SPECIES_SNORUNT },
    { 32, 32, SPECIES_GOLBAT },
    { 30, 30, SPECIES_SNORUNT },
};

const struct WildPokemonInfo ShoalCave_LowTideIceRoom_RubyRS_LandMonsInfo = { 10, ShoalCave_LowTideIceRoom_RubyRS_LandMons };

const struct WildPokemon NewMauville_Entrance_RubyRS_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
};

const struct WildPokemonInfo NewMauville_Entrance_RubyRS_LandMonsInfo = { 10, NewMauville_Entrance_RubyRS_LandMons };

const struct WildPokemon NewMauville_Inside_RubyRS_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_ELECTRODE },
    { 26, 26, SPECIES_MAGNETON },
};

const struct WildPokemonInfo NewMauville_Inside_RubyRS_LandMonsInfo = { 10, NewMauville_Inside_RubyRS_LandMons };

const struct WildPokemon AbandonedShip_Rooms_B1F_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_Rooms_B1F_RubyRS_WaterMonsInfo = { 4, AbandonedShip_Rooms_B1F_RubyRS_WaterMons };
const struct WildPokemon AbandonedShip_Rooms_B1F_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_Rooms_B1F_RubyRS_FishingMonsInfo = { 20, AbandonedShip_Rooms_B1F_RubyRS_FishingMons };

const struct WildPokemon AbandonedShip_HiddenFloorCorridors_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_HiddenFloorCorridors_RubyRS_WaterMonsInfo = { 4, AbandonedShip_HiddenFloorCorridors_RubyRS_WaterMons };
const struct WildPokemon AbandonedShip_HiddenFloorCorridors_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_HiddenFloorCorridors_RubyRS_FishingMonsInfo = { 20, AbandonedShip_HiddenFloorCorridors_RubyRS_FishingMons };

const struct WildPokemon SkyPillar_1F_RubyRS_LandMons[] =
{
    { 48, 48, SPECIES_MAWILE },
    { 48, 48, SPECIES_GOLBAT },
    { 50, 50, SPECIES_GOLBAT },
    { 50, 50, SPECIES_MAWILE },
    { 48, 48, SPECIES_CLAYDOL },
    { 48, 48, SPECIES_DUSCLOPS },
    { 50, 50, SPECIES_DUSCLOPS },
    { 49, 49, SPECIES_CLAYDOL },
    { 47, 47, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 47, 47, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo SkyPillar_1F_RubyRS_LandMonsInfo = { 10, SkyPillar_1F_RubyRS_LandMons };

const struct WildPokemon SkyPillar_3F_RubyRS_LandMons[] =
{
    { 51, 51, SPECIES_MAWILE },
    { 51, 51, SPECIES_GOLBAT },
    { 53, 53, SPECIES_GOLBAT },
    { 53, 53, SPECIES_MAWILE },
    { 51, 51, SPECIES_CLAYDOL },
    { 51, 51, SPECIES_DUSCLOPS },
    { 53, 53, SPECIES_DUSCLOPS },
    { 52, 52, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 53, 53, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 53, 53, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo SkyPillar_3F_RubyRS_LandMonsInfo = { 10, SkyPillar_3F_RubyRS_LandMons };

const struct WildPokemon SkyPillar_5F_RubyRS_LandMons[] =
{
    { 54, 54, SPECIES_MAWILE },
    { 54, 54, SPECIES_GOLBAT },
    { 56, 56, SPECIES_GOLBAT },
    { 56, 56, SPECIES_MAWILE },
    { 54, 54, SPECIES_CLAYDOL },
    { 54, 54, SPECIES_DUSCLOPS },
    { 56, 56, SPECIES_DUSCLOPS },
    { 55, 55, SPECIES_CLAYDOL },
    { 56, 56, SPECIES_CLAYDOL },
    { 57, 57, SPECIES_ALTARIA },
    { 54, 54, SPECIES_ALTARIA },
    { 60, 60, SPECIES_ALTARIA },
};

const struct WildPokemonInfo SkyPillar_5F_RubyRS_LandMonsInfo = { 10, SkyPillar_5F_RubyRS_LandMons };

const struct WildPokemon Route101_RubyRS_LandMons[] =
{
    { 2, 2, SPECIES_WURMPLE },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_WURMPLE },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
};

const struct WildPokemonInfo Route101_RubyRS_LandMonsInfo = { 20, Route101_RubyRS_LandMons };

const struct WildPokemon Route102_RubyRS_LandMons[] =
{
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WURMPLE },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_WURMPLE },
    { 3, 3, SPECIES_SEEDOT },
    { 4, 4, SPECIES_SEEDOT },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_RALTS },
    { 4, 4, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route102_RubyRS_LandMonsInfo = { 20, Route102_RubyRS_LandMons };
const struct WildPokemon Route102_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route102_RubyRS_WaterMonsInfo = { 4, Route102_RubyRS_WaterMons };
const struct WildPokemon Route102_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo Route102_RubyRS_FishingMonsInfo = { 30, Route102_RubyRS_FishingMons };

const struct WildPokemon Route103_RubyRS_LandMons[] =
{
    { 2, 2, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 2, 2, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route103_RubyRS_LandMonsInfo = { 20, Route103_RubyRS_LandMons };
const struct WildPokemon Route103_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route103_RubyRS_WaterMonsInfo = { 4, Route103_RubyRS_WaterMons };
const struct WildPokemon Route103_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route103_RubyRS_FishingMonsInfo = { 30, Route103_RubyRS_FishingMons };

const struct WildPokemon Route104_RubyRS_LandMons[] =
{
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_WURMPLE },
    { 5, 5, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_WURMPLE },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_TAILLOW },
    { 5, 5, SPECIES_TAILLOW },
    { 4, 4, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 5, 5, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route104_RubyRS_LandMonsInfo = { 20, Route104_RubyRS_LandMons };
const struct WildPokemon Route104_RubyRS_WaterMons[] =
{
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route104_RubyRS_WaterMonsInfo = { 4, Route104_RubyRS_WaterMons };
const struct WildPokemon Route104_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 20, 25, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 40, 45, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo Route104_RubyRS_FishingMonsInfo = { 30, Route104_RubyRS_FishingMons };

const struct WildPokemon Route105_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route105_RubyRS_WaterMonsInfo = { 4, Route105_RubyRS_WaterMons };
const struct WildPokemon Route105_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route105_RubyRS_FishingMonsInfo = { 30, Route105_RubyRS_FishingMons };

const struct WildPokemon Route106_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route106_RubyRS_WaterMonsInfo = { 4, Route106_RubyRS_WaterMons };
const struct WildPokemon Route106_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route106_RubyRS_FishingMonsInfo = { 30, Route106_RubyRS_FishingMons };

const struct WildPokemon Route107_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route107_RubyRS_WaterMonsInfo = { 4, Route107_RubyRS_WaterMons };
const struct WildPokemon Route107_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route107_RubyRS_FishingMonsInfo = { 30, Route107_RubyRS_FishingMons };

const struct WildPokemon Route108_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route108_RubyRS_WaterMonsInfo = { 4, Route108_RubyRS_WaterMons };
const struct WildPokemon Route108_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route108_RubyRS_FishingMonsInfo = { 30, Route108_RubyRS_FishingMons };

const struct WildPokemon Route109_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route109_RubyRS_WaterMonsInfo = { 4, Route109_RubyRS_WaterMons };
const struct WildPokemon Route109_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route109_RubyRS_FishingMonsInfo = { 30, Route109_RubyRS_FishingMons };

const struct WildPokemon Route110_RubyRS_LandMons[] =
{
    { 12, 12, SPECIES_ZIGZAGOON },
    { 12, 12, SPECIES_ELECTRIKE },
    { 12, 12, SPECIES_GULPIN },
    { 13, 13, SPECIES_ELECTRIKE },
    { 13, 13, SPECIES_MINUN },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_MINUN },
    { 13, 13, SPECIES_GULPIN },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_PLUSLE },
    { 13, 13, SPECIES_PLUSLE },
};

const struct WildPokemonInfo Route110_RubyRS_LandMonsInfo = { 20, Route110_RubyRS_LandMons };
const struct WildPokemon Route110_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route110_RubyRS_WaterMonsInfo = { 4, Route110_RubyRS_WaterMons };
const struct WildPokemon Route110_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route110_RubyRS_FishingMonsInfo = { 30, Route110_RubyRS_FishingMons };

const struct WildPokemon Route111_RubyRS_LandMons[] =
{
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 19, 19, SPECIES_CACNEA },
    { 21, 21, SPECIES_CACNEA },
    { 19, 19, SPECIES_SANDSHREW },
    { 19, 19, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_BALTOY },
    { 20, 20, SPECIES_BALTOY },
    { 22, 22, SPECIES_BALTOY },
    { 22, 22, SPECIES_BALTOY },
};

const struct WildPokemonInfo Route111_RubyRS_LandMonsInfo = { 10, Route111_RubyRS_LandMons };
const struct WildPokemon Route111_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route111_RubyRS_WaterMonsInfo = { 4, Route111_RubyRS_WaterMons };
const struct WildPokemon Route111_RubyRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo Route111_RubyRS_RockSmashMonsInfo = { 20, Route111_RubyRS_RockSmashMons };
const struct WildPokemon Route111_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route111_RubyRS_FishingMonsInfo = { 30, Route111_RubyRS_FishingMons };

const struct WildPokemon Route112_RubyRS_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_MACHOP },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_MACHOP },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_MACHOP },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
};

const struct WildPokemonInfo Route112_RubyRS_LandMonsInfo = { 20, Route112_RubyRS_LandMons };

const struct WildPokemon Route113_RubyRS_LandMons[] =
{
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SANDSHREW },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SANDSHREW },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
};

const struct WildPokemonInfo Route113_RubyRS_LandMonsInfo = { 20, Route113_RubyRS_LandMons };

const struct WildPokemon Route114_RubyRS_LandMons[] =
{
    { 16, 16, SPECIES_SWABLU },
    { 16, 16, SPECIES_SEEDOT },
    { 17, 17, SPECIES_SWABLU },
    { 15, 15, SPECIES_SWABLU },
    { 15, 15, SPECIES_SEEDOT },
    { 16, 16, SPECIES_ZANGOOSE },
    { 16, 16, SPECIES_NUZLEAF },
    { 18, 18, SPECIES_NUZLEAF },
    { 17, 17, SPECIES_ZANGOOSE },
    { 15, 15, SPECIES_ZANGOOSE },
    { 17, 17, SPECIES_ZANGOOSE },
    { 15, 15, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route114_RubyRS_LandMonsInfo = { 20, Route114_RubyRS_LandMons };
const struct WildPokemon Route114_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route114_RubyRS_WaterMonsInfo = { 4, Route114_RubyRS_WaterMons };
const struct WildPokemon Route114_RubyRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo Route114_RubyRS_RockSmashMonsInfo = { 20, Route114_RubyRS_RockSmashMons };
const struct WildPokemon Route114_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route114_RubyRS_FishingMonsInfo = { 30, Route114_RubyRS_FishingMons };

const struct WildPokemon Route115_RubyRS_LandMons[] =
{
    { 23, 23, SPECIES_SWABLU },
    { 23, 23, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWABLU },
    { 24, 24, SPECIES_TAILLOW },
    { 25, 25, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWELLOW },
    { 24, 24, SPECIES_JIGGLYPUFF },
    { 25, 25, SPECIES_JIGGLYPUFF },
    { 24, 24, SPECIES_WINGULL },
    { 24, 24, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route115_RubyRS_LandMonsInfo = { 20, Route115_RubyRS_LandMons };
const struct WildPokemon Route115_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route115_RubyRS_WaterMonsInfo = { 4, Route115_RubyRS_WaterMons };
const struct WildPokemon Route115_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route115_RubyRS_FishingMonsInfo = { 30, Route115_RubyRS_FishingMons };

const struct WildPokemon Route116_RubyRS_LandMons[] =
{
    { 6, 6, SPECIES_ZIGZAGOON },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_NINCADA },
    { 7, 7, SPECIES_WHISMUR },
    { 7, 7, SPECIES_NINCADA },
    { 6, 6, SPECIES_TAILLOW },
    { 7, 7, SPECIES_TAILLOW },
    { 8, 8, SPECIES_TAILLOW },
    { 7, 7, SPECIES_ZIGZAGOON },
    { 8, 8, SPECIES_ZIGZAGOON },
    { 7, 7, SPECIES_SKITTY },
    { 8, 8, SPECIES_SKITTY },
};

const struct WildPokemonInfo Route116_RubyRS_LandMonsInfo = { 20, Route116_RubyRS_LandMons };

const struct WildPokemon Route117_RubyRS_LandMons[] =
{
    { 13, 13, SPECIES_ZIGZAGOON },
    { 13, 13, SPECIES_ROSELIA },
    { 14, 14, SPECIES_ZIGZAGOON },
    { 14, 14, SPECIES_ROSELIA },
    { 13, 13, SPECIES_MARILL },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_VOLBEAT },
    { 13, 13, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route117_RubyRS_LandMonsInfo = { 20, Route117_RubyRS_LandMons };
const struct WildPokemon Route117_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route117_RubyRS_WaterMonsInfo = { 4, Route117_RubyRS_WaterMons };
const struct WildPokemon Route117_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo Route117_RubyRS_FishingMonsInfo = { 30, Route117_RubyRS_FishingMons };

const struct WildPokemon Route118_RubyRS_LandMons[] =
{
    { 24, 24, SPECIES_ZIGZAGOON },
    { 24, 24, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_LINOONE },
    { 26, 26, SPECIES_MANECTRIC },
    { 25, 25, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route118_RubyRS_LandMonsInfo = { 20, Route118_RubyRS_LandMons };
const struct WildPokemon Route118_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route118_RubyRS_WaterMonsInfo = { 4, Route118_RubyRS_WaterMons };
const struct WildPokemon Route118_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo Route118_RubyRS_FishingMonsInfo = { 30, Route118_RubyRS_FishingMons };

const struct WildPokemon Route119_RubyRS_LandMons[] =
{
    { 25, 25, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_LINOONE },
    { 27, 27, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 24, 24, SPECIES_ODDISH },
    { 25, 25, SPECIES_TROPIUS },
    { 26, 26, SPECIES_TROPIUS },
    { 27, 27, SPECIES_TROPIUS },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route119_RubyRS_LandMonsInfo = { 15, Route119_RubyRS_LandMons };
const struct WildPokemon Route119_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route119_RubyRS_WaterMonsInfo = { 4, Route119_RubyRS_WaterMons };
const struct WildPokemon Route119_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 25, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo Route119_RubyRS_FishingMonsInfo = { 30, Route119_RubyRS_FishingMons };

const struct WildPokemon Route120_RubyRS_LandMons[] =
{
    { 25, 25, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_LINOONE },
    { 27, 27, SPECIES_LINOONE },
    { 25, 25, SPECIES_ODDISH },
    { 25, 25, SPECIES_MARILL },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 27, 27, SPECIES_MARILL },
    { 25, 25, SPECIES_ABSOL },
    { 27, 27, SPECIES_ABSOL },
    { 25, 25, SPECIES_KECLEON },
    { 25, 25, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route120_RubyRS_LandMonsInfo = { 20, Route120_RubyRS_LandMons };
const struct WildPokemon Route120_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route120_RubyRS_WaterMonsInfo = { 4, Route120_RubyRS_WaterMons };
const struct WildPokemon Route120_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route120_RubyRS_FishingMonsInfo = { 30, Route120_RubyRS_FishingMons };

const struct WildPokemon Route121_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_DUSKULL },
    { 26, 26, SPECIES_LINOONE },
    { 28, 28, SPECIES_DUSKULL },
    { 28, 28, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route121_RubyRS_LandMonsInfo = { 20, Route121_RubyRS_LandMons };
const struct WildPokemon Route121_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route121_RubyRS_WaterMonsInfo = { 4, Route121_RubyRS_WaterMons };
const struct WildPokemon Route121_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route121_RubyRS_FishingMonsInfo = { 30, Route121_RubyRS_FishingMons };

const struct WildPokemon Route122_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route122_RubyRS_WaterMonsInfo = { 4, Route122_RubyRS_WaterMons };
const struct WildPokemon Route122_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route122_RubyRS_FishingMonsInfo = { 30, Route122_RubyRS_FishingMons };

const struct WildPokemon Route123_RubyRS_LandMons[] =
{
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_DUSKULL },
    { 26, 26, SPECIES_LINOONE },
    { 28, 28, SPECIES_DUSKULL },
    { 28, 28, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route123_RubyRS_LandMonsInfo = { 20, Route123_RubyRS_LandMons };
const struct WildPokemon Route123_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route123_RubyRS_WaterMonsInfo = { 4, Route123_RubyRS_WaterMons };
const struct WildPokemon Route123_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route123_RubyRS_FishingMonsInfo = { 30, Route123_RubyRS_FishingMons };

const struct WildPokemon Route124_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route124_RubyRS_WaterMonsInfo = { 4, Route124_RubyRS_WaterMons };
const struct WildPokemon Route124_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route124_RubyRS_FishingMonsInfo = { 30, Route124_RubyRS_FishingMons };

const struct WildPokemon Route125_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route125_RubyRS_WaterMonsInfo = { 4, Route125_RubyRS_WaterMons };
const struct WildPokemon Route125_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route125_RubyRS_FishingMonsInfo = { 30, Route125_RubyRS_FishingMons };

const struct WildPokemon Route126_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route126_RubyRS_WaterMonsInfo = { 4, Route126_RubyRS_WaterMons };
const struct WildPokemon Route126_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route126_RubyRS_FishingMonsInfo = { 30, Route126_RubyRS_FishingMons };

const struct WildPokemon Route127_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route127_RubyRS_WaterMonsInfo = { 4, Route127_RubyRS_WaterMons };
const struct WildPokemon Route127_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route127_RubyRS_FishingMonsInfo = { 30, Route127_RubyRS_FishingMons };

const struct WildPokemon Route128_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route128_RubyRS_WaterMonsInfo = { 4, Route128_RubyRS_WaterMons };
const struct WildPokemon Route128_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route128_RubyRS_FishingMonsInfo = { 30, Route128_RubyRS_FishingMons };

const struct WildPokemon Route129_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 35, 40, SPECIES_WAILORD },
};

const struct WildPokemonInfo Route129_RubyRS_WaterMonsInfo = { 4, Route129_RubyRS_WaterMons };
const struct WildPokemon Route129_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route129_RubyRS_FishingMonsInfo = { 30, Route129_RubyRS_FishingMons };

const struct WildPokemon Route130_RubyRS_LandMons[] =
{
    { 30, 30, SPECIES_WYNAUT },
    { 35, 35, SPECIES_WYNAUT },
    { 25, 25, SPECIES_WYNAUT },
    { 40, 40, SPECIES_WYNAUT },
    { 20, 20, SPECIES_WYNAUT },
    { 45, 45, SPECIES_WYNAUT },
    { 15, 15, SPECIES_WYNAUT },
    { 50, 50, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
};

const struct WildPokemonInfo Route130_RubyRS_LandMonsInfo = { 20, Route130_RubyRS_LandMons };
const struct WildPokemon Route130_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route130_RubyRS_WaterMonsInfo = { 4, Route130_RubyRS_WaterMons };
const struct WildPokemon Route130_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route130_RubyRS_FishingMonsInfo = { 30, Route130_RubyRS_FishingMons };

const struct WildPokemon Route131_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route131_RubyRS_WaterMonsInfo = { 4, Route131_RubyRS_WaterMons };
const struct WildPokemon Route131_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route131_RubyRS_FishingMonsInfo = { 30, Route131_RubyRS_FishingMons };

const struct WildPokemon Route132_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route132_RubyRS_WaterMonsInfo = { 4, Route132_RubyRS_WaterMons };
const struct WildPokemon Route132_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route132_RubyRS_FishingMonsInfo = { 30, Route132_RubyRS_FishingMons };

const struct WildPokemon Route133_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route133_RubyRS_WaterMonsInfo = { 4, Route133_RubyRS_WaterMons };
const struct WildPokemon Route133_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route133_RubyRS_FishingMonsInfo = { 30, Route133_RubyRS_FishingMons };

const struct WildPokemon Route134_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route134_RubyRS_WaterMonsInfo = { 4, Route134_RubyRS_WaterMons };
const struct WildPokemon Route134_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route134_RubyRS_FishingMonsInfo = { 30, Route134_RubyRS_FishingMons };

const struct WildPokemon SafariZone_Northwest_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_RHYHORN },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_RHYHORN },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_DODUO },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_DODUO },
    { 29, 29, SPECIES_DODRIO },
    { 27, 27, SPECIES_PINSIR },
    { 31, 31, SPECIES_DODRIO },
    { 29, 29, SPECIES_PINSIR },
};

const struct WildPokemonInfo SafariZone_Northwest_RubyRS_LandMonsInfo = { 25, SafariZone_Northwest_RubyRS_LandMons };
const struct WildPokemon SafariZone_Northwest_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_GOLDUCK },
    { 25, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo SafariZone_Northwest_RubyRS_WaterMonsInfo = { 9, SafariZone_Northwest_RubyRS_WaterMons };
const struct WildPokemon SafariZone_Northwest_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo SafariZone_Northwest_RubyRS_FishingMonsInfo = { 35, SafariZone_Northwest_RubyRS_FishingMons };

const struct WildPokemon SafariZone_Northeast_RubyRS_LandMons[] =
{
    { 27, 27, SPECIES_PHANPY },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_PHANPY },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_NATU },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_NATU },
    { 29, 29, SPECIES_XATU },
    { 27, 27, SPECIES_HERACROSS },
    { 31, 31, SPECIES_XATU },
    { 29, 29, SPECIES_HERACROSS },
};

const struct WildPokemonInfo SafariZone_Northeast_RubyRS_LandMonsInfo = { 25, SafariZone_Northeast_RubyRS_LandMons };
const struct WildPokemon SafariZone_Northeast_RubyRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 20, 25, SPECIES_GEODUDE },
    { 25, 30, SPECIES_GEODUDE },
};

const struct WildPokemonInfo SafariZone_Northeast_RubyRS_RockSmashMonsInfo = { 25, SafariZone_Northeast_RubyRS_RockSmashMons };

const struct WildPokemon SafariZone_Southwest_RubyRS_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 25, 25, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo SafariZone_Southwest_RubyRS_LandMonsInfo = { 25, SafariZone_Southwest_RubyRS_LandMons };
const struct WildPokemon SafariZone_Southwest_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo SafariZone_Southwest_RubyRS_WaterMonsInfo = { 9, SafariZone_Southwest_RubyRS_WaterMons };
const struct WildPokemon SafariZone_Southwest_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo SafariZone_Southwest_RubyRS_FishingMonsInfo = { 35, SafariZone_Southwest_RubyRS_FishingMons };

const struct WildPokemon SafariZone_Southeast_RubyRS_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 25, 25, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo SafariZone_Southeast_RubyRS_LandMonsInfo = { 25, SafariZone_Southeast_RubyRS_LandMons };

const struct WildPokemon DewfordTown_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo DewfordTown_RubyRS_WaterMonsInfo = { 4, DewfordTown_RubyRS_WaterMons };
const struct WildPokemon DewfordTown_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo DewfordTown_RubyRS_FishingMonsInfo = { 10, DewfordTown_RubyRS_FishingMons };

const struct WildPokemon PacifidlogTown_RubyRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo PacifidlogTown_RubyRS_WaterMonsInfo = { 4, PacifidlogTown_RubyRS_WaterMons };
const struct WildPokemon PacifidlogTown_RubyRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo PacifidlogTown_RubyRS_FishingMonsInfo = { 10, PacifidlogTown_RubyRS_FishingMons };

const struct WildPokemon Underwater1_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo Underwater1_RubyRS_WaterMonsInfo = { 4, Underwater1_RubyRS_WaterMons };

const struct WildPokemon Underwater2_RubyRS_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo Underwater2_RubyRS_WaterMonsInfo = { 4, Underwater2_RubyRS_WaterMons };

const struct WildPokemon PetalburgCity_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
};

const struct WildPokemonInfo PetalburgCity_SapphireRS_WaterMonsInfo = { 1, PetalburgCity_SapphireRS_WaterMons };
const struct WildPokemon PetalburgCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo PetalburgCity_SapphireRS_FishingMonsInfo = { 10, PetalburgCity_SapphireRS_FishingMons };

const struct WildPokemon SlateportCity_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo SlateportCity_SapphireRS_WaterMonsInfo = { 4, SlateportCity_SapphireRS_WaterMons };
const struct WildPokemon SlateportCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SlateportCity_SapphireRS_FishingMonsInfo = { 10, SlateportCity_SapphireRS_FishingMons };

const struct WildPokemon LilycoveCity_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo LilycoveCity_SapphireRS_WaterMonsInfo = { 4, LilycoveCity_SapphireRS_WaterMons };
const struct WildPokemon LilycoveCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_STARYU },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo LilycoveCity_SapphireRS_FishingMonsInfo = { 10, LilycoveCity_SapphireRS_FishingMons };

const struct WildPokemon MossdeepCity_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo MossdeepCity_SapphireRS_WaterMonsInfo = { 4, MossdeepCity_SapphireRS_WaterMons };
const struct WildPokemon MossdeepCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo MossdeepCity_SapphireRS_FishingMonsInfo = { 10, MossdeepCity_SapphireRS_FishingMons };

const struct WildPokemon SootopolisCity_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo SootopolisCity_SapphireRS_WaterMonsInfo = { 1, SootopolisCity_SapphireRS_WaterMons };
const struct WildPokemon SootopolisCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_GYARADOS },
    { 35, 45, SPECIES_GYARADOS },
    { 5, 45, SPECIES_GYARADOS },
};

const struct WildPokemonInfo SootopolisCity_SapphireRS_FishingMonsInfo = { 10, SootopolisCity_SapphireRS_FishingMons };

const struct WildPokemon EverGrandeCity_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo EverGrandeCity_SapphireRS_WaterMonsInfo = { 4, EverGrandeCity_SapphireRS_WaterMons };
const struct WildPokemon EverGrandeCity_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo EverGrandeCity_SapphireRS_FishingMonsInfo = { 10, EverGrandeCity_SapphireRS_FishingMons };

const struct WildPokemon MeteorFalls_1F_1R_SapphireRS_LandMons[] =
{
    { 16, 16, SPECIES_ZUBAT },
    { 17, 17, SPECIES_ZUBAT },
    { 18, 18, SPECIES_ZUBAT },
    { 15, 15, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 16, 16, SPECIES_LUNATONE },
    { 18, 18, SPECIES_LUNATONE },
    { 14, 14, SPECIES_LUNATONE },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
    { 19, 19, SPECIES_ZUBAT },
    { 20, 20, SPECIES_ZUBAT },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_SapphireRS_LandMonsInfo = { 10, MeteorFalls_1F_1R_SapphireRS_LandMons };
const struct WildPokemon MeteorFalls_1F_1R_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 25, 35, SPECIES_LUNATONE },
    { 15, 25, SPECIES_LUNATONE },
    { 5, 15, SPECIES_LUNATONE },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_SapphireRS_WaterMonsInfo = { 4, MeteorFalls_1F_1R_SapphireRS_WaterMons };
const struct WildPokemon MeteorFalls_1F_1R_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo MeteorFalls_1F_1R_SapphireRS_FishingMonsInfo = { 30, MeteorFalls_1F_1R_SapphireRS_FishingMons };

const struct WildPokemon MeteorFalls_1F_2R_SapphireRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_LUNATONE },
    { 33, 33, SPECIES_LUNATONE },
    { 37, 37, SPECIES_LUNATONE },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_LUNATONE },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_SapphireRS_LandMonsInfo = { 10, MeteorFalls_1F_2R_SapphireRS_LandMons };
const struct WildPokemon MeteorFalls_1F_2R_SapphireRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_LUNATONE },
    { 15, 25, SPECIES_LUNATONE },
    { 5, 15, SPECIES_LUNATONE },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_SapphireRS_WaterMonsInfo = { 4, MeteorFalls_1F_2R_SapphireRS_WaterMons };
const struct WildPokemon MeteorFalls_1F_2R_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_1F_2R_SapphireRS_FishingMonsInfo = { 30, MeteorFalls_1F_2R_SapphireRS_FishingMons };

const struct WildPokemon MeteorFalls_B1F_1R_SapphireRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_LUNATONE },
    { 33, 33, SPECIES_LUNATONE },
    { 37, 37, SPECIES_LUNATONE },
    { 35, 35, SPECIES_GOLBAT },
    { 39, 39, SPECIES_LUNATONE },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_SapphireRS_LandMonsInfo = { 10, MeteorFalls_B1F_1R_SapphireRS_LandMons };
const struct WildPokemon MeteorFalls_B1F_1R_SapphireRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_LUNATONE },
    { 15, 25, SPECIES_LUNATONE },
    { 5, 15, SPECIES_LUNATONE },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_SapphireRS_WaterMonsInfo = { 4, MeteorFalls_B1F_1R_SapphireRS_WaterMons };
const struct WildPokemon MeteorFalls_B1F_1R_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_B1F_1R_SapphireRS_FishingMonsInfo = { 30, MeteorFalls_B1F_1R_SapphireRS_FishingMons };

const struct WildPokemon MeteorFalls_B1F_2R_SapphireRS_LandMons[] =
{
    { 33, 33, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 30, 30, SPECIES_BAGON },
    { 35, 35, SPECIES_LUNATONE },
    { 35, 35, SPECIES_BAGON },
    { 37, 37, SPECIES_LUNATONE },
    { 25, 25, SPECIES_BAGON },
    { 39, 39, SPECIES_LUNATONE },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
    { 38, 38, SPECIES_GOLBAT },
    { 40, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_SapphireRS_LandMonsInfo = { 10, MeteorFalls_B1F_2R_SapphireRS_LandMons };
const struct WildPokemon MeteorFalls_B1F_2R_SapphireRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_LUNATONE },
    { 15, 25, SPECIES_LUNATONE },
    { 5, 15, SPECIES_LUNATONE },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_SapphireRS_WaterMonsInfo = { 4, MeteorFalls_B1F_2R_SapphireRS_WaterMons };
const struct WildPokemon MeteorFalls_B1F_2R_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo MeteorFalls_B1F_2R_SapphireRS_FishingMonsInfo = { 30, MeteorFalls_B1F_2R_SapphireRS_FishingMons };

const struct WildPokemon RusturfTunnel_SapphireRS_LandMons[] =
{
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 7, 7, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
    { 5, 5, SPECIES_WHISMUR },
    { 8, 8, SPECIES_WHISMUR },
};

const struct WildPokemonInfo RusturfTunnel_SapphireRS_LandMonsInfo = { 10, RusturfTunnel_SapphireRS_LandMons };

const struct WildPokemon GraniteCave_1F_SapphireRS_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_GEODUDE },
    { 8, 8, SPECIES_GEODUDE },
    { 6, 6, SPECIES_GEODUDE },
    { 9, 9, SPECIES_GEODUDE },
};

const struct WildPokemonInfo GraniteCave_1F_SapphireRS_LandMonsInfo = { 10, GraniteCave_1F_SapphireRS_LandMons };

const struct WildPokemon GraniteCave_B1F_SapphireRS_LandMons[] =
{
    { 9, 9, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ARON },
    { 9, 9, SPECIES_ARON },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ZUBAT },
    { 9, 9, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 11, 11, SPECIES_MAKUHITA },
    { 10, 10, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
    { 9, 9, SPECIES_SABLEYE },
    { 11, 11, SPECIES_SABLEYE },
};

const struct WildPokemonInfo GraniteCave_B1F_SapphireRS_LandMonsInfo = { 10, GraniteCave_B1F_SapphireRS_LandMons };

const struct WildPokemon GraniteCave_B2F_SapphireRS_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 11, 11, SPECIES_ARON },
    { 10, 10, SPECIES_ARON },
    { 11, 11, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ARON },
    { 10, 10, SPECIES_ABRA },
    { 10, 10, SPECIES_SABLEYE },
    { 11, 11, SPECIES_SABLEYE },
    { 12, 12, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
    { 12, 12, SPECIES_SABLEYE },
    { 10, 10, SPECIES_SABLEYE },
};

const struct WildPokemonInfo GraniteCave_B2F_SapphireRS_LandMonsInfo = { 10, GraniteCave_B2F_SapphireRS_LandMons };
const struct WildPokemon GraniteCave_B2F_SapphireRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 10, 20, SPECIES_NOSEPASS },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo GraniteCave_B2F_SapphireRS_RockSmashMonsInfo = { 20, GraniteCave_B2F_SapphireRS_RockSmashMons };

const struct WildPokemon GraniteCave_StevensRoom_SapphireRS_LandMons[] =
{
    { 7, 7, SPECIES_ZUBAT },
    { 8, 8, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ZUBAT },
    { 9, 9, SPECIES_MAKUHITA },
    { 8, 8, SPECIES_ABRA },
    { 10, 10, SPECIES_MAKUHITA },
    { 6, 6, SPECIES_MAKUHITA },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
    { 7, 7, SPECIES_ARON },
    { 8, 8, SPECIES_ARON },
};

const struct WildPokemonInfo GraniteCave_StevensRoom_SapphireRS_LandMonsInfo = { 10, GraniteCave_StevensRoom_SapphireRS_LandMons };

const struct WildPokemon PetalburgWoods_SapphireRS_LandMons[] =
{
    { 5, 5, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_WURMPLE },
    { 5, 5, SPECIES_SHROOMISH },
    { 6, 6, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_SILCOON },
    { 5, 5, SPECIES_CASCOON },
    { 6, 6, SPECIES_WURMPLE },
    { 6, 6, SPECIES_SHROOMISH },
    { 5, 5, SPECIES_TAILLOW },
    { 5, 5, SPECIES_SLAKOTH },
    { 6, 6, SPECIES_TAILLOW },
    { 6, 6, SPECIES_SLAKOTH },
};

const struct WildPokemonInfo PetalburgWoods_SapphireRS_LandMonsInfo = { 20, PetalburgWoods_SapphireRS_LandMons };

const struct WildPokemon JaggedPass_SapphireRS_LandMons[] =
{
    { 21, 21, SPECIES_NUMEL },
    { 21, 21, SPECIES_NUMEL },
    { 21, 21, SPECIES_MACHOP },
    { 20, 20, SPECIES_NUMEL },
    { 20, 20, SPECIES_SPOINK },
    { 20, 20, SPECIES_MACHOP },
    { 21, 21, SPECIES_SPOINK },
    { 22, 22, SPECIES_MACHOP },
    { 22, 22, SPECIES_NUMEL },
    { 22, 22, SPECIES_SPOINK },
    { 22, 22, SPECIES_NUMEL },
    { 22, 22, SPECIES_SPOINK },
};

const struct WildPokemonInfo JaggedPass_SapphireRS_LandMonsInfo = { 20, JaggedPass_SapphireRS_LandMons };

const struct WildPokemon FieryPath_SapphireRS_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_GRIMER },
    { 16, 16, SPECIES_NUMEL },
    { 15, 15, SPECIES_MACHOP },
    { 15, 15, SPECIES_TORKOAL },
    { 15, 15, SPECIES_SLUGMA },
    { 16, 16, SPECIES_GRIMER },
    { 16, 16, SPECIES_MACHOP },
    { 14, 14, SPECIES_TORKOAL },
    { 16, 16, SPECIES_TORKOAL },
    { 14, 14, SPECIES_KOFFING },
    { 14, 14, SPECIES_KOFFING },
};

const struct WildPokemonInfo FieryPath_SapphireRS_LandMonsInfo = { 10, FieryPath_SapphireRS_LandMons };

const struct WildPokemon MtPyre_1F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_1F_SapphireRS_LandMonsInfo = { 10, MtPyre_1F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_2F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_2F_SapphireRS_LandMonsInfo = { 10, MtPyre_2F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_3F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
};

const struct WildPokemonInfo MtPyre_3F_SapphireRS_LandMonsInfo = { 10, MtPyre_3F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_4F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_4F_SapphireRS_LandMonsInfo = { 10, MtPyre_4F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_5F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_5F_SapphireRS_LandMonsInfo = { 10, MtPyre_5F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_6F_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 23, 23, SPECIES_SHUPPET },
    { 22, 22, SPECIES_SHUPPET },
    { 27, 27, SPECIES_DUSKULL },
    { 27, 27, SPECIES_DUSKULL },
    { 25, 25, SPECIES_DUSKULL },
    { 29, 29, SPECIES_DUSKULL },
};

const struct WildPokemonInfo MtPyre_6F_SapphireRS_LandMonsInfo = { 10, MtPyre_6F_SapphireRS_LandMons };

const struct WildPokemon MtPyre_Exterior_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_MEDITITE },
    { 28, 28, SPECIES_SHUPPET },
    { 29, 29, SPECIES_MEDITITE },
    { 29, 29, SPECIES_SHUPPET },
    { 27, 27, SPECIES_VULPIX },
    { 29, 29, SPECIES_VULPIX },
    { 25, 25, SPECIES_VULPIX },
    { 27, 27, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
};

const struct WildPokemonInfo MtPyre_Exterior_SapphireRS_LandMonsInfo = { 10, MtPyre_Exterior_SapphireRS_LandMons };

const struct WildPokemon MtPyre_Summit_SapphireRS_LandMons[] =
{
    { 28, 28, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 26, 26, SPECIES_SHUPPET },
    { 30, 30, SPECIES_SHUPPET },
    { 25, 25, SPECIES_SHUPPET },
    { 24, 24, SPECIES_SHUPPET },
    { 28, 28, SPECIES_DUSKULL },
    { 26, 26, SPECIES_DUSKULL },
    { 30, 30, SPECIES_DUSKULL },
    { 28, 28, SPECIES_CHIMECHO },
    { 28, 28, SPECIES_CHIMECHO },
};

const struct WildPokemonInfo MtPyre_Summit_SapphireRS_LandMonsInfo = { 10, MtPyre_Summit_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Entrance_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Entrance_SapphireRS_WaterMonsInfo = { 4, SeafloorCavern_Entrance_SapphireRS_WaterMons };
const struct WildPokemon SeafloorCavern_Entrance_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Entrance_SapphireRS_FishingMonsInfo = { 10, SeafloorCavern_Entrance_SapphireRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room1_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room1_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room1_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Room2_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room2_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room2_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Room3_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room3_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room3_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Room4_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room4_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room4_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Room5_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room5_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room5_SapphireRS_LandMons };

const struct WildPokemon SeafloorCavern_Room6_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room6_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room6_SapphireRS_LandMons };
const struct WildPokemon SeafloorCavern_Room6_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room6_SapphireRS_WaterMonsInfo = { 4, SeafloorCavern_Room6_SapphireRS_WaterMons };
const struct WildPokemon SeafloorCavern_Room6_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Room6_SapphireRS_FishingMonsInfo = { 10, SeafloorCavern_Room6_SapphireRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room7_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room7_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room7_SapphireRS_LandMons };
const struct WildPokemon SeafloorCavern_Room7_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room7_SapphireRS_WaterMonsInfo = { 4, SeafloorCavern_Room7_SapphireRS_WaterMons };
const struct WildPokemon SeafloorCavern_Room7_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo SeafloorCavern_Room7_SapphireRS_FishingMonsInfo = { 10, SeafloorCavern_Room7_SapphireRS_FishingMons };

const struct WildPokemon SeafloorCavern_Room8_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo SeafloorCavern_Room8_SapphireRS_LandMonsInfo = { 4, SeafloorCavern_Room8_SapphireRS_LandMons };

const struct WildPokemon CaveOfOrigin_Entrance_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 33, 33, SPECIES_ZUBAT },
    { 28, 28, SPECIES_ZUBAT },
    { 29, 29, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 35, 35, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_Entrance_SapphireRS_LandMonsInfo = { 4, CaveOfOrigin_Entrance_SapphireRS_LandMons };

const struct WildPokemon CaveOfOrigin_1F_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_1F_SapphireRS_LandMonsInfo = { 4, CaveOfOrigin_1F_SapphireRS_LandMons };

const struct WildPokemon CaveOfOrigin_B1F_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B1F_SapphireRS_LandMonsInfo = { 4, CaveOfOrigin_B1F_SapphireRS_LandMons };

const struct WildPokemon CaveOfOrigin_B2F_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B2F_SapphireRS_LandMonsInfo = { 4, CaveOfOrigin_B2F_SapphireRS_LandMons };

const struct WildPokemon CaveOfOrigin_B3F_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_ZUBAT },
    { 31, 31, SPECIES_ZUBAT },
    { 32, 32, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SABLEYE },
    { 32, 32, SPECIES_SABLEYE },
    { 34, 34, SPECIES_SABLEYE },
    { 33, 33, SPECIES_ZUBAT },
    { 34, 34, SPECIES_ZUBAT },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 33, 33, SPECIES_GOLBAT },
    { 36, 36, SPECIES_GOLBAT },
};

const struct WildPokemonInfo CaveOfOrigin_B3F_SapphireRS_LandMonsInfo = { 4, CaveOfOrigin_B3F_SapphireRS_LandMons };

const struct WildPokemon VictoryRoad_1F_SapphireRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LOUDRED },
    { 36, 36, SPECIES_ZUBAT },
    { 36, 36, SPECIES_MAKUHITA },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
    { 36, 36, SPECIES_ARON },
    { 36, 36, SPECIES_WHISMUR },
};

const struct WildPokemonInfo VictoryRoad_1F_SapphireRS_LandMonsInfo = { 10, VictoryRoad_1F_SapphireRS_LandMons };

const struct WildPokemon VictoryRoad_B1F_SapphireRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_MEDICHAM },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MEDITITE },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MEDITITE },
};

const struct WildPokemonInfo VictoryRoad_B1F_SapphireRS_LandMonsInfo = { 10, VictoryRoad_B1F_SapphireRS_LandMons };
const struct WildPokemon VictoryRoad_B1F_SapphireRS_RockSmashMons[] =
{
    { 30, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo VictoryRoad_B1F_SapphireRS_RockSmashMonsInfo = { 20, VictoryRoad_B1F_SapphireRS_RockSmashMons };

const struct WildPokemon VictoryRoad_B2F_SapphireRS_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_SABLEYE },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_MEDICHAM },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_SABLEYE },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_SABLEYE },
    { 42, 42, SPECIES_LAIRON },
    { 42, 42, SPECIES_MEDICHAM },
    { 44, 44, SPECIES_LAIRON },
    { 44, 44, SPECIES_MEDICHAM },
};

const struct WildPokemonInfo VictoryRoad_B2F_SapphireRS_LandMonsInfo = { 10, VictoryRoad_B2F_SapphireRS_LandMons };
const struct WildPokemon VictoryRoad_B2F_SapphireRS_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 25, 30, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo VictoryRoad_B2F_SapphireRS_WaterMonsInfo = { 4, VictoryRoad_B2F_SapphireRS_WaterMons };
const struct WildPokemon VictoryRoad_B2F_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 30, 35, SPECIES_WHISCASH },
    { 35, 40, SPECIES_WHISCASH },
    { 40, 45, SPECIES_WHISCASH },
};

const struct WildPokemonInfo VictoryRoad_B2F_SapphireRS_FishingMonsInfo = { 30, VictoryRoad_B2F_SapphireRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideEntranceRoom_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_SapphireRS_LandMonsInfo = { 10, ShoalCave_LowTideEntranceRoom_SapphireRS_LandMons };
const struct WildPokemon ShoalCave_LowTideEntranceRoom_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_SapphireRS_WaterMonsInfo = { 4, ShoalCave_LowTideEntranceRoom_SapphireRS_WaterMons };
const struct WildPokemon ShoalCave_LowTideEntranceRoom_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo ShoalCave_LowTideEntranceRoom_SapphireRS_FishingMonsInfo = { 10, ShoalCave_LowTideEntranceRoom_SapphireRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideInnerRoom_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_SapphireRS_LandMonsInfo = { 10, ShoalCave_LowTideInnerRoom_SapphireRS_LandMons };
const struct WildPokemon ShoalCave_LowTideInnerRoom_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_SapphireRS_WaterMonsInfo = { 4, ShoalCave_LowTideInnerRoom_SapphireRS_WaterMons };
const struct WildPokemon ShoalCave_LowTideInnerRoom_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo ShoalCave_LowTideInnerRoom_SapphireRS_FishingMonsInfo = { 10, ShoalCave_LowTideInnerRoom_SapphireRS_FishingMons };

const struct WildPokemon ShoalCave_LowTideStairsRoom_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideStairsRoom_SapphireRS_LandMonsInfo = { 10, ShoalCave_LowTideStairsRoom_SapphireRS_LandMons };

const struct WildPokemon ShoalCave_LowTideLowerRoom_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 32, 32, SPECIES_ZUBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
    { 32, 32, SPECIES_GOLBAT },
    { 32, 32, SPECIES_SPHEAL },
};

const struct WildPokemonInfo ShoalCave_LowTideLowerRoom_SapphireRS_LandMonsInfo = { 10, ShoalCave_LowTideLowerRoom_SapphireRS_LandMons };

const struct WildPokemon ShoalCave_LowTideIceRoom_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZUBAT },
    { 26, 26, SPECIES_SPHEAL },
    { 28, 28, SPECIES_ZUBAT },
    { 28, 28, SPECIES_SPHEAL },
    { 30, 30, SPECIES_ZUBAT },
    { 30, 30, SPECIES_SPHEAL },
    { 26, 26, SPECIES_SNORUNT },
    { 32, 32, SPECIES_SPHEAL },
    { 30, 30, SPECIES_GOLBAT },
    { 28, 28, SPECIES_SNORUNT },
    { 32, 32, SPECIES_GOLBAT },
    { 30, 30, SPECIES_SNORUNT },
};

const struct WildPokemonInfo ShoalCave_LowTideIceRoom_SapphireRS_LandMonsInfo = { 10, ShoalCave_LowTideIceRoom_SapphireRS_LandMons };

const struct WildPokemon NewMauville_Entrance_SapphireRS_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
};

const struct WildPokemonInfo NewMauville_Entrance_SapphireRS_LandMonsInfo = { 10, NewMauville_Entrance_SapphireRS_LandMons };

const struct WildPokemon NewMauville_Inside_SapphireRS_LandMons[] =
{
    { 24, 24, SPECIES_VOLTORB },
    { 24, 24, SPECIES_MAGNEMITE },
    { 25, 25, SPECIES_VOLTORB },
    { 25, 25, SPECIES_MAGNEMITE },
    { 23, 23, SPECIES_VOLTORB },
    { 23, 23, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_VOLTORB },
    { 26, 26, SPECIES_MAGNEMITE },
    { 22, 22, SPECIES_VOLTORB },
    { 22, 22, SPECIES_MAGNEMITE },
    { 26, 26, SPECIES_ELECTRODE },
    { 26, 26, SPECIES_MAGNETON },
};

const struct WildPokemonInfo NewMauville_Inside_SapphireRS_LandMonsInfo = { 10, NewMauville_Inside_SapphireRS_LandMons };

const struct WildPokemon AbandonedShip_Rooms_B1F_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_Rooms_B1F_SapphireRS_WaterMonsInfo = { 4, AbandonedShip_Rooms_B1F_SapphireRS_WaterMons };
const struct WildPokemon AbandonedShip_Rooms_B1F_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_Rooms_B1F_SapphireRS_FishingMonsInfo = { 20, AbandonedShip_Rooms_B1F_SapphireRS_FishingMons };

const struct WildPokemon AbandonedShip_HiddenFloorCorridors_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_HiddenFloorCorridors_SapphireRS_WaterMonsInfo = { 4, AbandonedShip_HiddenFloorCorridors_SapphireRS_WaterMons };
const struct WildPokemon AbandonedShip_HiddenFloorCorridors_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_TENTACOOL },
    { 25, 30, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
    { 25, 30, SPECIES_TENTACRUEL },
    { 20, 25, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo AbandonedShip_HiddenFloorCorridors_SapphireRS_FishingMonsInfo = { 20, AbandonedShip_HiddenFloorCorridors_SapphireRS_FishingMons };

const struct WildPokemon SkyPillar_1F_SapphireRS_LandMons[] =
{
    { 48, 48, SPECIES_SABLEYE },
    { 48, 48, SPECIES_GOLBAT },
    { 50, 50, SPECIES_GOLBAT },
    { 50, 50, SPECIES_SABLEYE },
    { 48, 48, SPECIES_CLAYDOL },
    { 48, 48, SPECIES_BANETTE },
    { 50, 50, SPECIES_BANETTE },
    { 49, 49, SPECIES_CLAYDOL },
    { 47, 47, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 47, 47, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo SkyPillar_1F_SapphireRS_LandMonsInfo = { 10, SkyPillar_1F_SapphireRS_LandMons };

const struct WildPokemon SkyPillar_3F_SapphireRS_LandMons[] =
{
    { 51, 51, SPECIES_SABLEYE },
    { 51, 51, SPECIES_GOLBAT },
    { 53, 53, SPECIES_GOLBAT },
    { 53, 53, SPECIES_SABLEYE },
    { 51, 51, SPECIES_CLAYDOL },
    { 51, 51, SPECIES_BANETTE },
    { 53, 53, SPECIES_BANETTE },
    { 52, 52, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 53, 53, SPECIES_CLAYDOL },
    { 50, 50, SPECIES_CLAYDOL },
    { 53, 53, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo SkyPillar_3F_SapphireRS_LandMonsInfo = { 10, SkyPillar_3F_SapphireRS_LandMons };

const struct WildPokemon SkyPillar_5F_SapphireRS_LandMons[] =
{
    { 54, 54, SPECIES_SABLEYE },
    { 54, 54, SPECIES_GOLBAT },
    { 56, 56, SPECIES_GOLBAT },
    { 56, 56, SPECIES_SABLEYE },
    { 54, 54, SPECIES_CLAYDOL },
    { 54, 54, SPECIES_BANETTE },
    { 56, 56, SPECIES_BANETTE },
    { 55, 55, SPECIES_CLAYDOL },
    { 56, 56, SPECIES_CLAYDOL },
    { 57, 57, SPECIES_ALTARIA },
    { 54, 54, SPECIES_ALTARIA },
    { 60, 60, SPECIES_ALTARIA },
};

const struct WildPokemonInfo SkyPillar_5F_SapphireRS_LandMonsInfo = { 10, SkyPillar_5F_SapphireRS_LandMons };

const struct WildPokemon Route101_SapphireRS_LandMons[] =
{
    { 2, 2, SPECIES_WURMPLE },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_WURMPLE },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
};

const struct WildPokemonInfo Route101_SapphireRS_LandMonsInfo = { 20, Route101_SapphireRS_LandMons };

const struct WildPokemon Route102_SapphireRS_LandMons[] =
{
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WURMPLE },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_WURMPLE },
    { 3, 3, SPECIES_LOTAD },
    { 4, 4, SPECIES_LOTAD },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_RALTS },
    { 4, 4, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route102_SapphireRS_LandMonsInfo = { 20, Route102_SapphireRS_LandMons };
const struct WildPokemon Route102_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route102_SapphireRS_WaterMonsInfo = { 4, Route102_SapphireRS_WaterMons };
const struct WildPokemon Route102_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo Route102_SapphireRS_FishingMonsInfo = { 30, Route102_SapphireRS_FishingMons };

const struct WildPokemon Route103_SapphireRS_LandMons[] =
{
    { 2, 2, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 2, 2, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route103_SapphireRS_LandMonsInfo = { 20, Route103_SapphireRS_LandMons };
const struct WildPokemon Route103_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route103_SapphireRS_WaterMonsInfo = { 4, Route103_SapphireRS_WaterMons };
const struct WildPokemon Route103_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route103_SapphireRS_FishingMonsInfo = { 30, Route103_SapphireRS_FishingMons };

const struct WildPokemon Route104_SapphireRS_LandMons[] =
{
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_WURMPLE },
    { 5, 5, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_WURMPLE },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 5, 5, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_TAILLOW },
    { 5, 5, SPECIES_TAILLOW },
    { 4, 4, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 5, 5, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route104_SapphireRS_LandMonsInfo = { 20, Route104_SapphireRS_LandMons };
const struct WildPokemon Route104_SapphireRS_WaterMons[] =
{
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route104_SapphireRS_WaterMonsInfo = { 4, Route104_SapphireRS_WaterMons };
const struct WildPokemon Route104_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 30, 35, SPECIES_MAGIKARP },
    { 20, 25, SPECIES_MAGIKARP },
    { 35, 40, SPECIES_MAGIKARP },
    { 40, 45, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo Route104_SapphireRS_FishingMonsInfo = { 30, Route104_SapphireRS_FishingMons };

const struct WildPokemon Route105_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route105_SapphireRS_WaterMonsInfo = { 4, Route105_SapphireRS_WaterMons };
const struct WildPokemon Route105_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route105_SapphireRS_FishingMonsInfo = { 30, Route105_SapphireRS_FishingMons };

const struct WildPokemon Route106_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route106_SapphireRS_WaterMonsInfo = { 4, Route106_SapphireRS_WaterMons };
const struct WildPokemon Route106_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route106_SapphireRS_FishingMonsInfo = { 30, Route106_SapphireRS_FishingMons };

const struct WildPokemon Route107_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route107_SapphireRS_WaterMonsInfo = { 4, Route107_SapphireRS_WaterMons };
const struct WildPokemon Route107_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route107_SapphireRS_FishingMonsInfo = { 30, Route107_SapphireRS_FishingMons };

const struct WildPokemon Route108_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route108_SapphireRS_WaterMonsInfo = { 4, Route108_SapphireRS_WaterMons };
const struct WildPokemon Route108_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route108_SapphireRS_FishingMonsInfo = { 30, Route108_SapphireRS_FishingMons };

const struct WildPokemon Route109_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route109_SapphireRS_WaterMonsInfo = { 4, Route109_SapphireRS_WaterMons };
const struct WildPokemon Route109_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route109_SapphireRS_FishingMonsInfo = { 30, Route109_SapphireRS_FishingMons };

const struct WildPokemon Route110_SapphireRS_LandMons[] =
{
    { 12, 12, SPECIES_ZIGZAGOON },
    { 12, 12, SPECIES_ELECTRIKE },
    { 12, 12, SPECIES_GULPIN },
    { 13, 13, SPECIES_ELECTRIKE },
    { 13, 13, SPECIES_PLUSLE },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_PLUSLE },
    { 13, 13, SPECIES_GULPIN },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_WINGULL },
    { 12, 12, SPECIES_MINUN },
    { 13, 13, SPECIES_MINUN },
};

const struct WildPokemonInfo Route110_SapphireRS_LandMonsInfo = { 20, Route110_SapphireRS_LandMons };
const struct WildPokemon Route110_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route110_SapphireRS_WaterMonsInfo = { 4, Route110_SapphireRS_WaterMons };
const struct WildPokemon Route110_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route110_SapphireRS_FishingMonsInfo = { 30, Route110_SapphireRS_FishingMons };

const struct WildPokemon Route111_SapphireRS_LandMons[] =
{
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 19, 19, SPECIES_CACNEA },
    { 21, 21, SPECIES_CACNEA },
    { 19, 19, SPECIES_SANDSHREW },
    { 19, 19, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_BALTOY },
    { 20, 20, SPECIES_BALTOY },
    { 22, 22, SPECIES_BALTOY },
    { 22, 22, SPECIES_BALTOY },
};

const struct WildPokemonInfo Route111_SapphireRS_LandMonsInfo = { 10, Route111_SapphireRS_LandMons };
const struct WildPokemon Route111_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route111_SapphireRS_WaterMonsInfo = { 4, Route111_SapphireRS_WaterMons };
const struct WildPokemon Route111_SapphireRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo Route111_SapphireRS_RockSmashMonsInfo = { 20, Route111_SapphireRS_RockSmashMons };
const struct WildPokemon Route111_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route111_SapphireRS_FishingMonsInfo = { 30, Route111_SapphireRS_FishingMons };

const struct WildPokemon Route112_SapphireRS_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_MACHOP },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_MACHOP },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_MACHOP },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
};

const struct WildPokemonInfo Route112_SapphireRS_LandMonsInfo = { 20, Route112_SapphireRS_LandMons };

const struct WildPokemon Route113_SapphireRS_LandMons[] =
{
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SANDSHREW },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SANDSHREW },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SANDSHREW },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
};

const struct WildPokemonInfo Route113_SapphireRS_LandMonsInfo = { 20, Route113_SapphireRS_LandMons };

const struct WildPokemon Route114_SapphireRS_LandMons[] =
{
    { 16, 16, SPECIES_SWABLU },
    { 16, 16, SPECIES_LOTAD },
    { 17, 17, SPECIES_SWABLU },
    { 15, 15, SPECIES_SWABLU },
    { 15, 15, SPECIES_LOTAD },
    { 16, 16, SPECIES_SEVIPER },
    { 16, 16, SPECIES_LOMBRE },
    { 18, 18, SPECIES_LOMBRE },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_SEVIPER },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route114_SapphireRS_LandMonsInfo = { 20, Route114_SapphireRS_LandMons };
const struct WildPokemon Route114_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route114_SapphireRS_WaterMonsInfo = { 4, Route114_SapphireRS_WaterMons };
const struct WildPokemon Route114_SapphireRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo Route114_SapphireRS_RockSmashMonsInfo = { 20, Route114_SapphireRS_RockSmashMons };
const struct WildPokemon Route114_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route114_SapphireRS_FishingMonsInfo = { 30, Route114_SapphireRS_FishingMons };

const struct WildPokemon Route115_SapphireRS_LandMons[] =
{
    { 23, 23, SPECIES_SWABLU },
    { 23, 23, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWABLU },
    { 24, 24, SPECIES_TAILLOW },
    { 25, 25, SPECIES_TAILLOW },
    { 25, 25, SPECIES_SWELLOW },
    { 24, 24, SPECIES_JIGGLYPUFF },
    { 25, 25, SPECIES_JIGGLYPUFF },
    { 24, 24, SPECIES_WINGULL },
    { 24, 24, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
};

const struct WildPokemonInfo Route115_SapphireRS_LandMonsInfo = { 20, Route115_SapphireRS_LandMons };
const struct WildPokemon Route115_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route115_SapphireRS_WaterMonsInfo = { 4, Route115_SapphireRS_WaterMons };
const struct WildPokemon Route115_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route115_SapphireRS_FishingMonsInfo = { 30, Route115_SapphireRS_FishingMons };

const struct WildPokemon Route116_SapphireRS_LandMons[] =
{
    { 6, 6, SPECIES_ZIGZAGOON },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_NINCADA },
    { 7, 7, SPECIES_WHISMUR },
    { 7, 7, SPECIES_NINCADA },
    { 6, 6, SPECIES_TAILLOW },
    { 7, 7, SPECIES_TAILLOW },
    { 8, 8, SPECIES_TAILLOW },
    { 7, 7, SPECIES_ZIGZAGOON },
    { 8, 8, SPECIES_ZIGZAGOON },
    { 7, 7, SPECIES_SKITTY },
    { 8, 8, SPECIES_SKITTY },
};

const struct WildPokemonInfo Route116_SapphireRS_LandMonsInfo = { 20, Route116_SapphireRS_LandMons };

const struct WildPokemon Route117_SapphireRS_LandMons[] =
{
    { 13, 13, SPECIES_ZIGZAGOON },
    { 13, 13, SPECIES_ROSELIA },
    { 14, 14, SPECIES_ZIGZAGOON },
    { 14, 14, SPECIES_ROSELIA },
    { 13, 13, SPECIES_MARILL },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_VOLBEAT },
    { 13, 13, SPECIES_VOLBEAT },
    { 14, 14, SPECIES_VOLBEAT },
    { 14, 14, SPECIES_VOLBEAT },
    { 13, 13, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route117_SapphireRS_LandMonsInfo = { 20, Route117_SapphireRS_LandMons };
const struct WildPokemon Route117_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route117_SapphireRS_WaterMonsInfo = { 4, Route117_SapphireRS_WaterMons };
const struct WildPokemon Route117_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_CORPHISH },
    { 25, 30, SPECIES_CORPHISH },
    { 30, 35, SPECIES_CORPHISH },
    { 20, 25, SPECIES_CORPHISH },
    { 35, 40, SPECIES_CORPHISH },
    { 40, 45, SPECIES_CORPHISH },
};

const struct WildPokemonInfo Route117_SapphireRS_FishingMonsInfo = { 30, Route117_SapphireRS_FishingMons };

const struct WildPokemon Route118_SapphireRS_LandMons[] =
{
    { 24, 24, SPECIES_ZIGZAGOON },
    { 24, 24, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_ELECTRIKE },
    { 26, 26, SPECIES_LINOONE },
    { 26, 26, SPECIES_MANECTRIC },
    { 25, 25, SPECIES_WINGULL },
    { 25, 25, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route118_SapphireRS_LandMonsInfo = { 20, Route118_SapphireRS_LandMons };
const struct WildPokemon Route118_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route118_SapphireRS_WaterMonsInfo = { 4, Route118_SapphireRS_WaterMons };
const struct WildPokemon Route118_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo Route118_SapphireRS_FishingMonsInfo = { 30, Route118_SapphireRS_FishingMons };

const struct WildPokemon Route119_SapphireRS_LandMons[] =
{
    { 25, 25, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_LINOONE },
    { 27, 27, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 24, 24, SPECIES_ODDISH },
    { 25, 25, SPECIES_TROPIUS },
    { 26, 26, SPECIES_TROPIUS },
    { 27, 27, SPECIES_TROPIUS },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route119_SapphireRS_LandMonsInfo = { 15, Route119_SapphireRS_LandMons };
const struct WildPokemon Route119_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route119_SapphireRS_WaterMonsInfo = { 4, Route119_SapphireRS_WaterMons };
const struct WildPokemon Route119_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_CARVANHA },
    { 25, 30, SPECIES_CARVANHA },
    { 30, 35, SPECIES_CARVANHA },
    { 20, 25, SPECIES_CARVANHA },
    { 35, 40, SPECIES_CARVANHA },
    { 40, 45, SPECIES_CARVANHA },
};

const struct WildPokemonInfo Route119_SapphireRS_FishingMonsInfo = { 30, Route119_SapphireRS_FishingMons };

const struct WildPokemon Route120_SapphireRS_LandMons[] =
{
    { 25, 25, SPECIES_ZIGZAGOON },
    { 25, 25, SPECIES_LINOONE },
    { 27, 27, SPECIES_LINOONE },
    { 25, 25, SPECIES_ODDISH },
    { 25, 25, SPECIES_MARILL },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 27, 27, SPECIES_MARILL },
    { 25, 25, SPECIES_ABSOL },
    { 27, 27, SPECIES_ABSOL },
    { 25, 25, SPECIES_KECLEON },
    { 25, 25, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route120_SapphireRS_LandMonsInfo = { 20, Route120_SapphireRS_LandMons };
const struct WildPokemon Route120_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_SURSKIT },
};

const struct WildPokemonInfo Route120_SapphireRS_WaterMonsInfo = { 4, Route120_SapphireRS_WaterMons };
const struct WildPokemon Route120_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_BARBOACH },
    { 25, 30, SPECIES_BARBOACH },
    { 30, 35, SPECIES_BARBOACH },
    { 20, 25, SPECIES_BARBOACH },
    { 35, 40, SPECIES_BARBOACH },
    { 40, 45, SPECIES_BARBOACH },
};

const struct WildPokemonInfo Route120_SapphireRS_FishingMonsInfo = { 30, Route120_SapphireRS_FishingMons };

const struct WildPokemon Route121_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_LINOONE },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route121_SapphireRS_LandMonsInfo = { 20, Route121_SapphireRS_LandMons };
const struct WildPokemon Route121_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route121_SapphireRS_WaterMonsInfo = { 4, Route121_SapphireRS_WaterMons };
const struct WildPokemon Route121_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route121_SapphireRS_FishingMonsInfo = { 30, Route121_SapphireRS_FishingMons };

const struct WildPokemon Route122_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route122_SapphireRS_WaterMonsInfo = { 4, Route122_SapphireRS_WaterMons };
const struct WildPokemon Route122_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route122_SapphireRS_FishingMonsInfo = { 30, Route122_SapphireRS_FishingMons };

const struct WildPokemon Route123_SapphireRS_LandMons[] =
{
    { 26, 26, SPECIES_ZIGZAGOON },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_LINOONE },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_LINOONE },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo Route123_SapphireRS_LandMonsInfo = { 20, Route123_SapphireRS_LandMons };
const struct WildPokemon Route123_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route123_SapphireRS_WaterMonsInfo = { 4, Route123_SapphireRS_WaterMons };
const struct WildPokemon Route123_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route123_SapphireRS_FishingMonsInfo = { 30, Route123_SapphireRS_FishingMons };

const struct WildPokemon Route124_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route124_SapphireRS_WaterMonsInfo = { 4, Route124_SapphireRS_WaterMons };
const struct WildPokemon Route124_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route124_SapphireRS_FishingMonsInfo = { 30, Route124_SapphireRS_FishingMons };

const struct WildPokemon Route125_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route125_SapphireRS_WaterMonsInfo = { 4, Route125_SapphireRS_WaterMons };
const struct WildPokemon Route125_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route125_SapphireRS_FishingMonsInfo = { 30, Route125_SapphireRS_FishingMons };

const struct WildPokemon Route126_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route126_SapphireRS_WaterMonsInfo = { 4, Route126_SapphireRS_WaterMons };
const struct WildPokemon Route126_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route126_SapphireRS_FishingMonsInfo = { 30, Route126_SapphireRS_FishingMons };

const struct WildPokemon Route127_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route127_SapphireRS_WaterMonsInfo = { 4, Route127_SapphireRS_WaterMons };
const struct WildPokemon Route127_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route127_SapphireRS_FishingMonsInfo = { 30, Route127_SapphireRS_FishingMons };

const struct WildPokemon Route128_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route128_SapphireRS_WaterMonsInfo = { 4, Route128_SapphireRS_WaterMons };
const struct WildPokemon Route128_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_LUVDISC },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_LUVDISC },
    { 30, 35, SPECIES_WAILMER },
    { 30, 35, SPECIES_CORSOLA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route128_SapphireRS_FishingMonsInfo = { 30, Route128_SapphireRS_FishingMons };

const struct WildPokemon Route129_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_WAILORD },
};

const struct WildPokemonInfo Route129_SapphireRS_WaterMonsInfo = { 4, Route129_SapphireRS_WaterMons };
const struct WildPokemon Route129_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route129_SapphireRS_FishingMonsInfo = { 30, Route129_SapphireRS_FishingMons };

const struct WildPokemon Route130_SapphireRS_LandMons[] =
{
    { 30, 30, SPECIES_WYNAUT },
    { 35, 35, SPECIES_WYNAUT },
    { 25, 25, SPECIES_WYNAUT },
    { 40, 40, SPECIES_WYNAUT },
    { 20, 20, SPECIES_WYNAUT },
    { 45, 45, SPECIES_WYNAUT },
    { 15, 15, SPECIES_WYNAUT },
    { 50, 50, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
    { 10, 10, SPECIES_WYNAUT },
    { 5, 5, SPECIES_WYNAUT },
};

const struct WildPokemonInfo Route130_SapphireRS_LandMonsInfo = { 20, Route130_SapphireRS_LandMons };
const struct WildPokemon Route130_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route130_SapphireRS_WaterMonsInfo = { 4, Route130_SapphireRS_WaterMons };
const struct WildPokemon Route130_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route130_SapphireRS_FishingMonsInfo = { 30, Route130_SapphireRS_FishingMons };

const struct WildPokemon Route131_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route131_SapphireRS_WaterMonsInfo = { 4, Route131_SapphireRS_WaterMons };
const struct WildPokemon Route131_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route131_SapphireRS_FishingMonsInfo = { 30, Route131_SapphireRS_FishingMons };

const struct WildPokemon Route132_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route132_SapphireRS_WaterMonsInfo = { 4, Route132_SapphireRS_WaterMons };
const struct WildPokemon Route132_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route132_SapphireRS_FishingMonsInfo = { 30, Route132_SapphireRS_FishingMons };

const struct WildPokemon Route133_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route133_SapphireRS_WaterMonsInfo = { 4, Route133_SapphireRS_WaterMons };
const struct WildPokemon Route133_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route133_SapphireRS_FishingMonsInfo = { 30, Route133_SapphireRS_FishingMons };

const struct WildPokemon Route134_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo Route134_SapphireRS_WaterMonsInfo = { 4, Route134_SapphireRS_WaterMons };
const struct WildPokemon Route134_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_HORSEA },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo Route134_SapphireRS_FishingMonsInfo = { 30, Route134_SapphireRS_FishingMons };

const struct WildPokemon SafariZone_Northwest_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_RHYHORN },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_RHYHORN },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_DODUO },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_DODUO },
    { 29, 29, SPECIES_DODRIO },
    { 27, 27, SPECIES_PINSIR },
    { 31, 31, SPECIES_DODRIO },
    { 29, 29, SPECIES_PINSIR },
};

const struct WildPokemonInfo SafariZone_Northwest_SapphireRS_LandMonsInfo = { 25, SafariZone_Northwest_SapphireRS_LandMons };
const struct WildPokemon SafariZone_Northwest_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_GOLDUCK },
    { 25, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo SafariZone_Northwest_SapphireRS_WaterMonsInfo = { 9, SafariZone_Northwest_SapphireRS_WaterMons };
const struct WildPokemon SafariZone_Northwest_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo SafariZone_Northwest_SapphireRS_FishingMonsInfo = { 35, SafariZone_Northwest_SapphireRS_FishingMons };

const struct WildPokemon SafariZone_Northeast_SapphireRS_LandMons[] =
{
    { 27, 27, SPECIES_PHANPY },
    { 27, 27, SPECIES_ODDISH },
    { 29, 29, SPECIES_PHANPY },
    { 29, 29, SPECIES_ODDISH },
    { 27, 27, SPECIES_NATU },
    { 29, 29, SPECIES_GLOOM },
    { 31, 31, SPECIES_GLOOM },
    { 29, 29, SPECIES_NATU },
    { 29, 29, SPECIES_XATU },
    { 27, 27, SPECIES_HERACROSS },
    { 31, 31, SPECIES_XATU },
    { 29, 29, SPECIES_HERACROSS },
};

const struct WildPokemonInfo SafariZone_Northeast_SapphireRS_LandMonsInfo = { 25, SafariZone_Northeast_SapphireRS_LandMons };
const struct WildPokemon SafariZone_Northeast_SapphireRS_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 20, 25, SPECIES_GEODUDE },
    { 25, 30, SPECIES_GEODUDE },
};

const struct WildPokemonInfo SafariZone_Northeast_SapphireRS_RockSmashMonsInfo = { 25, SafariZone_Northeast_SapphireRS_RockSmashMons };

const struct WildPokemon SafariZone_Southwest_SapphireRS_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 27, 27, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo SafariZone_Southwest_SapphireRS_LandMonsInfo = { 25, SafariZone_Southwest_SapphireRS_LandMons };
const struct WildPokemon SafariZone_Southwest_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo SafariZone_Southwest_SapphireRS_WaterMonsInfo = { 9, SafariZone_Southwest_SapphireRS_WaterMons };
const struct WildPokemon SafariZone_Southwest_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 25, SPECIES_GOLDEEN },
    { 10, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_SEAKING },
    { 35, 40, SPECIES_SEAKING },
    { 25, 30, SPECIES_SEAKING },
};

const struct WildPokemonInfo SafariZone_Southwest_SapphireRS_FishingMonsInfo = { 35, SafariZone_Southwest_SapphireRS_FishingMons };

const struct WildPokemon SafariZone_Southeast_SapphireRS_LandMons[] =
{
    { 25, 25, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 25, 25, SPECIES_GIRAFARIG },
    { 27, 27, SPECIES_GIRAFARIG },
    { 25, 25, SPECIES_NATU },
    { 25, 25, SPECIES_DODUO },
    { 25, 25, SPECIES_GLOOM },
    { 27, 27, SPECIES_WOBBUFFET },
    { 25, 25, SPECIES_PIKACHU },
    { 27, 27, SPECIES_WOBBUFFET },
    { 27, 27, SPECIES_PIKACHU },
    { 29, 29, SPECIES_WOBBUFFET },
};

const struct WildPokemonInfo SafariZone_Southeast_SapphireRS_LandMonsInfo = { 25, SafariZone_Southeast_SapphireRS_LandMons };

const struct WildPokemon DewfordTown_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo DewfordTown_SapphireRS_WaterMonsInfo = { 4, DewfordTown_SapphireRS_WaterMons };
const struct WildPokemon DewfordTown_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_WAILMER },
    { 20, 25, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo DewfordTown_SapphireRS_FishingMonsInfo = { 10, DewfordTown_SapphireRS_FishingMons };

const struct WildPokemon PacifidlogTown_SapphireRS_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo PacifidlogTown_SapphireRS_WaterMonsInfo = { 4, PacifidlogTown_SapphireRS_WaterMons };
const struct WildPokemon PacifidlogTown_SapphireRS_FishingMons[] =
{
    { 5, 10, SPECIES_MAGIKARP },
    { 5, 10, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WAILMER },
    { 30, 35, SPECIES_SHARPEDO },
    { 30, 35, SPECIES_WAILMER },
    { 25, 30, SPECIES_WAILMER },
    { 35, 40, SPECIES_WAILMER },
    { 40, 45, SPECIES_WAILMER },
};

const struct WildPokemonInfo PacifidlogTown_SapphireRS_FishingMonsInfo = { 10, PacifidlogTown_SapphireRS_FishingMons };

const struct WildPokemon Underwater1_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo Underwater1_SapphireRS_WaterMonsInfo = { 4, Underwater1_SapphireRS_WaterMons };

const struct WildPokemon Underwater2_SapphireRS_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo Underwater2_SapphireRS_WaterMonsInfo = { 4, Underwater2_SapphireRS_WaterMons };


const struct WildPokemonHeader gWildMonHeadersRS[] =
{
    {
                .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &PetalburgCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PetalburgCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SlateportCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SlateportCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &LilycoveCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &MossdeepCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MossdeepCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SootopolisCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SootopolisCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &EverGrandeCity_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &EverGrandeCity_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
                .landMonsInfo = &MeteorFalls_1F_1R_RubyRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_1F_1R_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_1F_1R_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
                .landMonsInfo = &MeteorFalls_1F_2R_RubyRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_1F_2R_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_1F_2R_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
                .landMonsInfo = &MeteorFalls_B1F_1R_RubyRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_B1F_1R_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_B1F_1R_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
                .landMonsInfo = &MeteorFalls_B1F_2R_RubyRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_B1F_2R_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_B1F_2R_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
                .landMonsInfo = &RusturfTunnel_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
                .landMonsInfo = &GraniteCave_1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
                .landMonsInfo = &GraniteCave_B1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
                .landMonsInfo = &GraniteCave_B2F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B2F_RubyRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
                .landMonsInfo = &GraniteCave_StevensRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
                .landMonsInfo = &PetalburgWoods_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
                .landMonsInfo = &JaggedPass_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
                .landMonsInfo = &FieryPath_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
                .landMonsInfo = &MtPyre_1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
                .landMonsInfo = &MtPyre_2F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
                .landMonsInfo = &MtPyre_3F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
                .landMonsInfo = &MtPyre_4F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
                .landMonsInfo = &MtPyre_5F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
                .landMonsInfo = &MtPyre_6F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
                .landMonsInfo = &MtPyre_Exterior_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
                .landMonsInfo = &MtPyre_Summit_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SeafloorCavern_Entrance_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Entrance_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
                .landMonsInfo = &SeafloorCavern_Room1_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
                .landMonsInfo = &SeafloorCavern_Room2_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
                .landMonsInfo = &SeafloorCavern_Room3_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
                .landMonsInfo = &SeafloorCavern_Room4_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
                .landMonsInfo = &SeafloorCavern_Room5_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
                .landMonsInfo = &SeafloorCavern_Room6_RubyRS_LandMonsInfo,
        .waterMonsInfo = &SeafloorCavern_Room6_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Room6_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
                .landMonsInfo = &SeafloorCavern_Room7_RubyRS_LandMonsInfo,
        .waterMonsInfo = &SeafloorCavern_Room7_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Room7_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
                .landMonsInfo = &SeafloorCavern_Room8_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
                .landMonsInfo = &CaveOfOrigin_Entrance_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
                .landMonsInfo = &CaveOfOrigin_1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
                .landMonsInfo = &CaveOfOrigin_B1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
                .landMonsInfo = &CaveOfOrigin_B2F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
                .landMonsInfo = &CaveOfOrigin_B3F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
                .landMonsInfo = &VictoryRoad_1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
                .landMonsInfo = &VictoryRoad_B1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &VictoryRoad_B1F_RubyRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
                .landMonsInfo = &VictoryRoad_B2F_RubyRS_LandMonsInfo,
        .waterMonsInfo = &VictoryRoad_B2F_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &VictoryRoad_B2F_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
                .landMonsInfo = &ShoalCave_LowTideEntranceRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = &ShoalCave_LowTideEntranceRoom_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &ShoalCave_LowTideEntranceRoom_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
                .landMonsInfo = &ShoalCave_LowTideInnerRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = &ShoalCave_LowTideInnerRoom_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &ShoalCave_LowTideInnerRoom_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
                .landMonsInfo = &ShoalCave_LowTideStairsRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
                .landMonsInfo = &ShoalCave_LowTideLowerRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
                .landMonsInfo = &ShoalCave_LowTideIceRoom_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
                .landMonsInfo = &NewMauville_Entrance_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
                .landMonsInfo = &NewMauville_Inside_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
                .landMonsInfo = NULL,
        .waterMonsInfo = &AbandonedShip_Rooms_B1F_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &AbandonedShip_Rooms_B1F_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
                .landMonsInfo = NULL,
        .waterMonsInfo = &AbandonedShip_HiddenFloorCorridors_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &AbandonedShip_HiddenFloorCorridors_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
                .landMonsInfo = &SkyPillar_1F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
                .landMonsInfo = &SkyPillar_3F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
                .landMonsInfo = &SkyPillar_5F_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
                .landMonsInfo = &Route101_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
                .landMonsInfo = &Route102_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route102_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route102_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
                .landMonsInfo = &Route103_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route103_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route103_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
                .landMonsInfo = &Route104_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route104_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route104_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route105_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route105_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route106_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route106_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route107_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route107_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route108_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route108_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route109_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route109_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
                .landMonsInfo = &Route110_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route110_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route110_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
                .landMonsInfo = &Route111_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route111_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = &Route111_RubyRS_RockSmashMonsInfo,
        .fishingMonsInfo = &Route111_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
                .landMonsInfo = &Route112_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
                .landMonsInfo = &Route113_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
                .landMonsInfo = &Route114_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route114_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = &Route114_RubyRS_RockSmashMonsInfo,
        .fishingMonsInfo = &Route114_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
                .landMonsInfo = &Route115_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route115_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route115_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
                .landMonsInfo = &Route116_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
                .landMonsInfo = &Route117_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route117_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route117_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
                .landMonsInfo = &Route118_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route118_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route118_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
                .landMonsInfo = &Route119_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route119_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route119_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
                .landMonsInfo = &Route120_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route120_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route120_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
                .landMonsInfo = &Route121_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route121_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route121_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route122_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route122_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
                .landMonsInfo = &Route123_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route123_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route123_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route124_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route124_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route125_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route125_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route126_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route126_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route127_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route127_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route128_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route128_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route129_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route129_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
                .landMonsInfo = &Route130_RubyRS_LandMonsInfo,
        .waterMonsInfo = &Route130_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route130_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route131_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route131_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route132_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route132_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route133_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route133_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route134_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route134_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
                .landMonsInfo = &SafariZone_Northwest_RubyRS_LandMonsInfo,
        .waterMonsInfo = &SafariZone_Northwest_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_Northwest_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
                .landMonsInfo = &SafariZone_Northeast_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &SafariZone_Northeast_RubyRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
                .landMonsInfo = &SafariZone_Southwest_RubyRS_LandMonsInfo,
        .waterMonsInfo = &SafariZone_Southwest_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_Southwest_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
                .landMonsInfo = &SafariZone_Southeast_RubyRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
                .landMonsInfo = NULL,
        .waterMonsInfo = &DewfordTown_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordTown_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
                .landMonsInfo = NULL,
        .waterMonsInfo = &PacifidlogTown_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogTown_RubyRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(UNDERWATER_ROUTE124),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE124),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Underwater1_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(UNDERWATER_ROUTE126),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE126),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Underwater2_RubyRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &PetalburgCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PetalburgCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SlateportCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SlateportCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &LilycoveCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &LilycoveCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &MossdeepCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MossdeepCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SootopolisCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SootopolisCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
                .landMonsInfo = NULL,
        .waterMonsInfo = &EverGrandeCity_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &EverGrandeCity_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
                .landMonsInfo = &MeteorFalls_1F_1R_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_1F_1R_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_1F_1R_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
                .landMonsInfo = &MeteorFalls_1F_2R_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_1F_2R_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_1F_2R_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
                .landMonsInfo = &MeteorFalls_B1F_1R_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_B1F_1R_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_B1F_1R_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
                .landMonsInfo = &MeteorFalls_B1F_2R_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &MeteorFalls_B1F_2R_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &MeteorFalls_B1F_2R_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
                .landMonsInfo = &RusturfTunnel_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
                .landMonsInfo = &GraniteCave_1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
                .landMonsInfo = &GraniteCave_B1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
                .landMonsInfo = &GraniteCave_B2F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &GraniteCave_B2F_SapphireRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
                .landMonsInfo = &GraniteCave_StevensRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
                .landMonsInfo = &PetalburgWoods_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
                .landMonsInfo = &JaggedPass_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
                .landMonsInfo = &FieryPath_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
                .landMonsInfo = &MtPyre_1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
                .landMonsInfo = &MtPyre_2F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
                .landMonsInfo = &MtPyre_3F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
                .landMonsInfo = &MtPyre_4F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
                .landMonsInfo = &MtPyre_5F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
                .landMonsInfo = &MtPyre_6F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
                .landMonsInfo = &MtPyre_Exterior_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
                .landMonsInfo = &MtPyre_Summit_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
                .landMonsInfo = NULL,
        .waterMonsInfo = &SeafloorCavern_Entrance_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Entrance_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
                .landMonsInfo = &SeafloorCavern_Room1_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
                .landMonsInfo = &SeafloorCavern_Room2_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
                .landMonsInfo = &SeafloorCavern_Room3_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
                .landMonsInfo = &SeafloorCavern_Room4_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
                .landMonsInfo = &SeafloorCavern_Room5_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
                .landMonsInfo = &SeafloorCavern_Room6_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &SeafloorCavern_Room6_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Room6_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
                .landMonsInfo = &SeafloorCavern_Room7_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &SeafloorCavern_Room7_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SeafloorCavern_Room7_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
                .landMonsInfo = &SeafloorCavern_Room8_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
                .landMonsInfo = &CaveOfOrigin_Entrance_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
                .landMonsInfo = &CaveOfOrigin_1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
                .landMonsInfo = &CaveOfOrigin_B1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
                .landMonsInfo = &CaveOfOrigin_B2F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
                .landMonsInfo = &CaveOfOrigin_B3F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
                .landMonsInfo = &VictoryRoad_1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
                .landMonsInfo = &VictoryRoad_B1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &VictoryRoad_B1F_SapphireRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
                .landMonsInfo = &VictoryRoad_B2F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &VictoryRoad_B2F_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &VictoryRoad_B2F_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
                .landMonsInfo = &ShoalCave_LowTideEntranceRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &ShoalCave_LowTideEntranceRoom_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &ShoalCave_LowTideEntranceRoom_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
                .landMonsInfo = &ShoalCave_LowTideInnerRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &ShoalCave_LowTideInnerRoom_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &ShoalCave_LowTideInnerRoom_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
                .landMonsInfo = &ShoalCave_LowTideStairsRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
                .landMonsInfo = &ShoalCave_LowTideLowerRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
                .landMonsInfo = &ShoalCave_LowTideIceRoom_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
                .landMonsInfo = &NewMauville_Entrance_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
                .landMonsInfo = &NewMauville_Inside_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
                .landMonsInfo = NULL,
        .waterMonsInfo = &AbandonedShip_Rooms_B1F_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &AbandonedShip_Rooms_B1F_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
                .landMonsInfo = NULL,
        .waterMonsInfo = &AbandonedShip_HiddenFloorCorridors_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &AbandonedShip_HiddenFloorCorridors_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
                .landMonsInfo = &SkyPillar_1F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
                .landMonsInfo = &SkyPillar_3F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
                .landMonsInfo = &SkyPillar_5F_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
                .landMonsInfo = &Route101_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
                .landMonsInfo = &Route102_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route102_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route102_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
                .landMonsInfo = &Route103_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route103_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route103_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
                .landMonsInfo = &Route104_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route104_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route104_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route105_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route105_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route106_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route106_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route107_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route107_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route108_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route108_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route109_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route109_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
                .landMonsInfo = &Route110_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route110_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route110_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
                .landMonsInfo = &Route111_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route111_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = &Route111_SapphireRS_RockSmashMonsInfo,
        .fishingMonsInfo = &Route111_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
                .landMonsInfo = &Route112_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
                .landMonsInfo = &Route113_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
                .landMonsInfo = &Route114_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route114_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = &Route114_SapphireRS_RockSmashMonsInfo,
        .fishingMonsInfo = &Route114_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
                .landMonsInfo = &Route115_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route115_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route115_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
                .landMonsInfo = &Route116_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
                .landMonsInfo = &Route117_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route117_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route117_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
                .landMonsInfo = &Route118_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route118_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route118_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
                .landMonsInfo = &Route119_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route119_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route119_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
                .landMonsInfo = &Route120_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route120_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route120_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
                .landMonsInfo = &Route121_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route121_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route121_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route122_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route122_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
                .landMonsInfo = &Route123_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route123_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route123_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route124_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route124_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route125_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route125_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route126_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route126_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route127_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route127_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route128_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route128_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route129_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route129_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
                .landMonsInfo = &Route130_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &Route130_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route130_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route131_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route131_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route132_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route132_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route133_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route133_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Route134_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &Route134_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
                .landMonsInfo = &SafariZone_Northwest_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &SafariZone_Northwest_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_Northwest_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
                .landMonsInfo = &SafariZone_Northeast_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &SafariZone_Northeast_SapphireRS_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
                .landMonsInfo = &SafariZone_Southwest_SapphireRS_LandMonsInfo,
        .waterMonsInfo = &SafariZone_Southwest_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &SafariZone_Southwest_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
                .landMonsInfo = &SafariZone_Southeast_SapphireRS_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
                .landMonsInfo = NULL,
        .waterMonsInfo = &DewfordTown_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &DewfordTown_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
                .landMonsInfo = NULL,
        .waterMonsInfo = &PacifidlogTown_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &PacifidlogTown_SapphireRS_FishingMonsInfo,
    },
    {
                .mapGroup = MAP_GROUP(UNDERWATER_ROUTE124),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE124),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Underwater1_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
                .mapGroup = MAP_GROUP(UNDERWATER_ROUTE126),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE126),
                .landMonsInfo = NULL,
        .waterMonsInfo = &Underwater2_SapphireRS_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};
