#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

/**
 * String incrementer
 *
 * Your job is to write a function which increments a string, to create a new string.
 *
 * If the string already ends with a number, the number should be incremented by 1.
 * If the string does not end with a number. the number 1 should be appended to the new string.
 *
 * foo -> foo1
 * foobar23 -> foobar24
 * foo0042 -> foo0043
 * foo9 -> foo10
 * foo099 -> foo100
 * Attention: If the number has leading zeros the amount of digits should be considered.
 */

std::string incrementString(const std::string &str)
{
    if (str.empty()) {
        return "1";
    }

    std::string res {str};

    auto it_last_simbol = std::prev(res.end());
    if (!std::isdigit(*it_last_simbol)) {
        res += "1";
        return res;
    }

    const int last_digit = *it_last_simbol - '0';
    if (last_digit < 9) {
        ++(*it_last_simbol);
        return res;
    }


    // ну и позорище тут написал
    std::regex regex_last_num {R"(([\d]+)$)"};
    auto regex_match = std::sregex_iterator(res.begin(), res.end(), regex_last_num);
    std::string str_last_digit = regex_match->str();
    std::string new_str_last_digit = std::to_string(std::stoll(str_last_digit) + 1);


    size_t count_zero {0};
    for (char c: str_last_digit) {
        if (c == '0') {
            ++count_zero;
        }
        else {
            break;
        }
    }

    res.erase(res.length() - str_last_digit.length());
    const bool is_need_erase_more_zero = str_last_digit.length() != new_str_last_digit.length() &&
                                         std::isdigit(res[res.length() - str_last_digit.length() - 1]);

    if (is_need_erase_more_zero) {
        res.erase(res.length() - 1);
    }

    if (count_zero > 1) {
        for (size_t i = 0; i < count_zero - 1; --i) {
            res += "0";
        }
    }
    res += new_str_last_digit;
    return res;
}

int main()
{
    std::cout << incrementString("foo") << std::endl;
    std::cout << incrementString("") << std::endl;
    std::cout << incrementString("foobar23") << std::endl;
    std::cout << incrementString("foo9") << std::endl;
    std::cout << incrementString("foo99") << std::endl;
    std::cout << incrementString("foo099") << std::endl;
    std::cout << incrementString("foobar999") << std::endl;

    return 0;
}
