#include <stdlib.h>
#include <stdio.h>

int func1(int i)
{
    static int s = 0;
    s += i;
    return s;
}

void func2(char *ch, int len)
{
    printf("String: [%s], len: %d\n", ch, len);
}

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
