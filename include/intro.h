#ifndef GUARD_INTRO_H
#define GUARD_INTRO_H

// Exported type declarations

// Exported RAM declarations
extern struct GcmbStruct gMultibootProgramStruct;

// Exported ROM declarations
void CB2_InitCopyrightScreenAfterBootup(void);
void CB2_InitCopyrightScreenAfterTitleScreen(void);
void PanFadeAndZoomScreen(u16, u16, u16, u16);
void CB2_DetectGameBoyPlayer(void);

#endif // GUARD_INTRO_H
