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
* @file freemem.c
* @brief freemem function for the memory test project.  
*
* This source file provides support for freeing a block of
* memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "freemem.h"

void freemem(char *cmd, struct blockStruct *b)
{
    if((cmd == 0) || (b == 0))
    {
        printf("Internal Error: Missing buffer data or block pointer!\n");
        return;
    }

    //If we have an allocated block of memory, free it
    //make sure to wipe out the structure that keeps track
    //of the block info
    if((b->ptr != 0) && (b->size != 0))
    {
        printf("Freeing %d words of allocated memory!\n",b->size);
        free(b->ptr);
        b->size = 0;
        b->ptr = 0;
    }
    else
    {
        printf("No allocated blocks of memory to free!\n");
    }

    return;
}

