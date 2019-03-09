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

#define WELCOME ("Welcome to the memory test suite!\nType 'help' to get a list of commands.\r\n")
#define PROMPT	(">>")

#define BUF_SIZE	(50)  //maximum size of buffer to recieve from stdin
#define CMD_SIZE	(12)  //maximum size of an individual command

char buffer[BUF_SIZE];
char command[CMD_SIZE];

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "help.h"
#include "allocmem.h"
#include "freemem.h"
#include "dispmem.h"
#include "writemem.h"
#include "invertmem.h"
#include "writepat.h"
#include "verifypat.h"
#include "exit.h"

const struct commandStruct commands[] = {
    {"help", &help, HELP_HELP},
    {"exit", &exitapp, HELP_EXIT},
    {"allocmem", &allocmem, HELP_ALLOC},
    {"freemem", &freemem, HELP_FREE},
    {"dispmem", &dispmem, HELP_DISP},
    {"writemem", &writemem, HELP_WRITE},
    {"invertmem", &invertmem, HELP_INV},
    {"writepat", &writepat, HELP_WPAT},
    {"verifypat", &verifypat, HELP_VPAT},
    {"",0,""}
};

/*
* Extract just the command name from the user input
*/
void getcmd(char *buf,char *cmd)
{
int16_t i;

    if((buf == 0) || (cmd == 0))
    {
        return;
    }

    //clear out any previous command
    for(i = 0; i < CMD_SIZE; i++)
        {
        cmd[i] = '\0';
        }
    
    //copy up to the first space line feed or null from the buffer
    //this get us just the command portion
    i = 0;
    while((*buf != ' ') && (*buf != '\n') && (*buf != '\0'))
    {
        *cmd = *buf;
        cmd++;
        buf++;
        i++;
    }
}

/*
* Find the index in the function table
*/
int getcmdidx(char *cmd, const struct commandStruct *commands)
{
int16_t i = 0;

    if((cmd == 0) || (commands == 0))
    {
        return(-1);
    }

    while((commands[i].func != 0) && (strcmp(cmd,commands[i].cmdName) != 0))
    {
        i++;
    }


    return(i);
}

int main(void)
{
int16_t cmdidx;
struct blockStruct block = {0, 0};
   
    //print the welcome message then enter a forever loop.
    //we'll only leave the loop if the user exits the application.  
    printf(WELCOME);

    while(1)
    {
        //print the command prompt and wait for user input
        printf(PROMPT);
        fgets(buffer,BUF_SIZE,stdin);

        // get the command name that the user typed so we can compare it against valid
        //command names.  
        getcmd(buffer,command);
        
        //get the index of the command that the user typed
        cmdidx = getcmdidx(command, &commands[0]);

        //if the user calls the exit command we also want to return from the application
        if(strcmp(command,"exit") == 0)
        {
            exitapp(buffer,&block);
            return(0);
        }

        //the help command is a little special.  we need to pass the command table
        //instead of the buffer.
        if(strcmp(command,"help") == 0)
        {
            help((char *)&commands[0],&block);
        }
        else if((cmdidx != -1) && (commands[cmdidx].func != 0))  //if the user typed a valid command name then run the associated function
        {
        (*commands[cmdidx].func)(buffer,&block);
        }
        else
        {
            printf("%s is not a recongized command.\r\n", buffer);
        }
    }
    return 0 ;
}
