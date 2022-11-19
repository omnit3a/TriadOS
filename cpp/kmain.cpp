#include "memory.hpp"
#include "print.hpp"
#include "messages.hpp"
#include "bootup.hpp"

extern "C" void kmain(){
  inith();
  clearScreen();

  //verify that all files have been compiled correctly
  verifyLoad();
}
