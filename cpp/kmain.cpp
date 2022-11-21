#include "memory.hpp"
#include "print.hpp"
#include "messages.hpp"
#include "bootup.hpp"
#include "message_bar.hpp"
#include "kbd.hpp"

extern "C" void kmain(){
  //verify that all files have been compiled correctly
  if (verifyLoad()){
    verifyLoad();
    setAttrColor(DEFAULT_COLORS);
    clearScreen();
  } else {
    hang();
  }

  //initialize heap
  inith();

  t_uch xTempCursor = kbdCursorX;
  t_uch yTempCursor = kbdCursorY;
  //main loop
  while(TRUE){
    takeKeypress(getKeycode());
    displayMessageBar();
  }
}
