#include <forward_list>
#include <iostream>
#include <cassert>


std::forward_list<int32_t> mergeTwoLists(std::forward_list<int32_t> list1, std::forward_list<int32_t> list2)
{
    //
    std::forward_list<int32_t> result;

    auto it1 = list1.begin();
    auto it2 = list2.begin();

    while (it1 != list1.end() || it2 != list2.end())
    {
        if (it1 == list1.end())
        {
            result.push_front(*(it2++));
            continue;
        }

        if (it2 == list2.end())
        {
            result.push_front(*(it1++));
            continue;
        }

        if (*it1 < *it2)
        {
            result.push_front(*it1);
            ++it1;
        }
        else
        {
            result.push_front(*it2);
            ++it2;
        }
    }
    result.reverse();
    return result;
}

int main()
{
    // Написать тесты
    assert(mergeTwoLists({1, 3, 5}, {2, 4}) == std::forward_list<int32_t>({1, 2, 3, 4, 5}));
}
