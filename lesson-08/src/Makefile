CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: myvector containers iterators algorithms

myvector: myvector.cpp
	$(CC) $(FLAGS) myvector.cpp -o myvector

containers: containers.cpp
	$(CC) $(FLAGS) containers.cpp -o containers

iterators: iterators.cpp
	$(CC) $(FLAGS) iterators.cpp -o iterators

algorithms: algorithms.cpp
	$(CC) $(FLAGS) algorithms.cpp -o algorithms

clean:
	rm -f *.o myvector containers iterators algorithms
