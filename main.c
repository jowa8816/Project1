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
* @file main.c
* @brief main file for the memory test project.  
*
* This source file provides the main() function for the
* memory test project.  
*
* @author Jon Warriner
* @date February 14, 2019
* @version 1.0
*
*/

#define WELCOME ("Welcome to the memory test suite!\nType 'help' to get a list of commands.\n")
#define PROMPT	(">>")

#define BUF_SIZE	(50)

char buffer[BUF_SIZE];

#include <stdio.h>
#include "help.h"
#include "allocate.h"
#include "freemem.h"
#include "dispmem.h"
#include "writemem.h"
#include "invertmem.h"
#include "writepat.h"
#include "verifypat.h"

struct commandStruct
{
    const char *cmdName;
    void (*func)(char *cmd);
    const char *helpStr;
};

const struct commandStruct commands[] = {
    {"help", &help, "Display the help message"},
    {"allocate", &allocate, "Allocate a block of memory"},
    {"freemem", &freemem, "Free a block of memory"},
    {"dispmem", &dispmem, "Display a block of memory"},
    {"writemem", &writemem, "Write to a specified memory location"},
    {"invertmem", &invertmem, "Invert a block of memory"},
    {"writepat", &writepat, "Write a pseudo random pattern to a block of memory"},
    {"verifypat", &verifypat, "Verify a pseudo random pattern within a block of memory"},
    {"",0,""}
};

int main(void)
{
    
    printf(WELCOME);
    printf(PROMPT);
    fgets(buffer,BUF_SIZE,stdin);
    printf("string is: %s\n", buffer);

    printf("\n");
	
	//help();

    return 0 ;
}
