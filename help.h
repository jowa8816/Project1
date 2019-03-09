/*****************************************************************************
* Copyright (C) 2019 by Jon Warriner
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Jon Warrinerk and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file help.h
* @brief An abstraction for the help function
*
* This header file provides an abstraction of the function to
* display a list of available commands.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __HELP_H__
#define __HELP_H__

#include <stdio.h>
#include "types.h"

//define the help string
#define HELP_HELP ("help - Display the help message.\r\n")

/**
* @brief Displays a list of commands
*
* Given a pointer to a char command buffer, this will display the help
* message.
*
* @param buf Pointer to a command buffer
*
* @return void.
*/
void help(char *cmd, struct blockStruct *b);
#endif /* __HELP_H__ */

