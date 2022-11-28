CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra
TEST_LIB=-lgtest -lgtest_main -lpthread

all: allocator test_bin

allocator: allocator.cpp allocator.hpp
	$(CC) $(FLAGS) -c allocator.cpp

test_bin: allocator.o tests.cpp
	$(CC) $(FLAGS) allocator.o tests.cpp -o test_bin $(TEST_LIB)

test:
	./test_bin

clean:
	rm -f *.o test_bin
