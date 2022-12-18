#include <iostream>

struct A
{
    void foo() {}
};

struct B
{
};

template<class T1, class T2>
struct IsSame
{
    static constexpr bool value = false;
};

template<class T>
struct IsSame<T, T>
{
    static constexpr bool value = true;
};

template<typename T>
struct HasFoo
{
    static int check(...);

    template<typename U>
    static auto check(U *u) -> decltype(u->foo());

    static constexpr bool value = IsSame<void,
                                         decltype( HasFoo<T>::check( static_cast<T *>(nullptr) ) )>::value;
};


template<typename T>
void hasFoo(T& t,
            typename std::enable_if<HasFoo<T>::value>::type* = nullptr)
{
    std::cout << "Has Foo" << std::endl;
    t.foo();
}

template<typename T>
void hasFoo(T&,
     typename std::enable_if<!HasFoo<T>::value>::type* = nullptr)
{
    std::cout << "Has not Foo" << std::endl;
}


int main()
{
    std::cout << std::boolalpha << HasFoo<A>::value << std::endl;
    std::cout << HasFoo<B>::value << std::endl;
    A a;
    B b;
    hasFoo(a);
    hasFoo(b);
}
