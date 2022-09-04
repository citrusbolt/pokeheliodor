#ifndef GUARD_RUMBLE_H
#define GUARD_RUMBLE_H

void RumbleGBPConfig();


enum RumbleState {
    rumble_start     = 0x40000026,
    rumble_stop      = 0x40000004,
    rumble_hard_stop = 0x40000015,
};

enum GBPCommsStage {
    gbp_comms_nintendo_handshake,
    gbp_comms_check_magic1,
    gbp_comms_check_magic2,
    gbp_comms_rumble,
    gbp_comms_finalize
};

struct GBPComms {
    enum GBPCommsStage stage_;
    u32 serial_in_;
    u16 index_;
    u16 out_0_;
    u16 out_1_;
};
void rumble_set_state(enum RumbleState state);

void rumble_init();

void rumble_update();
void gbp_serial_isr();

extern EWRAM_DATA u8 rumble_state;
extern EWRAM_DATA struct GBPComms gbp_comms;

extern u8 const comms_handshake_data[];

#endif // GUARD_RUMBLE_H