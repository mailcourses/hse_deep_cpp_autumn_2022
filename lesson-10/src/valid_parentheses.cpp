#include <string>
#include <cassert>
#include <stack>
#include <unordered_map>

// Проверяем, что '(' и ')'
bool is_valid_parentheses(const std::string & str)
{
    size_t stack = 0;
    for (auto chr: str)
    {
        if (chr == '(') ++stack;
        else
        {
            if (stack > 0) --stack;
            else return false;
        }
    }
    return stack == 0;
}

const std::unordered_map<char, char> parenthese_matching = {{'}', '{'}, {']', '['}, {')', '('}};

bool is_open_parenthese(char symbol)
{
    //return symbol == '(' || symbol == '{' || symbol == '[';
    return parenthese_matching.find(symbol) == parenthese_matching.end();
}

bool is_valid_multiparentheses(const std::string & str)
{
    /*enum parentheses_type
    {
        CIRCLE = 0,
        CURVE = 1,
        QUBIC = 2
    };

    std::stack<parentheses_type> st;
    */
    std::stack<char> st;
    for(auto chr: str)
    {
        /*parentheses_type type;
        if (chr == '(' || chr == ')') type = CIRCLE;
        else if (chr == '[' || chr == ']') type = QUBIC;
        else type = CURVE;

        if (is_open_parenthese(chr)) st.push(type);
        else
        {
            if (st.empty()) return false;
            parentheses_type last = st.top();
            st.pop();
            if (last != type) return false;
        }*/
        if (is_open_parenthese(chr)) st.push(chr);
        else
        {
            if (st.empty()) return false;

            char open_paranthese = parenthese_matching.at(chr);
            char top = st.top(); st.pop();
            if (top != open_paranthese) return false;
        }
    }
    return st.empty();
}

int main()
{
    // Надо написать проверки.
    assert(is_valid_parentheses("()()()"));
    assert(is_valid_parentheses("((()))"));
    assert(is_valid_parentheses("(()())"));
    assert(!is_valid_parentheses("((())"));
    assert(!is_valid_parentheses(")()"));
    assert(!is_valid_parentheses(")()("));
    assert(is_valid_parentheses(""));

    assert(is_valid_multiparentheses("[](){}"));
    assert(is_valid_multiparentheses("([{}])"));
    assert(is_valid_multiparentheses("[{}()]"));
    assert(!is_valid_multiparentheses("[]({}"));
    assert(!is_valid_multiparentheses("{([)]}"));
    assert(is_valid_multiparentheses(""));
}
