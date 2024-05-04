#include <iostream>
#include <string>

/**
 * Even or Odd
 *
 * Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
 */

std::string even_or_odd(int number)
{
    return number % 2 == 0? "Even" : "Odd";
}

int main()
{
    std::cout << even_or_odd(1) << std::endl;
    return 0;
}
