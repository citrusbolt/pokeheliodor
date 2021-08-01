BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_EVReader::
	msgbox BattleFrontier_Lounge4_Text_LetsReadEVs, MSGBOX_NPC
	goto BattleFrontier_Lounge4_EventScript_ChooseMonToShowReader
	end

BattleFrontier_Lounge4_EventScript_EVEraser::
	special ShowBattlePointsWindow
	msgbox BattleFrontier_Lounge4_Text_OfferToResetEVs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge4_EventScript_RefuseErase
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, 100
	goto_if_ge BattleFrontier_Lounge4_EventScript_ChooseMonToShowEraser
	msgbox BattleFrontier_Lounge4_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge4_EventScript_ChooseMonToShowEraser::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne BattleFrontier_Lounge4_EventScript_ShowMonToEraser
	msgbox BattleFrontier_Lounge4_Text_CancelMonErase
	release
	end

BattleFrontier_Lounge4_EventScript_ShowMonToEraser::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge4_EventScript_ShowEggToEraser
	specialvar VAR_RESULT, AreEVsZero
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge4_EventScript_EVsAreZero
	bufferpartymonnick 0, VAR_0x8004
	msgbox BattleFrontier_Lounge4_Text_ConfirmErase, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge4_EventScript_RefuseErase
	special EraseEVs
	setvar VAR_0x8004, 100
	special TakeFrontierBattlePoints
	msgbox BattleFrontier_Lounge4_Text_EVsErased, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge4_EventScript_ShowEggToEraser::
	msgbox BattleFrontier_Lounge4_Text_EggIsUntrained, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge4_EventScript_ChooseMonToShowEraser
	end

BattleFrontier_Lounge4_EventScript_RefuseErase::
	msgbox BattleFrontier_Lounge4_Text_CancelMonErase, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge4_EventScript_EVsAreZero::
	msgbox BattleFrontier_Lounge4_Text_MonIsUntrained, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge4_EventScript_ChooseMonToShowReader::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne BattleFrontier_Lounge4_EventScript_ShowMonToReader
	msgbox BattleFrontier_Lounge4_Text_CancelMonRead
	release
	end

BattleFrontier_Lounge4_EventScript_ShowMonToReader::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge4_EventScript_ShowEggToReader
	special BufferEVs1
	msgbox BattleFrontier_Lounge4_Text_ReciteEVs1, MSGBOX_DEFAULT
	special BufferEVs2
	msgbox BattleFrontier_Lounge4_Text_ReciteEVs2, MSGBOX_DEFAULT
	specialvar VAR_RESULT, AreEVsMaxedOut
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge4_EventScript_EVsNotMaxed
	msgbox BattleFrontier_Lounge4_Text_EVsMaxed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge4_EventScript_ShowEggToReader::
	msgbox BattleFrontier_Lounge4_Text_EggIsUntrained, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge4_EventScript_ChooseMonToShowReader
	end

BattleFrontier_Lounge4_EventScript_EVsNotMaxed::
	msgbox BattleFrontier_Lounge4_Text_EVsNotMaxed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "I wonder if they'll be airing interviews\n"
	.string "with tough TRAINERS today?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "If I opened a restaurant here,\n"
	.string "it'd make money for sure.$"

BattleFrontier_Lounge4_Text_OfferToResetEVs:
	.string "Sometimes it's good to start anew\n"
	.string "and go down a fresh path.\p"
	.string "If you want a POKéMON to\n"
	.string "forget the training it has received,\l"
	.string "I can help.\p"
	.string "Give me 100 BP, and I'll prepare\n"
	.string "a POKéMON so that it can put\l"
	.string "a lot more effort into training.$"

BattleFrontier_Lounge4_Text_DontHaveEnoughPoints:
	.string "I'm sorry,\n"
	.string "You don't have enough Battle Points.$"

BattleFrontier_Lounge4_Text_CancelMonErase:
	.string "Feel free to return any time\n"
	.string "to utilize my skill.$"

BattleFrontier_Lounge4_Text_ConfirmErase:
	.string "So you want me to give {STR_VAR_1}\n"
	.string "a clean slate?$"

BattleFrontier_Lounge4_Text_EVsErased:
	.string "{STR_VAR_1} is ready to\n"
	.string "receive new training!$"

BattleFrontier_Lounge4_Text_MonIsUntrained:
	.string "This POKéMON hasn't received\n"
	.string "any training!$"

BattleFrontier_Lounge4_Text_LetsReadEVs:
	.string "Show me a POKéMON and I will\n"
	.string "judge its training.$"

BattleFrontier_Lounge4_Text_CancelMonRead:
	.string "Feel free to return any time\n"
	.string "to show me a trained POKéMON.$"

BattleFrontier_Lounge4_Text_EggIsUntrained:
	.string "A POKéMON EGG can not\n"
	.string "receive any training!$"

BattleFrontier_Lounge4_Text_ReciteEVs1:
	.string "I'd rate its HP\n"
	.string "training as {STR_VAR_1}.\p"
	.string "I'd rate its ATTACK\n"
	.string "training as {STR_VAR_2}.\p"
	.string "I'd rate its DEFENSE\n"
	.string "training as {STR_VAR_3}.$"

BattleFrontier_Lounge4_Text_ReciteEVs2:
	.string "I'd rate its SPECIAL ATTACK\n"
	.string "training as {STR_VAR_1}.\p"
	.string "I'd rate its SPECIAL DEFENSE\n"
	.string "training as {STR_VAR_2}.\p"
	.string "I'd rate its SPEED\n"
	.string "training as {STR_VAR_3}.$"

BattleFrontier_Lounge4_Text_EVsNotMaxed:
	.string "This POKéMON needs more training\n"
	.string "in order to reach its full potential.$"

BattleFrontier_Lounge4_Text_EVsMaxed:
	.string "This POKéMON has put a lot\n"
	.string "of effort into its training!$"
