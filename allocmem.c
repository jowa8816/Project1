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
* @file allocmem.c
* @brief allocate function for the memory test project.  
*
* This source file provides support for allocating a block of
* memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "allocmem.h"

void allocmem(char *cmd, struct blockStruct *b)
{
int32_t size;

    if((cmd == 0) || (b == 0))
    {
        MYPRINTF("Internal Error: Missing buffer data or block pointer!\r\n");
        return;
    }

    //Extract the size from the command buffer
    //command name is 9 chars long so we should start after that
    size = strtol(&cmd[9], 0, 10);
#ifdef MY_DEBUG
    MYPRINTF("size is: %d\r\n", size);
#endif

    //size needs to be positive
    if(size > 0)
    {
        //Do we already have a block allocated?
        //If not, allocate a new block of the specified size.
        //If so, reallocate the existing block with the new size.  
        if(b->size == 0)
        {
            b->ptr = malloc(size*sizeof(int32_t));
            if(b->ptr)
            {
                b->size = size;
                MYPRINTF("Allocated %d 4-byte words starting at address %p\r\n", size, b->ptr);
            }
            else
            {
            	b->size = 0;
            	MYPRINTF(" Failed to allocate %d 4-byte words.  Try again!\r\n", size);
            }
        }
        else
        {
            b->ptr = realloc(b->ptr,size*sizeof(int32_t));
            if(b->ptr)
            {
                b->size = size;
                MYPRINTF("Reallocated block at address %p with %d 4-byte words\r\n", b->ptr, size);
            }
            else
            {
            	b->size = 0;
            	MYPRINTF(" Failed to allocate %d 4-byte words.  Try again!\r\n", size);
            }
        }
    }
    else
    {
          MYPRINTF("Error: Failed to specify size or specified size is less than or equal to 0!\r\n");
    }

    return;
}

