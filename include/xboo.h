#ifndef GUARD_XBOO_H
#define GUARD_XBOO_H

#define FCLOSE_CMD	('C' << 24 | 'L' << 16 | 'S' << 8)
#define FOPEN_CMD	('O' << 24 | 'P' << 16 | 'N' << 8)
#define FREAD_CMD	('F' << 24 | 'R' << 16 | 'D' << 8)
#define FSEEK_CMD	('F' << 24 | 'S' << 16 | 'K' << 8)
#define FTELL_CMD	('F' << 24 | 'T' << 16 | 'L' << 8)
#define FWRITE_CMD	('F' << 24 | 'W' << 16 | 'R' << 8)
#define REWIND_CMD	('R' << 24 | 'W' << 16 | 'D' << 8)
#define PRINT_CMD	('P' << 24 | 'R' << 16 | 'T' << 8)
#define FGETC_CMD	('F' << 24 | 'G' << 16 | 'T' << 8)
#define FPUTC_CMD	('F' << 24 | 'P' << 16 | 'T' << 8)
#define GETCH_CMD	('G' << 24 | 'T' << 16 | 'C' << 8)
#define DPUTC_CMD	('D' << 24 | 'P' << 16 | 'T' << 8)
#define KBHIT_CMD	('K' << 24 | 'B' << 16 | 'H' << 8)

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

void XbooInit(void);
void XbooSend(u32 data);
void XbooSendBlock(const void *block, u32 length);
u32 XbooReceive(void);
void XbooReceiveBlock(const void *block, u32 length);
u32 XbooExchange(u32 data);
void XbooFileClose(u32 handle);
u32 XbooFileOpen(const u8 *filename, const u8 *mode);
void XbooFileRead(u32 handle, u32 size, u32 count, void *buffer);
void XbooFileSeek(u32 handle, u32 offset, u32 origin);
u32 XbooFileTell(u32 handle);
void XbooFileWrite(u32 handle, u32 size, u32 count, void *buffer);
//void XbooRewind(u32 handle);
//void XbooPrint(u8 *string);
u8 XbooFileReadByte(u32 handle);
void XbooFileWriteByte(u8 byte, u32 handle);
u32 XbooReadKey(void);
bool32 XbooIsKeyPressed(void);

#endif // GUARD_XBOO_H
