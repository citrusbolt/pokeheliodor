#include "global.h"
#include "malloc.h"
#include "battle_pyramid.h"
#include "berry.h"
#include "day_night.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "mauville_old_man.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sprite.h"
#include "task.h"
#include "trainer_see.h"
#include "trainer_hill.h"
#include "util.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/mauville_old_man.h"
#include "constants/trainer_types.h"
#include "constants/union_room.h"

// this file was known as evobjmv.c in Game Freak's original source

#define movement_type_def(setup, table) \
static u8 setup##_callback(struct ObjectEvent *, struct Sprite *);\
void setup(struct Sprite *sprite)\
{\
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, setup##_callback);\
}\
static u8 setup##_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)\
{\
    return table[sprite->data[1]](objectEvent, sprite);\
}

#define movement_type_empty_callback(setup) \
static u8 setup##_callback(struct ObjectEvent *, struct Sprite *);\
void setup(struct Sprite *sprite)\
{\
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, setup##_callback);\
}\
static u8 setup##_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)\
{\
    return 0;\
}

EWRAM_DATA u8 sCurrentReflectionType = 0;
EWRAM_DATA u16 sCurrentSpecialObjectPaletteTag = 0;
EWRAM_DATA struct LockedAnimObjectEvents *gLockedAnimObjectEvents = {0};

static void MoveCoordsInDirection(u32, s16 *, s16 *, s16, s16);
static bool8 ObjectEventExecSingleMovementAction(struct ObjectEvent *, struct Sprite *);
static void SetMovementDelay(struct Sprite *, s16);
static bool8 WaitForMovementDelay(struct Sprite *);
static u8 GetCollisionInDirection(struct ObjectEvent *, u8);
static u32 state_to_direction(u8, u32, u32);
static void TryEnableObjectEventAnim(struct ObjectEvent *, struct Sprite *);
static void ObjectEventExecHeldMovementAction(struct ObjectEvent *, struct Sprite *);
static void UpdateObjectEventSpriteAnimPause(struct ObjectEvent *, struct Sprite *);
static bool8 IsCoordOutsideObjectEventMovementRange(struct ObjectEvent *, s16, s16);
static bool8 IsMetatileDirectionallyImpassable(struct ObjectEvent *, s16, s16, u8);
static bool8 DoesObjectCollideWithObjectAt(struct ObjectEvent *, s16, s16);
static void sub_8096530(struct ObjectEvent *, struct Sprite *);
static void UpdateObjEventSpriteVisibility(struct ObjectEvent *, struct Sprite *);
static void ObjectEventUpdateMetatileBehaviors(struct ObjectEvent*);
static void GetGroundEffectFlags_Reflection(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_TallGrassOnSpawn(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_LongGrassOnSpawn(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_SandHeap(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_ShallowFlowingWater(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_ShortGrass(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_HotSprings(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_TallGrassOnBeginStep(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_LongGrassOnBeginStep(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_Tracks(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_Puddle(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_Ripple(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_Seaweed(struct ObjectEvent*, u32*);
static void GetGroundEffectFlags_JumpLanding(struct ObjectEvent*, u32*);
static u8 ObjectEventCheckForReflectiveSurface(struct ObjectEvent*);
static u8 GetReflectionTypeByMetatileBehavior(u32);
static void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z);
static void ObjectEventUpdateSubpriority(struct ObjectEvent*, struct Sprite*);
static void DoTracksGroundEffect_None(struct ObjectEvent*, struct Sprite*, u8);
static void DoTracksGroundEffect_Footprints(struct ObjectEvent*, struct Sprite*, u8);
static void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent*, struct Sprite*, u8);
static void DoRippleFieldEffect(struct ObjectEvent*, struct Sprite*);
static void DoGroundEffects_OnSpawn(struct ObjectEvent*, struct Sprite*);
static void DoGroundEffects_OnBeginStep(struct ObjectEvent*, struct Sprite*);
static void DoGroundEffects_OnFinishStep(struct ObjectEvent*, struct Sprite*);
static void UpdateObjectEventSpritePosition(struct Sprite*);
static void ApplyLevitateMovement(u8);
static bool8 MovementType_Disguise_Callback(struct ObjectEvent *, struct Sprite *);
static bool8 MovementType_Hidden_Callback(struct ObjectEvent *, struct Sprite *);
static void CreateReflectionEffectSprites(void);
static u8 GetObjectEventIdByLocalId(u8);
static u8 GetObjectEventIdByLocalIdAndMapInternal(u8, u8, u8);
static bool8 GetAvailableObjectEventId(u16, u8, u8, u8 *);
static void SetObjectEventDynamicGraphicsId(struct ObjectEvent *);
static void RemoveObjectEventInternal(struct ObjectEvent *);
static u16 GetObjectEventFlagIdByObjectEventId(u8);
static void UpdateObjectEventVisibility(struct ObjectEvent *, struct Sprite *);
static void MakeObjectTemplateFromObjectEventTemplate(struct ObjectEventTemplate *, struct SpriteTemplate *, const struct SubspriteTable **);
static void GetObjectEventMovingCameraOffset(s16 *, s16 *);
static struct ObjectEventTemplate *GetObjectEventTemplateByLocalIdAndMap(u8, u8, u8);
static void LoadObjectEventPalette(u16);
static void RemoveObjectEventIfOutsideView(struct ObjectEvent *);
static void sub_808E1B8(u8, s16, s16);
static void SetPlayerAvatarObjectEventIdAndObjectId(u8, u8);
static void sub_808E38C(struct ObjectEvent *);
static u8 sub_808E8F4(const struct SpritePalette *);
static u8 FindObjectEventPaletteIndexByTag(u16);
static void sub_808EAB0(u16, u8);
static bool8 ObjectEventDoesZCoordMatch(struct ObjectEvent *, u8);
static void ObjectCB_CameraObject(struct Sprite *);
static void CameraObject_0(struct Sprite *);
static void CameraObject_1(struct Sprite *);
static void CameraObject_2(struct Sprite *);
static struct ObjectEventTemplate *FindObjectEventTemplateByLocalId(u8 localId, struct ObjectEventTemplate *templates, u8 count);
static void ClearObjectEventMovement(struct ObjectEvent *, struct Sprite *);
static void ObjectEventSetSingleMovement(struct ObjectEvent *, struct Sprite *, u8);
static void oamt_npc_ministep_reset(struct Sprite *, u8, u8);
static void UpdateObjectEventSpriteSubpriorityAndVisibility(struct Sprite *);
static void InitSpriteForFigure8Anim(struct Sprite *sprite);
static bool8 AnimateSpriteInFigure8(struct Sprite *sprite);
static void UpdateObjectEventSprite(struct Sprite *);

const u8 gReflectionEffectPaletteMap[] = {1, 1, 6, 7, 8, 9, 6, 7, 8, 9, 11, 11, 0, 0, 0, 0};

const struct SpriteTemplate gCameraSpriteTemplate = {0, 0xFFFF, &gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, ObjectCB_CameraObject};

void (*const gCameraObjectFuncs[])(struct Sprite *) = {
    CameraObject_0,
    CameraObject_1,
    CameraObject_2,
};

#include "data/object_events/object_event_graphics.h"

// movement type callbacks
static void (*const sMovementTypeCallbacks[])(struct Sprite *) =
{
    [MOVEMENT_TYPE_NONE] = MovementType_None,
    [MOVEMENT_TYPE_LOOK_AROUND] = MovementType_LookAround,
    [MOVEMENT_TYPE_WANDER_AROUND] = MovementType_WanderAround,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_DOWN] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_LEFT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_RIGHT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_PLAYER] = MovementType_Player,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = MovementType_BerryTreeGrowth,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = MovementType_FaceDownAndUp,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = MovementType_FaceLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = MovementType_FaceUpAndLeft,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = MovementType_FaceUpAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = MovementType_FaceDownAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = MovementType_FaceDownAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = MovementType_FaceDownUpAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = MovementType_FaceDownUpAndRight,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = MovementType_FaceUpRightAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = MovementType_FaceDownRightAndLeft,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = MovementType_RotateCounterclockwise,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = MovementType_RotateClockwise,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = MovementType_WalkSequenceUpRightLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = MovementType_WalkSequenceRightLeftDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = MovementType_WalkSequenceDownUpRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = MovementType_WalkSequenceLeftDownUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = MovementType_WalkSequenceUpLeftRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = MovementType_WalkSequenceLeftRightDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = MovementType_WalkSequenceDownUpLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = MovementType_WalkSequenceRightDownUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = MovementType_WalkSequenceLeftUpDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = MovementType_WalkSequenceUpDownRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = MovementType_WalkSequenceRightLeftUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = MovementType_WalkSequenceDownRightLeftUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = MovementType_WalkSequenceRightUpDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = MovementType_WalkSequenceUpDownLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = MovementType_WalkSequenceLeftRightUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = MovementType_WalkSequenceDownLeftRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = MovementType_WalkSequenceUpLeftDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = MovementType_WalkSequenceDownRightUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = MovementType_WalkSequenceLeftDownRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = MovementType_WalkSequenceRightUpLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = MovementType_WalkSequenceUpRightDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = MovementType_WalkSequenceDownLeftUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = MovementType_WalkSequenceLeftUpRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = MovementType_WalkSequenceRightDownLeftUp,
    [MOVEMENT_TYPE_COPY_PLAYER] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_TREE_DISGUISE] = MovementType_TreeDisguise,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = MovementType_MountainDisguise,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_HIDDEN] = MovementType_Hidden,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_INVISIBLE] = MovementType_Invisible,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = MovementType_WalkSlowlyInPlace,
};

const u8 gRangedMovementTypes[] = {
    [MOVEMENT_TYPE_NONE] = 0,
    [MOVEMENT_TYPE_LOOK_AROUND] = 0,
    [MOVEMENT_TYPE_WANDER_AROUND] = 1,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = 1,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = 1,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = 1,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = 1,
    [MOVEMENT_TYPE_FACE_UP] = 0,
    [MOVEMENT_TYPE_FACE_DOWN] = 0,
    [MOVEMENT_TYPE_FACE_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_RIGHT] = 0,
    [MOVEMENT_TYPE_PLAYER] = 0,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = 0,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = 0,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = 0,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = 0,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = 1,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = 1,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = 1,
    [MOVEMENT_TYPE_TREE_DISGUISE] = 0,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = 0,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = 1,
    [MOVEMENT_TYPE_HIDDEN] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = 0,
    [MOVEMENT_TYPE_INVISIBLE] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = 0,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = 0,
};

const u8 gInitialMovementTypeFacingDirections[] = {
    [MOVEMENT_TYPE_NONE] = DIR_SOUTH,
    [MOVEMENT_TYPE_LOOK_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_FACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_PLAYER] = DIR_SOUTH,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = DIR_EAST,
    [MOVEMENT_TYPE_COPY_PLAYER] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = DIR_EAST,
    [MOVEMENT_TYPE_TREE_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = DIR_EAST,
    [MOVEMENT_TYPE_HIDDEN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_INVISIBLE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = DIR_EAST,
};

#define OBJ_EVENT_PAL_TAG_BRENDAN                 0x1100
#define OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION      0x1101
#define OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION       0x1102
#define OBJ_EVENT_PAL_TAG_NPC_1                   0x1103
#define OBJ_EVENT_PAL_TAG_NPC_2                   0x1104
#define OBJ_EVENT_PAL_TAG_NPC_3                   0x1105
#define OBJ_EVENT_PAL_TAG_NPC_4                   0x1106
#define OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION        0x1107
#define OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION        0x1108
#define OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION        0x1109
#define OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION        0x110A
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP            0x110B
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION 0x110C
#define OBJ_EVENT_PAL_TAG_TRUCK                   0x110D
#define OBJ_EVENT_PAL_TAG_VIGOROTH                0x110E
#define OBJ_EVENT_PAL_TAG_ZIGZAGOON               0x110F
#define OBJ_EVENT_PAL_TAG_MAY                     0x1110
#define OBJ_EVENT_PAL_TAG_MAY_REFLECTION          0x1111
#define OBJ_EVENT_PAL_TAG_MOVING_BOX              0x1112
#define OBJ_EVENT_PAL_TAG_CABLE_CAR               0x1113
#define OBJ_EVENT_PAL_TAG_SSTIDAL                 0x1114
#define OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER       0x1115
#define OBJ_EVENT_PAL_TAG_KYOGRE                  0x1116
#define OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION       0x1117
#define OBJ_EVENT_PAL_TAG_GROUDON                 0x1118
#define OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION      0x1119
#define OBJ_EVENT_PAL_TAG_UNUSED                  0x111A
#define OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW        0x111B
#define OBJ_EVENT_PAL_TAG_POOCHYENA               0x111C
#define OBJ_EVENT_PAL_TAG_RED_LEAF                0x111D
#define OBJ_EVENT_PAL_TAG_DEOXYS                  0x111E
#define OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE      0x111F
#define OBJ_EVENT_PAL_TAG_HO_OH                   0x1120
#define OBJ_EVENT_PAL_TAG_LUGIA                   0x1121
#define OBJ_EVENT_PAL_TAG_RS_BRENDAN              0x1122
#define OBJ_EVENT_PAL_TAG_RS_MAY                  0x1123
#define OBJ_EVENT_PAL_TAG_ZAPDOS                  0x1124
#define OBJ_EVENT_PAL_TAG_MEWTWO                  0x1125
#define OBJ_EVENT_PAL_TAG_NONE                    0x11FF

#include "data/object_events/object_event_graphics_info_pointers.h"
#include "data/field_effects/field_effect_object_template_pointers.h"
#include "data/object_events/object_event_pic_tables.h"
#include "data/object_events/object_event_anims.h"
#include "data/object_events/base_oam.h"
#include "data/object_events/object_event_subsprites.h"
#include "data/object_events/object_event_graphics_info.h"

static const struct SpritePalette sObjectEventSpritePalettes[] = {
    {gObjectEventPal_Npc1,                  OBJ_EVENT_PAL_TAG_NPC_1},
    {gObjectEventPal_Npc2,                  OBJ_EVENT_PAL_TAG_NPC_2},
    {gObjectEventPal_Npc3,                  OBJ_EVENT_PAL_TAG_NPC_3},
    {gObjectEventPal_Npc4,                  OBJ_EVENT_PAL_TAG_NPC_4},
    {gObjectEventPal_Npc1Reflection,        OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION},
    {gObjectEventPal_Npc2Reflection,        OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION},
    {gObjectEventPal_Npc3Reflection,        OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION},
    {gObjectEventPal_Npc4Reflection,        OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION},
    {gObjectEventPal_Brendan,               OBJ_EVENT_PAL_TAG_BRENDAN},
    {gObjectEventPal_BrendanReflection,     OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION},
    {gObjectEventPal_BridgeReflection,      OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION},
    {gObjectEventPal_PlayerUnderwater,      OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER},
    {gObjectEventPal_QuintyPlump,           OBJ_EVENT_PAL_TAG_QUINTY_PLUMP},
    {gObjectEventPal_QuintyPlumpReflection, OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION},
    {gObjectEventPal_Truck,                 OBJ_EVENT_PAL_TAG_TRUCK},
    {gObjectEventPal_Vigoroth,              OBJ_EVENT_PAL_TAG_VIGOROTH},
    {gObjectEventPal_EnemyZigzagoon,        OBJ_EVENT_PAL_TAG_ZIGZAGOON},
    {gObjectEventPal_May,                   OBJ_EVENT_PAL_TAG_MAY},
    {gObjectEventPal_MayReflection,         OBJ_EVENT_PAL_TAG_MAY_REFLECTION},
    {gObjectEventPal_MovingBox,             OBJ_EVENT_PAL_TAG_MOVING_BOX},
    {gObjectEventPal_CableCar,              OBJ_EVENT_PAL_TAG_CABLE_CAR},
    {gObjectEventPal_SSTidal,               OBJ_EVENT_PAL_TAG_SSTIDAL},
    {gObjectEventPal_Kyogre,                OBJ_EVENT_PAL_TAG_KYOGRE},
    {gObjectEventPal_KyogreReflection,      OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION},
    {gObjectEventPal_Groudon,               OBJ_EVENT_PAL_TAG_GROUDON},
    {gObjectEventPal_GroudonReflection,     OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION},
    {gObjectEventPal_SubmarineShadow,       OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW},
    {gObjectEventPal_Poochyena,             OBJ_EVENT_PAL_TAG_POOCHYENA},
    {gObjectEventPal_RedLeaf,               OBJ_EVENT_PAL_TAG_RED_LEAF},
    {gObjectEventPal_Deoxys,                OBJ_EVENT_PAL_TAG_DEOXYS},
    {gObjectEventPal_BirthIslandStone,      OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE},
    {gObjectEventPal_HoOh,                  OBJ_EVENT_PAL_TAG_HO_OH},
    {gObjectEventPal_Lugia,                 OBJ_EVENT_PAL_TAG_LUGIA},
    {gObjectEventPal_RubySapphireBrendan,   OBJ_EVENT_PAL_TAG_RS_BRENDAN},
    {gObjectEventPal_RubySapphireMay,       OBJ_EVENT_PAL_TAG_RS_MAY},
    {gObjectEventPal_Zapdos,                OBJ_EVENT_PAL_TAG_ZAPDOS},
    {gObjectEventPal_Mewtwo,                OBJ_EVENT_PAL_TAG_MEWTWO},
    {NULL,                                  0x0000},
};

static const u16 sReflectionPaletteTags_Brendan[] = {
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
};

static const u16 sReflectionPaletteTags_May[] = {
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
};

static const u16 sReflectionPaletteTags_PlayerUnderwater[] = {
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
};

static const struct PairedPalettes sPlayerReflectionPaletteSets[] = {
    {OBJ_EVENT_PAL_TAG_BRENDAN,           sReflectionPaletteTags_Brendan},
    {OBJ_EVENT_PAL_TAG_MAY,               sReflectionPaletteTags_May},
    {OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER, sReflectionPaletteTags_PlayerUnderwater},
    {OBJ_EVENT_PAL_TAG_NONE,              NULL},
};

static const u16 sReflectionPaletteTags_QuintyPlump[] = {
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
};

static const u16 sReflectionPaletteTags_Truck[] = {
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
};

static const u16 sReflectionPaletteTags_VigorothMover[] = {
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
};

static const u16 sReflectionPaletteTags_MovingBox[] = {
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
};

static const u16 sReflectionPaletteTags_CableCar[] = {
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
};

static const u16 sReflectionPaletteTags_SSTidal[] = {
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
};

static const u16 sReflectionPaletteTags_SubmarineShadow[] = {
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
};

static const u16 sReflectionPaletteTags_Kyogre[] = {
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
};

static const u16 sReflectionPaletteTags_Groudon[] = {
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
};

static const u16 sReflectionPaletteTags_Npc3[] = { // Only used by the Route 120 bridge Kecleon
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
};

static const u16 sReflectionPaletteTags_RedLeaf[] = {
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
};

static const struct PairedPalettes sSpecialObjectReflectionPaletteSets[] = {
    {OBJ_EVENT_PAL_TAG_BRENDAN,          sReflectionPaletteTags_Brendan},
    {OBJ_EVENT_PAL_TAG_MAY,              sReflectionPaletteTags_May},
    {OBJ_EVENT_PAL_TAG_QUINTY_PLUMP,     sReflectionPaletteTags_QuintyPlump},
    {OBJ_EVENT_PAL_TAG_TRUCK,            sReflectionPaletteTags_Truck},
    {OBJ_EVENT_PAL_TAG_VIGOROTH,         sReflectionPaletteTags_VigorothMover},
    {OBJ_EVENT_PAL_TAG_MOVING_BOX,       sReflectionPaletteTags_MovingBox},
    {OBJ_EVENT_PAL_TAG_CABLE_CAR,        sReflectionPaletteTags_CableCar},
    {OBJ_EVENT_PAL_TAG_SSTIDAL,          sReflectionPaletteTags_SSTidal},
    {OBJ_EVENT_PAL_TAG_KYOGRE,           sReflectionPaletteTags_Kyogre},
    {OBJ_EVENT_PAL_TAG_GROUDON,          sReflectionPaletteTags_Groudon},
    {OBJ_EVENT_PAL_TAG_NPC_3,            sReflectionPaletteTags_Npc3},
    {OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW, sReflectionPaletteTags_SubmarineShadow},
    {OBJ_EVENT_PAL_TAG_RED_LEAF,         sReflectionPaletteTags_RedLeaf},
    {OBJ_EVENT_PAL_TAG_NONE,             NULL},
};

static const u16 sObjectPaletteTags0[] = {
    OBJ_EVENT_PAL_TAG_BRENDAN,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_1,
    OBJ_EVENT_PAL_TAG_NPC_2,
    OBJ_EVENT_PAL_TAG_NPC_3,
    OBJ_EVENT_PAL_TAG_NPC_4,
    OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

static const u16 sObjectPaletteTags1[] = {
    OBJ_EVENT_PAL_TAG_BRENDAN,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_1,
    OBJ_EVENT_PAL_TAG_NPC_2,
    OBJ_EVENT_PAL_TAG_NPC_3,
    OBJ_EVENT_PAL_TAG_NPC_4,
    OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

static const u16 sObjectPaletteTags2[] = {
    OBJ_EVENT_PAL_TAG_BRENDAN,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_1,
    OBJ_EVENT_PAL_TAG_NPC_2,
    OBJ_EVENT_PAL_TAG_NPC_3,
    OBJ_EVENT_PAL_TAG_NPC_4,
    OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

static const u16 sObjectPaletteTags3[] = {
    OBJ_EVENT_PAL_TAG_BRENDAN,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_1,
    OBJ_EVENT_PAL_TAG_NPC_2,
    OBJ_EVENT_PAL_TAG_NPC_3,
    OBJ_EVENT_PAL_TAG_NPC_4,
    OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

static const u16 *const sObjectPaletteTagSets[] = {
    sObjectPaletteTags0,
    sObjectPaletteTags1,
    sObjectPaletteTags2,
    sObjectPaletteTags3,
};

#include "data/object_events/berry_tree_graphics_tables.h"
#include "data/field_effects/field_effect_objects.h"

const s16 gMovementDelaysMedium[] = {32, 64,  96, 128};
const s16 gMovementDelaysLong[] =   {32, 64, 128, 192};
const s16 gMovementDelaysShort[] =  {32, 48,  64,  80};

#include "data/object_events/movement_type_func_tables.h"

const u8 gFaceDirectionAnimNums[] = {
    [DIR_NONE] = 0,
    [DIR_SOUTH] = 0,
    [DIR_NORTH] = 1,
    [DIR_WEST] = 2,
    [DIR_EAST] = 3,
    [DIR_SOUTHWEST] = 0,
    [DIR_SOUTHEAST] = 0,
    [DIR_NORTHWEST] = 1,
    [DIR_NORTHEAST] = 1,
};
const u8 gMoveDirectionAnimNums[] = {
    [DIR_NONE] = 4,
    [DIR_SOUTH] = 4,
    [DIR_NORTH] = 5,
    [DIR_WEST] = 6,
    [DIR_EAST] = 7,
    [DIR_SOUTHWEST] = 4,
    [DIR_SOUTHEAST] = 4,
    [DIR_NORTHWEST] = 5,
    [DIR_NORTHEAST] = 5,
};
const u8 gMoveDirectionFastAnimNums[] = {
    [DIR_NONE] = 8,
    [DIR_SOUTH] = 8,
    [DIR_NORTH] = 9,
    [DIR_WEST] = 10,
    [DIR_EAST] = 11,
    [DIR_SOUTHWEST] = 8,
    [DIR_SOUTHEAST] = 8,
    [DIR_NORTHWEST] = 9,
    [DIR_NORTHEAST] = 9,
};
const u8 gMoveDirectionFasterAnimNums[] = {
    [DIR_NONE] = 12,
    [DIR_SOUTH] = 12,
    [DIR_NORTH] = 13,
    [DIR_WEST] = 14,
    [DIR_EAST] = 15,
    [DIR_SOUTHWEST] = 12,
    [DIR_SOUTHEAST] = 12,
    [DIR_NORTHWEST] = 13,
    [DIR_NORTHEAST] = 13,
};
const u8 gMoveDirectionFastestAnimNums[] = {
    [DIR_NONE] = 16,
    [DIR_SOUTH] = 16,
    [DIR_NORTH] = 17,
    [DIR_WEST] = 18,
    [DIR_EAST] = 19,
    [DIR_SOUTHWEST] = 16,
    [DIR_SOUTHEAST] = 16,
    [DIR_NORTHWEST] = 17,
    [DIR_NORTHEAST] = 17,
};
const u8 gJumpSpecialDirectionAnimNums[] = { // used for jumping onto surf mon
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};
const u8 gAcroWheelieDirectionAnimNums[] = {
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};
const u8 gUnrefAnimNums_08375633[] = {
    [DIR_NONE] = 24,
    [DIR_SOUTH] = 24,
    [DIR_NORTH] = 25,
    [DIR_WEST] = 26,
    [DIR_EAST] = 27,
    [DIR_SOUTHWEST] = 24,
    [DIR_SOUTHEAST] = 24,
    [DIR_NORTHWEST] = 25,
    [DIR_NORTHEAST] = 25,
};
const u8 gAcroEndWheelieDirectionAnimNums[] = {
    [DIR_NONE] = 28,
    [DIR_SOUTH] = 28,
    [DIR_NORTH] = 29,
    [DIR_WEST] = 30,
    [DIR_EAST] = 31,
    [DIR_SOUTHWEST] = 28,
    [DIR_SOUTHEAST] = 28,
    [DIR_NORTHWEST] = 29,
    [DIR_NORTHEAST] = 29,
};
const u8 gAcroUnusedActionDirectionAnimNums[] = {
    [DIR_NONE] = 32,
    [DIR_SOUTH] = 32,
    [DIR_NORTH] = 33,
    [DIR_WEST] = 34,
    [DIR_EAST] = 35,
    [DIR_SOUTHWEST] = 32,
    [DIR_SOUTHEAST] = 32,
    [DIR_NORTHWEST] = 33,
    [DIR_NORTHEAST] = 33,
};
const u8 gAcroWheeliePedalDirectionAnimNums[] = {
    [DIR_NONE] = 36,
    [DIR_SOUTH] = 36,
    [DIR_NORTH] = 37,
    [DIR_WEST] = 38,
    [DIR_EAST] = 39,
    [DIR_SOUTHWEST] = 36,
    [DIR_SOUTHEAST] = 36,
    [DIR_NORTHWEST] = 37,
    [DIR_NORTHEAST] = 37,
};
const u8 gFishingDirectionAnimNums[] = {
    [DIR_NONE] = 0,
    [DIR_SOUTH] = 0,
    [DIR_NORTH] = 1,
    [DIR_WEST] = 2,
    [DIR_EAST] = 3,
    [DIR_SOUTHWEST] = 0,
    [DIR_SOUTHEAST] = 0,
    [DIR_NORTHWEST] = 1,
    [DIR_NORTHEAST] = 1,
};
const u8 gFishingNoCatchDirectionAnimNums[] = {
    [DIR_NONE] = 4,
    [DIR_SOUTH] = 4,
    [DIR_NORTH] = 5,
    [DIR_WEST] = 6,
    [DIR_EAST] = 7,
    [DIR_SOUTHWEST] = 4,
    [DIR_SOUTHEAST] = 4,
    [DIR_NORTHWEST] = 5,
    [DIR_NORTHEAST] = 5,
};
const u8 gFishingBiteDirectionAnimNums[] = {
    [DIR_NONE] = 8,
    [DIR_SOUTH] = 8,
    [DIR_NORTH] = 9,
    [DIR_WEST] = 10,
    [DIR_EAST] = 11,
    [DIR_SOUTHWEST] = 8,
    [DIR_SOUTHEAST] = 8,
    [DIR_NORTHWEST] = 9,
    [DIR_NORTHEAST] = 9,
};
const u8 gRunningDirectionAnimNums[] = {
    [DIR_NONE] = 20,
    [DIR_SOUTH] = 20,
    [DIR_NORTH] = 21,
    [DIR_WEST] = 22,
    [DIR_EAST] = 23,
    [DIR_SOUTHWEST] = 20,
    [DIR_SOUTHEAST] = 20,
    [DIR_NORTHWEST] = 21,
    [DIR_NORTHEAST] = 21,
};

const u8 gTrainerFacingDirectionMovementTypes[] = {
    [DIR_NONE] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_SOUTH] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_NORTH] = MOVEMENT_TYPE_FACE_UP,
    [DIR_WEST] = MOVEMENT_TYPE_FACE_LEFT,
    [DIR_EAST] = MOVEMENT_TYPE_FACE_RIGHT,
    [DIR_SOUTHWEST] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_SOUTHEAST] = MOVEMENT_TYPE_FACE_DOWN,
    [DIR_NORTHWEST] = MOVEMENT_TYPE_FACE_UP,
    [DIR_NORTHEAST] = MOVEMENT_TYPE_FACE_UP,
};

bool8 (*const gOppositeDirectionBlockedMetatileFuncs[])(u8) = {
    MetatileBehavior_IsSouthBlocked,
    MetatileBehavior_IsNorthBlocked,
    MetatileBehavior_IsWestBlocked,
    MetatileBehavior_IsEastBlocked
};

bool8 (*const gDirectionBlockedMetatileFuncs[])(u8) = {
    MetatileBehavior_IsNorthBlocked,
    MetatileBehavior_IsSouthBlocked,
    MetatileBehavior_IsEastBlocked,
    MetatileBehavior_IsWestBlocked
};

static const struct Coords16 sDirectionToVectors[] = {
    { 0,  0},
    { 0,  1},
    { 0, -1},
    {-1,  0},
    { 1,  0},
    {-1,  1},
    { 1,  1},
    {-1, -1},
    { 1, -1}
};

const u8 gFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_UP,
    MOVEMENT_ACTION_FACE_LEFT,
    MOVEMENT_ACTION_FACE_RIGHT,
};
const u8 gWalkSlowMovementActions[] = {
    MOVEMENT_ACTION_WALK_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_SLOW_UP,
    MOVEMENT_ACTION_WALK_SLOW_LEFT,
    MOVEMENT_ACTION_WALK_SLOW_RIGHT,
};
const u8 gWalkNormalMovementActions[] = {
    MOVEMENT_ACTION_WALK_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_NORMAL_UP,
    MOVEMENT_ACTION_WALK_NORMAL_LEFT,
    MOVEMENT_ACTION_WALK_NORMAL_RIGHT,
};
const u8 gWalkFastMovementActions[] = {
    MOVEMENT_ACTION_WALK_FAST_DOWN,
    MOVEMENT_ACTION_WALK_FAST_DOWN,
    MOVEMENT_ACTION_WALK_FAST_UP,
    MOVEMENT_ACTION_WALK_FAST_LEFT,
    MOVEMENT_ACTION_WALK_FAST_RIGHT,
};
const u8 gRideWaterCurrentMovementActions[] = {
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_UP,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_LEFT,
    MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT,
};
const u8 gWalkFastestMovementActions[] = {
    MOVEMENT_ACTION_WALK_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_FASTEST_UP,
    MOVEMENT_ACTION_WALK_FASTEST_LEFT,
    MOVEMENT_ACTION_WALK_FASTEST_RIGHT,
};
const u8 gSlideMovementActions[] = {
    MOVEMENT_ACTION_SLIDE_DOWN,
    MOVEMENT_ACTION_SLIDE_DOWN,
    MOVEMENT_ACTION_SLIDE_UP,
    MOVEMENT_ACTION_SLIDE_LEFT,
    MOVEMENT_ACTION_SLIDE_RIGHT,
};
const u8 gPlayerRunMovementActions[] = {
    MOVEMENT_ACTION_PLAYER_RUN_DOWN,
    MOVEMENT_ACTION_PLAYER_RUN_DOWN,
    MOVEMENT_ACTION_PLAYER_RUN_UP,
    MOVEMENT_ACTION_PLAYER_RUN_LEFT,
    MOVEMENT_ACTION_PLAYER_RUN_RIGHT,
};
const u8 gJump2MovementActions[] = {
    MOVEMENT_ACTION_JUMP_2_DOWN,
    MOVEMENT_ACTION_JUMP_2_DOWN,
    MOVEMENT_ACTION_JUMP_2_UP,
    MOVEMENT_ACTION_JUMP_2_LEFT,
    MOVEMENT_ACTION_JUMP_2_RIGHT,
};
const u8 gJumpInPlaceMovementActions[] = {
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP,
    MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT,
    MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT,
};
const u8 gJumpInPlaceTurnAroundMovementActions[] = {
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN,
    MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP,
    MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT,
    MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT,
};
const u8 gJumpMovementActions[] = {
    MOVEMENT_ACTION_JUMP_DOWN,
    MOVEMENT_ACTION_JUMP_DOWN,
    MOVEMENT_ACTION_JUMP_UP,
    MOVEMENT_ACTION_JUMP_LEFT,
    MOVEMENT_ACTION_JUMP_RIGHT,
};
const u8 gJumpSpecialMovementActions[] = {
    MOVEMENT_ACTION_JUMP_SPECIAL_DOWN,
    MOVEMENT_ACTION_JUMP_SPECIAL_DOWN,
    MOVEMENT_ACTION_JUMP_SPECIAL_UP,
    MOVEMENT_ACTION_JUMP_SPECIAL_LEFT,
    MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT,
};
const u8 gWalkInPlaceSlowMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT,
};
const u8 gWalkInPlaceNormalMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT,
};
const u8 gWalkInPlaceFastMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT,
};
const u8 gWalkInPlaceFastestMovementActions[] = {
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_DOWN,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_UP,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_LEFT,
    MOVEMENT_ACTION_WALK_IN_PLACE_FASTEST_RIGHT,
};
const u8 gAcroWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT,
};
const u8 gAcroPopWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT,
};
const u8 gAcroEndWheelieFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT,
};
const u8 gAcroWheelieHopFaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT,
};
const u8 gAcroWheelieHopDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT,
};
const u8 gAcroWheelieJumpDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT,
};
const u8 gAcroWheelieInPlaceDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT,
};
const u8 gAcroPopWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT,
};
const u8 gAcroWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT,
};
const u8 gAcroEndWheelieMoveDirectionMovementActions[] = {
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_UP,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_LEFT,
    MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT,
};

