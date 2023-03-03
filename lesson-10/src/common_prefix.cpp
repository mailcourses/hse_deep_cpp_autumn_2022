#include <string>
#include <vector>
#include <cassert>
#include <limits>

std::string common_prefix(const std::vector<std::string>& words)
{
    if (words.empty()) {
        return std::string("");
    }

    std::string result_string = "";

    // find min
    size_t min_size = std::numeric_limits<size_t>::max();

    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i].size() < min_size) {
            min_size = words[i].size();
        }
    }

    for (size_t i = 0; i < min_size; ++i) {
        char label = words[0][i];
        for (size_t j = 1; j < words.size(); ++j) {
            if (words[j][i] != label) {
                return result_string;
            }
        }

        result_string.push_back(label);
    }
    return result_string;
}

/*  |
*   apple
    appricas
    asdpsap
*/

int main()
{
    {
        const std::vector<std::string> words = {"apple", "appriciate", "appstore", "application"};
        std::string prefix = common_prefix( words );
        assert( prefix == std::string("app") );
    }

    {
        const std::vector<std::string> words = {"apple", "xiaomi", "kickstarter"};
        std::string prefix = common_prefix( words );
        assert( prefix == std::string() );
    }

    {
        const std::vector<std::string> words = {};
        std::string prefix = common_prefix( words );
        assert( prefix == std::string() );
    }
    return 0;
}
