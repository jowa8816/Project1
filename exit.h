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
* @file exit.h
* @brief An abstraction for the exit function
*
* This header file provides an abstraction of the function to
* exit the application.
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __EXIT_H__
#define __EXIT_H__

#include <stdio.h>
#include "types.h"

//define the help string
#define HELP_EXIT ("exit - Exit this application\r\n")

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
void exitapp(char *cmd, struct blockStruct *b);
#endif /* __EXIT_H__ */

