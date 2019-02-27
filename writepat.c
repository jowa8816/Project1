/*****************************************************************************
* Copyright (C) 2019 by Jon Warriner
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Jon Warriner and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file writepat.c
* @brief writepat function for the memory test project.  
*
* This source file provides support for writing a pseudo random pattern
* to an area within of a block of memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "writepat.h"

void writepat(char *cmd, struct blockStruct *b)
{
struct randStruct rnd;
uint32_t i = 0;
uint32_t seed = 0;

    if((cmd == 0) || (b == 0))
    {
        printf("Internal Error: Missing buffer data or block pointer!\n");
        return;
    }

    //Extract the seed from the command buffer
    //command name is 8 chars long so we should start after that
    seed = strtol(&cmd[8], 0, 10);
#ifdef DEBUG
    printf("seed is: %d\n", seed);
#endif

    rnd.m = 8;
    rnd.c = 3;
    rnd.a = 5;
    rnd.X = seed;
    for(i = 0; i < 20; i++)
    {
        ps_rand(&rnd);
        printf("%d\n", rnd.X);
    }

    return;
}

