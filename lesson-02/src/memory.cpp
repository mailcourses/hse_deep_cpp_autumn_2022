#include <iostream>

int CMemory()
{
    size_t n = 10;
    std::cout << "sizeof(int) is " << sizeof(int) << std::endl;
    int *arr = (int *)malloc(n* sizeof(int));

    for (size_t i = 0; i < n; ++i) {
        arr[i] = i;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }


    std::cout << "===========" << std::endl;
    arr = (int *)realloc(arr, 2 * n * sizeof(int));
    for (size_t i = 0; i < n; ++i) {
        arr[n+i] = i;
    }

    for (size_t i = 0; i < n * 2; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    free(arr);
    return 0;
}

int CppMemory()
{
    size_t n = 10;
    int *num = new int(10); // 1 объект
    int *arr = new int[n]; // std::bad_alloc, n объектов.
    for (size_t i = 0; i < n; ++i)
    {
        arr[i] = i;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    std::cout << "=========== sizeof(int*)" << sizeof(int *) << std::endl;
    std::cout << "=========== sizeof(char*)" << sizeof(char *) << std::endl;
    delete num;
    delete[] arr;

    return 0;
}

int main()
{
    CMemory();
    std::cout << "===== cpp =====" << std::endl;
    CppMemory();

    int *p = nullptr;
    int a = 10, b = 20;

    int &c = a;
    std::cout << "a=" << a << ", b = " << b << ", c = " << c << std::endl;
    c = 5;
    std::cout << "a=" << a << ", b = " << b << ", c = " << c << std::endl;
    c = b;
    std::cout << "a=" << a << ", b = " << b << ", c = " << c << std::endl;
    p = &a;
    *p = 35;
    std::cout << "a=" << a << ", b = " << b << ", c = " << c << std::endl;
    p = &b;
    *p = -10;
    std::cout << "a=" << a << ", b = " << b << ", c = " << c << std::endl;

    // isBST(TreeNode *root);
    // isBSTHelper(root, nullptr, nullptr)
    // bool isBSTHelper(TreeNode *root, int* pmin, int *pmax)
}
