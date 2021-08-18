.set LOCALID_ZAPDOS, 1

NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Entrance_OnResume
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Entrance_EventScript_TryRemoveZapdos
	end

NewMauville_Entrance_EventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Entrance_OnLoad:
	compare VAR_NEW_MAUVILLE_STATE, 0
	call_if_eq NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, 1
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, 1
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, 1
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, 1
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, 1
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, 1
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	special ResumeRoamerQuest
	compare VAR_RESULT, 1
	goto_if_eq NewMauville_Entrance_EventScript_ShowLegendary
	compare VAR_RESULT, 2
	goto_if_eq NewMauville_Entrance_EventScript_ShowLegendary
	setflag FLAG_HIDE_ZAPDOS
	removeobject LOCALID_ZAPDOS
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, 0
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, 0
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, 0
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, 1
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, 0
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, 1
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_ShowLegendary::
	compare VAR_LEGENDARY_AT_NEW_MAUVILLE, 0
	goto_if_ne NewMauville_Entrance_EventScript_ShowWhichLegendary
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ZAPDOS
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowWhichLegendary::
	switch VAR_LEGENDARY_AT_NEW_MAUVILLE
	case 1, NewMauville_Entrance_EventScript_ShowArticuno
	case 2, NewMauville_Entrance_EventScript_ShowZapdos
	case 3, NewMauville_Entrance_EventScript_ShowMoltres
	case 4, NewMauville_Entrance_EventScript_ShowRaikou
	case 5, NewMauville_Entrance_EventScript_ShowEntei
	case 6, NewMauville_Entrance_EventScript_ShowSuicune
	end

NewMauville_Entrance_EventScript_ShowArticuno::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ARTICUNO
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowZapdos::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ZAPDOS
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowMoltres::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MOLTRES
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowRaikou::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RAIKOU
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowEntei::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ENTEI
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_ShowSuicune::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SUICUNE
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_Entrance_EventScript_Legendary::
	switch VAR_LEGENDARY_AT_NEW_MAUVILLE
	case 0, NewMauville_Entrance_EventScript_Zapdos
	case 1, NewMauville_Entrance_EventScript_Articuno
	case 2, NewMauville_Entrance_EventScript_Zapdos
	case 3, NewMauville_Entrance_EventScript_Moltres
	case 4, NewMauville_Entrance_EventScript_Raikou
	case 5, NewMauville_Entrance_EventScript_Entei
	case 6, NewMauville_Entrance_EventScript_Suicune
	end

NewMauville_Entrance_EventScript_Articuno::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ARTICUNO, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromArticuno
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromArticuno
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_Zapdos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromZapdos
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromZapdos
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromMoltres
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromMoltres
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_Raikou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAIKOU, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_RAIKOU, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromRaikou
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromRaikou
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_Entei::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ENTEI, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_ENTEI, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromEntei
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, 2
	message NewMauville_Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	setwildbattle SPECIES_SUICUNE, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Entrance_EventScript_DefeatedZapdos
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Entrance_EventScript_RanFromSuicune
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Entrance_EventScript_RanFromSuicune
	setflag FLAG_DEFEATED_ZAPDOS
	release
	end

NewMauville_Entrance_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Entrance_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

NewMauville_Text_Gyaoo:
	.string "Gyaoo!$"
