.set LOCALID_FOSSIL1, 1
.set LOCALID_FOSSIL2, 2
.set LOCALID_FOSSIL3, 3
.set LOCALID_FOSSIL4, 4
.set LOCALID_FOSSIL5, 5

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	goto_if_set FLAG_HIDE_DESERT_UNDERPASS_FOSSIL, DesetUnderpass_EventScript_HideBothHoennFossils
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_GOT_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil::
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL2
	release
	end

DesertUnderpass_EventScript_GiveRootFossil::
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_FOSSIL1
	release
	end

DesertUnderpass_EventScript_GiveHelixFossil::
	giveitem ITEM_HELIX_FOSSIL
	removeobject LOCALID_FOSSIL3
	release
	end

DesertUnderpass_EventScript_GiveDomeFossil::
	giveitem ITEM_DOME_FOSSIL
	removeobject LOCALID_FOSSIL4
	release
	end

DesertUnderpass_EventScript_GiveOldAmber::
	giveitem ITEM_OLD_AMBER
	removeobject LOCALID_FOSSIL5
	release
	end

DesetUnderpass_EventScript_HideBothHoennFossils::
	removeobject LOCALID_FOSSIL1
	removeobject LOCALID_FOSSIL2
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER} found the Root Fossil.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the Claw Fossil.$"

