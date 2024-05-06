#include <iostream>
#include <string>
#include <algorithm>

/**
 * Replace With Alphabet Position
 *
 * Welcome.
 *
 * In this kata you are required to, given a string, replace every letter with its position in the alphabet.
 * If anything in the text isn't a letter, ignore it and don't return it.
 * "a" = 1, "b" = 2, etc.
 *
 * alphabet_position("The sunset sets at twelve o' clock.") =>
 * Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )
 */

std::string alphabet_position(const std::string &text) {
    std::string original_text_lower(text);
    std::transform(original_text_lower.begin(), original_text_lower.end(), original_text_lower.begin(), ::tolower);

    std::string res;

    for (const char c: original_text_lower) {
        if (c >= 'a' && c <= 'z') {
            res += std::to_string(c - 'a' + 1) + " ";
        }
    }

    if (!res.empty()) {
        res.erase(res.end() - 1, res.end());
    }
    return res;
}

int main()
{
    std::cout << alphabet_position("The sunset sets at twelve o' clock.") << std::endl;
    return 0;
}
