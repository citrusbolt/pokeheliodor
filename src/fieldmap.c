#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "day_night.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "menu.h"
#include "mirage_tower.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "script.h"
#include "secret_base.h"
#include "trainer_hill.h"
#include "tv.h"
#include "constants/rgb.h"
#include "constants/metatile_behaviors.h"
#include "constants/region_map_sections.h"

struct ConnectionFlags
{
    u8 south:1;
    u8 north:1;
    u8 west:1;
    u8 east:1;
};

EWRAM_DATA static u16 ALIGNED(4) sBackupMapData[MAX_MAP_DATA_SIZE] = {0};
EWRAM_DATA struct MapHeader gMapHeader = {0};
EWRAM_DATA struct Camera gCamera = {0};
EWRAM_DATA static struct ConnectionFlags sMapConnectionFlags = {0};
EWRAM_DATA static u32 UNUSED sFiller = 0; // without this, the next file won't align properly

COMMON_DATA struct BackupMapLayout gBackupMapLayout = {0};

static const struct ConnectionFlags sDummyConnectionFlags = {0};

static void InitMapLayoutData(struct MapHeader *mapHeader);
static void InitBackupMapLayoutData(const u16 *map, u16 width, u16 height);
static void FillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void InitBackupMapLayoutConnections(struct MapHeader *mapHeader);
static void LoadSavedMapView(void);
static bool8 SkipCopyingMetatileFromSavedMap(u16 *mapBlock, u16 mapWidth, u8 yMode);
static const struct MapConnection *GetIncomingConnection(u8 direction, int x, int y);
static bool8 IsPosInIncomingConnectingMap(u8 direction, int x, int y, const struct MapConnection *connection);
static bool8 IsCoordInIncomingConnectingMap(int coord, int srcMax, int destMax, int offset);

#define GetBorderBlockAt(x, y) ({                                                                  \
    u16 block;                                                                                     \
    int i;                                                                                         \
    const u16 *border = gMapHeader.mapLayout->border; /* Unused, they read it again below */       \
                                                                                                   \
    i = (x + 1) & 1;                                                                               \
    i += ((y + 1) & 1) * 2;                                                                        \
                                                                                                   \
    block = gMapHeader.mapLayout->border[i] | MAPGRID_COLLISION_MASK;                              \
})

#define AreCoordsWithinMapGridBounds(x, y) (x >= 0 && x < gBackupMapLayout.width && y >= 0 && y < gBackupMapLayout.height)

#define GetMapGridBlockAt(x, y) (AreCoordsWithinMapGridBounds(x, y) ? gBackupMapLayout.map[x + gBackupMapLayout.width * y] : GetBorderBlockAt(x, y))

static const u32 sKantoMetatileAttrMasks[METATILE_ATTRIBUTE_COUNT] = {
    [METATILE_ATTRIBUTE_BEHAVIOR]       = 0x000001ff,
    [METATILE_ATTRIBUTE_TERRAIN]        = 0x00003e00,
    [METATILE_ATTRIBUTE_2]              = 0x0003c000,
    [METATILE_ATTRIBUTE_3]              = 0x00fc0000,
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 0x07000000,
    [METATILE_ATTRIBUTE_5]              = 0x18000000,
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = 0x60000000,
    [METATILE_ATTRIBUTE_7]              = 0x80000000
};

static const u8 sKantoMetatileAttrShifts[METATILE_ATTRIBUTE_COUNT] = {
    [METATILE_ATTRIBUTE_BEHAVIOR]       = 0,
    [METATILE_ATTRIBUTE_TERRAIN]        = 9,
    [METATILE_ATTRIBUTE_2]              = 14,
    [METATILE_ATTRIBUTE_3]              = 18,
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 24,
    [METATILE_ATTRIBUTE_5]              = 27,
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = 29,
    [METATILE_ATTRIBUTE_7]              = 31
};

