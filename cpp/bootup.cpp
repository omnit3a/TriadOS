#include "messages.hpp"
#include "print.hpp"
#include "bootup.hpp"

extern "C" void verifyLoad(){
  #ifdef MEMORY_H_
    setAttrColor(SUCCESS_COLORS);
    placeString(0,0,MEMORY_MANAGER_REACHED);
  #else 
    setAttrColor(FAILURE_COLORS);
    placeString(0,0,UNLOADED_UNIT_FAULT);
  #endif

  #ifdef PRINT_H_
    setAttrColor(SUCCESS_COLORS);
    placeString(0,1,PRINT_REACHED);
  #else 
    setAttrColor(FAILURE_COLORS);
    placeString(0,1,UNLOADED_UNIT_FAULT);
  #endif

  placeString(0,2,KERNEL_REACHED);
}
