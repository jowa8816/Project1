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
* @file types.h
* @brief Define some custom datatypes and structures
*
* @author Jon Warriner
* @date February 17 2019
* @version 1.0
*
*/
#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdlib.h>
#include <stdint.h>

//choose the platform
#define LINUX
//#define KL25

//choose printf based on platform
#if defined(LINUX)
#define MYPRINTF printf
#elif defined(KL25)
#include "fsl_debug_console.h"
#define MYPRINTF PRINTF
#else
#error "Need to select a platform!"
#endif


//define time measurement constants for and function for KL25
//these come from time.h for Linux
#if defined(LINUX)
#include <time.h>
#define MYCLOCK()	clock()
#elif defined(KL25)
#include "fsl_device_registers.h"
//this is negative because we are using the PIT as a timer and it counts down.
#define CLOCKS_PER_SEC	-48000000.0
#define MYCLOCK() PIT->CHANNEL[0].CVAL
#endif

//uncomment this define to enable some debug messages
//#define MY_DEBUG

//define a structure for a block of allocated memory
struct blockStruct
{
    void *ptr;
    uint32_t size;
};

//define a structure for the command table
struct commandStruct
{
    const char *cmdName;
    void (*func)(char *cmd, struct blockStruct *b);
    const char *helpStr;
};

#endif /* __TYPES_H__ */

