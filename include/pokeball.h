#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

enum
{
    BALL_NONE,
    BALL_MASTER,
    BALL_ULTRA,
    BALL_GREAT,
    BALL_POKE,
    BALL_SAFARI,
    BALL_NET,
    BALL_DIVE,
    BALL_NEST,
    BALL_REPEAT,
    BALL_TIMER,
    BALL_LUXURY,
    BALL_PREMIER,
    BALL_DUSK,
    BALL_HEAL,
    BALL_QUICK,
    BALL_CHERISH,
    BALL_FAST,
    BALL_LEVEL,
    BALL_LURE,
    BALL_HEAVY,
    BALL_LOVE,
    BALL_FRIEND,
    BALL_MOON,
    BALL_SPORT,
    BALL_PARK,
    BALL_DREAM,
    BALL_BEAST,
    BALL_STRANGE,
    BALL_HISUI_POKE,
    BALL_HISUI_GREAT,
    BALL_HISUI_ULTRA,
    BALL_HISUI_FEATHER,
    BALL_HISUI_WING,
    BALL_HISUI_JET,
    BALL_HISUI_HEAVY,
    BALL_HISUI_LEADEN,
    BALL_HISUI_GIGATON,
    BALL_HISUI_ORIGIN,
    POKEBALL_COUNT
};

enum {
    BALL_AFFINE_ANIM_0,
    BALL_ROTATE_RIGHT,
    BALL_ROTATE_LEFT,
    BALL_AFFINE_ANIM_3,
    BALL_AFFINE_ANIM_4
};

extern const struct CompressedSpriteSheet gBallSpriteSheets[];
extern const struct CompressedSpritePalette gBallSpritePalettes[];
extern const struct SpriteTemplate gBallSpriteTemplates[];
extern const struct SpriteTemplate gBallSummarySpriteTemplates[];

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow);
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subpriority, u8 delay, u32 fadePalettes, u16 species, u8 form);
u8 CreateTradePokeballSprite(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 delay, u32 fadePalettes);
void StartHealthboxSlideIn(u8 battler);
void DoHitAnimHealthboxEffect(u8 battler);
void LoadBallGfx(u8 ballId);
void FreeBallGfx(u8 ballId);

#endif // GUARD_POKEBALL_H
