#include "global.h"
#include "rumble.h"
#include "main.h"
#include "sound.h"

EWRAM_DATA struct GBPCommunication gGBPCommunication;
EWRAM_DATA u32 gRumbleState = 0;

static u16 const sNintendoHandshakeData[] = {0x494E, 0x544E, 0x4E45, 0x4F44, 0x8000};

void GBPSerialInterrupt()
{
    u16 inputLow;
    u32 state = gGBPCommunication.state;
    u32 response = 0;

    gGBPCommunication.input = REG_SIODATA32;
    inputLow = gGBPCommunication.input;

    switch (gGBPCommunication.state) {
        case GBP_SERIAL_STATUS_NINTENDO_HANDSHAKE:
            if (inputLow == 0x8002)
            {
                response = 0x10000010;
                gGBPCommunication.state = GBP_SERIAL_STATUS_CHECK_MAGIC1;
                break;
            }

            if ((gGBPCommunication.input >> 16) != gGBPCommunication.outputLow)
                gGBPCommunication.handshakeIndex = 0;

            if (gGBPCommunication.input == (u32) ~(gGBPCommunication.outputLow | (gGBPCommunication.outputHigh << 16)))
                gGBPCommunication.handshakeIndex++;

            gGBPCommunication.outputHigh = sNintendoHandshakeData[gGBPCommunication.handshakeIndex];
            gGBPCommunication.outputLow = ~inputLow;
            response = gGBPCommunication.outputLow;
            response |= gGBPCommunication.outputHigh << 16;
            break;
        case GBP_SERIAL_STATUS_CHECK_MAGIC1:
            if (gGBPCommunication.input == 0x10000010)
            {
                response = 0x20000013;
                gGBPCommunication.state = GBP_SERIAL_STATUS_CHECK_MAGIC2;
            }
            else
            {
                gGBPCommunication.state = GBP_SERIAL_STATUS_RESET;
            }
            break;
        case GBP_SERIAL_STATUS_CHECK_MAGIC2:
            if (gGBPCommunication.input == 0x20000013)
            {
                response = 0x40000004;
                gGBPCommunication.state = GBP_SERIAL_STATUS_RUMBLE;
            }
            else
            {
                gGBPCommunication.state = GBP_SERIAL_STATUS_RESET;
            }
            break;
        case GBP_SERIAL_STATUS_RUMBLE:
            if (gGBPCommunication.input == 0x30000003)
                response = gRumbleState;
            else
                gGBPCommunication.state = GBP_SERIAL_STATUS_RESET;
            break;
        case GBP_SERIAL_STATUS_RESET:
            gGBPCommunication.input = 0;
            gGBPCommunication.state = GBP_SERIAL_STATUS_NINTENDO_HANDSHAKE;
            gGBPCommunication.handshakeIndex = 0;
            gGBPCommunication.outputHigh = 0;
            gGBPCommunication.outputLow = 0;
            return;
    }

    //DebugPrintf("%x - %x", gGBPCommunication.input, response);

    REG_SIODATA32 = response;
    REG_SIOCNT |= SIO_START;
    REG_IF = INTR_FLAG_SERIAL;
}

void RumbleFrameUpdate()
{
    if (gGameBoyPlayerDetected && gSaveBlock2Ptr->optionsRumble && gGBPCommunication.input != 0x30000003)
    {
        REG_SIOCNT &= ~1;
        REG_SIOCNT |= SIO_START;
    }
}

void SetRumbleState(u32 state)
{
    gRumbleState = state;

    if (!gGameBoyPlayerDetected) {
        GPIO_PORT_DIRECTION = 1 << 3;
        GPIO_PORT_DATA = (gRumbleState == RUMBLE_ON) << 3;
    }
}
