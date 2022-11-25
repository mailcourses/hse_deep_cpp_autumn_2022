#include <iostream>
#include <unordered_map>
#include <vector>

void foo() {} // ::foo

namespace A {

    void foo() {} // A::foo

    namespace B {

         void bar() // A::B::bar
         {
             foo(); // A::foo
             ::foo(); // foo()
         }
    }
}

struct Foo
{
    static int foo() { return 100; }
    int boo() { return 100; }
    static const int radius = 6400;
    const bool is_dummy = false;
};

namespace std
{
    int foo() { return 0; }
    //int endl = 10;
}


using hash_t = std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>>;

void moo(hash_t &hash)
{
}

int main()
{
    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> hash;
    hash_t::iterator it = hash.begin();

    std::cout << std::foo();
    std::cout << "Foo::foo() = " << Foo::foo() << std::endl;
    std::cout << "Foo::radius = " << Foo::radius << std::endl;

    Foo foo;
    std::cout << "Foo::dummy = " << foo.is_dummy << std::endl;
    return 0;
}

