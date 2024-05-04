#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>


/**
 * Sum without highest and lowest number
 *
 * Sum all the numbers of a given array ( cq. list ), except the highest and the lowest element ( by value, not by index! ).
 * The highest or lowest element respectively is a single element at each edge, even if there are more than one with the same value.
 * Mind the input validation.
 *
 * If an empty value ( null, None, Nothing etc. ) is given instead of an array, or the given array is an empty list or a list with only 1 element, return 0.
 *
 * { 6, 2, 1, 8, 10 } => 16
 * { 1, 1, 11, 2, 3 } => 6
 */

int sum(std::vector<int> numbers)
{
    if (numbers.size() < 2) {
        return 0;
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    const std::pair min_max = std::minmax_element(numbers.begin(), numbers.end());
    sum -= *min_max.first + *min_max.second;

    return sum;
}

int main()
{
    std::cout << sum({6, 2, 1, 8, 10}) << std::endl;
    return 0;
}
