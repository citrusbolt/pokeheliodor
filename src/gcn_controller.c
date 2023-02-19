#include "global.h"
#include "gcn_controller.h"
#include "main.h"
#include "link.h"
#include "gpu_regs.h"

#define CMD_ID          0x00
#define CMD_STATUS      0x40
#define CMD_ORIGIN      0x41
#define CMD_RECALIBRATE 0x42
#define CMD_STATUS_LONG 0x43
#define CMD_RESET       0xFF

#define BIOS_HALT       0x00
#define BIOS_STOP       0x80

#define R_GPIO      0x8000
#define GPIO_IRQ    0x100
#define GPIO_SO_IO  0x80
#define GPIO_SO     0x8

#define GCN_RUMBLE_OFF          0
#define GCN_RUMBLE_ON           1
#define GCN_RUMBLE_HARD_STOP    2

struct mode0 {
    u32 cStickX:8;
    u32 cStickY:8;
    u32 lAnalog:4;
    u32 rAnalog:4;
    u32 a:4;
    u32 b:4;
};

struct mode1 {
    u32 cStickX:4;
    u32 cStickY:4;
    u32 lAnalog:8;
    u32 rAnalog:8;
    u32 a:4;
    u32 b:4;
};

struct mode2 {
    u32 cStickX:4;
    u32 cStickY:4;
    u32 lAnalog:4;
    u32 rAnalog:4;
    u32 a:8;
    u32 b:8;
};

struct mode3 {
    u32 cStickX:8;
    u32 cStickY:8;
    u32 lAnalog:8;
    u32 rAnalog:8;
};

struct mode4 {
    u32 cStickX:8;
    u32 cStickY:8;
    u32 a:8;
    u32 b:8;
};

struct modeLong {
    u8 cStickX;
    u8 cStickY;
    u8 lAnalog;
    u8 rAnalog;
    u8 a;
    u8 b;
    u16 padding; // not sent
};

struct inputData {
    u16 errStat:1;
    u16 errLatch:1;
    u16 getOrigin:1;
    u16 start:1;
    u16 y:1;
    u16 x:1;
    u16 b:1;
    u16 a:1;
    u16 useOrigin:1;
    u16 l:1;
    u16 r:1;
    u16 z:1;
    u16 up:1;
    u16 down:1;
    u16 right:1;
    u16 left:1;
    u8 analogStickX;
    u8 analogStickY;
    
    union {
        struct mode0 m0;
        struct mode1 m1;
        struct mode2 m2;
        struct mode3 m3;
        struct mode4 m4;
        struct modeLong mLong;
    } mode;
};

struct statusData {
    u16 deviceId;
    u8 unknown:1;
    u8 errLatch:1;
    u8 getOrigin:1;
    u8 rumbleState:2;
    u8 mode:3;
    u8 padding; // not sent
};

EWRAM_DATA struct inputData inputBuffer = {
    .getOrigin = TRUE,
    .useOrigin = TRUE,
    .analogStickX = 128,
    .analogStickY = 128,
};

EWRAM_DATA struct inputData inputToSend;

EWRAM_DATA struct statusData status;

EWRAM_DATA struct GCNCommunication gGCNCommunication;

static inline void CustomHalt(u8 flag)
{
    register int r2 asm("r2") = flag;
	asm volatile("mov lr, pc; mov pc, #0x000001AC" :: "r" (r2) : "ip", "lr", "memory");
}

static void GCNSendComm(void* buffer, u8 commSize)
{
    u32 byte = 0;
    u32 bit = 0;

    do {
        if (bit++ % 8 == 0)
            byte = *(u8*)buffer++;
        byte <<= 1;

        if (byte & 0x100) {
            asm volatile (
                "strb  %0, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %1, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %1, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %1, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                :
                : "r" (GPIO_SO_IO), "r" (GPIO_SO_IO | GPIO_SO),
                "m" (REG_RCNT)
                : "memory"
            );
        } else {
            asm volatile (
                "strb  %0, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %0, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %0, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "strb  %1, %2 \n"
                "nop \n"
                "nop \n"
                "nop \n"
                "nop \n"
                :
                : "r" (GPIO_SO_IO), "r" (GPIO_SO_IO | GPIO_SO),
                "m" (REG_RCNT)
                : "memory"
            );
        }
    } while (bit < commSize);

    asm volatile (
        "nop \n"
        "nop \n"
        "nop \n"
        "strb  %0, %2 \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "nop \n"
        "strb  %1, %2 \n"
        :
        : "r" (GPIO_SO_IO), "r" (GPIO_SO_IO | GPIO_SO),
        "m" (REG_RCNT)
        : "memory"
    );
}

