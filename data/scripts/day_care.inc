.set LOCALID_DAYCARE_LADY, 1

Route117_EventScript_DaycareMan:: @ 8291C18
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_EGG_WAITING
	goto_if_eq Route117_EventScript_DaycareEggWaiting
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route117_EventScript_CheckOnOneMon
	compare VAR_RESULT, DAYCARE_TWO_MONS
	goto_if_eq Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting:: @ 8291C4D
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg:: @ 8291C83
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg:: @ 8291C9D
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail:: @ 8291CB7
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	compare VAR_RESULT, 1
	call_if_eq Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail:: @ 8291CC8
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon:: @ 8291CD1
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons:: @ 8291CE8
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman:: @ 8291D11
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_EGG_WAITING
	goto_if_eq Route117_PokemonDayCare_EventScript_EggWaiting
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route117_PokemonDayCare_EventScript_OneMonInDaycare
	compare VAR_RESULT, DAYCARE_TWO_MONS
	goto_if_eq Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise:: @ 8291D56
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 1
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	compare VAR_RESULT, 2
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	compare VAR_RESULT, 0
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, 0
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain:: @ 8291DCA
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore:: @ 8291DD4
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon:: @ 8291DED
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon:: @ 8291DF7
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons:: @ 8291E01
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting:: @ 8291E0B
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels:: @ 8291E15
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained:: @ 8291E1E
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	compare VAR_RESULT, 0
	call_if_ne Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare:: @ 8291E2F
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon:: @ 8291E6D
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt:: @ 8291EAC
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney:: @ 8291EC8
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	compare VAR_RESULT, 1
	goto_if_eq Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon:: @ 8291EE2
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, 0
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	compare VAR_RESULT, DAYCARE_ONE_MON
	goto_if_eq Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon:: @ 8291F24
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom:: @ 8291F3D
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon: @ 8291F47
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd:: @ 8291F5B
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare:: @ 8291F5C
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon:: @ 8291F95
	special ShowDaycareLevelMenu
	waitstate
	compare VAR_RESULT, 2
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch:: @ 8291FC0
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

EventScript_Incubator::
	playse SE_PC_LOGIN
	goto_if_unset FLAG_EGG_IN_INCUBATOR, EventScript_Incubator_PutEgg
	msgbox Incubator_Text_WantToCheck, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_Check
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_PutEgg::
	msgbox Incubator_Text_WantToIncubate, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_Incubator_Exit
	msgbox Incubator_Text_WhichEgg, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseEggForIncubator
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq EventScript_Incubator_Exit
	msgbox Incubator_Text_EggInserted, MSGBOX_DEFAULT
	special PutSelectedEggInIncubator
	special CheckIncubator
	msgbox Incubator_Text_Time, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Check::
	specialvar VAR_RESULT, CheckIncubator
	compare VAR_RESULT, 100
	goto_if_ge EventScript_Incubator_UhOh
	compare VAR_RESULT, 41
	goto_if_ge EventScript_Incubator_Tier4
	compare VAR_RESULT, 11
	goto_if_ge EventScript_Incubator_Tier3
	compare VAR_RESULT, 6
	goto_if_ge EventScript_Incubator_Tier2
	compare VAR_RESULT, 1
	goto_if_ge EventScript_Incubator_Tier1
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_Incubator_ReadyToHatch
	special HatchEggInIncubator
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_RemoveEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_Incubator_NoRoom
	msgbox Incubator_Text_EggRemoved, MSGBOX_DEFAULT
	special RemoveEggFromIncubator
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Exit::
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Tier4::
	msgbox Incubator_Text_Tier4, MSGBOX_DEFAULT
	msgbox Incubator_Text_RemoveEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_RemoveEgg
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Tier3::
	msgbox Incubator_Text_Tier3, MSGBOX_DEFAULT
	msgbox Incubator_Text_RemoveEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_RemoveEgg
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Tier2::
	msgbox Incubator_Text_Tier2, MSGBOX_DEFAULT
	msgbox Incubator_Text_RemoveEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_RemoveEgg
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_Tier1::
	msgbox Incubator_Text_Tier1, MSGBOX_DEFAULT
	msgbox Incubator_Text_RemoveEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_RemoveEgg
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_UhOh::
	msgbox Incubator_Text_UhOh, MSGBOX_DEFAULT
	msgbox Incubator_Text_RemoveEgg, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Incubator_RemoveEgg
	goto EventScript_PCMainMenu
	end

EventScript_Incubator_NoRoom::
	msgbox Incubator_Text_NoRoom, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end
	
EventScript_Incubator_ReadyToHatch::
	msgbox Incubator_Text_ReadyToHatch, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end
	
EventScript_EventEggMan::
	lock
	faceplayer
	specialvar VAR_RESULT, CheckIfEligibleForEventEgg
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_EventEggMan_GiveEgg
	msgbox EventScript_EventEggMan_Text_LookingForEggExpert, MSGBOX_DEFAULT
	release
	end
	
EventScript_EventEggMan_GiveEgg::
	msgbox EventScript_EventEggMan_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_EventEggMan_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_EventEggMan_NoRoomForEgg
	msgbox EventScript_EventEggMan_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	copyvar  VAR_0x8004, VAR_RECEIVED_EVENT_EGGS
	addvar VAR_RECEIVED_EVENT_EGGS, 1
	playfanfare MUS_OBTAIN_ITEM
	message EventScript_EventEggMan_Text_ReceivedTheEgg
	waitfanfare
	special GiveEventEgg
	release
	end

