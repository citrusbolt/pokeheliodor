//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/wild_encounters_e.json and Inja template src/data/wild_encounters_e.json.txt
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



const struct WildPokemon gRoute101E_LandMons[] =
{
    { 2, 2, SPECIES_WURMPLE },
    { 2, 2, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_WURMPLE },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WURMPLE },
    { 3, 3, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 2, 2, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
};

const struct WildPokemonInfo gRoute101E_LandMonsInfo = { 20, gRoute101E_LandMons };
const struct WildPokemon gRoute102E_LandMons[] =
{
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_WURMPLE },
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_WURMPLE },
    { 3, 3, SPECIES_LOTAD },
    { 4, 4, SPECIES_LOTAD },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_RALTS },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute102E_LandMonsInfo = { 20, gRoute102E_LandMons };
const struct WildPokemon gRoute102E_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute102E_WaterMonsInfo = { 4, gRoute102E_WaterMons };
const struct WildPokemon gRoute102E_FishingMons[] =
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

const struct WildPokemonInfo gRoute102E_FishingMonsInfo = { 30, gRoute102E_FishingMons };
const struct WildPokemon gRoute103E_LandMons[] =
{
    { 2, 2, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 3, 3, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_POOCHYENA },
    { 2, 2, SPECIES_WINGULL },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_ZIGZAGOON },
    { 4, 4, SPECIES_ZIGZAGOON },
    { 3, 3, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 2, 2, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
};

const struct WildPokemonInfo gRoute103E_LandMonsInfo = { 20, gRoute103E_LandMons };
const struct WildPokemon gRoute103E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute103E_WaterMonsInfo = { 4, gRoute103E_WaterMons };
const struct WildPokemon gRoute103E_FishingMons[] =
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

const struct WildPokemonInfo gRoute103E_FishingMonsInfo = { 30, gRoute103E_FishingMons };
const struct WildPokemon gRoute104E_LandMons[] =
{
    { 4, 4, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_WURMPLE },
    { 5, 5, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_MARILL },
    { 4, 4, SPECIES_MARILL },
    { 5, 5, SPECIES_POOCHYENA },
    { 4, 4, SPECIES_TAILLOW },
    { 5, 5, SPECIES_TAILLOW },
    { 4, 4, SPECIES_WINGULL },
    { 4, 4, SPECIES_WINGULL },
    { 3, 3, SPECIES_WINGULL },
    { 5, 5, SPECIES_WINGULL },
};

const struct WildPokemonInfo gRoute104E_LandMonsInfo = { 20, gRoute104E_LandMons };
const struct WildPokemon gRoute104E_WaterMons[] =
{
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute104E_WaterMonsInfo = { 4, gRoute104E_WaterMons };
const struct WildPokemon gRoute104E_FishingMons[] =
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

const struct WildPokemonInfo gRoute104E_FishingMonsInfo = { 30, gRoute104E_FishingMons };
const struct WildPokemon gRoute105E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute105E_WaterMonsInfo = { 4, gRoute105E_WaterMons };
const struct WildPokemon gRoute105E_FishingMons[] =
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

const struct WildPokemonInfo gRoute105E_FishingMonsInfo = { 30, gRoute105E_FishingMons };
const struct WildPokemon gRoute110E_LandMons[] =
{
    { 12, 12, SPECIES_POOCHYENA },
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

const struct WildPokemonInfo gRoute110E_LandMonsInfo = { 20, gRoute110E_LandMons };
const struct WildPokemon gRoute110E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute110E_WaterMonsInfo = { 4, gRoute110E_WaterMons };
const struct WildPokemon gRoute110E_FishingMons[] =
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

const struct WildPokemonInfo gRoute110E_FishingMonsInfo = { 30, gRoute110E_FishingMons };
const struct WildPokemon gRoute111E_LandMons[] =
{
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 19, 19, SPECIES_BALTOY },
    { 21, 21, SPECIES_BALTOY },
    { 19, 19, SPECIES_SANDSHREW },
    { 19, 19, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_BALTOY },
    { 20, 20, SPECIES_CACNEA },
    { 22, 22, SPECIES_CACNEA },
    { 22, 22, SPECIES_CACNEA },
};

const struct WildPokemonInfo gRoute111E_LandMonsInfo = { 10, gRoute111E_LandMons };
const struct WildPokemon gRoute111E_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute111E_WaterMonsInfo = { 4, gRoute111E_WaterMons };
const struct WildPokemon gRoute111E_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute111E_RockSmashMonsInfo = { 20, gRoute111E_RockSmashMons };
const struct WildPokemon gRoute111E_FishingMons[] =
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

const struct WildPokemonInfo gRoute111E_FishingMonsInfo = { 30, gRoute111E_FishingMons };
const struct WildPokemon gRoute112E_LandMons[] =
{
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_NUMEL },
    { 15, 15, SPECIES_MARILL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_NUMEL },
    { 14, 14, SPECIES_MARILL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_MARILL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
    { 16, 16, SPECIES_NUMEL },
};

const struct WildPokemonInfo gRoute112E_LandMonsInfo = { 20, gRoute112E_LandMons };
const struct WildPokemon gRoute113E_LandMons[] =
{
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SPINDA },
    { 15, 15, SPECIES_SLUGMA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SPINDA },
    { 14, 14, SPECIES_SLUGMA },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SLUGMA },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
    { 16, 16, SPECIES_SPINDA },
    { 16, 16, SPECIES_SKARMORY },
};

const struct WildPokemonInfo gRoute113E_LandMonsInfo = { 20, gRoute113E_LandMons };
const struct WildPokemon gRoute114E_LandMons[] =
{
    { 16, 16, SPECIES_SWABLU },
    { 16, 16, SPECIES_LOTAD },
    { 17, 17, SPECIES_SWABLU },
    { 15, 15, SPECIES_SWABLU },
    { 15, 15, SPECIES_LOTAD },
    { 16, 16, SPECIES_LOMBRE },
    { 16, 16, SPECIES_LOMBRE },
    { 18, 18, SPECIES_LOMBRE },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_SEVIPER },
    { 17, 17, SPECIES_SEVIPER },
    { 15, 15, SPECIES_NUZLEAF },
};

const struct WildPokemonInfo gRoute114E_LandMonsInfo = { 20, gRoute114E_LandMons };
const struct WildPokemon gRoute114E_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute114E_WaterMonsInfo = { 4, gRoute114E_WaterMons };
const struct WildPokemon gRoute114E_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gRoute114E_RockSmashMonsInfo = { 20, gRoute114E_RockSmashMons };
const struct WildPokemon gRoute114E_FishingMons[] =
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

const struct WildPokemonInfo gRoute114E_FishingMonsInfo = { 30, gRoute114E_FishingMons };
const struct WildPokemon gRoute116E_LandMons[] =
{
    { 6, 6, SPECIES_POOCHYENA },
    { 6, 6, SPECIES_WHISMUR },
    { 6, 6, SPECIES_NINCADA },
    { 7, 7, SPECIES_ABRA },
    { 7, 7, SPECIES_NINCADA },
    { 6, 6, SPECIES_TAILLOW },
    { 7, 7, SPECIES_TAILLOW },
    { 8, 8, SPECIES_TAILLOW },
    { 7, 7, SPECIES_POOCHYENA },
    { 8, 8, SPECIES_POOCHYENA },
    { 7, 7, SPECIES_SKITTY },
    { 8, 8, SPECIES_SKITTY },
};

