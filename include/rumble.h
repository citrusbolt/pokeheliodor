#ifndef GUARD_RUMBLE_H
#define GUARD_RUMBLE_H

enum {
    RUMBLE_ON        = 0x40000026,
    RUMBLE_OFF       = 0x40000004,
    RUMBLE_HARD_STOP = 0x40000015
};

enum {
    GBP_SERIAL_STATUS_NINTENDO_HANDSHAKE,
    GBP_SERIAL_STATUS_CHECK_MAGIC1,
    GBP_SERIAL_STATUS_CHECK_MAGIC2,
    GBP_SERIAL_STATUS_RUMBLE,
    GBP_SERIAL_STATUS_RESET
};

struct GBPCommunication {
    u32 state;
    u32 input;
    u16 handshakeIndex;
    u16 outputHigh;
    u16 outputLow;
};

void GBPSerialInterrupt();
void RumbleFrameUpdate();
void SetRumbleState(u32 state);

extern EWRAM_DATA struct GBPCommunication gGBPCommunication;
extern EWRAM_DATA u32 gRumbleState;

#endif // GUARD_RUMBLE_H