static const u8 sMetatileBehaviorConversion[] = {
	[MB_KANTO_NORMAL]                      	= MB_NORMAL,
	[MB_KANTO_01]                          	= MB_NORMAL,
	[MB_KANTO_TALL_GRASS]                  	= MB_TALL_GRASS,
	[MB_KANTO_TREE1]                        = MB_TREE1,
	[MB_KANTO_TREE2]                        = MB_TREE2,
	[MB_KANTO_TREE3]                        = MB_TREE3,
	[MB_KANTO_TREE4]                        = MB_TREE4,
	[MB_KANTO_CAVE]                        	= MB_CAVE,
	[MB_KANTO_RUNNING_DISALLOWED]          	= MB_NO_RUNNING,
	[MB_KANTO_0B]                          	= MB_INDOOR_ENCOUNTER,
	[MB_KANTO_0C]                          	= MB_MOUNTAIN_TOP,
	[MB_KANTO_POND_WATER]                  	= MB_POND_WATER,
	[MB_KANTO_SEMI_DEEP_WATER]             	= MB_INTERIOR_DEEP_WATER,
	[MB_KANTO_DEEP_WATER]                  	= MB_DEEP_WATER,
	[MB_KANTO_WATERFALL]                   	= MB_WATERFALL,
	[MB_KANTO_OCEAN_WATER]                 	= MB_OCEAN_WATER,
	[MB_KANTO_PUDDLE]                      	= MB_PUDDLE,
	[MB_KANTO_SHALLOW_WATER]               	= MB_SHALLOW_WATER,
	[MB_KANTO_UNDERWATER_BLOCKED_ABOVE]    	= MB_NO_SURFACING,
	[MB_KANTO_1A]                          	= MB_POND_WATER,
	[MB_KANTO_1B]                          	= MB_POND_WATER,	// ?
	[MB_KANTO_STRENGTH_BUTTON]             	= MB_NORMAL,
	[MB_KANTO_SAND]                        	= MB_SAND,
	[MB_KANTO_SEAWEED]                     	= MB_SEAWEED,
	[MB_KANTO_ICE]                         	= MB_ICE,
	[MB_KANTO_THIN_ICE]                    	= MB_THIN_ICE,
	[MB_KANTO_CRACKED_ICE]                 	= MB_CRACKED_ICE,
	[MB_KANTO_HOT_SPRINGS]                 	= MB_HOT_SPRINGS,
	[MB_KANTO_ROCK_STAIRS]                 	= MB_NORMAL,
	[MB_KANTO_SAND_CAVE]                   	= MB_CAVE,
	[MB_KANTO_IMPASSABLE_EAST]             	= MB_IMPASSABLE_EAST,
	[MB_KANTO_IMPASSABLE_WEST]             	= MB_IMPASSABLE_WEST,
	[MB_KANTO_IMPASSABLE_NORTH]            	= MB_IMPASSABLE_NORTH,
	[MB_KANTO_IMPASSABLE_SOUTH]            	= MB_IMPASSABLE_SOUTH,
	[MB_KANTO_IMPASSABLE_NORTHEAST]        	= MB_IMPASSABLE_NORTHEAST,
	[MB_KANTO_IMPASSABLE_NORTHWEST]        	= MB_IMPASSABLE_NORTHWEST,
	[MB_KANTO_IMPASSABLE_SOUTHEAST]        	= MB_IMPASSABLE_SOUTHEAST,
	[MB_KANTO_IMPASSABLE_SOUTHWEST]        	= MB_IMPASSABLE_SOUTHWEST,
	[MB_KANTO_JUMP_EAST]                   	= MB_JUMP_EAST,
	[MB_KANTO_JUMP_WEST]                   	= MB_JUMP_WEST,
	[MB_KANTO_JUMP_NORTH]                  	= MB_JUMP_NORTH,
	[MB_KANTO_JUMP_SOUTH]                  	= MB_JUMP_SOUTH,
	[MB_KANTO_JUMP_SOUTHEAST]              	= MB_JUMP_SOUTHEAST,
	[MB_KANTO_JUMP_SOUTHWEST]              	= MB_JUMP_SOUTHWEST,
	[MB_KANTO_WALK_EAST]                   	= MB_WALK_EAST,
	[MB_KANTO_WALK_WEST]                   	= MB_WALK_WEST,
	[MB_KANTO_WALK_NORTH]                  	= MB_WALK_NORTH,
	[MB_KANTO_WALK_SOUTH]                  	= MB_WALK_SOUTH,
	[MB_KANTO_SLIDE_EAST]                  	= MB_SLIDE_EAST,
	[MB_KANTO_SLIDE_WEST]                  	= MB_SLIDE_WEST,
	[MB_KANTO_SLIDE_NORTH]                 	= MB_SLIDE_NORTH,
	[MB_KANTO_SLIDE_SOUTH]                 	= MB_SLIDE_SOUTH,
	[MB_KANTO_UNKNOWN_MOVEMENT_48]         	= MB_ICE,
	[MB_KANTO_EASTWARD_CURRENT]            	= MB_EASTWARD_CURRENT,
	[MB_KANTO_WESTWARD_CURRENT]            	= MB_WESTWARD_CURRENT,
	[MB_KANTO_NORTHWARD_CURRENT]           	= MB_NORTHWARD_CURRENT,
	[MB_KANTO_SOUTHWARD_CURRENT]           	= MB_SOUTHWARD_CURRENT,
	[MB_KANTO_SPIN_RIGHT]                  	= MB_NORMAL,
	[MB_KANTO_SPIN_LEFT]                   	= MB_NORMAL,
	[MB_KANTO_SPIN_UP]                     	= MB_NORMAL,
	[MB_KANTO_SPIN_DOWN]                   	= MB_NORMAL,
	[MB_KANTO_STOP_SPINNING]               	= MB_NORMAL,
	[MB_KANTO_CAVE_DOOR]                   	= MB_NON_ANIMATED_DOOR,
	[MB_KANTO_LADDER]                      	= MB_LADDER,
	[MB_KANTO_EAST_ARROW_WARP]             	= MB_EAST_ARROW_WARP,
	[MB_KANTO_WEST_ARROW_WARP]             	= MB_WEST_ARROW_WARP,
	[MB_KANTO_NORTH_ARROW_WARP]            	= MB_NORTH_ARROW_WARP,
	[MB_KANTO_SOUTH_ARROW_WARP]            	= MB_SOUTH_ARROW_WARP,
	[MB_KANTO_FALL_WARP]                   	= MB_MT_PYRE_HOLE,
	[MB_KANTO_REGULAR_WARP]                	= MB_AQUA_HIDEOUT_WARP,
	[MB_KANTO_LAVARIDGE_1F_WARP]           	= MB_LAVARIDGE_GYM_1F_WARP,
	[MB_KANTO_WARP_DOOR]                   	= MB_ANIMATED_DOOR,
	[MB_KANTO_UP_ESCALATOR]                	= MB_UP_ESCALATOR,
	[MB_KANTO_DOWN_ESCALATOR]              	= MB_DOWN_ESCALATOR,
	[MB_KANTO_UP_RIGHT_STAIR_WARP]         	= MB_UP_RIGHT_STAIR_WARP,
	[MB_KANTO_UP_LEFT_STAIR_WARP]          	= MB_UP_LEFT_STAIR_WARP,
	[MB_KANTO_DOWN_RIGHT_STAIR_WARP]       	= MB_DOWN_RIGHT_STAIR_WARP,
	[MB_KANTO_DOWN_LEFT_STAIR_WARP]        	= MB_DOWN_LEFT_STAIR_WARP,
	[MB_KANTO_UNION_ROOM_WARP]             	= MB_NORMAL,
	[MB_KANTO_COUNTER]                     	= MB_COUNTER,
	[MB_KANTO_BOOKSHELF]                   	= MB_BOOKSHELF,
	[MB_KANTO_POKEMART_SHELF]              	= MB_SHOP_SHELF,
	[MB_KANTO_PC]                          	= MB_PC,
	[MB_KANTO_SIGNPOST]                    	= MB_NORMAL,
	[MB_KANTO_REGION_MAP]                  	= MB_REGION_MAP,
	[MB_KANTO_TELEVISION]                  	= MB_TELEVISION,
	[MB_KANTO_POKEMON_CENTER_SIGN]         	= MB_NORMAL,
	[MB_KANTO_POKEMART_SIGN]               	= MB_NORMAL,
	[MB_KANTO_CABINET]                     	= MB_NORMAL,
	[MB_KANTO_KITCHEN]                     	= MB_NORMAL,
	[MB_KANTO_DRESSER]                     	= MB_NORMAL,
	[MB_KANTO_SNACKS]                      	= MB_NORMAL,
	[MB_KANTO_8D]                          	= MB_WIRELESS_BOX_RESULTS,
	[MB_KANTO_BATTLE_RECORDS]              	= MB_CABLE_BOX_RESULTS_2,
	[MB_KANTO_QUESTIONNAIRE]               	= MB_QUESTIONNAIRE,
	[MB_KANTO_FOOD]                        	= MB_NORMAL,
	[MB_KANTO_INDIGO_PLATEAU_MARK_DPAD]    	= MB_NORMAL,
	[MB_KANTO_INDIGO_PLATEAU_MARK_2_DPAD]  	= MB_NORMAL,
	[MB_KANTO_BLUEPRINTS]                  	= MB_NORMAL,
	[MB_KANTO_PAINTING]                    	= MB_NORMAL,
	[MB_KANTO_POWER_PLANT_MACHINE]         	= MB_NORMAL,
	[MB_KANTO_TELEPHONE]                   	= MB_NORMAL,
	[MB_KANTO_COMPUTER]                    	= MB_NORMAL,
	[MB_KANTO_ADVERTISING_POSTER]          	= MB_NORMAL,
	[MB_KANTO_FOOD_SMELLS_TASTY]           	= MB_NORMAL,
	[MB_KANTO_TRASH_BIN]                   	= MB_TRASH_CAN,
	[MB_KANTO_CUP]                         	= MB_NORMAL,
	[MB_KANTO_PORTHOLE]                    	= MB_NORMAL,
	[MB_KANTO_BLINKING_LIGHTS]             	= MB_NORMAL,
	[MB_KANTO_NEATLY_LINED_UP_TOOLS]       	= MB_NORMAL,
	[MB_KANTO_IMPRESSIVE_MACHINE]          	= MB_NORMAL,
	[MB_KANTO_VIDEO_GAME]                  	= MB_NORMAL,
	[MB_KANTO_BURGLARY]                    	= MB_NORMAL,
	[MB_KANTO_TRAINER_TOWER_MONITOR]       	= MB_TRAINER_HILL_TIMER,
	[MB_KANTO_CYCLING_ROAD_PULL_DOWN]      	= MB_NORMAL,
	[MB_KANTO_CYCLING_ROAD_PULL_DOWN_GRASS]	= MB_NORMAL
};

