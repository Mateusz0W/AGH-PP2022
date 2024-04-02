zad3.exe: stack_main.o stack.o
	gcc -o zad3.exe stack_main.o stack.o

stack.o: stack.c stack.h
	gcc -c stack.c -Wall

stack_main.o: stack_main.c stack.h
	gcc -c stack_main.c -Wall