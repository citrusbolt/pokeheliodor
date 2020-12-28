.set LOCALID_FOSSIL1, 1
.set LOCALID_FOSSIL2, 2
.set LOCALID_FOSSIL3, 3
.set LOCALID_FOSSIL4, 4
.set LOCALID_FOSSIL5, 5

DesertUnderpass_MapScripts:: @ 823AF37
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition: @ 823AF3D
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	goto_if_set FLAG_HIDE_DESERT_UNDERPASS_FOSSIL, DesetUnderpass_EventScript_HideBothHoennFossils
	end

DesertUnderpass_EventScript_Fossil:: @ 823AF41
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_GOT_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil:: @ 823AF57
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL2
	release
	end

DesertUnderpass_EventScript_GiveRootFossil:: @ 823AF68
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
DesertUnderpass_Text_FoundRootFossil:: @ 823AF79
	.string "{PLAYER} found the ROOT FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil:: @ 823AF93
	.string "{PLAYER} found the CLAW FOSSIL.$"