const u8 gOppositeDirections[] = {
    DIR_NORTH,
    DIR_SOUTH,
    DIR_EAST,
    DIR_WEST,
    DIR_NORTHEAST,
    DIR_NORTHWEST,
    DIR_SOUTHEAST,
    DIR_SOUTHWEST,
};

const u8 gUnknown_0850DC2F[][4] = {
    {2, 1, 4, 3},
    {1, 2, 3, 4},
    {3, 4, 2, 1},
    {4, 3, 1, 2}
};

const u8 gUnknown_0850DC3F[][4] = {
    {2, 1, 4, 3},
    {1, 2, 3, 4},
    {4, 3, 1, 2},
    {3, 4, 2, 1}
};

#include "data/object_events/movement_action_func_tables.h"

// Code

static void ClearObjectEvent(struct ObjectEvent *objectEvent)
{
    *objectEvent = (struct ObjectEvent){};
    objectEvent->localId = 0xFF;
    objectEvent->mapNum = 0xFF;
    objectEvent->mapGroup = 0xFF;
    objectEvent->movementActionId = 0xFF;
}

static void ClearAllObjectEvents(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        ClearObjectEvent(&gObjectEvents[i]);
}

void ResetObjectEvents(void)
{
    ClearLinkPlayerObjectEvents();
    ClearAllObjectEvents();
    ClearPlayerAvatarInfo();
    CreateReflectionEffectSprites();
}

static void CreateReflectionEffectSprites(void)
{
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_REFLECTION_DISTORTION], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 0);
    gSprites[spriteId].invisible = TRUE;

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_REFLECTION_DISTORTION], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].invisible = TRUE;
}

u8 GetFirstInactiveObjectEventId(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            break;
    }

    return i;
}

u8 GetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId)
{
    if (localId < OBJ_EVENT_ID_PLAYER)
    {
        return GetObjectEventIdByLocalIdAndMapInternal(localId, mapNum, mapGroupId);
    }
    return GetObjectEventIdByLocalId(localId);
}

bool8 TryGetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId, u8 *objectEventId)
{
    *objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroupId);
    if (*objectEventId == OBJECT_EVENTS_COUNT)
        return TRUE;
    else
        return FALSE;
}

u8 GetObjectEventIdByXY(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
            break;
    }

    return i;
}

static u8 GetObjectEventIdByLocalIdAndMapInternal(u8 localId, u8 mapNum, u8 mapGroupId)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroupId)
            return i;
    }

    return OBJECT_EVENTS_COUNT;
}

static u8 GetObjectEventIdByLocalId(u8 localId)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId)
            return i;
    }

    return OBJECT_EVENTS_COUNT;
}

static u8 InitObjectEventStateFromTemplate(struct ObjectEventTemplate *template, u8 mapNum, u8 mapGroup)
{
    struct ObjectEvent *objectEvent;
    u8 objectEventId;
    s16 x;
    s16 y;

    if (GetAvailableObjectEventId(template->localId, mapNum, mapGroup, &objectEventId))
        return OBJECT_EVENTS_COUNT;
    objectEvent = &gObjectEvents[objectEventId];
    ClearObjectEvent(objectEvent);
    x = template->x + 7;
    y = template->y + 7;
    objectEvent->active = TRUE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    objectEvent->graphicsId = template->graphicsId;
    objectEvent->movementType = template->movementType;
    objectEvent->localId = template->localId;
    objectEvent->mapNum = mapNum;
    objectEvent->mapGroup = mapGroup;
    objectEvent->initialCoords.x = x;
    objectEvent->initialCoords.y = y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
    objectEvent->previousCoords.x = x;
    objectEvent->previousCoords.y = y;
    objectEvent->currentElevation = template->elevation;
    objectEvent->previousElevation = template->elevation;
    objectEvent->rangeX = template->movementRangeX;
    objectEvent->rangeY = template->movementRangeY;
    objectEvent->trainerType = template->trainerType;
    objectEvent->mapNum = mapNum;
    objectEvent->trainerRange_berryTreeId = template->trainerRange_berryTreeId;
    objectEvent->previousMovementDirection = gInitialMovementTypeFacingDirections[template->movementType];
    SetObjectEventDirection(objectEvent, objectEvent->previousMovementDirection);
    SetObjectEventDynamicGraphicsId(objectEvent);
    if (gRangedMovementTypes[objectEvent->movementType])
    {
        if (objectEvent->rangeX == 0)
        {
            objectEvent->rangeX++;
        }
        if (objectEvent->rangeY == 0)
        {
            objectEvent->rangeY++;
        }
    }
    return objectEventId;
}

u8 Unref_TryInitLocalObjectEvent(u8 localId)
{
    u8 i;
    u8 objectEventCount;
    struct ObjectEventTemplate *template;

    if (gMapHeader.events != NULL)
    {
        if (InBattlePyramid())
        {
            objectEventCount = GetNumBattlePyramidObjectEvents();
        }
        else if (InTrainerHill())
        {
            objectEventCount = 2;
        }
        else
        {
            objectEventCount = gMapHeader.events->objectEventCount;
        }
        for (i = 0; i < objectEventCount; i++)
        {
            template = &gSaveBlock1Ptr->objectEventTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
            {
                return InitObjectEventStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            }
        }
    }
    return OBJECT_EVENTS_COUNT;
}

static bool8 GetAvailableObjectEventId(u16 localId, u8 mapNum, u8 mapGroup, u8 *objectEventId)
// Looks for an empty slot.
// Returns FALSE and the location of the available slot
// in *objectEventId.
// If no slots are available, or if the object is already
// loaded, returns TRUE.
{
    u8 i = 0;

    for (i = 0; i < OBJECT_EVENTS_COUNT && gObjectEvents[i].active; i++)
    {
        if (gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= OBJECT_EVENTS_COUNT)
        return TRUE;
    *objectEventId = i;
    for (; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroup)
            return TRUE;
    }
    return FALSE;
}

static void RemoveObjectEvent(struct ObjectEvent *objectEvent)
{
    objectEvent->active = FALSE;
    RemoveObjectEventInternal(objectEvent);
}

void RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        FlagSet(GetObjectEventFlagIdByObjectEventId(objectEventId));
        RemoveObjectEvent(&gObjectEvents[objectEventId]);
    }
}

static void RemoveObjectEventInternal(struct ObjectEvent *objectEvent)
{
    struct SpriteFrameImage image;
    image.size = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->size;
    gSprites[objectEvent->spriteId].images = &image;
    DestroySprite(&gSprites[objectEvent->spriteId]);
}

void RemoveAllObjectEventsExceptPlayer(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (i != gPlayerAvatar.objectEventId)
            RemoveObjectEvent(&gObjectEvents[i]);
    }
}

static u8 TrySetupObjectEventSprite(struct ObjectEventTemplate *objectEventTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 spriteId;
    u8 paletteSlot;
    u8 objectEventId;
    struct Sprite *sprite;
    struct ObjectEvent *objectEvent;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    objectEventId = InitObjectEventStateFromTemplate(objectEventTemplate, mapNum, mapGroup);
    if (objectEventId == OBJECT_EVENTS_COUNT)
        return OBJECT_EVENTS_COUNT;

    objectEvent = &gObjectEvents[objectEventId];
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag, 0);
    }
    else if (paletteSlot == 10)
    {
        LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, 10);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag, paletteSlot);
    }

    if (objectEvent->movementType == MOVEMENT_TYPE_INVISIBLE)
        objectEvent->invisible = TRUE;

    *(u16 *)&spriteTemplate->paletteTag = 0xFFFF;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gObjectEvents[objectEventId].active = FALSE;
        return OBJECT_EVENTS_COUNT;
    }

    sprite = &gSprites[spriteId];
    sub_8092FF0(objectEvent->currentCoords.x + cameraX, objectEvent->currentCoords.y + cameraY, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data[0] = objectEventId;
    objectEvent->spriteId = spriteId;
    objectEvent->inanimate = graphicsInfo->inanimate;
    if (!objectEvent->inanimate)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(objectEvent->facingDirection));

    SetObjectSubpriorityByZCoord(objectEvent->previousElevation, sprite, 1);
    UpdateObjectEventVisibility(objectEvent, sprite);
    return objectEventId;
}