void GCNTimerInterrrupt(void)
{
    u16 length;
    u32 buttons;
    
    //DebugPrintf("timer", NULL);
    
    REG_TM1CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER1;
    REG_TM1CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE;
    
    //if (REG_KEYINPUT & (START_BUTTON | A_BUTTON))
    //{
    //    GCNControllerDisable();
    //    return;
    //}
    
    length = gGCNCommunication.amountOfBits;
    
    if (length >= 8)
    {
        gGCNCommunication.currentByte = 0;
        gGCNCommunication.amountOfBits = 0;
        
        buttons = REG_KEYINPUT ^ KEYS_MASK;
        if (buttons & (START_BUTTON | B_BUTTON))
        {
            GCNControllerDisable();
            return;
        }
        
        inputBuffer.errStat     = 0;
        inputBuffer.errLatch    = 0;
        inputBuffer.start       = !!(buttons & START_BUTTON);
        inputBuffer.y           = 0;
        inputBuffer.x           = 0;
        inputBuffer.b           = !!(buttons & B_BUTTON);
        inputBuffer.a           = !!(buttons & A_BUTTON);
        inputBuffer.r           = !!(buttons & L_BUTTON);
        inputBuffer.l           = !!(buttons & R_BUTTON);
        inputBuffer.z           = !!(buttons & SELECT_BUTTON);
    
        #ifndef EMU_ANALOG
        inputBuffer.up          = !!(buttons & DPAD_UP);
        inputBuffer.down        = !!(buttons & DPAD_DOWN);
        inputBuffer.right       = !!(buttons & DPAD_RIGHT);
        inputBuffer.left        = !!(buttons & DPAD_LEFT);
        #endif
    
        status.getOrigin  = inputBuffer.getOrigin;
        status.errLatch   = inputBuffer.errLatch;
    
        switch (gGCNCommunication.buffer[0]) {
            case CMD_RESET:
                status.rumbleState = GCN_RUMBLE_OFF;
            case CMD_ID:
                if (length == 8 + 1) {
                        status.deviceId = 0x2900; // Standard GCN controller, but missing rumble
        
                    GCNSendComm(&status, 24);
                }
                break;
            case CMD_STATUS:
                if (length == 24 + 1) {
                    u32 mode  = gGCNCommunication.buffer[1] & 7;
                    u32 rumbleState = gGCNCommunication.buffer[2] & 3;
        
                    status.mode = mode;
                    if (rumbleState <= GCN_RUMBLE_HARD_STOP)
                        status.rumbleState = rumbleState;
    
                    inputToSend.errStat         = inputBuffer.errStat;
                    inputToSend.errLatch        = inputBuffer.errLatch;
                    inputToSend.getOrigin       = inputBuffer.getOrigin;
                    inputToSend.start           = inputBuffer.start;
                    inputToSend.y               = inputBuffer.y;
                    inputToSend.x               = inputBuffer.x;
                    inputToSend.b               = inputBuffer.b;
                    inputToSend.a               = inputBuffer.a;
                    inputToSend.useOrigin       = inputBuffer.useOrigin;
                    inputToSend.l               = inputBuffer.l;
                    inputToSend.r               = inputBuffer.r;
                    inputToSend.z               = inputBuffer.z;
                    inputToSend.up              = inputBuffer.up;
                    inputToSend.down            = inputBuffer.down;
                    inputToSend.right           = inputBuffer.right;
                    inputToSend.left            = inputBuffer.left;
                    inputToSend.analogStickX    = inputBuffer.analogStickX;
                    inputToSend.analogStickY    = inputBuffer.analogStickY;
    
                    #ifdef EMU_ANALOG
                    if (JOY_HELD(DPAD_RIGHT))
                        inputToSend.analogStickX += 100;
                    else if (JOY_HELD(DPAD_LEFT))
                        inputToSend.analogStickX -= 100;
                    if (JOY_HELD(DPAD_UP))
                        inputToSend.analogStickY += 100;
                    else if (JOY_HELD(DPAD_DOWN))
                        inputToSend.analogStickY -= 100;
                    #endif
    
                    switch (status.mode) {
                        default:
                            inputToSend.mode.m0.cStickX   = inputBuffer.mode.mLong.cStickX;
                            inputToSend.mode.m0.cStickY   = inputBuffer.mode.mLong.cStickY;
                            inputToSend.mode.m0.lAnalog   = (buttons & L_BUTTON ? 200 : 0) >> 4;
                            inputToSend.mode.m0.rAnalog   = (buttons & R_BUTTON ? 200 : 0) >> 4;
                            inputToSend.mode.m0.a         = (buttons & A_BUTTON ? 200 : 0) >> 4;
                            inputToSend.mode.m0.b         = (buttons & B_BUTTON ? 200 : 0) >> 4;
                            break;
                        case 1:
                            inputToSend.mode.m1.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
                            inputToSend.mode.m1.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
                            inputToSend.mode.m1.lAnalog   = (buttons & L_BUTTON ? 200 : 0);
                            inputToSend.mode.m1.rAnalog   = (buttons & R_BUTTON ? 200 : 0);
                            inputToSend.mode.m1.a         = (buttons & A_BUTTON ? 200 : 0)  >> 4;
                            inputToSend.mode.m1.b         = (buttons & B_BUTTON ? 200 : 0)  >> 4;
                            break;
                        case 2:
                            inputToSend.mode.m2.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
                            inputToSend.mode.m2.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
                            inputToSend.mode.m2.lAnalog   = (buttons & L_BUTTON ? 200 : 0) >> 4;
                            inputToSend.mode.m2.rAnalog   = (buttons & R_BUTTON ? 200 : 0) >> 4;
                            inputToSend.mode.m2.a         = (buttons & A_BUTTON ? 200 : 0);
                            inputToSend.mode.m2.b         = (buttons & B_BUTTON ? 200 : 0);
                            break;
                        case 3:
                            inputToSend.mode.m3.cStickX   = inputBuffer.mode.mLong.cStickX;
                            inputToSend.mode.m3.cStickY   = inputBuffer.mode.mLong.cStickY;
                            inputToSend.mode.m3.lAnalog   = (buttons & L_BUTTON ? 200 : 0);
                            inputToSend.mode.m3.rAnalog   = (buttons & R_BUTTON ? 200 : 0);
                            break;
                        case 4:
                            inputToSend.mode.m4.cStickX   = inputBuffer.mode.mLong.cStickX;
                            inputToSend.mode.m4.cStickY   = inputBuffer.mode.mLong.cStickY;
                            inputToSend.mode.m4.a         = (buttons & A_BUTTON ? 200 : 0);
                            inputToSend.mode.m4.b         = (buttons & B_BUTTON ? 200 : 0);
                            break;
                    }
    
                    GCNSendComm(&inputToSend, 64);
                }
                break;
            case CMD_ORIGIN:
                if (length == 8 + 1) {
                    inputBuffer.getOrigin = FALSE;
                    GCNSendComm(&inputBuffer, 80);
                }
                break;
            case CMD_RECALIBRATE:
                if (length == 24 + 1) {
                    inputBuffer.getOrigin = FALSE;
                    GCNSendComm(&inputBuffer, 80);
                }
                break;
            case CMD_STATUS_LONG:
                if (length == 24 + 1) {
                    u32 rumbleState = gGCNCommunication.buffer[2] & 3;
    
                    if (rumbleState <= GCN_RUMBLE_HARD_STOP)
                        status.rumbleState = rumbleState;
    
                    inputToSend.errStat         = inputBuffer.errStat;
                    inputToSend.errLatch        = inputBuffer.errLatch;
                    inputToSend.getOrigin       = inputBuffer.getOrigin;
                    inputToSend.start           = inputBuffer.start;
                    inputToSend.y               = inputBuffer.y;
                    inputToSend.x               = inputBuffer.x;
                    inputToSend.b               = inputBuffer.b;
                    inputToSend.a               = inputBuffer.a;
                    inputToSend.useOrigin       = inputBuffer.useOrigin;
                    inputToSend.l               = inputBuffer.l;
                    inputToSend.r               = inputBuffer.r;
                    inputToSend.z               = inputBuffer.z;
                    inputToSend.up              = inputBuffer.up;
                    inputToSend.down            = inputBuffer.down;
                    inputToSend.right           = inputBuffer.right;
                    inputToSend.left            = inputBuffer.left;
                    inputToSend.analogStickX    = inputBuffer.analogStickX;
                    inputToSend.analogStickY    = inputBuffer.analogStickY;
    
                    #ifdef EMU_ANALOG
                    if (JOY_HELD(DPAD_RIGHT))
                        inputToSend.analogStickX += 100;
                    else if (JOY_HELD(DPAD_LEFT))
                        inputToSend.analogStickX -= 100;
                    if (JOY_HELD(DPAD_UP))
                        inputToSend.analogStickY += 100;
                    else if (JOY_HELD(DPAD_DOWN))
                        inputToSend.analogStickY -= 100;
                    #endif
    
                    inputToSend.mode.mLong.cStickX    = inputBuffer.mode.mLong.cStickX;
                    inputToSend.mode.mLong.cStickY    = inputBuffer.mode.mLong.cStickY;
                    inputToSend.mode.mLong.lAnalog    = (buttons & L_BUTTON ? 200 : 0);
                    inputToSend.mode.mLong.rAnalog    = (buttons & R_BUTTON ? 200 : 0);
                    inputToSend.mode.mLong.a          = (buttons & A_BUTTON ? 200 : 0);
                    inputToSend.mode.mLong.b          = (buttons & B_BUTTON ? 200 : 0);
    
                    GCNSendComm(&status, 80);
                }
                break;
        }
    }
}
    
    //u32 byte = 0;
    //u32 bit = 0;
    //u32 irq = 0;
    //
    //DebugPrintf("receive", NULL);
    //REG_TM1CNT_H = 0;
    //REG_TM2CNT_H = 0;
    //irq = REG_IF;
    //DebugPrintf("%x", irq);
    //if (irq & INTR_FLAG_SERIAL)
    //    REG_IF = INTR_FLAG_SERIAL;
    //if (irq & INTR_FLAG_TIMER1)
    //    REG_IF = INTR_FLAG_TIMER1;
    //if (irq & INTR_FLAG_TIMER2)
    //    REG_IF = INTR_FLAG_TIMER2;
	////REG_TM2CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE | TIMER_1024CLK;
    //
    //do {
    //DebugPrintf("%x", gGCNCommunication.amountOfBits);
    //    //if (irq & INTR_FLAG_TIMER2)
    //    //    CustomHalt(BIOS_STOP);
    //    //else
    //    //    CustomHalt(BIOS_HALT);
    //
    //DebugPrintf("here1", NULL);
    //    REG_TM1CNT_H = 0;
    //    irq = REG_IF;
    //DebugPrintf("here1a", NULL);
    //DebugPrintf("%x", irq);
    //    if (irq & INTR_FLAG_SERIAL)
    //        REG_IF = INTR_FLAG_SERIAL;
    //    if (irq & INTR_FLAG_TIMER1)
    //        REG_IF = INTR_FLAG_TIMER1;
    //    if (irq & INTR_FLAG_TIMER2)
    //        REG_IF = INTR_FLAG_TIMER2;
    //    //REG_IF = irq;
    //DebugPrintf("here1b", NULL);
    //    REG_TM1CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE;
    //DebugPrintf("here1c", NULL);
    //
    //DebugPrintf("here2", NULL);
    //    if (irq & INTR_FLAG_SERIAL) {
    //DebugPrintf("here3", NULL);
    //        gGCNCommunication.currentByte <<= 1;
    //        gGCNCommunication.currentByte |= !!((REG_RCNT | REG_RCNT | REG_RCNT) & 4);
    //    
    //        if (++gGCNCommunication.amountOfBits % 8 == 0)
    //            *((u8*)gGCNCommunication.buffer + (gGCNCommunication.amountOfBits / 8)) = gGCNCommunication.currentByte;
    //    } else if (irq & INTR_FLAG_TIMER1)
    //    {
    //        
    //DebugPrintf("woah", NULL);
    //        break;
    //    }
    //} while (gGCNCommunication.amountOfBits < bufferSizeInBits);
    //
    //return gGCNCommunication.amountOfBits;
