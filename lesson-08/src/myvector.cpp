#include <iostream>
#include <vector>

int main()
{
    {
        std::vector<int32_t> v1;
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
    }
    {
        std::vector<int32_t> v1;
        v1.reserve(5);
        std::cout << "0) v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
        for (size_t i = 0; i < 6; ++i)
        {
            v1.push_back(i);
            std::cout << (i+1) << ") v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
        }
    }

    {
        std::vector<int32_t> v1 = {1, 2, 3, 4, 5};
        std::vector<std::pair<std::string, int32_t>> v2 = { {"Walter", 52}, {"Jesse", 25} };
        // std::vector<std::pair<std::string, int32_t>> v2;
        // v2.push_back(std::make_pair("Walter", 52));
        // v2.push_back(std::make_pair("Jesse", 25));
        auto [name, age] = v2[0];
        // auto name = v2[0].first;
        // auto age = v2[0].second;
        std::cout << "name=" << name << ", age=" << age << std::endl;
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
    }

    {
        constexpr size_t row = 10;
        constexpr size_t col = 20;
        std::vector<std::vector<double>> v1(row, std::vector<double>(col, -1));
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
    }
    {
        std::cout << "Example #N. Clear" << std::endl;
        std::vector<int32_t> v1(1000);
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
        v1.clear();
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
        v1 = {1,2,3,4,5};
        v1.shrink_to_fit();
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
    }
    {
        std::cout << "Example #N. Swap" << std::endl;
        std::vector<int32_t> v1(1000);
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
        std::vector<int32_t>().swap(v1);
        std::cout << "v1.size=" << v1.size() << ", v1.capacity=" << v1.capacity() << std::endl;
    }
}
/*
 * 0) v1.size=0, v1.capacity=5
 * [ | | | | ]
 * 1) v1.size=1, v1.capacity=5
 * [0| | | | ]
 * 2) v1.size=2, v1.capacity=5
 * [0|1| | | ]
 * 3) v1.size=3, v1.capacity=5
 * [0|1|2| | ]
 * 4) v1.size=4, v1.capacity=5
 * [0|1|2|3| ]
 * 5) v1.size=5, v1.capacity=5
 * [0|1|2|3|4]
 * 6) v1.size=6, v1.capacity=10
 * [ | | | | | | | | | ]
 * [0|1|2|3|4| | | | | ]
 * [0|1|2|3|4|5| | | | ]
 */
