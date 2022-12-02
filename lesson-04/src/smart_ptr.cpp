#include <iostream>
#include <chrono>

namespace std
{

using T = int32_t;

class smart_ptr
{
public:
    smart_ptr(T *ptr)
    {
        std::cout << "Ctor smart_ptr" << std::endl;
        ptr_ = ptr;
    }
    ~smart_ptr()
    {
        std::cout << "Dtor smart_ptr" << std::endl;
        delete ptr_;
    }
public:
    T *ptr_;
};

}

using duration_t = std::chrono::microseconds;

class Profiler
{
public:
    Profiler(const std::string & name)
    {
        start_ts_ = std::chrono::system_clock::now();
        func_name_ = name;
    }

    ~Profiler()
    {
        auto end_ts = std::chrono::system_clock::now();
        uint64_t duration = std::chrono::duration_cast<duration_t>(end_ts - start_ts_).count();
        std::cout << "Time of function [" << func_name_ << "] execution is " << duration << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> start_ts_;
    std::string func_name_;
};

void foo()
{
    Profiler profiler(__func__);
    for(size_t i = 0; i < 10000000; ++i)
    {
        char *p = new char[i+1];
        delete[] p;
    }
}
class Person
{
public:
    Person()
    {
        std::cout << "Ctor Person" << std::endl;
    }

    Person(int)
    {
        std::cout << "Ctor Person (age)" << std::endl;
    }
};

class Dog
{
public:
    Dog(const Person &person) : person_(person)
    {
        std::cout << "Ctor Dog" << std::endl;
    }
private:
    const Person &person_;
    Person person2_;
};

struct Foo
{
    void f1() const
    {
        // Изменение состояния объекта;
        moo -= 10;
        //f2();
    }

    void f2()
    {
        moo -= 10;
    }

    mutable int moo = 200;
    int boo = 10;
};

int main()
{
    std::smart_ptr p1(new int{10});
    foo();

    Person person;
    Dog catdog(person);

    const Foo foo;
    foo.f1();
}
