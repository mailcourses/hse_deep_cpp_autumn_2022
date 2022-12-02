CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: lambda enum class smart_ptr inheritance

lambda: lambda.cpp
	$(CC) $(FLAGS) lambda.cpp -o lambda

enum: enum.cpp
	$(CC) $(FLAGS) enum.cpp -o enum

class: class.cpp
	$(CC) $(FLAGS) class.cpp -o class

smart_ptr: smart_ptr.cpp
	$(CC) $(FLAGS) smart_ptr.cpp -o smart_ptr

inheritance: inheritance.cpp
	$(CC) $(FLAGS) inheritance.cpp -o inheritance

clean:
	rm -f *.o lambda enum class smart_ptr inheritance
