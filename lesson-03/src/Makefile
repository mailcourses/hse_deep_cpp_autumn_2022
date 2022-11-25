CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: smart_pointers fastcall arguments

smart_pointers: smart_pointers.cpp
	$(CC) $(FLAGS) smart_pointers.cpp -o smart_pointers

fastcall: fastcall.cpp
	$(CC) $(FLAGS) fastcall.cpp -o fastcall

arguments: arguments.cpp
	$(CC) $(FLAGS) arguments.cpp -o arguments

clean:
	rm -f *.o smart_pointers fastcall arguments
