#include <string>
#include <iostream>
#include <algorithm>

/**
 * All Star Code Challenge #18
 *
 * Create a function that accepts a string and a single character, and returns
 * an integer of the count of occurrences the 2nd argument is found in the first one.
 * If no occurrences can be found, a count of 0 should be returned.
 *
 * ("Hello", "o")  ==>  1
 * ("Hello", "l")  ==>  2
 * ("", "z")       ==>  0
 */

unsigned int strCount(const std::string& word, char letter){
    return std::count(word.begin(), word.end(), letter);
}

int main()
{
    std::cout << strCount("Hello", 'o') << std::endl;
    return 0;
}
