#include "memory.hpp"
#include "print.hpp"
#include "messages.hpp"
#include "bootup.hpp"
#include "message_bar.hpp"
#include "kbd.hpp"
#include "shell.hpp"

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

  //main loop
  placeCursor(kbdCursorX,kbdCursorY);
  while(TRUE){
    takeKeypress(getKeycode());
    displayMessageBar();
  }
}
