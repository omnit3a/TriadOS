#ifndef KBD_H_
#define KBD_H_

#include "memory.hpp"

extern t_uch kbdCursorX;
extern t_uch kbdCursorY;

extern t_uch kbdus[128];

extern "C" t_uch getKeycode();

extern "C" void takeKeypress(t_uch code);

#endif