static u8 TrySpawnObjectEventTemplate(struct ObjectEventTemplate *objectEventTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 objectEventId;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    const struct SubspriteTable *subspriteTables = NULL;

    graphicsInfo = GetObjectEventGraphicsInfo(objectEventTemplate->graphicsId);
    MakeObjectTemplateFromObjectEventTemplate(objectEventTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    objectEventId = TrySetupObjectEventSprite(objectEventTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (objectEventId == OBJECT_EVENTS_COUNT)
        return OBJECT_EVENTS_COUNT;

    gSprites[gObjectEvents[objectEventId].spriteId].images = graphicsInfo->images;
    if (subspriteTables)
        SetSubspriteTables(&gSprites[gObjectEvents[objectEventId].spriteId], subspriteTables);

    return objectEventId;
}

u8 SpawnSpecialObjectEvent(struct ObjectEventTemplate *objectEventTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetObjectEventMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnObjectEventTemplate(objectEventTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}

u8 SpawnSpecialObjectEventParameterized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 z)
{
    struct ObjectEventTemplate objectEventTemplate;

    x -= 7;
    y -= 7;
    objectEventTemplate.localId = localId;
    objectEventTemplate.graphicsId = graphicsId;
    objectEventTemplate.inConnection = 0;
    objectEventTemplate.x = x;
    objectEventTemplate.y = y;
    objectEventTemplate.elevation = z;
    objectEventTemplate.movementType = movementBehavior;
    objectEventTemplate.movementRangeX = 0;
    objectEventTemplate.movementRangeY = 0;
    objectEventTemplate.trainerType = TRAINER_TYPE_NONE;
    objectEventTemplate.trainerRange_berryTreeId = 0;
    return SpawnSpecialObjectEvent(&objectEventTemplate);
}

u8 TrySpawnObjectEvent(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct ObjectEventTemplate *objectEventTemplate;
    s16 cameraX, cameraY;

    objectEventTemplate = GetObjectEventTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (!objectEventTemplate)
        return OBJECT_EVENTS_COUNT;

    GetObjectEventMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnObjectEventTemplate(objectEventTemplate, mapNum, mapGroup, cameraX, cameraY);
}

static void MakeObjectTemplateFromObjectEventGraphicsInfo(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);

    spriteTemplate->tileTag = graphicsInfo->tileTag;
    spriteTemplate->paletteTag = graphicsInfo->paletteTag;
    spriteTemplate->oam = graphicsInfo->oam;
    spriteTemplate->anims = graphicsInfo->anims;
    spriteTemplate->images = graphicsInfo->images;
    spriteTemplate->affineAnims = graphicsInfo->affineAnims;
    spriteTemplate->callback = callback;
    *subspriteTables = graphicsInfo->subspriteTables;
}

static void MakeObjectTemplateFromObjectEventGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromObjectEventGraphicsInfo(graphicsId, sMovementTypeCallbacks[callbackIndex], spriteTemplate, subspriteTables);
}

static void MakeObjectTemplateFromObjectEventTemplate(struct ObjectEventTemplate *objectEventTemplate, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromObjectEventGraphicsInfoWithCallbackIndex(objectEventTemplate->graphicsId, objectEventTemplate->movementType, spriteTemplate, subspriteTables);
}

u8 AddPseudoObjectEvent(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate *spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct Sprite *sprite;
    u8 spriteId;

    spriteTemplate = malloc(sizeof(struct SpriteTemplate));
    MakeObjectTemplateFromObjectEventGraphicsInfo(graphicsId, callback, spriteTemplate, &subspriteTables);
    if (spriteTemplate->paletteTag != 0xFFFF)
    {
        LoadObjectEventPalette(spriteTemplate->paletteTag);
    }
    spriteId = CreateSprite(spriteTemplate, x, y, subpriority);
    free(spriteTemplate);

    if (spriteId != MAX_SPRITES && subspriteTables != NULL)
    {
        sprite = &gSprites[spriteId];
        SetSubspriteTables(sprite, subspriteTables);
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    }
    return spriteId;
}

// Used to create sprite object events instead of a full object event
// Used when resources are limiting, e.g. for the audience in contests or group members in Union Room
u8 CreateObjectSprite(u8 graphicsId, u8 a1, s16 x, s16 y, u8 z, u8 direction)
{
    u8 spriteId;
    struct Sprite *sprite;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    MakeObjectTemplateFromObjectEventGraphicsInfo(graphicsId, UpdateObjectEventSprite, &spriteTemplate, &subspriteTables);
    *(u16 *)&spriteTemplate.paletteTag = 0xFFFF;
    x += 7;
    y += 7;
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 16);
    spriteId = CreateSpriteAtEnd(&spriteTemplate, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.y += sprite->centerToCornerVecY;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        if (sprite->oam.paletteNum >= 16)
        {
            sprite->oam.paletteNum -= 16;
        }
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = a1;
        sprite->data[1] = z;
        if (graphicsInfo->paletteSlot == 10)
        {
            LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
        }
        else if (graphicsInfo->paletteSlot >= 16)
        {
            sub_808EAB0(graphicsInfo->paletteTag, graphicsInfo->paletteSlot | 0xf0);
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
            sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        }
        InitObjectPriorityByZCoord(sprite, z);
        SetObjectSubpriorityByZCoord(z, sprite, 1);
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(direction));
    }
    return spriteId;
}

void TrySpawnObjectEvents(s16 cameraX, s16 cameraY)
{
    u8 i;
    u8 objectCount;

    if (gMapHeader.events != NULL)
    {
        s16 left = gSaveBlock1Ptr->pos.x - 2;
        s16 right = gSaveBlock1Ptr->pos.x + 17;
        s16 top = gSaveBlock1Ptr->pos.y;
        s16 bottom = gSaveBlock1Ptr->pos.y + 16;

        if (InBattlePyramid())
        {
            objectCount = GetNumBattlePyramidObjectEvents();
        }
        else if (InTrainerHill())
        {
            objectCount = 2;
        }
        else
        {
            objectCount = gMapHeader.events->objectEventCount;
        }

        for (i = 0; i < objectCount; i++)
        {
            struct ObjectEventTemplate *template = &gSaveBlock1Ptr->objectEventTemplates[i];
            s16 npcX = template->x + 7;
            s16 npcY = template->y + 7;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                TrySpawnObjectEventTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
}

void RemoveObjectEventsOutsideView(void)
{
    u8 i, j;
    bool8 isActiveLinkPlayer;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerObjectEvents); j++)
        {
            if (gLinkPlayerObjectEvents[j].active && i == gLinkPlayerObjectEvents[j].objEventId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            struct ObjectEvent *objectEvent = &gObjectEvents[i];

            if (objectEvent->active && !objectEvent->isPlayer)
                RemoveObjectEventIfOutsideView(objectEvent);
        }
    }
}

static void RemoveObjectEventIfOutsideView(struct ObjectEvent *objectEvent)
{
    s16 left =   gSaveBlock1Ptr->pos.x - 2;
    s16 right =  gSaveBlock1Ptr->pos.x + 17;
    s16 top =    gSaveBlock1Ptr->pos.y;
    s16 bottom = gSaveBlock1Ptr->pos.y + 16;

    if (objectEvent->currentCoords.x >= left && objectEvent->currentCoords.x <= right
     && objectEvent->currentCoords.y >= top && objectEvent->currentCoords.y <= bottom)
        return;
    if (objectEvent->initialCoords.x >= left && objectEvent->initialCoords.x <= right
     && objectEvent->initialCoords.y >= top && objectEvent->initialCoords.y <= bottom)
        return;
    RemoveObjectEvent(objectEvent);
}

void sub_808E16C(s16 x, s16 y)
{
    u8 i;

    ClearPlayerAvatarInfo();
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active)
        {
            sub_808E1B8(i, x, y);
        }
    }
    CreateReflectionEffectSprites();
}

static void sub_808E1B8(u8 objectEventId, s16 x, s16 y)
{
    u8 spriteId;
    u8 paletteSlot;
    struct Sprite *sprite;
    struct ObjectEvent *objectEvent;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct SubspriteTable *subspriteTables;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

#define i spriteId
    for (i = 0; i < ARRAY_COUNT(gLinkPlayerObjectEvents); i++)
    {
        if (gLinkPlayerObjectEvents[i].active && objectEventId == gLinkPlayerObjectEvents[i].objEventId)
        {
            return;
        }
    }
#undef i

    objectEvent = &gObjectEvents[objectEventId];
    subspriteTables = NULL;
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    spriteFrameImage.size = graphicsInfo->size;
    MakeObjectTemplateFromObjectEventGraphicsInfoWithCallbackIndex(objectEvent->graphicsId, objectEvent->movementType, &spriteTemplate, &subspriteTables);
    spriteTemplate.images = &spriteFrameImage;
    *(u16 *)&spriteTemplate.paletteTag = 0xFFFF;
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag, paletteSlot);
    }
    *(u16 *)&spriteTemplate.paletteTag = 0xFFFF;
    spriteId = CreateSprite(&spriteTemplate, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sub_8092FF0(x + objectEvent->currentCoords.x, y + objectEvent->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->pos1.x += 8;
        sprite->pos1.y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (objectEvent->movementType == MOVEMENT_TYPE_PLAYER)
        {
            SetPlayerAvatarObjectEventIdAndObjectId(objectEventId, spriteId);
            objectEvent->warpArrowSpriteId = CreateWarpArrowSprite();
        }
        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
        }
        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = objectEventId;
        objectEvent->spriteId = spriteId;
        if (!objectEvent->inanimate && objectEvent->movementType != MOVEMENT_TYPE_PLAYER)
        {
            StartSpriteAnim(sprite, GetFaceDirectionAnimNum(objectEvent->facingDirection));
        }
        sub_808E38C(objectEvent);
        SetObjectSubpriorityByZCoord(objectEvent->previousElevation, sprite, 1);
    }
}

static void sub_808E38C(struct ObjectEvent *objectEvent)
{
    objectEvent->singleMovementActive = FALSE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    objectEvent->hasShadow = FALSE;
    objectEvent->hasReflection = FALSE;
    objectEvent->inShortGrass = FALSE;
    objectEvent->inShallowFlowingWater = FALSE;
    objectEvent->inSandPile = FALSE;
    objectEvent->inHotSprings = FALSE;
    ObjectEventClearHeldMovement(objectEvent);
}

static void SetPlayerAvatarObjectEventIdAndObjectId(u8 objectEventId, u8 spriteId)
{
    gPlayerAvatar.objectEventId = objectEventId;
    gPlayerAvatar.spriteId = spriteId;
    gPlayerAvatar.gender = GetPlayerAvatarGenderByGraphicsId(gObjectEvents[objectEventId].graphicsId);
    SetPlayerAvatarExtraStateTransition(gObjectEvents[objectEventId].graphicsId, PLAYER_AVATAR_FLAG_5);
}

void ObjectEventSetGraphicsId(struct ObjectEvent *objectEvent, u8 graphicsId)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 paletteSlot;

    graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    sprite = &gSprites[objectEvent->spriteId];
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == 0)
    {
        PatchObjectPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == 10)
    {
        LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        sub_808EAB0(graphicsInfo->paletteTag, paletteSlot);
    }
    sprite->oam.shape = graphicsInfo->oam->shape;
    sprite->oam.size = graphicsInfo->oam->size;
    sprite->images = graphicsInfo->images;
    sprite->anims = graphicsInfo->anims;
    sprite->subspriteTables = graphicsInfo->subspriteTables;
    sprite->oam.paletteNum = paletteSlot;
    objectEvent->inanimate = graphicsInfo->inanimate;
    objectEvent->graphicsId = graphicsId;
    SetSpritePosToMapCoords(objectEvent->currentCoords.x, objectEvent->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    if (objectEvent->trackedByCamera)
    {
        CameraObjectReset1();
    }
}

void ObjectEventSetGraphicsIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 graphicsId)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], graphicsId);
    }
}

void ObjectEventTurn(struct ObjectEvent *objectEvent, u8 direction)
{
    SetObjectEventDirection(objectEvent, direction);
    if (!objectEvent->inanimate)
    {
        StartSpriteAnim(&gSprites[objectEvent->spriteId], GetFaceDirectionAnimNum(objectEvent->facingDirection));
        SeekSpriteAnim(&gSprites[objectEvent->spriteId], 0);
    }
}

void ObjectEventTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        ObjectEventTurn(&gObjectEvents[objectEventId], direction);
    }
}

void PlayerObjectTurn(struct PlayerAvatar *playerAvatar, u8 direction)
{
    ObjectEventTurn(&gObjectEvents[playerAvatar->objectEventId], direction);
}

static void get_berry_tree_graphics(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 berryStage;
    u8 berryId;

    objectEvent->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(objectEvent->trainerRange_berryTreeId);
    if (berryStage != 0)
    {
        objectEvent->invisible = FALSE;
        sprite->invisible = FALSE;
        berryId = GetBerryTypeByBerryTreeId(objectEvent->trainerRange_berryTreeId) - 1;
        berryStage--;
        if (berryId > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berryId = 0;

        ObjectEventSetGraphicsId(objectEvent, gBerryTreeObjectEventGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = gBerryTreePaletteSlotTablePointers[berryId][berryStage];
        StartSpriteAnim(sprite, berryStage);
    }
}

const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8 graphicsId)
{
    u8 bard;

    if (graphicsId >= OBJ_EVENT_GFX_VARS)
    {
        graphicsId = VarGetObjectEventGraphicsId(graphicsId - OBJ_EVENT_GFX_VARS);
    }
    if (graphicsId == OBJ_EVENT_GFX_BARD)
    {
        bard = GetCurrentMauvilleOldMan();
        return gMauvilleOldManGraphicsInfoPointers[bard];
    }

    if (graphicsId >= NUM_OBJ_EVENT_GFX)
    {
        graphicsId = OBJ_EVENT_GFX_NINJA_BOY;
    }
    
    return gObjectEventGraphicsInfoPointers[graphicsId];
}

static void SetObjectEventDynamicGraphicsId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->graphicsId >= OBJ_EVENT_GFX_VARS)
    {
        objectEvent->graphicsId = VarGetObjectEventGraphicsId(objectEvent->graphicsId - OBJ_EVENT_GFX_VARS);
    }
}

void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, u8 state)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        gObjectEvents[objectEventId].invisible = state;
    }
}

void ObjectEventGetLocalIdAndMap(struct ObjectEvent *objectEvent, void *localId, void *mapNum, void *mapGroup)
{
    *(u8*)(localId) = objectEvent->localId;
    *(u8*)(mapNum) = objectEvent->mapNum;
    *(u8*)(mapGroup) = objectEvent->mapGroup;
}

void sub_808E75C(s16 x, s16 y)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    objectEventId = GetObjectEventIdByXY(x, y);
    if (objectEventId != OBJECT_EVENTS_COUNT)
    {
        objectEvent = &gObjectEvents[objectEventId];
        objectEvent->triggerGroundEffectsOnMove = TRUE;
    }
}

void sub_808E78C(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        objectEvent = &gObjectEvents[objectEventId];
        sprite = &gSprites[objectEvent->spriteId];
        objectEvent->fixedPriority = TRUE;
        sprite->subpriority = subpriority;
    }
}

void sub_808E7E4(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        objectEvent = &gObjectEvents[objectEventId];
        objectEvent->fixedPriority = FALSE;
        objectEvent->triggerGroundEffectsOnMove = TRUE;
    }
}

void SetObjectEventSpritePosByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 objectEventId;
    struct Sprite *sprite;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        sprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        sprite->pos2.x = x;
        sprite->pos2.y = y;
    }
}

void FreeAndReserveObjectSpritePalettes(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12;
}

static void LoadObjectEventPalette(u16 paletteTag)
{
    u16 i = FindObjectEventPaletteIndexByTag(paletteTag);

    if (i != OBJ_EVENT_PAL_TAG_NONE) // always true
    {
        sub_808E8F4(&sObjectEventSpritePalettes[i]);
    }
}

void Unused_LoadObjectEventPaletteSet(u16 *paletteTags)
{
    u8 i;

    for (i = 0; paletteTags[i] != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        LoadObjectEventPalette(paletteTags[i]);
    }
}

// NOTE: Does not use LoadSpritePaletteDayNight because of naming screen
static u8 sub_808E8F4(const struct SpritePalette *spritePalette)
{
    if (IndexOfSpritePaletteTag(spritePalette->tag) != 0xFF)
    {
        return 0xFF;
    }
    return LoadSpritePalette(spritePalette);
}

void PatchObjectPalette(u16 paletteTag, u8 paletteSlot)
{
    u8 paletteIndex = FindObjectEventPaletteIndexByTag(paletteTag);

    //LoadPalette(sObjectEventSpritePalettes[paletteIndex].data, 16 * paletteSlot + 0x100, 0x20);
    LoadPaletteDayNight(sObjectEventSpritePalettes[paletteIndex].data, 16 * paletteSlot + 0x100, 0x20);
}

void PatchObjectPaletteRange(const u16 *paletteTags, u8 minSlot, u8 maxSlot)
{
    while (minSlot < maxSlot)
    {
        PatchObjectPalette(*paletteTags, minSlot);
        paletteTags++;
        minSlot++;
    }
}

static u8 FindObjectEventPaletteIndexByTag(u16 tag)
{
    u8 i;

    for (i = 0; sObjectEventSpritePalettes[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sObjectEventSpritePalettes[i].tag == tag)
        {
            return i;
        }
    }
    return 0xFF;
}

void LoadPlayerObjectReflectionPalette(u16 tag, u8 slot)
{
    u8 i;

    PatchObjectPalette(tag, slot);
    for (i = 0; sPlayerReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sPlayerReflectionPaletteSets[i].tag == tag)
        {
            PatchObjectPalette(sPlayerReflectionPaletteSets[i].data[sCurrentReflectionType], gReflectionEffectPaletteMap[slot]);
            return;
        }
    }
}

void LoadSpecialObjectReflectionPalette(u16 tag, u8 slot)
{
    u8 i;

    sCurrentSpecialObjectPaletteTag = tag;
    PatchObjectPalette(tag, slot);
    for (i = 0; sSpecialObjectReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sSpecialObjectReflectionPaletteSets[i].tag == tag)
        {
            PatchObjectPalette(sSpecialObjectReflectionPaletteSets[i].data[sCurrentReflectionType], gReflectionEffectPaletteMap[slot]);
            return;
        }
    }
}

static void sub_808EAB0(u16 tag, u8 slot)
{
    PatchObjectPalette(tag, slot);
}

void unref_sub_808EAC4(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = objectEvent->currentCoords.x;
    objectEvent->previousCoords.y = objectEvent->currentCoords.y;
    objectEvent->currentCoords.x += x;
    objectEvent->currentCoords.y += y;
}

void ShiftObjectEventCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = objectEvent->currentCoords.x;
    objectEvent->previousCoords.y = objectEvent->currentCoords.y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
}

static void SetObjectEventCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = x;
    objectEvent->previousCoords.y = y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
}

void MoveObjectEventToMapCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    sprite = &gSprites[objectEvent->spriteId];
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    SetObjectEventCoords(objectEvent, x, y);
    SetSpritePosToMapCoords(objectEvent->currentCoords.x, objectEvent->currentCoords.y, &sprite->pos1.x, &sprite->pos1.y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->pos1.x += 8;
    sprite->pos1.y += 16 + sprite->centerToCornerVecY;
    sub_808E38C(objectEvent);
    if (objectEvent->trackedByCamera)
        CameraObjectReset1();
}

void TryMoveObjectEventToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        x += 7;
        y += 7;
        MoveObjectEventToMapCoords(&gObjectEvents[objectEventId], x, y);
    }
}

void ShiftStillObjectEventCoords(struct ObjectEvent *objectEvent)
{
    ShiftObjectEventCoords(objectEvent, objectEvent->currentCoords.x, objectEvent->currentCoords.y);
}

void UpdateObjectEventCoordsForCameraUpdate(void)
{
    u8 i;
    s16 dx;
    s16 dy;

    if (gCamera.active)
    {
        dx = gCamera.x;
        dy = gCamera.y;
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            if (gObjectEvents[i].active)
            {
                gObjectEvents[i].initialCoords.x -= dx;
                gObjectEvents[i].initialCoords.y -= dy;
                gObjectEvents[i].currentCoords.x -= dx;
                gObjectEvents[i].currentCoords.y -= dy;
                gObjectEvents[i].previousCoords.x -= dx;
                gObjectEvents[i].previousCoords.y -= dy;
            }
        }
    }
}

u8 GetObjectEventIdByXYZ(u16 x, u16 y, u8 z)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active)
        {
            if (gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y && ObjectEventDoesZCoordMatch(&gObjectEvents[i], z))
            {
                return i;
            }
        }
    }
    return OBJECT_EVENTS_COUNT;
}

static bool8 ObjectEventDoesZCoordMatch(struct ObjectEvent *objectEvent, u8 z)
{
    if (objectEvent->currentElevation != 0 && z != 0 && objectEvent->currentElevation != z)
    {
        return FALSE;
    }
    return TRUE;
}

void UpdateObjectEventsForCameraUpdate(s16 x, s16 y)
{
    UpdateObjectEventCoordsForCameraUpdate();
    TrySpawnObjectEvents(x, y);
    RemoveObjectEventsOutsideView();
}

u8 AddCameraObject(u8 linkedSpriteId)
{
    u8 spriteId = CreateSprite(&gCameraSpriteTemplate, 0, 0, 4);

    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data[0] = linkedSpriteId;
    return spriteId;
}

static void ObjectCB_CameraObject(struct Sprite *sprite)
{
    void (*callbacks[ARRAY_COUNT(gCameraObjectFuncs)])(struct Sprite *);

    memcpy(callbacks, gCameraObjectFuncs, sizeof gCameraObjectFuncs);
    callbacks[sprite->data[1]](sprite);
}

static void CameraObject_0(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
    sprite->invisible = TRUE;
    sprite->data[1] = 1;
    CameraObject_1(sprite);
}

static void CameraObject_1(struct Sprite *sprite)
{
    s16 x = gSprites[sprite->data[0]].pos1.x;
    s16 y = gSprites[sprite->data[0]].pos1.y;

    sprite->data[2] = x - sprite->pos1.x;
    sprite->data[3] = y - sprite->pos1.y;
    sprite->pos1.x = x;
    sprite->pos1.y = y;
}

