#include <iostream>
#include <functional>

int real_func(int x, int y)
{
    return x + y;
}

class Functor
{
public:
    int operator()(int x, int y)
    {
        return (x + y) * -1;
    }

    int operator()(int x, int y, int z)
    {
        return (x + y) * z;
    }
};

int main()
{
    auto func = [](int x, int y) { return x + y; };
    //auto i = 10;
    std::cout << func(10, 5) << std::endl;

    int mult = 10;
    std::cout << "mult before lambda: " << mult << std::endl;
    auto func2 = [mult](int x, int y) mutable {
        mult = 100;
        return (x + y) * mult;
    };
    std::cout << func2(10, 5) << std::endl;
    std::cout << "mult after lambda: " << mult << std::endl;

    Functor func3;
    std::cout << func3(10, 5) << std::endl;

    std::vector<std::function<int(int, int)>> workflow;
    //std::vector<int (*)(int, int)> workflow; <-- ошибка компиляция.
    workflow.push_back( real_func );
    workflow.push_back( func2 );
    workflow.push_back( func3 );

    func3(1, 2, 3);

    int a = 100000, b = 500;
    for (size_t i = 0; i < workflow.size(); ++i)
    {
        std::cout << "workflow stage #" << i << " is [" << workflow[i](a, b) << "]\n";
    }
}
