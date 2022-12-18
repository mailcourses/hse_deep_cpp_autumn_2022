#include <string>
#include <iostream>

template <class T>
class Matrix
{
    T* data_;
public:
    Matrix() {}
    ~Matrix() {}
    void foo() {}
};

/*
 * class Matrix
 * {
 *   int *data_;
 *   ...
 * };
 *
 * class Matrix
 * {
 *   double *data_;
 * }
 */

template<typename T, size_t Size>
struct Array
{
    T data[Size];
    Array()
    {
        //5 += 1;
        std::cout << "Template Size: " << Size << std::endl;
    }
};

template <float N> // Ошибка
void foo()
{
    std::cout << N << std::endl;
}

int main()
{
    Matrix<double> m1;
    Matrix<int> m2;
    Matrix<std::string> m3;
    m1.foo();
    m2.foo();
    m3.foo();

    const size_t n = 5;
    //std::cin >> n;
    Array<int32_t, n> array;
    const float c = static_cast<float>(3);
    foo<c>();
}
