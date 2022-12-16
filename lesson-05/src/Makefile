CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: new cast friend shared_ptr

new: new.cpp
	$(CC) $(FLAGS) new.cpp -o new

cast: cast.cpp
	$(CC) $(FLAGS) cast.cpp -o cast

friend: friend.cpp
	$(CC) $(FLAGS) friend.cpp -o friend

shared_ptr: shared_ptr.cpp
	$(CC) $(FLAGS) shared_ptr.cpp -o shared_ptr

clean:
	rm -f *.o new cast friend shared_ptr