//}

void GCNSerialInterrupt(void)
{
    //DebugPrintf("serial", NULL);
    REG_TM1CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER1;
    REG_IF = INTR_FLAG_SERIAL;
    REG_TM1CNT_H = TIMER_ENABLE | TIMER_INTR_ENABLE;
    
    
//    DebugPrintf("%x", gGCNCommunication.amountOfBits);
    gGCNCommunication.currentByte <<= 1;
    gGCNCommunication.currentByte |= !!((REG_RCNT | REG_RCNT | REG_RCNT) & 4);

    if (++gGCNCommunication.amountOfBits % 8 == 0)
        *((u8*)gGCNCommunication.buffer + (gGCNCommunication.amountOfBits / 8)) = gGCNCommunication.currentByte;

//    DebugPrintf("here", NULL);
    if (gGCNCommunication.amountOfBits > sizeof(gGCNCommunication.buffer) * 8)
    {
        gGCNCommunication.currentByte = 0;
        gGCNCommunication.amountOfBits = 0;
    }
}
//        return;
//
//
//    if (JOY_HELD(L_BUTTON | A_BUTTON))
//    {
//        GCNControllerDisable();
//        return;
//    }
//
//    inputBuffer.errStat     = 0;
//    inputBuffer.errLatch    = 0;
//    inputBuffer.start       = !!(JOY_HELD(START_BUTTON));
//    inputBuffer.y           = 0;
//    inputBuffer.x           = 0;
//    inputBuffer.b           = !!(JOY_HELD(B_BUTTON));
//    inputBuffer.a           = !!(JOY_HELD(A_BUTTON));
//    inputBuffer.r           = !!(JOY_HELD(L_BUTTON));
//    inputBuffer.l           = !!(JOY_HELD(R_BUTTON));
//    inputBuffer.z           = !!(JOY_HELD(SELECT_BUTTON));
//
//    #ifndef EMU_ANALOG
//    inputBuffer.up          = !!(JOY_HELD(DPAD_UP));
//    inputBuffer.down        = !!(JOY_HELD(DPAD_DOWN));
//    inputBuffer.right       = !!(JOY_HELD(DPAD_RIGHT));
//    inputBuffer.left        = !!(JOY_HELD(DPAD_LEFT));
//    #endif
//
//    status.getOrigin  = inputBuffer.getOrigin;
//    status.errLatch   = inputBuffer.errLatch;
//
//    switch (gGCNCommunication.buffer[0]) {
//        case CMD_RESET:
//            status.rumbleState = GCN_RUMBLE_OFF;
//        case CMD_ID:
//            if (length == 8 + 1) {
//                    status.deviceId = 0x2900; // Standard GCN controller, but missing rumble
//    
//                GCNSendComm(&status, 24);
//            }
//            break;
//        case CMD_STATUS:
//            if (length == 24 + 1) {
//                u32 mode  = gGCNCommunication.buffer[1] & 7;
//                u32 rumbleState = gGCNCommunication.buffer[2] & 3;
//    
//                status.mode = mode;
//                if (rumbleState <= GCN_RUMBLE_HARD_STOP)
//                    status.rumbleState = rumbleState;
//
//                inputToSend.errStat         = inputBuffer.errStat;
//                inputToSend.errLatch        = inputBuffer.errLatch;
//                inputToSend.getOrigin       = inputBuffer.getOrigin;
//                inputToSend.start           = inputBuffer.start;
//                inputToSend.y               = inputBuffer.y;
//                inputToSend.x               = inputBuffer.x;
//                inputToSend.b               = inputBuffer.b;
//                inputToSend.a               = inputBuffer.a;
//                inputToSend.useOrigin       = inputBuffer.useOrigin;
//                inputToSend.l               = inputBuffer.l;
//                inputToSend.r               = inputBuffer.r;
//                inputToSend.z               = inputBuffer.z;
//                inputToSend.up              = inputBuffer.up;
//                inputToSend.down            = inputBuffer.down;
//                inputToSend.right           = inputBuffer.right;
//                inputToSend.left            = inputBuffer.left;
//                inputToSend.analogStickX    = inputBuffer.analogStickX;
//                inputToSend.analogStickY    = inputBuffer.analogStickY;
//
//                #ifdef EMU_ANALOG
//                if (JOY_HELD(DPAD_RIGHT))
//                    inputToSend.analogStickX += 100;
//                else if (JOY_HELD(DPAD_LEFT))
//                    inputToSend.analogStickX -= 100;
//                if (JOY_HELD(DPAD_UP))
//                    inputToSend.analogStickY += 100;
//                else if (JOY_HELD(DPAD_DOWN))
//                    inputToSend.analogStickY -= 100;
//                #endif
//
//                switch (status.mode) {
//                    default:
//                        inputToSend.mode.m0.cStickX   = inputBuffer.mode.mLong.cStickX;
//                        inputToSend.mode.m0.cStickY   = inputBuffer.mode.mLong.cStickY;
//                        inputToSend.mode.m0.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0) >> 4;
//                        inputToSend.mode.m0.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0) >> 4;
//                        inputToSend.mode.m0.a         = (JOY_HELD(A_BUTTON) ? 200 : 0) >> 4;
//                        inputToSend.mode.m0.b         = (JOY_HELD(B_BUTTON) ? 200 : 0) >> 4;
//                        break;
//                    case 1:
//                        inputToSend.mode.m1.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
//                        inputToSend.mode.m1.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
//                        inputToSend.mode.m1.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0);
//                        inputToSend.mode.m1.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0);
//                        inputToSend.mode.m1.a         = (JOY_HELD(A_BUTTON) ? 200 : 0)  >> 4;
//                        inputToSend.mode.m1.b         = (JOY_HELD(B_BUTTON) ? 200 : 0)  >> 4;
//                        break;
//                    case 2:
//                        inputToSend.mode.m2.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
//                        inputToSend.mode.m2.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
//                        inputToSend.mode.m2.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0) >> 4;
//                        inputToSend.mode.m2.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0) >> 4;
//                        inputToSend.mode.m2.a         = (JOY_HELD(A_BUTTON) ? 200 : 0);
//                        inputToSend.mode.m2.b         = (JOY_HELD(B_BUTTON) ? 200 : 0);
//                        break;
//                    case 3:
//                        inputToSend.mode.m3.cStickX   = inputBuffer.mode.mLong.cStickX;
//                        inputToSend.mode.m3.cStickY   = inputBuffer.mode.mLong.cStickY;
//                        inputToSend.mode.m3.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0);
//                        inputToSend.mode.m3.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0);
//                        break;
//                    case 4:
//                        inputToSend.mode.m4.cStickX   = inputBuffer.mode.mLong.cStickX;
//                        inputToSend.mode.m4.cStickY   = inputBuffer.mode.mLong.cStickY;
//                        inputToSend.mode.m4.a         = (JOY_HELD(A_BUTTON) ? 200 : 0);
//                        inputToSend.mode.m4.b         = (JOY_HELD(B_BUTTON) ? 200 : 0);
//                        break;
//                }
//
//                GCNSendComm(&inputToSend, 64);
//            }
//            break;
//        case CMD_ORIGIN:
//            if (length == 8 + 1) {
//                inputBuffer.getOrigin = FALSE;
//                GCNSendComm(&inputBuffer, 80);
//            }
//            break;
//        case CMD_RECALIBRATE:
//            if (length == 24 + 1) {
//                inputBuffer.getOrigin = FALSE;
//                GCNSendComm(&inputBuffer, 80);
//            }
//            break;
//        case CMD_STATUS_LONG:
//            if (length == 24 + 1) {
//                u32 rumbleState = gGCNCommunication.buffer[2] & 3;
//
//                if (rumbleState <= GCN_RUMBLE_HARD_STOP)
//                    status.rumbleState = rumbleState;
//
//                inputToSend.errStat         = inputBuffer.errStat;
//                inputToSend.errLatch        = inputBuffer.errLatch;
//                inputToSend.getOrigin       = inputBuffer.getOrigin;
//                inputToSend.start           = inputBuffer.start;
//                inputToSend.y               = inputBuffer.y;
//                inputToSend.x               = inputBuffer.x;
//                inputToSend.b               = inputBuffer.b;
//                inputToSend.a               = inputBuffer.a;
//                inputToSend.useOrigin       = inputBuffer.useOrigin;
//                inputToSend.l               = inputBuffer.l;
//                inputToSend.r               = inputBuffer.r;
//                inputToSend.z               = inputBuffer.z;
//                inputToSend.up              = inputBuffer.up;
//                inputToSend.down            = inputBuffer.down;
//                inputToSend.right           = inputBuffer.right;
//                inputToSend.left            = inputBuffer.left;
//                inputToSend.analogStickX    = inputBuffer.analogStickX;
//                inputToSend.analogStickY    = inputBuffer.analogStickY;
//
//                #ifdef EMU_ANALOG
//                if (JOY_HELD(DPAD_RIGHT))
//                    inputToSend.analogStickX += 100;
//                else if (JOY_HELD(DPAD_LEFT))
//                    inputToSend.analogStickX -= 100;
//                if (JOY_HELD(DPAD_UP))
//                    inputToSend.analogStickY += 100;
//                else if (JOY_HELD(DPAD_DOWN))
//                    inputToSend.analogStickY -= 100;
//                #endif
//
//                inputToSend.mode.mLong.cStickX    = inputBuffer.mode.mLong.cStickX;
//                inputToSend.mode.mLong.cStickY    = inputBuffer.mode.mLong.cStickY;
//                inputToSend.mode.mLong.lAnalog    = (JOY_HELD(L_BUTTON) ? 200 : 0);
//                inputToSend.mode.mLong.rAnalog    = (JOY_HELD(R_BUTTON) ? 200 : 0);
//                inputToSend.mode.mLong.a          = (JOY_HELD(A_BUTTON) ? 200 : 0);
//                inputToSend.mode.mLong.b          = (JOY_HELD(B_BUTTON) ? 200 : 0);
//
//                GCNSendComm(&status, 80);
//            }
//            break;
//    }
//
//    REG_IF = INTR_FLAG_SERIAL;
//
//}

