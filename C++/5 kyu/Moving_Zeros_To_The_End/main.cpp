#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Moving Zeros To The End
 *
 * Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.
 *
 * move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
 */


std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> res{input};

    size_t count_zero = std::count(res.begin(), res.end(), 0);
    std::remove(res.begin(), res.end(), 0);

    auto it = std::prev(res.end());
    while (count_zero > 0) {
        *it = 0;
        --it;
        --count_zero;
    }

    return res;
}

void printVec(const std::vector<int>& vec)
{
    for (int i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const std::vector original_vector{1, 0, 1, 2, 0, 1, 3};
    printVec(original_vector);
    const auto res = move_zeroes(original_vector);
    printVec(res);
    return 0;
}
