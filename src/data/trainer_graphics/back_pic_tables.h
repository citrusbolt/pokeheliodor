const struct MonCoords gTrainerBackPicCoords[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LEAF] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RS_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RS_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_WALLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_STEVEN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_E_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_E_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_GOLD] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_KRIS] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RY_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RY_LEAF] = {.size = 8, .y_offset = 5},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = {
        .data = (const u32 *)gTrainerBackPic_Brendan,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Brendan),
        .tag = TRAINER_BACK_PIC_BRENDAN,
    },
    [TRAINER_BACK_PIC_MAY] = {
        .data = (const u32 *)gTrainerBackPic_May,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_May),
        .tag = TRAINER_BACK_PIC_MAY,
    },
    [TRAINER_BACK_PIC_RED] = {
        .data = (const u32 *)gTrainerBackPic_Red,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Red),
        .tag = TRAINER_BACK_PIC_RED,
    },
    [TRAINER_BACK_PIC_LEAF] = {
        .data = (const u32 *)gTrainerBackPic_Leaf,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Leaf),
        .tag = TRAINER_BACK_PIC_LEAF,
    },
    [TRAINER_BACK_PIC_RS_BRENDAN] = {
        .data = (const u32 *)gTrainerBackPic_RubySapphireBrendan,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_RubySapphireBrendan),
        .tag = TRAINER_BACK_PIC_RS_BRENDAN,
    },
    [TRAINER_BACK_PIC_RS_MAY] = {
        .data = (const u32 *)gTrainerBackPic_RubySapphireMay,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_RubySapphireMay),
        .tag = TRAINER_BACK_PIC_RS_MAY,
    },
    [TRAINER_BACK_PIC_WALLY] = {
        .data = (const u32 *)gTrainerBackPic_Wally,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Wally),
        .tag = TRAINER_BACK_PIC_WALLY,
    },
    [TRAINER_BACK_PIC_STEVEN] = {
        .data = (const u32 *)gTrainerBackPic_Steven,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Steven),
        .tag = TRAINER_BACK_PIC_STEVEN,
    },
    [TRAINER_BACK_PIC_E_BRENDAN] = {
        .data = (const u32 *)gTrainerBackPic_EmeraldBrendan,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_EmeraldBrendan),
        .tag = TRAINER_BACK_PIC_E_BRENDAN,
    },
    [TRAINER_BACK_PIC_E_MAY] = {
        .data = (const u32 *)gTrainerBackPic_EmeraldMay,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_EmeraldMay),
        .tag = TRAINER_BACK_PIC_E_MAY,
    },
    [TRAINER_BACK_PIC_GOLD] = {
        .data = (const u32 *)gTrainerBackPic_Gold,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Gold),
        .tag = TRAINER_BACK_PIC_GOLD,
    },
    [TRAINER_BACK_PIC_KRIS] = {
        .data = (const u32 *)gTrainerBackPic_Kris,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_Kris),
        .tag = TRAINER_BACK_PIC_KRIS,
    },
    [TRAINER_BACK_PIC_RY_RED] = {
        .data = (const u32 *)gTrainerBackPic_RechargedRed,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_RechargedRed),
        .tag = TRAINER_BACK_PIC_RY_RED,
    },
    [TRAINER_BACK_PIC_RY_LEAF] = {
        .data = (const u32 *)gTrainerBackPic_RechargedLeaf,
        .size = TRAINER_PIC_SIZE * ARRAY_COUNT(gTrainerBackPicTable_RechargedLeaf),
        .tag = TRAINER_BACK_PIC_LEAF,
    },
};

#define TRAINER_BACK_PAL(trainerPic, pal) [TRAINER_BACK_PIC_##trainerPic] = {pal, TRAINER_BACK_PIC_##trainerPic}

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] =
{
    TRAINER_BACK_PAL(BRENDAN, gTrainerBackPicPalette_Brendan),
    TRAINER_BACK_PAL(MAY, gTrainerBackPicPalette_May),
    TRAINER_BACK_PAL(RED, gTrainerBackPicPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerBackPicPalette_Leaf),
    TRAINER_BACK_PAL(RS_BRENDAN, gTrainerBackPicPalette_RubySapphireBrendan),
    TRAINER_BACK_PAL(RS_MAY, gTrainerBackPicPalette_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerBackPicPalette_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerBackPicPalette_Steven),
    TRAINER_BACK_PAL(E_BRENDAN, gTrainerBackPicPalette_EmeraldBrendan),
    TRAINER_BACK_PAL(E_MAY, gTrainerBackPicPalette_EmeraldMay),
    TRAINER_BACK_PAL(GOLD, gTrainerBackPicPalette_Gold),
    TRAINER_BACK_PAL(KRIS, gTrainerBackPicPalette_Kris),
    TRAINER_BACK_PAL(RY_RED, gTrainerBackPicPalette_RechargedRed),
    TRAINER_BACK_PAL(RY_LEAF, gTrainerBackPicPalette_RechargedLeaf),
};