const struct WildPokemonInfo gRoute116E_LandMonsInfo = { 20, gRoute116E_LandMons };
const struct WildPokemon gRoute117E_LandMons[] =
{
    { 13, 13, SPECIES_POOCHYENA },
    { 13, 13, SPECIES_ODDISH },
    { 14, 14, SPECIES_POOCHYENA },
    { 14, 14, SPECIES_ODDISH },
    { 13, 13, SPECIES_MARILL },
    { 13, 13, SPECIES_ODDISH },
    { 13, 13, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 14, 14, SPECIES_ILLUMISE },
    { 13, 13, SPECIES_VOLBEAT },
    { 13, 13, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute117E_LandMonsInfo = { 20, gRoute117E_LandMons };
const struct WildPokemon gRoute117E_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute117E_WaterMonsInfo = { 4, gRoute117E_WaterMons };
const struct WildPokemon gRoute117E_FishingMons[] =
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

const struct WildPokemonInfo gRoute117E_FishingMonsInfo = { 30, gRoute117E_FishingMons };
const struct WildPokemon gRoute118E_LandMons[] =
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

const struct WildPokemonInfo gRoute118E_LandMonsInfo = { 20, gRoute118E_LandMons };
const struct WildPokemon gRoute118E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute118E_WaterMonsInfo = { 4, gRoute118E_WaterMons };
const struct WildPokemon gRoute118E_FishingMons[] =
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

const struct WildPokemonInfo gRoute118E_FishingMonsInfo = { 30, gRoute118E_FishingMons };
const struct WildPokemon gRoute124E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute124E_WaterMonsInfo = { 4, gRoute124E_WaterMons };
const struct WildPokemon gRoute124E_FishingMons[] =
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

const struct WildPokemonInfo gRoute124E_FishingMonsInfo = { 30, gRoute124E_FishingMons };
const struct WildPokemon gPetalburgWoodsE_LandMons[] =
{
    { 5, 5, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_WURMPLE },
    { 5, 5, SPECIES_SHROOMISH },
    { 6, 6, SPECIES_POOCHYENA },
    { 5, 5, SPECIES_SILCOON },
    { 5, 5, SPECIES_CASCOON },
    { 6, 6, SPECIES_WURMPLE },
    { 6, 6, SPECIES_SHROOMISH },
    { 5, 5, SPECIES_TAILLOW },
    { 5, 5, SPECIES_SLAKOTH },
    { 6, 6, SPECIES_TAILLOW },
    { 6, 6, SPECIES_SLAKOTH },
};

const struct WildPokemonInfo gPetalburgWoodsE_LandMonsInfo = { 20, gPetalburgWoodsE_LandMons };
const struct WildPokemon gRusturfTunnelE_LandMons[] =
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

const struct WildPokemonInfo gRusturfTunnelE_LandMonsInfo = { 10, gRusturfTunnelE_LandMons };
const struct WildPokemon gGraniteCave_1FE_LandMons[] =
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

const struct WildPokemonInfo gGraniteCave_1FE_LandMonsInfo = { 10, gGraniteCave_1FE_LandMons };
const struct WildPokemon gGraniteCave_B1FE_LandMons[] =
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

const struct WildPokemonInfo gGraniteCave_B1FE_LandMonsInfo = { 10, gGraniteCave_B1FE_LandMons };
const struct WildPokemon gMtPyre_1FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_1FE_LandMonsInfo = { 10, gMtPyre_1FE_LandMons };
const struct WildPokemon gVictoryRoad_1FE_LandMons[] =
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

const struct WildPokemonInfo gVictoryRoad_1FE_LandMonsInfo = { 10, gVictoryRoad_1FE_LandMons };
const struct WildPokemon gSafariZone_SouthE_LandMons[] =
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

const struct WildPokemonInfo gSafariZone_SouthE_LandMonsInfo = { 25, gSafariZone_SouthE_LandMons };
const struct WildPokemon gUnderwater_Route126E_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo gUnderwater_Route126E_WaterMonsInfo = { 4, gUnderwater_Route126E_WaterMons };
const struct WildPokemon gAbandonedShip_Rooms_B1FE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1FE_WaterMonsInfo = { 4, gAbandonedShip_Rooms_B1FE_WaterMons };
const struct WildPokemon gAbandonedShip_Rooms_B1FE_FishingMons[] =
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

const struct WildPokemonInfo gAbandonedShip_Rooms_B1FE_FishingMonsInfo = { 20, gAbandonedShip_Rooms_B1FE_FishingMons };
const struct WildPokemon gGraniteCave_B2FE_LandMons[] =
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

const struct WildPokemonInfo gGraniteCave_B2FE_LandMonsInfo = { 10, gGraniteCave_B2FE_LandMons };
const struct WildPokemon gGraniteCave_B2FE_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 10, 20, SPECIES_NOSEPASS },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gGraniteCave_B2FE_RockSmashMonsInfo = { 20, gGraniteCave_B2FE_RockSmashMons };
const struct WildPokemon gFieryPathE_LandMons[] =
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

const struct WildPokemonInfo gFieryPathE_LandMonsInfo = { 10, gFieryPathE_LandMons };
const struct WildPokemon gMeteorFalls_B1F_2RE_LandMons[] =
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

const struct WildPokemonInfo gMeteorFalls_B1F_2RE_LandMonsInfo = { 10, gMeteorFalls_B1F_2RE_LandMons };
const struct WildPokemon gMeteorFalls_B1F_2RE_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_2RE_WaterMonsInfo = { 4, gMeteorFalls_B1F_2RE_WaterMons };
const struct WildPokemon gMeteorFalls_B1F_2RE_FishingMons[] =
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

const struct WildPokemonInfo gMeteorFalls_B1F_2RE_FishingMonsInfo = { 30, gMeteorFalls_B1F_2RE_FishingMons };
const struct WildPokemon gJaggedPassE_LandMons[] =
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

const struct WildPokemonInfo gJaggedPassE_LandMonsInfo = { 20, gJaggedPassE_LandMons };
const struct WildPokemon gRoute106E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute106E_WaterMonsInfo = { 4, gRoute106E_WaterMons };
const struct WildPokemon gRoute106E_FishingMons[] =
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

const struct WildPokemonInfo gRoute106E_FishingMonsInfo = { 30, gRoute106E_FishingMons };
const struct WildPokemon gRoute107E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute107E_WaterMonsInfo = { 4, gRoute107E_WaterMons };
const struct WildPokemon gRoute107E_FishingMons[] =
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

const struct WildPokemonInfo gRoute107E_FishingMonsInfo = { 30, gRoute107E_FishingMons };
const struct WildPokemon gRoute108E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute108E_WaterMonsInfo = { 4, gRoute108E_WaterMons };
const struct WildPokemon gRoute108E_FishingMons[] =
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

const struct WildPokemonInfo gRoute108E_FishingMonsInfo = { 30, gRoute108E_FishingMons };
const struct WildPokemon gRoute109E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute109E_WaterMonsInfo = { 4, gRoute109E_WaterMons };
const struct WildPokemon gRoute109E_FishingMons[] =
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

const struct WildPokemonInfo gRoute109E_FishingMonsInfo = { 30, gRoute109E_FishingMons };
const struct WildPokemon gRoute115E_LandMons[] =
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

const struct WildPokemonInfo gRoute115E_LandMonsInfo = { 20, gRoute115E_LandMons };
const struct WildPokemon gRoute115E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute115E_WaterMonsInfo = { 4, gRoute115E_WaterMons };
const struct WildPokemon gRoute115E_FishingMons[] =
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

const struct WildPokemonInfo gRoute115E_FishingMonsInfo = { 30, gRoute115E_FishingMons };
const struct WildPokemon gNewMauville_InsideE_LandMons[] =
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

const struct WildPokemonInfo gNewMauville_InsideE_LandMonsInfo = { 10, gNewMauville_InsideE_LandMons };
const struct WildPokemon gRoute119E_LandMons[] =
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

const struct WildPokemonInfo gRoute119E_LandMonsInfo = { 15, gRoute119E_LandMons };
const struct WildPokemon gRoute119E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute119E_WaterMonsInfo = { 4, gRoute119E_WaterMons };
const struct WildPokemon gRoute119E_FishingMons[] =
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

const struct WildPokemonInfo gRoute119E_FishingMonsInfo = { 30, gRoute119E_FishingMons };
const struct WildPokemon gRoute120E_LandMons[] =
{
    { 25, 25, SPECIES_POOCHYENA },
    { 25, 25, SPECIES_MIGHTYENA },
    { 27, 27, SPECIES_MIGHTYENA },
    { 25, 25, SPECIES_ODDISH },
    { 25, 25, SPECIES_MARILL },
    { 26, 26, SPECIES_ODDISH },
    { 27, 27, SPECIES_ODDISH },
    { 27, 27, SPECIES_MARILL },
    { 25, 25, SPECIES_ABSOL },
    { 27, 27, SPECIES_ABSOL },
    { 25, 25, SPECIES_KECLEON },
    { 25, 25, SPECIES_SEEDOT },
};

const struct WildPokemonInfo gRoute120E_LandMonsInfo = { 20, gRoute120E_LandMons };
const struct WildPokemon gRoute120E_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 20, 30, SPECIES_GOLDEEN },
};

