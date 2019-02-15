memtests : main.o
        cc -o memtests main.o

main.o : main.c
        cc -Wall -Werror -c main.c

clean :
        rm memtests main.o