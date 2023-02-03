#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <queue>

void print_arr(std::vector<int32_t> &arr)
{
    for(auto el : arr)
    {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}

std::vector<int32_t> top_k()
{
    constexpr uint32_t k = 3;
    std::vector<int32_t> res;
    std::vector<int32_t> arr = {1,2,3,4,5,6,7,8,9,10};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);

    std::cout << "before sort" << std::endl;
    print_arr( arr );

    // Работает O(nlogn)
    /*
    std::sort(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.end());
    std::cout << "after sort" << std::endl;
    print_arr( arr );
    for(size_t i = 0; i < k; ++i)
    {
        res.push_back( arr[i] );
    }
    */
    // Ускоряем до O(n log k)
    std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> pq;
    // Будем max-heap по умолчанию.
    //std::priority_queue<int32_t> pq;
    for (auto el : arr)
    {
        pq.push(el);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    std::cout << "Final result" << std::endl;
    print_arr(res);
    return res;
}

int main()
{
    std::map<int32_t, std::string> rb_tree;
    std::unordered_map<int32_t, std::string> hash_table;
    hash_table.reserve(100);

    std::vector<int32_t> arr = {1,2,3,4,5,6,7,8,9,10};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    for(auto el : arr)
    {
        rb_tree.insert({el, std::to_string(el)});
        hash_table.insert({el, std::to_string(el)});
        std::cout << el << ", ";
    }
    std::cout << std::endl;

    std::cout << "Red-Black tree" << std::endl;
    for(auto [key, value] : rb_tree)
    {
        std::cout << "key=" << key << ", value=" << value << std::endl;
    }

    std::cout << "Hash table" << std::endl;
    for(auto [key, value] : hash_table)
    {
        std::cout << "key=" << key << ", value=" << value << std::endl;
    }

    std::cout << "hash table bucket count=" << hash_table.bucket_count() << std::endl;
    std::cout << "hash table load_factor=" << hash_table.load_factor() << std::endl;

    top_k();

    return 0;
}
