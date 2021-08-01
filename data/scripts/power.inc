EventScript_PowerPurchase::
	compare VAR_0x8004, TRUE
	goto_if_eq EventScript_PowerPurchase_Active
EventScript_PowerPurchase_Menu::
	message EventScript_PowerPurchase_Text_WhichPower
	waitmessage
	special ShowPowerPointsWindow
	setvar VAR_0x8004, SCROLL_MULTI_POWER_PURCHASE
	special ShowScrollableMultichoice
	waitstate
	compare VAR_RESULT, POWER_NUM_OPTIONS
	goto_if_eq EventScript_PowerPurchase_Exit
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_PowerPurchase_Exit
	special BufferPowerConfirm
	msgbox EventScript_PowerPurchase_Text_ConfirmPurchase, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_PowerPurchase_Menu
	special BuyPower
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PowerPurchase_PowerActivated
	compare VAR_RESULT, 2
	goto_if_eq EventScript_PowerPurchase_TimeMaxedOut
	msgbox EventScript_PowerPurchase_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto EventScript_PowerPurchase_Menu

EventScript_PowerPurchase_Active::
	msgbox gStringVar4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PowerPurchase_Menu
	release
	end

EventScript_PowerPurchase_PowerActivated::
	special UpdatePowerPointsWindow
	playse SE_DEX_SEARCH
	message EventScript_PowerPurchase_Text_Processing
	waitmessage
	waitse
	playse SE_USE_ITEM
	msgbox EventScript_PowerPurchase_Text_PowerActivated, MSGBOX_DEFAULT
	goto EventScript_PowerPurchase_Exit

EventScript_PowerPurchase_TimeMaxedOut::
	msgbox EventScript_PowerPurchase_Text_TimeMaxedOut, MSGBOX_DEFAULT
EventScript_PowerPurchase_Exit::
	special CloseBattlePointsWindow
	release
	end

EventScript_PowerPurchase_Text_WhichPower:
	.string "Which H-POWER would you\n"
	.string "to activate?{PAUSE 24}$"

EventScript_PowerPurchase_Text_ConfirmPurchase:
	.string "You've chosen H-{STR_VAR_1} {LV}{STR_VAR_2}.\n"
	.string "Is that correct?$"

EventScript_PowerPurchase_Text_DontHaveEnoughPoints:
	.string "You do not have enough\n"
	.string "POWER POINTS.$"

EventScript_PowerPurchase_Text_Processing:
	.string "Processing...$"

EventScript_PowerPurchase_Text_PowerActivated:
	.string "H-{STR_VAR_1} {LV}{STR_VAR_2} activated!$"

EventScript_PowerPurchase_Text_HatchDesc1::
	.string "Helps EGGS hatch a little faster.\n"
	.string "The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_HatchDesc2::
	.string "Helps EGGS hatch faster.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_HatchDesc3::
	.string "Helps EGGS hatch much faster.\n"
	.string "The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_BargainDesc1::
	.string "{PKMN} MARTS mark everything down 10%.\n"
	.string "The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_BargainDesc2::
	.string "{PKMN} MARTS mark everything down 25%.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_BargainDesc3::
	.string "{PKMN} MARTS mark everything down 50%.\n"
	.string "The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_PrizeDesc1::
	.string "Increases the prize money from battles\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_PrizeDesc2::
	.string "Increases the prize money from battles.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_PrizeDesc3::
	.string "Increases the prize money from battles\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_ExpDesc1::
	.string "Increases the EXP. points from battles\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_ExpDesc2::
	.string "Increases the EXP. points from battles.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_ExpDesc3::
	.string "Increases the EXP. points from battles\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_CaptureDesc1::
	.string "Increases the chance to catch a {PKMN}\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_CaptureDesc2::
	.string "Increases the chance to catch a {PKMN}.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_CaptureDesc3::
	.string "Increases the chance to catch a {PKMN}\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_EncounterDesc1::
	.string "Increases the chance of finding wild {PKMN}\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_EncounterDesc2::
	.string "Increases the chance of finding wild {PKMN}.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_EncounterDesc3::
	.string "Increases the chance of finding wild {PKMN}\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_StealthDesc1::
	.string "Decreases the chance of finding wild {PKMN}\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_StealthDesc2::
	.string "Decreases the chance of finding wild {PKMN}.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_StealthDesc3::
	.string "Decreases the chance of finding wild {PKMN}\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_FriendDesc1::
	.string "Helps {PKMN} grow friendly a little faster.\n"
	.string "The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_FriendDesc2::
	.string "Helps {PKMN} grow friendly faster.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_FriendDesc3::
	.string "Helps {PKMN} grow friendly much faster.\n"
	.string "The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_ItemDesc1::
	.string "Increases the chance of finding items\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_ItemDesc2::
	.string "Increases the chance of finding items.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_ItemDesc3::
	.string "Increases the chance of finding items\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_TrainingDesc1::
	.string "Helps {PKMN} put a little more effort into\n"
	.string "training. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_TrainingDesc2::
	.string "Helps {PKMN} put more effort into\n"
	.string "training. The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_TrainingDesc3::
	.string "Helps {PKMN} put much more effort into\n"
	.string "training. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_LuckyDesc1::
	.string "Increases the chance of finding rare {PKMN}\n"
	.string "a little. The effect lasts 10 minutes.$"

EventScript_PowerPurchase_Text_LuckyDesc2::
	.string "Increases the chance of finding rare {PKMN}.\n"
	.string "The effect lasts 20 minutes.$"

EventScript_PowerPurchase_Text_LuckyDesc3::
	.string "Increases the chance of finding rare {PKMN}\n"
	.string "a lot. The effect lasts 60 minutes.$"

EventScript_PowerPurchase_Text_TimeMaxedOut:
	.string "H-{STR_VAR_1} time can not\n"
	.string "be increased that much!$"