static void CameraObject_2(struct Sprite *sprite)
{
    sprite->pos1.x = gSprites[sprite->data[0]].pos1.x;
    sprite->pos1.y = gSprites[sprite->data[0]].pos1.y;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
}

static struct Sprite *FindCameraObject(void)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse && gSprites[i].callback == ObjectCB_CameraObject)
        {
            return &gSprites[i];
        }
    }
    return NULL;
}

void CameraObjectReset1(void)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data[1] = 0;
        cameraObject->callback(cameraObject);
    }
}

void CameraObjectSetFollowedObjectId(u8 objectId)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data[0] = objectId;
        CameraObjectReset1();
    }
}

u8 CameraObjectGetFollowedObjectId(void)
{
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject == NULL)
    {
        return MAX_SPRITES;
    }
    return cameraObject->data[0];
}

void CameraObjectReset2(void)
{
    // UB: Possible null dereference
#ifdef UBFIX
    struct Sprite *cameraObject;

    cameraObject = FindCameraObject();
    if (cameraObject != NULL)
    {
        cameraObject->data[1] = 2;
    }
#else
    FindCameraObject()->data[1] = 2;
#endif // UBFIX
}

u8 CopySprite(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].pos1.x = x;
            gSprites[i].pos1.y = y;
            gSprites[i].subpriority = subpriority;
            break;
        }
    }
    return i;
}

u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    s16 i;

    for (i = MAX_SPRITES - 1; i > -1; i--)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].pos1.x = x;
            gSprites[i].pos1.y = y;
            gSprites[i].subpriority = subpriority;
            return i;
        }
    }
    return MAX_SPRITES;
}

void SetObjectEventDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    s8 d2;
    objectEvent->previousMovementDirection = objectEvent->facingDirection;
    if (!objectEvent->facingDirectionLocked)
    {
        d2 = direction;
        objectEvent->facingDirection = d2;
    }
    objectEvent->movementDirection = direction;
}

static const u8 *GetObjectEventScriptPointerByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetObjectEventTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->script;
}

const u8 *GetObjectEventScriptPointerByObjectEventId(u8 objectEventId)
{
    return GetObjectEventScriptPointerByLocalIdAndMap(gObjectEvents[objectEventId].localId, gObjectEvents[objectEventId].mapNum, gObjectEvents[objectEventId].mapGroup);
}

static u16 GetObjectEventFlagIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct ObjectEventTemplate *obj = GetObjectEventTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
#ifdef UBFIX
    // BUG: The function may return NULL, and attempting to read from NULL may freeze the game using modern compilers.
    if (obj == NULL)
        return 0;
#endif // UBFIX
    return obj->flagId;
}

static u16 GetObjectEventFlagIdByObjectEventId(u8 objectEventId)
{
    return GetObjectEventFlagIdByLocalIdAndMap(gObjectEvents[objectEventId].localId, gObjectEvents[objectEventId].mapNum, gObjectEvents[objectEventId].mapGroup);
}

// Unused
static u8 GetObjectTrainerTypeByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        return 0xFF;
    }
    return gObjectEvents[objectEventId].trainerType;
}

// Unused
static u8 GetObjectTrainerTypeByObjectEventId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerType;
}

// Unused
u8 GetObjectEventBerryTreeIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        return 0xFF;
    }
    return gObjectEvents[objectEventId].trainerRange_berryTreeId;
}

u8 GetObjectEventBerryTreeId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerRange_berryTreeId;
}

static struct ObjectEventTemplate *GetObjectEventTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    struct ObjectEventTemplate *templates;
    const struct MapHeader *mapHeader;
    u8 count;

    if (gSaveBlock1Ptr->location.mapNum == mapNum && gSaveBlock1Ptr->location.mapGroup == mapGroup)
    {
        templates = gSaveBlock1Ptr->objectEventTemplates;
        count = gMapHeader.events->objectEventCount;
    }
    else
    {
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);
        templates = mapHeader->events->objectEvents;
        count = mapHeader->events->objectEventCount;
    }
    return FindObjectEventTemplateByLocalId(localId, templates, count);
}

static struct ObjectEventTemplate *FindObjectEventTemplateByLocalId(u8 localId, struct ObjectEventTemplate *templates, u8 count)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (templates[i].localId == localId)
        {
            return &templates[i];
        }
    }
    return NULL;
}

struct ObjectEventTemplate *GetBaseTemplateForObjectEvent(const struct ObjectEvent *objectEvent)
{
    int i;

    if (objectEvent->mapNum != gSaveBlock1Ptr->location.mapNum || objectEvent->mapGroup != gSaveBlock1Ptr->location.mapGroup)
    {
        return NULL;
    }
    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        if (objectEvent->localId == gSaveBlock1Ptr->objectEventTemplates[i].localId)
        {
            return &gSaveBlock1Ptr->objectEventTemplates[i];
        }
    }
    return NULL;
}

void OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate != NULL)
    {
        objectEventTemplate->x = objectEvent->currentCoords.x - 7;
        objectEventTemplate->y = objectEvent->currentCoords.y - 7;
    }
}

static void OverrideObjectEventTemplateScript(const struct ObjectEvent *objectEvent, const u8 *script)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate)
        objectEventTemplate->script = script;
}

void TryOverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent, u8 movementType)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate != NULL)
    {
        objectEventTemplate->movementType = movementType;
    }
}

void TryOverrideObjectEventTemplateCoords(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        OverrideTemplateCoordsForObjectEvent(&gObjectEvents[objectEventId]);
}

void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        switch (decorationCategory)
        {
        case DECORCAT_DOLL:
            OverrideObjectEventTemplateScript(&gObjectEvents[objectEventId], SecretBase_EventScript_DollInteract);
            break;
        case DECORCAT_CUSHION:
            OverrideObjectEventTemplateScript(&gObjectEvents[objectEventId], SecretBase_EventScript_CushionInteract);
            break;
        }
    }
}

void InitObjectEventPalettes(u8 palSlot)
{
    FreeAndReserveObjectSpritePalettes();
    sCurrentSpecialObjectPaletteTag = OBJ_EVENT_PAL_TAG_NONE;
    sCurrentReflectionType = palSlot;
    if (palSlot == 1)
    {
        PatchObjectPaletteRange(sObjectPaletteTagSets[sCurrentReflectionType], 0, 6);
        gReservedSpritePaletteCount = 8;
    }
    else
    {
        PatchObjectPaletteRange(sObjectPaletteTagSets[sCurrentReflectionType], 0, 10);
    }
}

u16 GetObjectPaletteTag(u8 palSlot)
{
    u8 i;

    if (palSlot < 10)
    {
        return sObjectPaletteTagSets[sCurrentReflectionType][palSlot];
    }
    for (i = 0; sSpecialObjectReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sSpecialObjectReflectionPaletteSets[i].tag == sCurrentSpecialObjectPaletteTag)
        {
            return sSpecialObjectReflectionPaletteSets[i].data[sCurrentReflectionType];
        }
    }
    return OBJ_EVENT_PAL_TAG_NONE;
}

movement_type_empty_callback(MovementType_None)
movement_type_def(MovementType_WanderAround, gMovementTypeFuncs_WanderAround)

bool8 MovementType_WanderAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    u8 chosenDirection;

    memcpy(directions, gStandardDirections, sizeof directions);
    chosenDirection = directions[Random() & 3];
    SetObjectEventDirection(objectEvent, chosenDirection);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(objectEvent, chosenDirection))
        sprite->data[1] = 1;

    return TRUE;
}

bool8 MovementType_WanderAround_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkNormalMovementAction(objectEvent->movementDirection));
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderAround_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 ObjectEventIsTrainerAndCloseToPlayer(struct ObjectEvent *objectEvent)
{
    s16 playerX;
    s16 playerY;
    s16 objX;
    s16 objY;
    s16 minX;
    s16 maxX;
    s16 minY;
    s16 maxY;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH))
    {
        return FALSE;
    }
    if (objectEvent->trainerType != TRAINER_TYPE_NORMAL && objectEvent->trainerType != TRAINER_TYPE_BURIED)
    {
        return FALSE;
    }
    PlayerGetDestCoords(&playerX, &playerY);
    objX = objectEvent->currentCoords.x;
    objY = objectEvent->currentCoords.y;
    minX = objX - objectEvent->trainerRange_berryTreeId;
    minY = objY - objectEvent->trainerRange_berryTreeId;
    maxX = objX + objectEvent->trainerRange_berryTreeId;
    maxY = objY + objectEvent->trainerRange_berryTreeId;
    if (minX > playerX || maxX < playerX || minY > playerY || maxY < playerY)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetVectorDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    if (absdx > absdy)
    {
        direction = DIR_EAST;
        if (dx < 0)
        {
            direction = DIR_WEST;
        }
    }
    else
    {
        direction = DIR_SOUTH;
        if (dy < 0)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_SOUTH;
    if (dy < 0)
    {
        direction = DIR_NORTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_EAST;
    if (dx < 0)
    {
        direction = DIR_WEST;
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_NORTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
        {
            direction = DIR_NORTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
        {
            direction = DIR_SOUTH;
        }
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
        {
            direction = DIR_SOUTH;
        }
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthWest(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_NorthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    }
    return direction;
}

u8 TryGetTrainerEncounterDirection(struct ObjectEvent *objectEvent, u8 movementType)
{
    s16 dx, dy;
    s16 absdx, absdy;

    if (!ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        return 0;
    }
    PlayerGetDestCoords(&dx, &dy);
    dx -= objectEvent->currentCoords.x;
    dy -= objectEvent->currentCoords.y;
    absdx = dx;
    absdy = dy;
    if (absdx < 0)
    {
        absdx = -absdx;
    }
    if (absdy < 0)
    {
        absdy = -absdy;
    }
    return gGetVectorDirectionFuncs[movementType](dx, dy, absdx, absdy);
}

movement_type_def(MovementType_LookAround, gMovementTypeFuncs_LookAround)

bool8 MovementType_LookAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_LookAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_LookAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_LookAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_LookAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];

    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_WanderUpAndDown, gMovementTypeFuncs_WanderUpAndDown)

bool8 MovementType_WanderUpAndDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderUpAndDown_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(objectEvent, direction))
        sprite->data[1] = 1;

    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkNormalMovementAction(objectEvent->movementDirection));
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_WanderLeftAndRight, gMovementTypeFuncs_WanderLeftAndRight)

bool8 MovementType_WanderLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        return FALSE;
    }
    SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 5;
    if (GetCollisionInDirection(objectEvent, direction))
        sprite->data[1] = 1;

    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkNormalMovementAction(objectEvent->movementDirection));
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 6;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_FaceDirection, gMovementTypeFuncs_FaceDirection)

bool8 MovementType_FaceDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDirection_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDirection_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = 0;
    return FALSE;
}

static bool8 ObjectEventCB2_BerryTree(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 (*const gMovementTypeFuncs_BerryTreeGrowth[])(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void MovementType_BerryTreeGrowth(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->data[0]];
    if (!(sprite->data[7] & 1))
    {
        get_berry_tree_graphics(objectEvent, sprite);
        sprite->data[7] |= 1;
    }
    UpdateObjectEventCurrentMovement(objectEvent, sprite, ObjectEventCB2_BerryTree);
}
static bool8 ObjectEventCB2_BerryTree(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_BerryTreeGrowth[sprite->data[1]](objectEvent, sprite);
}

bool8 MovementType_BerryTreeGrowth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 berryStage;
    ClearObjectEventMovement(objectEvent, sprite);
    objectEvent->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(objectEvent->trainerRange_berryTreeId);
    if (berryStage == 0)
    {
        if (!(sprite->data[7] & 4) && sprite->animNum == 4)
        {
            gFieldEffectArguments[0] = objectEvent->currentCoords.x;
            gFieldEffectArguments[1] = objectEvent->currentCoords.y;
            gFieldEffectArguments[2] = sprite->subpriority - 1;
            gFieldEffectArguments[3] = sprite->oam.priority;
            FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
            sprite->animNum = berryStage;
        }
        return FALSE;
    }
    objectEvent->invisible = FALSE;
    sprite->invisible = FALSE;
    berryStage --;
    if (sprite->animNum != berryStage)
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    get_berry_tree_graphics(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->data[1] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_BerryTreeGrowth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 3;
    sprite->data[2] = 0;
    sprite->data[7] |= 2;
    gFieldEffectArguments[0] = objectEvent->currentCoords.x;
    gFieldEffectArguments[1] = objectEvent->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->data[2]++;
    objectEvent->invisible = (sprite->data[2] & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data[2] > 64)
    {
        get_berry_tree_graphics(objectEvent, sprite);
        sprite->data[1] = 4;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_BerryTreeGrowth_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->data[2]++;
    objectEvent->invisible = (sprite->data[2] & 0x02) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->data[2] > 64)
    {
        sprite->data[1] = 0;
        sprite->data[7] &= ~0x0002;
        return TRUE;
    }
    return FALSE;
}

movement_type_def(MovementType_FaceDownAndUp, gMovementTypeFuncs_FaceDownAndUp)

bool8 MovementType_FaceDownAndUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndUp_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndUp_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndUp_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof gUpAndDownDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceLeftAndRight, gMovementTypeFuncs_FaceLeftAndRight)

bool8 MovementType_FaceLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysMedium[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof gLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpAndLeft, gMovementTypeFuncs_FaceUpAndLeft)

bool8 MovementType_FaceUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndLeftDirections, sizeof gUpAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpAndRight, gMovementTypeFuncs_FaceUpAndRight)

bool8 MovementType_FaceUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndRightDirections, sizeof gUpAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownAndLeft, gMovementTypeFuncs_FaceDownAndLeft)

bool8 MovementType_FaceDownAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndLeftDirections, sizeof gDownAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownAndRight, gMovementTypeFuncs_FaceDownAndRight)

bool8 MovementType_FaceDownAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndRightDirections, sizeof gDownAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 1];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownUpAndLeft, gMovementTypeFuncs_FaceDownUpAndLeft)

bool8 MovementType_FaceDownUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndLeftDirections, sizeof gDownUpAndLeftDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownUpAndRight, gMovementTypeFuncs_FaceDownUpAndRight)

bool8 MovementType_FaceDownUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndRightDirections, sizeof gDownUpAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH_EAST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceUpRightAndLeft, gMovementTypeFuncs_FaceUpLeftAndRight)

bool8 MovementType_FaceUpLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceUpLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceUpLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceUpLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gUpLeftAndRightDirections, sizeof gUpLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_FaceDownRightAndLeft, gMovementTypeFuncs_FaceDownLeftAndRight)

bool8 MovementType_FaceDownLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_FaceDownLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_FaceDownLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, gMovementDelaysShort[Random() & 3]);
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_FaceDownLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownLeftAndRightDirections, sizeof gDownLeftAndRightDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_EAST_WEST);
    if (direction == 0)
    {
        direction = directions[Random() & 3];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_RotateCounterclockwise, gMovementTypeFuncs_RotateCounterclockwise)

bool8 MovementType_RotateCounterclockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_RotateCounterclockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gCounterclockwiseDirections, sizeof gCounterclockwiseDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[objectEvent->facingDirection];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 0;
    return TRUE;
}

movement_type_def(MovementType_RotateClockwise, gMovementTypeFuncs_RotateClockwise)

bool8 MovementType_RotateClockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_RotateClockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->data[1] = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || ObjectEventIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->data[1] = 3;
    }
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gClockwiseDirections, sizeof gClockwiseDirections);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == 0)
    {
        direction = directions[objectEvent->facingDirection];
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 0;
    return TRUE;
}

movement_type_def(MovementType_WalkBackAndForth, gMovementTypeFuncs_WalkBackAndForth)

bool8 MovementType_WalkBackAndForth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;

    direction = gInitialMovementTypeFacingDirections[objectEvent->movementType];
    if (objectEvent->directionSequenceIndex)
    {
        direction = GetOppositeDirection(direction);
    }
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    bool8 collision;
    u8 movementActionId;

    if (objectEvent->directionSequenceIndex && objectEvent->initialCoords.x == objectEvent->currentCoords.x && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 0;
        SetObjectEventDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
    }
    collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    movementActionId = GetWalkNormalMovementAction(objectEvent->movementDirection);
    if (collision == COLLISION_OUTSIDE_RANGE)
    {
        objectEvent->directionSequenceIndex++;
        SetObjectEventDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
        movementActionId = GetWalkNormalMovementAction(objectEvent->movementDirection);
        collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    }

    if (collision)
        movementActionId = GetWalkInPlaceNormalMovementAction(objectEvent->facingDirection);

    ObjectEventSetSingleMovement(objectEvent, sprite, movementActionId);
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 3;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 MovementType_WalkSequence_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MoveNextDirectionInSequence(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 *route)
{
    u8 collision;
    u8 movementActionId;

    if (objectEvent->directionSequenceIndex == 3 && objectEvent->initialCoords.x == objectEvent->currentCoords.x && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 0;

    SetObjectEventDirection(objectEvent, route[objectEvent->directionSequenceIndex]);
    movementActionId = GetWalkNormalMovementAction(objectEvent->movementDirection);
    collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    if (collision == COLLISION_OUTSIDE_RANGE)
    {
        objectEvent->directionSequenceIndex++;
        SetObjectEventDirection(objectEvent, route[objectEvent->directionSequenceIndex]);
        movementActionId = GetWalkNormalMovementAction(objectEvent->movementDirection);
        collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    }

    if (collision)
        movementActionId = GetWalkInPlaceNormalMovementAction(objectEvent->facingDirection);

    ObjectEventSetSingleMovement(objectEvent, sprite, movementActionId);
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 MovementType_WalkSequence_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

movement_type_def(MovementType_WalkSequenceUpRightLeftDown, gMovementTypeFuncs_WalkSequenceUpRightLeftDown)

u8 MovementType_WalkSequenceUpRightLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpRightLeftDownDirections)];
    memcpy(directions, gUpRightLeftDownDirections, sizeof(gUpRightLeftDownDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightLeftDownUp, gMovementTypeFuncs_WalkSequenceRightLeftDownUp)

u8 MovementType_WalkSequenceRightLeftDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightLeftDownUpDirections)];
    memcpy(directions, gRightLeftDownUpDirections, sizeof(gRightLeftDownUpDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownUpRightLeft, gMovementTypeFuncs_WalkSequenceDownUpRightLeft)

u8 MovementType_WalkSequenceDownUpRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownUpRightLeftDirections)];
    memcpy(directions, gDownUpRightLeftDirections, sizeof(gDownUpRightLeftDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftDownUpRight, gMovementTypeFuncs_WalkSequenceLeftDownUpRight)

u8 MovementType_WalkSequenceLeftDownUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftDownUpRightDirections)];
    memcpy(directions, gLeftDownUpRightDirections, sizeof(gLeftDownUpRightDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpLeftRightDown, gMovementTypeFuncs_WalkSequenceUpLeftRightDown)

u8 MovementType_WalkSequenceUpLeftRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpLeftRightDownDirections)];
    memcpy(directions, gUpLeftRightDownDirections, sizeof(gUpLeftRightDownDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftRightDownUp, gMovementTypeFuncs_WalkSequenceLeftRightDownUp)

u8 MovementType_WalkSequenceLeftRightDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftRightDownUpDirections)];
    memcpy(directions, gLeftRightDownUpDirections, sizeof(gLeftRightDownUpDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownUpLeftRight, gMovementTypeFuncs_WalkSequenceDownUpLeftRight)

u8 MovementType_WalkSequenceDownUpLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gStandardDirections)];
    memcpy(directions, gStandardDirections, sizeof(gStandardDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightDownUpLeft, gMovementTypeFuncs_WalkSequenceRightDownUpLeft)

u8 MovementType_WalkSequenceRightDownUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightDownUpLeftDirections)];
    memcpy(directions, gRightDownUpLeftDirections, sizeof(gRightDownUpLeftDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftUpDownRight, gMovementTypeFuncs_WalkSequenceLeftUpDownRight)

u8 MovementType_WalkSequenceLeftUpDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftUpDownRightDirections)];
    memcpy(directions, gLeftUpDownRightDirections, sizeof(gLeftUpDownRightDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpDownRightLeft, gMovementTypeFuncs_WalkSequenceUpDownRightLeft)

u8 MovementType_WalkSequenceUpDownRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpDownRightLeftDirections)];
    memcpy(directions, gUpDownRightLeftDirections, sizeof(gUpDownRightLeftDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightLeftUpDown, gMovementTypeFuncs_WalkSequenceRightLeftUpDown)

u8 MovementType_WalkSequenceRightLeftUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightLeftUpDownDirections)];
    memcpy(directions, gRightLeftUpDownDirections, sizeof(gRightLeftUpDownDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownRightLeftUp, gMovementTypeFuncs_WalkSequenceDownRightLeftUp)

u8 MovementType_WalkSequenceDownRightLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownRightLeftUpDirections)];
    memcpy(directions, gDownRightLeftUpDirections, sizeof(gDownRightLeftUpDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightUpDownLeft, gMovementTypeFuncs_WalkSequenceRightUpDownLeft)

u8 MovementType_WalkSequenceRightUpDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightUpDownLeftDirections)];
    memcpy(directions, gRightUpDownLeftDirections, sizeof(gRightUpDownLeftDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpDownLeftRight, gMovementTypeFuncs_WalkSequenceUpDownLeftRight)

u8 MovementType_WalkSequenceUpDownLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpDownLeftRightDirections)];
    memcpy(directions, gUpDownLeftRightDirections, sizeof(gUpDownLeftRightDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftRightUpDown, gMovementTypeFuncs_WalkSequenceLeftRightUpDown)

u8 MovementType_WalkSequenceLeftRightUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftRightUpDownDirections)];
    memcpy(directions, gLeftRightUpDownDirections, sizeof(gLeftRightUpDownDirections));
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 2;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownLeftRightUp, gMovementTypeFuncs_WalkSequenceDownLeftRightUp)

u8 MovementType_WalkSequenceDownLeftRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownLeftRightUpDirections)];
    memcpy(directions, gDownLeftRightUpDirections, sizeof(gDownLeftRightUpDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpLeftDownRight, gMovementTypeFuncs_WalkSequenceUpLeftDownRight)

u8 MovementType_WalkSequenceUpLeftDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpLeftDownRightDirections)];
    memcpy(directions, gUpLeftDownRightDirections, sizeof(gUpLeftDownRightDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownRightUpLeft, gMovementTypeFuncs_WalkSequenceDownRightUpLeft)

u8 MovementType_WalkSequenceDownRightUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownRightUpLeftDirections)];
    memcpy(directions, gDownRightUpLeftDirections, sizeof(gDownRightUpLeftDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftDownRightUp, gMovementTypeFuncs_WalkSequenceLeftDownRightUp)

u8 MovementType_WalkSequenceLeftDownRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftDownRightUpDirections)];
    memcpy(directions, gLeftDownRightUpDirections, sizeof(gLeftDownRightUpDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightUpLeftDown, gMovementTypeFuncs_WalkSequenceRightUpLeftDown)

u8 MovementType_WalkSequenceRightUpLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightUpLeftDownDirections)];
    memcpy(directions, gRightUpLeftDownDirections, sizeof(gRightUpLeftDownDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceUpRightDownLeft, gMovementTypeFuncs_WalkSequenceUpRightDownLeft)

u8 MovementType_WalkSequenceUpRightDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gUpRightDownLeftDirections)];
    memcpy(directions, gUpRightDownLeftDirections, sizeof(gUpRightDownLeftDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceDownLeftUpRight, gMovementTypeFuncs_WalkSequenceDownLeftUpRight)

u8 MovementType_WalkSequenceDownLeftUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gDownLeftUpRightDirections)];
    memcpy(directions, gDownLeftUpRightDirections, sizeof(gDownLeftUpRightDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceLeftUpRightDown, gMovementTypeFuncs_WalkSequenceLeftUpRightDown)

u8 MovementType_WalkSequenceLeftUpRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gLeftUpRightDownDirections)];
    memcpy(directions, gLeftUpRightDownDirections, sizeof(gLeftUpRightDownDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_WalkSequenceRightDownLeftUp, gMovementTypeFuncs_WalkSequenceRightDownLeftUp)

u8 MovementType_WalkSequenceRightDownLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[sizeof(gRightDownLeftUpDirections)];
    memcpy(directions, gRightDownLeftUpDirections, sizeof(gRightDownLeftUpDirections));
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
    {
        objectEvent->directionSequenceIndex = 3;
    }
    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

movement_type_def(MovementType_CopyPlayer, gMovementTypeFuncs_CopyPlayer)

bool8 MovementType_CopyPlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    if (objectEvent->directionSequenceIndex == 0)
    {
        objectEvent->directionSequenceIndex = GetPlayerFacingDirection();
    }
    sprite->data[1] = 1;
    return TRUE;
}

bool8 MovementType_CopyPlayer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
    {
        return FALSE;
    }
    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](objectEvent, sprite, GetPlayerMovementDirection(), NULL);
}

bool8 MovementType_CopyPlayer_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = 0;
        sprite->data[1] = 1;
    }
    return FALSE;
}

bool8 CopyablePlayerMovement_None(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    return FALSE;
}

bool8 CopyablePlayerMovement_FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, playerDirection)));
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed0(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    if (ObjectEventIsFarawayIslandMew(objectEvent))
    {
        direction = GetMewMoveDirection();
        if (direction == DIR_NONE)
        {
            direction = playerDirection;
            direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
            ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
            ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
            objectEvent->singleMovementActive = 1;
            sprite->data[1] = 2;
            return TRUE;
        }
    }
    else
    {
        direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    }
    ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkNormalMovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = 1;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkFastMovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed2(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkFastestMovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_Slide(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetSlideMovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 cph_IM_DIFFERENT(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetJumpInPlaceMovementAction(direction));
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_GoSpeed4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    ObjectEventMoveDestCoords(objectEvent, direction, &x, &y);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetJumpMovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

bool8 CopyablePlayerMovement_Jump(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    u32 direction;
    s16 x;
    s16 y;

    direction = playerDirection;
    direction = state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, direction);
    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    MoveCoordsInDirection(direction, &x, &y, 2, 2);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetJump2MovementAction(direction));
    if (GetCollisionAtCoords(objectEvent, x, y, direction) || (tileCallback != NULL && !tileCallback(MapGridGetMetatileBehaviorAt(x, y))))
    {
        ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(direction));
    }
    objectEvent->singleMovementActive = TRUE;
    sprite->data[1] = 2;
    return TRUE;
}

movement_type_def(MovementType_CopyPlayerInGrass, gMovementTypeFuncs_CopyPlayerInGrass)

bool8 MovementType_CopyPlayerInGrass_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].movementActionId == 0xFF || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
    {
        return FALSE;
    }
    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](objectEvent, sprite, GetPlayerMovementDirection(), MetatileBehavior_IsPokeGrass);
}

void MovementType_TreeDisguise(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->data[0]];
    if (objectEvent->directionSequenceIndex == 0 || (objectEvent->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        objectEvent->fieldEffectSpriteId = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        objectEvent->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, MovementType_Disguise_Callback);
}

static bool8 MovementType_Disguise_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    return FALSE;
}

void MovementType_MountainDisguise(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->data[0]];
    if (objectEvent->directionSequenceIndex == 0 || (objectEvent->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        objectEvent->fieldEffectSpriteId = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        objectEvent->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, MovementType_Disguise_Callback);
}

void MovementType_Hidden(struct Sprite *sprite)
{
    if (!sprite->data[7])
    {
        gObjectEvents[sprite->data[0]].fixedPriority = TRUE;
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        sprite->oam.priority = 3;
        sprite->data[7]++;
    }
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, MovementType_Hidden_Callback);
}

static bool8 MovementType_Hidden_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_Hidden[sprite->data[1]](objectEvent, sprite);
}

bool8 MovementType_Hidden_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    return FALSE;
}

bool8 MovementType_MoveInPlace_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->data[1] = 0;
    }
    return FALSE;
}

movement_type_def(MovementType_WalkInPlace, gMovementTypeFuncs_WalkInPlace)

bool8 MovementType_WalkInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkInPlaceNormalMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_WalkSlowlyInPlace, gMovementTypeFuncs_WalkSlowlyInPlace)

bool8 MovementType_WalkSlowlyInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkInPlaceSlowMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_JogInPlace, gMovementTypeFuncs_JogInPlace)

bool8 MovementType_JogInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkInPlaceFastMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_RunInPlace, gMovementTypeFuncs_RunInPlace)

bool8 MovementType_RunInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetWalkInPlaceFastestMovementAction(objectEvent->facingDirection));
    sprite->data[1] = 1;
    return TRUE;
}

movement_type_def(MovementType_Invisible, gMovementTypeFuncs_Invisible)

bool8 MovementType_Invisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearObjectEventMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    objectEvent->invisible = TRUE;
    sprite->data[1] = 1;
    return TRUE;
}
bool8 MovementType_Invisible_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->data[1] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_Invisible_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = 0;
    return FALSE;
}

static void ClearObjectEventMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = 0;
    objectEvent->heldMovementActive = FALSE;
    objectEvent->heldMovementFinished = FALSE;
    objectEvent->movementActionId = 0xFF;
    sprite->data[1] = 0;
}

u8 GetFaceDirectionAnimNum(u8 direction)
{
    return gFaceDirectionAnimNums[direction];
}

u8 GetMoveDirectionAnimNum(u8 direction)
{
    return gMoveDirectionAnimNums[direction];
}

u8 GetMoveDirectionFastAnimNum(u8 direction)
{
    return gMoveDirectionFastAnimNums[direction];
}

u8 GetMoveDirectionFasterAnimNum(u8 direction)
{
    return gMoveDirectionFasterAnimNums[direction];
}

u8 GetMoveDirectionFastestAnimNum(u8 direction)
{
    return gMoveDirectionFastestAnimNums[direction];
}

u8 GetJumpSpecialDirectionAnimNum(u8 direction)
{
    return gJumpSpecialDirectionAnimNums[direction];
}

u8 GetAcroWheelieDirectionAnimNum(u8 direction)
{
    return gAcroWheelieDirectionAnimNums[direction];
}

u8 Unref_GetAnimNums_08375633(u8 direction)
{
    return gUnrefAnimNums_08375633[direction];
}

u8 GetAcroEndWheelieDirectionAnimNum(u8 direction)
{
    return gAcroEndWheelieDirectionAnimNums[direction];
}

u8 GetAcroUnusedActionDirectionAnimNum(u8 direction)
{
    return gAcroUnusedActionDirectionAnimNums[direction];
}

u8 GetAcroWheeliePedalDirectionAnimNum(u8 direction)
{
    return gAcroWheeliePedalDirectionAnimNums[direction];
}

u8 GetFishingDirectionAnimNum(u8 direction)
{
    return gFishingDirectionAnimNums[direction];
}

u8 GetFishingNoCatchDirectionAnimNum(u8 direction)
{
    return gFishingNoCatchDirectionAnimNums[direction];
}

u8 GetFishingBiteDirectionAnimNum(u8 direction)
{
    return gFishingBiteDirectionAnimNums[direction];
}

u8 GetRunningDirectionAnimNum(u8 direction)
{
    return gRunningDirectionAnimNums[direction];
}

static const struct UnkStruct_085094AC *sub_8092A4C(const union AnimCmd *const *anims)
{
    const struct UnkStruct_085094AC *retval;

    for (retval = gUnknown_085094AC; retval->anims != NULL; retval++)
    {
        if (retval->anims == anims)
        {
            return retval;
        }
    }
    return NULL;
}

void npc_apply_anim_looping(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!objectEvent->inanimate)
    {
        sprite->animNum = animNum;
        unk85094AC = sub_8092A4C(sprite->anims);
        if (unk85094AC != NULL)
        {
            if (sprite->animCmdIndex == unk85094AC->animPos[0])
            {
                sprite->animCmdIndex = unk85094AC->animPos[3];
            }
            else if (sprite->animCmdIndex == unk85094AC->animPos[1])
            {
                sprite->animCmdIndex = unk85094AC->animPos[2];
            }
        }
        SeekSpriteAnim(sprite, sprite->animCmdIndex);
    }
}

void obj_npc_animation_step(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    const struct UnkStruct_085094AC *unk85094AC;

    if (!objectEvent->inanimate)
    {
        u8 animPos;

        sprite->animNum = animNum;
        unk85094AC = sub_8092A4C(sprite->anims);
        if (unk85094AC != NULL)
        {
            animPos = unk85094AC->animPos[1];
            if (sprite->animCmdIndex <= unk85094AC->animPos[0])
            {
                animPos = unk85094AC->animPos[0];
            }
            SeekSpriteAnim(sprite, animPos);
        }
    }
}

// file boundary?

u8 GetDirectionToFace(s16 x1, s16 y1, s16 x2, s16 y2)
{
    if (x1 > x2)
    {
        return DIR_WEST;
    }
    if (x1 < x2)
    {
        return DIR_EAST;
    }
    if (y1 > y2)
    {
        return DIR_NORTH;
    }
    return DIR_SOUTH;
}

void SetTrainerMovementType(struct ObjectEvent *objectEvent, u8 movementType)
{
    objectEvent->movementType = movementType;
    objectEvent->directionSequenceIndex = 0;
    objectEvent->playerCopyableMovement = 0;
    gSprites[objectEvent->spriteId].callback = sMovementTypeCallbacks[movementType];
    gSprites[objectEvent->spriteId].data[1] = 0;
}

u8 GetTrainerFacingDirectionMovementType(u8 direction)
{
    return gTrainerFacingDirectionMovementTypes[direction];
}

static u8 GetCollisionInDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    s16 x;
    s16 y;
    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return GetCollisionAtCoords(objectEvent, x, y, direction);
}

u8 GetCollisionAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir)
{
    u8 direction = dir;
    if (IsCoordOutsideObjectEventMovementRange(objectEvent, x, y))
        return COLLISION_OUTSIDE_RANGE;
    else if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(objectEvent, x, y, direction))
        return COLLISION_IMPASSABLE;
    else if (objectEvent->trackedByCamera && !CanCameraMoveInDirection(direction))
        return COLLISION_IMPASSABLE;
    else if (IsZCoordMismatchAt(objectEvent->currentElevation, x, y))
        return COLLISION_ELEVATION_MISMATCH;
    else if (DoesObjectCollideWithObjectAt(objectEvent, x, y))
        return COLLISION_OBJECT_EVENT;
    return COLLISION_NONE;
}

u8 GetCollisionFlagsAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction)
{
    u8 flags = 0;

    if (IsCoordOutsideObjectEventMovementRange(objectEvent, x, y))
        flags |= 1;
    if (MapGridIsImpassableAt(x, y) || GetMapBorderIdAt(x, y) == -1 || IsMetatileDirectionallyImpassable(objectEvent, x, y, direction) || (objectEvent->trackedByCamera && !CanCameraMoveInDirection(direction)))
        flags |= 2;
    if (IsZCoordMismatchAt(objectEvent->currentElevation, x, y))
        flags |= 4;
    if (DoesObjectCollideWithObjectAt(objectEvent, x, y))
        flags |= 8;
    return flags;
}

static bool8 IsCoordOutsideObjectEventMovementRange(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (objectEvent->rangeX != 0)
    {
        left = objectEvent->initialCoords.x - objectEvent->rangeX;
        right = objectEvent->initialCoords.x + objectEvent->rangeX;
        if (left > x || right < x)
        {
            return TRUE;
        }
    }
    if (objectEvent->rangeY != 0)
    {
        top = objectEvent->initialCoords.y - objectEvent->rangeY;
        bottom = objectEvent->initialCoords.y + objectEvent->rangeY;
        if (top > y || bottom < y)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsMetatileDirectionallyImpassable(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction)
{
    if (gOppositeDirectionBlockedMetatileFuncs[direction - 1](objectEvent->currentMetatileBehavior)
        || gDirectionBlockedMetatileFuncs[direction - 1](MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }
    return FALSE;
}

static bool8 DoesObjectCollideWithObjectAt(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    u8 i;
    struct ObjectEvent *curObject;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        curObject = &gObjectEvents[i];
        if (curObject->active && curObject != objectEvent)
        {
            if ((curObject->currentCoords.x == x && curObject->currentCoords.y == y) || (curObject->previousCoords.x == x && curObject->previousCoords.y == y))
            {
                if (AreZCoordsCompatible(objectEvent->currentElevation, curObject->currentElevation))
                {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
        && gSprites[gObjectEvents[objectEventId].spriteId].data[7] & 2)
    {
        return TRUE;
    }

    return FALSE;
}

void sub_8092EF0(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        gSprites[gObjectEvents[objectEventId].spriteId].data[7] |= 0x04;
    }
}

void MoveCoords(u8 direction, s16 *x, s16 *y)
{
    *x += sDirectionToVectors[direction].x;
    *y += sDirectionToVectors[direction].y;
}

void sub_8092F60(u8 direction, s16 *x, s16 *y)
{
    *x += sDirectionToVectors[direction].x << 4;
    *y += sDirectionToVectors[direction].y << 4;
}

static void MoveCoordsInDirection(u32 dir, s16 *x, s16 *y, s16 deltaX, s16 deltaY)
{
    u8 direction = dir;
    s16 dx2 = (u16)deltaX;
    s16 dy2 = (u16)deltaY;
    if (sDirectionToVectors[direction].x > 0)
        *x += dx2;
    if (sDirectionToVectors[direction].x < 0)
        *x -= dx2;
    if (sDirectionToVectors[direction].y > 0)
        *y += dy2;
    if (sDirectionToVectors[direction].y < 0)
        *y -= dy2;
}

void sub_8092FF0(s16 x, s16 y, s16 *destX, s16 *destY)
{
    *destX = (x - gSaveBlock1Ptr->pos.x) << 4;
    *destY = (y - gSaveBlock1Ptr->pos.y) << 4;
    *destX -= gTotalCameraPixelOffsetX;
    *destY -= gTotalCameraPixelOffsetY;
}

void SetSpritePosToMapCoords(s16 mapX, s16 mapY, s16 *destX, s16 *destY)
{
    s16 dx = -gTotalCameraPixelOffsetX - gFieldCamera.x;
    s16 dy = -gTotalCameraPixelOffsetY - gFieldCamera.y;
    if (gFieldCamera.x > 0)
        dx += 16;

    if (gFieldCamera.x < 0)
        dx -= 16;

    if (gFieldCamera.y > 0)
        dy += 16;

    if (gFieldCamera.y < 0)
        dy -= 16;

    *destX = ((mapX - gSaveBlock1Ptr->pos.x) << 4) + dx;
    *destY = ((mapY - gSaveBlock1Ptr->pos.y) << 4) + dy;
}

void SetSpritePosToOffsetMapCoords(s16 *x, s16 *y, s16 dx, s16 dy)
{
    SetSpritePosToMapCoords(*x, *y, x, y);
    *x += dx;
    *y += dy;
}

static void GetObjectEventMovingCameraOffset(s16 *x, s16 *y)
{
    *x = 0;
    *y = 0;
    if (gFieldCamera.x > 0)
    {
        (*x)++;
    }
    if (gFieldCamera.x < 0)
    {
        (*x) --;
    }
    if (gFieldCamera.y > 0)
    {
        (*y)++;
    }
    if (gFieldCamera.y < 0)
    {
        (*y) --;
    }
}

void ObjectEventMoveDestCoords(struct ObjectEvent *objectEvent, u32 direction, s16 *x, s16 *y)
{
    u8 newDirn = direction;
    *x = objectEvent->currentCoords.x;
    *y = objectEvent->currentCoords.y;
    MoveCoords(newDirn, x, y);
}

bool8 ObjectEventIsMovementOverridden(struct ObjectEvent *objectEvent)
{
    if (objectEvent->singleMovementActive || objectEvent->heldMovementActive)
        return TRUE;

    return FALSE;
}

bool8 ObjectEventIsHeldMovementActive(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive && objectEvent->movementActionId != 0xFF)
        return TRUE;

    return FALSE;
}

bool8 ObjectEventSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId)
{
    if (ObjectEventIsMovementOverridden(objectEvent))
        return TRUE;

    UnfreezeObjectEvent(objectEvent);
    objectEvent->movementActionId = movementActionId;
    objectEvent->heldMovementActive = TRUE;
    objectEvent->heldMovementFinished = FALSE;
    gSprites[objectEvent->spriteId].data[2] = 0;
    return FALSE;
}

void ObjectEventForceSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId)
{
    ObjectEventClearHeldMovementIfActive(objectEvent);
    ObjectEventSetHeldMovement(objectEvent, movementActionId);
}

void ObjectEventClearHeldMovementIfActive(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        ObjectEventClearHeldMovement(objectEvent);
}

void ObjectEventClearHeldMovement(struct ObjectEvent *objectEvent)
{
    objectEvent->movementActionId = 0xFF;
    objectEvent->heldMovementActive = FALSE;
    objectEvent->heldMovementFinished = FALSE;
    gSprites[objectEvent->spriteId].data[1] = 0;
    gSprites[objectEvent->spriteId].data[2] = 0;
}

u8 ObjectEventCheckHeldMovementStatus(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->heldMovementFinished;

    return 16;
}

u8 ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *objectEvent)
{
    u8 heldMovementStatus = ObjectEventCheckHeldMovementStatus(objectEvent);
    if (heldMovementStatus != 0 && heldMovementStatus != 16)
        ObjectEventClearHeldMovementIfActive(objectEvent);

    return heldMovementStatus;
}

u8 ObjectEventGetHeldMovementActionId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->movementActionId;

    return 0xFF;
}

void UpdateObjectEventCurrentMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 (*callback)(struct ObjectEvent *, struct Sprite *))
{
    DoGroundEffects_OnSpawn(objectEvent, sprite);
    TryEnableObjectEventAnim(objectEvent, sprite);
    if (ObjectEventIsHeldMovementActive(objectEvent))
    {
        ObjectEventExecHeldMovementAction(objectEvent, sprite);
    }
    else if (!objectEvent->frozen)
    {
        while (callback(objectEvent, sprite));
    }
    DoGroundEffects_OnBeginStep(objectEvent, sprite);
    DoGroundEffects_OnFinishStep(objectEvent, sprite);
    UpdateObjectEventSpriteAnimPause(objectEvent, sprite);
    UpdateObjectEventVisibility(objectEvent, sprite);
    ObjectEventUpdateSubpriority(objectEvent, sprite);
}

#define dirn_to_anim(name, table)\
u8 name(u32 idx)\
{\
    u8 direction;\
    u8 animIds[sizeof(table)];\
    direction = idx;\
    memcpy(animIds, (table), sizeof(table));\
    if (direction > DIR_EAST) direction = 0;\
    return animIds[direction];\
}

