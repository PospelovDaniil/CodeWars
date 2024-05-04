#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

/**
 * The Vowel Code
 *
 * Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:
 * a -> 1
 * e -> 2
 * i -> 3
 * o -> 4
 * u -> 5
 *
 * For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.
 *
 * Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.
 * For example, decode("h3 th2r2") would return "hi there".
 * For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.
 */

static const std::unordered_map<char, int> encoder_map {{'a', 1},
                                                        {'e', 2},
                                                        {'i', 3},
                                                        {'o', 4},
                                                        {'u', 5}};

static const std::unordered_map<int, char> decoder_map {{'1', 'a'},
                                                        {'2', 'e'},
                                                        {'3', 'i'},
                                                        {'4', 'o'},
                                                        {'5', 'u'}};

std::string encode(const std::string &str) {
    std::string res {str};

    std::transform(res.begin(), res.end(), res.begin(), [](char c) {
        const auto it = encoder_map.find(c);
        return it != encoder_map.cend() ? std::to_string(it->second)[0] : c;
    });

    return res;
}

std::string decode(const std::string &str) {
    std::string res {str};

    std::transform(res.begin(), res.end(), res.begin(), [](char c) {
        if (!std::isdigit(c)) {
            return c;
        }

        const auto it = decoder_map.find(c);
        return it != decoder_map.cend() ? it->second : c;
    });

    return res;
}

int main()
{
    const std::string test_str{"hello"};
    const std::string encoded_str {encode(test_str)};

    std::cout << test_str << std::endl;
    std::cout << encoded_str << std::endl;
    std::cout << decode(encoded_str) << std::endl;

    return 0;
}
