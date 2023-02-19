#ifndef GUARD_GCN_CONTROLLER_H
#define GUARD_GCN_CONTROLLER_H

struct GCNCommunication {
    bool8 controllerEnabled;
    u8 currentByte;
    u16 amountOfBits;
    u8 buffer[80];
};

void GCNSerialInterrupt(void);
void GCNControllerFrameUpdate(void);
bool8 GCNControllerEnable(void);
void GCNControllerDisable(void);

extern EWRAM_DATA struct GCNCommunication gGCNCommunication;

#endif // GUARD_GCN_CONTROLLER_H