const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection)
{
    return Overworld_GetMapHeaderByGroupAndId(connection->mapGroup, connection->mapNum);
}

void InitMap(void)
{
    InitMapLayoutData(&gMapHeader);
    SetOccupiedSecretBaseEntranceMetatiles(gMapHeader.events);
    RunOnLoadMapScript();
}

void InitMapFromSavedGame(void)
{
    InitMapLayoutData(&gMapHeader);
    InitSecretBaseAppearance(FALSE);
    SetOccupiedSecretBaseEntranceMetatiles(gMapHeader.events);
    LoadSavedMapView();
    RunOnLoadMapScript();
    UpdateTVScreensOnMap(gBackupMapLayout.width, gBackupMapLayout.height);
}

void InitBattlePyramidMap(bool8 setPlayerPosition)
{
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));
    GenerateBattlePyramidFloorLayout(sBackupMapData, setPlayerPosition);
}

void InitTrainerHillMap(void)
{
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));
    GenerateTrainerHillFloorLayout(sBackupMapData);
}

static void InitMapLayoutData(struct MapHeader *mapHeader)
{
    struct MapLayout const *mapLayout;
    int width;
    int height;
    mapLayout = mapHeader->mapLayout;
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));
    gBackupMapLayout.map = sBackupMapData;
    width = mapLayout->width + MAP_OFFSET_W;
    gBackupMapLayout.width = width;
    height = mapLayout->height + MAP_OFFSET_H;
    gBackupMapLayout.height = height;
    if (width * height <= MAX_MAP_DATA_SIZE)
    {
        InitBackupMapLayoutData(mapLayout->map, mapLayout->width, mapLayout->height);
        InitBackupMapLayoutConnections(mapHeader);
    }
}

