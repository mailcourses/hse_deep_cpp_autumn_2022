CC=g++
FLAGS=-std=c++20 -Wall -pedantic -Werror -Wextra

all: matrix template vector things sfinae

matrix: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp -o matrix

template: template.cpp
	$(CC) $(FLAGS) template.cpp -o template

things: things.cpp
	$(CC) $(FLAGS) things.cpp -o things

sfinae: sfinae.cpp
	$(CC) $(FLAGS) sfinae.cpp -o sfinae

clean:
	rm -f *.o matrix template sfinae things
