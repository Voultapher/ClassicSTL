#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

struct ByHeaviest {
    using Pair = std::pair<const std::string, int>;
    bool operator()(const Pair& a, const Pair& b) const {
        if (a.second != b.second) return (a.second > b.second);
        return (a.first < b.first);
    }
};

template<class It, class OutIt>
OutIt ten_heaviest_words(It first, It last, OutIt out)
{
    auto getfirst = [](const auto& kv) { return kv.first; };

    std::multimap<std::string, int> words;
    std::for_each(first, last, [&](auto&& word) {
        int weight = word.size();
        auto it = words.emplace(word, weight);
        std::for_each(words.begin(), it, [](auto&& kv) {
            kv.second += 1;
        });
    });
    std::vector<std::pair<std::string, int>> result(10);
    auto end = std::partial_sort_copy(words.begin(), words.end(), result.begin(), result.end(), ByHeaviest());

    return std::transform(result.begin(), end, out, getfirst);
}

int main()
{
    std::vector<std::string> actual;
    std::istringstream iss;
    std::ostringstream oss;

    iss = std::istringstream("s t d l i s t");
    oss = std::ostringstream();
    actual = {};
    ten_heaviest_words(
        std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        std::back_inserter(actual)
    );
    std::copy(actual.begin(), actual.end(), std::ostream_iterator<std::string>(oss, " "));
    std::cout << oss.str() << "\n";
    assert(oss.str() == "d s i l s t t ");

    iss = std::istringstream("now is the time for all good men to come to the aid of their country");
    oss = std::ostringstream();
    actual = {};
    ten_heaviest_words(
        std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        std::back_inserter(actual)
    );
    std::copy(actual.begin(), actual.end(), std::ostream_iterator<std::string>(oss, " "));
    std::cout << oss.str() << "\n";
    assert(oss.str() == "all for good is now come men the country aid ");

    std::cout << "All tests passed!\n";
}
