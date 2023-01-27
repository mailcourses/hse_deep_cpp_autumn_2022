#include <iostream>

struct A
{
    void foo()
    {
    }
};

struct B
{
};

template<typename T>
concept HasFoo = requires(T t) {
    { t.foo() } -> std::same_as<void>;
};

template<typename T>
void boo(T /*t*/)
{
    std::cout << "boo without void foo()" << std::endl;
}

/*
 * template<HasFoo T>
 * void boo(T)
 */
template<typename T>
void boo(T /*t*/) requires HasFoo<T>
{
    std::cout << "boo with void foo()" << std::endl;
}

int main()
{
    A a;
    B b;
    boo(a);
    boo(b);
}
