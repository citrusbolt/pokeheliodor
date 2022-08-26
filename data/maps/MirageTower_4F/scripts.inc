.set LOCALID_RUBY, 1
.set LOCALID_SAPPHIRE, 2

MirageTower_4F_MapScripts::
	.byte 0

MirageTower_4F_EventScript_Ruby::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRuby, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRuby
	giveitem ITEM_RUBY
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_RUBY
	setflag FLAG_HIDE_MIRAGE_TOWER_SAPPHIRE
	removeobject LOCALID_RUBY
	delay 30
	setflag FLAG_GOT_GEM
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRuby::
	msgbox MirageTower_4F_Text_LeftRubyAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_Sapphire::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeSapphire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveSapphire
	giveitem ITEM_SAPPHIRE
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_SAPPHIRE
	setflag FLAG_HIDE_MIRAGE_TOWER_RUBY
	removeobject LOCALID_SAPPHIRE
	delay 30
	setflag FLAG_GOT_GEM
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveSapphire::
	msgbox MirageTower_4F_Text_LeaveSapphireAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_TakeRuby:
	.string "You found the Ruby.\p"
	.string "If this gem is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the Ruby anyway?$"

MirageTower_4F_Text_LeftRubyAlone:
	.string "{PLAYER} left the Ruby alone.$"

MirageTower_4F_Text_TakeSapphire:
	.string "You found the Sapphire.\p"
	.string "If this gem is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the Sapphire anyway?$"

MirageTower_4F_Text_LeaveSapphireAlone:
	.string "{PLAYER} left the Sapphire alone.$"

