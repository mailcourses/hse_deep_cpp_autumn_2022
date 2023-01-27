#include <iostream>

template<typename T>
void f(T&& t)
{
    std::cout << "Calling f" << std::endl;
    t += 10;
}

template<typename T>
class vector
{
public:
    void push_back(T&& /*t*/) {  }
    void push_back(T& /*t*/) {  }

    template<typename... Args>
    void emplace_back(Args&& .../*args*/)
    {
        std::cout << "emplace_back" << std::endl;
    }
};

int main()
{
    int a = 10;
    f(a);
    std::cout << "a=" << a << std::endl;
    f(std::move(a));
    std::cout << "a=" << a << std::endl;

    vector<int> v;
    v.push_back(std::move(a));
    v.push_back(a);
    v.emplace_back(std::move(a));
    v.emplace_back(a);
}
