#ifndef GUARD_ITEM_ICON_H
#define GUARD_ITEM_ICON_H

extern u8 *gItemIconDecompressionBuffer;
extern u8 *gItemIcon4x4Buffer;
extern u8 *gLangLabelBuffer;
extern u8 *gLangLabelDecompressionBuffer;

extern const struct SpriteTemplate gItemIconSpriteTemplate;
extern const struct SpriteTemplate gBallIconSpriteTemplate;
extern const struct SpriteTemplate gLangLabelSpriteTemplate;

bool8 AllocItemIconTemporaryBuffers(void);
void FreeItemIconTemporaryBuffers(void);
void CopyItemIconPicTo4x4Buffer(const void *src, void *dest);
u8 AddItemIconSprite(u16 tilesTag, u16 paletteTag, u16 itemId);
u8 AddCustomItemIconSprite(const struct SpriteTemplate *customSpriteTemplate, u16 tilesTag, u16 paletteTag, u16 itemId);
const void *GetItemIconPicOrPalette(u16 itemId, u8 which);
u8 AddBallIconSprite(u16 tilesTag, u16 paletteTag, u8 ballId);
u8 AddLangLabelSprite(u16 tilesTag, u16 paletteTag, u8 lang);

#endif //GUARD_ITEM_ICON_H
