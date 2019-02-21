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
* @file help.c
* @brief help function for the memory test project.  
*
* This source file provides support for displaying the list of
* commands available for the memory test project.  
*
* @author Jon Warriner
* @date February 16, 2019
* @version 1.0
*
*/

#include "help.h"

void help(char *cmd, struct blockStruct *b)
{
struct commandStruct *tbl = (struct commandStruct *)cmd;
int16_t i = 0;

    if(cmd == 0)
    {
        printf("Can't display help\n");
        return;
    }

    while(tbl[i].func != 0)
    {
        printf("%s\n", tbl[i].helpStr);
        tbl++;
    }

    return;
}

