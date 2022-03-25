EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_Incubator
	case 3, EventScript_AccessHallOfFame
	case 4, EventScript_CouponWindow
	case 5, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_CouponWindow
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end

EventScript_CouponWindow::
	special HasReceivedPokeCoupons
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_TurnOffPC
	special ShowPokeCouponsWindow
	goto EventScript_CouponExchange

EventScript_CouponExchange::
	setvar VAR_0x8004, SCROLL_MULTI_COUPON_EXCHANGE
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, EventScript_CouponExchange_PremierBall
	case 1, EventScript_CouponExchange_LuxuryBall
	case 2, EventScript_CouponExchange_RareCandy
	case 3, EventScript_CouponExchange_LiechiBerry
	case 4, EventScript_CouponExchange_GanlonBerry
	case 5, EventScript_CouponExchange_SalacBerry
	case 6, EventScript_CouponExchange_PetayaBerry
	case 7, EventScript_CouponExchange_ApicotBerry
	case 8, EventScript_CouponExchange_LansatBerry
	case 9, EventScript_CouponExchange_StarfBerry
	case 10, EventScript_CouponExchange_RegirockDoll
	case 11, EventScript_CouponExchange_RegiceDoll
	case 12, EventScript_CouponExchange_RegisteelDoll
	case 13, EventScript_CouponExchange_MasterBall
	case 14, EventScript_CouponExchange_50BP
	case 15, EventScript_CouponExchange_500BP
	case 16, EventScript_CouponExchange_Exit
	case MULTI_B_PRESSED, EventScript_CouponExchange_Exit
	end

EventScript_CouponExchange_PremierBall::
	msgbox EventScript_CouponExchange_Text_ConfirmPremierBall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 10
	setvar VAR_0x8009, ITEM_PREMIER_BALL
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_LuxuryBall::
	msgbox EventScript_CouponExchange_Text_ConfirmLuxuryBall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 15
	setvar VAR_0x8009, ITEM_LUXURY_BALL
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_RareCandy::
	msgbox EventScript_CouponExchange_Text_ConfirmRareCandy, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 100
	setvar VAR_0x8009, ITEM_RARE_CANDY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_LiechiBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmLiechiBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_LIECHI_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_GanlonBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmGanlonBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_GANLON_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_SalacBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmSalacBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_SALAC_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_PetayaBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmPetayaBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_PETAYA_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_ApicotBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmApicotBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_APICOT_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_LansatBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmLansatBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_LANSAT_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_StarfBerry::
	msgbox EventScript_CouponExchange_Text_ConfirmStarfBerry, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 150
	setvar VAR_0x8009, ITEM_STARF_BERRY
	goto EventScript_CouponExchange_TryPurchaseItem
	end

EventScript_CouponExchange_RegirockDoll::
	msgbox EventScript_CouponExchange_Text_ConfirmRegirockDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 600
	setvar VAR_0x8009, DECOR_REGIROCK_DOLL
	goto EventScript_CouponExchange_TryPurchaseDecor
	end

EventScript_CouponExchange_RegisteelDoll::
	msgbox EventScript_CouponExchange_Text_ConfirmRegisteelDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 600
	setvar VAR_0x8009, DECOR_REGISTEEL_DOLL
	goto EventScript_CouponExchange_TryPurchaseDecor
	end

EventScript_CouponExchange_RegiceDoll::
	msgbox EventScript_CouponExchange_Text_ConfirmRegiceDoll, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 600
	setvar VAR_0x8009, DECOR_REGICE_DOLL
	goto EventScript_CouponExchange_TryPurchaseDecor
	end

EventScript_CouponExchange_MasterBall::
	msgbox EventScript_CouponExchange_Text_ConfirmMasterBall, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 1000
	setvar VAR_0x8009, ITEM_MASTER_BALL
	goto EventScript_CouponExchange_TryPurchaseItem
	end
	
EventScript_CouponExchange_50BP::
	msgbox EventScript_CouponExchange_Text_Confirm50BP, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 100
	setvar VAR_0x8009, 50
	goto EventScript_CouponExchange_TryPurchaseBP
	end

EventScript_CouponExchange_500BP::
	msgbox EventScript_CouponExchange_Text_Confirm500BP, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CouponExchange
	setvar VAR_0x8008, 1000
	setvar VAR_0x8009, 500
	goto EventScript_CouponExchange_TryPurchaseBP
	end

EventScript_CouponExchange_TryPurchaseItem::
	specialvar VAR_TEMP_1, GetPokeCoupons
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge EventScript_CouponExchange_TryGiveItem
	msgbox EventScript_CouponExchange_Text_DontHaveEnoughCoupons, MSGBOX_DEFAULT
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_TryPurchaseDecor::
	specialvar VAR_TEMP_1, GetPokeCoupons
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge EventScript_CouponExchange_TryGiveDecor
	msgbox EventScript_CouponExchange_Text_DontHaveEnoughCoupons, MSGBOX_DEFAULT
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_TryPurchaseBP::
	specialvar VAR_TEMP_1, GetPokeCoupons
	compare VAR_TEMP_1, VAR_0x8008
	goto_if_ge EventScript_CouponExchange_TryGiveBP
	msgbox EventScript_CouponExchange_Text_DontHaveEnoughCoupons, MSGBOX_DEFAULT
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_TryGiveItem::
	checkitemspace VAR_0x8009, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CouponExchange_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakePokeCoupons
	additem VAR_0x8009
	special UpdatePokeCouponsWindow
	playse SE_SHOP
	msgbox EventScript_CouponExchange_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_BagFull::
	msgbox EventScript_CouponExchange_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	goto EventScript_PCMainMenu
	release
	end

