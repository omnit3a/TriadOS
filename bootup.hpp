#ifndef BOOTUP_H_
#define BOOTUP_H_

#include "memory.hpp"

extern "C" void hang();

extern "C" t_valid verifyLoad();

#endif
