#include "global.h"
#include "rumble.h"
#include "main.h"
#include "sound.h"

EWRAM_DATA u32 rumble_state = 0;


u8 const comms_handshake_data[] = {"NINTENDO"};

EWRAM_DATA struct GBPComms gbp_comms;


static void gbp_serial_start()
{

    if (gbp_comms.serial_in_ == 0x30000003) {
        /* We're currently in the middle of the GBP comms rumble stage. */
        return;
    }

    REG_SIOCNT &= ~1;
    REG_SIOCNT |= SIO_START;
}


void gbp_serial_isr()
{
    u32 state = gbp_comms.stage_;
    u32 result = 0;
    gbp_comms.serial_in_ = REG_SIODATA32;

    if (!IsSEPlaying())
        rumble_state = rumble_stop;

    switch (gbp_comms.stage_) {
    case gbp_comms_rumble:
        if (gbp_comms.serial_in_ == 0x30000003) {
            result = rumble_state;
        } else {
            gbp_comms.stage_ = gbp_comms_finalize;
        }
        break;

    case gbp_comms_finalize: {
        gbp_comms.serial_in_ = 0;
        gbp_comms.stage_ = gbp_comms_nintendo_handshake;
        gbp_comms.index_ = 0;
        gbp_comms.out_0_ = 0;
        gbp_comms.out_1_ = 0;
        return;
    }

    case gbp_comms_nintendo_handshake: {
        const u16 in_lower = gbp_comms.serial_in_;
        static u16 const comms_handshake_data[] = {0x494E, 0x544E, 0x4E45, 0x4F44, 0x8000};

        if (in_lower == 0x8002) {
            result = 0x10000010;
            gbp_comms.stage_ = gbp_comms_check_magic1;
            break;
        }

        if ((gbp_comms.serial_in_ >> 16) != gbp_comms.out_1_) {
            gbp_comms.index_ = 0;
        }

        if (gbp_comms.index_ > 3) {
            gbp_comms.out_0_ = 0x8000;
        } else {
            if (gbp_comms.serial_in_ ==
                (u32) ~(gbp_comms.out_1_ | (gbp_comms.out_0_ << 16))) {
                gbp_comms.index_ += 1;
            }


            gbp_comms.out_0_ = comms_handshake_data[gbp_comms.index_];
        }

        gbp_comms.out_1_ = ~in_lower;
        result = gbp_comms.out_1_;
        result |= gbp_comms.out_0_ << 16;
        break;
    }

    case gbp_comms_check_magic1:
        /* The GBATEK reference says to check for these integer constants in
           this order... but why? Who knows. Anyway, it seems to work. */
        if (gbp_comms.serial_in_ == 0x10000010) {
            result = 0x20000013;
            gbp_comms.stage_ = gbp_comms_check_magic2;
        } else {
            gbp_comms.stage_ = gbp_comms_finalize;
        }
        break;

    case gbp_comms_check_magic2:
        if (gbp_comms.serial_in_ == 0x20000013) {
            result = 0x40000004;
            gbp_comms.stage_ = gbp_comms_rumble;
        } else {
            gbp_comms.stage_ = gbp_comms_finalize;
        }
        break;
    }

    //DebugPrintf("%x - %x", gbp_comms.serial_in_, result);

    REG_SIODATA32 = result;
    REG_SIOCNT |= SIO_START;
    REG_IF = INTR_FLAG_SERIAL;
}


void rumble_init()
{
    rumble_state = rumble_stop;

    
        //config->serial_irq_setup_(gbp_serial_isr);
        REG_RCNT = 0;
        REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD;
        REG_SIOCNT |= SIO_INTR_ENABLE;
        gGameBoyPlayerDetected = TRUE;
        gbp_comms.serial_in_ = 0;
        gbp_comms.stage_ = gbp_comms_nintendo_handshake;
        gbp_comms.index_ = 0;
        gbp_comms.out_0_ = 0;
        gbp_comms.out_1_ = 0;
}


void rumble_update()
{
    if (gGameBoyPlayerDetected) {
        gbp_serial_start();
    }
}


void rumble_set_state(u32 state)
{
    rumble_state = state;

    if (!gGameBoyPlayerDetected) {
        GPIO_PORT_DIRECTION = 1 << 3;
        GPIO_PORT_DATA = (rumble_state == rumble_start) << 3;
    }
}
