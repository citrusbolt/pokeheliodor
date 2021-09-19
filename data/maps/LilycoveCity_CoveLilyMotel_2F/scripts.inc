LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	@waitstate
	goto_if_unset FLAG_RECEIVED_JIRACHI, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveJirachi
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMap
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_WaitForMew, MSGBOX_NPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllJohtoMons
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_GiveCelebi
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_WaitForCelebi, MSGBOX_NPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EReader, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKidNo
	checkitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_HaveEnigmaBerry
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EnigmaDad, MSGBOX_NPC
	special SetMochiBerry
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_HaveEnigmaBerry::
	specialvar VAR_RESULT, GetEnigmaName
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_HaveMochiBerry
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EnigmaTransform, MSGBOX_NPC
	special SetMochiBerry
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_HaveMochiBerry::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_EnigmaHave, MSGBOX_NPC
	special SetMochiBerry
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKidNo::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveJirachi::
	releaseall
	lock
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CompleteHoenn, MSGBOX_DEFAULT
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GiveJirachi, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_JIRACHI
	givemon SPECIES_JIRACHI, 5, 0
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SendJirachiToParty
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SendJirachiToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMap::
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, LilycoveCity_CoveLilyMotel_2F_EventScript_ReceivedOldSeaMap
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GiveOldSeaMap, MSGBOX_DEFAULT
	giveitem ITEM_OLD_SEA_MAP, 1
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ReceivedOldSeaMap::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveCelebi::
	goto_if_set FLAG_RECEIVED_CELEBI, LilycoveCity_CoveLilyMotel_2F_EventScript_ReceivedCelebi
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_CompleteJohto, MSGBOX_DEFAULT
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GiveCelebi, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CELEBI
	givemon SPECIES_CELEBI, 10, 0
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SendCelebiToParty
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SendCelebiToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SendJirachiToParty::
	setflag FLAG_RECEIVED_JIRACHI
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SendJirachiToPC::
	setflag FLAG_RECEIVED_JIRACHI
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	call Common_EventScript_TransferredToPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SendCelebiToParty::
	setflag FLAG_RECEIVED_CELEBI
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SendCelebiToPC::
	setflag FLAG_RECEIVED_CELEBI
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	call Common_EventScript_TransferredToPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ReceivedCelebi::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the Game Designer.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a PokéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This PokéDEX is completely filled!\n"
	.string "You really must love Pokémon!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the Programmer.\p"
	.string "I wonder what the Slots are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the Graphic Artist! Aren't the\n"
	.string "Pokémon of Hoenn interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "The girl Tubers, they're cute, hey?\n"
	.string "To battle against a cute Tuber…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the Twins! Aren't they cute?\n"
	.string "A 2-on-2 battle with Twins…\p"
	.string "Whoop, it's unbearably fun!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my Game Boy Advance.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "Scott: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this Pokémon\n"
	.string "Contest thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough Trainers.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the Gyms, Contests, Battle Tent,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "Scott: I think it does take strategy\n"
	.string "to win a Contest.\p"
	.string "Devising Contest strategies is one way\n"
	.string "of becoming a better Trainer, I'd say.$"

LilycoveCity_CoveLilyMotel_2F_Text_CompleteHoenn:
	.string "I'd also like to entrust this\n"
	.string "special Pokémon with you!$"

LilycoveCity_CoveLilyMotel_2F_Text_GiveJirachi:
	.string "{PLAYER} received JIRACHI!$"

LilycoveCity_CoveLilyMotel_2F_Text_GiveOldSeaMap:
	.string "Wow! You've registered all the\n"
	.string "Pokémon originally from the\l"
	.string "Kanto region in your PokéDEX!\p"
	.string "I'd like you to have this\n"
	.string "special map.\p"
	.string "Present this map to the staff\n"
	.string "of the S.S. Tidal at the\l"
	.string "Lilycove City port.$"

LilycoveCity_CoveLilyMotel_2F_Text_CompleteJohto:
	.string "Wow! You've registered all the\n"
	.string "Pokémon originally from the\l"
	.string "Johto region in your PokéDEX!\p"
	.string "I'd like to entrust this\n"
	.string "special Pokémon with you!$"

LilycoveCity_CoveLilyMotel_2F_Text_GiveCelebi:
	.string "{PLAYER} received CELEBI!$"

LilycoveCity_CoveLilyMotel_2F_Text_WaitForMew:
	.string "I'm looking for someone who has\n"
	.string "found all the Pokémon first\l"
	.string "discovered in the Kanto region.\p"
	.string "Could that be you?$"

LilycoveCity_CoveLilyMotel_2F_Text_WaitForCelebi:
	.string "I'm looking for someone who has\n"
	.string "found all the Pokémon first\l"
	.string "discovered in the Johto region.\p"
	.string "Could that be you?$"

LilycoveCity_CoveLilyMotel_2F_Text_EReader:
	.string "The e-Reader is awesome!\p"
	.string "If you don't have one, I can\n"
	.string "scan this Mochi Berry card for you.$"

LilycoveCity_CoveLilyMotel_2F_Text_ScanCard:
	.string "There we go!\n"
	.string "It's scanned in.\p"
	.string "I wonder what it did.$"

LilycoveCity_CoveLilyMotel_2F_Text_EnigmaDad:
	.string "There we go!\n"
	.string "It's scanned in.\l"
	.string "The screen says,\p"
	.string "“Obtained a Mochi Berry!\n"
	.string "Dad has it at Petalburg Gym.”\p"
	.string "That's weird...$"

LilycoveCity_CoveLilyMotel_2F_Text_EnigmaTransform:
	.string "There we go!\n"
	.string "It's scanned in.\l"
	.string "The screen says,\p"
	.string "“The {STR_VAR_1} Berry transformed\n"
	.string "into one Mochi Berry.”$"

LilycoveCity_CoveLilyMotel_2F_Text_EnigmaHave:
	.string "There we go!\n"
	.string "It's scanned in.\l"
	.string "The screen says,\p"
	.string "“The Mochi Berry has already been\n"
	.string "obtained.”$"
