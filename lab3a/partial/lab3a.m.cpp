#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <queue>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

struct ByLongestThenAlphabetical {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    }
};

template<class It, class OutIt>
OutIt ten_longest_words(It first, It last, OutIt out)
{
    std::array<std::string, 10> result;
    return std::copy(
        result.begin(),
        std::partial_sort_copy(
            first, last,
            result.begin(), result.end(),
            ByLongestThenAlphabetical()
        ),
        out
    );
}

int main()
{
    std::string sample = "now is the time for all good men to come to the aid of their country";

    std::cout << "The words in the string are:\n";
    std::copy(
        YOUR CODE GOES HERE
        std::ostream_iterator<std::string>(std::cout, " ")
    );
    std::cout << "\n\n";

    std::cout << "The ten longest words in the string (ties broken alphabetically) are:\n";
    ten_longest_words(
        YOUR CODE GOES HERE
        std::ostream_iterator<std::string>(std::cout, " ")
    );
    std::cout << "\n";
}
