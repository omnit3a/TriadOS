#ifndef MEMORY_H_
#define MEMORY_H_

#define HEAP_RAM 0x80000
#define SCREEN_RAM 0xb8000
#define HEAP_SIZE 4096

typedef unsigned char t_uch;
typedef unsigned short t_ush;
typedef unsigned int t_uin;
typedef char t_ch;
typedef short t_sh;
typedef short t_in;

//boolean types
enum t_valid {
  TRUE = 1,
  FALSE = 0
};

//a block in the heap. 4096 available blocks on bootup
struct t_hblock {
  t_uin offset;
  t_valid free;
};

extern t_valid HEAP_FREE[HEAP_SIZE];
extern t_uin * HEAP_SPACE;

//vga screen memory
extern t_ush * SCREEN_SPACE;

//initialize the heap
extern "C" void inith();

//allocate a fixed, 4 byte space on the heap
extern "C" void * alloch();

//free a space on the heap
extern "C" void freeh(void * block);

#endif
