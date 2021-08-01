BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	compare VAR_TEMP_2, EXCHANGE_CORNER_STONE_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	compare VAR_TEMP_2, EXCHANGE_CORNER_STONE_CLERK
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_StoneClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_STONE_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_STONE_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_FireStone
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WaterStone
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ThunderStone
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_LeafStone
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MoonStone
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_SunStone
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DragonScale
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_MetalCoat
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_UpGrade
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaScale
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaTooth
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FireStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFireStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_FIRE_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WaterStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWaterStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_WATER_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ThunderStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmThunderStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_THUNDER_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LeafStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeafStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_LEAF_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MoonStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMoonStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_MOON_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SunStone::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSunStone, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_SUN_STONE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DragonScale::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDragonScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_DRAGON_SCALE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MetalCoat::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMetalCoat, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_METAL_COAT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_UpGrade::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpGrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_UP_GRADE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaScale::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDeepSeaScale, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_DEEP_SEA_SCALE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DeepSeaTooth::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDeepSeaTooth, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseStone
	setvar VAR_0x8008, 3
	setvar VAR_0x8009, ITEM_DEEP_SEA_TOOTH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Stick
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ThickClub
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_LuckyPunch
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_LaxIncense
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_SeaIncense
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Stick::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmStick, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_STICK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ThickClub::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmThickClub, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_THICK_CLUB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LuckyPunch::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLuckyPunch, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LUCKY_PUNCH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaxIncense::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxIncense, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LAX_INCENSE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SeaIncense::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeaIncense, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_SEA_INCENSE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CouponClerk::
	lock
	faceplayer
	goto_if_unset FLAG_BOUGHT_COUPONS, BattleFrontier_ExchangeServiceCorner_EventScript_CouponClerkFirstVisit
	msgbox BattleFrontier_ExchangeServiceCorner_Text_CouponClerk, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	msgbox BattleFrontier_ExchangeServiceCorner_Text_BuyCoupons, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, 50
	goto_if_ge BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveCoupons
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CouponClerkFirstVisit::
	setflag FLAG_BOUGHT_COUPONS
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MtBattlePartnership, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	msgbox BattleFrontier_ExchangeServiceCorner_Text_BuyCoupons, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, 50
	goto_if_ge BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveCoupons
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveCoupons::
	special GetPokeCoupons
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForCoupons
	setvar VAR_0x8004, 50
	special TakeFrontierBattlePoints
	setvar VAR_0x8004, 100
	special GivePokeCoupons
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ObtainedCoupons, MSGBOX_GETPOINTS
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForCoupons::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_CouponsAreMax, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "You've chosen the SMOOCHUM DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "You've chosen the TOGEPI DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "You've chosen the MEOWTH DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "You've chosen the CLEFAIRY DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "You've chosen the DITTO DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "You've chosen the CYNDAQUIL DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "You've chosen the CHIKORITA DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "You've chosen the TOTODILE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "You've chosen the LAPRAS DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "You've chosen the SNORLAX DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "You've chosen the VENUSAUR DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "You've chosen the CHARIZARD DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "You've chosen the BLASTOISE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFireStone: @ 825FB9B
	.string "You've chosen the FIRE STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWaterStone: @ 825FBC7
	.string "You've chosen the WATER STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmThunderStone: @ 825FBF3
	.string "You've chosen the THUNDER STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeafStone: @ 825FC1C
	.string "You've chosen the LEAF STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMoonStone: @ 825FC45
	.string "You've chosen the MOON STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSunStone: @ 825FC70
	.string "You've chosen the SUN STONE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDragonScale:
	.string "You've chosen the DRAGON SCALE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMetalCoat:
	.string "You've chosen the METAL COAT.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmUpGrade:
	.string "You've chosen the UP-GRADE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDeepSeaScale:
	.string "You've chosen the DEEPSEASCALE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDeepSeaTooth:
	.string "You've chosen the DEEPSEATOOTH.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmStick:
	.string "You've chosen the STICK.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmThickClub:
	.string "You've chosen the THICK CLUB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLuckyPunch:
	.string "You've chosen the LUCKY PUNCH.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxIncense:
	.string "You've chosen the LAX INCENSE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeaIncense:
	.string "You've chosen the SEA INCENSE.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_FireStoneDesc:: @ 8260397
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_WaterStoneDesc:: @ 82603BE
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_ThunderStoneDesc:: @ 82603E6
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_LeafStoneDesc:: @ 826040E
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_MoonStoneDesc:: @ 8260436
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_SunStoneDesc:: @ 826045C
	.string "Makes certain species of\n"
	.string "POKéMON evolve.$"

BattleFrontier_ExchangeServiceCorner_Text_DragonScaleDesc::
	.string "A strance scale held by DRAGON-\n"
	.string "type POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_MetalCoatDesc::
	.string "A hold item that raises the power of\n"
	.string "STEEL-type moves.$"

BattleFrontier_ExchangeServiceCorner_Text_UpGradeDesc::
	.string "A peculiar box made by SILPH CO.$"

BattleFrontier_ExchangeServiceCorner_Text_DeepSeaScaleDesc::
	.string "A hold item that raises the SP. ATK\n"
	.string "of CLAMPERL.$"

BattleFrontier_ExchangeServiceCorner_Text_DeepSeaToothDesc::
	.string "A hold item that raises the SP. DEF\n"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_Text_StickDesc::
	.string "A hold item that raises FARFETCH'D's\n"
	.string "critical-hit ratio.$"

BattleFrontier_ExchangeServiceCorner_Text_ThickClubDesc::
	.string "A hold item that raises CUBONE\n"
	.string "or MAROWAK's attack.$"

BattleFrontier_ExchangeServiceCorner_Text_LuckyPunchDesc::
	.string "A hold item that raises CHANSEY's\n"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_Text_LaxIncenseDesc::
	.string "A hold item that slightly lowers the\n"
	.string "foe's accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_SeaIncenseDesc::
	.string "A hold item that slightly boosts\n"
	.string "WATER-type moves.$"

BattleFrontier_ExchangeServiceCorner_Text_MtBattlePartnership::
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We have recently made arrangements\n"
	.string "with the MT. BATTLE facility in the\l"
	.string "ORRE region to exchange Battle Points\l"
	.string "for POKé COUPONS.\p"
	.string "You are also now able to access\n"
	.string "their COUPON EXCHANGE via the PC.$"

BattleFrontier_ExchangeServiceCorner_Text_CouponClerk::
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.$"

BattleFrontier_ExchangeServiceCorner_Text_BuyCoupons::
	.string "Would you like to purchase\n"
	.string "10000 POKé COUPONS for 50 BP?$"

BattleFrontier_ExchangeServiceCorner_Text_ObtainedCoupons::
	.string "{PLAYER} obtained\n"
	.string "10000 POKé COUPONS.$"

BattleFrontier_ExchangeServiceCorner_Text_CouponsAreMax::
	.string "Your POKé COUPONS are already\n"
	.string "at the maximum!$"
