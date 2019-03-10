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
* @file verifypat.h
* @brief An abstraction for the verifypat function
*
* This header file provides an abstraction of the function to
* verify a pseudo random pattern previously written to an area
* within an allocated block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __VERIFYPAT_H__
#define __VERIFYPAT_H__

#include "types.h"
#include <stdio.h>
#include <ctype.h>
#include "ps_rand.h"

//define the help string
#define HELP_VPAT ("verifypat [-o] <address> [<words>] [<seed>]- Verify a pseudo random pattern starting at <address> for one or [<words>] 4-byte words.  [<seed>] specifies the starting point for the random number generator.  Optional '-o' argument treats <address> as an offset into the allocated block of memory.\r\n")

/**
* @brief Verify a pseudo random patterm within an allocated block of memory
*
* Given a pointer to a char command buffer, this will verify
* a pseudo random pattern previously written to an area within
* a block of allocated memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void verifypat(char *cmd, struct blockStruct *b);
#endif /* __VERIFYPAT_H__ */

