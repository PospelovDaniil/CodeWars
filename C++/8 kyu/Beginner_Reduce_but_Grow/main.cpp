#include <iostream>
#include <vector>
#include <numeric>

/**
 * Beginner - Reduce but Grow
 *
 * Given a non-empty array of integers, return the result of multiplying the values together in order. Example:
 *
 * [1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24
 */

int grow(std::vector<int> nums) {
    return std::accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
}

int main()
{
    std::cout << grow({1, 2, 3, 4}) << std::endl;
    return 0;
}