const struct WildPokemonInfo gRoute120E_WaterMonsInfo = { 4, gRoute120E_WaterMons };
const struct WildPokemon gRoute120E_FishingMons[] =
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

const struct WildPokemonInfo gRoute120E_FishingMonsInfo = { 30, gRoute120E_FishingMons };
const struct WildPokemon gRoute121E_LandMons[] =
{
    { 26, 26, SPECIES_POOCHYENA },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_MIGHTYENA },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_MIGHTYENA },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute121E_LandMonsInfo = { 20, gRoute121E_LandMons };
const struct WildPokemon gRoute121E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute121E_WaterMonsInfo = { 4, gRoute121E_WaterMons };
const struct WildPokemon gRoute121E_FishingMons[] =
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

const struct WildPokemonInfo gRoute121E_FishingMonsInfo = { 30, gRoute121E_FishingMons };
const struct WildPokemon gRoute122E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute122E_WaterMonsInfo = { 4, gRoute122E_WaterMons };
const struct WildPokemon gRoute122E_FishingMons[] =
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

const struct WildPokemonInfo gRoute122E_FishingMonsInfo = { 30, gRoute122E_FishingMons };
const struct WildPokemon gRoute123E_LandMons[] =
{
    { 26, 26, SPECIES_POOCHYENA },
    { 26, 26, SPECIES_SHUPPET },
    { 26, 26, SPECIES_MIGHTYENA },
    { 28, 28, SPECIES_SHUPPET },
    { 28, 28, SPECIES_MIGHTYENA },
    { 26, 26, SPECIES_ODDISH },
    { 28, 28, SPECIES_ODDISH },
    { 28, 28, SPECIES_GLOOM },
    { 26, 26, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
    { 25, 25, SPECIES_KECLEON },
};

const struct WildPokemonInfo gRoute123E_LandMonsInfo = { 20, gRoute123E_LandMons };
const struct WildPokemon gRoute123E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute123E_WaterMonsInfo = { 4, gRoute123E_WaterMons };
const struct WildPokemon gRoute123E_FishingMons[] =
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

const struct WildPokemonInfo gRoute123E_FishingMonsInfo = { 30, gRoute123E_FishingMons };
const struct WildPokemon gMtPyre_2FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_2FE_LandMonsInfo = { 10, gMtPyre_2FE_LandMons };
const struct WildPokemon gMtPyre_3FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_3FE_LandMonsInfo = { 10, gMtPyre_3FE_LandMons };
const struct WildPokemon gMtPyre_4FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_4FE_LandMonsInfo = { 10, gMtPyre_4FE_LandMons };
const struct WildPokemon gMtPyre_5FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_5FE_LandMonsInfo = { 10, gMtPyre_5FE_LandMons };
const struct WildPokemon gMtPyre_6FE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_6FE_LandMonsInfo = { 10, gMtPyre_6FE_LandMons };
const struct WildPokemon gMtPyre_ExteriorE_LandMons[] =
{
    { 27, 27, SPECIES_SHUPPET },
    { 27, 27, SPECIES_SHUPPET },
    { 28, 28, SPECIES_SHUPPET },
    { 29, 29, SPECIES_SHUPPET },
    { 29, 29, SPECIES_VULPIX },
    { 27, 27, SPECIES_VULPIX },
    { 29, 29, SPECIES_VULPIX },
    { 25, 25, SPECIES_VULPIX },
    { 27, 27, SPECIES_WINGULL },
    { 27, 27, SPECIES_WINGULL },
    { 26, 26, SPECIES_WINGULL },
    { 28, 28, SPECIES_WINGULL },
};

const struct WildPokemonInfo gMtPyre_ExteriorE_LandMonsInfo = { 10, gMtPyre_ExteriorE_LandMons };
const struct WildPokemon gMtPyre_SummitE_LandMons[] =
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

const struct WildPokemonInfo gMtPyre_SummitE_LandMonsInfo = { 10, gMtPyre_SummitE_LandMons };
const struct WildPokemon gGraniteCave_StevensRoomE_LandMons[] =
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

const struct WildPokemonInfo gGraniteCave_StevensRoomE_LandMonsInfo = { 10, gGraniteCave_StevensRoomE_LandMons };
const struct WildPokemon gRoute125E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute125E_WaterMonsInfo = { 4, gRoute125E_WaterMons };
const struct WildPokemon gRoute125E_FishingMons[] =
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

const struct WildPokemonInfo gRoute125E_FishingMonsInfo = { 30, gRoute125E_FishingMons };
const struct WildPokemon gRoute126E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute126E_WaterMonsInfo = { 4, gRoute126E_WaterMons };
const struct WildPokemon gRoute126E_FishingMons[] =
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

const struct WildPokemonInfo gRoute126E_FishingMonsInfo = { 30, gRoute126E_FishingMons };
const struct WildPokemon gRoute127E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute127E_WaterMonsInfo = { 4, gRoute127E_WaterMons };
const struct WildPokemon gRoute127E_FishingMons[] =
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

const struct WildPokemonInfo gRoute127E_FishingMonsInfo = { 30, gRoute127E_FishingMons };
const struct WildPokemon gRoute128E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute128E_WaterMonsInfo = { 4, gRoute128E_WaterMons };
const struct WildPokemon gRoute128E_FishingMons[] =
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

const struct WildPokemonInfo gRoute128E_FishingMonsInfo = { 30, gRoute128E_FishingMons };
const struct WildPokemon gRoute129E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_WAILORD },
};

const struct WildPokemonInfo gRoute129E_WaterMonsInfo = { 4, gRoute129E_WaterMons };
const struct WildPokemon gRoute129E_FishingMons[] =
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

const struct WildPokemonInfo gRoute129E_FishingMonsInfo = { 30, gRoute129E_FishingMons };
const struct WildPokemon gRoute130E_LandMons[] =
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

const struct WildPokemonInfo gRoute130E_LandMonsInfo = { 20, gRoute130E_LandMons };
const struct WildPokemon gRoute130E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute130E_WaterMonsInfo = { 4, gRoute130E_WaterMons };
const struct WildPokemon gRoute130E_FishingMons[] =
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

const struct WildPokemonInfo gRoute130E_FishingMonsInfo = { 30, gRoute130E_FishingMons };
const struct WildPokemon gRoute131E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute131E_WaterMonsInfo = { 4, gRoute131E_WaterMons };
const struct WildPokemon gRoute131E_FishingMons[] =
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

const struct WildPokemonInfo gRoute131E_FishingMonsInfo = { 30, gRoute131E_FishingMons };
const struct WildPokemon gRoute132E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute132E_WaterMonsInfo = { 4, gRoute132E_WaterMons };
const struct WildPokemon gRoute132E_FishingMons[] =
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

const struct WildPokemonInfo gRoute132E_FishingMonsInfo = { 30, gRoute132E_FishingMons };
const struct WildPokemon gRoute133E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute133E_WaterMonsInfo = { 4, gRoute133E_WaterMons };
const struct WildPokemon gRoute133E_FishingMons[] =
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

const struct WildPokemonInfo gRoute133E_FishingMonsInfo = { 30, gRoute133E_FishingMons };
const struct WildPokemon gRoute134E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gRoute134E_WaterMonsInfo = { 4, gRoute134E_WaterMons };
const struct WildPokemon gRoute134E_FishingMons[] =
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

