#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <list>
#include <queue>
#include <string>
#include <vector>


// YOUR COMPARATOR CODE GOES HERE

template<class It, class OutIt>
OutIt ten_longest_words(It first, It last, OutIt out)
{
    // USE AN APPROPRIATE SPECIALIZATION OF PRIORITY_QUEUE
    std::priority_queue<~~~> pq;

    // INSERT EACH WORD INTO PQ

    // POP THE TOP 10 WORDS AND COPY THEM INTO "OUT"

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

    std::cout << "All tests passed!\n";
}
