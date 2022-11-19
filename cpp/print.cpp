#include "print.h"
#include "memory.h"

t_ush SCREEN_COLORS = DEFAULT_COLORS;

extern "C" void setAttrColor(t_ush color){
  SCREEN_COLORS = color;
}

extern "C" void clearScreen(){
  for (t_uin i = 0 ; i < SCREEN_SIZE ; i++){
    SCREEN_SPACE[i] = SCREEN_COLORS | ' ';
  } 
}

extern "C" void placeScreenByte(t_uch x, t_uch y, t_uch byte){
  SCREEN_SPACE[x+(y*80)] = SCREEN_COLORS | byte;
}

extern "C" void placeString(t_uch x, t_uch y, String string){
  t_uch lengthOfString = 0;
  for (t_uch i = 0 ; i < 80 ; i++){
    if (string[i] == 0x00){
      lengthOfString = i;
      break;
    }
  }
  for (t_uch i = 0 ; i < lengthOfString ; i++){
    placeScreenByte(x+i, y, string[i]);

  }
}

//yes this literally a copy and paste from itoa()'s gcc implementation
extern "C" void placeHex(t_uch x, t_uch y, t_uin value) {
    int size = 0;
    int t = value;

    while(t / 10 != 0) {
        t = t/10;
        size++;
    }
    static char ret[64];
    size++;
    ret[size] = '\0';
    t = value;
    int i = size - 1;
    while(i >= 0) {
        ret[i] = (t % 10) + '0';
        t = t/10;
        i--;
    }

    placeString(x,y,ret);
}
