#include "kbd.hpp"
#include "memory.hpp"
#include "print.hpp"
#include "shell.hpp"
#include "messages.hpp"

t_uch kbdCursorX = 0;
t_uch kbdCursorY = 0;

t_uch kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', 8,	/* Backspace */
  9,			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', 13,	/* Enter key */
    29,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   14,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   15,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    30,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    17,	/* Left Arrow */
    0,
    16,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    31,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};	

extern "C" t_uch getKeycode(){
  asm(
    "mov $589828, %ebx;"
    "in $96, %eax;"
    "mov %eax, (%ebx);"
  );
  t_uch kbdCodeEpic = KBD_OUTPUT[0];
  if (kbdCodeEpic > 128){
    return 0;
  }
  if (kbdus[kbdCodeEpic] >= 'a' && kbdus[kbdCodeEpic] <= 'z'){
    return kbdus[kbdCodeEpic] - 32;
  }
  return kbdus[kbdCodeEpic];
}

t_uch keyPrevious = getKeycode();

extern "C" void clearCursor(){
    setAttrColor(DEFAULT_COLORS);
    placeScreenByte(kbdCursorX, kbdCursorY,' ');
}

extern "C" void resetCursor(){
  clearCursor();
  kbdCursorX = 0;
  kbdCursorY = -1;
}

extern "C" void takeKeypress(t_uch code){
  if (keyPrevious != code){
  switch (code){
    case 30:
      if (kbdCursorY != 0){
        clearCursor();
        kbdCursorY--;
      }
      break;
    case 31:
      if (kbdCursorY != SCREEN_HEIGHT-2){
        clearCursor();
        kbdCursorY++;
      }
      break;
    case 17:
      if (kbdCursorX != 0){
        clearCursor();
        kbdCursorX--;
      }
      break;
    case 16:
      if (kbdCursorX != SCREEN_WIDTH-1){
        clearCursor();
        kbdCursorX++;
      }
      break;
  }
  if (((code >= 65 && code <= 90) || code == ' ') && kbdCursorX < SCREEN_WIDTH-1){
    setAttrColor(DEFAULT_COLORS);
    placeScreenByte(kbdCursorX,kbdCursorY,code);
    kbdCursorX++;
  } else if (code == 8 && kbdCursorX > 0){
    clearCursor();
    kbdCursorX--;

  //enter key
  } else if (code == 13 && kbdCursorY < SCREEN_HEIGHT-2){
    clearCursor();
    executeCommand(readCommand(kbdCursorY));
    kbdCursorY++;
    if (stringsEqual((t_ch*)readCommand(kbdCursorY), CLEAR_SCREEN)){
      kbdCursorY--;
    }
    kbdCursorX = 0;
  }
  keyPrevious = code;
  placeCursor(kbdCursorX, kbdCursorY);
  }
}
