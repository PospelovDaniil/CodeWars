#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
}

inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), s.end());
}

inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

// MORSE_CODE exists somewhere outside, its map<string, string>

std::string decodeMorse(const std::string& morseCode) {
    std::string decoded;
    std::string morse_word;

    for (auto it = morseCode.begin(); it != morseCode.end(); ++it) {
        if (*it != ' ') {
            morse_word += *it;

            const auto it_next_char = std::next(it);
            if (*it_next_char == ' ' || it_next_char == morseCode.end()) {
                decoded += MORSE_CODE[morse_word];
                morse_word.clear();
            }
        }

        const auto it_next = std::next(it);
        const auto it_next_next = std::next(it_next);

        if (it_next != morseCode.end() || it_next_next != morseCode.end()) {
            if (*it == ' ' && *it_next == ' ' && *it_next_next == ' ') {
                decoded += " ";
                continue;
            }
        }
    }

    trim(decoded);
    return decoded;
}

int main()
{
    std::cout << decodeMorse(".... . -.--   .--- ..- -.. .") << std::endl; // "HEY JUDE"
    std::cout << decodeMorse("   .   . ") << std::endl; // "E E"
    return 0;
}
