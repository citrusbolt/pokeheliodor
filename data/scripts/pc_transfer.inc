@ VAR_0x8004 here is used by ChangePokemonNickname
Common_EventScript_GetGiftMonPartySlot:: @ 827378B
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	return

Common_EventScript_NameReceivedBoxMon:: @ 8273797
	fadescreen FADE_TO_BLACK
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	return

Common_EventScript_TransferredToPC:: @ 82737A0
	bufferspeciesname 1, VAR_TEMP_1
	call Common_EventScript_CheckMonHasItem
	bufferboxname 0, VAR_PC_BOX_TO_SEND_MON
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_TransferredSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_TransferredLanettesPC
	return

EventScript_TransferredSomeonesPC:: @ 82737BB
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	compare VAR_RESULT, 1
	goto_if_eq EventScript_SomeonesPCBoxFull
	msgbox gText_PkmnTransferredSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_SomeonesPCBoxFull:: @ 82737D4
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname 2, VAR_RESULT
	msgbox gText_PkmnTransferredSomeonesPCBoxFull, MSGBOX_DEFAULT
	return

EventScript_TransferredLanettesPC:: @ 82737E6
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_LanettesPCBoxFull
	msgbox gText_PkmnTransferredLanettesPC, MSGBOX_DEFAULT
	return

EventScript_LanettesPCBoxFull:: @ 82737FF
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname 2, VAR_RESULT
	msgbox gText_PkmnTransferredLanettesPCBoxFull, MSGBOX_DEFAULT
	return

Common_EventScript_NoMoreRoomForPokemon:: @ 8273811
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	release
	end

Common_EventScript_CheckMonHasItem::
	specialvar VAR_RESULT, DoesGiftMonHaveItem
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_AskToTakeItem
	return

Common_EventScript_AskToTakeItem::
	msgbox gText_TakeItemCaptured, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_TakeCaughtMonItem
	return

Common_EventScript_TakeCaughtMonItem::
	special PutGiftMonItemInBag
	msgbox gText_ItemTaken, MSGBOX_DEFAULT
	return
