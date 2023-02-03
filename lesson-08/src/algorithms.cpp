#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

template<class T>
bool isAdjacentElements(const T& lhs, const T& rhs)
{
    return lhs + 2 == rhs;
}

/*
template<class T>
iterator my_adjacent_find(iterator it1, iterator it2, pred)
{
    while (it1 != it2)
    {
        if (pred(*it1, *(it1+1))) {
            return it1;
        }
        ++it1;
    }
    return it2
}
*/

int main()
{
    {
        using vec_value = int32_t;
        std::vector<vec_value> v = { 1, 2, 3, 5 };
        auto it = std::adjacent_find(std::begin(v), std::end(v), [](const vec_value &lhs, const vec_value &rhs)
        {
            return lhs + 2 == rhs;
        });
        if (it == std::end(v))
        {
            std::cout << "There is no adjacent elements" << std::endl;
        }
        else
        {
            std::cout << "Element is " << *it << std::endl;
        }
    }

    {
        std::vector<std::string> v = {"dog", "cat", "1234"};
        std::cout << all_of(std::begin(v), std::begin(v) + 2, [](const std::string &str) {
            for(char ch : str)
            {
                if (ch < 'a' || ch > 'z')
                    return false;
            }
            return true;
        }) << std::endl;
        std::cout << any_of(std::begin(v), std::end(v), [](const std::string &str) {
            for(char ch : str)
            {
                if (ch < '0' || ch > '9')
                    return false;
            }
            return true;
        }) << std::endl;
        std::cout << none_of(std::begin(v), std::end(v), [](const std::string &str) {
            for(char ch : str)
            {
                if (ch < 'A' || ch > 'Z')
                    return false;
            }
            return true;
        }) << std::endl;
    }

    {
        std::cout << "count, count_if, equal" << std::endl;
        std::vector<int32_t> v = {1,2,3,4,5,6,7,4};
        std::cout << std::count(std::begin(v), std::end(v), 4) << std::endl;
        std::cout << std::count_if(std::begin(v), std::end(v), [](int32_t rhs){
            return rhs % 2 == 0;
        }) << std::endl;
        std::vector<std::string> words1 = {"Lazy", "lion", "eats", "bool"};
        std::vector<std::string> words2 = {"Lazy", "lion", "eats", "meets"};
        std::cout << std::equal(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2), [](const std::string& s1, const std::string& s2){
            return s1 == s2;
        }) << std::endl;
    }

    {
        std::string str = "Hello Kitty!";
        std::cout << "string before for_each is " << str << std::endl;
        std::for_each(std::begin(str), std::end(str), [](char &ch) {
            ch = std::tolower(ch);
        });
        std::cout << "string after for_each is " << str << std::endl;
    }

    {
        std::string str1 = "Hello world";
        std::string str2 = "lo wo";
        auto it = std::search(std::begin(str1), std::end(str1), std::begin(str2), std::end(str2));
        if (it == str1.end()) {
            std::cout << "Not found" << std::endl;
        } else {
            //int size = std::distance(std::begin(str1), it);
            std::cout << "Found subsequence from " << std::distance(std::begin(str1), it) << std::endl;
        }
    }

    {
        std::vector<int> data;
        auto iter = std::back_inserter(data);

        std::random_device rd;
        std::mt19937 gen(rd());

        std::generate_n(iter, 10, gen);

        std::copy(data.begin(), data.end(),
        std::ostream_iterator<int>(std::cout, " "));
    }


}
