#include <iostream>
#include <string>
#include <vector>
#include <cassert>

void split(const std::string & str, char delimiter, std::vector<std::string> &result)
{
    std::string word = "";
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if (*it == delimiter)
        {
            
            result.push_back(word);
            word.clear();
            continue;
        }
        word += *it;
    }
    result.push_back(word);
    for (auto val : result)
    {
        std::cout << val << '|';
    }
    std::cout << std::endl;
}

// str = "aa&&bb&&cc"
// delitemeter = "&&"
/*
start = 0
idx = 2
{"aa"}

start = 4
idx = 6
{"aa", "bb"}
*/

void split(const std::string & str, const std::string& delimiter, std::vector<std::string> &result)
{
    std::vector<int> positions;
    std::string word = "";
    size_t start = 0;
    size_t pos = str.find(delimiter, start);
    while (pos != std::string::npos)
    {
        auto substr = str.substr(start, pos - start);
        result.push_back( substr );
        start = pos + delimiter.size();
        pos = str.find(delimiter, start );
    }
    auto substr = str.substr(start);
    result.push_back( substr );
    /*for (auto it = str.begin(); it != str.end(); ++it)
    {
        size_t pos = str.find(delimiter);
        if (pos == std::string::npos)
        {
            break; //???
        }
        
    }*/
    for (auto val : result)
    {
        std::cout << val << '$';
    }
    std::cout << std::endl;
}

int main()
{
    {
        std::vector<std::string> res;
        split("Mama myla ramu", ' ', res);
        std::vector<std::string> correct = {"Mama", "myla", "ramu"};
        assert(res == correct);
    }
    {
        std::vector<std::string> res;
        split("Mamamylaramu", ' ', res);
        std::vector<std::string> correct = {"Mamamylaramu"};
        assert(res == correct);
    }
    
    {
        std::vector<std::string> res;
        split("Mamamylaramu", "**", res);
        std::vector<std::string> correct = {"Mamamylaramu"};
        assert(res == correct);
    }
    {
        std::vector<std::string> res;
        split("Mama**myla**ramu", "**", res);
        std::vector<std::string> correct = {"Mama", "myla", "ramu"};
        assert(res == correct);
    }
}
