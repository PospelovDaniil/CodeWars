
#include <iostream>

/**
 * Convert a Number to a String!
 *
 * We need a function that can transform a number (integer) into a string.
 * What ways of achieving this do you know?
 *
 * 123  --> "123"
 * 999  --> "999"
 * -100 --> "-100"
 */

std::string number_to_string(int num) {
    return std::to_string(num);
}

int main()
{
    std::cout << number_to_string(123) << std::endl;
    return 0;
}
