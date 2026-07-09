.PHONY:clean

CC = gcc
OBJS = creative-test-refactored.o ficha.o

all: main

main: ${OBJS}
	${CC} -o main ${OBJS} -I ./include 

creative-test-refactored.o: creative-test-refactored.c
	${CC} -c creative-test-refactored.c -I ./include 

ficha.o: ficha.c ./include/ficha.h
	${CC} -c ficha.c 

clean:
	rm *.o main ficha.txt