void GCNControllerFrameUpdate(void)
{
    u32 length;
    length = gGCNCommunication.amountOfBits;

    DebugPrintf("here", NULL);
    if (length < sizeof(gGCNCommunication.buffer) * 8 + 1)
        return;

    gGCNCommunication.currentByte = 0;
    gGCNCommunication.amountOfBits = 0;

    if (JOY_HELD(L_BUTTON | A_BUTTON))
    {
        GCNControllerDisable();
        return;
    }

    inputBuffer.errStat     = 0;
    inputBuffer.errLatch    = 0;
    inputBuffer.start       = !!(JOY_HELD(START_BUTTON));
    inputBuffer.y           = 0;
    inputBuffer.x           = 0;
    inputBuffer.b           = !!(JOY_HELD(B_BUTTON));
    inputBuffer.a           = !!(JOY_HELD(A_BUTTON));
    inputBuffer.r           = !!(JOY_HELD(L_BUTTON));
    inputBuffer.l           = !!(JOY_HELD(R_BUTTON));
    inputBuffer.z           = !!(JOY_HELD(SELECT_BUTTON));

    #ifndef EMU_ANALOG
    inputBuffer.up          = !!(JOY_HELD(DPAD_UP));
    inputBuffer.down        = !!(JOY_HELD(DPAD_DOWN));
    inputBuffer.right       = !!(JOY_HELD(DPAD_RIGHT));
    inputBuffer.left        = !!(JOY_HELD(DPAD_LEFT));
    #endif

    status.getOrigin  = inputBuffer.getOrigin;
    status.errLatch   = inputBuffer.errLatch;

    switch (gGCNCommunication.buffer[0]) {
        case CMD_RESET:
            status.rumbleState = GCN_RUMBLE_OFF;
        case CMD_ID:
            if (length == 8 + 1) {
                    status.deviceId = 0x2900; // Standard GCN controller, but missing rumble
    
                GCNSendComm(&status, 24);
            }
            break;
        case CMD_STATUS:
            if (length == 24 + 1) {
                u32 mode  = gGCNCommunication.buffer[1] & 7;
                u32 rumbleState = gGCNCommunication.buffer[2] & 3;
    
                status.mode = mode;
                if (rumbleState <= GCN_RUMBLE_HARD_STOP)
                    status.rumbleState = rumbleState;

                inputToSend.errStat         = inputBuffer.errStat;
                inputToSend.errLatch        = inputBuffer.errLatch;
                inputToSend.getOrigin       = inputBuffer.getOrigin;
                inputToSend.start           = inputBuffer.start;
                inputToSend.y               = inputBuffer.y;
                inputToSend.x               = inputBuffer.x;
                inputToSend.b               = inputBuffer.b;
                inputToSend.a               = inputBuffer.a;
                inputToSend.useOrigin       = inputBuffer.useOrigin;
                inputToSend.l               = inputBuffer.l;
                inputToSend.r               = inputBuffer.r;
                inputToSend.z               = inputBuffer.z;
                inputToSend.up              = inputBuffer.up;
                inputToSend.down            = inputBuffer.down;
                inputToSend.right           = inputBuffer.right;
                inputToSend.left            = inputBuffer.left;
                inputToSend.analogStickX    = inputBuffer.analogStickX;
                inputToSend.analogStickY    = inputBuffer.analogStickY;

                #ifdef EMU_ANALOG
                if (JOY_HELD(DPAD_RIGHT))
                    inputToSend.analogStickX += 100;
                else if (JOY_HELD(DPAD_LEFT))
                    inputToSend.analogStickX -= 100;
                if (JOY_HELD(DPAD_UP))
                    inputToSend.analogStickY += 100;
                else if (JOY_HELD(DPAD_DOWN))
                    inputToSend.analogStickY -= 100;
                #endif

                switch (status.mode) {
                    default:
                        inputToSend.mode.m0.cStickX   = inputBuffer.mode.mLong.cStickX;
                        inputToSend.mode.m0.cStickY   = inputBuffer.mode.mLong.cStickY;
                        inputToSend.mode.m0.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0) >> 4;
                        inputToSend.mode.m0.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0) >> 4;
                        inputToSend.mode.m0.a         = (JOY_HELD(A_BUTTON) ? 200 : 0) >> 4;
                        inputToSend.mode.m0.b         = (JOY_HELD(B_BUTTON) ? 200 : 0) >> 4;
                        break;
                    case 1:
                        inputToSend.mode.m1.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
                        inputToSend.mode.m1.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
                        inputToSend.mode.m1.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0);
                        inputToSend.mode.m1.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0);
                        inputToSend.mode.m1.a         = (JOY_HELD(A_BUTTON) ? 200 : 0)  >> 4;
                        inputToSend.mode.m1.b         = (JOY_HELD(B_BUTTON) ? 200 : 0)  >> 4;
                        break;
                    case 2:
                        inputToSend.mode.m2.cStickX   = inputBuffer.mode.mLong.cStickX >> 4;
                        inputToSend.mode.m2.cStickY   = inputBuffer.mode.mLong.cStickY >> 4;
                        inputToSend.mode.m2.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0) >> 4;
                        inputToSend.mode.m2.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0) >> 4;
                        inputToSend.mode.m2.a         = (JOY_HELD(A_BUTTON) ? 200 : 0);
                        inputToSend.mode.m2.b         = (JOY_HELD(B_BUTTON) ? 200 : 0);
                        break;
                    case 3:
                        inputToSend.mode.m3.cStickX   = inputBuffer.mode.mLong.cStickX;
                        inputToSend.mode.m3.cStickY   = inputBuffer.mode.mLong.cStickY;
                        inputToSend.mode.m3.lAnalog   = (JOY_HELD(L_BUTTON) ? 200 : 0);
                        inputToSend.mode.m3.rAnalog   = (JOY_HELD(R_BUTTON) ? 200 : 0);
                        break;
                    case 4:
                        inputToSend.mode.m4.cStickX   = inputBuffer.mode.mLong.cStickX;
                        inputToSend.mode.m4.cStickY   = inputBuffer.mode.mLong.cStickY;
                        inputToSend.mode.m4.a         = (JOY_HELD(A_BUTTON) ? 200 : 0);
                        inputToSend.mode.m4.b         = (JOY_HELD(B_BUTTON) ? 200 : 0);
                        break;
                }

                GCNSendComm(&inputToSend, 64);
            }
            break;
        case CMD_ORIGIN:
            if (length == 8 + 1) {
                inputBuffer.getOrigin = FALSE;
                GCNSendComm(&inputBuffer, 80);
            }
            break;
        case CMD_RECALIBRATE:
            if (length == 24 + 1) {
                inputBuffer.getOrigin = FALSE;
                GCNSendComm(&inputBuffer, 80);
            }
            break;
        case CMD_STATUS_LONG:
            if (length == 24 + 1) {
                u32 rumbleState = gGCNCommunication.buffer[2] & 3;

                if (rumbleState <= GCN_RUMBLE_HARD_STOP)
                    status.rumbleState = rumbleState;

                inputToSend.errStat         = inputBuffer.errStat;
                inputToSend.errLatch        = inputBuffer.errLatch;
                inputToSend.getOrigin       = inputBuffer.getOrigin;
                inputToSend.start           = inputBuffer.start;
                inputToSend.y               = inputBuffer.y;
                inputToSend.x               = inputBuffer.x;
                inputToSend.b               = inputBuffer.b;
                inputToSend.a               = inputBuffer.a;
                inputToSend.useOrigin       = inputBuffer.useOrigin;
                inputToSend.l               = inputBuffer.l;
                inputToSend.r               = inputBuffer.r;
                inputToSend.z               = inputBuffer.z;
                inputToSend.up              = inputBuffer.up;
                inputToSend.down            = inputBuffer.down;
                inputToSend.right           = inputBuffer.right;
                inputToSend.left            = inputBuffer.left;
                inputToSend.analogStickX    = inputBuffer.analogStickX;
                inputToSend.analogStickY    = inputBuffer.analogStickY;

                #ifdef EMU_ANALOG
                if (JOY_HELD(DPAD_RIGHT))
                    inputToSend.analogStickX += 100;
                else if (JOY_HELD(DPAD_LEFT))
                    inputToSend.analogStickX -= 100;
                if (JOY_HELD(DPAD_UP))
                    inputToSend.analogStickY += 100;
                else if (JOY_HELD(DPAD_DOWN))
                    inputToSend.analogStickY -= 100;
                #endif

                inputToSend.mode.mLong.cStickX    = inputBuffer.mode.mLong.cStickX;
                inputToSend.mode.mLong.cStickY    = inputBuffer.mode.mLong.cStickY;
                inputToSend.mode.mLong.lAnalog    = (JOY_HELD(L_BUTTON) ? 200 : 0);
                inputToSend.mode.mLong.rAnalog    = (JOY_HELD(R_BUTTON) ? 200 : 0);
                inputToSend.mode.mLong.a          = (JOY_HELD(A_BUTTON) ? 200 : 0);
                inputToSend.mode.mLong.b          = (JOY_HELD(B_BUTTON) ? 200 : 0);

                GCNSendComm(&status, 80);
            }
            break;
    }
}

bool8 GCNControllerEnable(void)
{
    if (gGameBoyPlayerDetected && gSaveBlock2Ptr->optionsRumble)
        return FALSE;

    SetSerialCallback(GCNSerialInterrupt);
    SetTimer1Callback(GCNTimerInterrrupt);

    REG_IE |= INTR_FLAG_SERIAL | INTR_FLAG_TIMER1/* | INTR_FLAG_TIMER2*/;
    //REG_IF = REG_IF;
    REG_RCNT = R_GPIO | GPIO_IRQ | GPIO_SO_IO | GPIO_SO;
	REG_TM1CNT_L = gSaveBlock1Ptr->siWindowTest;
	REG_TM1CNT_H = TIMER_ENABLE;

    inputBuffer.mode.mLong.cStickX = 128;
    inputBuffer.mode.mLong.cStickY = 128;

    gGCNCommunication.controllerEnabled = TRUE;
    return FALSE;
}

void GCNControllerDisable(void)
{
    REG_IE &= ~(INTR_FLAG_TIMER1);
    REG_TM1CNT_L = 0;
    REG_TM1CNT_H = 0;

    SetSerialCallback(SerialCB);
    SetTimer1Callback(NULL);

    gGCNCommunication.controllerEnabled = FALSE;
}
