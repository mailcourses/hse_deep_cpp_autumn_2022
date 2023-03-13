#include <string>
#include <map>
#include <cassert>
#include <iostream>


/*
abcdabdefa

abcabd

bcaabd
*/
size_t lengthOfLongestSubstring(const std::string& str)
{
    if (str.size() == 0) return 0;
    size_t result = 1;
    std::map<char, size_t> unique;
    size_t l = 0, r = 1;
    unique.insert({str[0], 0});
    while (r < str.size())
    {
        auto it = unique.find(str[r]);
        if (it != unique.end() && it->second >= l)
        {
            result = std::max(result, r - l);
            l = unique[str[r]] + 1;
        }
        unique[str[r]] = r;

        ++r;
    }
    
    result = std::max(result, r - l);
    return result;
}

int main()
{
    assert(lengthOfLongestSubstring("abcdabdefa") == 5);
    assert(lengthOfLongestSubstring("abcabd") == 4);
    assert(lengthOfLongestSubstring("bcaabd") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring("aaaaaa") == 1);
    assert(lengthOfLongestSubstring("abcdef") == 6);

    
    return 0;
}
