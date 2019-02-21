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
    if(cmd == 0)
    {
        printf("Missing buffer data\n");
        return;
    }

    printf("This will be the invertmem function.\n");

    return;
}

