#include "vector.hpp"

struct A
{
    void magic() {}
};

int main()
{
    //mystd::vector<int32_t> vec(10);
    mystd::vector<std::string> vec_str(10);
    mystd::vector<mystd::Dog> vec_dog(10);
    mystd::vector<bool> vec_bool(10);
}
