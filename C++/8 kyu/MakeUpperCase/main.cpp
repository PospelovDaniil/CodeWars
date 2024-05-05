#include <iostream>
#include <string>
#include <algorithm>

/**
 * MakeUpperCase
 *
 * Write a function which converts the input string to uppercase.
 */


std::string makeUpperCase (const std::string& str)
{
    std::string res{str};
    std::transform(res.begin(), res.end(), res.begin(), ::toupper);
    return res;
}

int main()
{
    std::cout << makeUpperCase("Hello World!") << std::endl;
    return 0;
}
