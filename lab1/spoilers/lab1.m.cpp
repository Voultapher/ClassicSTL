#include <algorithm>
#include <cassert>
#include <forward_list>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>

template<class It>
bool is_palindrome(It first, It last)
{
    while (first != last) {
        --last;
        if (first == last) break;
        if (*first != *last) {
            return false;
        }
        ++first;
    }
    return true;
}

int main()
{
    std::list<char> lst;
    std::string s = "able was i ere i saw elba";
    assert(is_palindrome(s.begin(), s.end()));
    assert(!is_palindrome(s.begin(), s.end()-1));

    lst.assign(s.begin(), s.end());
    assert(is_palindrome(lst.begin(), lst.end()));
    assert(!is_palindrome(lst.begin(), std::prev(lst.end())));

    s = "madam in eden i'm adam";
    assert(!is_palindrome(s.begin(), s.end()));  // because spaces count
    assert(is_palindrome(&s[0], &s[5]));
    assert(!is_palindrome(&s[0], &s[3]));

    s = "redder";
    assert(is_palindrome(&s[0], &s[6]));

    lst.assign(s.begin(), s.end());
    assert(is_palindrome(lst.begin(), lst.end()));
}