dirn_to_anim(GetFaceDirectionMovementAction, gFaceDirectionMovementActions);
dirn_to_anim(GetWalkSlowMovementAction, gWalkSlowMovementActions);
dirn_to_anim(GetWalkNormalMovementAction, gWalkNormalMovementActions);
dirn_to_anim(GetWalkFastMovementAction, gWalkFastMovementActions);
dirn_to_anim(GetRideWaterCurrentMovementAction, gRideWaterCurrentMovementActions);
dirn_to_anim(GetWalkFastestMovementAction, gWalkFastestMovementActions);
dirn_to_anim(GetSlideMovementAction, gSlideMovementActions);
dirn_to_anim(GetPlayerRunMovementAction, gPlayerRunMovementActions);
dirn_to_anim(GetJump2MovementAction, gJump2MovementActions);
dirn_to_anim(GetJumpInPlaceMovementAction, gJumpInPlaceMovementActions);
dirn_to_anim(GetJumpInPlaceTurnAroundMovementAction, gJumpInPlaceTurnAroundMovementActions);
dirn_to_anim(GetJumpMovementAction, gJumpMovementActions);
dirn_to_anim(GetJumpSpecialMovementAction, gJumpSpecialMovementActions);
dirn_to_anim(GetWalkInPlaceSlowMovementAction, gWalkInPlaceSlowMovementActions);
dirn_to_anim(GetWalkInPlaceNormalMovementAction, gWalkInPlaceNormalMovementActions);
dirn_to_anim(GetWalkInPlaceFastMovementAction, gWalkInPlaceFastMovementActions);
dirn_to_anim(GetWalkInPlaceFastestMovementAction, gWalkInPlaceFastestMovementActions);

bool8 ObjectEventFaceOppositeDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    return ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(GetOppositeDirection(direction)));
}

dirn_to_anim(GetAcroWheelieFaceDirectionMovementAction, gAcroWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroPopWheelieFaceDirectionMovementAction, gAcroPopWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroEndWheelieFaceDirectionMovementAction, gAcroEndWheelieFaceDirectionMovementActions);
dirn_to_anim(GetAcroWheelieHopFaceDirectionMovementAction, gAcroWheelieHopFaceDirectionMovementActions);
dirn_to_anim(GetAcroWheelieHopDirectionMovementAction, gAcroWheelieHopDirectionMovementActions);
dirn_to_anim(GetAcroWheelieJumpDirectionMovementAction, gAcroWheelieJumpDirectionMovementActions);
dirn_to_anim(GetAcroWheelieInPlaceDirectionMovementAction, gAcroWheelieInPlaceDirectionMovementActions);
dirn_to_anim(GetAcroPopWheelieMoveDirectionMovementAction, gAcroPopWheelieMoveDirectionMovementActions);
dirn_to_anim(GetAcroWheelieMoveDirectionMovementAction, gAcroWheelieMoveDirectionMovementActions);
dirn_to_anim(GetAcroEndWheelieMoveDirectionMovementAction, gAcroEndWheelieMoveDirectionMovementActions);

u8 GetOppositeDirection(u8 direction)
{
    u8 directions[sizeof gOppositeDirections];

    memcpy(directions, gOppositeDirections, sizeof gOppositeDirections);
    if (direction < 1 || direction > (sizeof gOppositeDirections))
    {
        return direction;
    }
    return directions[direction - 1];
}

static u32 zffu_offset_calc(u8 a0, u8 a1)
{
    return gUnknown_0850DC2F[a0 - 1][a1 - 1];
}

static u32 state_to_direction(u8 a0, u32 a1, u32 a2)
{
    u32 zffuOffset;
    u8 a1_2;
    u8 a2_2;

    a1_2 = a1;
    a2_2 = a2;
    if (a1_2 == 0 || a2_2 == 0 || a1_2 > DIR_EAST || a2_2 > DIR_EAST)
    {
        return 0;
    }
    zffuOffset = zffu_offset_calc(a1_2, a2);
    return gUnknown_0850DC3F[a0 - 1][zffuOffset - 1];
}

static void ObjectEventExecHeldMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gMovementActionFuncs[objectEvent->movementActionId][sprite->data[2]](objectEvent, sprite))
    {
        objectEvent->heldMovementFinished = TRUE;
    }
}

static bool8 ObjectEventExecSingleMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gMovementActionFuncs[objectEvent->movementActionId][sprite->data[2]](objectEvent, sprite))
    {
        objectEvent->movementActionId = 0xFF;
        sprite->data[2] = 0;
        return TRUE;
    }
    return FALSE;
}

static void ObjectEventSetSingleMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animId)
{
    objectEvent->movementActionId = animId;
    sprite->data[2] = 0;
}

static void FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    SetObjectEventDirection(objectEvent, direction);
    ShiftStillObjectEventCoords(objectEvent);
    obj_npc_animation_step(objectEvent, sprite, GetMoveDirectionAnimNum(objectEvent->facingDirection));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 MovementAction_FaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 MovementAction_FaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_NORTH);
    return TRUE;
}

bool8 MovementAction_FaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_WEST);
    return TRUE;
}

bool8 MovementAction_FaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_EAST);
    return TRUE;
}

void npc_apply_direction(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    s16 x;
    s16 y;

    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    SetObjectEventDirection(objectEvent, direction);
    MoveCoords(direction, &x, &y);
    ShiftObjectEventCoords(objectEvent, x, y);
    oamt_npc_ministep_reset(sprite, direction, speed);
    sprite->animPaused = FALSE;
    if (gLockedAnimObjectEvents != NULL && FindLockedObjectEventIndex(objectEvent) != OBJECT_EVENTS_COUNT)
    {
        sprite->animPaused = TRUE;
    }
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void do_go_anim(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    u8 (*functions[ARRAY_COUNT(gUnknown_0850DEE8)])(u8);

    memcpy(functions, gUnknown_0850DEE8, sizeof gUnknown_0850DEE8);
    npc_apply_direction(objectEvent, sprite, direction, speed);
    npc_apply_anim_looping(objectEvent, sprite, functions[speed](objectEvent->facingDirection));
}

void StartRunningAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    npc_apply_direction(objectEvent, sprite, direction, 1);
    npc_apply_anim_looping(objectEvent, sprite, GetRunningDirectionAnimNum(objectEvent->facingDirection));
}

bool8 npc_obj_ministep_stop_on_arrival(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (obj_npc_ministep(sprite))
    {
        ShiftStillObjectEventCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

void sub_8093AF0(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    s16 x;
    s16 y;

    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    SetObjectEventDirection(objectEvent, direction);
    MoveCoords(direction, &x, &y);
    ShiftObjectEventCoords(objectEvent, x, y);
    sub_80976DC(sprite, direction);
    sprite->animPaused = FALSE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    sprite->data[2] = 1;
}

void sub_8093B60(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    sub_8093AF0(objectEvent, sprite, direction);
    npc_apply_anim_looping(objectEvent, sprite, GetMoveDirectionAnimNum(objectEvent->facingDirection));
}

bool8 an_walk_any_2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80976EC(sprite))
    {
        ShiftStillObjectEventCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_NORTHWEST);
    return MovementAction_WalkSlowDiagonalUpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_NORTHEAST);
    return MovementAction_WalkSlowDiagonalUpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_SOUTHWEST);
    return MovementAction_WalkSlowDiagonalDownLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_SOUTHEAST);
    return MovementAction_WalkSlowDiagonalDownRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_WalkSlowDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_NORTH);
    return MovementAction_WalkSlowUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_WEST);
    return MovementAction_WalkSlowLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_EAST);
    return MovementAction_WalkSlowRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTHWEST, 0);
    return MovementAction_WalkNormalDiagonalUpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTHEAST, 0);
    return MovementAction_WalkNormalDiagonalUpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTHWEST, 0);
    return MovementAction_WalkNormalDiagonalDownLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTHEAST, 0);
    return MovementAction_WalkNormalDiagonalDownRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTH, 0);
    return MovementAction_WalkNormalDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTH, 0);
    return MovementAction_WalkNormalUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 0);
    return MovementAction_WalkNormalLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 0);
    return MovementAction_WalkNormalRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8093FC4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed, u8 a5)
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFBC)];
    s16 x;
    s16 y;

    memcpy(displacements, gUnknown_0850DFBC, sizeof gUnknown_0850DFBC);
    x = 0;
    y = 0;
    SetObjectEventDirection(objectEvent, direction);
    MoveCoordsInDirection(direction, &x, &y, displacements[speed], displacements[speed]);
    ShiftObjectEventCoords(objectEvent, objectEvent->currentCoords.x + x, objectEvent->currentCoords.y + y);
    sub_809783C(sprite, direction, speed, a5);
    sprite->data[2] = 1;
    sprite->animPaused = 0;
    objectEvent->triggerGroundEffectsOnMove = 1;
    objectEvent->disableCoveringGroundEffects = 1;
}

void maybe_shadow_1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(objectEvent, sprite, direction, speed, a4);
    npc_apply_anim_looping(objectEvent, sprite, GetMoveDirectionAnimNum(objectEvent->facingDirection));
    DoShadowFieldEffect(objectEvent);
}

u8 sub_80940C4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 callback(struct Sprite *))
{
    s16 displacements[ARRAY_COUNT(gUnknown_0850DFC2)];
    s16 x;
    s16 y;
    u8 result;

    memcpy(displacements, gUnknown_0850DFC2, sizeof gUnknown_0850DFC2);
    result = callback(sprite);
    if (result == 1 && displacements[sprite->data[4]] != 0)
    {
        x = 0;
        y = 0;
        MoveCoordsInDirection(objectEvent->movementDirection, &x, &y, displacements[sprite->data[4]], displacements[sprite->data[4]]);
        ShiftObjectEventCoords(objectEvent, objectEvent->currentCoords.x + x, objectEvent->currentCoords.y + y);
        objectEvent->triggerGroundEffectsOnMove = TRUE;
        objectEvent->disableCoveringGroundEffects = TRUE;
    }
    else if (result == 0xFF)
    {
        ShiftStillObjectEventCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        objectEvent->landingJump = TRUE;
        sprite->animPaused = TRUE;
    }
    return result;
}

u8 sub_8094188(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return sub_80940C4(objectEvent, sprite, sub_809785C);
}

u8 sub_809419C(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return sub_80940C4(objectEvent, sprite, sub_80978E4);
}

bool8 sub_80941B0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_8094188(objectEvent, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941C8(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_809419C(objectEvent, sprite) == 0xFF)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 sub_80941E0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    switch (sub_8094188(objectEvent, sprite))
    {
        case 255:
            return TRUE;
        case   1:
            SetObjectEventDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
            obj_npc_animation_step(objectEvent, sprite, GetMoveDirectionAnimNum(objectEvent->facingDirection));
        default:
            return FALSE;
    }
}

bool8 MovementAction_Jump2Down_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, 2, 0);
    return MovementAction_Jump2Down_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Down_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Up_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, 2, 0);
    return MovementAction_Jump2Up_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Up_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Left_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, 2, 0);
    return MovementAction_Jump2Left_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Left_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Right_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, 2, 0);
    return MovementAction_Jump2Right_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Right_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}


void sub_8094390(struct Sprite *sprite, u16 duration)
{
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 MovementAction_Delay_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Delay1_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094390(sprite, 1);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay2_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094390(sprite, 2);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay4_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094390(sprite, 4);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay8_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094390(sprite, 8);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay16_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094390(sprite, 16);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_WalkFastDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_WalkFastUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 1);
    return MovementAction_WalkFastLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 1);
    return MovementAction_WalkFastRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}


void sub_8094554(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum, u16 duration)
{
    SetObjectEventDirection(objectEvent, direction);
    npc_apply_anim_looping(objectEvent, sprite, animNum);
    sprite->animPaused = FALSE;
    sprite->data[2] = 1;
    sprite->data[3] = duration;
}

bool8 MovementAction_WalkInPlace_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (-- sprite->data[3] == 0)
    {
        sprite->data[2] = 2;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkInPlaceSlow_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sprite->data[3] & 1)
    {
        sprite->animDelayCounter++;
    }
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_SOUTH, GetMoveDirectionAnimNum(DIR_SOUTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_NORTH, GetMoveDirectionAnimNum(DIR_NORTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_WEST, GetMoveDirectionAnimNum(DIR_WEST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_EAST, GetMoveDirectionAnimNum(DIR_EAST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_SOUTH, GetMoveDirectionAnimNum(DIR_SOUTH), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_NORTH, GetMoveDirectionAnimNum(DIR_NORTH), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_WEST, GetMoveDirectionAnimNum(DIR_WEST), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_EAST, GetMoveDirectionAnimNum(DIR_EAST), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_SOUTH, GetMoveDirectionFastAnimNum(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_NORTH, GetMoveDirectionFastAnimNum(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_WEST, GetMoveDirectionFastAnimNum(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_EAST, GetMoveDirectionFastAnimNum(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastestDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_SOUTH, GetMoveDirectionFasterAnimNum(DIR_SOUTH), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastestUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_NORTH, GetMoveDirectionFasterAnimNum(DIR_NORTH), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastestLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_WEST, GetMoveDirectionFasterAnimNum(DIR_WEST), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastestRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_EAST, GetMoveDirectionFasterAnimNum(DIR_EAST), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTH, 2);
    return MovementAction_RideWaterCurrentDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTH, 2);
    return MovementAction_RideWaterCurrentUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 2);
    return MovementAction_RideWaterCurrentLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 2);
    return MovementAction_RideWaterCurrentRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTH, 3);
    return MovementAction_WalkFastestDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastestDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTH, 3);
    return MovementAction_WalkFastestUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastestUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 3);
    return MovementAction_WalkFastestLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastestLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastestRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 3);
    return MovementAction_WalkFastestRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastestRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_SOUTH, 4);
    return MovementAction_SlideDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_NORTH, 4);
    return MovementAction_SlideUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 4);
    return MovementAction_SlideLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 4);
    return MovementAction_SlideRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_PlayerRunDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_NORTH);
    return MovementAction_PlayerRunUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_WEST);
    return MovementAction_PlayerRunLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_EAST);
    return MovementAction_PlayerRunRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void StartSpriteAnimInDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum)
{
    SetAndStartSpriteAnim(sprite, animNum, 0);
    SetObjectEventDirection(objectEvent, direction);
    sprite->data[2] = 1;
}

bool8 MovementAction_StartAnimInDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, objectEvent->movementDirection, sprite->animNum);
    return FALSE;
}

bool8 MovementAction_WaitSpriteAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8094DE4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    sub_8093FC4(objectEvent, sprite, direction, 1, 0);
    StartSpriteAnim(sprite, GetJumpSpecialDirectionAnimNum(direction));
}

bool8 MovementAction_JumpSpecialDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094DE4(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_JumpSpecialDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941C8(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094DE4(objectEvent, sprite, DIR_NORTH);
    return MovementAction_JumpSpecialUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941C8(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094DE4(objectEvent, sprite, DIR_WEST);
    return MovementAction_JumpSpecialLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941C8(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094DE4(objectEvent, sprite, DIR_EAST);
    return MovementAction_JumpSpecialRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941C8(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_FacePlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0, &playerObjectId))
    {
        FaceDirection(objectEvent, sprite, GetDirectionToFace(objectEvent->currentCoords.x, objectEvent->currentCoords.y, gObjectEvents[playerObjectId].currentCoords.x, gObjectEvents[playerObjectId].currentCoords.y));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_FaceAwayPlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0, &playerObjectId))
    {
        FaceDirection(objectEvent, sprite, GetOppositeDirection(GetDirectionToFace(objectEvent->currentCoords.x, objectEvent->currentCoords.y, gObjectEvents[playerObjectId].currentCoords.x, gObjectEvents[playerObjectId].currentCoords.y)));
    }
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_LockFacingDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->facingDirectionLocked = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_UnlockFacingDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->facingDirectionLocked = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_JumpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, 1, 2);
    return MovementAction_JumpDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, 1, 2);
    return MovementAction_JumpUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, 1, 2);
    return MovementAction_JumpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, 1, 2);
    return MovementAction_JumpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, 0, 0);
    return MovementAction_JumpInPlaceDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, 0, 0);
    return MovementAction_JumpInPlaceUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, 0, 0);
    return MovementAction_JumpInPlaceLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, 0, 0);
    return MovementAction_JumpInPlaceRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDownUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, 0, 2);
    return MovementAction_JumpInPlaceDownUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941E0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, 0, 2);
    return MovementAction_JumpInPlaceUpDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941E0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceLeftRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, 0, 2);
    return MovementAction_JumpInPlaceLeftRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941E0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRightLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, 0, 2);
    return MovementAction_JumpInPlaceRightLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941E0(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_FaceOriginalDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, gInitialMovementTypeFacingDirections[objectEvent->movementType]);
    return TRUE;
}

bool8 MovementAction_NurseJoyBowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, 0x14);
    return FALSE;
}

bool8 MovementAction_EnableJumpLandingGroundEffect_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->disableJumpLandingGroundEffect = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DisableJumpLandingGroundEffect_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->disableJumpLandingGroundEffect = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DisableAnimation_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->inanimate = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_RestoreAnimation_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->inanimate = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->inanimate;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_SetInvisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_SetVisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteExclamationMark_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteQuestionMark_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_QUESTION_MARK_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_EmoteHeart_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_HEART_ICON);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_RevealTrainer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->movementType == MOVEMENT_TYPE_HIDDEN)
    {
        sub_80B4578(objectEvent);
        return FALSE;
    }
    if (objectEvent->movementType != MOVEMENT_TYPE_TREE_DISGUISE && objectEvent->movementType != MOVEMENT_TYPE_MOUNTAIN_DISGUISE)
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    sub_8155D78(objectEvent);
    sprite->data[2] = 1;
    return MovementAction_RevealTrainer_Step1(objectEvent, sprite);
}

bool8 MovementAction_RevealTrainer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_8155DA0(objectEvent))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        SetMovementDelay(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible ^= TRUE;
    if (WaitForMovementDelay(sprite))
    {
        objectEvent->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 MovementAction_CutTree_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->data[2] = 1;
    return FALSE;
}

bool8 MovementAction_CutTree_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        SetMovementDelay(sprite, 32);
        sprite->data[2] = 2;
    }
    return FALSE;
}

bool8 MovementAction_CutTree_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible ^= TRUE;
    if (WaitForMovementDelay(sprite))
    {
        objectEvent->invisible = TRUE;
        sprite->data[2] = 3;
    }
    return FALSE;
}

bool8 MovementAction_SetFixedPriority_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->fixedPriority = TRUE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_ClearFixedPriority_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->fixedPriority = FALSE;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_InitAffineAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sprite->affineAnimPaused = TRUE;
    sprite->subspriteMode = SUBSPRITES_OFF;
    return TRUE;
}

bool8 MovementAction_ClearAffineAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FreeOamMatrix(sprite->oam.matrixNum);
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    return TRUE;
}

bool8 MovementAction_HideReflection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->hideReflection = TRUE;
    return TRUE;
}

bool8 MovementAction_ShowReflection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->hideReflection = FALSE;
    return TRUE;
}

bool8 MovementAction_WalkDownStartAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    StartSpriteAffineAnimIfDifferent(sprite, 0);
    return MovementAction_WalkDownStartAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkDownStartAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkDownAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8093B60(objectEvent, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 1);
    return MovementAction_WalkDownAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkDownAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (an_walk_any_2(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkLeftAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_WEST, 1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 2);
    return MovementAction_WalkLeftAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkLeftAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkRightAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    do_go_anim(objectEvent, sprite, DIR_EAST, 1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 3);
    return MovementAction_WalkRightAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkRightAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

static void sub_80958C0(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    SetObjectEventDirection(objectEvent, direction);
    ShiftStillObjectEventCoords(objectEvent);
    obj_npc_animation_step(objectEvent, sprite, GetAcroWheeliePedalDirectionAnimNum(direction));
    sprite->animPaused = TRUE;
    sprite->data[2] = 1;
}

bool8 MovementAction_AcroWheelieFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80958C0(objectEvent, sprite, DIR_SOUTH);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80958C0(objectEvent, sprite, DIR_NORTH);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80958C0(objectEvent, sprite, DIR_WEST);
    return TRUE;
}

bool8 MovementAction_AcroWheelieFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80958C0(objectEvent, sprite, DIR_EAST);
    return TRUE;
}

