
#include <iostream>

/**
 * Convert a String to a Number!
 *
 * We need a function that can transform a string into a number. What ways of achieving this do you know?
 * Note: Don't worry, all inputs will be strings, and every string is a perfectly valid representation of an integral number.
 *
 * "1234" --> 1234
 * "605"  --> 605
 * "1405" --> 1405
 * "-7" --> -7
 */

int string_to_number(const std::string& s) {
    return std::stoi(s);
}

int main()
{
    std::cout << string_to_number("1234") << std::endl;
    return 0;
}
