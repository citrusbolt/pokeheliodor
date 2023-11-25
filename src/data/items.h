const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
        .gameCubeName = _("MASTER BALL"),
        .price = 0,
        .description = sMasterBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_MASTER_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_MASTER,
    },

    [ITEM_ULTRA_BALL] =
    {
        .gameCubeName = _("ULTRA BALL"),
        .price = 1200,
        .description = sUltraBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_POKE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_ULTRA,
    },

    [ITEM_GREAT_BALL] =
    {
        .gameCubeName = _("GREAT BALL"),
        .price = 600,
        .description = sGreatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_GREAT_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_GREAT,
    },

    [ITEM_POKE_BALL] =
    {
        .gameCubeName = _("POKé BALL"),
        .price = 200,
        .description = sPokeBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_POKE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_POKE,
    },

    [ITEM_SAFARI_BALL] =
    {
        .gameCubeName = _("SAFARI BALL"),
        .price = 0,
        .description = sSafariBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_SAFARI_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_SAFARI,
    },

    [ITEM_NET_BALL] =
    {
        .gameCubeName = _("NET BALL"),
        .price = 1000,
        .description = sNetBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_NET_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_NET,
    },

    [ITEM_DIVE_BALL] =
    {
        .gameCubeName = _("DIVE BALL"),
        .price = 1000,
        .description = sDiveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_DIVE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_DIVE,
    },

    [ITEM_NEST_BALL] =
    {
        .gameCubeName = _("NEST BALL"),
        .price = 1000,
        .description = sNestBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_NEST_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_NEST,
    },

    [ITEM_REPEAT_BALL] =
    {
        .gameCubeName = _("REPEAT BALL"),
        .price = 1000,
        .description = sRepeatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_REPEAT_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_REPEAT,
    },

    [ITEM_TIMER_BALL] =
    {
        .gameCubeName = _("TIMER BALL"),
        .price = 1000,
        .description = sTimerBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_TIMER_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_TIMER,
    },

    [ITEM_LUXURY_BALL] =
    {
        .gameCubeName = _("LUXURY BALL"),
        .price = 1000,
        .description = sLuxuryBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_LUXURY_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_LUXURY,
    },

    [ITEM_PREMIER_BALL] =
    {
        .gameCubeName = _("PREMIER BALL"),
        .price = 200,
        .description = sPremierBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_PREMIER_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_PREMIER,
    },