const struct WildPokemonInfo gRoute134E_FishingMonsInfo = { 30, gRoute134E_FishingMons };
const struct WildPokemon gAbandonedShip_HiddenFloorCorridorsE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_TENTACOOL },
    { 30, 35, SPECIES_TENTACRUEL },
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridorsE_WaterMonsInfo = { 4, gAbandonedShip_HiddenFloorCorridorsE_WaterMons };
const struct WildPokemon gAbandonedShip_HiddenFloorCorridorsE_FishingMons[] =
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

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridorsE_FishingMonsInfo = { 20, gAbandonedShip_HiddenFloorCorridorsE_FishingMons };
const struct WildPokemon gSeafloorCavern_Room1E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room1E_LandMonsInfo = { 4, gSeafloorCavern_Room1E_LandMons };
const struct WildPokemon gSeafloorCavern_Room2E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room2E_LandMonsInfo = { 4, gSeafloorCavern_Room2E_LandMons };
const struct WildPokemon gSeafloorCavern_Room3E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room3E_LandMonsInfo = { 4, gSeafloorCavern_Room3E_LandMons };
const struct WildPokemon gSeafloorCavern_Room4E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room4E_LandMonsInfo = { 4, gSeafloorCavern_Room4E_LandMons };
const struct WildPokemon gSeafloorCavern_Room5E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room5E_LandMonsInfo = { 4, gSeafloorCavern_Room5E_LandMons };
const struct WildPokemon gSeafloorCavern_Room6E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room6E_LandMonsInfo = { 4, gSeafloorCavern_Room6E_LandMons };
const struct WildPokemon gSeafloorCavern_Room6E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room6E_WaterMonsInfo = { 4, gSeafloorCavern_Room6E_WaterMons };
const struct WildPokemon gSeafloorCavern_Room6E_FishingMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room6E_FishingMonsInfo = { 10, gSeafloorCavern_Room6E_FishingMons };
const struct WildPokemon gSeafloorCavern_Room7E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room7E_LandMonsInfo = { 4, gSeafloorCavern_Room7E_LandMons };
const struct WildPokemon gSeafloorCavern_Room7E_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_Room7E_WaterMonsInfo = { 4, gSeafloorCavern_Room7E_WaterMons };
const struct WildPokemon gSeafloorCavern_Room7E_FishingMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room7E_FishingMonsInfo = { 10, gSeafloorCavern_Room7E_FishingMons };
const struct WildPokemon gSeafloorCavern_Room8E_LandMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_Room8E_LandMonsInfo = { 4, gSeafloorCavern_Room8E_LandMons };
const struct WildPokemon gSeafloorCavern_EntranceE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gSeafloorCavern_EntranceE_WaterMonsInfo = { 4, gSeafloorCavern_EntranceE_WaterMons };
const struct WildPokemon gSeafloorCavern_EntranceE_FishingMons[] =
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

const struct WildPokemonInfo gSeafloorCavern_EntranceE_FishingMonsInfo = { 10, gSeafloorCavern_EntranceE_FishingMons };
const struct WildPokemon gCaveOfOrigin_EntranceE_LandMons[] =
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

const struct WildPokemonInfo gCaveOfOrigin_EntranceE_LandMonsInfo = { 4, gCaveOfOrigin_EntranceE_LandMons };
const struct WildPokemon gCaveOfOrigin_1FE_LandMons[] =
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

const struct WildPokemonInfo gCaveOfOrigin_1FE_LandMonsInfo = { 4, gCaveOfOrigin_1FE_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap1E_LandMons[] =
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

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap1E_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap1E_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap2E_LandMons[] =
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

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap2E_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap2E_LandMons };
const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap3E_LandMons[] =
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

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap3E_LandMonsInfo = { 4, gCaveOfOrigin_UnusedRubySapphireMap3E_LandMons };
const struct WildPokemon gNewMauville_EntranceE_LandMons[] =
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

const struct WildPokemonInfo gNewMauville_EntranceE_LandMonsInfo = { 10, gNewMauville_EntranceE_LandMons };
const struct WildPokemon gSafariZone_SouthwestE_LandMons[] =
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

const struct WildPokemonInfo gSafariZone_SouthwestE_LandMonsInfo = { 25, gSafariZone_SouthwestE_LandMons };
const struct WildPokemon gSafariZone_SouthwestE_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
};

const struct WildPokemonInfo gSafariZone_SouthwestE_WaterMonsInfo = { 9, gSafariZone_SouthwestE_WaterMons };
const struct WildPokemon gSafariZone_SouthwestE_FishingMons[] =
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

const struct WildPokemonInfo gSafariZone_SouthwestE_FishingMonsInfo = { 35, gSafariZone_SouthwestE_FishingMons };
const struct WildPokemon gSafariZone_NorthE_LandMons[] =
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

const struct WildPokemonInfo gSafariZone_NorthE_LandMonsInfo = { 25, gSafariZone_NorthE_LandMons };
const struct WildPokemon gSafariZone_NorthE_RockSmashMons[] =
{
    { 10, 15, SPECIES_GEODUDE },
    { 5, 10, SPECIES_GEODUDE },
    { 15, 20, SPECIES_GEODUDE },
    { 20, 25, SPECIES_GEODUDE },
    { 25, 30, SPECIES_GEODUDE },
};

const struct WildPokemonInfo gSafariZone_NorthE_RockSmashMonsInfo = { 25, gSafariZone_NorthE_RockSmashMons };
const struct WildPokemon gSafariZone_NorthwestE_LandMons[] =
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

const struct WildPokemonInfo gSafariZone_NorthwestE_LandMonsInfo = { 25, gSafariZone_NorthwestE_LandMons };
const struct WildPokemon gSafariZone_NorthwestE_WaterMons[] =
{
    { 20, 30, SPECIES_PSYDUCK },
    { 20, 30, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_PSYDUCK },
    { 30, 35, SPECIES_GOLDUCK },
    { 25, 40, SPECIES_GOLDUCK },
};

const struct WildPokemonInfo gSafariZone_NorthwestE_WaterMonsInfo = { 9, gSafariZone_NorthwestE_WaterMons };
const struct WildPokemon gSafariZone_NorthwestE_FishingMons[] =
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

const struct WildPokemonInfo gSafariZone_NorthwestE_FishingMonsInfo = { 35, gSafariZone_NorthwestE_FishingMons };
const struct WildPokemon gVictoryRoad_B1FE_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_HARIYAMA },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LAIRON },
    { 38, 38, SPECIES_GOLBAT },
    { 38, 38, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_HARIYAMA },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MAWILE },
    { 42, 42, SPECIES_LAIRON },
    { 38, 38, SPECIES_MAWILE },
};

