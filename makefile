#set default c compiler:gcc
CC=gcc

main:	io net
	${CC} main.c -o fmq io.o net.o

io:	
	${CC} -c io.c -o io.o

net:	fepoll
	${CC} -c net.c -o net.o

fepoll:	fepoll.h fepoll.c
	${CC} -c fepoll.c -o fepoll.o

clean:
	rm -f *.o
	rm -f fmq
