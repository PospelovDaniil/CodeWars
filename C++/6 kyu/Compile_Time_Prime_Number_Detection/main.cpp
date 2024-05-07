#include <iostream>
#include <cmath>

/**
 * Compile Time Prime Number Detection
 *
 * Your task is to determine at compile time if a given number is a prime number.
 * The easiest way to do this is to write a runtime function and declare it constexpr. Instead in tis kata you shall use proper metaprogramming and hence the use of functions is prohibited.
 * The tested numbers are all below 200 so that a implementation with O(n) instantiations should not exceed the maximal recursion limit.
 */


template <int n, int d>
struct is_prime_helper {
    static const bool value = (n % d) && is_prime_helper<n, d - 1>::value;
};

template <int n>
struct is_prime_helper<n, 1> {
    static const bool value = true;
};

template <int n>
struct is_prime_helper<n, 0> {
    static const bool value = false;
};

template <unsigned n>
struct is_prime { static const bool value = is_prime_helper<n, n - 1>::value; };

int main()
{
    std::cout << is_prime<1>::value << std::endl;
    std::cout << is_prime<5>::value << std::endl;
    return 0;
}