const struct WildPokemonInfo gVictoryRoad_B1FE_LandMonsInfo = { 10, gVictoryRoad_B1FE_LandMons };
const struct WildPokemon gVictoryRoad_B1FE_RockSmashMons[] =
{
    { 30, 40, SPECIES_GRAVELER },
    { 30, 40, SPECIES_GEODUDE },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
    { 35, 40, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gVictoryRoad_B1FE_RockSmashMonsInfo = { 20, gVictoryRoad_B1FE_RockSmashMons };
const struct WildPokemon gVictoryRoad_B2FE_LandMons[] =
{
    { 40, 40, SPECIES_GOLBAT },
    { 40, 40, SPECIES_SABLEYE },
    { 40, 40, SPECIES_LAIRON },
    { 40, 40, SPECIES_LAIRON },
    { 42, 42, SPECIES_GOLBAT },
    { 42, 42, SPECIES_SABLEYE },
    { 44, 44, SPECIES_GOLBAT },
    { 44, 44, SPECIES_SABLEYE },
    { 42, 42, SPECIES_LAIRON },
    { 42, 42, SPECIES_MAWILE },
    { 44, 44, SPECIES_LAIRON },
    { 44, 44, SPECIES_MAWILE },
};

const struct WildPokemonInfo gVictoryRoad_B2FE_LandMonsInfo = { 10, gVictoryRoad_B2FE_LandMons };
const struct WildPokemon gVictoryRoad_B2FE_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 25, 30, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
    { 35, 40, SPECIES_GOLBAT },
};

const struct WildPokemonInfo gVictoryRoad_B2FE_WaterMonsInfo = { 4, gVictoryRoad_B2FE_WaterMons };
const struct WildPokemon gVictoryRoad_B2FE_FishingMons[] =
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

const struct WildPokemonInfo gVictoryRoad_B2FE_FishingMonsInfo = { 30, gVictoryRoad_B2FE_FishingMons };
const struct WildPokemon gMeteorFalls_1F_1RE_LandMons[] =
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

const struct WildPokemonInfo gMeteorFalls_1F_1RE_LandMonsInfo = { 10, gMeteorFalls_1F_1RE_LandMons };
const struct WildPokemon gMeteorFalls_1F_1RE_WaterMons[] =
{
    { 5, 35, SPECIES_ZUBAT },
    { 30, 35, SPECIES_ZUBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_1RE_WaterMonsInfo = { 4, gMeteorFalls_1F_1RE_WaterMons };
const struct WildPokemon gMeteorFalls_1F_1RE_FishingMons[] =
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

const struct WildPokemonInfo gMeteorFalls_1F_1RE_FishingMonsInfo = { 30, gMeteorFalls_1F_1RE_FishingMons };
const struct WildPokemon gMeteorFalls_1F_2RE_LandMons[] =
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

const struct WildPokemonInfo gMeteorFalls_1F_2RE_LandMonsInfo = { 10, gMeteorFalls_1F_2RE_LandMons };
const struct WildPokemon gMeteorFalls_1F_2RE_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_1F_2RE_WaterMonsInfo = { 4, gMeteorFalls_1F_2RE_WaterMons };
const struct WildPokemon gMeteorFalls_1F_2RE_FishingMons[] =
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

const struct WildPokemonInfo gMeteorFalls_1F_2RE_FishingMonsInfo = { 30, gMeteorFalls_1F_2RE_FishingMons };
const struct WildPokemon gMeteorFalls_B1F_1RE_LandMons[] =
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

const struct WildPokemonInfo gMeteorFalls_B1F_1RE_LandMonsInfo = { 10, gMeteorFalls_B1F_1RE_LandMons };
const struct WildPokemon gMeteorFalls_B1F_1RE_WaterMons[] =
{
    { 30, 35, SPECIES_GOLBAT },
    { 30, 35, SPECIES_GOLBAT },
    { 25, 35, SPECIES_SOLROCK },
    { 15, 25, SPECIES_SOLROCK },
    { 5, 15, SPECIES_SOLROCK },
};

const struct WildPokemonInfo gMeteorFalls_B1F_1RE_WaterMonsInfo = { 4, gMeteorFalls_B1F_1RE_WaterMons };
const struct WildPokemon gMeteorFalls_B1F_1RE_FishingMons[] =
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

const struct WildPokemonInfo gMeteorFalls_B1F_1RE_FishingMonsInfo = { 30, gMeteorFalls_B1F_1RE_FishingMons };
const struct WildPokemon gShoalCave_LowTideStairsRoomE_LandMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideStairsRoomE_LandMonsInfo = { 10, gShoalCave_LowTideStairsRoomE_LandMons };
const struct WildPokemon gShoalCave_LowTideLowerRoomE_LandMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideLowerRoomE_LandMonsInfo = { 10, gShoalCave_LowTideLowerRoomE_LandMons };
const struct WildPokemon gShoalCave_LowTideInnerRoomE_LandMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideInnerRoomE_LandMonsInfo = { 10, gShoalCave_LowTideInnerRoomE_LandMons };
const struct WildPokemon gShoalCave_LowTideInnerRoomE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoomE_WaterMonsInfo = { 4, gShoalCave_LowTideInnerRoomE_WaterMons };
const struct WildPokemon gShoalCave_LowTideInnerRoomE_FishingMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideInnerRoomE_FishingMonsInfo = { 10, gShoalCave_LowTideInnerRoomE_FishingMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoomE_LandMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoomE_LandMonsInfo = { 10, gShoalCave_LowTideEntranceRoomE_LandMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoomE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 5, 35, SPECIES_ZUBAT },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 30, SPECIES_SPHEAL },
    { 25, 35, SPECIES_SPHEAL },
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoomE_WaterMonsInfo = { 4, gShoalCave_LowTideEntranceRoomE_WaterMons };
const struct WildPokemon gShoalCave_LowTideEntranceRoomE_FishingMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoomE_FishingMonsInfo = { 10, gShoalCave_LowTideEntranceRoomE_FishingMons };
const struct WildPokemon gLilycoveCityE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gLilycoveCityE_WaterMonsInfo = { 4, gLilycoveCityE_WaterMons };
const struct WildPokemon gLilycoveCityE_FishingMons[] =
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

const struct WildPokemonInfo gLilycoveCityE_FishingMonsInfo = { 10, gLilycoveCityE_FishingMons };
const struct WildPokemon gDewfordTownE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gDewfordTownE_WaterMonsInfo = { 4, gDewfordTownE_WaterMons };
const struct WildPokemon gDewfordTownE_FishingMons[] =
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

const struct WildPokemonInfo gDewfordTownE_FishingMonsInfo = { 10, gDewfordTownE_FishingMons };
const struct WildPokemon gSlateportCityE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gSlateportCityE_WaterMonsInfo = { 4, gSlateportCityE_WaterMons };
const struct WildPokemon gSlateportCityE_FishingMons[] =
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

const struct WildPokemonInfo gSlateportCityE_FishingMonsInfo = { 10, gSlateportCityE_FishingMons };
const struct WildPokemon gMossdeepCityE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gMossdeepCityE_WaterMonsInfo = { 4, gMossdeepCityE_WaterMons };
const struct WildPokemon gMossdeepCityE_FishingMons[] =
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

const struct WildPokemonInfo gMossdeepCityE_FishingMonsInfo = { 10, gMossdeepCityE_FishingMons };
const struct WildPokemon gPacifidlogTownE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gPacifidlogTownE_WaterMonsInfo = { 4, gPacifidlogTownE_WaterMons };
const struct WildPokemon gPacifidlogTownE_FishingMons[] =
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

const struct WildPokemonInfo gPacifidlogTownE_FishingMonsInfo = { 10, gPacifidlogTownE_FishingMons };
const struct WildPokemon gEverGrandeCityE_WaterMons[] =
{
    { 5, 35, SPECIES_TENTACOOL },
    { 10, 30, SPECIES_WINGULL },
    { 15, 25, SPECIES_WINGULL },
    { 25, 30, SPECIES_PELIPPER },
    { 25, 30, SPECIES_PELIPPER },
};

const struct WildPokemonInfo gEverGrandeCityE_WaterMonsInfo = { 4, gEverGrandeCityE_WaterMons };
const struct WildPokemon gEverGrandeCityE_FishingMons[] =
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

const struct WildPokemonInfo gEverGrandeCityE_FishingMonsInfo = { 10, gEverGrandeCityE_FishingMons };
const struct WildPokemon gPetalburgCityE_WaterMons[] =
{
    { 20, 30, SPECIES_MARILL },
    { 10, 20, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
    { 5, 10, SPECIES_MARILL },
};

const struct WildPokemonInfo gPetalburgCityE_WaterMonsInfo = { 1, gPetalburgCityE_WaterMons };
const struct WildPokemon gPetalburgCityE_FishingMons[] =
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

const struct WildPokemonInfo gPetalburgCityE_FishingMonsInfo = { 10, gPetalburgCityE_FishingMons };
const struct WildPokemon gUnderwater_Route124E_WaterMons[] =
{
    { 20, 30, SPECIES_CLAMPERL },
    { 20, 30, SPECIES_CHINCHOU },
    { 30, 35, SPECIES_CLAMPERL },
    { 30, 35, SPECIES_RELICANTH },
    { 30, 35, SPECIES_RELICANTH },
};

const struct WildPokemonInfo gUnderwater_Route124E_WaterMonsInfo = { 4, gUnderwater_Route124E_WaterMons };
const struct WildPokemon gShoalCave_LowTideIceRoomE_LandMons[] =
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

const struct WildPokemonInfo gShoalCave_LowTideIceRoomE_LandMonsInfo = { 10, gShoalCave_LowTideIceRoomE_LandMons };
const struct WildPokemon gSkyPillar_1FE_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo gSkyPillar_1FE_LandMonsInfo = { 10, gSkyPillar_1FE_LandMons };
const struct WildPokemon gSootopolisCityE_WaterMons[] =
{
    { 5, 35, SPECIES_MAGIKARP },
    { 10, 30, SPECIES_MAGIKARP },
    { 15, 25, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_MAGIKARP },
};

const struct WildPokemonInfo gSootopolisCityE_WaterMonsInfo = { 1, gSootopolisCityE_WaterMons };
const struct WildPokemon gSootopolisCityE_FishingMons[] =
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

const struct WildPokemonInfo gSootopolisCityE_FishingMonsInfo = { 10, gSootopolisCityE_FishingMons };
const struct WildPokemon gSkyPillar_3FE_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_CLAYDOL },
};

const struct WildPokemonInfo gSkyPillar_3FE_LandMonsInfo = { 10, gSkyPillar_3FE_LandMons };
const struct WildPokemon gSkyPillar_5FE_LandMons[] =
{
    { 33, 33, SPECIES_SABLEYE },
    { 34, 34, SPECIES_GOLBAT },
    { 35, 35, SPECIES_GOLBAT },
    { 34, 34, SPECIES_SABLEYE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_BANETTE },
    { 38, 38, SPECIES_BANETTE },
    { 36, 36, SPECIES_CLAYDOL },
    { 37, 37, SPECIES_CLAYDOL },
    { 38, 38, SPECIES_ALTARIA },
    { 39, 39, SPECIES_ALTARIA },
    { 39, 39, SPECIES_ALTARIA },
};

const struct WildPokemonInfo gSkyPillar_5FE_LandMonsInfo = { 10, gSkyPillar_5FE_LandMons };
const struct WildPokemon gSafariZone_SoutheastE_LandMons[] =
{
    { 33, 33, SPECIES_SUNKERN },
    { 34, 34, SPECIES_MAREEP },
    { 35, 35, SPECIES_SUNKERN },
    { 36, 36, SPECIES_MAREEP },
    { 34, 34, SPECIES_AIPOM },
    { 33, 33, SPECIES_SPINARAK },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_SNUBBULL },
    { 36, 36, SPECIES_STANTLER },
    { 37, 37, SPECIES_GLIGAR },
    { 39, 39, SPECIES_STANTLER },
    { 40, 40, SPECIES_GLIGAR },
};

const struct WildPokemonInfo gSafariZone_SoutheastE_LandMonsInfo = { 25, gSafariZone_SoutheastE_LandMons };
const struct WildPokemon gSafariZone_SoutheastE_WaterMons[] =
{
    { 25, 30, SPECIES_WOOPER },
    { 25, 30, SPECIES_MARILL },
    { 25, 30, SPECIES_MARILL },
    { 30, 35, SPECIES_MARILL },
    { 35, 40, SPECIES_QUAGSIRE },
};

const struct WildPokemonInfo gSafariZone_SoutheastE_WaterMonsInfo = { 9, gSafariZone_SoutheastE_WaterMons };
const struct WildPokemon gSafariZone_SoutheastE_FishingMons[] =
{
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_MAGIKARP },
    { 25, 30, SPECIES_GOLDEEN },
    { 30, 35, SPECIES_REMORAID },
    { 25, 30, SPECIES_GOLDEEN },
    { 25, 30, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 30, 35, SPECIES_REMORAID },
    { 35, 40, SPECIES_OCTILLERY },
};

