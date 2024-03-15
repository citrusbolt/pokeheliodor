#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

u8 ScriptGiveMon(u16, u8, u16, u8);
u8 ScriptGiveUnown(u8, u16);
u8 ScriptGiveEgg(u16, u8);
void CreateScriptedWildMon(u16, u8, u8, u16);
void ScriptSetMonMoveSlot(u8, u16, u8);
void ReducePlayerPartyToSelectedMons(void);
void HealPlayerParty(void);

#endif // GUARD_SCRIPT_POKEMON_UTIL_H
