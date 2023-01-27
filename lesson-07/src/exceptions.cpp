#include <iostream>
#include <memory>

struct A
{
    A(int i) : id(i)
    {
        std::cout << "A(" << i << ")" << std::endl;
    }
    ~A()
    {
        std::cout << "~A(" << id << ")" << std::endl;
    }
    int id;
};

struct Error
{
};

struct FileError : Error
{
};

void foo()
{
    A a1(1);
    throw FileError();
}

void bar()
{
    A a2(2);
    try
    {
        A a3(3);
        foo();
    }
    catch(...)
    {
        std::cout << "catch any exception" << std::endl;
    }
    /*catch(const Error&)
    {
        std::cout << "catch Error" << std::endl;
    }*/
}

class Dog
{
public:
    Dog()
    {
        data_.reset(new int);
        std::cout << "Dog()" << std::endl;
        throw Error();
    }
    ~Dog()
    {
        std::cout << "~Dog()" << std::endl;
    }
private:
    std::unique_ptr<int> data_;
};

int main()
{
    bar();
    try
    {
        Dog dog;
    }
    catch(...)
    {
    }
}
