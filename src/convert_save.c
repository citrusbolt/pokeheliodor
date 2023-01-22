#include "global.h"
#include "other_saves.h"
#include "save.h"

u8 DetectSaveType(void)
{
    u32 i;
    u8 *rawBlock2 = (u8 *)gSaveBlock2Ptr;

    for (i = 0x890; i < 0xF2C; i++)
    {
        if (rawBlock2[i] != 0)
            return 1; // E
    }

    return 2; // RS
}
