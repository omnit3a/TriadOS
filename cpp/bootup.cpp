#include "messages.hpp"
#include "message_bar.hpp"
#include "memory.hpp"
#include "print.hpp"
#include "bootup.hpp"

extern "C" void hang(){
  while(TRUE){
  }
}

extern "C" t_valid verifyLoad(){
  #ifdef MEMORY_H_
    setAttrColor(SUCCESS_COLORS);
    placeString(0,0,MEMORY_MANAGER_REACHED);
  #else 
    setAttrColor(FAILURE_COLORS);
    placeString(0,0,UNLOADED_UNIT_FAULT);
    return FALSE;
  #endif

  #ifdef PRINT_H_
    setAttrColor(SUCCESS_COLORS);
    placeString(0,1,PRINT_REACHED);
  #else 
    setAttrColor(FAILURE_COLORS);
    placeString(0,1,UNLOADED_UNIT_FAULT);
    return FALSE;
  #endif
  
  #ifdef MESSAGE_BAR_H_
    setAttrColor(SUCCESS_COLORS);
    placeString(0,2,MESSAGE_BAR_REACHED);
  #else
    setAttrColor(FAILURE_COLORS);
    placeString(0,2,UNLOADED_UNIT_FAULT);
    return FALSE;
  #endif

  placeString(0,4,KERNEL_REACHED);
  return TRUE;
}
