CC = gcc

all: calculator

calculator: calculator.c
	gcc -Wall -Wextra -g3 calculator.c -o calculator 
clean:
	rm calculator