static void InitBackupMapLayoutData(const u16 *map, u16 width, u16 height)
{
    u16 *dest;
    int y;
    dest = gBackupMapLayout.map;
    dest += gBackupMapLayout.width * 7 + MAP_OFFSET;
    for (y = 0; y < height; y++)
    {
        CpuCopy16(map, dest, width * 2);
        dest += width + MAP_OFFSET_W;
        map += width;
    }
}

static void InitBackupMapLayoutConnections(struct MapHeader *mapHeader)
{
    int count;
    const struct MapConnection *connection;
    int i;

    if (mapHeader->connections)
    {
        count = mapHeader->connections->count;
        connection = mapHeader->connections->connections;
        sMapConnectionFlags = sDummyConnectionFlags;
        for (i = 0; i < count; i++, connection++)
        {
            struct MapHeader const *cMap = GetMapHeaderFromConnection(connection);
            s32 offset = connection->offset;
            switch (connection->direction)
            {
            case CONNECTION_SOUTH:
                FillSouthConnection(mapHeader, cMap, offset);
                sMapConnectionFlags.south = TRUE;
                break;
            case CONNECTION_NORTH:
                FillNorthConnection(mapHeader, cMap, offset);
                sMapConnectionFlags.north = TRUE;
                break;
            case CONNECTION_WEST:
                FillWestConnection(mapHeader, cMap, offset);
                sMapConnectionFlags.west = TRUE;
                break;
            case CONNECTION_EAST:
                FillEastConnection(mapHeader, cMap, offset);
                sMapConnectionFlags.east = TRUE;
                break;
            }
        }
    }
}

static void FillConnection(int x, int y, struct MapHeader const *connectedMapHeader, int x2, int y2, int width, int height)
{
    int i;
    const u16 *src;
    u16 *dest;
    int mapWidth;

    mapWidth = connectedMapHeader->mapLayout->width;
    src = &connectedMapHeader->mapLayout->map[mapWidth * y2 + x2];
    dest = &gBackupMapLayout.map[gBackupMapLayout.width * y + x];

    for (i = 0; i < height; i++)
    {
        CpuCopy16(src, dest, width * 2);
        dest += gBackupMapLayout.width;
        src += mapWidth;
    }
}

static void FillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x, y;
    int x2;
    int width;
    int cWidth;

    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        x = offset + MAP_OFFSET;
        y = mapHeader->mapLayout->height + MAP_OFFSET;
        if (x < 0)
        {
            x2 = -x;
            x += cWidth;
            if (x < gBackupMapLayout.width)
                width = x;
            else
                width = gBackupMapLayout.width;
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gBackupMapLayout.width)
                width = cWidth;
            else
                width = gBackupMapLayout.width - x;
        }

        FillConnection(
            x, y,
            connectedMapHeader,
            x2, /*y2*/ 0,
            width, /*height*/ MAP_OFFSET);
    }
}

static void FillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x;
    int x2, y2;
    int width;
    int cWidth, cHeight;

    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        cHeight = connectedMapHeader->mapLayout->height;
        x = offset + MAP_OFFSET;
        y2 = cHeight - MAP_OFFSET;
        if (x < 0)
        {
            x2 = -x;
            x += cWidth;
            if (x < gBackupMapLayout.width)
                width = x;
            else
                width = gBackupMapLayout.width;
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gBackupMapLayout.width)
                width = cWidth;
            else
                width = gBackupMapLayout.width - x;
        }

        FillConnection(
            x, /*y*/ 0,
            connectedMapHeader,
            x2, y2,
            width, /*height*/ MAP_OFFSET);

    }
}

static void FillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int y;
    int x2, y2;
    int height;
    int cWidth, cHeight;
    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        cHeight = connectedMapHeader->mapLayout->height;
        y = offset + MAP_OFFSET;
        x2 = cWidth - MAP_OFFSET;
        if (y < 0)
        {
            y2 = -y;
            if (y + cHeight < gBackupMapLayout.height)
                height = y + cHeight;
            else
                height = gBackupMapLayout.height;
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gBackupMapLayout.height)
                height = cHeight;
            else
                height = gBackupMapLayout.height - y;
        }

        FillConnection(
            /*x*/ 0, y,
            connectedMapHeader,
            x2, y2,
            /*width*/ MAP_OFFSET, height);
    }
}

