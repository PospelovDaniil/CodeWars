#include <iostream>
#include <vector>
#include <string>

/**
 * https://www.codewars.com/kata/53dc23c68a0c93699800041d
 *
 * Sentence Smash
 * Write a function that takes an array of words and smashes them together into a sentence and returns the sentence.
 * You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word.
 * Be careful, there shouldn't be a space at the beginning or the end of the sentence!
 *
 * ['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
 */

std::string smash(const std::vector<std::string>& words)
{
    std::string res;

    for (auto it = words.begin(); it != words.end(); ++it) {
        if (it == words.begin() || it == words.end()) {
            res += *it;
        }
        else {
            res += " " + *it;
        }
    }

    return res;
}

int main()
{
    using namespace std::string_literals;

    std::vector strings {"hello"s, "world"s, "this"s, "is"s, "great"s};
    std::cout << smash(strings) << std::endl;

    return 0;
}