bool8 MovementAction_AcroPopWheelieDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetAcroWheelieDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetAcroWheelieDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetAcroWheelieDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetAcroWheelieDirectionAnimNum(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetAcroEndWheelieDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetAcroEndWheelieDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetAcroEndWheelieDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetAcroEndWheelieDirectionAnimNum(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetAcroUnusedActionDirectionAnimNum(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetAcroUnusedActionDirectionAnimNum(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetAcroUnusedActionDirectionAnimNum(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetAcroUnusedActionDirectionAnimNum(DIR_EAST));
    return FALSE;
}

void InitFigure8Anim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitSpriteForFigure8Anim(sprite);
    sprite->animPaused = FALSE;
}

bool8 DoFigure8Anim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (AnimateSpriteInFigure8(sprite))
    {
        ShiftStillObjectEventCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Figure8_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitFigure8Anim(objectEvent, sprite);
    sprite->data[2] = 1;
    return MovementAction_Figure8_Step1(objectEvent, sprite);
}

bool8 MovementAction_Figure8_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoFigure8Anim(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8095B84(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed, u8 a4)
{
    sub_8093FC4(objectEvent, sprite, direction, speed, a4);
    StartSpriteAnimIfDifferent(sprite, GetAcroWheelieDirectionAnimNum(direction));
    DoShadowFieldEffect(objectEvent);
}

bool8 MovementAction_AcroWheelieHopFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_SOUTH, 0, 1);
    return MovementAction_AcroWheelieHopFaceDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_NORTH, 0, 1);
    return MovementAction_AcroWheelieHopFaceUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_WEST,  0, 1);
    return MovementAction_AcroWheelieHopFaceLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_EAST,  0, 1);
    return MovementAction_AcroWheelieHopFaceRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_SOUTH, 1, 1);
    return MovementAction_AcroWheelieHopDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_NORTH, 1, 1);
    return MovementAction_AcroWheelieHopUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_WEST,  1, 1);
    return MovementAction_AcroWheelieHopLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_EAST,  1, 1);
    return MovementAction_AcroWheelieHopRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_SOUTH, 2, 0);
    return MovementAction_AcroWheelieJumpDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_NORTH, 2, 0);
    return MovementAction_AcroWheelieJumpUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_WEST,  2, 0);
    return MovementAction_AcroWheelieJumpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8095B84(objectEvent, sprite, DIR_EAST,  2, 0);
    return MovementAction_AcroWheelieJumpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_80941B0(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieInPlaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_SOUTH, GetAcroWheeliePedalDirectionAnimNum(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_NORTH, GetAcroWheeliePedalDirectionAnimNum(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_WEST, GetAcroWheeliePedalDirectionAnimNum(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8094554(objectEvent, sprite, DIR_EAST, GetAcroWheeliePedalDirectionAnimNum(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

void sub_80960C8(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    StartSpriteAnim(sprite, GetAcroWheelieDirectionAnimNum(objectEvent->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80960C8(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroPopWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80960C8(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroPopWheelieMoveUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80960C8(objectEvent, sprite, DIR_WEST,  1);
    return MovementAction_AcroPopWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_80960C8(objectEvent, sprite, DIR_EAST,  1);
    return MovementAction_AcroPopWheelieMoveRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8096200(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    npc_apply_anim_looping(objectEvent, sprite, GetAcroWheeliePedalDirectionAnimNum(objectEvent->facingDirection));
}

bool8 MovementAction_AcroWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096200(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096200(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroWheelieMoveUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096200(objectEvent, sprite, DIR_WEST,  1);
    return MovementAction_AcroWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096200(objectEvent, sprite, DIR_EAST, 1);
    return MovementAction_AcroWheelieMoveRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_8096330(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    StartSpriteAnim(sprite, GetAcroEndWheelieDirectionAnimNum(objectEvent->facingDirection));
    SeekSpriteAnim(sprite, 0);
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096330(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroEndWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096330(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroEndWheelieMoveUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096330(objectEvent, sprite, DIR_WEST, 1);
    return MovementAction_AcroEndWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096330(objectEvent, sprite, DIR_EAST, 1);
    return MovementAction_AcroEndWheelieMoveRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (npc_obj_ministep_stop_on_arrival(objectEvent, sprite))
    {
        sprite->data[2] = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Levitate_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    CreateLevitateMovementTask(objectEvent);
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_StopLevitate_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    DestroyExtraMovementTask(objectEvent->warpArrowSpriteId);
    sprite->pos2.y = 0;
    sprite->data[2] = 1;
    return TRUE;
}

bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sprite->pos2.y == 0)
    {
        DestroyExtraMovementTask(objectEvent->warpArrowSpriteId);
        sprite->data[2] = 1;
        return TRUE;
    }
    return FALSE;
}

u8 MovementAction_Finish(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return TRUE;
}

bool8 MovementAction_PauseSpriteAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    return TRUE;
}

static void UpdateObjectEventSpriteAnimPause(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->disableAnim)
    {
        sprite->animPaused = TRUE;
    }
}

static void TryEnableObjectEventAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->enableAnim)
    {
        sprite->animPaused = FALSE;
        objectEvent->disableAnim = FALSE;
        objectEvent->enableAnim = FALSE;
    }
}

static void UpdateObjectEventVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_8096530(objectEvent, sprite);
    UpdateObjEventSpriteVisibility(objectEvent, sprite);
}

static void sub_8096530(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u16 x, y;
    u16 x2, y2;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    objectEvent->offScreen = FALSE;
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    if (sprite->coordOffsetEnabled)
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    }
    x2 = graphicsInfo->width;
    x2 += x;
    y2 = y;
    y2 += graphicsInfo->height;
    if ((s16)x >= 0x100 || (s16)x2 < -0x10)
    {
        objectEvent->offScreen = TRUE;
    }
    if ((s16)y >= 0xB0 || (s16)y2 < -0x10)
    {
        objectEvent->offScreen = TRUE;
    }
}

static void UpdateObjEventSpriteVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (objectEvent->invisible || objectEvent->offScreen)
    {
        sprite->invisible = TRUE;
    }
}

static void GetAllGroundEffectFlags_OnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    ObjectEventUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_Reflection(objEvent, flags);
    GetGroundEffectFlags_TallGrassOnSpawn(objEvent, flags);
    GetGroundEffectFlags_LongGrassOnSpawn(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
}

static void GetAllGroundEffectFlags_OnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    ObjectEventUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_Reflection(objEvent, flags);
    GetGroundEffectFlags_TallGrassOnBeginStep(objEvent, flags);
    GetGroundEffectFlags_LongGrassOnBeginStep(objEvent, flags);
    GetGroundEffectFlags_Tracks(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_Puddle(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
}

static void GetAllGroundEffectFlags_OnFinishStep(struct ObjectEvent *objEvent, u32 *flags)
{
    ObjectEventUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_Puddle(objEvent, flags);
    GetGroundEffectFlags_Ripple(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
    GetGroundEffectFlags_Seaweed(objEvent, flags);
    GetGroundEffectFlags_JumpLanding(objEvent, flags);
}

static void ObjectEventUpdateMetatileBehaviors(struct ObjectEvent *objEvent)
{
    objEvent->previousMetatileBehavior = MapGridGetMetatileBehaviorAt(objEvent->previousCoords.x, objEvent->previousCoords.y);
    objEvent->currentMetatileBehavior = MapGridGetMetatileBehaviorAt(objEvent->currentCoords.x, objEvent->currentCoords.y);
}

static void GetGroundEffectFlags_Reflection(struct ObjectEvent *objEvent, u32 *flags)
{
    u32 reflectionFlags[2] = { GROUND_EFFECT_FLAG_REFLECTION, GROUND_EFFECT_FLAG_ICE_REFLECTION };
    u8 type = ObjectEventCheckForReflectiveSurface(objEvent);

    if (type)
    {
        if (!objEvent->hasReflection)
        {
            objEvent->hasReflection = 0;
            objEvent->hasReflection = 1;
            *flags |= reflectionFlags[type - 1];
        }
    }
    else
    {
        objEvent->hasReflection = 0;
    }
}

static void GetGroundEffectFlags_TallGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_TallGrassOnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_LongGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN;
}

static void GetGroundEffectFlags_LongGrassOnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE;
}

static void GetGroundEffectFlags_Tracks(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(objEvent->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_DEEP_SAND;
    }
    else if (MetatileBehavior_IsSandOrDeepSand(objEvent->previousMetatileBehavior)
             || MetatileBehavior_IsFootprints(objEvent->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_SAND;
    }
}

static void GetGroundEffectFlags_SandHeap(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsDeepSand(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inSandPile)
        {
            objEvent->inSandPile = 0;
            objEvent->inSandPile = 1;
            *flags |= GROUND_EFFECT_FLAG_SAND_PILE;
        }
    }
    else
    {
        objEvent->inSandPile = 0;
    }
}

static void GetGroundEffectFlags_ShallowFlowingWater(struct ObjectEvent *objEvent, u32 *flags)
{
    if ((MetatileBehavior_IsShallowFlowingWater(objEvent->currentMetatileBehavior)
         && MetatileBehavior_IsShallowFlowingWater(objEvent->previousMetatileBehavior))
        || (MetatileBehavior_IsPacifidlogLog(objEvent->currentMetatileBehavior)
            && MetatileBehavior_IsPacifidlogLog(objEvent->previousMetatileBehavior)))
    {
        if (!objEvent->inShallowFlowingWater)
        {
            objEvent->inShallowFlowingWater = 0;
            objEvent->inShallowFlowingWater = 1;
            *flags |= GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER;
        }
    }
    else
    {
        objEvent->inShallowFlowingWater = 0;
    }
}

static void GetGroundEffectFlags_Puddle(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsPuddle(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsPuddle(objEvent->previousMetatileBehavior))
    {
        *flags |= GROUND_EFFECT_FLAG_PUDDLE;
    }
}

static void GetGroundEffectFlags_Ripple(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_HasRipples(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_RIPPLES;
}

static void GetGroundEffectFlags_ShortGrass(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsShortGrass(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsShortGrass(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inShortGrass)
        {
            objEvent->inShortGrass = 0;
            objEvent->inShortGrass = 1;
            *flags |= GROUND_EFFECT_FLAG_SHORT_GRASS;
        }
    }
    else
    {
        objEvent->inShortGrass = 0;
    }
}

static void GetGroundEffectFlags_HotSprings(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsHotSprings(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsHotSprings(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inHotSprings)
        {
            objEvent->inHotSprings = 0;
            objEvent->inHotSprings = 1;
            *flags |= GROUND_EFFECT_FLAG_HOT_SPRINGS;
        }
    }
    else
    {
        objEvent->inHotSprings = 0;
    }
}

static void GetGroundEffectFlags_Seaweed(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsSeaweed(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_SEAWEED;
}

static void GetGroundEffectFlags_JumpLanding(struct ObjectEvent *objEvent, u32 *flags)
{
    typedef bool8 (*MetatileFunc)(u8);

    static const MetatileFunc metatileFuncs[] = {
        MetatileBehavior_IsTallGrass,
        MetatileBehavior_IsLongGrass,
        MetatileBehavior_IsPuddle,
        MetatileBehavior_IsSurfableWaterOrUnderwater,
        MetatileBehavior_IsShallowFlowingWater,
        MetatileBehavior_IsATile,
    };

    static const u32 jumpLandingFlags[] = {
        GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS,
        GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS,
        GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER,
        GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER,
        GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER,
        GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND,
    };

    if (objEvent->landingJump && !objEvent->disableJumpLandingGroundEffect)
    {
        u8 i;

        for (i = 0; i < ARRAY_COUNT(metatileFuncs); i++)
        {
            if (metatileFuncs[i](objEvent->currentMetatileBehavior))
            {
                *flags |= jumpLandingFlags[i];
                return;
            }
        }
    }
}

static u8 ObjectEventCheckForReflectiveSurface(struct ObjectEvent *objEvent)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objEvent->graphicsId);

    // ceil div by tile width?
    s16 width = (info->width + 8) >> 4;
    s16 height = (info->height + 8) >> 4;
    s16 i;
    s16 j;
    u8 result;
    u8 b;
    s16 one;

#define RETURN_REFLECTION_TYPE_AT(x, y)              \
    b = MapGridGetMetatileBehaviorAt(x, y);          \
    result = GetReflectionTypeByMetatileBehavior(b); \
    if (result != 0)                                 \
        return result;

    for (i = 0, one = 1; i < height; i++)
    {
        RETURN_REFLECTION_TYPE_AT(objEvent->currentCoords.x, objEvent->currentCoords.y + one + i)
        RETURN_REFLECTION_TYPE_AT(objEvent->previousCoords.x, objEvent->previousCoords.y + one + i)
        for (j = 1; j < width; j++)
        {
            RETURN_REFLECTION_TYPE_AT(objEvent->currentCoords.x + j, objEvent->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objEvent->currentCoords.x - j, objEvent->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objEvent->previousCoords.x + j, objEvent->previousCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objEvent->previousCoords.x - j, objEvent->previousCoords.y + one + i)
        }
    }
    return 0;

#undef RETURN_REFLECTION_TYPE_AT
}

static u8 GetReflectionTypeByMetatileBehavior(u32 behavior)
{
    if (MetatileBehavior_IsIce(behavior))
        return 1;
    else if (MetatileBehavior_IsReflective(behavior))
        return 2;
    else
        return 0;
}

u8 GetLedgeJumpDirection(s16 x, s16 y, u8 z)
{
    static bool8 (*const unknown_08376040[])(u8) = {
        MetatileBehavior_IsJumpSouth,
        MetatileBehavior_IsJumpNorth,
        MetatileBehavior_IsJumpWest,
        MetatileBehavior_IsJumpEast,
    };

    u8 b;
    u8 index = z;

    if (index == 0)
        return 0;
    else if (index > 4)
        index -= 4;

    index--;
    b = MapGridGetMetatileBehaviorAt(x, y);

    if (unknown_08376040[index](b) == 1)
        return index + 1;

    return 0;
}

static void SetObjectEventSpriteOamTableForLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    if (objEvent->disableCoveringGroundEffects)
        return;

    if (!MetatileBehavior_IsLongGrass(objEvent->currentMetatileBehavior))
        return;

    if (!MetatileBehavior_IsLongGrass(objEvent->previousMetatileBehavior))
        return;

    sprite->subspriteTableNum = 4;

    if (ZCoordToPriority(objEvent->previousElevation) == 1)
        sprite->subspriteTableNum = 5;
}

bool8 IsZCoordMismatchAt(u8 z, s16 x, s16 y)
{
    u8 mapZ;

    if (z == 0)
        return FALSE;

    mapZ = MapGridGetZCoordAt(x, y);

    if (mapZ == 0 || mapZ == 0xF)
        return FALSE;

    if (mapZ != z)
        return TRUE;

    return FALSE;
}

static const u8 sUnknown_08376050[] = {
    0x73, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x73, 0x53, 0x00, 0x00, 0x73
};

// Each byte corresponds to a sprite priority for an object event.
// This is directly the inverse of gObjectEventPriorities_08376070.
static const u8 sObjectEventPriorities_08376060[] = {
    2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 0, 2
};

// Each byte corresponds to a sprite priority for an object event.
// This is the inverse of gObjectEventPriorities_08376060.
// 1 = Above player sprite
// 2 = Below player sprite
static const u8 sObjectEventPriorities_08376070[] = {
    1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 1,
};

void UpdateObjectEventZCoordAndPriority(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    if (objEvent->fixedPriority)
        return;

    ObjectEventUpdateZCoord(objEvent);

    sprite->subspriteTableNum = sObjectEventPriorities_08376070[objEvent->previousElevation];
    sprite->oam.priority = sObjectEventPriorities_08376060[objEvent->previousElevation];
}

static void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 z)
{
    sprite->subspriteTableNum = sObjectEventPriorities_08376070[z];
    sprite->oam.priority = sObjectEventPriorities_08376060[z];
}

u8 ZCoordToPriority(u8 z)
{
    return sObjectEventPriorities_08376060[z];
}

void ObjectEventUpdateZCoord(struct ObjectEvent *objEvent)
{
    u8 z = MapGridGetZCoordAt(objEvent->currentCoords.x, objEvent->currentCoords.y);
    u8 z2 = MapGridGetZCoordAt(objEvent->previousCoords.x, objEvent->previousCoords.y);

    if (z == 0xF || z2 == 0xF)
        return;

    objEvent->currentElevation = z;

    if (z != 0 && z != 0xF)
        objEvent->previousElevation = z;
}

void SetObjectSubpriorityByZCoord(u8 a, struct Sprite *sprite, u8 b)
{
    s32 tmp = sprite->centerToCornerVecY;
    u32 tmpa = *(u16 *)&sprite->pos1.y;
    u32 tmpb = *(u16 *)&gSpriteCoordOffsetY;
    s32 tmp2 = (tmpa - tmp) + tmpb;
    u16 tmp3 = (0x10 - ((((u32)tmp2 + 8) & 0xFF) >> 4)) * 2;
    sprite->subpriority = tmp3 + sUnknown_08376050[a] + b;
}

static void ObjectEventUpdateSubpriority(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    if (objEvent->fixedPriority)
        return;

    SetObjectSubpriorityByZCoord(objEvent->previousElevation, sprite, 1);
}

bool8 AreZCoordsCompatible(u8 a, u8 b)
{
    if (a == 0 || b == 0)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
}

void GroundEffect_SpawnOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_StepOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_SpawnOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_StepOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = (objEvent->localId << 8) | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_WaterReflection(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    SetUpReflection(objEvent, sprite, 0);
}

void GroundEffect_IceReflection(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    SetUpReflection(objEvent, sprite, 1);
}

void GroundEffect_FlowingWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_FEET_IN_FLOWING_WATER, objEvent);
}

static void (*const sGroundEffectTracksFuncs[])(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 a) = {
    DoTracksGroundEffect_None,
    DoTracksGroundEffect_Footprints,
    DoTracksGroundEffect_BikeTireTracks,
};

void GroundEffect_SandTracks(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objEvent->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](objEvent, sprite, 0);
}

void GroundEffect_DeepSandTracks(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objEvent->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](objEvent, sprite, 1);
}

static void DoTracksGroundEffect_None(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 a)
{
}

static void DoTracksGroundEffect_Footprints(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 a)
{
    // First half-word is a Field Effect script id. (gFieldEffectScriptPointers)
    u16 sandFootprints_FieldEffectData[2] = {
        FLDEFF_SAND_FOOTPRINTS,
        FLDEFF_DEEP_SAND_FOOTPRINTS
    };

    gFieldEffectArguments[0] = objEvent->previousCoords.x;
    gFieldEffectArguments[1] = objEvent->previousCoords.y;
    gFieldEffectArguments[2] = 149;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objEvent->facingDirection;
    FieldEffectStart(sandFootprints_FieldEffectData[a]);
}

static void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 a)
{
    //  Specifies which bike track shape to show next.
    //  For example, when the bike turns from up to right, it will show
    //  a track that curves to the right.
    //  Each 4-byte row corresponds to the initial direction of the bike, and
    //  each byte in that row is for the next direction of the bike in the order
    //  of down, up, left, right.
    static const u8 bikeTireTracks_Transitions[4][4] = {
        1, 2, 7, 8,
        1, 2, 6, 5,
        5, 8, 3, 4,
        6, 7, 3, 4,
    };

    if (objEvent->currentCoords.x != objEvent->previousCoords.x || objEvent->currentCoords.y != objEvent->previousCoords.y)
    {
        gFieldEffectArguments[0] = objEvent->previousCoords.x;
        gFieldEffectArguments[1] = objEvent->previousCoords.y;
        gFieldEffectArguments[2] = 149;
        gFieldEffectArguments[3] = 2;
        gFieldEffectArguments[4] =
            bikeTireTracks_Transitions[objEvent->previousMovementDirection][objEvent->facingDirection - 5];
        FieldEffectStart(FLDEFF_BIKE_TIRE_TRACKS);
    }
}

void GroundEffect_Ripple(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    DoRippleFieldEffect(objEvent, sprite);
}

void GroundEffect_StepOnPuddle(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SPLASH, objEvent);
}

void GroundEffect_SandHeap(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SAND_PILE, objEvent);
}

void GroundEffect_JumpOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    u8 spriteId;

    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_TALL_GRASS);

    spriteId = FindTallGrassFieldEffectSpriteId(
        objEvent->localId,
        objEvent->mapNum,
        objEvent->mapGroup,
        objEvent->currentCoords.x,
        objEvent->currentCoords.y);

    if (spriteId == MAX_SPRITES)
        GroundEffect_SpawnOnTallGrass(objEvent, sprite);
}

void GroundEffect_JumpOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_LONG_GRASS);
}

void GroundEffect_JumpOnShallowWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_SMALL_SPLASH);
}

void GroundEffect_JumpOnWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
}

void GroundEffect_JumpLandingDust(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_DUST);
}

void GroundEffect_ShortGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SHORT_GRASS, objEvent);
}

void GroundEffect_HotSprings(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_HOT_SPRINGS_WATER, objEvent);
}

void GroundEffect_Seaweed(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    FieldEffectStart(FLDEFF_BUBBLES);
}

static void (*const sGroundEffectFuncs[])(struct ObjectEvent *objEvent, struct Sprite *sprite) = {
    GroundEffect_SpawnOnTallGrass,      // GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN
    GroundEffect_StepOnTallGrass,       // GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE
    GroundEffect_SpawnOnLongGrass,      // GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN
    GroundEffect_StepOnLongGrass,       // GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE
    GroundEffect_WaterReflection,       // GROUND_EFFECT_FLAG_ICE_REFLECTION
    GroundEffect_IceReflection,         // GROUND_EFFECT_FLAG_REFLECTION
    GroundEffect_FlowingWater,          // GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER
    GroundEffect_SandTracks,            // GROUND_EFFECT_FLAG_SAND
    GroundEffect_DeepSandTracks,        // GROUND_EFFECT_FLAG_DEEP_SAND
    GroundEffect_Ripple,                // GROUND_EFFECT_FLAG_RIPPLES
    GroundEffect_StepOnPuddle,          // GROUND_EFFECT_FLAG_PUDDLE
    GroundEffect_SandHeap,              // GROUND_EFFECT_FLAG_SAND_PILE
    GroundEffect_JumpOnTallGrass,       // GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS
    GroundEffect_JumpOnLongGrass,       // GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS
    GroundEffect_JumpOnShallowWater,    // GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER
    GroundEffect_JumpOnWater,           // GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER
    GroundEffect_JumpLandingDust,       // GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND
    GroundEffect_ShortGrass,            // GROUND_EFFECT_FLAG_SHORT_GRASS
    GroundEffect_HotSprings,            // GROUND_EFFECT_FLAG_HOT_SPRINGS
    GroundEffect_Seaweed                // GROUND_EFFECT_FLAG_SEAWEED
};

