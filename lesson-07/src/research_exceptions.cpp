struct A
{
    A() {}
    ~A() {}
};

void bar()
{
    throw A();
}

void foo()
{
    A a;
    try
    {
        bar();
    }
    catch(...)
    {
    }
}
