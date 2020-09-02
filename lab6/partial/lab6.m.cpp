#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

template<class It, class OutIt>
OutIt ten_heaviest_words(It first, It last, OutIt out)
{
    YOUR CODE GOES HERE
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
