#ifndef GUARD_CONSTANTS_POWER_H
#define GUARD_CONSTANTS_POWER_H

#define POWER_NONE		0
#define POWER_HATCH		1
#define POWER_BARGAIN	2
#define POWER_PRIZE		3
#define POWER_EXP		4
#define POWER_CAPTURE	5
#define POWER_ENCOUNTER	6
#define POWER_STEALTH	7
#define POWER_FRIEND	8
#define POWER_ITEM		9
#define POWER_TRAINING	10
#define POWER_LUCKY		11

#define POWER_NUM_TYPES	(POWER_LUCKY + 1)
#define POWER_NUM_OPTIONS ((POWER_NUM_TYPES - 1) * 3)

#endif
