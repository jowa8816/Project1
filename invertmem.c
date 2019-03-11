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
#if defined(LINUX)
clock_t start_t, end_t;
#elif defined(KL25)
int32_t start_t, end_t;
#endif
double elapsed_t;

    if((cmd == 0) || (b == 0))
    {
        MYPRINTF("Internal Error: Missing buffer data or block pointer!\r\n");
        return;
    }

    //First, we need to make sure we have an allocated block of memory 
    //to invert
    if((b->ptr != 0) && (b->size != 0))
    {
        if(isdigit(cmd[10]))
        {
            //Extract the address and size from the command buffer
            //command name is 9 chars long so we should start after that
#if defined(LINUX)
            address = (int32_t *)strtoll(&cmd[9], &endptr, 16);
#elif defined(KL25)
            address = (int32_t *)strtol(&cmd[9], &endptr, 16);
#endif
            size = strtol(endptr, 0, 10);
        }
        else if((cmd[10] == '-') && (cmd[11] == 'o'))
        {
            //Extract the offset and size from the command buffer
            //command name plus '-o' is 12 chars long so we should start after that
#if defined(LINUX)
            address = b->ptr + (int32_t )strtoll(&cmd[12], &endptr, 16);
#elif defined(KL25)
            address = b->ptr + (int32_t )strtol(&cmd[12], &endptr, 16);
#endif
            size = strtol(endptr, 0, 10);
        }
#ifdef MY_DEBUG
        MYPRINTF("address is: %p\r\n", address);
        MYPRINTF("size is: %d\r\n", size);
#endif
#ifndef NO_RANGE
        //make sure the memory we want to invert is within the 
        //bounds of our allocated block
        if((size >= 0) && (address >= (int32_t *)b->ptr) && ((address + size) <= ((int32_t *)b->ptr + (int32_t)b->size)))
        {
#endif
            MYPRINTF("Inverting %d words of memory starting at adress %p.\r\n", size,address);
            start_t = MYCLOCK();
            do
            {
                *address ^= 0xFFFFFFFF;
                address++;
                i++;
            }while(i < size);
            end_t = MYCLOCK();
            elapsed_t = (((double)(end_t - start_t) / CLOCKS_PER_SEC) * 1000000.0);
            MYPRINTF("Total elapsed time = %d micro-seconds\r\n", (int32_t)elapsed_t);
#ifndef NO_RANGE
        }
        else
        {
            MYPRINTF("Error: All or part of the requested memory area is outside of the allocated block!\r\n");
        }
#endif
    }
    else
    {
        MYPRINTF("Error: No allocated blocks of memory to invert!\r\n");
    }

    return;
}