const struct WildPokemonInfo gSafariZone_SoutheastE_FishingMonsInfo = { 35, gSafariZone_SoutheastE_FishingMons };
const struct WildPokemon gSafariZone_NortheastE_LandMons[] =
{
    { 33, 33, SPECIES_AIPOM },
    { 34, 34, SPECIES_TEDDIURSA },
    { 35, 35, SPECIES_AIPOM },
    { 36, 36, SPECIES_TEDDIURSA },
    { 34, 34, SPECIES_SUNKERN },
    { 33, 33, SPECIES_LEDYBA },
    { 35, 35, SPECIES_HOOTHOOT },
    { 34, 34, SPECIES_PINECO },
    { 36, 36, SPECIES_HOUNDOUR },
    { 37, 37, SPECIES_MILTANK },
    { 39, 39, SPECIES_HOUNDOUR },
    { 40, 40, SPECIES_MILTANK },
};

const struct WildPokemonInfo gSafariZone_NortheastE_LandMonsInfo = { 25, gSafariZone_NortheastE_LandMons };
const struct WildPokemon gSafariZone_NortheastE_RockSmashMons[] =
{
    { 25, 30, SPECIES_SHUCKLE },
    { 20, 25, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 30, 35, SPECIES_SHUCKLE },
    { 35, 40, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gSafariZone_NortheastE_RockSmashMonsInfo = { 25, gSafariZone_NortheastE_RockSmashMons };
const struct WildPokemon gMagmaHideout_1FE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_1FE_LandMonsInfo = { 10, gMagmaHideout_1FE_LandMons };
const struct WildPokemon gMagmaHideout_2F_1RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_1RE_LandMonsInfo = { 10, gMagmaHideout_2F_1RE_LandMons };
const struct WildPokemon gMagmaHideout_2F_2RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_2RE_LandMonsInfo = { 10, gMagmaHideout_2F_2RE_LandMons };
const struct WildPokemon gMagmaHideout_3F_1RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_1RE_LandMonsInfo = { 10, gMagmaHideout_3F_1RE_LandMons };
const struct WildPokemon gMagmaHideout_3F_2RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_2RE_LandMonsInfo = { 10, gMagmaHideout_3F_2RE_LandMons };
const struct WildPokemon gMagmaHideout_4FE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_4FE_LandMonsInfo = { 10, gMagmaHideout_4FE_LandMons };
const struct WildPokemon gMagmaHideout_3F_3RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_3F_3RE_LandMonsInfo = { 10, gMagmaHideout_3F_3RE_LandMons };
const struct WildPokemon gMagmaHideout_2F_3RE_LandMons[] =
{
    { 27, 27, SPECIES_GEODUDE },
    { 28, 28, SPECIES_TORKOAL },
    { 28, 28, SPECIES_GEODUDE },
    { 30, 30, SPECIES_TORKOAL },
    { 29, 29, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GEODUDE },
    { 30, 30, SPECIES_GRAVELER },
    { 30, 30, SPECIES_GRAVELER },
    { 31, 31, SPECIES_GRAVELER },
    { 32, 32, SPECIES_GRAVELER },
    { 33, 33, SPECIES_GRAVELER },
};

const struct WildPokemonInfo gMagmaHideout_2F_3RE_LandMonsInfo = { 10, gMagmaHideout_2F_3RE_LandMons };
const struct WildPokemon gMirageTower_1FE_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_1FE_LandMonsInfo = { 10, gMirageTower_1FE_LandMons };
const struct WildPokemon gMirageTower_2FE_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_2FE_LandMonsInfo = { 10, gMirageTower_2FE_LandMons };
const struct WildPokemon gMirageTower_3FE_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_3FE_LandMonsInfo = { 10, gMirageTower_3FE_LandMons };
const struct WildPokemon gMirageTower_4FE_LandMons[] =
{
    { 21, 21, SPECIES_SANDSHREW },
    { 21, 21, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 20, 20, SPECIES_SANDSHREW },
    { 20, 20, SPECIES_TRAPINCH },
    { 22, 22, SPECIES_SANDSHREW },
    { 22, 22, SPECIES_TRAPINCH },
    { 23, 23, SPECIES_SANDSHREW },
    { 23, 23, SPECIES_TRAPINCH },
    { 24, 24, SPECIES_SANDSHREW },
    { 24, 24, SPECIES_TRAPINCH },
};

const struct WildPokemonInfo gMirageTower_4FE_LandMonsInfo = { 10, gMirageTower_4FE_LandMons };
const struct WildPokemon gDesertUnderpassE_LandMons[] =
{
    { 38, 38, SPECIES_DITTO },
    { 35, 35, SPECIES_WHISMUR },
    { 40, 40, SPECIES_DITTO },
    { 40, 40, SPECIES_LOUDRED },
    { 41, 41, SPECIES_DITTO },
    { 36, 36, SPECIES_WHISMUR },
    { 38, 38, SPECIES_LOUDRED },
    { 42, 42, SPECIES_DITTO },
    { 38, 38, SPECIES_WHISMUR },
    { 43, 43, SPECIES_DITTO },
    { 44, 44, SPECIES_LOUDRED },
    { 45, 45, SPECIES_DITTO },
};

const struct WildPokemonInfo gDesertUnderpassE_LandMonsInfo = { 10, gDesertUnderpassE_LandMons };
const struct WildPokemon gArtisanCave_B1FE_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gArtisanCave_B1FE_LandMonsInfo = { 10, gArtisanCave_B1FE_LandMons };
const struct WildPokemon gArtisanCave_1FE_LandMons[] =
{
    { 40, 40, SPECIES_SMEARGLE },
    { 41, 41, SPECIES_SMEARGLE },
    { 42, 42, SPECIES_SMEARGLE },
    { 43, 43, SPECIES_SMEARGLE },
    { 44, 44, SPECIES_SMEARGLE },
    { 45, 45, SPECIES_SMEARGLE },
    { 46, 46, SPECIES_SMEARGLE },
    { 47, 47, SPECIES_SMEARGLE },
    { 48, 48, SPECIES_SMEARGLE },
    { 49, 49, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
    { 50, 50, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gArtisanCave_1FE_LandMonsInfo = { 10, gArtisanCave_1FE_LandMons };
const struct WildPokemon gAlteringCave1E_LandMons[] =
{
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 10, 10, SPECIES_ZUBAT },
    { 12, 12, SPECIES_ZUBAT },
    { 16, 16, SPECIES_ZUBAT },
    { 6, 6, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
    { 8, 8, SPECIES_ZUBAT },
    { 14, 14, SPECIES_ZUBAT },
};

const struct WildPokemonInfo gAlteringCave1E_LandMonsInfo = { 7, gAlteringCave1E_LandMons };
const struct WildPokemon gAlteringCave2E_LandMons[] =
{
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 7, 7, SPECIES_MAREEP },
    { 9, 9, SPECIES_MAREEP },
    { 13, 13, SPECIES_MAREEP },
    { 3, 3, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
    { 5, 5, SPECIES_MAREEP },
    { 11, 11, SPECIES_MAREEP },
};

const struct WildPokemonInfo gAlteringCave2E_LandMonsInfo = { 7, gAlteringCave2E_LandMons };
const struct WildPokemon gAlteringCave3E_LandMons[] =
{
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 22, 22, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 23, 23, SPECIES_PINECO },
    { 25, 25, SPECIES_PINECO },
    { 29, 29, SPECIES_PINECO },
    { 19, 19, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
    { 21, 21, SPECIES_PINECO },
    { 27, 27, SPECIES_PINECO },
};

const struct WildPokemonInfo gAlteringCave3E_LandMonsInfo = { 7, gAlteringCave3E_LandMons };
const struct WildPokemon gAlteringCave4E_LandMons[] =
{
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 16, 16, SPECIES_HOUNDOUR },
    { 18, 18, SPECIES_HOUNDOUR },
    { 22, 22, SPECIES_HOUNDOUR },
    { 12, 12, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
    { 14, 14, SPECIES_HOUNDOUR },
    { 20, 20, SPECIES_HOUNDOUR },
};

const struct WildPokemonInfo gAlteringCave4E_LandMonsInfo = { 7, gAlteringCave4E_LandMons };
const struct WildPokemon gAlteringCave5E_LandMons[] =
{
    { 10, 10, SPECIES_TEDDIURSA },
    { 12, 12, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
    { 10, 10, SPECIES_TEDDIURSA },
    { 12, 12, SPECIES_TEDDIURSA },
    { 16, 16, SPECIES_TEDDIURSA },
    { 6, 6, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
    { 8, 8, SPECIES_TEDDIURSA },
    { 14, 14, SPECIES_TEDDIURSA },
};

const struct WildPokemonInfo gAlteringCave5E_LandMonsInfo = { 7, gAlteringCave5E_LandMons };
const struct WildPokemon gAlteringCave6E_LandMons[] =
{
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 22, 22, SPECIES_AIPOM },
    { 24, 24, SPECIES_AIPOM },
    { 28, 28, SPECIES_AIPOM },
    { 18, 18, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
    { 20, 20, SPECIES_AIPOM },
    { 26, 26, SPECIES_AIPOM },
};

const struct WildPokemonInfo gAlteringCave6E_LandMonsInfo = { 7, gAlteringCave6E_LandMons };
const struct WildPokemon gAlteringCave7E_LandMons[] =
{
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 22, 22, SPECIES_SHUCKLE },
    { 24, 24, SPECIES_SHUCKLE },
    { 28, 28, SPECIES_SHUCKLE },
    { 18, 18, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
    { 20, 20, SPECIES_SHUCKLE },
    { 26, 26, SPECIES_SHUCKLE },
};

const struct WildPokemonInfo gAlteringCave7E_LandMonsInfo = { 7, gAlteringCave7E_LandMons };
const struct WildPokemon gAlteringCave8E_LandMons[] =
{
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 22, 22, SPECIES_STANTLER },
    { 24, 24, SPECIES_STANTLER },
    { 28, 28, SPECIES_STANTLER },
    { 18, 18, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
    { 20, 20, SPECIES_STANTLER },
    { 26, 26, SPECIES_STANTLER },
};

const struct WildPokemonInfo gAlteringCave8E_LandMonsInfo = { 7, gAlteringCave8E_LandMons };
const struct WildPokemon gAlteringCave9E_LandMons[] =
{
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 22, 22, SPECIES_SMEARGLE },
    { 24, 24, SPECIES_SMEARGLE },
    { 28, 28, SPECIES_SMEARGLE },
    { 18, 18, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
    { 20, 20, SPECIES_SMEARGLE },
    { 26, 26, SPECIES_SMEARGLE },
};

const struct WildPokemonInfo gAlteringCave9E_LandMonsInfo = { 7, gAlteringCave9E_LandMons };
const struct WildPokemon gMeteorFalls_StevensCaveE_LandMons[] =
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

const struct WildPokemonInfo gMeteorFalls_StevensCaveE_LandMonsInfo = { 10, gMeteorFalls_StevensCaveE_LandMons };

const struct WildPokemonHeader gWildMonHeadersE[] =
{
    {
        .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .landMonsInfo = &gRoute101E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
        .landMonsInfo = &gRoute102E_LandMonsInfo,
        .waterMonsInfo = &gRoute102E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute102E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
        .landMonsInfo = &gRoute103E_LandMonsInfo,
        .waterMonsInfo = &gRoute103E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute103E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
        .landMonsInfo = &gRoute104E_LandMonsInfo,
        .waterMonsInfo = &gRoute104E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute104E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute105E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute105E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
        .landMonsInfo = &gRoute110E_LandMonsInfo,
        .waterMonsInfo = &gRoute110E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute110E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
        .landMonsInfo = &gRoute111E_LandMonsInfo,
        .waterMonsInfo = &gRoute111E_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute111E_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute111E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
        .landMonsInfo = &gRoute112E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
        .landMonsInfo = &gRoute113E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
        .landMonsInfo = &gRoute114E_LandMonsInfo,
        .waterMonsInfo = &gRoute114E_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute114E_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute114E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
        .landMonsInfo = &gRoute116E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
        .landMonsInfo = &gRoute117E_LandMonsInfo,
        .waterMonsInfo = &gRoute117E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute117E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
        .landMonsInfo = &gRoute118E_LandMonsInfo,
        .waterMonsInfo = &gRoute118E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute118E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute124E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute124E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
        .landMonsInfo = &gPetalburgWoodsE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
        .landMonsInfo = &gRusturfTunnelE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
        .landMonsInfo = &gGraniteCave_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
        .landMonsInfo = &gGraniteCave_B1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
        .landMonsInfo = &gMtPyre_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo = &gVictoryRoad_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTH),
        .landMonsInfo = &gSafariZone_SouthE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE126),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater_Route126E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_Rooms_B1FE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_Rooms_B1FE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
        .landMonsInfo = &gGraniteCave_B2FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gGraniteCave_B2FE_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
        .landMonsInfo = &gFieryPathE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
        .landMonsInfo = &gMeteorFalls_B1F_2RE_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_2RE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_2RE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
        .landMonsInfo = &gJaggedPassE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute106E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute106E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute107E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute107E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute108E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute108E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute109E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute109E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
        .landMonsInfo = &gRoute115E_LandMonsInfo,
        .waterMonsInfo = &gRoute115E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute115E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
        .landMonsInfo = &gNewMauville_InsideE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
        .landMonsInfo = &gRoute119E_LandMonsInfo,
        .waterMonsInfo = &gRoute119E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute119E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
        .landMonsInfo = &gRoute120E_LandMonsInfo,
        .waterMonsInfo = &gRoute120E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute120E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
        .landMonsInfo = &gRoute121E_LandMonsInfo,
        .waterMonsInfo = &gRoute121E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute121E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute122E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute122E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
        .landMonsInfo = &gRoute123E_LandMonsInfo,
        .waterMonsInfo = &gRoute123E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute123E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
        .landMonsInfo = &gMtPyre_2FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
        .landMonsInfo = &gMtPyre_3FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
        .landMonsInfo = &gMtPyre_4FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
        .landMonsInfo = &gMtPyre_5FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
        .landMonsInfo = &gMtPyre_6FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
        .landMonsInfo = &gMtPyre_ExteriorE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
        .landMonsInfo = &gMtPyre_SummitE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
        .landMonsInfo = &gGraniteCave_StevensRoomE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute125E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute125E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute126E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute126E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute127E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute127E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute128E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute128E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute129E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute129E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
        .landMonsInfo = &gRoute130E_LandMonsInfo,
        .waterMonsInfo = &gRoute130E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute130E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute131E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute131E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute132E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute132E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute133E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute133E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute134E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute134E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_HiddenFloorCorridorsE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_HiddenFloorCorridorsE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
        .landMonsInfo = &gSeafloorCavern_Room1E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
        .landMonsInfo = &gSeafloorCavern_Room2E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
        .landMonsInfo = &gSeafloorCavern_Room3E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
        .landMonsInfo = &gSeafloorCavern_Room4E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
        .landMonsInfo = &gSeafloorCavern_Room5E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
        .landMonsInfo = &gSeafloorCavern_Room6E_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room6E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room6E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
        .landMonsInfo = &gSeafloorCavern_Room7E_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room7E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room7E_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
        .landMonsInfo = &gSeafloorCavern_Room8E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSeafloorCavern_EntranceE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_EntranceE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
        .landMonsInfo = &gCaveOfOrigin_EntranceE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
        .landMonsInfo = &gCaveOfOrigin_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap1E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap2E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap3E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
        .landMonsInfo = &gNewMauville_EntranceE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
        .landMonsInfo = &gSafariZone_SouthwestE_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_SouthwestE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_SouthwestE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
        .landMonsInfo = &gSafariZone_NorthE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_NorthE_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
        .landMonsInfo = &gSafariZone_NorthwestE_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_NorthwestE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_NorthwestE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
        .landMonsInfo = &gVictoryRoad_B1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gVictoryRoad_B1FE_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
        .landMonsInfo = &gVictoryRoad_B2FE_LandMonsInfo,
        .waterMonsInfo = &gVictoryRoad_B2FE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gVictoryRoad_B2FE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
        .landMonsInfo = &gMeteorFalls_1F_1RE_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_1RE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_1RE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
        .landMonsInfo = &gMeteorFalls_1F_2RE_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_2RE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_2RE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
        .landMonsInfo = &gMeteorFalls_B1F_1RE_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_1RE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_1RE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .landMonsInfo = &gShoalCave_LowTideStairsRoomE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideLowerRoomE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideInnerRoomE_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideInnerRoomE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideInnerRoomE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideEntranceRoomE_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideEntranceRoomE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideEntranceRoomE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gLilycoveCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gLilycoveCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gDewfordTownE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gDewfordTownE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSlateportCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSlateportCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gMossdeepCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMossdeepCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPacifidlogTownE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPacifidlogTownE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gEverGrandeCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gEverGrandeCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPetalburgCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPetalburgCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER_ROUTE124),
        .mapNum = MAP_NUM(UNDERWATER_ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater_Route124E_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideIceRoomE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
        .landMonsInfo = &gSkyPillar_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSootopolisCityE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSootopolisCityE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
        .landMonsInfo = &gSkyPillar_3FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
        .landMonsInfo = &gSkyPillar_5FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
        .landMonsInfo = &gSafariZone_SoutheastE_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_SoutheastE_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_SoutheastE_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
        .landMonsInfo = &gSafariZone_NortheastE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_NortheastE_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_1F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_1F),
        .landMonsInfo = &gMagmaHideout_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_1R),
        .landMonsInfo = &gMagmaHideout_2F_1RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_2R),
        .landMonsInfo = &gMagmaHideout_2F_2RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_1R),
        .landMonsInfo = &gMagmaHideout_3F_1RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_2R),
        .landMonsInfo = &gMagmaHideout_3F_2RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_4F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_4F),
        .landMonsInfo = &gMagmaHideout_4FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_3R),
        .landMonsInfo = &gMagmaHideout_3F_3RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_3R),
        .landMonsInfo = &gMagmaHideout_2F_3RE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_1F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_1F),
        .landMonsInfo = &gMirageTower_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_2F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_2F),
        .landMonsInfo = &gMirageTower_2FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_3F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_3F),
        .landMonsInfo = &gMirageTower_3FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_4F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_4F),
        .landMonsInfo = &gMirageTower_4FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DESERT_UNDERPASS),
        .mapNum = MAP_NUM(DESERT_UNDERPASS),
        .landMonsInfo = &gDesertUnderpassE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_B1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_B1F),
        .landMonsInfo = &gArtisanCave_B1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_1F),
        .landMonsInfo = &gArtisanCave_1FE_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave1E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave2E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave3E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave4E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave5E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave6E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave7E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave8E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave9E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_STEVENS_CAVE),
        .mapNum = MAP_NUM(METEOR_FALLS_STEVENS_CAVE),
        .landMonsInfo = &gMeteorFalls_StevensCaveE_LandMonsInfo,
        .waterMonsInfo = NULL,
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



