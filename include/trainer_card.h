#ifndef GUARD_TRAINER_CARD_H
#define GUARD_TRAINER_CARD_H

#define TRAINER_CARD_PROFILE_LENGTH  4
#define TRAINER_CARD_STICKER_TYPES   3

enum
{
    TRAINER_FRLG,
    TRAINER_RS,
    TRAINER_EMERALD,
    TRAINER_HELIODOR,
    TRAINER_CRYSTALDUST,
    TRAINER_TEST
};

enum
{
	CARD_LAYOUT_RS,
    CARD_LAYOUT_FRLG,
    CARD_LAYOUT_EMERALD,
    CARD_LAYOUT_HELIODOR
};

enum
{
	CARD_STAT_NONE,
	CARD_STAT_HOF_DEBUT,
	CARD_STAT_LINK_BATTLES,
	CARD_STAT_TRADES,
	CARD_STAT_POKEBLOCKS,
	CARD_STAT_CONTESTS,
	CARD_STAT_BATTLE_TOWER,
	CARD_STAT_UNION_ROOM,
	CARD_STAT_BERRY_CRUSH,
	CARD_STAT_BATTLE_POINTS,
	CARD_STAT_SHINIES,
	CARD_STAT_POWER_POINTS,
    CARD_STAT_POKE_COUPONS
};

enum
{
    MON_ICON_TINT_NORMAL,
    MON_ICON_TINT_BLACK,
    MON_ICON_TINT_PINK,
    MON_ICON_TINT_SEPIA,
};

struct TrainerCard
{
    /*0x00*/ u8 gender;
    /*0x01*/ u8 stars;
    /*0x02*/ bool8 hasPokedex;
    /*0x03*/ u8 cardLayout; // caughtAllHoenn in FRLGE
    /*0x04*/ u8 outfit; // hasAllPaintings in FRLGE
	/*0x05*/ u8 extraStars;
    /*0x06*/ u16 hofDebutHours;
    /*0x08*/ u16 hofDebutMinutes;
    /*0x0A*/ u16 hofDebutSeconds;
    /*0x0C*/ u16 caughtMonsCount; // pokedexSeen in RS
    /*0x0E*/ u16 trainerId;
    /*0x10*/ u16 playTimeHours;
    /*0x12*/ u16 playTimeMinutes;
    /*0x14*/ u16 linkBattleWins;
    /*0x16*/ u16 linkBattleLosses;
    /*0x18*/ u16 battleTowerWins;
    /*0x1A*/ u16 battleTowerStraightWins;
    /*0x1C*/ u16 contestsWithFriends;
    /*0x1E*/ u16 pokeblocksWithFriends;
    /*0x20*/ u16 pokemonTrades;
	/*0x22*/ u16 shinies;
    /*0x24*/ u32 money;
    /*0x28*/ u16 easyChatProfile[TRAINER_CARD_PROFILE_LENGTH];
    /*0x30*/ u8 playerName[PLAYER_NAME_LENGTH + 1]; // RS ends here
    /*0x38*/ u8 version;
	/*0x39*/ u8 crystalDustVersion;
    /*0x3A*/ u16 secretId; // hasAllFrontierSymbols in FRLG, linkHasAllFrontierSymbols in E
    /*0x3C*/ u32 berryCrushPoints;
    /*0x40*/ u32 unionRoomNum;
    /*0x44*/ u32 pokeCoupons:24; // berriesPicked in FRLG
             u32 filler:8;
    /*0x48*/ u32 jumpsInRow; // Free for use
    /*0x4C*/ bool8 shouldDrawStickers;
    /*0x4D*/ bool8 hasAllMons; // Free for use
    /*0x4E*/ u8 monIconTint;
    /*0x4F*/ u8 facilityClass;
    /*0x50*/ u8 stickers[TRAINER_CARD_STICKER_TYPES];
	/*0x53*/ u8 versionModifier;
    /*0x54*/ u16 monSpecies[PARTY_SIZE]; // FRLG ends here
             // Note: Link players use hasAllFrontierSymbols, not the field below,
             // which they use for a Wonder Card flag id instead (see CreateTrainerCardInBuffer)
    /*0x60*/ bool16 hasAllSymbols; // Gets overwritten with Wonder Card ID, E then overwrites again with secretId after receiving; in short, we can't really use this for anything
    /*0x62*/ u16 frontierBP; // E ends here
	/*0x64*/ u32 monForm0:2;
	         u32 monForm1:2;
	         u32 monForm2:2;
	         u32 monForm3:2;
	         u32 monForm4:2;
	         u32 monForm5:2;
	         u32 stat0:4;
	         u32 stat1:4;
	         u32 stat2:4;
	         u32 stat3:4;
	         u32 stat4:4;
	/*0x68*/ u16 powerPoints;
	/*0x6A*/ u16 hSticker0:3;
	         u16 hSticker1:3;
	         u16 hSticker2:3;
			 u16 displayDotCode:1;
             u16 filler2:6;
};

extern struct TrainerCard gTrainerCards[4];

u32 CountPlayerTrainerStars(void);
u8 GetTrainerCardStars(u8 cardId);
void CopyTrainerCardData(struct TrainerCard *dst, struct TrainerCard *src, u8 gameVersion, u8 versionModifier);
void ShowPlayerTrainerCard(void (*callback)(void));
void ShowTrainerCardInLink(u8 cardId, void (*callback)(void));
void TrainerCard_GenerateCardForPlayer(struct TrainerCard *);

#endif // GUARD_TRAINER_CARD_H