// Medicine

    [ITEM_POTION] =
    {
        .gameCubeName = _("POTION"),
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_POTION,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ANTIDOTE] =
    {
        .gameCubeName = _("ANTIDOTE"),
        .price = 100,
        .description = sAntidoteDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ANTIDOTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BURN_HEAL] =
    {
        .gameCubeName = _("BURN HEAL"),
        .price = 250,
        .description = sBurnHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_BURN_HEAL,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ICE_HEAL] =
    {
        .gameCubeName = _("ICE HEAL"),
        .price = 250,
        .description = sIceHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ICE_HEAL,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_AWAKENING] =
    {
        .gameCubeName = _("AWAKENING"),
        .price = 250,
        .description = sAwakeningDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_AWAKENING,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .gameCubeName = _("PARLYZ HEAL"),
        .price = 200,
        .description = sParalyzeHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_PARALYZE_HEAL,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_RESTORE] =
    {
        .gameCubeName = _("FULL RESTORE"),
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_FULL_RESTORE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_POTION] =
    {
        .gameCubeName = _("MAX POTION"),
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_MAX_POTION,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HYPER_POTION] =
    {
        .gameCubeName = _("HYPER POTION"),
        .price = 1200,
        .holdEffectParam = 200,
        .description = sHyperPotionDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_HYPER_POTION,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SUPER_POTION] =
    {
        .gameCubeName = _("SUPER POTION"),
        .price = 700,
        .holdEffectParam = 50,
        .description = sSuperPotionDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_SUPER_POTION,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_HEAL] =
    {
        .gameCubeName = _("FULL HEAL"),
        .price = 600,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_FULL_HEAL,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVE] =
    {
        .gameCubeName = _("REVIVE"),
        .price = 1500,
        .description = sReviveDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_REVIVE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_REVIVE] =
    {
        .gameCubeName = _("MAX REVIVE"),
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_MAX_REVIVE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FRESH_WATER] =
    {
        .gameCubeName = _("FRESH WATER"),
        .price = 200,
        .holdEffectParam = 50,
        .description = sFreshWaterDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_FRESH_WATER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SODA_POP] =
    {
        .gameCubeName = _("SODA POP"),
        .price = 300,
        .holdEffectParam = 60,
        .description = sSodaPopDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_SODA_POP,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEMONADE] =
    {
        .gameCubeName = _("LEMONADE"),
        .price = 350,
        .holdEffectParam = 80,
        .description = sLemonadeDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_LEMONADE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .gameCubeName = _("MOOMOO MILK"),
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_MOOMOO_MILK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .gameCubeName = _("ENERGYPOWDER"),
        .price = 500,
        .description = sEnergyPowderDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ENERGY_POWDER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .gameCubeName = _("ENERGY ROOT"),
        .price = 800,
        .description = sEnergyRootDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ENERGY_ROOT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HEAL_POWDER] =
    {
        .gameCubeName = _("HEAL POWDER"),
        .price = 450,
        .description = sHealPowderDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_HEAL_POWDER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .gameCubeName = _("REVIVAL HERB"),
        .price = 2800,
        .description = sRevivalHerbDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_REVIVAL_HERB,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ETHER] =
    {
        .gameCubeName = _("ETHER"),
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ETHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ETHER] =
    {
        .gameCubeName = _("MAX ETHER"),
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_MAX_ETHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ELIXIR] =
    {
        .gameCubeName = _("ELIXIR"),
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_ELIXIR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .gameCubeName = _("MAX ELIXIR"),
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_MAX_ELIXIR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .gameCubeName = _("LAVA COOKIE"),
        .price = 200,
        .description = sLavaCookieDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_LAVA_COOKIE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLUE_FLUTE] =
    {
        .gameCubeName = _("BLUE FLUTE"),
        .price = 100,
        .description = sBlueFluteDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_BLUE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .gameCubeName = _("YELLOW FLUTE"),
        .price = 200,
        .description = sYellowFluteDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_YELLOW_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RED_FLUTE] =
    {
        .gameCubeName = _("RED FLUTE"),
        .price = 300,
        .description = sRedFluteDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_RED_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLACK_FLUTE] =
    {
        .gameCubeName = _("BLACK FLUTE"),
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BLACK_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .gameCubeName = _("WHITE FLUTE"),
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_WHITE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_BERRY_JUICE] =
    {
        .gameCubeName = _("BERRY JUICE"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_BERRY_JUICE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SACRED_ASH] =
    {
        .gameCubeName = _("SACRED ASH"),
        .price = 200,
        .description = sSacredAshDesc,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_MEDICINE_SACRED_ASH,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
        .gameCubeName = _("SHOAL SALT"),
        .price = 20,
        .description = sShoalSaltDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_SHOAL_SALT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .gameCubeName = _("SHOAL SHELL"),
        .price = 20,
        .description = sShoalShellDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_SHOAL_SHELL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SHARD] =
    {
        .gameCubeName = _("RED SHARD"),
        .price = 200,
        .description = sRedShardDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_RED_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SHARD] =
    {
        .gameCubeName = _("BLUE SHARD"),
        .price = 200,
        .description = sBlueShardDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_BLUE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .gameCubeName = _("YELLOW SHARD"),
        .price = 200,
        .description = sYellowShardDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_YELLOW_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SHARD] =
    {
        .gameCubeName = _("GREEN SHARD"),
        .price = 200,
        .description = sGreenShardDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_GREEN_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_034] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_035] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_036] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_037] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_038] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_039] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03A] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03B] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03C] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03D] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03E] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .gameCubeName = _("HP UP"),
        .price = 9800,
        .description = sHPUpDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_HP_UP,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PROTEIN] =
    {
        .gameCubeName = _("PROTEIN"),
        .price = 9800,
        .description = sProteinDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_PROTEIN,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_IRON] =
    {
        .gameCubeName = _("IRON"),
        .price = 9800,
        .description = sIronDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_IRON,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CARBOS] =
    {
        .gameCubeName = _("CARBOS"),
        .price = 9800,
        .description = sCarbosDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CARBOS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CALCIUM] =
    {
        .gameCubeName = _("CALCIUM"),
        .price = 9800,
        .description = sCalciumDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CALCIUM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_RARE_CANDY] =
    {
        .gameCubeName = _("RARE CANDY"),
        .price = 4800,
        .description = sRareCandyDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_RARE_CANDY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
    },

    [ITEM_PP_UP] =
    {
        .gameCubeName = _("PP UP"),
        .price = 9800,
        .description = sPPUpDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_PP_UP,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_ZINC] =
    {
        .gameCubeName = _("ZINC"),
        .price = 9800,
        .description = sZincDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_ZINC,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PP_MAX] =
    {
        .gameCubeName = _("PP MAX"),
        .price = 9800,
        .description = sPPMaxDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_PP_MAX,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_048] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
        .gameCubeName = _("GUARD SPEC."),
        .price = 700,
        .description = sGuardSpecDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_GUARD_SPEC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_DIRE_HIT] =
    {
        .gameCubeName = _("DIRE HIT"),
        .price = 650,
        .description = sDireHitDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_DIRE_HIT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ATTACK] =
    {
        .gameCubeName = _("X ATTACK"),
        .price = 500,
        .description = sXAttackDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_X_ATTACK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_DEFEND] =
    {
        .gameCubeName = _("X DEFEND"),
        .price = 550,
        .description = sXDefendDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_X_DEFEND,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPEED] =
    {
        .gameCubeName = _("X SPEED"),
        .price = 350,
        .description = sXSpeedDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_X_SPEED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ACCURACY] =
    {
        .gameCubeName = _("X ACCURACY"),
        .price = 950,
        .description = sXAccuracyDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = 4,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPECIAL] =
    {
        .gameCubeName = _("X SPECIAL"),
        .price = 350,
        .description = sXSpecialDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_X_SPECIAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_POKE_DOLL] =
    {
        .gameCubeName = _("POKé DOLL"),
        .price = 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_POKE_DOLL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .gameCubeName = _("FLUFFY TAIL"),
        .price = 1000,
        .description = sFluffyTailDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortId = SORT_BATTLE_FLUFFY_TAIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_052] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
        .gameCubeName = _("SUPER REPEL"),
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SUPER_REPEL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_MAX_REPEL] =
    {
        .gameCubeName = _("MAX REPEL"),
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MAX_REPEL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .gameCubeName = _("ESCAPE ROPE"),
        .price = 550,
        .description = sEscapeRopeDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_ESCAPE_ROPE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
    },

    [ITEM_REPEL] =
    {
        .gameCubeName = _("REPEL"),
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_REPEL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_057] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_058] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_059] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05A] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05B] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05C] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
        .gameCubeName = _("SUN STONE"),
        .price = 2100,
        .description = sSunStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SUN_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_MOON_STONE] =
    {
        .gameCubeName = _("MOON STONE"),
        .price = 0,
        .description = sMoonStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MOON_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_FIRE_STONE] =
    {
        .gameCubeName = _("FIRE STONE"),
        .price = 2100,
        .description = sFireStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_FIRE_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .gameCubeName = _("THUNDERSTONE"),
        .price = 2100,
        .description = sThunderStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_THUNDER_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_WATER_STONE] =
    {
        .gameCubeName = _("WATER STONE"),
        .price = 2100,
        .description = sWaterStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_WATER_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .gameCubeName = _("LEAF STONE"),
        .price = 2100,
        .description = sLeafStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LEAF_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_063] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_064] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_065] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_066] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Valuable items

    [ITEM_TINY_MUSHROOM] =
    {
        .gameCubeName = _("TINYMUSHROOM"),
        .price = 500,
        .description = sTinyMushroomDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_TINY_MUSHROOM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .gameCubeName = _("BIG MUSHROOM"),
        .price = 5000,
        .description = sBigMushroomDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_BIG_MUSHROOM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_069] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PEARL] =
    {
        .gameCubeName = _("PEARL"),
        .price = 1400,
        .description = sPearlDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_PEARL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_PEARL] =
    {
        .gameCubeName = _("BIG PEARL"),
        .price = 7500,
        .description = sBigPearlDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_BIG_PEARL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARDUST] =
    {
        .gameCubeName = _("STARDUST"),
        .price = 2000,
        .description = sStardustDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_STARDUST,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STAR_PIECE] =
    {
        .gameCubeName = _("STAR PIECE"),
        .price = 9800,
        .description = sStarPieceDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_STAR_PIECE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NUGGET] =
    {
        .gameCubeName = _("NUGGET"),
        .price = 10000,
        .description = sNuggetDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_NUGGET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEART_SCALE] =
    {
        .gameCubeName = _("HEART SCALE"),
        .price = 100,
        .description = sHeartScaleDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_HEART_SCALE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_070] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_071] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_072] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_073] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_074] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_075] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_076] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_077] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_078] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
        .gameCubeName = _("ORANGE MAIL"),
        .price = 50,
        .description = sOrangeMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
        .gameCubeName = _("HARBOR MAIL"),
        .price = 50,
        .description = sHarborMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
        .gameCubeName = _("GLITTER MAIL"),
        .price = 50,
        .description = sGlitterMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
        .gameCubeName = _("MECH MAIL"),
        .price = 50,
        .description = sMechMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
        .gameCubeName = _("WOOD MAIL"),
        .price = 50,
        .description = sWoodMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
        .gameCubeName = _("WAVE MAIL"),
        .price = 50,
        .description = sWaveMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
        .gameCubeName = _("BEAD MAIL"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
        .gameCubeName = _("SHADOW MAIL"),
        .price = 50,
        .description = sShadowMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
        .gameCubeName = _("TROPIC MAIL"),
        .price = 50,
        .description = sTropicMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
        .gameCubeName = _("DREAM MAIL"),
        .price = 50,
        .description = sDreamMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
        .gameCubeName = _("FAB MAIL"),
        .price = 50,
        .description = sFabMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
        .gameCubeName = _("RETRO MAIL"),
        .price = 50,
        .description = sRetroMailDesc,
        .pocket = POCKET_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .gameCubeName = _("CHERI BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = sCheriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .gameCubeName = _("CHESTO BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = sChestoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PECHA_BERRY] =
    {
        .gameCubeName = _("PECHA BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = sPechaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RAWST_BERRY] =
    {
        .gameCubeName = _("RAWST BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = sRawstBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .gameCubeName = _("ASPEAR BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = sAspearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .gameCubeName = _("LEPPA BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ORAN_BERRY] =
    {
        .gameCubeName = _("ORAN BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .gameCubeName = _("PERSIM BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = sPersimBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LUM_BERRY] =
    {
        .gameCubeName = _("LUM BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = sLumBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .gameCubeName = _("SITRUS BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = sSitrusBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FIGY_BERRY] =
    {
        .gameCubeName = _("FIGY BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WIKI_BERRY] =
    {
        .gameCubeName = _("WIKI BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGO_BERRY] =
    {
        .gameCubeName = _("MAGO BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .gameCubeName = _("AGUAV BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .gameCubeName = _("IAPAPA BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .gameCubeName = _("RAZZ BERRY"),
        .price = 20,
        .description = sRazzBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUK_BERRY] =
    {
        .gameCubeName = _("BLUK BERRY"),
        .price = 20,
        .description = sBlukBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NANAB_BERRY] =
    {
        .gameCubeName = _("NANAB BERRY"),
        .price = 20,
        .description = sNanabBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .gameCubeName = _("WEPEAR BERRY"),
        .price = 20,
        .description = sWepearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINAP_BERRY] =
    {
        .gameCubeName = _("PINAP BERRY"),
        .price = 20,
        .description = sPinapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POMEG_BERRY] =
    {
        .gameCubeName = _("POMEG BERRY"),
        .price = 20,
        .description = sPomegBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .gameCubeName = _("KELPSY BERRY"),
        .price = 20,
        .description = sKelpsyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .gameCubeName = _("QUALOT BERRY"),
        .price = 20,
        .description = sQualotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .gameCubeName = _("HONDEW BERRY"),
        .price = 20,
        .description = sHondewBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_GREPA_BERRY] =
    {
        .gameCubeName = _("GREPA BERRY"),
        .price = 20,
        .description = sGrepaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .gameCubeName = _("TAMATO BERRY"),
        .price = 20,
        .description = sTamatoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_CORNN_BERRY] =
    {
        .gameCubeName = _("CORNN BERRY"),
        .price = 20,
        .description = sCornnBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .gameCubeName = _("MAGOST BERRY"),
        .price = 20,
        .description = sMagostBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .gameCubeName = _("RABUTA BERRY"),
        .price = 20,
        .description = sRabutaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .gameCubeName = _("NOMEL BERRY"),
        .price = 20,
        .description = sNomelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELON_BERRY] =
    {
        .gameCubeName = _("SPELON BERRY"),
        .price = 20,
        .description = sSpelonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .gameCubeName = _("PAMTRE BERRY"),
        .price = 20,
        .description = sPamtreBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .gameCubeName = _("WATMEL BERRY"),
        .price = 20,
        .description = sWatmelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DURIN_BERRY] =
    {
        .gameCubeName = _("DURIN BERRY"),
        .price = 20,
        .description = sDurinBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BELUE_BERRY] =
    {
        .gameCubeName = _("BELUE BERRY"),
        .price = 20,
        .description = sBelueBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .gameCubeName = _("LIECHI BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GANLON_BERRY] =
    {
        .gameCubeName = _("GANLON BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SALAC_BERRY] =
    {
        .gameCubeName = _("SALAC BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .gameCubeName = _("PETAYA BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_APICOT_BERRY] =
    {
        .gameCubeName = _("APICOT BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .gameCubeName = _("LANSAT BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARF_BERRY] =
    {
        .gameCubeName = _("STARF BERRY"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .gameCubeName = _("ENIGMA BERRY"),
        .price = 20,
        .description = sEnigmaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
        .gameCubeName = _("BRIGHTPOWDER"),
        .price = 10,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BRIGHT_POWDER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_HERB] =
    {
        .gameCubeName = _("WHITE HERB"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = sWhiteHerbDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_WHITE_HERB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACHO_BRACE] =
    {
        .gameCubeName = _("MACHO BRACE"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = sMachoBraceDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MACHO_BRACE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_SHARE] =
    {
        .gameCubeName = _("EXP. SHARE"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = sExpShareDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_EXP_SHARE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_QUICK_CLAW] =
    {
        .gameCubeName = _("QUICK CLAW"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_QUICK_CLAW,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .gameCubeName = _("SOOTHE BELL"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = sSootheBellDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SOOTHE_BELL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MENTAL_HERB] =
    {
        .gameCubeName = _("MENTAL HERB"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
        .description = sMentalHerbDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MENTAL_HERB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHOICE_BAND] =
    {
        .gameCubeName = _("CHOICE BAND"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = sChoiceBandDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CHOICE_BAND,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KINGS_ROCK] =
    {
        .gameCubeName = _("KING'S ROCK"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_KINGS_ROCK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILVER_POWDER] =
    {
        .gameCubeName = _("SILVERPOWDER"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SILVER_POWDER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AMULET_COIN] =
    {
        .gameCubeName = _("AMULET COIN"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_AMULET_COIN,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .gameCubeName = _("CLEANSE TAG"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sCleanseTagDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CLEANSE_TAG,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOUL_DEW] =
    {
        .gameCubeName = _("SOUL DEW"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .description = sSoulDewDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SOUL_DEW,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .gameCubeName = _("DEEPSEATOOTH"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = sDeepSeaToothDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_DEEP_SEA_TOOTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .gameCubeName = _("DEEPSEASCALE"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = sDeepSeaScaleDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_DEEP_SEA_SCALE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SMOKE_BALL] =
    {
        .gameCubeName = _("SMOKE BALL"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = sSmokeBallDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SMOKE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EVERSTONE] =
    {
        .gameCubeName = _("EVERSTONE"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = sEverstoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_EVERSTONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FOCUS_BAND] =
    {
        .gameCubeName = _("FOCUS BAND"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_FOCUS_BAND,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_EGG] =
    {
        .gameCubeName = _("LUCKY EGG"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = sLuckyEggDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LUCKY_EGG,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCOPE_LENS] =
    {
        .gameCubeName = _("SCOPE LENS"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = sScopeLensDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SCOPE_LENS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_COAT] =
    {
        .gameCubeName = _("METAL COAT"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_METAL_COAT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEFTOVERS] =
    {
        .gameCubeName = _("LEFTOVERS"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LEFTOVERS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .gameCubeName = _("DRAGON SCALE"),
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_DRAGON_SCALE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIGHT_BALL] =
    {
        .gameCubeName = _("LIGHT BALL"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = sLightBallDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LIGHT_BALL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOFT_SAND] =
    {
        .gameCubeName = _("SOFT SAND"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SOFT_SAND,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HARD_STONE] =
    {
        .gameCubeName = _("HARD STONE"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_HARD_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .gameCubeName = _("MIRACLE SEED"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MIRACLE_SEED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .gameCubeName = _("BLACKGLASSES"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BLACK_GLASSES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_BELT] =
    {
        .gameCubeName = _("BLACK BELT"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BLACK_BELT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGNET] =
    {
        .gameCubeName = _("MAGNET"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MAGNET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .gameCubeName = _("MYSTIC WATER"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MYSTIC_WATER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHARP_BEAK] =
    {
        .gameCubeName = _("SHARP BEAK"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SHARP_BEAK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_BARB] =
    {
        .gameCubeName = _("POISON BARB"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_POISON_BARB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .gameCubeName = _("NEVERMELTICE"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_NEVER_MELT_ICE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELL_TAG] =
    {
        .gameCubeName = _("SPELL TAG"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SPELL_TAG,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .gameCubeName = _("TWISTEDSPOON"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_TWISTED_SPOON,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHARCOAL] =
    {
        .gameCubeName = _("CHARCOAL"),
        .price = 9800,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CHARCOAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_FANG] =
    {
        .gameCubeName = _("DRAGON FANG"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_DRAGON_FANG,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILK_SCARF] =
    {
        .gameCubeName = _("SILK SCARF"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SILK_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UP_GRADE] =
    {
        .gameCubeName = _("UP-GRADE"),
        .price = 2100,
        .holdEffect = HOLD_EFFECT_UP_GRADE,
        .description = sUpGradeDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_UP_GRADE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHELL_BELL] =
    {
        .gameCubeName = _("SHELL BELL"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SHELL_BELL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SEA_INCENSE] =
    {
        .gameCubeName = _("SEA INCENSE"),
        .price = 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SEA_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LAX_INCENSE] =
    {
        .gameCubeName = _("LAX INCENSE"),
        .price = 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 5,
        .description = sLaxIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LAX_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .gameCubeName = _("LUCKY PUNCH"),
        .price = 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = sLuckyPunchDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LUCKY_PUNCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_POWDER] =
    {
        .gameCubeName = _("METAL POWDER"),
        .price = 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = sMetalPowderDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_METAL_POWDER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_THICK_CLUB] =
    {
        .gameCubeName = _("THICK CLUB"),
        .price = 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = sThickClubDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_THICK_CLUB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STICK] =
    {
        .gameCubeName = _("STICK"),
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICK,
        .description = sStickDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_STICK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E2] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E3] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E4] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E5] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E6] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E7] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E8] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E9] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EA] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EB] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EC] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0ED] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EE] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EF] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F0] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F1] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F2] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F3] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F4] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F5] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F6] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F7] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F8] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F9] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FA] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FB] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FC] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FD] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SCARF] =
    {
        .gameCubeName = _("RED SCARF"),
        .price = 100,
        .description = sRedScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_RED_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SCARF] =
    {
        .gameCubeName = _("BLUE SCARF"),
        .price = 100,
        .description = sBlueScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BLUE_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_SCARF] =
    {
        .gameCubeName = _("PINK SCARF"),
        .price = 100,
        .description = sPinkScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_PINK_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SCARF] =
    {
        .gameCubeName = _("GREEN SCARF"),
        .price = 100,
        .description = sGreenScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_GREEN_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .gameCubeName = _("YELLOW SCARF"),
        .price = 100,
        .description = sYellowScarfDesc,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_YELLOW_SCARF,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
        .gameCubeName = _("MACH BIKE"),
        .price = 0,
        .description = sMachBikeDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_MACH_BIKE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_COIN_CASE] =
    {
        .gameCubeName = _("COIN CASE"),
        .price = 0,
        .description = sCoinCaseDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_COIN_CASE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_ITEMFINDER] =
    {
        .gameCubeName = _("ITEMFINDER"),
        .price = 0,
        .description = sItemfinderDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ITEMFINDER,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_OLD_ROD] =
    {
        .gameCubeName = _("OLD ROD"),
        .price = 0,
        .description = sOldRodDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_OLD_ROD,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
        .gameCubeName = _("GOOD ROD"),
        .price = 0,
        .description = sGoodRodDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_GOOD_ROD,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
        .gameCubeName = _("SUPER ROD"),
        .price = 0,
        .description = sSuperRodDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SUPER_ROD,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_SS_TICKET] =
    {
        .gameCubeName = _("S.S. TICKET"),
        .price = 0,
        .description = sSSTicketDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SS_TICKET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
        .gameCubeName = _("CONTEST PASS"),
        .price = 0,
        .description = sContestPassDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_CONTEST_PASS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_10B] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .gameCubeName = _("WAILMER PAIL"),
        .price = 0,
        .description = sWailmerPailDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_WAILMER_PAIL,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_DEVON_GOODS] =
    {
        .gameCubeName = _("DEVON GOODS"),
        .price = 0,
        .description = sDevonGoodsDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_DEVON_GOODS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOT_SACK] =
    {
        .gameCubeName = _("SOOT SACK"),
        .price = 0,
        .description = sSootSackDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SOOT_SACK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SootSack,
        .secondaryId = 0,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .gameCubeName = _("BASEMENT KEY"),
        .price = 0,
        .description = sBasementKeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BASEMENT_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ACRO_BIKE] =
    {
        .gameCubeName = _("ACRO BIKE"),
        .price = 0,
        .description = sAcroBikeDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ACRO_BIKE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .gameCubeName = _("{POKEBLOCK} CASE"),
        .price = 0,
        .description = sPokeblockCaseDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POKEBLOCK_CASE,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_LETTER] =
    {
        .gameCubeName = _("LETTER"),
        .price = 0,
        .description = sLetterDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_LETTER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
        .gameCubeName = _("EON TICKET"),
        .price = 0,
        .description = sEonTicketDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_EON_TICKET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
        .gameCubeName = _("RED ORB"),
        .price = 0,
        .description = sRedOrbDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_RED_ORB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
        .gameCubeName = _("BLUE ORB"),
        .price = 0,
        .description = sBlueOrbDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BLUE_ORB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .gameCubeName = _("SCANNER"),
        .price = 0,
        .description = sScannerDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SCANNER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
        .gameCubeName = _("GO-GOGGLES"),
        .price = 0,
        .description = sGoGogglesDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_GO_GOGGLES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
        .gameCubeName = _("METEORITE"),
        .price = 0,
        .description = sMeteoriteDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_METEORITE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .gameCubeName = _("RM. 1 KEY"),
        .price = 0,
        .description = sRoom1KeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ROOM_1_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .gameCubeName = _("RM. 2 KEY"),
        .price = 0,
        .description = sRoom2KeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ROOM_2_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .gameCubeName = _("RM. 4 KEY"),
        .price = 0,
        .description = sRoom4KeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ROOM_4_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .gameCubeName = _("RM. 6 KEY"),
        .price = 0,
        .description = sRoom6KeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ROOM_6_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
        .gameCubeName = _("STORAGE KEY"),
        .price = 0,
        .description = sStorageKeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_STORAGE_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .gameCubeName = _("ROOT FOSSIL"),
        .price = 0,
        .description = sRootFossilDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_ROOT_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .gameCubeName = _("CLAW FOSSIL"),
        .price = 0,
        .description = sClawFossilDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_CLAW_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .gameCubeName = _("DEVON SCOPE"),
        .price = 0,
        .description = sDevonScopeDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_DEVON_SCOPE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// TMs/HMs

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .gameCubeName = _("TM01"),
        .price = 3000,
        .description = sTM01Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .gameCubeName = _("TM02"),
        .price = 3000,
        .description = sTM02Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .gameCubeName = _("TM03"),
        .price = 3000,
        .description = sTM03Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .gameCubeName = _("TM04"),
        .price = 2000,
        .description = sTM04Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .gameCubeName = _("TM05"),
        .price = 1000,
        .description = sTM05Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .gameCubeName = _("TM06"),
        .price = 2000,
        .description = sTM06Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .gameCubeName = _("TM07"),
        .price = 3000,
        .description = sTM07Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .gameCubeName = _("TM08"),
        .price = 2000,
        .description = sTM08Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 7,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .gameCubeName = _("TM09"),
        .price = 3000,
        .description = sTM09Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 8,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .gameCubeName = _("TM10"),
        .price = 3000,
        .description = sTM10Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 9,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .gameCubeName = _("TM11"),
        .price = 2000,
        .description = sTM11Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 10,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .gameCubeName = _("TM12"),
        .price = 1500,
        .description = sTM12Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 11,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .gameCubeName = _("TM13"),
        .price = 2000,
        .description = sTM13Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 12,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .gameCubeName = _("TM14"),
        .price = 5500,
        .description = sTM14Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 13,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .gameCubeName = _("TM15"),
        .price = 7500,
        .description = sTM15Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 14,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .gameCubeName = _("TM16"),
        .price = 3000,
        .description = sTM16Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 15,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .gameCubeName = _("TM17"),
        .price = 3000,
        .description = sTM17Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 16,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .gameCubeName = _("TM18"),
        .price = 2000,
        .description = sTM18Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 17,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .gameCubeName = _("TM19"),
        .price = 3000,
        .description = sTM19Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 18,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .gameCubeName = _("TM20"),
        .price = 3000,
        .description = sTM20Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 19,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .gameCubeName = _("TM21"),
        .price = 1000,
        .description = sTM21Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 20,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .gameCubeName = _("TM22"),
        .price = 3000,
        .description = sTM22Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 21,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .gameCubeName = _("TM23"),
        .price = 2000,
        .description = sTM23Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 22,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .gameCubeName = _("TM24"),
        .price = 2000,
        .description = sTM24Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 23,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .gameCubeName = _("TM25"),
        .price = 5500,
        .description = sTM25Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 24,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .gameCubeName = _("TM26"),
        .price = 2000,
        .description = sTM26Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 25,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .gameCubeName = _("TM27"),
        .price = 1000,
        .description = sTM27Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 26,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .gameCubeName = _("TM28"),
        .price = 2000,
        .description = sTM28Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 27,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .gameCubeName = _("TM29"),
        .price = 2000,
        .description = sTM29Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 28,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .gameCubeName = _("TM30"),
        .price = 2000,
        .description = sTM30Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 29,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .gameCubeName = _("TM31"),
        .price = 3000,
        .description = sTM31Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 30,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .gameCubeName = _("TM32"),
        .price = 2000,
        .description = sTM32Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 31,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .gameCubeName = _("TM33"),
        .price = 3000,
        .description = sTM33Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 32,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .gameCubeName = _("TM34"),
        .price = 3000,
        .description = sTM34Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 33,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .gameCubeName = _("TM35"),
        .price = 2000,
        .description = sTM35Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 34,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .gameCubeName = _("TM36"),
        .price = 1000,
        .description = sTM36Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 35,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .gameCubeName = _("TM37"),
        .price = 2000,
        .description = sTM37Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 36,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .gameCubeName = _("TM38"),
        .price = 5500,
        .description = sTM38Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 37,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .gameCubeName = _("TM39"),
        .price = 3000,
        .description = sTM39Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 38,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .gameCubeName = _("TM40"),
        .price = 2000,
        .description = sTM40Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 39,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .gameCubeName = _("TM41"),
        .price = 1500,
        .description = sTM41Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 40,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .gameCubeName = _("TM42"),
        .price = 3000,
        .description = sTM42Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 41,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .gameCubeName = _("TM43"),
        .price = 3000,
        .description = sTM43Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 42,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .gameCubeName = _("TM44"),
        .price = 1000,
        .description = sTM44Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 43,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .gameCubeName = _("TM45"),
        .price = 3000,
        .description = sTM45Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 44,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .gameCubeName = _("TM46"),
        .price = 3000,
        .description = sTM46Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 45,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .gameCubeName = _("TM47"),
        .price = 3000,
        .description = sTM47Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 46,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .gameCubeName = _("TM48"),
        .price = 3000,
        .description = sTM48Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 47,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .gameCubeName = _("TM49"),
        .price = 3000,
        .description = sTM49Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 48,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .gameCubeName = _("TM50"),
        .price = 3000,
        .description = sTM50Desc,
        .pocket = POCKET_TM_HM,
        .sortId = 49,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
        .gameCubeName = _("HM01"),
        .price = 0,
        .description = sHM01Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 50,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
        .gameCubeName = _("HM02"),
        .price = 0,
        .description = sHM02Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 51,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
        .gameCubeName = _("HM03"),
        .price = 0,
        .description = sHM03Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 52,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
        .gameCubeName = _("HM04"),
        .price = 0,
        .description = sHM04Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 53,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
        .gameCubeName = _("HM05"),
        .price = 0,
        .description = sHM05Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 54,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .gameCubeName = _("HM06"),
        .price = 0,
        .description = sHM06Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 55,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
        .gameCubeName = _("HM07"),
        .price = 0,
        .description = sHM07Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 56,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
        .gameCubeName = _("HM08"),
        .price = 0,
        .description = sHM08Desc,
        .blockHolding = TRUE,
        .pocket = POCKET_TM_HM,
        .sortId = 57,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_15B] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_15C] =
    {
        .gameCubeName = _("????????"),
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_NONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// FireRed/LeafGreen key items

    [ITEM_OAKS_PARCEL] =
    {
        .gameCubeName = _("OAK'S PARCEL"),
        .price = 0,
        .description = sOaksParcelDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_OAKS_PARCEL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
        .gameCubeName = _("POKé FLUTE"),
        .price = 0,
        .description = sPokeFluteDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POKE_FLUTE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
        .gameCubeName = _("SECRET KEY"),
        .price = 0,
        .description = sSecretKeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SECRET_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .gameCubeName = _("BIKE VOUCHER"),
        .price = 0,
        .description = sBikeVoucherDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BIKE_VOUCHER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
        .gameCubeName = _("GOLD TEETH"),
        .price = 0,
        .description = sGoldTeethDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_GOLD_TEETH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_AMBER] =
    {
        .gameCubeName = _("OLD AMBER"),
        .price = 0,
        .description = sOldAmberDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_OLD_AMBER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
        .gameCubeName = _("CARD KEY"),
        .price = 0,
        .description = sCardKeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_CARD_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
        .gameCubeName = _("LIFT KEY"),
        .price = 0,
        .description = sLiftKeyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_LIFT_KEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HELIX_FOSSIL] =
    {
        .gameCubeName = _("HELIX FOSSIL"),
        .price = 0,
        .description = sHelixFossilDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_HELIX_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .gameCubeName = _("DOME FOSSIL"),
        .price = 0,
        .description = sDomeFossilDesc,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_DOME_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .gameCubeName = _("SILPH SCOPE"),
        .price = 0,
        .description = sSilphScopeDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SILPH_SCOPE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BICYCLE] =
    {
        .gameCubeName = _("BICYCLE"),
        .price = 0,
        .description = sBicycleDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BICYCLE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TOWN_MAP] =
    {
        .gameCubeName = _("TOWN MAP"),
        .price = 0,
        .description = sTownMapDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_TOWN_MAP,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
        .gameCubeName = _("VS SEEKER"),
        .price = 0,
        .description = sVSSeekerDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_VS_SEEKER,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
        .gameCubeName = _("FAME CHECKER"),
        .price = 0,
        .description = sFameCheckerDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_FAME_CHECKER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TM_CASE] =
    {
        .gameCubeName = _("TM CASE"),
        .price = 0,
        .description = sTMCaseDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_TM_CASE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
        .gameCubeName = _("BERRY POUCH"),
        .price = 0,
        .description = sBerryPouchDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BERRY_POUCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
        .gameCubeName = _("TEACHY TV"),
        .price = 0,
        .description = sTeachyTVDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_TEACHY_TV,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .gameCubeName = _("TRI-PASS"),
        .price = 0,
        .description = sTriPassDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_TRI_PASS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .gameCubeName = _("RAINBOW PASS"),
        .price = 0,
        .description = sRainbowPassDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_RAINBOW_PASS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
        .gameCubeName = _("TEA"),
        .price = 0,
        .description = sTeaDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_TEA,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .gameCubeName = _("MYSTICTICKET"),
        .price = 0,
        .description = sMysticTicketDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_MYSTIC_TICKET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .gameCubeName = _("AURORATICKET"),
        .price = 0,
        .description = sAuroraTicketDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_AURORA_TICKET,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POWDER_JAR] =
    {
        .gameCubeName = _("POWDER JAR"),
        .price = 0,
        .description = sPowderJarDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POWDER_JAR,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_RUBY] =
    {
        .gameCubeName = _("RUBY"),
        .price = 0,
        .description = sRubyDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_RUBY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
        .gameCubeName = _("SAPPHIRE"),
        .price = 0,
        .description = sSapphireDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SAPPHIRE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
        .gameCubeName = _("MAGMA EMBLEM"),
        .price = 0,
        .description = sMagmaEmblemDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_MAGMA_EMBLEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .gameCubeName = _("OLD SEA MAP"),
        .price = 0,
        .description = sOldSeaMapDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_OLD_SEA_MAP,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Diamond/Pearl

    [ITEM_DUSK_BALL] =
    {
        .price = 1000,
        .description = sDuskBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_DUSK_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_DUSK,
    },

    [ITEM_HEAL_BALL] =
    {
        .price = 300,
        .description = sHealBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HEAL_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HEAL,
    },

    [ITEM_QUICK_BALL] =
    {
        .price = 1000,
        .description = sQuickBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_QUICK_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_QUICK,
    },

    [ITEM_CHERISH_BALL] =
    {
        .price = 0,
        .description = sCherishBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_CHERISH_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_CHERISH,
    },

    [ITEM_HONEY] =
    {
        .price = 300,
        .description = sHoneyDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_HONEY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GROWTH_MULCH] =
    {
        .price = 200,
        .description = sGrowthMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_GROWTH_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DAMP_MULCH] =
    {
        .price = 200,
        .description = sDampMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_DAMP_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STABLE_MULCH] =
    {
        .price = 200,
        .description = sStableMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_STABLE_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .price = 200,
        .description = sGooeyMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_GOOEY_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_RADAR] =
    {
        .price = 0,
        .description = sPokeRadarDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POKE_RADAR,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POINT_CARD] =
    {
        .price = 0,
        .description = sPointCardDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POINT_CARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_JOURNAL] =
    {
        .price = 0,
        .description = sJournalDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_JOURNAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PAL_PAD] =
    {
        .price = 0,
        .description = sPalPadDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_PAL_PAD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Platinum

    [ITEM_VS_RECORDER] =
    {
        .price = 0,
        .description = sVsRecorderDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_VS_RECORDER,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// HeartGold/SoulSilver

    [ITEM_APRICORN_BOX] =
    {
        .price = 0,
        .description = sApricornBoxDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_APRICORN_BOX,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNOWN_REPORT] =
    {
        .price = 0,
        .description = sUnownReportDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_UNOWN_REPORT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POTS] =
    {
        .price = 0,
        .description = sBerryPotsDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_BERRY_POTS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAST_BALL] =
    {
        .price = 300,
        .description = sFastBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_FAST_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_FAST,
    },

    [ITEM_LEVEL_BALL] =
    {
        .price = 300,
        .description = sLevelBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_LEVEL_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_LEVEL,
    },

    [ITEM_LURE_BALL] =
    {
        .price = 300,
        .description = sLureBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_LURE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_LURE,
    },

    [ITEM_HEAVY_BALL] =
    {
        .price = 300,
        .description = sHeavyBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HEAVY_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HEAVY,
    },

    [ITEM_LOVE_BALL] =
    {
        .price = 300,
        .description = sLureBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_LOVE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_LOVE,
    },

    [ITEM_FRIEND_BALL] =
    {
        .price = 300,
        .description = sFriendBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_FRIEND_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_FRIEND,
    },

    [ITEM_MOON_BALL] =
    {
        .price = 300,
        .description = sMoonBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_MOON_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_MOON,
    },

    [ITEM_SPORT_BALL] =
    {
        .price = 300,
        .description = sSportBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_SPORT_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_SPORT,
    },

    [ITEM_PARK_BALL] =
    {
        .price = 0,
        .description = sParkBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_PARK_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_PARK,
    },

    [ITEM_GB_SOUNDS] =
    {
        .price = 0,
        .description = sGBSoundsDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_GB_SOUNDS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_JADE_ORB] =
    {
        .price = 0,
        .description = sJadeOrbDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_JADE_ORB,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Black/White

    [ITEM_DREAM_BALL] =
    {
        .price = 0,
        .description = sDreamBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_DREAM_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_DREAM,
    },

// Black 2/White 2

	[ITEM_MEDAL_BOX] =
    {
        .price = 0,
        .description = sMedalBoxDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_MEDAL_BOX,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

	[ITEM_OVAL_CHARM] =
    {
        .gameCubeName = _("Oval Charm"),
        .price = 0,
        .description = sOvalCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_OVAL_CHARM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHINY_CHARM] =
    {
        .gameCubeName = _("Shiny Charm"),
        .price = 0,
        .description = sShinyCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_SHINY_CHARM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// X/Y

    [ITEM_ADVENTURE_GUIDE] =
    {
        .price = 0,
        .description = sAdventureGuideDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_ADVENTURE_GUIDE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RICH_MULCH] =
    {
        .price = 200,
        .description = sRichMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_RICH_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .price = 200,
        .description = sSurpriseMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SURPRISE_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BOOST_MULCH] =
    {
        .price = 200,
        .description = sBoostMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BOOST_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .price = 200,
        .description = sAmazeMulchDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_AMAZE_MULCH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Sun/Moon

    [ITEM_BOTTLE_CAP] =
    {
        .price = 20000,
        .description = sBottleCapDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_BOTTLE_CAP,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .price = 60000,
        .description = sGoldBottleCapDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_TREASURES,
        .sortId = SORT_TREASURE_GOLD_BOTTLE_CAP,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BEAST_BALL] =
    {
        .price = 1000,
        .description = sBeastBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_BEAST_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_BEAST,
    },

// Let's Go, Pikachu!/Let's Go, Eevee!

    [ITEM_CLOTHING_TRUNK] =
    {
        .price = 0,
        .description = sClothingTrunkDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_CLOTHING_TRUNK,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LURE] =
    {
        .price = 400,
        .description = sLureDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LURE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SUPER_LURE] =
    {
        .price = 700,
        .description = sSuperLureDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SUPER_LURE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAX_LURE] =
    {
        .price = 900,
        .description = sMaxLureDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MAX_LURE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Sword/Shield

    [ITEM_EXP_CANDY_XS] =
    {
        .price = 600,
        .description = sExpCandyXSDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_ITEM_EXP_CANDY_XS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CANDY_S] =
    {
        .price = 1600,
        .description = sExpCandySDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_ITEM_EXP_CANDY_S,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CANDY_M] =
    {
        .price = 6000,
        .description = sExpCandyMDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_ITEM_EXP_CANDY_M,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CANDY_L] =
    {
        .price = 18000,
        .description = sExpCandyLDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_ITEM_EXP_CANDY_L,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CANDY_XL] =
    {
        .price = 50000,
        .description = sExpCandyXLDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortId = SORT_ITEM_EXP_CANDY_XL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LONELY_MINT] =
    {
        .price = 20000,
        .description = sLonelyMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LONELY_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_LONELY,
    },

    [ITEM_ADAMANT_MINT] =
    {
        .price = 20000,
        .description = sAdamantMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_ADAMANT_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_ADAMANT,
    },

    [ITEM_NAUGHTY_MINT] =
    {
        .price = 20000,
        .description = sNaughtyMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_NAUGHTY_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_NAUGHTY,
    },

    [ITEM_BRAVE_MINT] =
    {
        .price = 20000,
        .description = sBraveMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BRAVE_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_BRAVE,
    },

    [ITEM_BOLD_MINT] =
    {
        .price = 20000,
        .description = sBoldMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_BOLD_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_BOLD,
    },

    [ITEM_IMPISH_MINT] =
    {
        .price = 20000,
        .description = sImpishMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_IMPISH_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_IMPISH,
    },

    [ITEM_LAX_MINT] =
    {
        .price = 20000,
        .description = sLaxMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_LAX_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_LAX,
    },

    [ITEM_RELAXED_MINT] =
    {
        .price = 20000,
        .description = sRelaxedMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_RELAXED_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_RELAXED,
    },

    [ITEM_MODEST_MINT] =
    {
        .price = 20000,
        .description = sModestMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MODEST_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_MODEST,
    },

    [ITEM_MILD_MINT] =
    {
        .price = 20000,
        .description = sMildMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_MILD_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_MILD,
    },

    [ITEM_RASH_MINT] =
    {
        .price = 20000,
        .description = sRashMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_RASH_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_RASH,
    },

    [ITEM_QUIET_MINT] =
    {
        .price = 20000,
        .description = sQuietMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_QUIET_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_QUIET,
    },

    [ITEM_CALM_MINT] =
    {
        .price = 20000,
        .description = sCalmMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CALM_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_CALM,
    },

    [ITEM_GENTLE_MINT] =
    {
        .price = 20000,
        .description = sGentleMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_GENTLE_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_GENTLE,
    },

    [ITEM_CAREFUL_MINT] =
    {
        .price = 20000,
        .description = sCarefulMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_CAREFUL_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_CAREFUL,
    },

    [ITEM_SASSY_MINT] =
    {
        .price = 20000,
        .description = sSassyMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SASSY_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_SASSY,
    },

    [ITEM_TIMID_MINT] =
    {
        .price = 20000,
        .description = sTimidMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_TIMID_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_TIMID,
    },

    [ITEM_HASTY_MINT] =
    {
        .price = 20000,
        .description = sHastyMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_HASTY_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_HASTY,
    },

    [ITEM_JOLLY_MINT] =
    {
        .price = 20000,
        .description = sJollyMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_JOLLY_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_JOLLY,
    },

    [ITEM_NAIVE_MINT] =
    {
        .price = 20000,
        .description = sNaiveMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_NAIVE_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_NAIVE,
    },

    [ITEM_SERIOUS_MINT] =
    {
        .price = 20000,
        .description = sSeriousMintDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_ITEMS,
        .sortId = SORT_ITEM_SERIOUS_MINT,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = MINT_SERIOUS,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .price = 0,
        .description = sCatchingCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_CATCHING_CHARM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Isle of Armor

    [ITEM_EXP_CHARM] =
    {
        .price = 0,
        .description = sExpCharmDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_EXP_CHARM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Legends: Arceus

    [ITEM_HISUI_POKE_BALL] =
    {
        .price = 100,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_POKE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_POKE,
    },

    [ITEM_HISUI_GREAT_BALL] =
    {
        .price = 300,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_GREAT_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_GREAT,
    },

    [ITEM_HISUI_ULTRA_BALL] =
    {
        .price = 600,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_ULTRA_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_ULTRA,
    },

    [ITEM_HISUI_FEATHER_BALL] =
    {
        .price = 140,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_FEATHER_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_FEATHER,
    },

    [ITEM_HISUI_WING_BALL] =
    {
        .price = 340,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_WING_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_WING,
    },

    [ITEM_HISUI_JET_BALL] =
    {
        .price = 680,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_JET_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_JET,
    },

    [ITEM_HISUI_HEAVY_BALL] =
    {
        .price = 120,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_HEAVY_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_HEAVY,
    },

    [ITEM_HISUI_LEADEN_BALL] =
    {
        .price = 320,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_LEADEN_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_LEADEN,
    },

    [ITEM_HISUI_GIGATON_BALL] =
    {
        .price = 640,
        .description = sHisuiPokeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_GIGATON_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_GIGATON,
    },

    [ITEM_HISUI_ORIGIN_BALL] =
    {
        .price = 0,
        .description = sHisuiOriginBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_HISUI_ORIGIN_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_HISUI_ORIGIN,
    },

    [ITEM_STRANGE_BALL] =
    {
        .price = 0,
        .description = sStrangeBallDesc,
        .blockHolding = TRUE,
        .pocket = POCKET_POKE_BALLS,
        .sortId = SORT_BALL_STRANGE_BALL,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = BALL_STRANGE,
    },

// Heliodor Set 1
    [ITEM_POWER_PAD] =
    {
        .price = 0,
        .description = sPowerPadDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_POWER_PAD,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PowerPad,
    },

    [ITEM_MAIL_CASE] =
    {
        .price = 0,
        .description = sMailCaseDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_MAIL_CASE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EMERALD] =
    {
        .price = 0,
        .description = sEmeraldDesc,
        .pocket = POCKET_KEY_ITEMS,
        .sortId = SORT_KEY_EMERALD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },
};

const u8 gItemNames[ITEMS_COUNT][ITEM_NAME_LENGTH] =
{
    [ITEM_MASTER_BALL]          = _("Master Ball"),
    [ITEM_ULTRA_BALL]           = _("Ultra Ball"),
    [ITEM_GREAT_BALL]           = _("Great Ball"),
    [ITEM_POKE_BALL]            = _("Poké Ball"),
    [ITEM_SAFARI_BALL]          = _("Safari Ball"),
    [ITEM_NET_BALL]             = _("Net Ball"),
    [ITEM_DIVE_BALL]            = _("Dive Ball"),
    [ITEM_NEST_BALL]            = _("Nest Ball"),
    [ITEM_REPEAT_BALL]          = _("Repeat Ball"),
    [ITEM_TIMER_BALL]           = _("Timer Ball"),
    [ITEM_LUXURY_BALL]          = _("Luxury Ball"),
    [ITEM_PREMIER_BALL]         = _("Premier Ball"),
    [ITEM_POTION]               = _("Potion"),
    [ITEM_ANTIDOTE]             = _("Antidote"),
    [ITEM_BURN_HEAL]            = _("Burn Heal"),
    [ITEM_ICE_HEAL]             = _("Ice Heal"),
    [ITEM_AWAKENING]            = _("Awakening"),
    [ITEM_PARALYZE_HEAL]        = _("Paralyze Heal"),
    [ITEM_FULL_RESTORE]         = _("Full Restore"),
    [ITEM_MAX_POTION]           = _("Max Potion"),
    [ITEM_HYPER_POTION]         = _("Hyper Potion"),
    [ITEM_SUPER_POTION]         = _("Super Potion"),
    [ITEM_FULL_HEAL]            = _("Full Heal"),
    [ITEM_REVIVE]               = _("Revive"),
    [ITEM_MAX_REVIVE]           = _("Max Revive"),
    [ITEM_FRESH_WATER]          = _("Fresh Water"),
    [ITEM_SODA_POP]             = _("Soda Pop"),
    [ITEM_LEMONADE]             = _("Lemonade"),
    [ITEM_MOOMOO_MILK]          = _("Moomoo Milk"),
    [ITEM_ENERGY_POWDER]        = _("Energy Powder"),
    [ITEM_ENERGY_ROOT]          = _("Energy Root"),
    [ITEM_HEAL_POWDER]          = _("Heal Powder"),
    [ITEM_REVIVAL_HERB]         = _("Revival Herb"),
    [ITEM_ETHER]                = _("Ether"),
    [ITEM_MAX_ETHER]            = _("Max Ether"),
    [ITEM_ELIXIR]               = _("Elixir"),
    [ITEM_MAX_ELIXIR]           = _("Max Elixir"),
    [ITEM_LAVA_COOKIE]          = _("Lava Cookie"),
    [ITEM_BLUE_FLUTE]           = _("Blue Flute"),
    [ITEM_YELLOW_FLUTE]         = _("Yellow Flute"),
    [ITEM_RED_FLUTE]            = _("Red Flute"),
    [ITEM_BLACK_FLUTE]          = _("Black Flute"),
    [ITEM_WHITE_FLUTE]          = _("White Flute"),
    [ITEM_BERRY_JUICE]          = _("Berry Juice"),
    [ITEM_SACRED_ASH]           = _("Sacred Ash"),
    [ITEM_SHOAL_SALT]           = _("Shoal Salt"),
    [ITEM_SHOAL_SHELL]          = _("Shoal Shell"),
    [ITEM_RED_SHARD]            = _("Red Shard"),
    [ITEM_BLUE_SHARD]           = _("Blue Shard"),
    [ITEM_YELLOW_SHARD]         = _("Yellow Shard"),
    [ITEM_GREEN_SHARD]          = _("Green Shard"),
    [ITEM_034]                  = _("????????"),
    [ITEM_035]                  = _("????????"),
    [ITEM_036]                  = _("????????"),
    [ITEM_037]                  = _("????????"),
    [ITEM_038]                  = _("????????"),
    [ITEM_039]                  = _("????????"),
    [ITEM_03A]                  = _("????????"),
    [ITEM_03B]                  = _("????????"),
    [ITEM_03C]                  = _("????????"),
    [ITEM_03D]                  = _("????????"),
    [ITEM_03E]                  = _("????????"),
    [ITEM_HP_UP]                = _("HP Up"),
    [ITEM_PROTEIN]              = _("Protein"),
    [ITEM_IRON]                 = _("Iron"),
    [ITEM_CARBOS]               = _("Carbos"),
    [ITEM_CALCIUM]              = _("Calcium"),
    [ITEM_RARE_CANDY]           = _("Rare Candy"),
    [ITEM_PP_UP]                = _("PP Up"),
    [ITEM_ZINC]                 = _("Zinc"),
    [ITEM_PP_MAX]               = _("PP Max"),
    [ITEM_048]                  = _("????????"),
    [ITEM_GUARD_SPEC]           = _("Guard Spec."),
    [ITEM_DIRE_HIT]             = _("Dire Hit"),
    [ITEM_X_ATTACK]             = _("X Attack"),
    [ITEM_X_DEFEND]             = _("X Defense"),
    [ITEM_X_SPEED]              = _("X Speed"),
    [ITEM_X_ACCURACY]           = _("X Accuracy"),
    [ITEM_X_SPECIAL]            = _("X Sp. Atk"),
    [ITEM_POKE_DOLL]            = _("Poké Doll"),
    [ITEM_FLUFFY_TAIL]          = _("Fluffy Tail"),
    [ITEM_052]                  = _("????????"),
    [ITEM_SUPER_REPEL]          = _("Super Repel"),
    [ITEM_MAX_REPEL]            = _("Max Repel"),
    [ITEM_ESCAPE_ROPE]          = _("Escape Rope"),
    [ITEM_REPEL]                = _("Repel"),
    [ITEM_057]                  = _("????????"),
    [ITEM_058]                  = _("????????"),
    [ITEM_059]                  = _("????????"),
    [ITEM_05A]                  = _("????????"),
    [ITEM_05B]                  = _("????????"),
    [ITEM_05C]                  = _("????????"),
    [ITEM_SUN_STONE]            = _("Sun Stone"),
    [ITEM_MOON_STONE]           = _("Moon Stone"),
    [ITEM_FIRE_STONE]           = _("Fire Stone"),
    [ITEM_THUNDER_STONE]        = _("Thunder Stone"),
    [ITEM_WATER_STONE]          = _("Water Stone"),
    [ITEM_LEAF_STONE]           = _("Leaf Stone"),
    [ITEM_063]                  = _("????????"),
    [ITEM_064]                  = _("????????"),
    [ITEM_065]                  = _("????????"),
    [ITEM_066]                  = _("????????"),
    [ITEM_TINY_MUSHROOM]        = _("Tiny Mushroom"),
    [ITEM_BIG_MUSHROOM]         = _("Big Mushroom"),
    [ITEM_069]                  = _("????????"),
    [ITEM_PEARL]                = _("Pearl"),
    [ITEM_BIG_PEARL]            = _("Big Pearl"),
    [ITEM_STARDUST]             = _("Stardust"),
    [ITEM_STAR_PIECE]           = _("Star Piece"),
    [ITEM_NUGGET]               = _("Nugget"),
    [ITEM_HEART_SCALE]          = _("Heart Scale"),
    [ITEM_070]                  = _("????????"),
    [ITEM_071]                  = _("????????"),
    [ITEM_072]                  = _("????????"),
    [ITEM_073]                  = _("????????"),
    [ITEM_074]                  = _("????????"),
    [ITEM_075]                  = _("????????"),
    [ITEM_076]                  = _("????????"),
    [ITEM_077]                  = _("????????"),
    [ITEM_078]                  = _("????????"),
    [ITEM_ORANGE_MAIL]          = _("Orange Mail"),
    [ITEM_HARBOR_MAIL]          = _("Harbor Mail"),
    [ITEM_GLITTER_MAIL]         = _("Glitter Mail"),
    [ITEM_MECH_MAIL]            = _("Mech Mail"),
    [ITEM_WOOD_MAIL]            = _("Wood Mail"),
    [ITEM_WAVE_MAIL]            = _("Wave Mail"),
    [ITEM_BEAD_MAIL]            = _("Bead Mail"),
    [ITEM_SHADOW_MAIL]          = _("Shadow Mail"),
    [ITEM_TROPIC_MAIL]          = _("Tropic Mail"),
    [ITEM_DREAM_MAIL]           = _("Dream Mail"),
    [ITEM_FAB_MAIL]             = _("Fab Mail"),
    [ITEM_RETRO_MAIL]           = _("Retro Mail"),
    [ITEM_CHERI_BERRY]          = _("Cheri Berry"),
    [ITEM_CHESTO_BERRY]         = _("Chesto Berry"),
    [ITEM_PECHA_BERRY]          = _("Pecha Berry"),
    [ITEM_RAWST_BERRY]          = _("Rawst Berry"),
    [ITEM_ASPEAR_BERRY]         = _("Aspear Berry"),
    [ITEM_LEPPA_BERRY]          = _("Leppa Berry"),
    [ITEM_ORAN_BERRY]           = _("Oran Berry"),
    [ITEM_PERSIM_BERRY]         = _("Persim Berry"),
    [ITEM_LUM_BERRY]            = _("Lum Berry"),
    [ITEM_SITRUS_BERRY]         = _("Sitrus Berry"),
    [ITEM_FIGY_BERRY]           = _("Figy Berry"),
    [ITEM_WIKI_BERRY]           = _("Wiki Berry"),
    [ITEM_MAGO_BERRY]           = _("Mago Berry"),
    [ITEM_AGUAV_BERRY]          = _("Aguav Berry"),
    [ITEM_IAPAPA_BERRY]         = _("Iapapa Berry"),
    [ITEM_RAZZ_BERRY]           = _("Razz Berry"),
    [ITEM_BLUK_BERRY]           = _("Bluk Berry"),
    [ITEM_NANAB_BERRY]          = _("Nanab Berry"),
    [ITEM_WEPEAR_BERRY]         = _("Wepear Berry"),
    [ITEM_PINAP_BERRY]          = _("Pinap Berry"),
    [ITEM_POMEG_BERRY]          = _("Pomeg Berry"),
    [ITEM_KELPSY_BERRY]         = _("Kelpsy Berry"),
    [ITEM_QUALOT_BERRY]         = _("Qualot Berry"),
    [ITEM_HONDEW_BERRY]         = _("Hondew Berry"),
    [ITEM_GREPA_BERRY]          = _("Grepa Berry"),
    [ITEM_TAMATO_BERRY]         = _("Tamato Berry"),
    [ITEM_CORNN_BERRY]          = _("Cornn Berry"),
    [ITEM_MAGOST_BERRY]         = _("Magost Berry"),
    [ITEM_RABUTA_BERRY]         = _("Rabuta Berry"),
    [ITEM_NOMEL_BERRY]          = _("Nomel Berry"),
    [ITEM_SPELON_BERRY]         = _("Spelon Berry"),
    [ITEM_PAMTRE_BERRY]         = _("Pamtre Berry"),
    [ITEM_WATMEL_BERRY]         = _("Watmel Berry"),
    [ITEM_DURIN_BERRY]          = _("Durin Berry"),
    [ITEM_BELUE_BERRY]          = _("Belue Berry"),
    [ITEM_LIECHI_BERRY]         = _("Liechi Berry"),
    [ITEM_GANLON_BERRY]         = _("Ganlon Berry"),
    [ITEM_SALAC_BERRY]          = _("Salac Berry"),
    [ITEM_PETAYA_BERRY]         = _("Petaya Berry"),
    [ITEM_APICOT_BERRY]         = _("Apicot Berry"),
    [ITEM_LANSAT_BERRY]         = _("Lansat Berry"),
    [ITEM_STARF_BERRY]          = _("Starf Berry"),
    [ITEM_ENIGMA_BERRY]         = _("Enigma Berry"),
    [ITEM_UNUSED_BERRY_1]       = _("????????"),
    [ITEM_UNUSED_BERRY_2]       = _("????????"),
    [ITEM_UNUSED_BERRY_3]       = _("????????"),
    [ITEM_BRIGHT_POWDER]        = _("Bright Powder"),
    [ITEM_WHITE_HERB]           = _("White Herb"),
    [ITEM_MACHO_BRACE]          = _("Macho Brace"),
    [ITEM_EXP_SHARE]            = _("Exp. Share"),
    [ITEM_QUICK_CLAW]           = _("Quick Claw"),
    [ITEM_SOOTHE_BELL]          = _("Soothe Bell"),
    [ITEM_MENTAL_HERB]          = _("Mental Herb"),
    [ITEM_CHOICE_BAND]          = _("Choice Band"),
    [ITEM_KINGS_ROCK]           = _("King's Rock"),
    [ITEM_SILVER_POWDER]        = _("Silver Powder"),
    [ITEM_AMULET_COIN]          = _("Amulet Coin"),
    [ITEM_CLEANSE_TAG]          = _("Cleanse Tag"),
    [ITEM_SOUL_DEW]             = _("Soul Dew"),
    [ITEM_DEEP_SEA_TOOTH]       = _("Deep Sea Tooth"),
    [ITEM_DEEP_SEA_SCALE]       = _("Deep Sea Scale"),
    [ITEM_SMOKE_BALL]           = _("Smoke Ball"),
    [ITEM_EVERSTONE]            = _("Everstone"),
    [ITEM_FOCUS_BAND]           = _("Focus Band"),
    [ITEM_LUCKY_EGG]            = _("Lucky Egg"),
    [ITEM_SCOPE_LENS]           = _("Scope Lens"),
    [ITEM_METAL_COAT]           = _("Metal Coat"),
    [ITEM_LEFTOVERS]            = _("Leftovers"),
    [ITEM_DRAGON_SCALE]         = _("Dragon Scale"),
    [ITEM_LIGHT_BALL]           = _("Light Ball"),
    [ITEM_SOFT_SAND]            = _("Soft Sand"),
    [ITEM_HARD_STONE]           = _("Hard Stone"),
    [ITEM_MIRACLE_SEED]         = _("Miracle Seed"),
    [ITEM_BLACK_GLASSES]        = _("Black Glasses"),
    [ITEM_BLACK_BELT]           = _("Black Belt"),
    [ITEM_MAGNET]               = _("Magnet"),
    [ITEM_MYSTIC_WATER]         = _("Mystic Water"),
    [ITEM_SHARP_BEAK]           = _("Sharp Beak"),
    [ITEM_POISON_BARB]          = _("Poison Barb"),
    [ITEM_NEVER_MELT_ICE]       = _("Never-Melt Ice"),
    [ITEM_SPELL_TAG]            = _("Spell Tag"),
    [ITEM_TWISTED_SPOON]        = _("Twisted Spoon"),
    [ITEM_CHARCOAL]             = _("Charcoal"),
    [ITEM_DRAGON_FANG]          = _("Dragon Fang"),
    [ITEM_SILK_SCARF]           = _("Silk Scarf"),
    [ITEM_UP_GRADE]             = _("Upgrade"),
    [ITEM_SHELL_BELL]           = _("Shell Bell"),
    [ITEM_SEA_INCENSE]          = _("Sea Incense"),
    [ITEM_LAX_INCENSE]          = _("Lax Incense"),
    [ITEM_LUCKY_PUNCH]          = _("Lucky Punch"),
    [ITEM_METAL_POWDER]         = _("Metal Powder"),
    [ITEM_THICK_CLUB]           = _("Thick Club"),
    [ITEM_STICK]                = _("Leek"),
    [ITEM_0E2]                  = _("????????"),
    [ITEM_0E3]                  = _("????????"),
    [ITEM_0E4]                  = _("????????"),
    [ITEM_0E5]                  = _("????????"),
    [ITEM_0E6]                  = _("????????"),
    [ITEM_0E7]                  = _("????????"),
    [ITEM_0E8]                  = _("????????"),
    [ITEM_0E9]                  = _("????????"),
    [ITEM_0EA]                  = _("????????"),
    [ITEM_0EB]                  = _("????????"),
    [ITEM_0EC]                  = _("????????"),
    [ITEM_0ED]                  = _("????????"),
    [ITEM_0EE]                  = _("????????"),
    [ITEM_0EF]                  = _("????????"),
    [ITEM_0F0]                  = _("????????"),
    [ITEM_0F1]                  = _("????????"),
    [ITEM_0F2]                  = _("????????"),
    [ITEM_0F3]                  = _("????????"),
    [ITEM_0F4]                  = _("????????"),
    [ITEM_0F5]                  = _("????????"),
    [ITEM_0F6]                  = _("????????"),
    [ITEM_0F7]                  = _("????????"),
    [ITEM_0F8]                  = _("????????"),
    [ITEM_0F9]                  = _("????????"),
    [ITEM_0FA]                  = _("????????"),
    [ITEM_0FB]                  = _("????????"),
    [ITEM_0FC]                  = _("????????"),
    [ITEM_0FD]                  = _("????????"),
    [ITEM_RED_SCARF]            = _("Red Scarf"),
    [ITEM_BLUE_SCARF]           = _("Blue Scarf"),
    [ITEM_PINK_SCARF]           = _("Pink Scarf"),
    [ITEM_GREEN_SCARF]          = _("Green Scarf"),
    [ITEM_YELLOW_SCARF]         = _("Yellow Scarf"),
    [ITEM_MACH_BIKE]            = _("Mach Bike"),
    [ITEM_COIN_CASE]            = _("Coin Case"),
    [ITEM_ITEMFINDER]           = _("Dowsing Machine"),
    [ITEM_OLD_ROD]              = _("Old Rod"),
    [ITEM_GOOD_ROD]             = _("Good Rod"),
    [ITEM_SUPER_ROD]            = _("Super Rod"),
    [ITEM_SS_TICKET]            = _("S.S. Ticket"),
    [ITEM_CONTEST_PASS]         = _("Contest Pass"),
    [ITEM_10B]                  = _("????????"),
    [ITEM_WAILMER_PAIL]         = _("WAILMER Pail"),
    [ITEM_DEVON_GOODS]          = _("Devon Parts"),
    [ITEM_SOOT_SACK]            = _("Soot Sack"),
    [ITEM_BASEMENT_KEY]         = _("Basement Key"),
    [ITEM_ACRO_BIKE]            = _("Acro Bike"),
    [ITEM_POKEBLOCK_CASE]       = _("Pokéblock Case"),
    [ITEM_LETTER]               = _("Letter"),
    [ITEM_EON_TICKET]           = _("Eon Ticket"),
    [ITEM_RED_ORB]              = _("Red Orb"),
    [ITEM_BLUE_ORB]             = _("Blue Orb"),
    [ITEM_SCANNER]              = _("Scanner"),
    [ITEM_GO_GOGGLES]           = _("Go-Goggles"),
    [ITEM_METEORITE]            = _("Meteorite"),
    [ITEM_ROOM_1_KEY]           = _("Key to Room 1"),
    [ITEM_ROOM_2_KEY]           = _("Key to Room 2"),
    [ITEM_ROOM_4_KEY]           = _("Key to Room 4"),
    [ITEM_ROOM_6_KEY]           = _("Key to Room 6"),
    [ITEM_STORAGE_KEY]          = _("Storage Key"),
    [ITEM_ROOT_FOSSIL]          = _("Root Fossil"),
    [ITEM_CLAW_FOSSIL]          = _("Claw Fossil"),
    [ITEM_DEVON_SCOPE]          = _("Devon Scope"),
    [ITEM_TM01]                 = _("TM01"),
    [ITEM_TM02]                 = _("TM02"),
    [ITEM_TM03]                 = _("TM03"),
    [ITEM_TM04]                 = _("TM04"),
    [ITEM_TM05]                 = _("TM05"),
    [ITEM_TM06]                 = _("TM06"),
    [ITEM_TM07]                 = _("TM07"),
    [ITEM_TM08]                 = _("TM08"),
    [ITEM_TM09]                 = _("TM09"),
    [ITEM_TM10]                 = _("TM10"),
    [ITEM_TM11]                 = _("TM11"),
    [ITEM_TM12]                 = _("TM12"),
    [ITEM_TM13]                 = _("TM13"),
    [ITEM_TM14]                 = _("TM14"),
    [ITEM_TM15]                 = _("TM15"),
    [ITEM_TM16]                 = _("TM16"),
    [ITEM_TM17]                 = _("TM17"),
    [ITEM_TM18]                 = _("TM18"),
    [ITEM_TM19]                 = _("TM19"),
    [ITEM_TM20]                 = _("TM20"),
    [ITEM_TM21]                 = _("TM21"),
    [ITEM_TM22]                 = _("TM22"),
    [ITEM_TM23]                 = _("TM23"),
    [ITEM_TM24]                 = _("TM24"),
    [ITEM_TM25]                 = _("TM25"),
    [ITEM_TM26]                 = _("TM26"),
    [ITEM_TM27]                 = _("TM27"),
    [ITEM_TM28]                 = _("TM28"),
    [ITEM_TM29]                 = _("TM29"),
    [ITEM_TM30]                 = _("TM30"),
    [ITEM_TM31]                 = _("TM31"),
    [ITEM_TM32]                 = _("TM32"),
    [ITEM_TM33]                 = _("TM33"),
    [ITEM_TM34]                 = _("TM34"),
    [ITEM_TM35]                 = _("TM35"),
    [ITEM_TM36]                 = _("TM36"),
    [ITEM_TM37]                 = _("TM37"),
    [ITEM_TM38]                 = _("TM38"),
    [ITEM_TM39]                 = _("TM39"),
    [ITEM_TM40]                 = _("TM40"),
    [ITEM_TM41]                 = _("TM41"),
    [ITEM_TM42]                 = _("TM42"),
    [ITEM_TM43]                 = _("TM43"),
    [ITEM_TM44]                 = _("TM44"),
    [ITEM_TM45]                 = _("TM45"),
    [ITEM_TM46]                 = _("TM46"),
    [ITEM_TM47]                 = _("TM47"),
    [ITEM_TM48]                 = _("TM48"),
    [ITEM_TM49]                 = _("TM49"),
    [ITEM_TM50]                 = _("TM50"),
    [ITEM_HM01]                 = _("HM01"),
    [ITEM_HM02]                 = _("HM02"),
    [ITEM_HM03]                 = _("HM03"),
    [ITEM_HM04]                 = _("HM04"),
    [ITEM_HM05]                 = _("HM05"),
    [ITEM_HM06]                 = _("HM06"),
    [ITEM_HM07]                 = _("HM07"),
    [ITEM_HM08]                 = _("HM08"),
    [ITEM_15B]                  = _("????????"),
    [ITEM_15C]                  = _("????????"),
    [ITEM_OAKS_PARCEL]          = _("Parcel"),
    [ITEM_POKE_FLUTE]           = _("Poké Flute"),
    [ITEM_SECRET_KEY]           = _("Secret Key"),
    [ITEM_BIKE_VOUCHER]         = _("Bike Voucher"),
    [ITEM_GOLD_TEETH]           = _("Gold Teeth"),
    [ITEM_OLD_AMBER]            = _("Old Amber"),
    [ITEM_CARD_KEY]             = _("Card Key"),
    [ITEM_LIFT_KEY]             = _("Lift Key"),
    [ITEM_HELIX_FOSSIL]         = _("Helix Fossil"),
    [ITEM_DOME_FOSSIL]          = _("Dome Fossil"),
    [ITEM_SILPH_SCOPE]          = _("Silph Scope"),
    [ITEM_BICYCLE]              = _("Bicycle"),
    [ITEM_TOWN_MAP]             = _("Town Map"),
    [ITEM_VS_SEEKER]            = _("Vs. Seeker"),
    [ITEM_FAME_CHECKER]         = _("Fame Checker"),
    [ITEM_TM_CASE]              = _("TM Case"),
    [ITEM_BERRY_POUCH]          = _("Berry Pouch"),
    [ITEM_TEACHY_TV]            = _("Teachy TV"),
    [ITEM_TRI_PASS]             = _("Tri-Pass"),
    [ITEM_RAINBOW_PASS]         = _("Rainbow Pass"),
    [ITEM_TEA]                  = _("Tea"),
    [ITEM_MYSTIC_TICKET]        = _("Mystic Ticket"),
    [ITEM_AURORA_TICKET]        = _("Aurora Ticket"),
    [ITEM_POWDER_JAR]           = _("Powder Jar"),
    [ITEM_RUBY]                 = _("Ruby"),
    [ITEM_SAPPHIRE]             = _("Sapphire"),
    [ITEM_MAGMA_EMBLEM]         = _("Magma Emblem"),
    [ITEM_OLD_SEA_MAP]          = _("Old Sea Map"),
    [ITEM_DUSK_BALL]            = _("Dusk Ball"),
    [ITEM_HEAL_BALL]            = _("Heal Ball"),
    [ITEM_QUICK_BALL]           = _("Quick Ball"),
    [ITEM_CHERISH_BALL]         = _("Cherish Ball"),
    [ITEM_HONEY]                = _("Honey"),
    [ITEM_GROWTH_MULCH]         = _("Growth Mulch"),
    [ITEM_DAMP_MULCH]           = _("Damp Mulch"),
    [ITEM_STABLE_MULCH]         = _("Stable Mulch"),
    [ITEM_GOOEY_MULCH]          = _("Gooey Mulch"),
    [ITEM_POKE_RADAR]           = _("Poké Radar"),
    [ITEM_POINT_CARD]           = _("Point Card"),
    [ITEM_JOURNAL]              = _("Journal"),
    [ITEM_PAL_PAD]              = _("Pal Pad"),
    [ITEM_VS_RECORDER]          = _("Vs. Recorder"),
    [ITEM_APRICORN_BOX]         = _("Apricorn Box"),
    [ITEM_UNOWN_REPORT]         = _("UNOWN Report"),
    [ITEM_BERRY_POTS]           = _("Berry Pots"),
    [ITEM_FAST_BALL]            = _("Fast Ball"),
    [ITEM_LEVEL_BALL]           = _("Level Ball"),
    [ITEM_LURE_BALL]            = _("Lure Ball"),
    [ITEM_HEAVY_BALL]           = _("Heavy Ball"),
    [ITEM_LOVE_BALL]            = _("Love Ball"),
    [ITEM_FRIEND_BALL]          = _("Friend Ball"),
    [ITEM_MOON_BALL]            = _("Moon Ball"),
    [ITEM_SPORT_BALL]           = _("Sport Ball"),
    [ITEM_PARK_BALL]            = _("Park Ball"),
    [ITEM_GB_SOUNDS]            = _("GB Sounds"),
    [ITEM_JADE_ORB]             = _("Jade Orb"),
    [ITEM_DREAM_BALL]           = _("Dream Ball"),
    [ITEM_MEDAL_BOX]            = _("Medal Box"),
    [ITEM_OVAL_CHARM]           = _("Oval Charm"),
    [ITEM_SHINY_CHARM]          = _("Shiny Charm"),
    [ITEM_ADVENTURE_GUIDE]      = _("Adventure Guide"),
    [ITEM_RICH_MULCH]           = _("Rich Mulch"),
    [ITEM_SURPRISE_MULCH]       = _("Suprise Mulch"),
    [ITEM_BOOST_MULCH]          = _("Boost Mulch"),
    [ITEM_AMAZE_MULCH]          = _("Amaze Mulch"),
    [ITEM_BOTTLE_CAP]           = _("Bottle Cap"),
    [ITEM_GOLD_BOTTLE_CAP]      = _("Gold Bottle Cap"),
    [ITEM_BEAST_BALL]           = _("Beast Ball"),
    [ITEM_CLOTHING_TRUNK]       = _("Clothing Trunk"),
    [ITEM_LURE]                 = _("Lure"),
    [ITEM_SUPER_LURE]           = _("Super Lure"),
    [ITEM_MAX_LURE]             = _("Max Lure"),
    [ITEM_EXP_CANDY_XS]         = _("Exp. Candy XS"),
    [ITEM_EXP_CANDY_S]          = _("Exp. Candy S"),
    [ITEM_EXP_CANDY_M]          = _("Exp. Candy M"),
    [ITEM_EXP_CANDY_L]          = _("Exp. Candy L"),
    [ITEM_EXP_CANDY_XL]         = _("Exp. Candy XL"),
    [ITEM_LONELY_MINT]          = _("Lonely Mint"),
    [ITEM_ADAMANT_MINT]         = _("Adamant Mint"),
    [ITEM_NAUGHTY_MINT]         = _("Naughty Mint"),
    [ITEM_BRAVE_MINT]           = _("Brave Mint"),
    [ITEM_BOLD_MINT]            = _("Bold Mint"),
    [ITEM_IMPISH_MINT]          = _("Impish Mint"),
    [ITEM_LAX_MINT]             = _("Lax Mint"),
    [ITEM_RELAXED_MINT]         = _("Relaxed Mint"),
    [ITEM_MODEST_MINT]          = _("Modest Mint"),
    [ITEM_MILD_MINT]            = _("Mild Mint"),
    [ITEM_RASH_MINT]            = _("Rash Mint"),
    [ITEM_QUIET_MINT]           = _("Quiet Mint"),
    [ITEM_CALM_MINT]            = _("Calm Mint"),
    [ITEM_GENTLE_MINT]          = _("Gentle Mint"),
    [ITEM_CAREFUL_MINT]         = _("Careful Mint"),
    [ITEM_SASSY_MINT]           = _("Sassy Mint"),
    [ITEM_TIMID_MINT]           = _("Timid Mint"),
    [ITEM_HASTY_MINT]           = _("Hasty Mint"),
    [ITEM_JOLLY_MINT]           = _("Jolly Mint"),
    [ITEM_NAIVE_MINT]           = _("Naive Mint"),
    [ITEM_SERIOUS_MINT]         = _("Serious Mint"),
    [ITEM_CATCHING_CHARM]       = _("Catching Charm"),
    [ITEM_EXP_CHARM]            = _("Exp. Charm"),
    [ITEM_HISUI_POKE_BALL]      = _("Old Poké Ball"),
    [ITEM_HISUI_GREAT_BALL]     = _("Old Great Ball"),
    [ITEM_HISUI_ULTRA_BALL]     = _("Old Ultra Ball"),
    [ITEM_HISUI_FEATHER_BALL]   = _("Feather Ball"),
    [ITEM_HISUI_WING_BALL]      = _("Wing Ball"),
    [ITEM_HISUI_JET_BALL]       = _("Jet Ball"),
    [ITEM_HISUI_HEAVY_BALL]     = _("Old Heavy Ball"),
    [ITEM_HISUI_LEADEN_BALL]    = _("Leaden Ball"),
    [ITEM_HISUI_GIGATON_BALL]   = _("Gigaton Ball"),
    [ITEM_HISUI_ORIGIN_BALL]    = _("Origin Ball"),
    [ITEM_STRANGE_BALL]         = _("Strange Ball"),
    [ITEM_POWER_PAD]            = _("Power Pad"),
    [ITEM_MAIL_CASE]            = _("Mail Case"),
    [ITEM_EMERALD]              = _("Emerald"),
};