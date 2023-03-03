#include <vector>
#include <string>
#include <cassert>
#include <array>
#include <algorithm>
#include <iostream>

/*
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
● состоять из символов таблицы ASCII с кодами от 33 до 126;
● быть не короче 8 символов и не длиннее 14;
● из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы
— в пароле должны присутствовать не менее трёх любых.
● Напишите программу, которая проверит, что введённый пароль подходит под эти
ограничения.
*/

const size_t MIN_GROUP = 3;

enum class Groups
{
    UPPER_LETTERS = 0,
    LOWER_LETTERS = 1,
    DIGITS = 2,
    OTHERS = 3,
    COUNT = 4
};

bool is_valid_password( const std::string & password )
{
    constexpr size_t max_size = static_cast<size_t>(Groups::COUNT);
    std::array<int, max_size> res;

    //check length
    if (password.size() < 8 || password.size() > 14)
    {
        return false;
    }

    for (size_t i = 0; i < password.size(); ++i)
    {
        if (password[i] < 33 || password[i] > 126)
        {
            return false;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            res[static_cast<size_t>(Groups::UPPER_LETTERS)]++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            res[static_cast<size_t>(Groups::LOWER_LETTERS)]++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            res[static_cast<size_t>(Groups::DIGITS)]++;
        }
        else
        {
            res[static_cast<size_t>(Groups::OTHERS)]++;
        }
    }

    int counter = std::count_if(std::begin(res), std::end(res), [](int elem) {
        return elem > 0;
    });
    std::cout << "counter=" << counter << std::endl;
    return counter >= MIN_GROUP;
}

int main()
{
    const std::vector<std::string> invalid_passwords = {
        "qwerty", "123456", "Ab1#"
    };

    for (auto password : invalid_passwords)
    {
        assert( !is_valid_password( password ) );
    }

    const std::vector<std::string> valid_passwords = {
        "qwerty123A", "1236Abcdefg", "Ab1esdfe345"
    };

    for (auto password : valid_passwords)
    {
        std::cout << "password=" << password << std::endl;
        assert( is_valid_password( password ) );
    }

    return 0;
}
