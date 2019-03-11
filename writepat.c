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
int32_t size;
uint32_t i = 0;
uint32_t seed = 0;
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
    //to write to
    if((b->ptr != 0) && (b->size != 0))
    {
        if(isdigit(cmd[9]))
        {
            //Extract the address, size and seed from the command buffer
            //command name is 9 chars long so we should start after that
#if defined(LINUX)
            address = (int32_t *)strtoll(&cmd[8], &endptr, 16);
#elif defined(KL25)
            address = (int32_t *)strtol(&cmd[8], &endptr, 16);
#endif
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
        else if((cmd[9] == '-') && (cmd[10] == 'o'))
        {
            //Extract the offset, size and seed from the command buffer
            //command name plus '-o' is 11 chars long so we should start after that
#if defined(LINUX)
            address = b->ptr + (int32_t )strtoll(&cmd[11], &endptr, 16);
#elif defined(KL25)
            address = b->ptr + (int32_t )strtol(&cmd[11], &endptr, 16);
#endif
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
#ifdef MY_DEBUG
        MYPRINTF("address is: %p\r\n", address);
        MYPRINTF("size is: 0x%08X\r\n", size);
        MYPRINTF("seed is: 0x%08X\r\n", seed);
#endif
#ifndef NO_RANGE
        //make sure the memory we want to write is within the 
        //bounds of our allocated block
        if((size >= 0) && (address >= (int32_t *)b->ptr) && ((address + size) <= ((int32_t *)b->ptr + (int32_t)b->size)))
        {
#endif
            //setup the random number generator
            rnd.m = RAND_M;
            rnd.c = RAND_C;
            rnd.a = RAND_A;
            rnd.X = seed;
            MYPRINTF("Writing %d pseudo random words of memory starting at adress %p.\r\n", size, address);
#ifdef MY_DEBUG
#if defined(LINUX)
            MYPRINTF("   Address           Data\r\n");
            MYPRINTF("--------------    ----------\r\n");
#elif defined(KL25)
            MYPRINTF(" Address         Data\r\n");
            MYPRINTF("----------    ----------\r\n");
#endif
#endif
            start_t = MYCLOCK();
            do
            {
                ps_rand(&rnd);
                *address = rnd.X;
#ifdef MY_DEBUG
                MYPRINTF("%p    0x%08X\r\n", address, *address);
#endif
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
        MYPRINTF("Error: No allocated blocks of memory to write!\r\n");
    }

    return;
}

