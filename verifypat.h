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

#include <stdio.h>
#include "types.h"

//define the help string
#define HELP_VPAT ("Verify a pseudo random pattern within a block of memory")

/**
* @brief Verify a pseudo random patterm within an allocated block of memory
*
* Given a pointer to a char command buffer, this will verify
* a pseudo random pattern previously written to an area within
* a block of allocated memory.
*
* @param cmd Pointer to a command buffer
*
* @return void.
*/
void verifypat(char *cmd);
#endif /* __VERIFYPAT_H__ */
