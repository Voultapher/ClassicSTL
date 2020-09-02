#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <string>
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
    std::vector<std::string> result(10);
    auto end = std::partial_sort_copy(
        first, last,
        result.begin(), result.end(),
        ByLongestThenAlphabetical()
    );
    return std::copy(result.begin(), end, out);
}

int main()
{
    std::string sample = "now is the time for all good men to come to the aid of their country";
    auto iss = std::istringstream(sample);

    std::cout << "The words in the string are:\n";
    std::copy(
        YOUR CODE GOES HERE
    );
    std::cout << "\n\n";

    iss = std::istringstream(sample);  // rewind to the beginning of the sample string

    std::cout << "The ten longest words in the string (ties broken alphabetically) are:\n";

    YOUR CODE GOES HERE

    std::cout << "\n";
}
