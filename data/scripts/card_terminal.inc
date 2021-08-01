EventScript_CardTerminal::
	lock
	playse SE_PC_ON
EventScript_CardTerminal_Menu:
	message EventScript_CardTerminal_Text_Begin
	waitmessage
	setvar VAR_RESULT, 255
	special ScriptMenu_CreateCardTerminalMultichoice
	waitstate
	switch VAR_RESULT
	case 0, EventScript_CardTerminal_Type
	case 1, EventScript_CardTerminal_Sticker
	case 2, EventScript_CardTerminal_IconTint
	case 3, EventScript_CardTerminal_Stat1
	case MULTI_B_PRESSED, EventScript_CardTerminal_Exit
	end

EventScript_CardTerminal_Exit:
	playse SE_PC_OFF
	release
	end

EventScript_CardTerminal_Type:
	message EventScript_CardTerminal_Text_Type
	waitmessage
	special ScriptMenu_CreateCardTerminalMultichoice
	waitstate
	compare VAR_RESULT, 4
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
	special UpdateTrainerCardLayout
	goto EventScript_CardTerminal_Updated
	end

EventScript_CardTerminal_Sticker:
	message EventScript_CardTerminal_Text_Sticker
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STICKER
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
	special UpdateTrainerCardStickers
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_CardTerminal_UpdatedSticker
	msgbox EventScript_CardTerminal_Text_NoNewSticker, MSGBOX_DEFAULT
	goto EventScript_CardTerminal_Sticker
	end

EventScript_CardTerminal_IconTint:
	message EventScript_CardTerminal_Text_IconTint
	waitmessage
	special ScriptMenu_CreateCardTerminalMultichoice
	waitstate
	compare VAR_RESULT, 4
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
	special UpdateTrainerCardMonIcons
	goto EventScript_CardTerminal_Updated
	end

EventScript_CardTerminal_Stat1:
	message EventScript_CardTerminal_Text_Stat1
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STATS
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_RESULT, 12
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
EventScript_CardTerminal_Stat2:
	message EventScript_CardTerminal_Text_Stat2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STATS
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8006, VAR_RESULT
	compare VAR_RESULT, 12
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
EventScript_CardTerminal_Stat3:
	message EventScript_CardTerminal_Text_Stat3
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STATS
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8007, VAR_RESULT
	compare VAR_RESULT, 12
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
EventScript_CardTerminal_Stat4:
	message EventScript_CardTerminal_Text_Stat4
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STATS
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_RESULT, 12
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
EventScript_CardTerminal_Stat5:
	message EventScript_CardTerminal_Text_Stat5
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_CARD_TERMINAL_STATS
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_0x8009, VAR_RESULT
	compare VAR_RESULT, 12
	goto_if_eq EventScript_CardTerminal_Menu
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CardTerminal_Menu
	special UpdateTrainerCardStats
	goto EventScript_CardTerminal_Updated
	end

EventScript_CardTerminal_UpdatedSticker:
	msgbox EventScript_CardTerminal_Text_UpdatedSticker, MSGBOX_DEFAULT
	goto EventScript_CardTerminal_Updated
	end

EventScript_CardTerminal_Updated:
	msgbox EventScript_CardTerminal_Text_Updated, MSGBOX_DEFAULT
	goto EventScript_CardTerminal_Exit
	end

EventScript_CardTerminal_Text_Begin:
	.string "Which Trainer Card service\n"
	.string "should be accessed?$"

EventScript_CardTerminal_Text_Type:
	.string "Which Trainer Card style\n"
	.string "would you like to use?$"

EventScript_CardTerminal_Text_Sticker:
	.string "Which sticker upgrade\n"
	.string "would you like to check on?$"

EventScript_CardTerminal_Text_IconTint:
	.string "Which color filter\n"
	.string "would you like to use?$"

EventScript_CardTerminal_Text_Stat1:
	.string "Which stat would you\n"
	.string "like to display first?$"

EventScript_CardTerminal_Text_Stat2:
	.string "Which stat would you\n"
	.string "like to display second?$"

EventScript_CardTerminal_Text_Stat3:
	.string "Which stat would you\n"
	.string "like to display third?$"

EventScript_CardTerminal_Text_Stat4:
	.string "Which stat would you\n"
	.string "like to display fourth?$"

EventScript_CardTerminal_Text_Stat5:
	.string "Which stat would you\n"
	.string "like to display fifth?$"

EventScript_CardTerminal_Text_NoNewSticker:
	.string "No new {STR_VAR_1} sticker\n"
	.string "is available.$"

EventScript_CardTerminal_Text_UpdatedSticker:
	.string "A new {STR_VAR_1} sticker\n"
	.string "has been issued!$"

EventScript_CardTerminal_Text_Updated:
	.string "Your Trainer Card has\n"
	.string "been updated!$"
