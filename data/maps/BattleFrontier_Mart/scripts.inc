.set LOCALID_OLD_WOMAN, 2

BattleFrontier_Mart_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

	.align 2
BattleFrontier_Mart_PokemartTM:
	.2byte ITEM_TM01
	.2byte ITEM_TM02
	.2byte ITEM_TM03
	.2byte ITEM_TM04
	.2byte ITEM_TM05
	.2byte ITEM_TM06
	.2byte ITEM_TM07
	.2byte ITEM_TM08
	.2byte ITEM_TM09
	.2byte ITEM_TM10
	.2byte ITEM_TM11
	.2byte ITEM_TM12
	.2byte ITEM_TM13
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_TM16
	.2byte ITEM_TM17
	.2byte ITEM_TM18
	.2byte ITEM_TM19
	.2byte ITEM_TM20
	.2byte ITEM_TM21
	.2byte ITEM_TM22
	.2byte ITEM_TM23
	.2byte ITEM_TM24
	.2byte ITEM_TM25
	.2byte ITEM_TM26
	.2byte ITEM_TM27
	.2byte ITEM_TM28
	.2byte ITEM_TM29
	.2byte ITEM_TM30
	.2byte ITEM_TM31
	.2byte ITEM_TM32
	.2byte ITEM_TM33
	.2byte ITEM_TM34
	.2byte ITEM_TM35
	.2byte ITEM_TM36
	.2byte ITEM_TM37
	.2byte ITEM_TM38
	.2byte ITEM_TM39
	.2byte ITEM_TM40
	.2byte ITEM_TM41
	.2byte ITEM_TM42
	.2byte ITEM_TM43
	.2byte ITEM_TM44
	.2byte ITEM_TM45
	.2byte ITEM_TM46
	.2byte ITEM_TM47
	.2byte ITEM_TM48
	.2byte ITEM_TM49
	.2byte ITEM_TM50
	.2byte ITEM_NONE
	release
	end

BattleFrontier_Mart_EventScript_ClerkTM::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTM
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We came here to chaperon our\n"
	.string "grandson.\p"
	.string "But since we're here, we thought\n"
	.string "we should get some souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Dear, what do you think of this?\n"
	.string "Wouldn't this make a nice gift?\p"
	.string "It's…PRO…TE…IN?\n"
	.string "It sounds delicious, doesn't it?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "A lot of the BATTLE FRONTIER's\n"
	.string "facilities don't allow the use of items\l"
	.string "during battles.\p"
	.string "That rule makes things tougher than\n"
	.string "they already are!$"

