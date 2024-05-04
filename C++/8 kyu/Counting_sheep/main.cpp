#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Counting sheep...
 *
 * Consider an array/list of sheep where some sheep may be missing from their place.
 * We need a function that counts the number of sheep present in the array (true means present).
 *
 * [true,  true,  true,  false,
 *  true,  true,  true,  true ,
 *  true,  false, true,  false,
 *  true,  false, false, true ,
 *  true,  true,  true,  true ,
 *  false, false, true,  true] => 17
 */

int count_sheep(std::vector<bool> arr)
{
    return std::count(arr.begin(), arr.end(), true);
}

int main()
{
    std::cout << count_sheep({true,  true,  true,  false,
                              true,  true,  true,  true ,
                              true,  false, true,  false,
                              true,  false, false, true ,
                              true,  true,  true,  true ,
                              false, false, true,  true}) << std::endl;
    return 0;
}
