#ifndef SHELL_H_
#define SHELL_H_

#include "memory.hpp"

extern "C" t_uch * readCommand(t_uch lineNumber);

extern "C" t_valid stringsEqual(t_ch * a, t_ch * b);

extern "C" void executeCommand(t_uch * command);

#endif
