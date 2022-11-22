CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: dummy memory

dummy: dummy.cpp
	$(CC) $(FLAGS) dummy.cpp -o dummy

memory: memory.cpp
	$(CC) $(FLAGS) memory.cpp -o memory

perfomance: perfomance.cpp
	$(CC) $(FLAGS) perfomance.cpp -o perfomance

clean:
	rm -f *.o memory dummy perfomance
