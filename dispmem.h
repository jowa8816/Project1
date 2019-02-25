/*****************************************************************************
* Copyright (C) 2019 by Jon Warriner
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Jon Warrinerk and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file dispmem.h
* @brief An abstraction for the dispmem function
*
* This header file provides an abstraction of the function to
* display the contents of a block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __DISPMEM_H__
#define __DISPMEM_H__

#include "types.h"
#include <ctype.h>
#include <stdio.h>

//define the help string
#define HELP_DISP ("dispmem [-o] <address> [<words>] - Display memory from <address> for one or [<words>] 4-byte words in hexadecimal format.  Optional '-o' argument treats <address> as an offset into the allocated block of memory.\n")

/**
* @brief Display the contents of a block of memory
*
* Given a pointer to a char command buffer, this will display
* the contents of a block of previously allocated memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void dispmem(char *cmd, struct blockStruct *b);
#endif /* __DISPMEM_H__ */

