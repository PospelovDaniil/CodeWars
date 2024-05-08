#include <iostream>
#include <algorithm>
#include <string>

/**
 * Convert all the cases!
 *
 * In this kata, you will make a function that converts between camelCase, snake_case, and kebab-case.
 *
 * You must write a function that changes to a given case. It must be able to handle all three case types:
 * cpp> changeCase("snakeCase", "snake")
 * "snake_case"
 * cpp> changeCase("some-lisp-name", "camel")
 * "someLispName"
 * cpp> changeCase("map_to_all", "kebab")
 * "map-to-all"
 * cpp> changeCase("doHTMLRequest", "kebab")
 * "do-h-t-m-l-request"
 * cpp> changeCase("invalid-inPut_bad", "kebab")
 * ""
 * cpp> changeCase("valid-input", "huh???")
 * ""
 * cpp> changeCase("", "camel")
 * ""
 *
 * Your function must deal with invalid input as shown, though it will only be passed strings.
 * Furthermore, all valid identifiers will be lowercase except when necessary, in other words on word boundaries in camelCase.
 */

using namespace std;

enum class Case
{
    Invalid,
    Snake,
    Kebab,
    Camel,
    NoCase
};

Case isValid(const string &str)
{
    const bool is_contains_underline = str.find("_") != string::npos;
    const bool is_contains_minus = str.find("-") != string::npos;
    const bool is_containse_uppercase = any_of(str.begin(), str.end(), ::isupper);

    const int hints = static_cast<int>(is_contains_underline) +
                      static_cast<int>(is_contains_minus) +
                      static_cast<int>(is_containse_uppercase);

    if (hints > 1) { return Case::Invalid; }
    if (is_contains_underline) { return Case::Snake; }
    if (is_contains_minus) { return Case::Kebab; }
    if (is_containse_uppercase) { return Case::Camel; }

    return Case::NoCase;
}

string changeCase(const string &identifier, const string &targetCase)
{
    const Case original_case = isValid(identifier);
    if (original_case == Case::Invalid) {
        return {};
    }

    string original {identifier};

    if (targetCase == "snake") {
        switch (original_case) {
        case Case::Kebab: { std::replace(original.begin(), original.end(), '-', '_'); return original; }
        case Case::Camel: {
            std::string res;
            for (const char c: original) {
                if (::isupper(c)) {
                    res += "_";
                    res += std::tolower(c);
                }
                else {
                    res += c;
                }
            }
            return res;
        };
        case Case::Snake: { return original; }
        case Case::Invalid: {}
        case Case::NoCase: { return original; }
        }
    }
    else if (targetCase == "camel") {
        switch (original_case) {
        case Case::Snake:
        case Case::Kebab: {
            std::string res;

            for (auto it = original.begin(); it != original.end();) {
                if (*it == '_' || *it == '-') {
                    res += std::toupper(*std::next(it));
                    it = std::next(it);
                }
                else {
                    res += *it;
                }

                ++it;
            }

            return res;
        };
        case Case::Camel: { return original; }
        case Case::Invalid: {}
        case Case::NoCase: { return original; }
        }
    }
    else if (targetCase == "kebab") {
        switch (original_case) {
        case Case::Kebab: { return original; }
        case Case::Camel: {
            std::string res;
            for (const char c: original) {
                if (::isupper(c)) {
                    res += "-";
                    res += std::tolower(c);
                }
                else {
                    res += c;
                }
            }
            return res;
        };
        case Case::Snake: { std::replace(original.begin(), original.end(), '_', '-'); return original; }
        case Case::Invalid: {}
        case Case::NoCase: { return original; }
        }
    }

    return {};
}

int main()
{
    cout << changeCase("snakeCase", "snake") << endl;
    cout << changeCase("some-lisp-name", "camel") << endl;
    cout << changeCase("map_to_all", "kebab") << endl;

    return 0;
}
