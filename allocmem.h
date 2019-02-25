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
* @file allocmem.h
* @brief An abstraction for the allocate function
*
* This header file provides an abstraction of the function to
* allocate a block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __ALLOCMEM_H__
#define __ALLOCMEM_H__

#include "types.h"
#include <stdio.h>

//define the help string
#define HELP_ALLOC ("allocmem <words> - Allocate a block of memory containing <words> 4-byte words.\n")

/**
* @brief Allocate a block of memory
*
* Given a pointer to a char command buffer, this will allocate
* a block of memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void allocmem(char *cmd, struct blockStruct *b);
#endif /* __ALLOCMEM_H__ */

