static const union AnimCmd sAnimCmd_FourFrame[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_FiveFrame[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sBackAnims_FourFrame[] =
{
    sAnim_GeneralFrame3,
    sAnimCmd_FourFrame,
};

static const union AnimCmd *const sBackAnims_FiveFrame[] =
{
    sAnim_GeneralFrame0,
    sAnimCmd_FiveFrame,
};

const union AnimCmd *const *const gTrainerBackAnimsPtrTable[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_MAY] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_RED] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_LEAF] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_RS_BRENDAN] = sBackAnims_FourFrame,
    [TRAINER_BACK_PIC_RS_MAY] = sBackAnims_FourFrame,
    [TRAINER_BACK_PIC_WALLY] = sBackAnims_FourFrame,
    [TRAINER_BACK_PIC_STEVEN] = sBackAnims_FourFrame,
    [TRAINER_BACK_PIC_E_BRENDAN] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_E_MAY] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_GOLD] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_KRIS] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_RY_RED] = sBackAnims_FiveFrame,
    [TRAINER_BACK_PIC_RY_LEAF] = sBackAnims_FiveFrame,
};
