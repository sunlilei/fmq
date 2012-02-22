#set default c compiler:gcc
CC=gcc

main:	io
	${CC} main.c -o fmq io.o

io:	io.h io.c
	${CC} -c io.c -o io.o

clean:
	rm -f *.o
	rm -f fmq
