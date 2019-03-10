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
* @file invertmem.h
* @brief An abstraction for the invertmem function
*
* This header file provides an abstraction of the function to
* invert the contents of a block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __INVERTMEM_H__
#define __INVERTMEM_H__

#include "types.h"
#include <stdio.h>
#include <ctype.h>

//define the help string
#define HELP_INV ("invertmem [-o] <address> [<words>] -Invert the contents of memory starting at <address> for one or [<words>] 4-byte words.  Optional '-o' argument treats <address> as an offset into the allocated block of memory.\r\n")

/**
* @brief Invert the contents of a block of memory
*
* Given a pointer to a char command buffer, this will invert
* the contents of a block of previously allocated memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void invertmem(char *cmd, struct blockStruct *b);
#endif /* __INVERTMEM_H__ */

