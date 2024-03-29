#ifndef PRINT_H_
#define PRINT_H_

#include "memory.hpp"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_SIZE (SCREEN_WIDTH*SCREEN_HEIGHT)*2

#define DEFAULT_COLORS 0x1b00
#define SUCCESS_COLORS 0x1a00
#define WARNING_COLORS 0x1e00
#define FAILURE_COLORS 0x1c00

typedef t_ch * String;

extern t_ush SCREEN_COLORS;

extern "C" void setAttrColor(t_ush color);

extern "C" void clearScreen();

extern "C" void clearScreenNoBar();

extern "C" void placeScreenByte(t_uch x, t_uch y, t_uch byte);

extern "C" void placeString(t_uch x, t_uch y, String string);

extern "C" void placeDecimal(t_uch x, t_uch y, t_uin value);

extern "C" void placeCursor(t_uch x, t_uch y);

extern "C" t_uch getScreenByteAt(t_uch x, t_uch y);

#endif