static void DoFlaggedGroundEffects(struct ObjectEvent *objEvent, struct Sprite *sprite, u32 flags)
{
    u8 i;

    if (ObjectEventIsFarawayIslandMew(objEvent) == TRUE && !ShouldMewShakeGrass(objEvent))
        return;

    for (i = 0; i < ARRAY_COUNT(sGroundEffectFuncs); i++, flags >>= 1)
        if (flags & 1)
            sGroundEffectFuncs[i](objEvent, sprite);
}

void filters_out_some_ground_effects(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->disableCoveringGroundEffects)
    {
        objEvent->inShortGrass = 0;
        objEvent->inSandPile = 0;
        objEvent->inShallowFlowingWater = 0;
        objEvent->inHotSprings = 0;
        *flags &= ~(GROUND_EFFECT_FLAG_HOT_SPRINGS
                  | GROUND_EFFECT_FLAG_SHORT_GRASS
                  | GROUND_EFFECT_FLAG_SAND_PILE
                  | GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER
                  | GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE);
    }
}

void FilterOutStepOnPuddleGroundEffectIfJumping(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->landingJump)
        *flags &= ~GROUND_EFFECT_FLAG_PUDDLE;
}

static void DoGroundEffects_OnSpawn(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objEvent->triggerGroundEffectsOnMove)
    {
        flags = 0;
        UpdateObjectEventZCoordAndPriority(objEvent, sprite);
        GetAllGroundEffectFlags_OnSpawn(objEvent, &flags);
        SetObjectEventSpriteOamTableForLongGrass(objEvent, sprite);
        DoFlaggedGroundEffects(objEvent, sprite, flags);
        objEvent->triggerGroundEffectsOnMove = 0;
        objEvent->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnBeginStep(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objEvent->triggerGroundEffectsOnMove)
    {
        flags = 0;
        UpdateObjectEventZCoordAndPriority(objEvent, sprite);
        GetAllGroundEffectFlags_OnBeginStep(objEvent, &flags);
        SetObjectEventSpriteOamTableForLongGrass(objEvent, sprite);
        filters_out_some_ground_effects(objEvent, &flags);
        DoFlaggedGroundEffects(objEvent, sprite, flags);
        objEvent->triggerGroundEffectsOnMove = 0;
        objEvent->disableCoveringGroundEffects = 0;
    }
}

static void DoGroundEffects_OnFinishStep(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objEvent->triggerGroundEffectsOnStop)
    {
        flags = 0;
        UpdateObjectEventZCoordAndPriority(objEvent, sprite);
        GetAllGroundEffectFlags_OnFinishStep(objEvent, &flags);
        SetObjectEventSpriteOamTableForLongGrass(objEvent, sprite);
        FilterOutStepOnPuddleGroundEffectIfJumping(objEvent, &flags);
        DoFlaggedGroundEffects(objEvent, sprite, flags);
        objEvent->triggerGroundEffectsOnStop = 0;
        objEvent->landingJump = 0;
    }
}

bool8 FreezeObjectEvent(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive || objectEvent->frozen)
    {
        return TRUE;
    }
    else
    {
        objectEvent->frozen = 1;
        objectEvent->spriteAnimPausedBackup = gSprites[objectEvent->spriteId].animPaused;
        objectEvent->spriteAffineAnimPausedBackup = gSprites[objectEvent->spriteId].affineAnimPaused;
        gSprites[objectEvent->spriteId].animPaused = 1;
        gSprites[objectEvent->spriteId].affineAnimPaused = 1;
        return FALSE;
    }
}

void FreezeObjectEvents(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
            FreezeObjectEvent(&gObjectEvents[i]);
}

void FreezeObjectEventsExceptOne(u8 objectEventId)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (i != objectEventId && gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
            FreezeObjectEvent(&gObjectEvents[i]);
}

void UnfreezeObjectEvent(struct ObjectEvent *objectEvent)
{
    if (objectEvent->active && objectEvent->frozen)
    {
        objectEvent->frozen = 0;
        gSprites[objectEvent->spriteId].animPaused = objectEvent->spriteAnimPausedBackup;
        gSprites[objectEvent->spriteId].affineAnimPaused = objectEvent->spriteAffineAnimPausedBackup;
    }
}

void UnfreezeObjectEvents(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (gObjectEvents[i].active)
            UnfreezeObjectEvent(&gObjectEvents[i]);
}

static void Step1(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += sDirectionToVectors[dir].x;
    sprite->pos1.y += sDirectionToVectors[dir].y;
}

static void Step2(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) sDirectionToVectors[dir].y;
}

static void Step3(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 2 * (u16) sDirectionToVectors[dir].x + (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 2 * (u16) sDirectionToVectors[dir].y + (u16) sDirectionToVectors[dir].y;
}

static void Step4(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 4 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 4 * (u16) sDirectionToVectors[dir].y;
}

static void Step8(struct Sprite *sprite, u8 dir)
{
    sprite->pos1.x += 8 * (u16) sDirectionToVectors[dir].x;
    sprite->pos1.y += 8 * (u16) sDirectionToVectors[dir].y;
}

static void oamt_npc_ministep_reset(struct Sprite *sprite, u8 direction, u8 a3)
{
    sprite->data[3] = direction;
    sprite->data[4] = a3;
    sprite->data[5] = 0;
}

typedef void (*SpriteStepFunc)(struct Sprite *sprite, u8 direction);

static const SpriteStepFunc gUnknown_0850E6C4[] = {
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
    Step1,
};

static const SpriteStepFunc gUnknown_0850E704[] = {
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
    Step2,
};

static const SpriteStepFunc gUnknown_0850E724[] = {
    Step2,
    Step3,
    Step3,
    Step2,
    Step3,
    Step3,
};

static const SpriteStepFunc gUnknown_0850E73C[] = {
    Step4,
    Step4,
    Step4,
    Step4,
};

static const SpriteStepFunc gUnknown_0850E74C[] = {
    Step8,
    Step8,
};

static const SpriteStepFunc *const gUnknown_0850E754[] = {
    gUnknown_0850E6C4,
    gUnknown_0850E704,
    gUnknown_0850E724,
    gUnknown_0850E73C,
    gUnknown_0850E74C,
};

static const s16 gUnknown_0850E768[] = {
    16, 8, 6, 4, 2
};

bool8 obj_npc_ministep(struct Sprite *sprite)
{
    if (sprite->data[5] >= gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    gUnknown_0850E754[sprite->data[4]][sprite->data[5]](sprite, sprite->data[3]);

    sprite->data[5]++;

    if (sprite->data[5] < gUnknown_0850E768[sprite->data[4]])
        return FALSE;

    return TRUE;
}

void sub_80976DC(struct Sprite *sprite, u8 direction)
{
    sprite->data[3] = direction;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

bool8 sub_80976EC(struct Sprite *sprite)
{
    if (!(sprite->data[4] & 1))
    {
        Step1(sprite, sprite->data[3]);
        sprite->data[5]++;
    }

    sprite->data[4]++;

    if (sprite->data[5] > 15)
        return TRUE;
    else
        return FALSE;
}

static const s8 sFigure8XOffsets[FIGURE_8_LENGTH] = {
    1, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 1, 2, 2, 1, 2,
    2, 1, 2, 2, 1, 2, 1, 1,
    2, 1, 1, 2, 1, 1, 2, 1,
    1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 0,
    1, 0, 1, 0, 1, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
};

static const s8 sFigure8YOffsets[FIGURE_8_LENGTH] = {
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  1,  1,  0,  1,  1,  0,
     1,  1,  0,  1,  1,  0,  1,  1,
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0, -1,  0,  0, -1,  0,  0,
    -1,  0, -1, -1,  0, -1, -1,  0,
    -1, -1, -1, -1, -1, -1, -1, -2,
};

s16 GetFigure8YOffset(s16 idx)
{
    return sFigure8YOffsets[idx];
}

s16 GetFigure8XOffset(s16 idx)
{
    return sFigure8XOffsets[idx];
}

static void InitSpriteForFigure8Anim(struct Sprite *sprite)
{
    sprite->data[6] = 0;
    sprite->data[7] = 0;
}

static bool8 AnimateSpriteInFigure8(struct Sprite *sprite)
{
    bool8 finished = FALSE;

    switch(sprite->data[7])
    {
    case 0:
        sprite->pos2.x += GetFigure8XOffset(sprite->data[6]);
        sprite->pos2.y += GetFigure8YOffset(sprite->data[6]);
        break;
    case 1:
        sprite->pos2.x -= GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        sprite->pos2.y += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        break;
    case 2:
        sprite->pos2.x -= GetFigure8XOffset(sprite->data[6]);
        sprite->pos2.y += GetFigure8YOffset(sprite->data[6]);
        break;
    case 3:
        sprite->pos2.x += GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        sprite->pos2.y += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        break;
    }
    if (++sprite->data[6] == FIGURE_8_LENGTH)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
    }
    if (sprite->data[7] == 4)
    {
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;
        finished = TRUE;
    }
    return finished;
}

static const s8 gUnknown_0850E802[] = {
    -4,  -6,  -8, -10, -11, -12, -12, -12, -11, -10,  -9,  -8,  -6,  -4,   0,   0
};

static const s8 gUnknown_0850E812[] = {
    0,  -2,  -3,  -4,  -5,  -6,  -6,  -6,  -5,  -5,  -4,  -3,  -2,   0,   0,   0
};

static const s8 gUnknown_0850E822[] = {
    -2,  -4,  -6,  -8,  -9, -10, -10, -10,  -9,  -8,  -6,  -5,  -3,  -2,   0,   0
};

static const s8 *const gUnknown_0850E834[] = {
    gUnknown_0850E802,
    gUnknown_0850E812,
    gUnknown_0850E822
};

s16 sub_8097820(s16 a1, u8 a2)
{
    return gUnknown_0850E834[a2][a1];
}

void sub_809783C(struct Sprite *sprite, u8 a2, u8 a3, u8 a4)
{
    sprite->data[3] = a2;
    sprite->data[4] = a3;
    sprite->data[5] = a4;
    sprite->data[6] = 0;
}

u8 sub_809785C(struct Sprite *sprite)
{
    s16 v5[] = {16, 16, 32};
    u8 v6[] = {0, 0, 1};
    u8 v2 = 0;

    if (sprite->data[4])
        Step1(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

u8 sub_80978E4(struct Sprite *sprite)
{
    s16 v5[] = {32, 32, 64};
    u8 v6[] = {1, 1, 2};
    u8 v2 = 0;

    if (sprite->data[4] && !(sprite->data[6] & 1))
        Step1(sprite, sprite->data[3]);

    sprite->pos2.y = sub_8097820(sprite->data[6] >> v6[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == (v5[sprite->data[4]] >> 1))
        v2 = 1;

    if (sprite->data[6] >= v5[sprite->data[4]])
    {
        sprite->pos2.y = 0;
        v2 = -1;
    }

    return v2;
}

static void SetMovementDelay(struct Sprite *sprite, s16 timer)
{
    sprite->data[3] = timer;
}

static bool8 WaitForMovementDelay(struct Sprite *sprite)
{
    sprite->data[3]--;

    if (sprite->data[3] == 0)
        return TRUE;
    else
        return FALSE;
}

void SetAndStartSpriteAnim(struct Sprite *sprite, u8 animNum, u8 animCmdIndex)
{
    sprite->animNum = animNum;
    sprite->animPaused = FALSE;
    SeekSpriteAnim(sprite, animCmdIndex);
}

bool8 SpriteAnimEnded(struct Sprite *sprite)
{
    if (sprite->animEnded)
        return TRUE;
    else
        return FALSE;
}

void UpdateObjectEventSpriteVisibility(struct Sprite *sprite, bool8 invisible)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = invisible;

    if (sprite->coordOffsetEnabled)
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->pos1.x + sprite->pos2.x + sprite->centerToCornerVecX;
        y = sprite->pos1.y + sprite->pos2.y + sprite->centerToCornerVecY;
    }

    x2 = x - (sprite->centerToCornerVecX >> 1);
    y2 = y - (sprite->centerToCornerVecY >> 1);

    if ((s16)x > 255 || x2 < -16)
        sprite->invisible = TRUE;
    if ((s16)y > 175 || y2 < -16)
        sprite->invisible = TRUE;
}

#define tInvisible     data[2]
#define tAnimNum       data[3]
#define tAnimState     data[4]

static void UpdateObjectEventSprite(struct Sprite *sprite)
{
    UpdateObjectEventSpritePosition(sprite);
    SetObjectSubpriorityByZCoord(sprite->data[1], sprite, 1);
    UpdateObjectEventSpriteVisibility(sprite, sprite->tInvisible);
}

// Unused
static void DestroyObjectEventSprites(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == UpdateObjectEventSprite)
            DestroySprite(sprite);
    }
}

static int GetObjectEventSpriteId(u8 var) // this should return a u8, because all that call this shifts to u8, but it wont match because it doesnt shift u8 at the end.
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == UpdateObjectEventSprite && (u8)sprite->data[0] == var)
            return i;
    }
    return MAX_SPRITES;
}

void TurnObjectEventSprite(u8 objectEventId, u8 direction)
{
    u8 spriteId = GetObjectEventSpriteId(objectEventId);

    if (spriteId != MAX_SPRITES)
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(direction));
}

void SetObjectEventSpriteGraphics(u8 objectEventId, u8 graphicsId)
{
    int spriteId = GetObjectEventSpriteId(objectEventId);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
        u16 tileNum = sprite->oam.tileNum;

        sprite->oam = *graphicsInfo->oam;
        sprite->oam.tileNum = tileNum;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        sprite->images = graphicsInfo->images;

        if (graphicsInfo->subspriteTables == NULL)
        {
            sprite->subspriteTables = NULL;
            sprite->subspriteTableNum = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
        }
        else
        {
            SetSubspriteTables(sprite, graphicsInfo->subspriteTables);
            sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        }
        StartSpriteAnim(sprite, 0);
    }
}

void SetObjectEventSpriteInvisibility(u8 objectEventId, bool32 invisible)
{
    u8 spriteId = GetObjectEventSpriteId(objectEventId);

    if (spriteId == MAX_SPRITES)
        return;

    if (invisible)
        gSprites[spriteId].tInvisible = TRUE;
    else
        gSprites[spriteId].tInvisible = FALSE;
}

bool32 IsObjectEventSpriteInvisible(u8 objectEventId)
{
    u8 spriteId = GetObjectEventSpriteId(objectEventId);

    if (spriteId == MAX_SPRITES)
        return FALSE;

    return (gSprites[spriteId].tInvisible == TRUE);
}

void SetObjectEventSpriteAnim(u8 objectEventId, u8 animNum)
{
    u8 spriteId = GetObjectEventSpriteId(objectEventId);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].tAnimNum = animNum;
        gSprites[spriteId].tAnimState = 0;
    }
}

static void MoveUnionRoomObjectUp(struct Sprite *sprite)
{
    switch(sprite->tAnimState)
    {
        case 0:
            sprite->pos2.y = 0;
            sprite->tAnimState++;
        case 1:
            sprite->pos2.y -= 8;
            if (sprite->pos2.y == -160)
            {
                sprite->pos2.y = 0;
                sprite->tInvisible = TRUE;
                sprite->tAnimNum = 0;
                sprite->tAnimState = 0;
            }
    }
}

static void MoveUnionRoomObjectDown(struct Sprite *sprite)
{
    switch(sprite->tAnimState)
    {
        case 0:
            sprite->pos2.y = -160;
            sprite->tAnimState++;
        case 1:
            sprite->pos2.y += 8;
            if(sprite->pos2.y == 0)
            {
                sprite->tAnimNum = 0;
                sprite->tAnimState = 0;
            }
    }
}

static void UpdateObjectEventSpritePosition(struct Sprite *sprite)
{
    switch(sprite->tAnimNum)
    {
        case UNION_ROOM_SPAWN_IN:
            MoveUnionRoomObjectDown(sprite);
            break;
        case UNION_ROOM_SPAWN_OUT:
            MoveUnionRoomObjectUp(sprite);
            break;
        case 0:
            break;
        default:
            sprite->tAnimNum = 0;
            break;
    }
}

bool32 IsObjectEventSpriteAnimating(u8 var)
{
    u8 spriteId = GetObjectEventSpriteId(var);

    if (spriteId == MAX_SPRITES)
        return FALSE;

    if (gSprites[spriteId].tAnimNum != 0)
        return TRUE;

    return FALSE;
}

u32 StartFieldEffectForObjectEvent(u8 fieldEffectId, struct ObjectEvent *objectEvent)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    return FieldEffectStart(fieldEffectId);
}

void DoShadowFieldEffect(struct ObjectEvent *objectEvent)
{
    if (!objectEvent->hasShadow)
    {
        objectEvent->hasShadow = 1;
        StartFieldEffectForObjectEvent(FLDEFF_SHADOW, objectEvent);
    }
}

static void DoRippleFieldEffect(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    gFieldEffectArguments[0] = sprite->pos1.x;
    gFieldEffectArguments[1] = sprite->pos1.y + (graphicsInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

u8 (*const gMovementActionFuncs_StoreAndLockAnim[])(struct ObjectEvent *, struct Sprite *) = {
    MovementAction_StoreAndLockAnim_Step0,
    MovementAction_Finish,
};

u8 (*const gMovementActionFuncs_FreeAndUnlockAnim[])(struct ObjectEvent *, struct Sprite *) = {
    MovementAction_FreeAndUnlockAnim_Step0,
    MovementAction_Finish,
};

u8 (*const gMovementActionFuncs_FlyUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementAction_FlyUp_Step0,
    MovementAction_FlyUp_Step1,
    MovementAction_Fly_Finish,
};

u8 (*const gMovementActionFuncs_FlyDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementAction_FlyDown_Step0,
    MovementAction_FlyDown_Step1,
    MovementAction_Fly_Finish,
};

u8 MovementAction_StoreAndLockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    bool32 ableToStore = FALSE;
    if (gLockedAnimObjectEvents == NULL)
    {
        gLockedAnimObjectEvents = AllocZeroed(sizeof(struct LockedAnimObjectEvents));
        gLockedAnimObjectEvents->objectEventIds[0] = objectEvent->localId;
        gLockedAnimObjectEvents->count = 1;
        ableToStore = TRUE;
    }
    else
    {
        u8 i;
        u8 firstFreeSlot;
        bool32 found;
        for (firstFreeSlot = 16, found = FALSE, i = 0; i < 16; i++)
        {
            if (firstFreeSlot == 16 && gLockedAnimObjectEvents->objectEventIds[i] == 0)
                firstFreeSlot = i;

            if (gLockedAnimObjectEvents->objectEventIds[i] == objectEvent->localId)
            {
                found = TRUE;
                break;
            }
        }

        if (!found && firstFreeSlot != 16)
        {
            gLockedAnimObjectEvents->objectEventIds[firstFreeSlot] = objectEvent->localId;
            gLockedAnimObjectEvents->count++;
            ableToStore = TRUE;
        }
    }

    if (ableToStore == TRUE)
    {
        objectEvent->inanimate = TRUE;
        objectEvent->facingDirectionLocked = TRUE;
    }

    sprite->data[2] = 1;
    return TRUE;
}

u8 MovementAction_FreeAndUnlockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    bool32 ableToStore;
    u8 index;

    sprite->data[2] = 1;
    if (gLockedAnimObjectEvents != NULL)
    {
        ableToStore = FALSE;
        index = FindLockedObjectEventIndex(objectEvent);
        if (index != 16)
        {
            gLockedAnimObjectEvents->objectEventIds[index] = 0;
            gLockedAnimObjectEvents->count--;
            ableToStore = TRUE;
        }
        if (gLockedAnimObjectEvents->count == 0)
            FREE_AND_SET_NULL(gLockedAnimObjectEvents);
        if (ableToStore == TRUE)
        {
            objectEvent->inanimate = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->inanimate;
            objectEvent->facingDirectionLocked = FALSE;
            sprite->animPaused = 0;
        }
    }

    return TRUE;
}

u8 FindLockedObjectEventIndex(struct ObjectEvent *objectEvent)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gLockedAnimObjectEvents->objectEventIds[i] == objectEvent->localId)
            return i;
    }
    return OBJECT_EVENTS_COUNT;
}

void CreateLevitateMovementTask(struct ObjectEvent *objectEvent)
{
    u8 taskId = CreateTask(ApplyLevitateMovement, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)objectEvent);
    objectEvent->warpArrowSpriteId = taskId;
    task->data[3] = 0xFFFF;
}

static void ApplyLevitateMovement(u8 taskId)
{
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&objectEvent); // load the map object pointer.
    sprite = &gSprites[objectEvent->spriteId];

    if(!(task->data[2] & 0x3))
        sprite->pos2.y += task->data[3];

    if(!(task->data[2] & 0xF))
        task->data[3] = -task->data[3];

    task->data[2]++;
}

void DestroyExtraMovementTask(u8 taskId)
{
    struct ObjectEvent *objectEvent;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&objectEvent); // unused objectEvent
    DestroyTask(taskId);
}

void sub_8098074(u8 var1, u8 var2)
{
    u8 i;

    for(i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if(i != var1 && i != var2 &&
            gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
                FreezeObjectEvent(&gObjectEvents[i]);
    }
}

u8 MovementAction_FlyUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->pos2.y = 0;
    sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->pos2.y -= 8;

    if(sprite->pos2.y == -160)
        sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->pos2.y = -160;
    sprite->data[2]++;
    return FALSE;
}

u8 MovementAction_FlyDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->pos2.y += 8;

    if(!sprite->pos2.y)
        sprite->data[2]++;
    return FALSE;
}

// though this function returns TRUE without doing anything, this header is required due to being in an array of functions which needs it.
u8 MovementAction_Fly_Finish(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return TRUE;
}
