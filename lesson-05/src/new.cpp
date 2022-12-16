#include <iostream>
#include <new>

/*
 * void* operator new(size_t)
 * void operator delete(void *)
 * void* operator new[](size_t)
 * void operator delete[](void *)
 */

void * operator new(size_t size)
{
    std::cout << "::operator new, size=" << size << std::endl;
    return malloc(size);
}

class Foo
{
public:
    Foo()
    {
        std::cout << "Ctor Foo()" << std::endl;
    }

    ~Foo()
    {
        std::cout << "Dtor Foo()" << std::endl;
    }

    void * operator new(size_t size)
    {
        std::cout << "Foo::operator new, size=" << size << std::endl;
        return malloc(size);
    }
private:
    double boo_;
};

class Boo
{
};

int main()
{
    Foo *foo = new Foo;
    delete foo;

    Boo *boo = new Boo;
    delete boo;
}
