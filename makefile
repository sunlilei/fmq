#set default c compiler:gcc
CC=gcc

main:	io net
	${CC} main.c -o fmq io.o net.o

io:	io.h io.c
	${CC} -c io.c -o io.o

net:	net.h net.c
	${CC} -c net.c -o net.o

clean:
	rm -f *.o
	rm -f fmq