static void FillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x, y;
    int y2;
    int height;
    int cHeight;
    if (connectedMapHeader)
    {
        cHeight = connectedMapHeader->mapLayout->height;
        x = mapHeader->mapLayout->width + MAP_OFFSET;
        y = offset + MAP_OFFSET;
        if (y < 0)
        {
            y2 = -y;
            if (y + cHeight < gBackupMapLayout.height)
                height = y + cHeight;
            else
                height = gBackupMapLayout.height;
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gBackupMapLayout.height)
                height = cHeight;
            else
                height = gBackupMapLayout.height - y;
        }

        FillConnection(
            x, y,
            connectedMapHeader,
            /*x2*/ 0, y2,
            /*width*/ MAP_OFFSET + 1, height);
    }
}

u8 MapGridGetElevationAt(int x, int y)
{
    u16 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return 0;

    return block >> MAPGRID_ELEVATION_SHIFT;
}

u8 MapGridGetCollisionAt(int x, int y)
{
    u16 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return TRUE;

    return (block & MAPGRID_COLLISION_MASK) >> MAPGRID_COLLISION_SHIFT;
}

u32 MapGridGetMetatileIdAt(int x, int y)
{
    u16 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return GetBorderBlockAt(x, y) & MAPGRID_METATILE_ID_MASK;

    return block & MAPGRID_METATILE_ID_MASK;
}

static u32 GetFRLGAttributesByMetatileId(u16 metatile)
{
	const u32 *attributes;
	if (metatile < NUM_METATILES_IN_PRIMARY_KANTO)
	{
		attributes = gMapHeader.mapLayout->primaryTileset->metatileAttributes;
		return attributes[metatile];
	}
	else if (metatile < NUM_METATILES_TOTAL)
	{
		attributes = gMapHeader.mapLayout->secondaryTileset->metatileAttributes;
		return attributes[metatile - NUM_METATILES_IN_PRIMARY_KANTO];
	}
	else
	{
		return MB_INVALID;
	}
}

u32 MapGridGetMetatileBehaviorAt(int x, int y)
{
    u16 metatile = MapGridGetMetatileIdAt(x, y);

	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		return sMetatileBehaviorConversion[GetFRLGAttributesByMetatileId(metatile) & sKantoMetatileAttrMasks[METATILE_ATTRIBUTE_BEHAVIOR] >> sKantoMetatileAttrShifts[METATILE_ATTRIBUTE_BEHAVIOR]];
	else
		return GetMetatileAttributesById(metatile) & METATILE_ATTR_BEHAVIOR_MASK;
}

u8 MapGridGetMetatileLayerTypeAt(int x, int y)
{
    u16 metatile = MapGridGetMetatileIdAt(x, y);

	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		return (GetFRLGAttributesByMetatileId(metatile) & sKantoMetatileAttrMasks[METATILE_ATTRIBUTE_LAYER_TYPE]) >> sKantoMetatileAttrShifts[METATILE_ATTRIBUTE_LAYER_TYPE];
	else
		return (GetMetatileAttributesById(metatile) & METATILE_ATTR_LAYER_MASK) >> METATILE_ATTR_LAYER_SHIFT;
}

void MapGridSetMetatileIdAt(int x, int y, u16 metatile)
{
    int i;
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        i = x + y * gBackupMapLayout.width;
        gBackupMapLayout.map[i] = (gBackupMapLayout.map[i] & MAPGRID_ELEVATION_MASK) | (metatile & ~MAPGRID_ELEVATION_MASK);
    }
}

void MapGridSetMetatileEntryAt(int x, int y, u16 metatile)
{
    int i;
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        i = x + gBackupMapLayout.width * y;
        gBackupMapLayout.map[i] = metatile;
    }
}

u16 GetMetatileAttributesById(u16 metatile)
{
	const u16 *attributes;
	if (metatile < NUM_METATILES_IN_PRIMARY)
	{
		attributes = gMapHeader.mapLayout->primaryTileset->metatileAttributes;
		return attributes[metatile];
	}
	else if (metatile < NUM_METATILES_TOTAL)
	{
		attributes = gMapHeader.mapLayout->secondaryTileset->metatileAttributes;
		return attributes[metatile - NUM_METATILES_IN_PRIMARY];
	}
	else
	{
		return MB_INVALID;
	}
}

void SaveMapView(void)
{
    int i, j;
    int x, y;
    u16 *mapView;
    int width;
    mapView = gSaveBlock1Ptr->mapView;
    width = gBackupMapLayout.width;
    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    for (i = y; i < y + MAP_OFFSET_H; i++)
    {
        for (j = x; j < x + MAP_OFFSET_W; j++)
            *mapView++ = sBackupMapData[width * i + j];
    }
}

static bool32 SavedMapViewIsEmpty(void)
{
    u16 i;
    u32 marker = 0;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->mapView); i++)
        marker |= gSaveBlock1Ptr->mapView[i];

    if (marker == 0)
        return TRUE;
    else
        return FALSE;
}

