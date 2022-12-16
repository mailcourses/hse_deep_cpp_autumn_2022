#include <iostream>

namespace X
{
    struct A
    {
    };

    void foo(const A& /*a*/)
    {
        std::cout << "X::foo()" << std::endl;
    }

    class B
    {
    friend void boo(const B& b);
    friend class A;
    friend std::ostream &operator<<(std::ostream &out, const B& b);
    private:
        int x = 100;
    };

    void boo(const B& b)
    {
        std::cout << "X::boo.x=" << b.x << std::endl;
        B &tmp = const_cast<B&>(b);
        tmp.x = 100500;
    }

    std::ostream &operator<<(std::ostream &out, const B& b)
    {
        out << "B(" << b.x << ")";
        return out;
    }
}

void foo(const X::A &)
{
    std::cout << "::foo()" << std::endl;
}

int main()
{
    X::A a;
    //A a; <-- ошибка компиляции
    ::foo(a);

    X::B b;
    X::boo(b);
    std::cout << b << std::endl;
}
