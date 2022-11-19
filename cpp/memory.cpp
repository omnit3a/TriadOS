#include "memory.hpp"

t_ush * SCREEN_SPACE = (t_ush *)SCREEN_RAM;

t_valid HEAP_FREE[HEAP_SIZE];
t_uin * HEAP_SPACE = (t_uin *)HEAP_RAM;

extern "C" void inith(){
  for (t_ush i = 0 ; i < HEAP_SIZE ; i++){
    HEAP_FREE[i] = TRUE;
    HEAP_SPACE[i] = 0x00;
  }
}

extern "C" void * alloch(){
  for (t_uin i = 0 ; i < HEAP_SIZE ; i++){
    if (HEAP_FREE[i] == TRUE){
      HEAP_FREE[i] = FALSE;
      return (void *)((i*4)+HEAP_RAM);
    }
  }
  return (void *)FALSE;
}

extern "C" void freeh(void * block){
  t_uin * ptr = (t_uin *)block;
  t_in testPtr = ((t_uin)ptr/4);
  HEAP_FREE[testPtr] = TRUE;
}
