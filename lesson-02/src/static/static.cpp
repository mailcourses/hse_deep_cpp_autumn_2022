#include <iostream>
#include "static.hpp"

int j = 20;

void foo(int a)
{
    static int i = 0;
    std::cout << "foo::i: " << i << std::endl;
    i += a;
}

/*
int main()
{
    foo(0);
    foo(10);
    foo(1);
    foo(0);
    return 100500;
}*/
