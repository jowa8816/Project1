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
clock_t start_t, end_t;
double elapsed_t;
uint32_t errors = 0;

    if((cmd == 0) || (b == 0))
    {
        printf("Internal Error: Missing buffer data or block pointer!\r\n");
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
            address = (int32_t *)strtoll(&cmd[9], &endptr, 16);
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
        else if((cmd[10] == '-') && (cmd[11] == 'o'))
        {
            //Extract the offset, size and seed from the command buffer
            //command name plus '-o' is 11 chars long so we should start after that
            address = b->ptr + (int32_t )strtoll(&cmd[12], &endptr, 16);
            size = strtol(endptr, &endptr, 10);
            seed = strtol(endptr, 0, 16);
        }
#ifdef DEBUG
        printf("address is: %p\r\n", address);
        printf("size is: 0x%08X\r\n", size);
        printf("seed is: 0x%08X\r\n", seed);
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
            printf("Verifying %d pseudo random words of memory starting at adress %p.\r\n", size, address);

            start_t = clock();
            do
            {
                ps_rand(&rnd);
                if(*address != rnd.X)
                {
                    errors++;
                    printf("Pattern mismatch at address: %p\r\n", address);
                    printf("Expected data: 0x%08X\r\n", rnd.X);
                    printf("Actual data: 0x%08X\r\n\n", *address);
                }
                address++;
                i++;
            }while(i < size);
            end_t = clock();
            elapsed_t = (((double)(end_t - start_t) / CLOCKS_PER_SEC) * 1000.0);
            if(errors == 0)
            {
                printf("All words verified!\r\n");
            }
            else
            {
                printf("%d total errors detected!\r\n", errors);
            }
            printf("Total elapsed time = %fms\r\n", elapsed_t);
        }
        else
        {
            printf("Error: All or part of the requested memory area is outside of the allocated block!\r\n");
        }
    }
    else
    {
        printf("Error: No allocated blocks of memory to verify!\r\n");
    }

    return;
}

