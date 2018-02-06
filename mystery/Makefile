CC = cc
CCFLAGS  = -ansi -pedantic -Wall

all: mystery mystery.o
	${CC} $(CCFLAGS) -o mystery mystery.o

mystery: mystery.o

clean:
	rm -f *.o mystery

mystery.o: mystery.c mystery.h
	${CC} $(CCFLAGS) -c mystery.c

%.o: %.c mystery.h
	${CC} $(CCFLAGS) -c %.c
