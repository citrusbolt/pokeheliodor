	.align 2
gTilesetPalOverrides_General::
	.byte 5             @ palette index
	.byte HOUR_NIGHT    @ start hour (inclusive)
	.byte HOUR_MORNING  @ end hour (exclusive)
	.byte 0             @ padding
	.4byte gTilesetPalOverride_General05

	.byte 0xFF
	.byte 0
	.byte 0
	.byte 0 @ padding
	.4byte NULL
