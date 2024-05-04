#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>

/**
 * Powers of 2
 *
 * Complete the function that takes a non-negative integer n as input,
 * and returns a list of all the powers of 2 with the exponent ranging from 0 to n ( inclusive ).
 *
 * n = 0  ==> [1]        # [2^0]
 * n = 1  ==> [1, 2]     # [2^0, 2^1]
 * n = 2  ==> [1, 2, 4]  # [2^0, 2^1, 2^2]
 */

std::vector<uint64_t> powers_of_two(int n)
{
    std::vector<uint64_t> res;

    while (n > 0) {
        res.push_back(std::pow(2, n));
        --n;
    }
    res.push_back(1);

    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    auto res = powers_of_two(3);
    for (auto el: res) {
        std::cout << el << std::endl;
    }
    return 0;
}