const struct WildPokemon gBattlePyramid_1E_LandMons[] =
{
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_BULBASAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
};

const struct WildPokemonInfo gBattlePyramid_1E_LandMonsInfo = { 4, gBattlePyramid_1E_LandMons };
const struct WildPokemon gBattlePyramid_2E_LandMons[] =
{
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_IVYSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMANDER },
};

const struct WildPokemonInfo gBattlePyramid_2E_LandMonsInfo = { 4, gBattlePyramid_2E_LandMons };
const struct WildPokemon gBattlePyramid_3E_LandMons[] =
{
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_VENUSAUR },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
};

const struct WildPokemonInfo gBattlePyramid_3E_LandMonsInfo = { 4, gBattlePyramid_3E_LandMons };
const struct WildPokemon gBattlePyramid_4E_LandMons[] =
{
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMANDER },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
};

const struct WildPokemonInfo gBattlePyramid_4E_LandMonsInfo = { 4, gBattlePyramid_4E_LandMons };
const struct WildPokemon gBattlePyramid_5E_LandMons[] =
{
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
};

const struct WildPokemonInfo gBattlePyramid_5E_LandMonsInfo = { 4, gBattlePyramid_5E_LandMons };
const struct WildPokemon gBattlePyramid_6E_LandMons[] =
{
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
};

