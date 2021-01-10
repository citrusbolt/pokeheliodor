.set LOCALID_MEWTWO, 5

Route130_MapScripts:: @ 81F735F
	map_script MAP_SCRIPT_ON_RESUME, Route130_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	.byte 0

Route130_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route130_EventScript_TryRemoveMewtwo
	end

Route130_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_MEWTWO
	return

Route130_OnTransition: @ 81F7365
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_ge Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	compare VAR_RESULT, TRUE
	goto_if_eq Route130_EventScript_SetMirageIslandLayout
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	setflag FLAG_HIDE_MEWTWO
	removeobject LOCALID_MEWTWO
	end

Route130_EventScript_SetMirageIslandLayout:: @ 81F73B1
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	goto_if_eq Route130_EventScript_ShowMewtwo
	setflag FLAG_HIDE_MEWTWO
	removeobject LOCALID_MEWTWO
	end

Route130_EventScript_CheckSetAbnormalWeather:: @ 81F73B5
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney:: @ 81F73BF
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie:: @ 81F73D6
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago:: @ 81F73ED
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_ShowMewtwo::
	clearflag FLAG_HIDE_MEWTWO
	end

Route130_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, 2
	message Route130_Text_Mew
	waitmessage
	waitmoncry
	delay 20
	setwildbattle SPECIES_MEWTWO, 70, ITEM_TWISTED_SPOON
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route130_EventScript_DefeatedMewtwo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route130_EventScript_RanFromMewtwo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route130_EventScript_RanFromMewtwo
	setflag FLAG_DEFEATED_MEWTWO
	release
	end

Route130_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

Route130_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

Route130_Text_Mew:
	.string "Mew!$"
