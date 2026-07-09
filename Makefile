.PHONY:clean

all: main

main: creative-test-refactored.o ficha.o
	gcc -o main creative-test-refactored.o ficha.o -I ./include 

creative-test-refactored.o: creative-test-refactored.c
	gcc -c creative-test-refactored.c -I ./include 

ficha.o: ficha.c ./include/ficha.h
	gcc -c ficha.c 

clean:
	rm *.o main ficha.txt
