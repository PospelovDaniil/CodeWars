#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <optional>

/**
 * 1-800-CODE-WAR
 *
 * 1-800 number format
 * This format probably varies for different countries, but for the purpose of this Kata here are my rules:
 *
 * A 1-800 number is an 11 digit phone number which starts with a 1-800 prefix.
 * The remaining 7 digits can be written as a combination of 3 or 4 letter words. e.g.
 *
 * 1-800-CODE-WAR
 * 1-800-NEW-KATA
 * 1-800-GOOD-JOB
 * The - are included just to improve the readability.
 *
 * Story
 * A local company has decided they want to reserve a 1-800 number to help with advertising.
 * They have already chosen what words they want to use, but they are worried that maybe that same phone number
 * could spell out other words as well. Maybe bad words. Maybe embarrassing words.
 * They need somebody to check for them so they can avoid any accidental PR scandals!
 * That's where you come in...
 *
 * Kata Task
 * There is a preloaded array of lots of 3 and 4 letter (upper-case) words:
 * For C++ it is preloaded::words
 * Given the 1-800 (phone word) number that the company wants to use, you need to check against all known words
 * and return the set of all possible 1-800 numbers which can be formed using those same digits.
 *
 * Notes
 * The desired phone-word number provided by the company is formatted properly. No need to check.
 * All the letters are upper-case. No need to check.
 * Only words in the list are allowed.
 */

// const std::string [573]
extern const std::string preloaded::words[];

template<typename T, unsigned int sz>
inline unsigned int lengthof(T (&)[sz]) { return sz; }

std::optional<std::vector<char>> toAlphabet(const int i)
{
    switch (i)
    {
    case 2: { return std::make_optional(std::vector{'A', 'B', 'C'}); }
    case 3: { return std::make_optional(std::vector{'D', 'E', 'F'}); }
    case 4: { return std::make_optional(std::vector{'G', 'H', 'I'}); }
    case 5: { return std::make_optional(std::vector{'J', 'K', 'L'}); }
    case 6: { return std::make_optional(std::vector{'M', 'N', 'O'}); }
    case 7: { return std::make_optional(std::vector{'P', 'Q', 'R', 'S'}); }
    case 8: { return std::make_optional(std::vector{'T', 'U', 'V'}); }
    case 9: { return std::make_optional(std::vector{'W', 'X', 'Y', 'Z'}); }
    default: { return {}; }
    }
}

std::optional<int> toNumber(const char c)
{
    switch (c)
    {
    case 'A':
    case 'B':
    case 'C': return std::make_optional(2);
    case 'D':
    case 'E':
    case 'F': return std::make_optional(3);
    case 'G':
    case 'H':
    case 'I': return std::make_optional(4);
    case 'J':
    case 'K':
    case 'L': return std::make_optional(5);
    case 'M':
    case 'N':
    case 'O': return std::make_optional(6);
    case 'P':
    case 'Q':
    case 'R':
    case 'S': return std::make_optional(7);
    case 'T':
    case 'U':
    case 'V': return std::make_optional(8);
    case 'W':
    case 'X':
    case 'Y':
    case 'Z': return std::make_optional(9);
    default: { return {}; }
    }
}

std::set<std::string> loadSetStrings()
{
    std::set<std::string> preloaded_words;
    for (size_t i = 0; i < lengthof(preloaded::words); ++i) {
        preloaded_words.insert(preloaded::words[i]);
    }
    return preloaded_words;
}

std::string decodeWordToNumber(const std::string &s)
{
    std::string res;

    for (const char c: s) {
        const auto opt_number = toNumber(c);
        if (opt_number) {
            res += std::to_string(*opt_number);
        }
        else {
            res += c;
        }
    }

    return res;
}

std::set<std::string> makeSymbolCombinations(const std::string &str_number)
{
    std::vector<std::string> buff;

    if (str_number.length() == 3) {
        const auto opt_part_1 = toAlphabet(str_number[0] - '0');
        const auto opt_part_2 = toAlphabet(str_number[1] - '0');
        const auto opt_part_3 = toAlphabet(str_number[2] - '0');

        if (opt_part_1 && opt_part_2 && opt_part_3) {
            for (const char keyboard_symbol_1: *opt_part_1) {
                for (const char keyboard_symbol_2: *opt_part_2) {
                    for (const char keyboard_symbol_3: *opt_part_3) {
                        std::string new_combo{keyboard_symbol_1};
                        new_combo += keyboard_symbol_2;
                        new_combo += keyboard_symbol_3;
                        buff.push_back(new_combo);
                    }
                }
            }
        }
    }
    else if (str_number.length() == 4) {
        const auto opt_part_1 = toAlphabet(str_number[0] - '0');
        const auto opt_part_2 = toAlphabet(str_number[1] - '0');
        const auto opt_part_3 = toAlphabet(str_number[2] - '0');
        const auto opt_part_4 = toAlphabet(str_number[3] - '0');

        if (opt_part_1 && opt_part_2 && opt_part_3 && opt_part_4) {
            for (const char keyboard_symbol_1: *opt_part_1) {
                for (const char keyboard_symbol_2: *opt_part_2) {
                    for (const char keyboard_symbol_3: *opt_part_3) {
                        for (const char keyboard_symbol_4: *opt_part_4) {
                            std::string new_combo{keyboard_symbol_1};
                            new_combo += keyboard_symbol_2;
                            new_combo += keyboard_symbol_3;
                            new_combo += keyboard_symbol_4;
                            buff.push_back(new_combo);
                        }
                    }
                }
            }
        }
    }


    std::set<std::string> res{buff.begin(), buff.end()};
    return res;
}