static void ClearSavedMapView(void)
{
    CpuFill16(0, gSaveBlock1Ptr->mapView, sizeof(gSaveBlock1Ptr->mapView));
}

static void LoadSavedMapView(void)
{
    u8 yMode;
    int i, j;
    int x, y;
    u16 *mapView;
    int width;
    mapView = gSaveBlock1Ptr->mapView;
    if (!SavedMapViewIsEmpty())
    {
        width = gBackupMapLayout.width;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        for (i = y; i < y + MAP_OFFSET_H; i++)
        {
            if (i == y && i != 0)
                yMode = 0;
            else if (i == y + MAP_OFFSET_H - 1 && i != gMapHeader.mapLayout->height - 1)
                yMode = 1;
            else
                yMode = 0xFF;

            for (j = x; j < x + MAP_OFFSET_W; j++)
            {
                if (!SkipCopyingMetatileFromSavedMap(&sBackupMapData[j + width * i], width, yMode))
                    sBackupMapData[j + width * i] = *mapView;
                mapView++;
            }
        }
        for (j = x; j < x + MAP_OFFSET_W; j++)
        {
            if (y != 0)
                FixLongGrassMetatilesWindowTop(j, y - 1);
            if (i < gMapHeader.mapLayout->height - 1)
                FixLongGrassMetatilesWindowBottom(j, y + MAP_OFFSET_H - 1);
        }
        ClearSavedMapView();
    }
}

static void MoveMapViewToBackup(u8 direction)
{
    int width;
    u16 *mapView;
    int x0, y0;
    int x2, y2;
    u16 *src, *dest;
    int srci, desti;
    int r9, r8;
    int x, y;
    int i, j;
    mapView = gSaveBlock1Ptr->mapView;
    width = gBackupMapLayout.width;
    r9 = 0;
    r8 = 0;
    x0 = gSaveBlock1Ptr->pos.x;
    y0 = gSaveBlock1Ptr->pos.y;
    x2 = MAP_OFFSET_W;
    y2 = MAP_OFFSET_H;
    switch (direction)
    {
    case CONNECTION_NORTH:
        y0 += 1;
        y2 = MAP_OFFSET_H - 1;
        break;
    case CONNECTION_SOUTH:
        r8 = 1;
        y2 = MAP_OFFSET_H - 1;
        break;
    case CONNECTION_WEST:
        x0 += 1;
        x2 = MAP_OFFSET_W - 1;
        break;
    case CONNECTION_EAST:
        r9 = 1;
        x2 = MAP_OFFSET_W - 1;
        break;
    }
    for (y = 0; y < y2; y++)
    {
        i = 0;
        j = 0;
        for (x = 0; x < x2; x++)
        {
            desti = width * (y + y0);
            srci = (y + r8) * MAP_OFFSET_W + r9;
            src = &mapView[srci + i];
            dest = &sBackupMapData[x0 + desti + j];
            *dest = *src;
            i++;
            j++;
        }
    }
    ClearSavedMapView();
}

int GetMapBorderIdAt(int x, int y)
{
    if (GetMapGridBlockAt(x, y) == MAPGRID_UNDEFINED)
        return CONNECTION_INVALID;

    if (x >= (gBackupMapLayout.width - (MAP_OFFSET + 1)))
    {
        if (!sMapConnectionFlags.east)
            return CONNECTION_INVALID;

        return CONNECTION_EAST;
    }
    else if (x < MAP_OFFSET)
    {
        if (!sMapConnectionFlags.west)
            return CONNECTION_INVALID;

        return CONNECTION_WEST;
    }
    else if (y >= (gBackupMapLayout.height - MAP_OFFSET))
    {
        if (!sMapConnectionFlags.south)
            return CONNECTION_INVALID;

        return CONNECTION_SOUTH;
    }
    else if (y < MAP_OFFSET)
    {
        if (!sMapConnectionFlags.north)
            return CONNECTION_INVALID;

        return CONNECTION_NORTH;
    }
    else
    {
        return CONNECTION_NONE;
    }
}

int GetPostCameraMoveMapBorderId(int x, int y)
{
    return GetMapBorderIdAt(gSaveBlock1Ptr->pos.x + MAP_OFFSET + x, gSaveBlock1Ptr->pos.y + MAP_OFFSET + y);
}

bool32 CanCameraMoveInDirection(int direction)
{
    int x, y;
    x = gSaveBlock1Ptr->pos.x + MAP_OFFSET + gDirectionToVectors[direction].x;
    y = gSaveBlock1Ptr->pos.y + MAP_OFFSET + gDirectionToVectors[direction].y;

    if (GetMapBorderIdAt(x, y) == CONNECTION_INVALID)
        return FALSE;

    return TRUE;
}

static void SetPositionFromConnection(const struct MapConnection *connection, int direction, int x, int y)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (direction)
    {
    case CONNECTION_EAST:
        gSaveBlock1Ptr->pos.x = -x;
        gSaveBlock1Ptr->pos.y -= connection->offset;
        break;
    case CONNECTION_WEST:
        gSaveBlock1Ptr->pos.x = mapHeader->mapLayout->width;
        gSaveBlock1Ptr->pos.y -= connection->offset;
        break;
    case CONNECTION_SOUTH:
        gSaveBlock1Ptr->pos.x -= connection->offset;
        gSaveBlock1Ptr->pos.y = -y;
        break;
    case CONNECTION_NORTH:
        gSaveBlock1Ptr->pos.x -= connection->offset;
        gSaveBlock1Ptr->pos.y = mapHeader->mapLayout->height;
        break;
    }
}

