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
* @file invertmem.c
* @brief invertmem function for the memory test project.  
*
* This source file provides support for inverting the contents
* of a block of memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "invertmem.h"

void invertmem(char *cmd, struct blockStruct *b)
{
int32_t size;
int32_t i = 0;
int32_t *address;
char *endptr = 0;
clock_t start_t, end_t;
double elapsed_t;

    if((cmd == 0) || (b == 0))
    {
        printf("Internal Error: Missing buffer data or block pointer!\n");
        return;
    }

    //First, we need to make sure we have an allocated block of memory 
    //to invert
    if((b->ptr != 0) && (b->size != 0))
    {
        //Extract the address and size from the command buffer
        //command name is 9 chars long so we should start after that
        address = (int32_t *)strtoll(&cmd[9], &endptr, 16);
        size = strtol(endptr, 0, 10);
#ifdef DEBUG
        printf("address is: %p\n", address);
        printf("size is: %d\n", size);
#endif
        //make sure the memory we want to invert is within the 
        //bounds of our allocated block
        if((size >= 0) && (address >= (int32_t *)b->ptr) && ((address + size) <= ((int32_t *)b->ptr + (int32_t)b->size)))
        {
            start_t = clock();

            printf("Inverting %d words of memory starting at adress %p.\n", size,address);
            do
            {
                *address ^= 0xFFFFFFFF;
                address++;
                i++;
            }while(i < size);
            end_t = clock();
            elapsed_t = (((double)(end_t - start_t) / CLOCKS_PER_SEC) * 1000.0);
            printf("Total elapsed time = %fms\n", elapsed_t);
        }
        else
        {
            printf("Error: All or part of the requested memory area is outside of the allocated block!\n");
        }
    }
    else
    {
        printf("Error: No allocated blocks of memory to invert!\n");
    }

    return;
}

