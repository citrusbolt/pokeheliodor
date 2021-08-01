.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TYROGUE_EGG, RustboroCity_PokemonCenter_1F_EventScript_ReceivedEgg
	msgbox RustboroCity_PokemonCenter_1F_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_PokemonCenter_1F_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq RustboroCity_PokemonCenter_1F_EventScript_NoRoomForEgg
	msgbox RustboroCity_PokemonCenter_1F_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TYROGUE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_PokemonCenter_1F_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_TYROGUE
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_ReceivedEgg::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_NoRoomForEgg::
	msgbox RustboroCity_PokemonCenter_1F_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_DeclineEgg::
	msgbox RustboroCity_PokemonCenter_1F_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"

RustboroCity_PokemonCenter_1F_Text_HaveEggWillYouTakeIt:
	.string "You look like a strong\n"
	.string "POKéMON TRAINER!\p"
	.string "I obtained this mysterious\n"
	.string "EGG in my travels, but I'm not much\l"
	.string "of a TRAINER myself.\p"
	.string "Will you take this EGG to raise?$"

RustboroCity_PokemonCenter_1F_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

RustboroCity_PokemonCenter_1F_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

RustboroCity_PokemonCenter_1F_Text_NoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

RustboroCity_PokemonCenter_1F_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"
