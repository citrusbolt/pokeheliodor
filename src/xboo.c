#include "global.h"
#include "main.h"
#include "xboo.h"
#include "gpu_regs.h"

void XbooInit(void)
{
    DisableInterrupts(INTR_FLAG_SERIAL);

    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD;
}

void XbooSend(u32 data)
{
    REG_SIODATA32 = data;
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD | SIO_START;
    while (REG_SIOCNT & SIO_START);
}

void XbooSendBlock(const void *block, u32 length)
{
    u32 data, i;
    u8 *ptr = (u8 *)block;
    
    for (i = 0; i < length; i++)
    {
        ((u8 *)(&data))[i & 3] = *(ptr++);
    
        if ((i & 3) == 3)
            XbooSend(data);
    }
    if (length & 3)
        XbooSend(data);
}

u32 XbooReceive(void)
{
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD | SIO_START;

    while (REG_SIOCNT & SIO_START);

    return REG_SIODATA32;
}

void XbooReceiveBlock(const void *block, u32 length)
{
    u32 data, i;
    u8 *ptr = (u8 *)block;
    
    for (i = 0; i < length; i++)
    {
        if ((i & 3) == 0)
            data = XbooReceive();

        *(ptr++) = ((u8 *)(&data))[i & 3];
    }
}

u32 XbooExchange(u32 data)
{
    REG_SIODATA32 = data;
    REG_SIOCNT = SIO_32BIT_MODE;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_MULTI_SD | SIO_START;
    while (REG_SIOCNT & SIO_START);

    return REG_SIODATA32;
}

void XbooFileClose(u32 handle)
{
    XbooSend(FCLOSE_CMD | (handle & 0x0FF));
}

u32 XbooFileOpen(const u8 *filename, const u8 *mode)
{
    u32 length = strlen(filename);

    XbooSend(FOPEN_CMD | (length & 0x0FF));
    XbooSendBlock(filename, length);
    XbooSendBlock(mode, 2);

    return XbooReceive();
}

void XbooFileRead(u32 handle, u32 size, u32 count, void *buffer)
{
    XbooSend(FREAD_CMD | (handle & 0x0FF));
    XbooSend(size);
    XbooSend(count);

    XbooReceiveBlock(buffer, size * count);
}

void XbooFileSeek(u32 handle, u32 offset, u32 origin)
{
    XbooSend(FSEEK_CMD | (handle & 0x0FF));
    XbooSend(offset);
    XbooSend(origin);
}

u32 XbooFileTell(u32 handle)
{
	XbooSend(FTELL_CMD | (handle & 0x0FF));

	return XbooReceive();
}

void XbooFileWrite(u32 handle, u32 size, u32 count, void *buffer)
{
    XbooSend(FWRITE_CMD | (handle & 0x0FF));
    XbooSend(size);
    XbooSend(count);

    XbooSendBlock(buffer, size * count);
}

u8 XbooFileReadByte(u32 handle)
{
    XbooSend(FGETC_CMD | (handle & 0x0FF));

    return XbooReceive();
}

void XbooFileWriteByte(u8 byte, u32 handle)
{
    XbooSend(FPUTC_CMD | (handle & 0x0FF));
    XbooSend(byte);
}

u32 XbooReadKey(void)
{
    XbooSend(GETCH_CMD);

    return XbooReceive();
}

bool32 XbooIsKeyPressed(void)
{
    XbooSend(KBHIT_CMD);

    return XbooReceive();
}
