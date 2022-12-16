#include <iostream>
#include <vector>

struct T
{
    T()
    {
        std::cout << "Ctor T()" << std::endl;
    }
    ~T()
    {
        std::cout << "Dtor T()" << std::endl;
    }
};

class shared_ptr
{
    struct wrapper
    {
        T *raw_data;
        int32_t counter = 0;
        //~wrapper() {}
    };
public:
    shared_ptr() = default;
    shared_ptr(T *ptr)
    {
        data_ = new wrapper;
        data_->raw_data = ptr;
        data_->counter += 1;
    }
    // Конструктор копирования.
    shared_ptr(const shared_ptr &rhs)
    {
        data_ = rhs.data_;
        if (data_)
        {
            data_->counter += 1;
            std::cout << "Copy Ctor::counter=" << data_->counter << std::endl;
        }
    }

    // Конструктор перемещения.
    shared_ptr(shared_ptr &&rhs)
    {
        std::cout << "Move Ctor shared_ptr" << std::endl;
        data_ = rhs.data_;
        rhs.data_ = nullptr;
    }

    // Оператор копирования.
    shared_ptr& operator=(const shared_ptr &rhs)
    {
        if ( this == &rhs )
        {
            return *this;
        }

        destroy();

        data_ = rhs.data_;
        if (data_)
        {
            data_->counter += 1;
            std::cout << "Copy Operator Ctor::counter=" << data_->counter << std::endl;
        }
        return *this;
    }

    shared_ptr& operator=(shared_ptr &&rhs)
    {
        std::cout << "Move Operator shared_ptr" << std::endl;
        if ( this == &rhs )
        {
            return *this;
        }
        destroy();
        data_ = rhs.data_;
        rhs.data_ = nullptr;
        return *this;
    }

    ~shared_ptr()
    {
        std::cout << "Dtor shared_ptr" << std::endl;
        destroy();
    }

    void destroy()
    {
        if (data_ && data_->raw_data)
        {
            data_->counter -= 1;
            if (data_->counter == 0)
            {
                delete data_->raw_data;
                delete data_;
            }
        }
    }
private:
    wrapper *data_ = nullptr;
};

class A
{
public:
    A() { ptr = new int32_t; }
    ~A() { delete ptr; }
    /*
     *  a2 = a1;
     *  A& operator=(const A& rhs)
     *  {
     *      ptr = rhs.ptr;
     *      s = rhs.s;
     *  }
    */
public:
    int32_t *ptr;
    std::string s;
};

int main()
{
    {
        shared_ptr p1(new T);
        {
            shared_ptr p2 = p1;
        }
        shared_ptr p3(new T);
        //ptr[i] = p3; ptr[i] == p3 -> p3 = p3;
        p3 = p1;
        p3 = p3;

        shared_ptr p4 = std::move(p1);
        shared_ptr p5(new T);
        p5 = std::move(p4);
    }

    std::vector<int32_t> v1(1000, 0);
    std::vector<int32_t> v2;
    std::cout << "v1.size()=" << v1.size() << ", v2.size()=" << v2.size() << std::endl;
    v2 = std::move(v1);
    std::cout << "v1.size()=" << v1.size() << ", v2.size()=" << v2.size() << std::endl;

    A a1;
    A a2;
    a2 = a1;
    return 0;
}
