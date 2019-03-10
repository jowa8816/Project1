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
* @file writemem.c
* @brief writemem function for the memory test project.  
*
* This source file provides support for writing to a location within
* of a block of memory for the memory test project.  
*
* @author Jon Warriner
* @date February 17, 2019
* @version 1.0

*/

#include "writemem.h"

void writemem(char *cmd, struct blockStruct *b)
{
int32_t data;
int32_t *address;
char *endptr = 0;

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
            //Extract the address and size from the command buffer
            //command name is 9 chars long so we should start after that
#if defined(LINUX)
            address = (int32_t *)strtoll(&cmd[8], &endptr, 16);
#elif defined(KL25)
            address = (int32_t *)strtol(&cmd[8], &endptr, 16);
#endif
            data = strtol(endptr, 0, 16);
        }
        else if((cmd[9] == '-') && (cmd[10] == 'o'))
        {
            //Extract the offset and size from the command buffer
            //command name plus '-o' is 11 chars long so we should start after that
#if defined(LINUX)
            address = (int32_t *)b->ptr + (int32_t )strtoll(&cmd[11], &endptr, 16);
#elif defined(KL25)
            address = (int32_t *)b->ptr + (int32_t )strtol(&cmd[11], &endptr, 16);
#endif
            data = strtol(endptr, 0, 16);
        }
#ifdef MY_DEBUG
        MYPRINTF("address is: %p\r\n", address);
        MYPRINTF("data is: 0x%08X\r\n", data);
#endif
        //make sure the memory we want to write is within the 
        //bounds of our allocated block
        if((address >= (int32_t *)b->ptr) && (address <= ((int32_t *)b->ptr + ((int32_t)b->size * sizeof(int32_t)))))
        {
            *address = data;
            MYPRINTF("%X written to address %p\r\n", data, address);
        }
        else
        {
            MYPRINTF("Error: The requested address is outside of the allocated block!\r\n");
        }
    }
    else
    {
        MYPRINTF("Error: No allocated blocks of memory to write!\r\n");
    }

    return;
}