std::set<std::string> makeFinallyCombolist(const std::set<std::string> preloaded_words,
                                           const std::set<std::string> &first_number_all_combinations_symbols,
                                           const std::set<std::string> &second_number_all_combinations_symbols)
{
    std::set<std::string> res;

    for (const std::string &first_combo: first_number_all_combinations_symbols) {
        if (preloaded_words.find(first_combo) != preloaded_words.end()) {
            for (const std::string &second_combo: second_number_all_combinations_symbols) {
                if (preloaded_words.find(second_combo) != preloaded_words.end()) {
                    res.insert("1-800-" + first_combo + "-" + second_combo);
                }
            }
        }
    }

    return res;
}

std::set<std::string> check1800(const std::string &str)
{
    const std::set<std::string> preloaded_words {loadSetStrings()};

    std::string temp_str{str.begin() + 6, str.end()};

    size_t pos_delimeter = temp_str.find('-');

    const std::string first_word{temp_str.begin(), temp_str.begin() + pos_delimeter};
    const std::string second_word{temp_str.begin() + pos_delimeter + 1, temp_str.end()};

    const std::string first_num{decodeWordToNumber(first_word)};
    const std::string second_num{decodeWordToNumber(second_word)};

    const std::set<std::string> first_number_all_combinations_symbols{makeSymbolCombinations(first_num)};
    const std::set<std::string> second_number_all_combinations_symbols{makeSymbolCombinations(second_num)};

    // directly
    std::set<std::string> finally_wordlist {makeFinallyCombolist(preloaded_words,
                                                                first_number_all_combinations_symbols,
                                                                second_number_all_combinations_symbols)};
    // backward
    std::string swaped_first_word {first_word};
    std::string swaped_second_word {second_word};

    if (swaped_first_word.length() == 3 && swaped_second_word.length() == 4) {
        std::string swaped_first{decodeWordToNumber(first_word)};
        std::string swaped_second{decodeWordToNumber(second_word)};

        swaped_first += swaped_second[0];
        swaped_second = swaped_second.erase(0, 1);

        const std::string swaped_first_num{decodeWordToNumber(swaped_first)};
        const std::string swaped_second_num{decodeWordToNumber(swaped_second)};

        const std::set<std::string> swaped_first_number_all_combinations_symbols{makeSymbolCombinations(swaped_first_num)};
        const std::set<std::string> swaped_second_number_all_combinations_symbols{makeSymbolCombinations(swaped_second_num)};

        const std::set<std::string> swaped_finally_wordlist {makeFinallyCombolist(preloaded_words,
                                                                                 swaped_first_number_all_combinations_symbols,
                                                                                 swaped_second_number_all_combinations_symbols)};
        finally_wordlist.insert(swaped_finally_wordlist.begin(), swaped_finally_wordlist.end());
    }
    else if (swaped_first_word.length() == 4 && swaped_second_word.length() == 3) {
        std::string swaped_first{decodeWordToNumber(first_word)};
        std::string swaped_second{decodeWordToNumber(second_word)};

        swaped_second = swaped_first[3] + swaped_second;
        swaped_first = swaped_first.erase(3, 4);

        const std::string swaped_first_num{decodeWordToNumber(swaped_first)};
        const std::string swaped_second_num{decodeWordToNumber(swaped_second)};

        const std::set<std::string> swaped_first_number_all_combinations_symbols{makeSymbolCombinations(swaped_first_num)};
        const std::set<std::string> swaped_second_number_all_combinations_symbols{makeSymbolCombinations(swaped_second_num)};

        const std::set<std::string> swaped_finally_wordlist {makeFinallyCombolist(preloaded_words,
                                                                                 swaped_first_number_all_combinations_symbols,
                                                                                 swaped_second_number_all_combinations_symbols)};
        finally_wordlist.insert(swaped_finally_wordlist.begin(), swaped_finally_wordlist.end());
    }


    return finally_wordlist;
}

int main()
{
    // ...
    return 0;
}
