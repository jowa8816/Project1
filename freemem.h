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
* @file freemem.h
* @brief An abstraction for the freemem function
*
* This header file provides an abstraction of the function to
* free a block of memory.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __FREEMEM_H__
#define __FREEMEM_H__
#include <stdio.h>

/**
* @brief Free a block of memory
*
* Given a pointer to a char command buffer, this will free
* a block of previously allocated memory.
*
* @param cmd Pointer to a command buffer
*
* @return void.
*/
void freemem(char *cmd);
#endif /* __FREEMEM_H__ */
