#include <map>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <forward_list>

template<typename T>
void printer(const T& containter)
{
    // auto begin_it = containter.rbegin();
    // auto end_it = containter.rend();
    // ===
    auto begin_it = std::rbegin(containter);
    auto end_it = std::rend(containter);
    while (begin_it != end_it)
    {
        std::cout << "container value: " << *begin_it << std::endl;
        ++begin_it;
    }
}

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
private:
    T* ptr_;
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
public:
    Iterator(T* ptr) : ptr_(ptr) {}
    bool operator==(const Iterator<T>& rhs) const
    {
        return ptr_ == rhs.ptr_;
    }

    bool operator!=(const Iterator<T>& rhs) const
    {
        return !(*this == rhs);
    }

    reference operator*() const
    {
        return *ptr_;
    }

    Iterator& operator++()
    {
        ++ptr_;
        return *this;
    }
};

template<class T, size_t N>
class Array
{
private:
    T data_[N];
public:
    using iterator = Iterator<T>;
public:
    Array( std::initializer_list<T> init )
    {
        auto begin_it = init.begin();
        auto end_it = init.end();
        for(size_t i = 0; begin_it != end_it; ++i, ++begin_it)
        {
            data_[i] = *begin_it;
        }
    }

    iterator begin() noexcept
    {
        return iterator(data_);
    }

    iterator end() noexcept
    {
        return iterator(data_ + N);
    }
};

int main()
{
    /*
     * std::back_insert_iterator
     * std::front_insert_iterator
     * std::insert_iterator
     *
     * 3 вспомогательные функции
     * std::back_inserter
     * std::front_inserter
     * std::inserter
     */
    std::deque<int32_t> dq;
    dq.push_back(10);
    std::cout << "deque size: " << dq.size() << std::endl;
    std::back_insert_iterator back_instr = std::back_inserter(dq);
    for (size_t i = 0; i < 5; ++i, ++back_instr)
    {
        *back_instr = i;
    }
    std::cout << "deque size: " << dq.size() << std::endl;
    printer(dq);

    {
        std::set<std::string> hash = {"cat", "dog", "owl"};
        printer(hash);
    }

    {
        std::list<int32_t> fl = {1, 2, 3};
        auto begin_it = std::begin(fl);
        //auto end_it = std::end(fl);
        begin_it++;
        std::cout << "Second element of forward is " << *begin_it << std::endl;
        --begin_it;
        std::cout << "First element of forward is " << *begin_it << std::endl;
    }

    {
        std::vector<std::string> vec = {"Walter", "Jesse", "Mike"};
        printer(vec);
        auto begin_vec_it = std::begin(vec);
        auto next_vec_it = begin_vec_it + 2;
        --next_vec_it;
        std::cout << "Second element of vector is " << *next_vec_it << std::endl;
    }

    {
        std::map<std::string, int32_t> rb_map = { {"cat", 0}, {"dob", 1} };
        auto begin_it = std::begin(rb_map);
        for (; begin_it != std::end(rb_map); ++begin_it)
        {
            std::cout << "=======" << std::endl;
            std::cout << "RB key=" << begin_it->first << std::endl;
            std::cout << "RB value=" << begin_it->second << std::endl;
        }
    }

    {
        Array<int32_t, 5> arr = {1, 2, 3, 4, 5};
        auto begin_it = std::begin(arr);
        auto end_it = std::end(arr);
        while (begin_it != end_it)
        {
            std::cout << "arr value = " << *begin_it << std::endl;
            ++begin_it;
        }
        int32_t sum = std::accumulate(std::begin(arr), std::end(arr), 100);
        std::cout << "Sum of array elements is " << sum << std::endl;
    }

    return 0;
}
