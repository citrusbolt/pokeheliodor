const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Brendan = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_BrendanMay,
    .images = sPicTable_Brendan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanMachBike = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BrendanMachBike,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanAcroBike = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_AcroBike,
    .images = sPicTable_BrendanAcroBike,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanSurfing = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Surfing,
    .images = sPicTable_BrendanSurfing,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanFieldMove = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_FieldMove,
    .images = sPicTable_BrendanFieldMove,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_NinjaBoy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_NinjaBoy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Twin = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Twin,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Boy1 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Boy1,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Girl1 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Girl1,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Boy2 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Boy2,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Girl2 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Girl2,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LittleBoy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LittleBoy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LittleGirl = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LittleGirl,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Boy3 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Boy3,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Girl3 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Girl3,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RichBoy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RichBoy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman1 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman1,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_FatMan = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_FatMan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PokefanF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_PokefanF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man1 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man1,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman2 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman2,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ExpertM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ExpertM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ExpertF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ExpertF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man2 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man2,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman3 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman3,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PokefanM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_PokefanM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman4 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman4,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Cook = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Cook,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LinkReceptionist = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LinkReceptionist,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldMan = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldMan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldWoman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldWoman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Camper = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Camper,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Picnicker = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Picnicker,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man3 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man3,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman5 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman5,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Youngster = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Youngster,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BugCatcher = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BugCatcher,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PsychicM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_PsychicM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SchoolKidM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SchoolKidM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Maniac = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Maniac,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_HexManiac = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_HexManiac,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RayquazaStill = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 2048,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_64x64,
    .subspriteTables = sOamTables_64x64,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RayquazaStill,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BlackBelt = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BlackBelt,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Beauty = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Beauty,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Scientist1 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Scientist1,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lass = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lass,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Gentleman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Gentleman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sailor = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Sailor,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Fisherman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Fisherman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RunningTriathleteM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RunningTriathleteM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RunningTriathleteF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RunningTriathleteF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Hiker = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Hiker,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CyclingTriathleteM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_AcroBike,
    .images = sPicTable_CyclingTriathleteM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CyclingTriathleteF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_AcroBike,
    .images = sPicTable_CyclingTriathleteF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Nurse = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Nurse,
    .images = sPicTable_Nurse,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ItemBall = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_ItemBall,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BerryTree = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = NULL,
    .anims = sAnimTable_BerryTree,
    .images = sPicTable_PechaBerryTree,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BerryTreeEarlyStages = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_BerryTree,
    .images = sPicTable_PechaBerryTree,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BerryTreeLateStages = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_BerryTree,
    .images = sPicTable_PechaBerryTree,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ProfBirch = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ProfBirch,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man4 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man4,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man5 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man5,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ReporterM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ReporterM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ReporterF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ReporterF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Bard = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BARD,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Bard,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Hipster = {
    .paletteTag = OBJ_EVENT_PAL_TAG_HIPSTER,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Hipster,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Trader = {
    .paletteTag = OBJ_EVENT_PAL_TAG_TRADER,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Trader,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Storyteller = {
    .paletteTag = OBJ_EVENT_PAL_TAG_STORYTELLER,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Storyteller,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Giddy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GIDDY,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Giddy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedNatuDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedNatuDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedMagnemiteDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedMagnemiteDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedSquirtleDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedSquirtleDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedWooperDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedWooperDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedPikachuDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedPikachuDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnusedPorygon2Doll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_UnusedPorygon2Doll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CuttableTree = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_CuttableTree,
    .images = sPicTable_CuttableTree,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MartEmployee = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MartEmployee,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RooftopSaleWoman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RooftopSaleWoman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Teala = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Teala,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BreakableRock = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_BreakableRock,
    .images = sPicTable_BreakableRock,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PushableBoulder = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_PushableBoulder,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MrBrineysBoat = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MrBrineysBoat,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_May = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_BrendanMay,
    .images = sPicTable_May,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayMachBike = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MayMachBike,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayAcroBike = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_AcroBike,
    .images = sPicTable_MayAcroBike,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MaySurfing = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Surfing,
    .images = sPicTable_MaySurfing,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayFieldMove = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_FieldMove,
    .images = sPicTable_MayFieldMove,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Truck = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 1152,
    .width = 48,
    .height = 48,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_48x48,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Truck,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_VigorothCarryingBox = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_VigorothCarryingBox,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_VigorothFacingAway = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_VigorothFacingAway,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BirchsBag = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BirchsBag,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_EnemyZigzagoon = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_EnemyZigzagoon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Poochyena = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Poochyena,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Artist = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Artist,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Cameraman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Cameraman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanUnderwater = {
    .paletteTag = OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BrendanUnderwater,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayUnderwater = {
    .paletteTag = OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MayUnderwater,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MovingBox = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_MovingBox,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CableCar = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 2048,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_64x64,
    .subspriteTables = sOamTables_64x64,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_CableCar,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Scientist2 = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Scientist2,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_DevonEmployee = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_DevonEmployee,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_AquaMemberM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_AquaMemberM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_AquaMemberF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_AquaMemberF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MagmaMemberM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MagmaMemberM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MagmaMemberF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MagmaMemberF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sidney = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Sidney,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Phoebe = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Phoebe,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Glacia = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Glacia,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Drake = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Drake,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Roxanne = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Roxanne,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Brawly = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brawly,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Wattson = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Wattson,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Flannery = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Flannery,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Norman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Norman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Winona = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Winona,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Liza = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Liza,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Tate = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Tate,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Wallace = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Wallace,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Steven = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Steven,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Wally = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Wally,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LittleBoy_RS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LittleBoy_RS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanFishing = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Fishing,
    .images = sPicTable_BrendanFishing,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayFishing = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Fishing,
    .images = sPicTable_MayFishing,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_HotSpringsOldWoman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_HotSpringsOldWoman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SSTidal = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 1920,
    .width = 96,
    .height = 40,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_8x8,
    .subspriteTables = sOamTables_96x40,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SSTidal,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SubmarineShadow = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 1408,
    .width = 88,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_8x8,
    .subspriteTables = sOamTables_88x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SubmarineShadow,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PichuDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_PichuDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PikachuDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_PikachuDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MarillDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_MarillDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TogepiDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TogepiDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CyndaquilDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_CyndaquilDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ChikoritaDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_ChikoritaDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TotodileDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TotodileDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_JigglypuffDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_JigglypuffDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MeowthDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_MeowthDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ClefairyDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_ClefairyDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_DittoDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_DittoDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SmoochumDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_SmoochumDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TreeckoDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TreeckoDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TorchicDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TorchicDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MudkipDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_MudkipDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_DuskullDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_DuskullDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_WynautDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_WynautDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BaltoyDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BaltoyDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KecleonDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_KecleonDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_AzurillDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_AzurillDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SkittyDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_SkittyDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwabluDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_SwabluDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GulpinDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_GulpinDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LotadDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_LotadDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SeedotDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_SeedotDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_PikaCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_PikaCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RoundCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_RoundCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KissCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_KissCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ZigzagCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_ZigzagCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SpinCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_SpinCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_DiamondCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_DiamondCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BallCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BallCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GrassCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_GrassCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_FireCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_FireCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_WaterCushion = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_WaterCushion,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigSnorlaxDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigSnorlaxDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigRhydonDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigRhydonDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigLaprasDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigLaprasDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigVenusaurDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigVenusaurDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigCharizardDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigCharizardDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigBlastoiseDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigBlastoiseDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigWailmerDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigWailmerDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigRegirockDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigRegirockDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigRegiceDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigRegiceDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BigRegisteelDoll = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BigRegisteelDoll,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Latias = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Latias,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Latios = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Latios,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GameBoyKid = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_GameBoyKid,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ContestJudge = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ContestJudge,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanWatering = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BrendanWatering,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayWatering = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MayWatering,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanDecorating = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BrendanDecorating,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayDecorating = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_MayDecorating,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Archie = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Archie,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Maxie = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Maxie,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KyogreFront = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_KyogreFront,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GroudonFront = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_GroudonFront,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KyogreSide = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_KyogreSide,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GroudonSide = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_GroudonSide,
    .images = sPicTable_GroudonSide,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Fossil = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Fossil,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Regirock = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Regirock,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Regice = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Regice,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Registeel = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Registeel,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Skitty = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Skitty,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Kecleon = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Kecleon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KyogreAsleep = {
    .paletteTag = OBJ_EVENT_PAL_TAG_KYOGRE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_KyogreFront,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GroudonAsleep = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GROUDON,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_GroudonFront,
    .affineAnims = sAffineAnimTable_KyogreGroudon,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Rayquaza = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 2048,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_64x64,
    .subspriteTables = sOamTables_64x64,
    .anims = sAnimTable_Rayquaza,
    .images = sPicTable_Rayquaza,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Zigzagoon = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Zigzagoon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Pikachu = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Pikachu,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Azumarill = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Azumarill,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Wingull = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Wingull,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_KecleonBridgeShadow = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Kecleon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberMSwimming = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberMSwimming,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Azurill = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Azurill,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Mom = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Mom,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Juan = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Juan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Scott = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Scott,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MysteryEventDeliveryman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MysteryEventDeliveryman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Statue = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Statue,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Kirlia = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Kirlia,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Dusclops = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_4,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Dusclops,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnionRoomAttendant = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_UnionRoomAttendant,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Red = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Red,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Leaf = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Leaf,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sudowoodo = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Sudowoodo,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Mew = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_1,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Mew,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_DeoxysS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_DeoxysS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BirthIslandStone = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_BirthIslandStone,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Anabel = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Anabel,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Tucker = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Tucker,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Greta = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Greta,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Spenser = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Spenser,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Noland = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Noland,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lucy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lucy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Brandon = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brandon,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Brendan_RS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN_RS,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brendan_RS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_May_RS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY_RS,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_May_RS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lugia = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lugia,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_HoOh = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_HoOh,
    .images = sPicTable_HoOh,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Articuno = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Articuno,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Zapdos = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Zapdos,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Moltres = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Moltres,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Mewtwo = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Mewtwo,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Raikou = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Raikou,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Entei = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Entei,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Suicune = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = TRUE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Suicune,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanRed = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN_RED,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brendan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayRed = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY_RED,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_May,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanBlue = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN_BLUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brendan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayBlue = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY_BLUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_May,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BrendanGreen = {
    .paletteTag = OBJ_EVENT_PAL_TAG_BRENDAN_GREEN,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brendan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MayGreen = {
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY_GREEN,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_May,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Gold = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Gold,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Kris = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Kris,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman7_RS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_2,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman7_RS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman8_RS = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman8_RS,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_HikerBackpack = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_3,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_HikerBackpack,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TMBall = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TMBall,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Policeman = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Policeman,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LittleBoy_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LittleBoy_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LittleGirl_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LittleGirl_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SittingBoy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SittingBoy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lass_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lass_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Youngster_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Youngster_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman1_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman1_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman3_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman3_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Boy_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Boy_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BattleGirl = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BattleGirl,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BugCatcher_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BugCatcher_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_FatMan_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_FatMan_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BaldingMan = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BaldingMan,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Woman2_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Woman2_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldMan1_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldMan1_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_WorkerM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_WorkerM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_WorkerF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_WorkerF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Beauty_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Beauty_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Chef = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Chef,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldMan2_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldMan2_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldWoman_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldWoman_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Camper_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Camper_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Picnicker_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Picnicker_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CoolTrainerM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_CoolTrainerM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_CoolTrainerF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_CoolTrainerF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SuperNerd = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SuperNerd,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Channeler = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Channeler,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RocketGruntF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RocketGruntF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerMSwimming_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerMSwimming_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerFSwimming_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerFSwimming_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerM_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerM_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SwimmerF_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SwimmerF_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_BlackBelt_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_BlackBelt_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Scientist_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Scientist_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Gentleman_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Gentleman_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sailor_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Sailor_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Captain = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Captain,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Fisherman_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Fisherman_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TeachyTVHost = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TeachyTVHost,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberF_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberF_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberMSwimming_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberMSwimming_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TuberM_FRLG= {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TuberM_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Hiker_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Hiker_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Biker = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Biker,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GymGuy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_BIKE_TIRE,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_GymGuy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Nurse_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Nurse,
    .images = sPicTable_Nurse_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ReceptionistM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ReceptionistM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_ProfOak = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_ProfOak,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Man_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Man_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Rocker = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Rocker,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MrFuji = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MrFuji,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Bruno = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Bruno,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldManLyingDown = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 512,
    .width = 32,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_32x32,
    .subspriteTables = sOamTables_32x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_OldManLyingDown,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MartEmployee_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MartEmployee_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_MysteryEventDeliveryman_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_MysteryEventDeliveryman_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TrainerTowerDude = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_TrainerTowerDude,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Teala_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Teala_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_UnionRoomAttendant_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_UnionRoomAttendant_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_RocketGruntM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_RocketGruntM,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Celio = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Celio,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Agatha = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Agatha,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Brock = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Brock,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Misty = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Misty,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_LtSurge = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_LtSurge,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Erika = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Erika,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Koga = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Koga,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Giovanni = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Giovanni,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Blaine = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Blaine,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sabrina = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Sabrina,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Bill = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Bill,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Daisy = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Daisy,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lorelei = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lorelei,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Lance = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Lance,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Blue = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_7,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Blue,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GameBoyKid_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_6,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_GameBoyKid_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Mom_FRLG = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Mom_FRLG,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Clipboard = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Clipboard,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_GymSign = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_GymSign,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_OldAmber = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_OldAmber,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Pokedex = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Pokedex,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Ruby = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Ruby,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sapphire = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Sapphire,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Seagallop = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 2048,
    .width = 64,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_64x64,
    .subspriteTables = sOamTables_64x64,
    .anims = sAnimTable_Standard,
    .images = sPicTable_Seagallop,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Sign = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_Sign,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_SSAnne = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 4096,
    .width = 128,
    .height = 64,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_8x8,
    .subspriteTables = sOamTables_128x64,
    .anims = sAnimTable_Standard,
    .images = sPicTable_SSAnne,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_TownMap = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_5,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_TownMap,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_WoodenSign = {
    .paletteTag = OBJ_EVENT_PAL_TAG_GENERIC_8,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_S,
    .inanimate = TRUE,
    .tracks = TRACKS_NONE,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Inanimate,
    .images = sPicTable_WoodenSign,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooHost = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooHost,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooLittleGirl = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 128,
    .width = 16,
    .height = 16,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x16,
    .subspriteTables = sOamTables_16x16,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooLittleGirl,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooReceptionistBrown = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooReceptionistBrown,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooReceptionistSilver = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooReceptionistSilver,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooScoutF = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooScoutF,
    .affineAnims = gDummySpriteAffineAnimTable,
};

const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_YahooScoutM = {
    .paletteTag = OBJ_EVENT_PAL_TAG_UNIQUE,
    .size = 256,
    .width = 16,
    .height = 32,
    .shadowSize = SHADOW_SIZE_M,
    .inanimate = FALSE,
    .tracks = TRACKS_FOOT,
    .oam = &gObjectEventBaseOam_16x32,
    .subspriteTables = sOamTables_16x32,
    .anims = sAnimTable_Standard,
    .images = sPicTable_YahooScoutM,
    .affineAnims = gDummySpriteAffineAnimTable,
};
