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
* @file writepat.h
* @brief An abstraction for the writepat function
*
* This header file provides an abstraction of the function to
* write a pseudo random pattern to an area within an allocated
* block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __WRITEPAT_H__
#define __WRITEPAT_H__

#include <stdio.h>
#include "types.h"

//define the help string
#define HELP_WPAT ("Write a pseudo random pattern to a block of memory")

/**
* @brief Write a pseudo random patterm to an area within an allocated block of memory
*
* Given a pointer to a char command buffer, this will write
* a pseudo random pattern to an area within a block of
* previously allocated memory.
*
* @param cmd Pointer to a command buffer
*
* @return void.
*/
void writepat(char *cmd, struct blockStruct *b);
#endif /* __WRITEPAT_H__ */