const struct WildPokemonInfo gBattlePyramid_6E_LandMonsInfo = { 4, gBattlePyramid_6E_LandMons };
const struct WildPokemon gBattlePyramid_7E_LandMons[] =
{
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_WARTORTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_SQUIRTLE },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARIZARD },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
    { 5, 5, SPECIES_CHARMELEON },
};

const struct WildPokemonInfo gBattlePyramid_7E_LandMonsInfo = { 8, gBattlePyramid_7E_LandMons };

const struct WildPokemonHeader gBattlePyramidWildMonHeadersE[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePyramid_1E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePyramid_2E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePyramid_3E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePyramid_4E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 5,
        .landMonsInfo = &gBattlePyramid_5E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 6,
        .landMonsInfo = &gBattlePyramid_6E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 7,
        .landMonsInfo = &gBattlePyramid_7E_LandMonsInfo,
        .waterMonsInfo = NULL,
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



const struct WildPokemon gBattlePike_1E_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_DUSCLOPS },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_1E_LandMonsInfo = { 10, gBattlePike_1E_LandMons };
const struct WildPokemon gBattlePike_2E_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_ELECTRODE },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_2E_LandMonsInfo = { 10, gBattlePike_2E_LandMons };
const struct WildPokemon gBattlePike_3E_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_BRELOOM },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_3E_LandMonsInfo = { 10, gBattlePike_3E_LandMons };
const struct WildPokemon gBattlePike_4E_LandMons[] =
{
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_WOBBUFFET },
    { 5, 5, SPECIES_SEVIPER },
    { 5, 5, SPECIES_MILOTIC },
};

const struct WildPokemonInfo gBattlePike_4E_LandMonsInfo = { 10, gBattlePike_4E_LandMons };

const struct WildPokemonHeader gBattlePikeWildMonHeadersE[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePike_1E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePike_2E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePike_3E_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePike_4E_LandMonsInfo,
        .waterMonsInfo = NULL,
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
