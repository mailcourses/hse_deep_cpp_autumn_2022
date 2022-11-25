#include <iostream>

void foo(int a)
{
    a += 1;
    std::cout << "foo::a=" << a << std::endl;
}

void boo(int &a)
{
    a += 1;
    std::cout << "boo::a=" << a << std::endl;
}

void moo(int const * a)
{
    const int b = 1000;
    //b++;
    a = &b;
    std::cout << "moo::a=" << *a << std::endl;
}

struct TreeNode
{
};

bool isBST(TreeNode *root)
{
    if (root == nullptr)
        return true;
    // что-то делаем.
    return true;
}

// std::optional можно использовать вместо указателей.
bool checkInteger(int num, int *min, int *max)
{
    if (min != nullptr && num < *min)
    {
        return false;
    }
    if (max != nullptr && num > *max)
    {
        return false;
    }
    return true;
}

int main()
{
    int obj = 100500;
    std::cout << "before obj=" << obj << std::endl;
    foo( obj );
    std::cout << "after obj=" << obj << std::endl;
    boo( obj );
    std::cout << "after boo obj=" << obj << std::endl;
    moo( &obj );
    std::cout << "after moo obj=" << obj << std::endl;

    {
        TreeNode *root = nullptr;
        isBST(root);
        root = new TreeNode();
        isBST(root);
        delete root;
    }

    {
        std::cout << std::boolalpha;
        std::cout << "checkInteger(100) = " << checkInteger(100, nullptr, nullptr) << std::endl;
        int min = 300;
        std::cout << "checkInteger(100, 300) = " << checkInteger(100, &min, nullptr) << std::endl;
        int max = 1000;
        std::cout << "checkInteger(500, 300, 1000) = " << checkInteger(500, &min, &max) << std::endl;
    }
}
