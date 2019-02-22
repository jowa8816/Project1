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
* @file dispmem.c
* @brief dispmem function for the memory test project.  
*
* This source file provides support for displaying the contents
* of a block of memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "dispmem.h"

void dispmem(char *cmd, struct blockStruct *b)
{
int32_t size;
int32_t i = 0;
int32_t *address;
char *endptr = 0;

    if((cmd == 0) || (b == 0))
    {
        printf("Internal Error: Missing buffer data or block pointer!\n");
        return;
    }

    //First, we need to make sure we have an allocated block of memory 
    //to display from
    if((b->ptr != 0) && (b->size != 0))
    {
        //Extract the address and size from the command buffer
        //command name is 7 chars long so we should start after that
        address = (int32_t *)strtoll(&cmd[7], &endptr, 16);
        size = strtol(endptr, 0, 10);
#ifdef DEBUG
        printf("address is: %p\n", address);
        printf("size is: %d\n", size);
#endif
        //make sure the memory we want to dispaly is within the 
        //bounds of our allocated block
        if((size >= 0) && (address >= (int32_t *)b->ptr) && ((address + size) <= ((int32_t *)b->ptr + (int32_t)b->size)))
        {
            printf("   Address           Data\n");
            printf("--------------    ----------\n");
            do
            {
                printf("%p    0x%08X\n", address, *address);
                address++;
                i++;
            }while(i < size);
        }
        else
        {
            printf("Error: All or part of the requested memory area is outside of the allocated block!\n");
        }
    }
    else
    {
        printf("Error: No allocated blocks of memory to display!\n");
    }

    return;
}

