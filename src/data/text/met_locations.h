#define REGION_UNKNOWN	0
#define REGION_KANTO	1
#define REGION_JOHTO	2
#define REGION_HOENN	3
#define REGION_ORRE		4
#define REGION_SINNOH	5

static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", KANTO");
static const u8 sRegionString_Johto[] = _(", JOHTO");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", ORRE");
static const u8 sRegionString_Sinnoh[] = _(", SINNOH");

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
const u8 gText_TrainerMemo_EggFromDayCare[] = _("An odd POKéMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _("An peculiar POKéMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _("A peculiar POKéMON EGG\nobtained at {DYNAMIC 0}a nice place{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _("A peculiar POKéMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _("A POKéMON EGG obtained\nat {DYNAMIC 0}the hot springs{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _("An odd POKéMON EGG\nobtained from {DYNAMIC 0}a traveler{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromElm[] = _("A POKéMON EGG obtained\nfrom {DYNAMIC 0}PROF. ELM.{DYNAMIC 1}\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromPokecomCenter[] = _("An odd POKéMON EGG\nobtained at {DYNAMIC 0}the POKéCOM\nCENTER{DYNAMIC 1} in {DYNAMIC 0}GOLDENROD CITY{DYNAMIC 1}.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _("An odd POKéMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}\nin the {DYNAMIC 0}KANTO{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromJohto[] = _("An odd POKéMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}\nin the {DYNAMIC 0}JOHTO{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _("A POKéMON EGG obtained\nfrom {DYNAMIC 0}BRIGETTE{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _("A very mysterious\nPOKéMON EGG.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}'s old friend\nfrom {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\nreceived from {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\ngiven to {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} by his dad\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");

//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("BATTLE TOWER");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("A DISTANT LAND");
static const u8 sMapName_OutskirtStand[] = _("OUTSKIRT STAND");
static const u8 sMapName_PhenacCity[] = _("PHENAC CITY");
static const u8 sMapName_MayorsHouse[] = _("MAYOR'S HOUSE");
static const u8 sMapName_PreGym[] = _("PRE GYM");
static const u8 sMapName_PhenacStadium[] = _("PHENAC STADIUM");
static const u8 sMapName_PyriteTown[] = _("PYRITE TOWN");
static const u8 sMapName_PyriteBldg[] = _("PYRITE BLDG");
static const u8 sMapName_PyriteCave[] = _("PYRITE CAVE");
static const u8 sMapName_MirorsHideout[] = _("MIROR'S HIDEOUT");
static const u8 sMapName_PyriteColosseum[] = _("PYRITE COLOSSEUM");
static const u8 sMapName_AgateVillage[] = _("AGATE VILLAGE");
static const u8 sMapName_RelicCave[] = _("RELIC CAVE");
static const u8 sMapName_TheUnder[] = _("THE UNDER");
static const u8 sMapName_TheUnderSubway[] = _("THE UNDER SUBWAY");
static const u8 sMapName_UnderColosseum[] = _("UNDER COLOSSEUM");
static const u8 sMapName_DeepColosseum[] = _("DEEP COLOSSEUM");
static const u8 sMapName_FrontOfLab[] = _("FRONT OF LAB");
static const u8 sMapName_Laboratory[] = _("LABORATORY");
static const u8 sMapName_MtBattle[] = _("MT. BATTLE");
static const u8 sMapName_MtBtlColosseum[] = _("MT.BTL COLOSSEUM");
static const u8 sMapName_RealgamTower[] = _("REALGAM TOWER");
static const u8 sMapName_RealgamTwrDome[] = _("REALGAMTWR DOME");
static const u8 sMapName_RealgamTwrLobby[] = _("REALGAMTWR LOBBY");
static const u8 sMapName_TowerColosseum[] = _("TOWER COLOSSEUM");
static const u8 sMapName_OrreColosseum[] = _("ORRE COLOSSEUM");
static const u8 sMapName_SnagemHideout[] = _("SNAGEM HIDEOUT");
static const u8 sMapName_RealgamTower2F[] = _("REALGAM TOWER 2F");
static const u8 sMapName_CipherLab[] = _("CIPHER LAB");
static const u8 sMapName_SSLibra[] = _("S.S. LIBRA");
static const u8 sMapName_CipherKeyLair[] = _("CIPHER KEY LAIR");
static const u8 sMapName_CitadarkIsle[] = _("CITADARK ISLE");
static const u8 sMapName_Rock[] = _("ROCK");
static const u8 sMapName_Oasis[] = _("OASIS");
static const u8 sMapName_Cave[] = _("CAVE");
static const u8 sMapName_PokemonHQLab[] = _("POKéMON HQ LAB");
static const u8 sMapName_GateonPort[] = _("GATEON PORT");
static const u8 sMapName_KaminkosHouse[] = _("KAMINKO'S HOUSE");

//Sinnoh location for Porygon
static const u8 sMapName_VeilstoneCity[] = _("VEILSTONE CITY");

//Johto met locations using CrystalDust's IDs
static const u8 sMapName_NewBarkTown[] = _("NEW BARK TOWN");
static const u8 sMapName_CherrygroveCity[] = _("CHERRYGROVE CITY");
static const u8 sMapName_AzaleaTown[] = _("AZALEA TOWN");
static const u8 sMapName_CianwoodCity[] = _("CIANWOOD CITY");
static const u8 sMapName_MahoganyTown[] = _("MAHOGANY TOWN");
static const u8 sMapName_VioletCity[] = _("VIOLET CITY");
static const u8 sMapName_EcruteakCity[] = _("ECRUTEAK CITY");
static const u8 sMapName_OlivineCity[] = _("OLIVINE CITY");
static const u8 sMapName_GoldenrodCity[] = _("GOLDENROD CITY");
static const u8 sMapName_BlackthornCity[] = _("BLACKTHORN CITY");
static const u8 sMapName_Route29[] = _("ROUTE 29");
static const u8 sMapName_Route30[] = _("ROUTE 30");
static const u8 sMapName_Route31[] = _("ROUTE 31");
static const u8 sMapName_Route32[] = _("ROUTE 32");
static const u8 sMapName_Route33[] = _("ROUTE 33");
static const u8 sMapName_Route34[] = _("ROUTE 34");
static const u8 sMapName_Route35[] = _("ROUTE 35");
static const u8 sMapName_Route36[] = _("ROUTE 36");
static const u8 sMapName_Route37[] = _("ROUTE 37");
static const u8 sMapName_Route38[] = _("ROUTE 38");
static const u8 sMapName_Route39[] = _("ROUTE 39");
static const u8 sMapName_Route40[] = _("ROUTE 40");
static const u8 sMapName_Route41[] = _("ROUTE 41");
static const u8 sMapName_Route42[] = _("ROUTE 42");
static const u8 sMapName_Route43[] = _("ROUTE 43");
static const u8 sMapName_Route44[] = _("ROUTE 44");
static const u8 sMapName_Route45[] = _("ROUTE 45");
static const u8 sMapName_Route46[] = _("ROUTE 46");
static const u8 sMapName_Route26[] = _("ROUTE 26");
static const u8 sMapName_Route27[] = _("ROUTE 27");
static const u8 sMapName_Route28[] = _("ROUTE 28");
static const u8 sMapName_DarkCave[] = _("DARK CAVE");
static const u8 sMapName_SlowpokeWell_B1F[] = _("SLOWPOKE WELL");
static const u8 sMapName_BattleFrontier[] = _("BATTLE FRONTIER");
static const u8 sMapName_IlexForest[] = _("ILEX FOREST");
static const u8 sMapName_UnionCave[] = _("UNION CAVE");
static const u8 sMapName_SproutTower[] = _("SPROUT TOWER");
static const u8 sMapName_RuinsOfAlph[] = _("RUINS OF ALPH");
static const u8 sMapName_AlphChambers[] = _("ALPH CHAMBERS");
static const u8 sMapName_RadioTower[] = _("RADIO TOWER");
static const u8 sMapName_MtMortar[] = _("MT. MORTAR");
static const u8 sMapName_Lighthouse[] = _("LIGHTHOUSE");
static const u8 sMapName_DragonsDen[] = _("DRAGON'S DEN");
static const u8 sMapName_LakeOfRage[] = _("LAKE OF RAGE");
static const u8 sMapName_NationalPark[] = _("NATIONAL PARK");
static const u8 sMapName_IcePath[] = _("ICE PATH");
static const u8 sMapName_SilverCave[] = _("SILVER CAVE");
static const u8 sMapName_WhirlIslands[] = _("WHIRL ISLANDS");
static const u8 sMapName_TinTower[] = _("TIN TOWER");

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
