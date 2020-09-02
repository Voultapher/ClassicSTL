#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <list>
#include <queue>
#include <string>
#include <vector>

struct ByShortestThenReverseAlphabetical {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.size() != b.size()) return a.size() < b.size();
        return a > b;
    }
};

template<class It, class OutIt>
OutIt ten_longest_words(It first, It last, OutIt out)
{
    std::priority_queue<std::string, std::vector<std::string>, ByShortestThenReverseAlphabetical> pq;

    std::for_each(first, last, [&](const std::string& word) {
        pq.push(word);
    });

    for (int i=0; (i < 10) && !pq.empty(); ++i) {
        *out++ = pq.top();
        pq.pop();
    }

    return out;
}

int main()
{
    const std::list<std::string> sample = {
        "now", "is", "the", "time", "for", "all", "good", "men", "to",
        "come", "to", "the", "aid", "of", "their", "country",
    };

    std::list<std::string> dest(10);
    auto end = ten_longest_words(sample.begin(), sample.end(), dest.begin());

    std::for_each(dest.begin(), end, [](const std::string& word) {
        std::cout << std::quoted(word) << ", ";
    });
    std::cout << "\n";

    const std::string expected[] = {
        "country", "their", "come", "good", "time", "aid", "all", "for", "men", "now",
    };
    assert(std::distance(dest.begin(), end) == 10);
    assert(std::equal(dest.begin(), end, std::begin(expected), std::end(expected)));

    // We can even check that the output is sorted appropriately!
    assert(std::is_sorted(
        std::make_reverse_iterator(dest.begin()),
        std::make_reverse_iterator(end),
        ByShortestThenReverseAlphabetical()
    ));

    std::cout << "All tests passed!\n";
}
