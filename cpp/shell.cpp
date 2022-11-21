#include "memory.hpp"
#include "print.hpp"
#include "messages.hpp"
#include "message_bar.hpp"
#include "kbd.hpp"

extern "C" t_uch * readCommand(t_uch lineNumber){
  t_uch * command;
  for (t_uin i = 0 ; i < 4 ; i++){
    command[i] = SCREEN_SPACE[i+(lineNumber*80)];
  }
  return command;
}

extern "C" t_valid stringsEqual(t_ch * a, t_ch * b){
  for (t_uch i = 0 ; i < 80 ; i++){
    if (a[i] != b[i]){
      return FALSE;
    }
    if (a[i] == b[i] && a[i] == 0x00){
      return TRUE;
    }
  }
  return TRUE;
}

extern "C" void executeCommand(t_uch * command){
  t_ch * tempCommand = (t_ch*)command;
  tempCommand[4] = 0x00;
  if (stringsEqual(tempCommand, CLEAR_SCREEN)){
    clearScreen();
    resetCursor();
    forceDisplayHeap();
  } else if (stringsEqual(tempCommand, HELP_COMMAND)){
    placeString(0,kbdCursorY,HELP_TEXT);
    placeCursor(20,kbdCursorY);
    clearCursor();
  } else {
    setAttrColor(WARNING_COLORS);
    placeString(0,kbdCursorY,UNKNOWN_COMMAND_FAULT);
    placeCursor(18,kbdCursorY);
    clearCursor();
  }
}
