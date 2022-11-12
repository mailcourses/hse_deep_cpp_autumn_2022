CC=g++
FLAGS=-std=c++20 -Wall -Werror -Wextra -Wno-unused-variable

all: my_prog

my_prog: main.o square.o
	$(CC) $(FLAGS) -o my_prog main.o square.o

main.o: main.cpp square.hpp
	$(CC) $(FLAGS) -c main.cpp

square.o: square.cpp square.hpp
	$(CC) $(FLAGS) -c square.cpp

test:
	<команда для запуска тестов>

clean:
	rm -rf *.o my_prog
