#include <iostream>

namespace mystd
{

struct Dog
{
    using iterator = int32_t;
    static const bool tosh = false;
};


template<typename T>
class vector
{
public:
    vector()
    {
        std::cout << "vector<T>" << std::endl;
    }
    vector(size_t size);
    ~vector();
private:
    /*
    Dog::iterator
    Dog::tosh
    */
    typename T::iterator it;

    size_t size_ = 0;
    size_t capacity_ = 0;
    T *data_ = nullptr;
};

template<>
class vector<bool>
{
public:
    vector()
    {
        std::cout << "vector<bool>" << std::endl;
    }
    vector(size_t /*size*/)
    {
        std::cout << "vector<bool>" << std::endl;
    }
    ~vector(){}
};

} // namespace mystd

#include "vector.tpp"
