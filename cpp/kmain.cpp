#include "memory.h"
#include "print.h"
#include "messages.h"
#include "bootup.h"
#include "kbd.h"

extern "C" void kmain(){
  inith();
  clearScreen();

  //verify that all files have been compiled correctly
  verifyLoad();
}
