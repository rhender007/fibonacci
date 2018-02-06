CC = cc
CCFLAGS  = -ansi -pedantic -Wall

all: nCr.o formula.o
	${CC} $(CCFLAGS) -o formula nCr.o formula.o

formula: formula.o nCr.o

nCr.o: nCr.h nCr.s
	${CC} $(CCFLAGS) -c nCr.s

formula.o: formula.c formula.h
	${CC} $(CCFLAGS) -c -Wall formula.c

clean:
	rm -f *.o formula

%.o: %.c nCr.h
	${CC} $(CCFLAGS) -c %.c

