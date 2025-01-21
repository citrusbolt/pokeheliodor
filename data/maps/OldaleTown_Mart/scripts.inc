OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_CHERISH_BALL
	.2byte ITEM_HONEY
	.2byte ITEM_GROWTH_MULCH
	.2byte ITEM_DAMP_MULCH
	.2byte ITEM_STABLE_MULCH
	.2byte ITEM_GOOEY_MULCH
	.2byte ITEM_POKE_RADAR
	.2byte ITEM_POINT_CARD
	.2byte ITEM_JOURNAL
	.2byte ITEM_PAL_PAD
	.2byte ITEM_VS_RECORDER
	.2byte ITEM_APRICORN_BOX
	.2byte ITEM_UNOWN_REPORT
	.2byte ITEM_BERRY_POTS
	.2byte ITEM_FAST_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_SPORT_BALL
	.2byte ITEM_PARK_BALL
	.2byte ITEM_GB_SOUNDS
	.2byte ITEM_JADE_ORB
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_MEDAL_BOX
	.2byte ITEM_OVAL_CHARM
	.2byte ITEM_SHINY_CHARM
	.2byte ITEM_ADVENTURE_GUIDE
	.2byte ITEM_RICH_MULCH
	.2byte ITEM_SURPRISE_MULCH
	.2byte ITEM_BOOST_MULCH
	.2byte ITEM_AMAZE_MULCH
	.2byte ITEM_BOTTLE_CAP
	.2byte ITEM_GOLD_BOTTLE_CAP
	.2byte ITEM_BEAST_BALL
	.2byte ITEM_CLOTHING_TRUNK
	.2byte ITEM_LURE
	.2byte ITEM_SUPER_LURE
	.2byte ITEM_MAX_LURE
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_CATCHING_CHARM
	.2byte ITEM_EXP_CHARM
	.2byte ITEM_HISUI_POKE_BALL
	.2byte ITEM_HISUI_GREAT_BALL
	.2byte ITEM_HISUI_ULTRA_BALL
	.2byte ITEM_HISUI_FEATHER_BALL
	.2byte ITEM_HISUI_WING_BALL
	.2byte ITEM_HISUI_JET_BALL
	.2byte ITEM_HISUI_HEAVY_BALL
	.2byte ITEM_HISUI_LEADEN_BALL
	.2byte ITEM_HISUI_GIGATON_BALL
	.2byte ITEM_HISUI_ORIGIN_BALL
	.2byte ITEM_STRANGE_BALL
	.2byte ITEM_POWER_PAD
	.2byte ITEM_MAIL_CASE
	.2byte ITEM_EMERALD
    .2byte ITEM_EXP_ALL
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any Poké Balls.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I'm going to buy a bunch of Poké Balls\n"
	.string "and catch a bunch of Pokémon!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "If a Pokémon gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your Pokémon from fainting,\n"
	.string "restore its HP with a Potion.$"

