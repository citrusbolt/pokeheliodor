.set LOCALID_ZAPDOS, 1

NewMauville_Entrance_MapScripts:: @ 82372AD
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

NewMauville_Entrance_OnLoad: @ 82372B8
	compare VAR_NEW_MAUVILLE_STATE, 0
	call_if_eq NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor:: @ 82372C4
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, 1
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, 1
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, 1
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, 1
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, 1
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, 1
	return

NewMauville_Entrance_OnTransition: @ 82372FB
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	special ResumeRoamerQuest
	compare VAR_RESULT, 1
	goto_if_eq NewMauville_Entrance_EventScript_ShowZapdos
	compare VAR_RESULT, 2
	goto_if_eq NewMauville_Entrance_EventScript_ShowZapdos
	setflag FLAG_HIDE_ZAPDOS
	removeobject LOCALID_ZAPDOS
	end

NewMauville_Entrance_EventScript_Door:: @ 82372FF
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

NewMauville_Entrance_EventScript_ShowZapdos::
	clearflag FLAG_HIDE_ZAPDOS
	end

NewMauville_EventScript_Zapdos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZAPDOS, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
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

NewMauville_Entrance_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Entrance_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

NewMauville_Entrance_EventScript_DontOpenDoor:: @ 8237380
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked: @ 8237382
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey: @ 8237396
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey: @ 82373AC
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

