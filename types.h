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

//define some standard datatypes
/*typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef long int32_t;
typedef unsigned long uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;*/

#include <stdlib.h>
#include <stdint.h>

//uncomment this define to enable some debug messages
//#define DEBUG

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

