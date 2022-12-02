#include <iostream>

/*
    A
   / \
  B   C
  \  /
    D
*/

class Animal
{
public:
    Animal()
    {
        std::cout << "Ctor Animal" << std::endl;
    }

    ~Animal()
    {
        std::cout << "Dtor Animal" << std::endl;
    }
public:
    uint32_t age{10};
};

class Mammal : public Animal
{
public:
    Mammal()
    {
        std::cout << "Ctor Mammal" << std::endl;
    }

    ~Mammal()
    {
        std::cout << "Dtor Mammal" << std::endl;
    }

    void bark() {
        std::cout << "he-he" << std::endl;
    }
/*
 * public:
 *  uint8_t age{0};
 */
};

struct Dog
{
    Dog()
    {
        std::cout << "Ctor Dog" << std::endl;
    }

    ~Dog()
    {
        std::cout << "Dtor Dog" << std::endl;
    }

};

struct Daschund : Dog, Mammal
{
    Daschund()
    {
        std::cout << "Ctor Daschund" << std::endl;
    }

    Daschund(const std::string &name) : name(name)
    {
        std::cout << "Ctor Daschund" << std::endl;
    }

    ~Daschund()
    {
        std::cout << "Dtor Daschund" << std::endl;
    }

    void bark() {
        std::cout << "Wow-wow" << std::endl;
    }

    bool operator==(const Daschund &rhs)
    {
        return name == rhs.name;
    }

    Daschund operator+(const Daschund &rhs)
    {
        return Daschund(name + rhs.name);
    }

    std::string name;
};

int ark(Mammal *mammal)
{
    mammal->bark();
    return 0;
}

int main()
{
    Animal animal;

    std::cout << "=====" << std::endl;
    Mammal mammal;


    std::cout << "Animal.age = " << animal.age << std::endl;
    std::cout << "Mammal.age=" << mammal.age << std::endl;

    std::cout << "=====" << std::endl;
    Daschund dog;
    dog.bark();
    Mammal *mammal_dog = new Daschund();
    std::cout << "===== Before ark ====" << std::endl;
    ark(mammal_dog);

    Daschund roxana("Roxana");
    Daschund mortimer("Mortimer");

    std::cout << std::boolalpha << (roxana == roxana) << std::endl;
    std::cout << std::boolalpha << (roxana == mortimer) << std::endl;
}
