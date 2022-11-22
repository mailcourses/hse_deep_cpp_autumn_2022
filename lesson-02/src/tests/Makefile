CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra
TEST_LIB=-lgtest -lgtest_main -lpthread

all: utils test_bin

utils: utils.cpp utils.hpp
	$(CC) $(FLAGS) -c utils.cpp

test_bin: utils.o tests.cpp
	$(CC) $(FLAGS) utils.o tests.cpp -o test_bin $(TEST_LIB)

test:
	./test_bin

clean:
	rm -f *.o test_bin
