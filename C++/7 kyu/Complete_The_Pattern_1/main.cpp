#include <iostream>
#include <string>

/**
 * Complete The Pattern #1
 *
 * You have to write a function pattern which returns the following Pattern(See Pattern & Examples) upto n number of rows.
 * Note:Returning the pattern is not the same as Printing the pattern.
 *
 * If n < 1 then it should return "" i.e. empty string.
 * There are no whitespaces in the pattern.
 *
 * Pattern:
 * 1
 * 22
 * 333
 * ....
 * .....
 * nnnnnn
 */

std::string pattern(int n)
{
    if (n < 1) {
        return {};
    }

    std::string res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i ; ++j) {
            res += std::to_string(i);
        }
        res += "\n";
    }

    res.pop_back();
    return res;
}

int main()
{
    std::cout << pattern(3) << std::endl;
    return 0;
}
