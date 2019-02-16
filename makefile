#*****************************************************************************
# Copyright (C) 2019 by Jon Warriner
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Jon Warriner and the University of Colorado are not liable for
# any misuse of this material.
#
#****************************************************************************
#
# @file makefile
# @brief makefile for the memory test project
#
# This file defines the make steps to build the
# memory test project.  
#
# @author Jon Warriner
# @date February 14, 2019
# @version 1.0
#
memtests : main.o help.o
	cc -o memtests main.o help.o

main.o : main.c help.h
	cc -Wall -Werror -c main.c

help.o : help.c help.h
	cc -Wall -Werror -c help.c

clean :
	rm memtests main.o help.o
