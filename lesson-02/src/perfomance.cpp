#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main()
{
    std::vector<int> arr1;
    std::list<int> arr2;
    for (size_t i = 0; i < 1000000; ++i)
    {
        arr1.push_back(i);
        arr2.push_back(i);
    }


    int sum1 = 0;
    int sum2 = 0;
    // start_ts =
    for (size_t i = 0; i < arr1.size(); ++i)
    {
        sum1 += arr1[i];
    }
    // end_ts =

    // start_ts =
    auto end = arr2.end();
    for(auto it = arr2.begin(); it != end; ++it)
    {
        sum2 += *it;
    }
    // end_ts =



    return 0;
}
