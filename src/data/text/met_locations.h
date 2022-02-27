#define REGION_UNKNOWN	0
#define REGION_KANTO	1
#define REGION_JOHTO	2
#define REGION_HOENN	3
#define REGION_ORRE		4
#define REGION_SINNOH	5

static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", Kanto");
static const u8 sRegionString_Johto[] = _(", Johto");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", Orre");
static const u8 sRegionString_Sinnoh[] = _(", Sinnoh");

const u8 *const gRegionStringPointers[] =
{
	[REGION_UNKNOWN] = sRegionString_Unknown,
	[REGION_KANTO]   = sRegionString_Kanto,
	[REGION_JOHTO]   = sRegionString_Johto,
	[REGION_HOENN]   = sRegionString_Hoenn,
	[REGION_ORRE]    = sRegionString_Orre,
	[REGION_SINNOH]  = sRegionString_Sinnoh,
};

const u8 gText_TrainerMemo_Standard[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nMet at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Hatched[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nHatched at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Trade[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\nObtained in {DYNAMIC 0}a trade{DYNAMIC 1}.\n\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Fateful[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\nObtained in a\n{DYNAMIC 0}fateful encounter{DYNAMIC 1} at {LV_2}{DYNAMIC 3}.\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Untrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nApparently met at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_HatchedUntrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nApparently hatched at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_EggFromDayCare[] = _("An odd Pokémon Egg found\nby {DYNAMIC 0}the Day Care couple{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _("An peculiar Pokémon Egg\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _("A peculiar Pokémon Egg\nobtained at {DYNAMIC 0}a nice place{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _("A peculiar Pokémon Egg\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _("A Pokémon Egg obtained\nat {DYNAMIC 0}the hot springs{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _("An odd Pokémon Egg\nobtained from {DYNAMIC 0}a traveler{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromElm[] = _("A Pokémon Egg obtained\nfrom {DYNAMIC 0}Prof. Elm.{DYNAMIC 1}\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromPokecomCenter[] = _("An odd Pokémon Egg\nobtained at {DYNAMIC 0}the PokéCom\nCenter{DYNAMIC 1} in {DYNAMIC 0}Goldenrod City{DYNAMIC 1}.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _("An odd Pokémon Egg found\nby {DYNAMIC 0}the Day Care couple{DYNAMIC 1}\nin the {DYNAMIC 0}Kanto{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromJohto[] = _("An odd Pokémon Egg found\nby {DYNAMIC 0}the Day Care couple{DYNAMIC 1}\nin the {DYNAMIC 0}Johto{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _("A Pokémon Egg obtained\nfrom {DYNAMIC 0}Brigette{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _("A very mysterious\nPokémon Egg.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}'s old friend\nfrom {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\nreceived from {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nin {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\ngiven to {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} by his dad\nin {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");

//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("Battle Tower");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("A Distant Land");
static const u8 sMapName_OutskirtStand[] = _("Outskirt Stand");
static const u8 sMapName_PhenacCity[] = _("Phenac City");
static const u8 sMapName_MayorsHouse[] = _("Mayor's House");
static const u8 sMapName_PreGym[] = _("Pre Gym");
static const u8 sMapName_PhenacStadium[] = _("Phenac Stadium");
static const u8 sMapName_PyriteTown[] = _("Pyrite Town");
static const u8 sMapName_PyriteBldg[] = _("Pyrite Bldg");
static const u8 sMapName_PyriteCave[] = _("Pyrite Cave");
static const u8 sMapName_MirorsHideout[] = _("Miror's Hideout");
static const u8 sMapName_PyriteColosseum[] = _("Pyrite Colosseum");
static const u8 sMapName_AgateVillage[] = _("Agate Village");
static const u8 sMapName_RelicCave[] = _("Relic Cave");
static const u8 sMapName_TheUnder[] = _("The Under");
static const u8 sMapName_TheUnderSubway[] = _("The Under Subway");
static const u8 sMapName_UnderColosseum[] = _("Under Colosseum");
static const u8 sMapName_DeepColosseum[] = _("Deep Colosseum");
static const u8 sMapName_FrontOfLab[] = _("Front Of Lab");
static const u8 sMapName_Laboratory[] = _("Laboratory");
static const u8 sMapName_MtBattle[] = _("Mt. Battle");
static const u8 sMapName_MtBtlColosseum[] = _("Mt.Btl Colosseum");
static const u8 sMapName_RealgamTower[] = _("Realgam Tower");
static const u8 sMapName_RealgamTwrDome[] = _("Realgamtwr Dome");
static const u8 sMapName_RealgamTwrLobby[] = _("Realgamtwr Lobby");
static const u8 sMapName_TowerColosseum[] = _("Tower Colosseum");
static const u8 sMapName_OrreColosseum[] = _("Orre Colosseum");
static const u8 sMapName_SnagemHideout[] = _("Snagem Hideout");
static const u8 sMapName_RealgamTower2F[] = _("Realgam Tower 2F");
static const u8 sMapName_CipherLab[] = _("Cipher Lab");
static const u8 sMapName_SSLibra[] = _("S.S. Libra");
static const u8 sMapName_CipherKeyLair[] = _("Cipher Key Lair");
static const u8 sMapName_CitadarkIsle[] = _("Citadark Isle");
static const u8 sMapName_Rock[] = _("Rock");
static const u8 sMapName_Oasis[] = _("Oasis");
static const u8 sMapName_Cave[] = _("Cave");
static const u8 sMapName_PokemonHQLab[] = _("Pokémon HQ Lab");
static const u8 sMapName_GateonPort[] = _("Gateon Port");
static const u8 sMapName_KaminkosHouse[] = _("Kaminko's House");

//Sinnoh location for Porygon
static const u8 sMapName_VeilstoneCity[] = _("Veilstone City");

//Johto met locations using CrystalDust's IDs
static const u8 sMapName_NewBarkTown[] = _("New Bark Town");
static const u8 sMapName_CherrygroveCity[] = _("Cherrygrove City");
static const u8 sMapName_AzaleaTown[] = _("Azalea Town");
static const u8 sMapName_CianwoodCity[] = _("Cianwood City");
static const u8 sMapName_MahoganyTown[] = _("Mahogany Town");
static const u8 sMapName_VioletCity[] = _("Violet City");
static const u8 sMapName_EcruteakCity[] = _("Ecruteak City");
static const u8 sMapName_OlivineCity[] = _("Olivine City");
static const u8 sMapName_GoldenrodCity[] = _("Goldenrod City");
static const u8 sMapName_BlackthornCity[] = _("Blackthorn City");
static const u8 sMapName_Route29[] = _("Route 29");
static const u8 sMapName_Route30[] = _("Route 30");
static const u8 sMapName_Route31[] = _("Route 31");
static const u8 sMapName_Route32[] = _("Route 32");
static const u8 sMapName_Route33[] = _("Route 33");
static const u8 sMapName_Route34[] = _("Route 34");
static const u8 sMapName_Route35[] = _("Route 35");
static const u8 sMapName_Route36[] = _("Route 36");
static const u8 sMapName_Route37[] = _("Route 37");
static const u8 sMapName_Route38[] = _("Route 38");
static const u8 sMapName_Route39[] = _("Route 39");
static const u8 sMapName_Route40[] = _("Route 40");
static const u8 sMapName_Route41[] = _("Route 41");
static const u8 sMapName_Route42[] = _("Route 42");
static const u8 sMapName_Route43[] = _("Route 43");
static const u8 sMapName_Route44[] = _("Route 44");
static const u8 sMapName_Route45[] = _("Route 45");
static const u8 sMapName_Route46[] = _("Route 46");
static const u8 sMapName_Route26[] = _("Route 26");
static const u8 sMapName_Route27[] = _("Route 27");
static const u8 sMapName_Route28[] = _("Route 28");
static const u8 sMapName_DarkCave[] = _("Dark Cave");
static const u8 sMapName_SlowpokeWell_B1F[] = _("Slowpoke Well");
static const u8 sMapName_BattleFrontier[] = _("Battle Frontier");
static const u8 sMapName_IlexForest[] = _("Ilex Forest");
static const u8 sMapName_UnionCave[] = _("Union Cave");
static const u8 sMapName_SproutTower[] = _("Sprout Tower");
static const u8 sMapName_RuinsOfAlph[] = _("Ruins Of Alph");
static const u8 sMapName_AlphChambers[] = _("Alph Chambers");
static const u8 sMapName_RadioTower[] = _("Radio Tower");
static const u8 sMapName_MtMortar[] = _("Mt. Mortar");
static const u8 sMapName_Lighthouse[] = _("Lighthouse");
static const u8 sMapName_DragonsDen[] = _("Dragon's Den");
static const u8 sMapName_LakeOfRage[] = _("Lake Of Rage");
static const u8 sMapName_NationalPark[] = _("National Park");
static const u8 sMapName_IcePath[] = _("Ice Path");
static const u8 sMapName_SilverCave[] = _("Silver Cave");
static const u8 sMapName_WhirlIslands[] = _("Whirl Islands");
static const u8 sMapName_TinTower[] = _("Tin Tower");

const u8 *const gOrreMapNamePointers[] =
{
	[MAPSEC_DISTANT_LAND]               = sMapName_DistantLand,
	[MAPSEC_OUTSKIRT_STAND]             = sMapName_OutskirtStand,
	[MAPSEC_PHENAC_CITY]                = sMapName_PhenacCity,
	[MAPSEC_MAYORS_HOUSE]               = sMapName_MayorsHouse,
	[MAPSEC_PRE_GYM]                    = sMapName_PreGym,
	[MAPSEC_PHENAC_STADIUM]             = sMapName_PhenacStadium,
	[MAPSEC_PYRITE_TOWN]                = sMapName_PyriteTown,
	[MAPSEC_PYRITE_BLDG]                = sMapName_PyriteBldg,
	[MAPSEC_PYRITE_CAVE]                = sMapName_PyriteCave,
	[MAPSEC_MIRORS_HIDEOUT]             = sMapName_MirorsHideout,
	[MAPSEC_PYRITE_COLOSSEUM]           = sMapName_PyriteColosseum,
	[MAPSEC_AGATE_VILLAGE]              = sMapName_AgateVillage,
	[MAPSEC_RELIC_CAVE]                 = sMapName_RelicCave,
	[MAPSEC_THE_UNDER]                  = sMapName_TheUnder,
	[MAPSEC_THE_UNDER_SUBWAY]           = sMapName_TheUnderSubway,
	[MAPSEC_UNDER_COLOSSEUM]            = sMapName_UnderColosseum,
	[MAPSEC_DEEP_COLOSSEUM]             = sMapName_DeepColosseum,
	[MAPSEC_FRONT_OF_LAB]               = sMapName_FrontOfLab,
	[MAPSEC_LABORATORY]                 = sMapName_Laboratory,
	[MAPSEC_MT_BATTLE]                  = sMapName_MtBattle,
	[MAPSEC_MTBTL_COLOSSEUM]            = sMapName_MtBtlColosseum,
	[MAPSEC_REALGAM_TOWER]              = sMapName_RealgamTower,
	[MAPSEC_REALGAMTWR_DOME]            = sMapName_RealgamTwrDome,
	[MAPSEC_REALGAMTWR_LOBBY]           = sMapName_RealgamTwrLobby,
	[MAPSEC_TOWER_COLOSSEUM]            = sMapName_TowerColosseum,
	[MAPSEC_ORRE_COLOSSEUM]             = sMapName_OrreColosseum,
	[MAPSEC_SNAGEM_HIDEOUT]             = sMapName_SnagemHideout,
	[MAPSEC_REALGAM_TOWER_2F]           = sMapName_RealgamTower2F,
	[MAPSEC_CIPHER_LAB]                 = sMapName_CipherLab,
	[MAPSEC_S_S_LIBRA]                  = sMapName_SSLibra,
	[MAPSEC_CIPHER_KEY_LAIR]            = sMapName_CipherKeyLair,
	[MAPSEC_CITADARK_ISLE]              = sMapName_CitadarkIsle,
	[MAPSEC_ROCK]                       = sMapName_Rock,
	[MAPSEC_OASIS]                      = sMapName_Oasis,
	[MAPSEC_CAVE]                       = sMapName_Cave,
	[MAPSEC_POKEMON_HQ_LAB]             = sMapName_PokemonHQLab,
	[MAPSEC_GATEON_PORT]                = sMapName_GateonPort,
	[MAPSEC_KAMINKOS_HOUSE]             = sMapName_KaminkosHouse
};

const u8 *const gSinnohMapNamePointers[] =
{
	[MAPSEC_VEILSTONE_CITY]             = sMapName_VeilstoneCity
};

const u8 *const gJohtoMapNamePointers[] =
{
	[MAPSEC_NEW_BARK_TOWN_CD]              = sMapName_NewBarkTown,
	[MAPSEC_CHERRYGROVE_CITY_CD]           = sMapName_CherrygroveCity,
	[MAPSEC_AZALEA_TOWN_CD]                = sMapName_AzaleaTown,
	[MAPSEC_CIANWOOD_CITY_CD]              = sMapName_CianwoodCity,
	[MAPSEC_MAHOGANY_TOWN_CD]              = sMapName_MahoganyTown,
	[MAPSEC_VIOLET_CITY_CD]                = sMapName_VioletCity,
	[MAPSEC_ECRUTEAK_CITY_CD]              = sMapName_EcruteakCity,
	[MAPSEC_OLIVINE_CITY_CD]               = sMapName_OlivineCity,
	[MAPSEC_GOLDENROD_CITY_CD]             = sMapName_GoldenrodCity,
	[MAPSEC_BLACKTHORN_CITY_CD]            = sMapName_BlackthornCity,
	[MAPSEC_ROUTE_29_CD]                   = sMapName_Route29,
	[MAPSEC_ROUTE_30_CD]                   = sMapName_Route30,
	[MAPSEC_ROUTE_31_CD]                   = sMapName_Route31,
	[MAPSEC_ROUTE_32_CD]                   = sMapName_Route32,
	[MAPSEC_ROUTE_33_CD]                   = sMapName_Route33,
	[MAPSEC_ROUTE_34_CD]                   = sMapName_Route34,
	[MAPSEC_ROUTE_35_CD]                   = sMapName_Route35,
	[MAPSEC_ROUTE_36_CD]                   = sMapName_Route36,
	[MAPSEC_ROUTE_37_CD]                   = sMapName_Route37,
	[MAPSEC_ROUTE_38_CD]                   = sMapName_Route38,
	[MAPSEC_ROUTE_39_CD]                   = sMapName_Route39,
	[MAPSEC_ROUTE_40_CD]                   = sMapName_Route40,
	[MAPSEC_ROUTE_41_CD]                   = sMapName_Route41,
	[MAPSEC_ROUTE_42_CD]                   = sMapName_Route42,
	[MAPSEC_ROUTE_43_CD]                   = sMapName_Route43,
	[MAPSEC_ROUTE_44_CD]                   = sMapName_Route44,
	[MAPSEC_ROUTE_45_CD]                   = sMapName_Route45,
	[MAPSEC_ROUTE_46_CD]                   = sMapName_Route46,
	[MAPSEC_ROUTE_26_CD]                   = sMapName_Route26,
	[MAPSEC_ROUTE_27_CD]                   = sMapName_Route27,
	[MAPSEC_ROUTE_28_CD]                   = sMapName_Route28,
	[MAPSEC_ROUTE_32_FLYDUP_CD]            = sMapName_Route32,
	[MAPSEC_DARK_CAVE_CD]                  = sMapName_DarkCave,
	[MAPSEC_SLOWPOKE_WELL_CD]              = sMapName_SlowpokeWell_B1F,
	[MAPSEC_BATTLE_FRONTIER_CD]            = sMapName_BattleFrontier,
	[MAPSEC_ILEX_FOREST_CD]                = sMapName_IlexForest,
	[MAPSEC_UNION_CAVE_CD]                 = sMapName_UnionCave,
	[MAPSEC_SPROUT_TOWER_CD]               = sMapName_SproutTower,
	[MAPSEC_RUINS_OF_ALPH_CD]              = sMapName_RuinsOfAlph,
	[MAPSEC_ALPH_CHAMBERS_CD]              = sMapName_AlphChambers,
	[MAPSEC_RADIO_TOWER_CD]                = sMapName_RadioTower,
	[MAPSEC_MT_MORTAR_CD]                  = sMapName_MtMortar,
	[MAPSEC_LIGHTHOUSE_CD]                 = sMapName_Lighthouse,
	[MAPSEC_DRAGONS_DEN_CD]                = sMapName_DragonsDen,
	[MAPSEC_LAKE_OF_RAGE_CD]               = sMapName_LakeOfRage,
	[MAPSEC_NATIONAL_PARK_CD]              = sMapName_NationalPark,
	[MAPSEC_ICE_PATH_CD]                   = sMapName_IcePath,
	[MAPSEC_SILVER_CAVE_CD]                = sMapName_SilverCave,
	[MAPSEC_WHIRL_ISLANDS_CD]              = sMapName_WhirlIslands,
	[MAPSEC_TIN_TOWER_CD]                  = sMapName_TinTower
};
