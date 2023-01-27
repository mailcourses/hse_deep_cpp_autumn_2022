CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: concept universal_ref error_handling exceptions research_exceptions

concept: concept.cpp
	$(CC) $(FLAGS) concept.cpp -o concept

universal_ref: universal_ref.cpp
	$(CC) $(FLAGS) universal_ref.cpp -o universal_ref

error_handling: error_handling.cpp
	$(CC) $(FLAGS) error_handling.cpp -o error_handling

exceptions: exceptions.cpp
	$(CC) $(FLAGS) exceptions.cpp -o exceptions

research_exceptions: research_exceptions.cpp
	$(CC) $(FLAGS) research_exceptions.cpp -c

clean:
	rm -f *.o concept universal_ref error_handling exceptions research_exceptions
