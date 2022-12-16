#include <iostream>
#include <vector>

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

    virtual ~Animal()
    {
        std::cout << "Dtor Animal" << std::endl;
    }

    virtual void bark() = 0;
    virtual void sleep() = 0;
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

    virtual ~Mammal()
    {
        std::cout << "Dtor Mammal" << std::endl;
    }

    virtual void bark() {
        std::cout << "he-he" << std::endl;
    }

    virtual void sleep() override {}
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

struct Daschund : Dog, public Mammal
{
    Daschund()
    {
        std::cout << "Ctor Daschund" << std::endl;
    }

    Daschund(const std::string &name) : name(name)
    {
        std::cout << "Ctor Daschund" << std::endl;
    }

    virtual ~Daschund()
    {
        std::cout << "Dtor Daschund" << std::endl;
    }

    virtual void bark() override {
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

int push_to_ark(Animal *animal)
{
    animal->bark();
    animal->sleep();
    return 0;
}

class Ape : public Mammal
{
public:
    virtual void bark() override {
        std::cout << "Uuu-aaa" << std::endl;
    }

    Ape() {
        std::cout << "Ctor Ape" << std::endl;
    }

    virtual ~Ape() {
        std::cout << "Dtor Ape" << std::endl;
    }
};

Animal * GenerateMammal(int i)
{
    if (i == 0)
    {
        return new Daschund();
    }
    return new Ape();
}

int main()
{
    //Animal animal;

    std::cout << "=====" << std::endl;
    Mammal mammal;


    //std::cout << "Animal.age = " << animal.age << std::endl;
    std::cout << "Mammal.age=" << mammal.age << std::endl;

    std::cout << "=====" << std::endl;
    Daschund dog;
    dog.bark();
    //Mammal *mammal_dog = new Daschund();

    //! Добавляем животных в ковчег.
    std::vector<Animal *> mammals;
    mammals.push_back( GenerateMammal(0) );
    mammals.push_back( GenerateMammal(1) );

    std::cout << "===== sizeof(Mammal)" << sizeof(Mammal) << std::endl;
    std::cout << "=====" << std::endl;
    for (size_t i = 0; i < mammals.size(); ++i)
    {
        std::cout << "Pushing to ark #" << i << std::endl;
        push_to_ark(mammals[i]);
        delete mammals[i];
    }
    std::cout << "=====" << std::endl;

    Daschund roxana("Roxana");
    Daschund mortimer("Mortimer");

    std::cout << std::boolalpha << (roxana == roxana) << std::endl;
    std::cout << std::boolalpha << (roxana == mortimer) << std::endl;
}
