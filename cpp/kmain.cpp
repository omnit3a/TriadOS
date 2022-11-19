#include "memory.hpp"
#include "print.hpp"
#include "messages.hpp"
#include "bootup.hpp"
#include "message_bar.hpp"

extern "C" void kmain(){
  inith();
  clearScreen();

  //verify that all files have been compiled correctly
  if (verifyLoad()){
    setAttrColor(DEFAULT_COLORS);
    clearScreen();
  } else {
    hang();
  }

  //main loop
  while(TRUE){
    displayMessageBar();
  }
}
