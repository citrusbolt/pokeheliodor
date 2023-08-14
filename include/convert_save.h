#ifndef GUARD_CONVERT_SAVE_H
#define GUARD_CONVERT_SAVE_H

#define SAVE_TYPE_RS    0
#define SAVE_TYPE_FRLG  1
#define SAVE_TYPE_E     2
#define SAVE_TYPE_NL    3

u8 DetectSaveType(void);
u8 ConvertSaveFileFromRSToNL(void);
u8 ConvertSaveFileFromEToNL(void);

#endif // GUARD_CONVERT_SAVE_H