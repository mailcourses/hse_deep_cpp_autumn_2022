CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: myvector containers

myvector: myvector.cpp
	$(CC) $(FLAGS) myvector.cpp -o myvector

containers: containers.cpp
	$(CC) $(FLAGS) containers.cpp -o containers

clean:
	rm -f *.o myvector containers
