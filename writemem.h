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
* @file writemem.h
* @brief An abstraction for the writemem function
*
* This header file provides an abstraction of the function to
* write to a location within and allocated block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __WRITEMEM_H__
#define __WRITEMEM_H__

#include <stdio.h>
#include <ctype.h>
#include "types.h"

//define the help string
#define HELP_WRITE ("writemem [-o] <address> <data> - Write one 4-byte word <data> to <address>.  Both parameters are in hexadecimal format.  Optional '-o' argument treats <address> as an offset into the allocated block of memory.\n")

/**
* @brief Write to a location within an allocated block of memory
*
* Given a pointer to a char command buffer, this will write
* to a location within a block of previously allocated memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void writemem(char *cmd, struct blockStruct *b);
#endif /* __WRITEMEM_H__ */

