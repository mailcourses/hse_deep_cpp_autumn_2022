#include <iostream>

#include "utils.hpp"

double avg(int *arr, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return static_cast<double>( sum ) / size;
}
