#include <iostream>
#include <vector>

class Base
{
public:
    virtual void base()
    {
        std::cout << "Base::base" << std::endl;
    }
};

class Derived : public Base
{
public:
    //virtual void base() override
    virtual void derived_method()
    {
        std::cout << "derived_method" << std::endl;
    }
};

class AnotherDerived : public Base
{
};

void foo(Base *obj)
{
    obj->base();
    try
    {
        Derived *derived = dynamic_cast<Derived *>( obj );
        if (derived == nullptr)
        {
            std::cout << "Can't cast to Derived *" << std::endl;
        }
        else
        {
            derived->derived_method();
        }
    }
    catch(std::bad_cast &exception)
    {
        std::cout << "Exception std:bad_cast" << std::endl;
    }
}

int main()
{
    std::vector<Base *> objs;
    objs.push_back(new Derived);
    objs.push_back(new AnotherDerived);
    for (size_t i = 0; i < objs.size(); ++i)
    {
        foo( objs[i] );
    }
    return 0;
}
