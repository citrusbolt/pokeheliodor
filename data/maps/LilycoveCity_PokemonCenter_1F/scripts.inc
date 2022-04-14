.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx::
	special SetLilycoveLadyGfx
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon::
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon::
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_JYNX_TRADE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_JYNX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne LilycoveCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox LilycoveCity_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_JYNX_TRADE_COMPLETED
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox LilycoveCity_PokemonCenter_1F_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon:
	.string "I wonder how many kinds of Pokémon\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade Pokémon with people far away.$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels:
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal Pokémon and rip\l"
	.string "off Meteorites.$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels:
	.string "Those rotten scoundrels who steal\n"
	.string "Pokémon and rip off Meteorites…\p"
	.string "I haven't seen them around recently.$"

LilycoveCity_PokemonCenter_1F_Text_IllTradeIfYouWant:
	.string "Hello, there! Do you happen to\n"
	.string "have a {STR_VAR_1}?\p"
	.string "Would you agree to a trade for\n"
	.string "my {STR_VAR_2}?$"

LilycoveCity_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon:
	.string "Thanks!$"

LilycoveCity_PokemonCenter_1F_Text_DoesntLookLikeMonToMe:
	.string "Hmmm?\n"
	.string "This isn't a {STR_VAR_1}.\p"
	.string "Think of me if you get one.$"

LilycoveCity_PokemonCenter_1F_Text_YouDontWantToThatsOkay:
	.string "Well, if you don't want to…$"

LilycoveCity_PokemonCenter_1F_Text_AnyPokemonCanBeCute:
	.string "Any Pokémon can be cute if you raise\n"
	.string "it with care and kindness.$"
