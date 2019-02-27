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
* @file ps_rand.h
* @brief An abstraction for the ps_rand function
*
* This header file provides an abstraction of the function to
* generate a pseudo random number sequence.
*
* @author Jon Warriner
* @date February 26 2019
* @version 1.0
*
*/
#ifndef __PS_RAND_H__
#define __PS_RAND_H__

#include "types.h"
#include <stdio.h>

//define a structure for a block of allocated memory
struct randStruct
{
    uint32_t a;
    uint32_t c;
    uint32_t m;
    uint32_t X;
};


/**
* @brief Generate a sequence of pseudo random numbers
*
* Given a pointer to a char command buffer, this will display
* the contents of a block of previously allocated memory.
*
* @param cmd Pointer to a command buffer
* @param b   Pointer to a memory block structure
*
* @return void.
*/
void ps_rand(struct randStruct *r);
#endif /* __PS_RAND_H__ */

