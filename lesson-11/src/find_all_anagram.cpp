#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <iostream>


/*
 * text = "abcdbacd"
 * pattern = "cba"
 */
 
 void print(const std::map<char, int>& cont )
{
    for (auto el : cont)
        std::cout << el.first << ' ' << el.second << std::endl;
}
 
 std::map<char, int> fillMap(const std::string& str)
 {
     std::map<char, int> res;
     for(auto chr : str)
     {
         auto it = res.find(chr);
         if (it != res.end()) it->second += 1;
         else res[chr] = 1;
     }
     return res;
 }
 
std::vector<int> findAnagrams(const std::string &text, const std::string &pattern)
{
    std::vector<int> res;
    
    size_t win_size = pattern.size();
    
    if (text.size() < win_size) return {};
    if (!win_size) return {};
    
    auto stat_pattern = fillMap(pattern);
    auto cur_stat = fillMap(text.substr(0, win_size));

    if (stat_pattern == cur_stat) res.push_back(0);
    
    for (size_t i=win_size; i < text.size() ; ++i)
    {
        //std::cout << i << std::endl;
        //print(cur_stat);
        cur_stat[text[i - win_size]] -= 1;
        auto it = cur_stat.find(text[i]);
        if (it != cur_stat.end()) it->second += 1;
        else cur_stat[text[i]] = 1;
        bool isEqual = true;
        for(auto [chr, count] : stat_pattern)
        {
            auto it = cur_stat.find(chr);
            if (it == cur_stat.end()) {isEqual = false; break;}
            if (stat_pattern[chr] != it->second) {isEqual = false; break;}
        }
        if (isEqual) res.push_back(i - win_size + 1);
    }
    return res;
}



int main()
{
    std::cout << "main()" << std::endl;
    //for (auto el: findAnagrams("abcdbacd", "abc"))
    //    std::cout << el << ' ' << std::endl;
    assert( (findAnagrams("abcdbacd", "abc") == std::vector<int>{0, 4}) );
    assert( (findAnagrams("qoqooqoq", "aaa") == std::vector<int>{} ));
    assert( (findAnagrams("aaaaa", "a") == std::vector<int>{0, 1, 2, 3, 4}) );
}
