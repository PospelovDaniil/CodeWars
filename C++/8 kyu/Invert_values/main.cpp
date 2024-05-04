#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Invert values
 *
 * Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives.
 *
 * invert([1,2,3,4,5]) == [-1,-2,-3,-4,-5]
 * invert([1,-2,3,-4,5]) == [-1,2,-3,4,-5]
 * invert([]) == []
 */

std::vector<int> invert(std::vector<int> values)
{
    std::transform(values.begin(), values.end(), values.begin(), [](int i){ return i * -1; });
    return values;
}

int main()
{
    const auto res = invert({-1,-2,-3,-4,-5});
    for (auto el: res) {
        std::cout << el << std::endl;
    }
    return 0;
}
