#include <iostream>
#include <cstdarg>

int sum(size_t n, ...)
{
    va_list args;
    va_start(args, n);
    int result{};
    while(n--) {
       auto next_element = va_arg(args, int);
       result += next_element;
    }
    va_end(args);
    return result;
}


int main()
{
    std::cout << sum(4, 10, 5, 4, 100) << std::endl;
    return 0;
}