EventScript_CouponExchange_TryGiveDecor::
	checkdecorspace VAR_0x8009
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CouponExchange_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakePokeCoupons
	adddecoration VAR_0x8009
	special UpdatePokeCouponsWindow
	playse SE_SHOP
	msgbox EventScript_CouponExchange_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_NoRoomForDecor::
	msgbox EventScript_CouponExchange_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	goto EventScript_PCMainMenu
	release
	end

EventScript_CouponExchange_TryGiveBP::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	compare VAR_TEMP_1, MAX_BATTLE_FRONTIER_POINTS
	goto_if_ge EventScript_CouponExchange_NoRoomForBP
	copyvar VAR_0x8004, VAR_0x8008
	special TakePokeCoupons
	copyvar VAR_0x8004, VAR_0x8009
	special GiveFrontierBattlePoints
	special UpdatePokeCouponsWindow
	playse SE_SHOP
	buffernumberstring 0, VAR_0x8009
	msgbox EventScript_CouponExchange_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	goto EventScript_CouponExchange
	end

EventScript_CouponExchange_NoRoomForBP::
	msgbox EventScript_CouponExchange_Text_BPIsMax, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	goto EventScript_PCMainMenu
	release
	end

EventScript_CouponExchange_Exit::
	special CloseBattlePointsWindow
	goto EventScript_PCMainMenu

EventScript_CouponExchange_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

EventScript_CouponExchange_Text_HereIsYourPrize:
	.string "Here is your prize!$"

EventScript_CouponExchange_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

EventScript_CouponExchange_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

EventScript_CouponExchange_Text_DontHaveEnoughCoupons::
	.string "You do not have enough\n"
	.string "Poké Coupons.$"

EventScript_CouponExchange_Text_ConfirmPremierBall:
	.string "You've chosen the Premier Ball.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmLuxuryBall:
	.string "You've chosen the Luxury Ball.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmRareCandy:
	.string "You've chosen the Rare Candy.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmLiechiBerry:
	.string "You've chosen the Liechi Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmGanlonBerry:
	.string "You've chosen the Ganlon Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmSalacBerry:
	.string "You've chosen the Salac Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmPetayaBerry:
	.string "You've chosen the Petaya Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmApicotBerry:
	.string "You've chosen the Apicot Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmLansatBerry:
	.string "You've chosen the Lansat Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmStarfBerry:
	.string "You've chosen the Starf Berry.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmRegirockDoll:
	.string "You've chosen the REGIROCK Doll.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmRegiceDoll:
	.string "You've chosen the REGICE Doll.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmRegisteelDoll:
	.string "You've chosen the REGISTEEL Doll.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_ConfirmMasterBall:
	.string "You've chosen the Master Ball.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_Confirm50BP:
	.string "You've chosen 50 BP.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_Confirm500BP:
	.string "You've chosen 500 BP.\n"
	.string "Is that correct?$"

EventScript_CouponExchange_Text_PremierBallDesc::
	.string "A rare Ball made in commemoration\n"
	.string "of some event.$"

EventScript_CouponExchange_Text_LuxuryBallDesc::
	.string "A cozy Ball that makes Pokémon\n"
	.string "more friendly.$"

EventScript_CouponExchange_Text_RareCandyDesc::
	.string "Raises the level of a Pokémon\n"
	.string "by one.$"

EventScript_CouponExchange_Text_LiechiBerryDesc::
	.string "A hold item that raises Attack\n"
	.string "in a pinch.$"

EventScript_CouponExchange_Text_GanlonBerryDesc::
	.string "A hold item that raises Defense\n"
	.string "in a pinch.$"

EventScript_CouponExchange_Text_SalacBerryDesc::
	.string "A hold item that raises Speed\n"
	.string "in a pinch.$"

EventScript_CouponExchange_Text_PetayaBerryDesc::
	.string "A hold item that raises SP. Atk\n"
	.string "in a pinch.$"

EventScript_CouponExchange_Text_ApicotBerryDesc::
	.string "A hold item that raises SP. Def\n"
	.string "in a pinch.$"

EventScript_CouponExchange_Text_LansatBerryDesc::
	.string "A hold item that ups the critical-\n"
	.string "hit rate in a pinch.$"

EventScript_CouponExchange_Text_StarfBerryDesc::
	.string "A hold item that sharply boosts a\n"
	.string "stat in a pinch.$"

EventScript_CouponExchange_Text_RegirockDollDesc::
	.string "A large Doll.\n"
	.string "Place it on a mat or a desk.$"

EventScript_CouponExchange_Text_RegiceDollDesc::
	.string "A large Doll.\n"
	.string "Place it on a mat or a desk.$"

EventScript_CouponExchange_Text_RegisteelDollDesc::
	.string "A large Doll.\n"
	.string "Place it on a mat or a desk.$"

EventScript_CouponExchange_Text_MasterBallDesc::
	.string "The best Ball that catches\n"
	.string "a Pokémon without fail.$"

EventScript_CouponExchange_Text_50BPDesc::
	.string "Convert Poké Coupons to Battle Points.$"

EventScript_CouponExchange_Text_500BPDesc::
	.string "Convert Poké Coupons to Battle Points.$"

EventScript_CouponExchange_Text_BPIsMax::
	.string "Your BP is already\n"
	.string "at the maximum!$"

EventScript_CouponExchange_Text_ObtainedBattlePoints::
	.string "{PLAYER} obtained\n"
	.string "{STR_VAR_1} Battle Points.$"
