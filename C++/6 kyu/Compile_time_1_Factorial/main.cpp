
#include <iostream>

/**
 * Compile time #1 Factorial
 *
 * Write a class template that, when instantiated with parameter x, will contain the static value equals to factorial of x. All calculations should be finished at compile time.
 * Test input: non-negative integers x up to 20.
 * Your class template will be instantiated this way during tests:
 * factorial<3>::value
 *
 * Sample test cases:
 * static_assert(factorial<3>::value ==  6, "");
 * static_assert(factorial<4>::value == 24, "");
 * // and
 * Assert::That(factorial<3>::value, Equals( 6));
 * Assert::That(factorial<4>::value, Equals(24));
 *
 * Factorial of a non-negative integer n (denoted by n!) recursively defined as following (see wiki for more details if necessary):
 * 0! = 1
 * n! = n * (n - 1)!
 */

constexpr size_t fact (int n)
{
    return n > 0 ? n * fact(n - 1) : 1;
}

template <int x>
struct factorial { enum { value = fact(x) }; };

int main()
{
    std::cout << factorial<11>::value << std::endl;
    return 0;
}
