#include <string>
#include <map>
#include <cassert>

void fillMap(const std::string & s, std::map<char, size_t>& charCounts)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        auto it = charCounts.find(s[i]);
        if (it != charCounts.end())
        {
            it->second += 1;
        } 
        else
        {
            charCounts[s[i]] = 1;
        }
    }
}

bool is_anagram(const std::string & s1, const std::string &s2) {
        std::map<char, size_t> charCounts1;
        std::map<char, size_t> charCounts2;
        
        fillMap(s1, charCounts1);
        fillMap(s2, charCounts2);
        
        
        return charCounts1 == charCounts2;
}

int main()
{
    assert(is_anagram(std::string("abc"), std::string("cab")));
    assert(is_anagram(std::string("cat"), std::string("act")));
    
    assert(!is_anagram(std::string("cat"), std::string("cttt")));
    assert(!is_anagram(std::string("abca"), std::string("cab")));
}