EventScript_EventEggMan_NoRoomForEgg::
	msgbox EventScript_EventEggMan_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

EventScript_EventEggMan_DeclineEgg::
	msgbox EventScript_EventEggMan_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end
	
Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon: @ 8291FCF
	.string "I'm the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you'd like me to raise your POKéMON,\n"
	.string "have a word with my wife.$"

Route117_Text_DoYouWantEgg: @ 829205D
	.string "Ah, it's you!\p"
	.string "We were raising your POKéMON,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don't know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"

Route117_Text_YourMonIsDoingFine: @ 8292114
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

Route117_Text_IllKeepIt: @ 8292149
	.string "Well then, I'll keep it.\n"
	.string "Thanks!$"

Route117_Text_YouHaveNoRoomForIt: @ 829216A
	.string "You have no room for it…\n"
	.string "Come back when you've made room.$"

Route117_Text_ReceivedEgg: @ 82921A4
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"

Route117_Text_TakeGoodCareOfIt: @ 82921CF
	.string "Take good care of it.$"

Route117_Text_FriendlyWithOtherTrainersMon: @ 82921E5
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon: @ 829225A
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"

Route117_Text_YourMonsAreDoingFine: @ 8292299
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route117_Text_IWillKeepDoYouWantIt: @ 82922C6
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon: @ 82922F4
	.string "I'm the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise: @ 8292349
	.string "Which POKéMON should we raise for\n"
	.string "you?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon: @ 8292370
	.string "Fine, we'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore: @ 82923AF
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou: @ 82923F6
	.string "My husband was looking for you.$"

Route117_PokemonDayCare_Text_FineThenComeAgain: @ 8292416
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_NotEnoughMoney: @ 8292432
	.string "You don't have enough money…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo: @ 829244F
	.string "Will you take back the other one,\n"
	.string "too?$"

Route117_PokemonDayCare_Text_ComeAgain: @ 8292476
	.string "Fine.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_GoodToSeeYou: @ 8292488
	.string "Ah, it's you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels: @ 82924CC
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route117_PokemonDayCare_Text_YourTeamIsFull: @ 82924EF
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon: @ 8292527
	.string "Which POKéMON will you take back?$"

Route117_PokemonDayCare_Text_ItWillCostX: @ 8292549
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon: @ 8292575
	.string "Perfect!\n"
	.string "Here's your POKéMON.$"

Route117_PokemonDayCare_Text_TookBackMon: @ 8292593
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon: @ 82925BB
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"

Route117_PokemonDayCare_Text_TakeYourMonBack: @ 82925F6
	.string "Will you take your POKéMON back?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith: @ 8292617
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

Text_EggHatchHuh: @ 8292668
	.string "Huh?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne: @ 829266D
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you'll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"

Incubator_Text_WantToIncubate:
	.string "Would you like to send\n"
	.string "an EGG to the incubator?$"

Incubator_Text_WantToCheck:
	.string "Would you like to check\n"
	.string "on the EGG in the incubator?$"

Incubator_Text_RemoveEgg:
	.string "Would you like to take\n"
	.string "the EGG from the incubator?$"

Incubator_Text_EggRemoved:
	.string "{PLAYER} took the EGG\n"
	.string "from the incubator.$"

Incubator_Text_WhichEgg:
	.string "Which EGG would you\n"
	.string "like to send?$"

Incubator_Text_EggInserted:
	.string "{PLAYER} sent the EGG\n"
	.string "to the incubator.$"

Incubator_Text_Tier4:
	.string "It looks like this EGG\n"
	.string "will take a long time to hatch.\p"
	.string "Estimated time to hatching:\n"
	.string "{STR_VAR_1} {STR_VAR_2}$"

Incubator_Text_Tier3:
	.string "What will hatch from this?\n"
	.string "It will take some time.\p"
	.string "Estimated time to hatching:\n"
	.string "{STR_VAR_1} {STR_VAR_2}$"

Incubator_Text_Tier2:
	.string "It moves occasionally.\n"
	.string "It should hatch soon.\p"
	.string "Estimated time to hatching:\n"
	.string "{STR_VAR_1} {STR_VAR_2}$"

Incubator_Text_Tier1:
	.string "It's making sounds!\n"
	.string "It's about to hatch!\p"
	.string "Estimated time to hatching:\n"
	.string "{STR_VAR_1} {STR_VAR_2}$"
	
Incubator_Text_Time:
	.string "Estimated time to hatching:\n"
	.string "{STR_VAR_1} {STR_VAR_2}$"
	
Incubator_Text_UhOh:
	.string "UhOh$"

Incubator_Text_ReadyToHatch:
	.string "The EGG looks ready to hatch,\n"
	.string "but your party is full!$"

Incubator_Text_NoRoom:
	.string "Your party is full!$"

EventScript_EventEggMan_Text_LookingForEggExpert:
	.string "Receiving a POKéMON EGG from\n"
	.string "someone is always so exciting!\p"
	.string "You never know what will\n"
	.string "be inside.$"

EventScript_EventEggMan_Text_HaveEggWillYouTakeIt:
	.string "You seem to be pretty good\n"
	.string "at taking care of POKéMON EGGS.\p"
	.string "Will you take this special EGG?$"

EventScript_EventEggMan_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

EventScript_EventEggMan_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

EventScript_EventEggMan_Text_NoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

EventScript_EventEggMan_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

