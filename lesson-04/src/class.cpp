#include <iostream>

class A
{
public:
    A() = default;
    A(const A&) = delete;
    /*A(int a)
    {
        x = a;
        std::cout << "Ctor A(int)" << std::endl;
    }*/
    ~A()
    {
        std::cout << "Dtor ~A()" << std::endl;
    }
public:
    std::string GetName()
    {
        return name + std::to_string(x);
    }
public:
    int x{0};
private:
    std::string name{"Jesse"};
};

struct B
{
    int x{1};
};

struct Point
{
    int x;
    int y;
    double distance(const Point &)
    {
        return this->x + /*this->*/y;
    }

    static double magic(const Point &rhs)
    {
        return rhs.x + rhs.y;
    }

    /*
    static double distance(const YoulaProduct &lhs, const YoulaProduct &rhs)
    {
        //..
    }
    */
};

namespace Point_
{
    double magic(const Point &rhs)
    {
        return rhs.x + rhs.y;
    }
}

int main()
{
    A a;
    //A a2 = a; <-- копирующий конструктор удалён.
    B b;
    std::cout << a.x << ", " << b.x << std::endl;
    std::cout << "Name of a=" << a.GetName() << std::endl;

    Point p1;
    std::cout << "Distance: " << p1.distance(p1) << std::endl;
    std::cout << "Magic: " << p1.magic(p1) << std::endl;
    std::cout << "Magic2: " << Point_::magic(p1) << std::endl;
    p1.distance(p1);
    int32_t *arr = new int[500000000];
    delete[] arr;
    //p1.x + p1.y;
}
