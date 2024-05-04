#include <iostream>

/**
 * Count Odd Numbers below n
 *
 * Given a number n, return the number of positive odd numbers below n, EASY!
 *
 * 7  -> 3 (because odd numbers below 7 are [1, 3, 5])
 * 15 -> 7 (because odd numbers below 15 are [1, 3, 5, 7, 9, 11, 13])
 */

int test(int n)
{
//    return n % 2 == 0 ? n / 2 : ((n - 1) / 2);
    return n / 2;
}

int main()
{
    std::cout << test(0) << std::endl;
    return 0;
}