bool8 CameraMove(int x, int y)
{
    int direction;
    const struct MapConnection *connection;
    int old_x, old_y;
    gCamera.active = FALSE;
    direction = GetPostCameraMoveMapBorderId(x, y);
    if (direction == CONNECTION_NONE || direction == CONNECTION_INVALID)
    {
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
    }
    else
    {
        SaveMapView();
        ClearMirageTowerPulseBlendEffect();
        old_x = gSaveBlock1Ptr->pos.x;
        old_y = gSaveBlock1Ptr->pos.y;
        connection = GetIncomingConnection(direction, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
        SetPositionFromConnection(connection, direction, x, y);
        LoadMapFromCameraTransition(connection->mapGroup, connection->mapNum);
        gCamera.active = TRUE;
        gCamera.x = old_x - gSaveBlock1Ptr->pos.x;
        gCamera.y = old_y - gSaveBlock1Ptr->pos.y;
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
        MoveMapViewToBackup(direction);
    }
    return gCamera.active;
}

static const struct MapConnection *GetIncomingConnection(u8 direction, int x, int y)
{
    int count;
    int i;
    const struct MapConnection *connection;
    const struct MapConnections *connections = gMapHeader.connections;

    if (connections == NULL || connections->connections == NULL)
        return NULL;
    count = connections->count;
    connection = connections->connections;
    for (i = 0; i < count; i++, connection++)
    {
        if (connection->direction == direction && IsPosInIncomingConnectingMap(direction, x, y, connection) == TRUE)
            return connection;
    }
    return NULL;
}

static bool8 IsPosInIncomingConnectingMap(u8 direction, int x, int y, const struct MapConnection *connection)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return IsCoordInIncomingConnectingMap(x, gMapHeader.mapLayout->width, mapHeader->mapLayout->width, connection->offset);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return IsCoordInIncomingConnectingMap(y, gMapHeader.mapLayout->height, mapHeader->mapLayout->height, connection->offset);
    }
    return FALSE;
}

static bool8 IsCoordInIncomingConnectingMap(int coord, int srcMax, int destMax, int offset)
{
    int offset2;
    offset2 = offset;

    if (offset2 < 0)
        offset2 = 0;

    if (destMax + offset < srcMax)
        srcMax = destMax + offset;

    if (offset2 <= coord && coord <= srcMax)
        return TRUE;

    return FALSE;
}

static int IsCoordInConnectingMap(int coord, int max)
{
    if (coord >= 0 && coord < max)
        return TRUE;

    return FALSE;
}

static int IsPosInConnectingMap(const struct MapConnection *connection, int x, int y)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (connection->direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return IsCoordInConnectingMap(x - connection->offset, mapHeader->mapLayout->width);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return IsCoordInConnectingMap(y - connection->offset, mapHeader->mapLayout->height);
    }
    return FALSE;
}

const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y)
{
    int count;
    const struct MapConnection *connection;
    int i;
    u8 direction;
    if (!gMapHeader.connections)
    {
        return NULL;
    }
    else
    {
        count = gMapHeader.connections->count;
        connection = gMapHeader.connections->connections;
        for (i = 0; i < count; i++, connection++)
        {
            direction = connection->direction;
            if ((direction == CONNECTION_DIVE || direction == CONNECTION_EMERGE)
             || (direction == CONNECTION_NORTH && y > MAP_OFFSET - 1)
             || (direction == CONNECTION_SOUTH && y < gMapHeader.mapLayout->height + MAP_OFFSET)
             || (direction == CONNECTION_WEST && x > MAP_OFFSET - 1)
             || (direction == CONNECTION_EAST && x < gMapHeader.mapLayout->width + MAP_OFFSET))
            {
                continue;
            }
            if (IsPosInConnectingMap(connection, x - MAP_OFFSET, y - MAP_OFFSET) == TRUE)
            {
                return connection;
            }
        }
    }
    return NULL;
}

void SetCameraFocusCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x - MAP_OFFSET;
    gSaveBlock1Ptr->pos.y = y - MAP_OFFSET;
}

void GetCameraFocusCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x + MAP_OFFSET;
    *y = gSaveBlock1Ptr->pos.y + MAP_OFFSET;
}

static void UNUSED SetCameraCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x;
    gSaveBlock1Ptr->pos.y = y;
}

void GetCameraCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x;
    *y = gSaveBlock1Ptr->pos.y;
}

void MapGridSetMetatileImpassabilityAt(int x, int y, bool32 impassable)
{
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        if (impassable)
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] |= MAPGRID_COLLISION_MASK;
        else
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] &= ~MAPGRID_COLLISION_MASK;
    }
}

static bool8 SkipCopyingMetatileFromSavedMap(u16 *mapBlock, u16 mapWidth, u8 yMode)
{
    if (yMode == 0xFF)
        return FALSE;

    if (yMode == 0)
        mapBlock -= mapWidth;
    else
        mapBlock += mapWidth;

    if (IsLargeBreakableDecoration(*mapBlock & MAPGRID_METATILE_ID_MASK, yMode) == TRUE)
        return TRUE;
    return FALSE;
}

