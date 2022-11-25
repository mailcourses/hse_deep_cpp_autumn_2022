[[gnu::fastcall]]
void foo1(int a, int b, int c, int d)
{
}

void foo2(int a, int b, int c, int d)
{
}

void foo3(int a, int b, int c, int d, int e, int f, int i, int j)
{
}

void bar1()
{
    foo1(1, 2, 3, 4);
}

void bar2()
{
    foo2(5, 6, 7, 8);
}

void bar3()
{
    foo3(9, 10, 11, 12, 13, 14, 15, 16);
}
