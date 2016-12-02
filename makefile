udll.o: udll.c udll.h
	gcc -Wall -c udll.c
main.o: main.c
	gcc -Wall -c main.c
universalDoubleLinkedList: main.o udll.o
	gcc -Wall -o universalDoubleLinkedList main.o udll.o

