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
* @file exit.c
* @brief exit function for the memory test project.  
*
* This source file provides support for exiting the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0
*
*/

#include "exit.h"

void exitapp(char *cmd, struct blockStruct *b)
{
    if(cmd == 0)
    {
        printf("Missing buffer data\n");
        return;
    }
    
    if(b->ptr)
    {
        printf("Freeing %d words of leftover allocated memory!\n",b->size);
        free(b->ptr);
    }
    printf("Bye bye!\n");

    return;
}

