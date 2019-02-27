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
memtests : main.o help.o allocmem.o freemem.o dispmem.o writemem.o invertmem.o writepat.o verifypat.o exit.o ps_rand.o
	cc -o memtests main.o help.o allocmem.o freemem.o dispmem.o writemem.o invertmem.o writepat.o verifypat.o exit.o ps_rand.o

main.o : main.c help.h allocmem.h freemem.h dispmem.h writemem.h invertmem.h writepat.h verifypat.h types.h exit.h
	cc -Wall -Werror -c main.c

help.o : help.c help.h types.h
	cc -Wall -Werror -c help.c

allocmem.o : allocmem.c allocmem.h types.h
	cc -Wall -Werror -c allocmem.c

freemem.o : freemem.c freemem.h types.h
	cc -Wall -Werror -c freemem.c

dispmem.o : dispmem.c dispmem.h types.h
	cc -Wall -Werror -c dispmem.c

writemem.o : writemem.c writemem.h types.h
	cc -Wall -Werror -c writemem.c

invertmem.o : invertmem.c invertmem.h types.h
	cc -Wall -Werror -c invertmem.c

writepat.o : writepat.c writepat.h types.h ps_rand.h
	cc -Wall -Werror -c writepat.c

verifypat.o : verifypat.c verifypat.h types.h ps_rand.h
	cc -Wall -Werror -c verifypat.c

exit.o : exit.c exit.h types.h
	cc -Wall -Werror -c exit.c

ps_rand.o : ps_rand.c ps_rand.h types.h
	cc -Wall -Werror -c ps_rand.c

clean :
	rm memtests main.o help.o allocmem.o freemem.o dispmem.o writemem.o invertmem.o writepat.o verifypat.o exit.o ps_rand.o

test : memtests testscript
	./memtests < testscript
