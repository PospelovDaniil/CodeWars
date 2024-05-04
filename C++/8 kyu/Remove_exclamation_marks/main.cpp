#include <iostream>
#include <string>
#include <algorithm>

/**
 * Remove exclamation marks
 *
 * Write function RemoveExclamationMarks which removes all exclamation marks from a given string.
 */

std::string removeExclamationMarks(std::string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return c == '!'; }), str.end());
    return str;
}

int main()
{
    std::string test_str {"Hello! World!"};
    std::cout << removeExclamationMarks(test_str) << std::endl;
    return 0;
}
