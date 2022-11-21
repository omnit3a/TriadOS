#include "message_bar.hpp"
#include "memory.hpp"
#include "print.hpp"
#include "kbd.hpp"

t_ush heapTest = 0;
t_uch kbdCode = 0;

//the message bar is always visible
//it displays the current heap space in t_uin
//plans for more statuses are underway
extern "C" void displayMessageBar(){
  setAttrColor(0xb100);
  for (t_uch i = 9 ; i < SCREEN_WIDTH ; i++){
    placeScreenByte(i,SCREEN_HEIGHT-1,' ');
  }
  if (heapTest != freehSpace()){
    heapTest = freehSpace();
    placeDecimal(5,SCREEN_HEIGHT-1,heapTest);
    placeString(0,SCREEN_HEIGHT-1,"HEAP:");
  }
}

extern "C" void forceDisplayHeap(){
  setAttrColor(0xb100);
  placeDecimal(5,SCREEN_HEIGHT-1,heapTest);
  placeString(0,SCREEN_HEIGHT-1,"HEAP:");
  setAttrColor(DEFAULT_COLORS);
}
