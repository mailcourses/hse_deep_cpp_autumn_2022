#include "square.hpp"

int a = 10;

int square(int x)
{
    return x + x;
}

namespace fake
{
    int square(int x)
    {
        return x * x;
    }
}
