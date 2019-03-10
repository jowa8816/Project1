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
* @file verifypat.c
* @brief verifypat function for the memory test project.  
*
* This source file provides support for verifying a previously written
* pseudo random pattern within of a block of memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "verifypat.h"

void verifypat(char *cmd, struct blockStruct *b)
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
uint32_t errors = 0;

    if((cmd == 0) || (b == 0))
    {
        MYPRINTF("Internal Error: Missing buffer data or block pointer!\r\n");
        return;
    }
    //First, we need to make sure we have an allocated block of memory 
    //to write to
    if((b->ptr != 0) && (b->size != 0))
    {
        if(isdigit(cmd[10]))
        {
            //Extract the address, size and seed from the command buffer
            //command name is 9 chars long so we should start after that
#if defined(LINUX)
            address = (int32_t *)strtoll(&cmd[9], &endptr, 16);
#elif defined(KL25)
            address = (int32_t *)strtol(&cmd[9], &endptr, 16);
#endif
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
        else if((cmd[10] == '-') && (cmd[11] == 'o'))
        {
            //Extract the offset, size and seed from the command buffer
            //command name plus '-o' is 11 chars long so we should start after that
#if defined(LINUX)
            address = b->ptr + (int32_t )strtoll(&cmd[12], &endptr, 16);
#elif defined(KL25)
            address = b->ptr + (int32_t )strtol(&cmd[12], &endptr, 16);
#endif
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
#ifdef MY_DEBUG
        MYPRINTF("address is: %p\r\n", address);
        MYPRINTF("size is: 0x%08X\r\n", size);
        MYPRINTF("seed is: 0x%08X\r\n", seed);
#endif
        //make sure the memory we want to write is within the 
        //bounds of our allocated block
        if((size >= 0) && (address >= (int32_t *)b->ptr) && ((address + size) <= ((int32_t *)b->ptr + (int32_t)b->size)))
        {
            //setup the random number generator
            rnd.m = RAND_M;
            rnd.c = RAND_C;
            rnd.a = RAND_A;
            rnd.X = seed;
            MYPRINTF("Verifying %d pseudo random words of memory starting at adress %p.\r\n", size, address);

            start_t = MYCLOCK();
            do
            {
                ps_rand(&rnd);
                if(*address != rnd.X)
                {
                    errors++;
                    MYPRINTF("Pattern mismatch at address: %p\r\n", address);
                    MYPRINTF("Expected data: 0x%08X\r\n", rnd.X);
                    MYPRINTF("Actual data: 0x%08X\r\n\n", *address);
                }
                address++;
                i++;
            }while(i < size);
            end_t = MYCLOCK();
//            elapsed_t = (((double)(end_t - start_t) / CLOCKS_PER_SEC) * 1000.0);
            elapsed_t = (((double)(end_t - start_t) / CLOCKS_PER_SEC) * 1000000.0);
            if(errors == 0)
            {
                MYPRINTF("All words verified!\r\n");
            }
            else
            {
                MYPRINTF("%d total errors detected!\r\n", errors);
            }
//            MYPRINTF("Total elapsed time = %fms\r\n", elapsed_t);
            MYPRINTF("Total elapsed time = %d micro-seconds\r\n", (int32_t)elapsed_t);
        }
        else
        {
            MYPRINTF("Error: All or part of the requested memory area is outside of the allocated block!\r\n");
        }
    }
    else
    {
        MYPRINTF("Error: No allocated blocks of memory to verify!\r\n");
    }

    return;
}