static void CopyTilesetToVram(struct Tileset const *tileset, u16 numTiles, u16 offset)
{
    if (tileset)
    {
        if (!tileset->isCompressed)
            LoadBgTiles(2, tileset->tiles, numTiles * 32, offset);
        else
            DecompressAndCopyTileDataToVram(2, tileset->tiles, numTiles * 32, offset, 0);
    }
}

static void CopyTilesetToVramUsingHeap(struct Tileset const *tileset, u16 numTiles, u16 offset)
{
    if (tileset)
    {
        if (!tileset->isCompressed)
            LoadBgTiles(2, tileset->tiles, numTiles * 32, offset);
        else
            DecompressAndLoadBgGfxUsingHeap(2, tileset->tiles, numTiles * 32, offset, 0);
    }
}

// Below two are dummied functions from FRLG, used to tint the overworld palettes for the Quest Log
static void ApplyGlobalTintToPaletteEntries(u16 offset, u16 size)
{

}

static void UNUSED ApplyGlobalTintToPaletteSlot(u8 slot, u8 count)
{

}

static void LoadTilesetPalette(struct Tileset const *tileset, u16 destOffset, u16 size)
{
    u16 black = RGB_BLACK;

    if (tileset)
    {
        if (tileset->isSecondary == FALSE)
        {
            gPaletteOverrides[0] = tileset->paletteOverrides;
            LoadPalette(&black, destOffset, PLTT_SIZEOF(1));
            LoadPaletteDayNight(((u16*)tileset->palettes) + 1, destOffset + 1, size - PLTT_SIZEOF(1));
            ApplyGlobalTintToPaletteEntries(destOffset + 1, (size - PLTT_SIZEOF(1)) >> 1);
        }
        else if (tileset->isSecondary == TRUE)
        {
            gPaletteOverrides[1] = tileset->paletteOverrides;
			if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
				LoadPaletteDayNight(((u16*)tileset->palettes) + (NUM_PALS_IN_PRIMARY_KANTO * 16), destOffset, size);
			else
				LoadPaletteDayNight(((u16*)tileset->palettes) + (NUM_PALS_IN_PRIMARY * 16), destOffset, size);
            ApplyGlobalTintToPaletteEntries(destOffset, size >> 1);
        }
        else
        {
            gPaletteOverrides[2] = tileset->paletteOverrides;
            LoadCompressedPalette((const u32 *)tileset->palettes, destOffset, size);
            ApplyGlobalTintToPaletteEntries(destOffset, size >> 1);
        }
    }
}

void CopyPrimaryTilesetToVram(struct MapLayout const *mapLayout)
{
	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		CopyTilesetToVram(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY_KANTO, 0);
	else
		CopyTilesetToVram(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
}

void CopySecondaryTilesetToVram(struct MapLayout const *mapLayout)
{
	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		CopyTilesetToVram(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY_KANTO, NUM_TILES_IN_PRIMARY_KANTO);
	else
		CopyTilesetToVram(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

void CopySecondaryTilesetToVramUsingHeap(struct MapLayout const *mapLayout)
{
	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY_KANTO, NUM_TILES_IN_PRIMARY_KANTO);
	else
		CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

static void LoadPrimaryTilesetPalette(struct MapLayout const *mapLayout)
{
	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		LoadTilesetPalette(mapLayout->primaryTileset, BG_PLTT_ID(0), NUM_PALS_IN_PRIMARY_KANTO * PLTT_SIZE_4BPP);
	else
		LoadTilesetPalette(mapLayout->primaryTileset, BG_PLTT_ID(0), NUM_PALS_IN_PRIMARY * PLTT_SIZE_4BPP);
}

void LoadSecondaryTilesetPalette(struct MapLayout const *mapLayout)
{
	if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		LoadTilesetPalette(mapLayout->secondaryTileset, BG_PLTT_ID(NUM_PALS_IN_PRIMARY_KANTO), (NUM_PALS_TOTAL - NUM_PALS_IN_PRIMARY_KANTO) * PLTT_SIZE_4BPP);
	else
		LoadTilesetPalette(mapLayout->secondaryTileset, BG_PLTT_ID(NUM_PALS_IN_PRIMARY), (NUM_PALS_TOTAL - NUM_PALS_IN_PRIMARY) * PLTT_SIZE_4BPP);
}

void CopyMapTilesetsToVram(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
		if (GetCurrentRegionMapSectionId() >= KANTO_MAPSEC_START && GetCurrentRegionMapSectionId() <= KANTO_MAPSEC_END)
		{
			CopyTilesetToVramUsingHeap(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY_KANTO, 0);
			CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY_KANTO, NUM_TILES_IN_PRIMARY_KANTO);
		}
		else
		{
			CopyTilesetToVramUsingHeap(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
			CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
		}
    }
}

void LoadMapTilesetPalettes(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        LoadPrimaryTilesetPalette(mapLayout);
        LoadSecondaryTilesetPalette(mapLayout);
    }
}
