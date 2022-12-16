#include <iostream>
#include <memory>

void init_foo( char * /*str*/ )
{
    // что-то делаем.
}

void free_foo( char *str )
{
    delete[] str;
}

/*
template<class T>
class auto_ptr
{
public:
    auto_ptr(char *data) { data_ = data; }
    ~auto_ptr() { delete data_; }
private:
    T* data_;
};
*/

int main()
{
    // std::auto_ptr is deprecated
    { /*
        char *ch_ptr = new char;
        *ch_ptr = 'z';
        std::auto_ptr<char> ptr(ch_ptr);
        std::cout << "ptr=" << *ptr << std::endl;
        std::auto_ptr<char> ptr1(new char);
        // ...
        std::auto_ptr<char> ptr3 = ptr;
        std::cout << "ptr3=" << *ptr3 << std::endl;
        // Будет Segmentation fault
        //std::cout << "ptr=" << *ptr << std::endl;
      */
    }

    {
        // Начиная с C++17
        std::shared_ptr<char[]> ptr1(new char[20]);
        // До C++17
        std::shared_ptr<char> ptr2(new char[20], std::default_delete<char[]>());
    }

    // у ch_ptr память уже оcвобождена.
    //init_foo( str );
    {
        std::shared_ptr<int> ptr1(new int);
        *ptr1 = 100500;
        {
            std::shared_ptr<int> ptr2 = ptr1;
            std::cout << "shared ptr1 = " <<  *ptr1 << std::endl;
            std::cout << "shared ptr2 = " <<  *ptr2 << std::endl;
        }
        std::cout << "shared ptr1 after = " <<  *ptr1 << std::endl;
    }

    {
        std::unique_ptr<int> ptr1(new int(100500));
        ptr1.reset(new int(500100));
        {
            std::unique_ptr<int> ptr2 = std::move(ptr1);
            std::cout << "unique ptr2 = " << *ptr2 << std::endl;
            ptr2.release();
            // Будет Ошибка сегментирования.
            //std::cout << "unique ptr1 = " <<  *ptr1 << std::endl;
        }
    }
}




