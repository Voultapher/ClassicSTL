#include <algorithm>
#include <cassert>
#include <forward_list>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>

#if CONCEPTS1

template<std::bidirectional_iterator It>
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

#else

template<class T>
using iter_category_t = typename std::iterator_traits<T>::iterator_category;

template<class Tag>
using is_bidirectional = std::is_base_of<std::bidirectional_iterator_tag, Tag>;

template<class T, class Enable = void>
struct is_bidirectional_iterator : std::false_type {};

template<class T>
struct is_bidirectional_iterator<T, std::enable_if_t<
    is_bidirectional<iter_category_t<T>>::value
>> : std::true_type {};

static_assert(std::is_same<iter_category_t<int*>, std::random_access_iterator_tag>::value, "");
static_assert(is_bidirectional<iter_category_t<int*>>::value, "");
static_assert(is_bidirectional_iterator<int*>::value, "");
static_assert(is_bidirectional_iterator<std::list<int>::iterator>::value, "");

template<class It>
auto is_palindrome(It first, It last)
    -> std::enable_if_t<is_bidirectional_iterator<It>::value, bool>
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

#endif

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

    std::list<int> ints = {1,2,1};
    assert(is_palindrome(ints.begin(), ints.end()));
    ints.assign({1,2,2,1});
    assert(is_palindrome(ints.begin(), ints.end()));
    ints.assign({1,2,3,1});
    assert(!is_palindrome(ints.begin(), ints.end()));
    ints.clear();
    assert(is_palindrome(ints.begin(), ints.end()));
}

#if CONCEPTS2

template<class... Args>
concept has_is_palindrome = requires (Args... args) {
    is_palindrome(args...);
};

#else

namespace {
    template<class... Args>
    constexpr auto hip_impl(int, Args*... args)
        -> decltype(is_palindrome(*args...)) { return true; }
    template<class... Args>
    constexpr bool hip_impl(long, Args*...) { return false; }
}

template<class... Args>
constexpr bool has_is_palindrome = hip_impl(42, (Args*)nullptr...);

#endif

void test() {
    std::string s;
    std::list<char> lst;
    std::forward_list<char> flst;
    static_assert(has_is_palindrome<decltype(s.begin()), decltype(s.end())>, "");
    static_assert(has_is_palindrome<decltype(lst.begin()), decltype(lst.end())>, "");
    static_assert(!has_is_palindrome<decltype(flst.begin()), decltype(flst.end())>, "");
    static_assert(!has_is_palindrome<decltype(lst.begin()), decltype(s.end())>, "");
    static_assert(!has_is_palindrome<decltype(flst.begin()), decltype(s.end())>, "");

    // Warning: If you're not using C++20, the metaprogramming for this last assertion is very tricky.
    // If you're using C++20 std::bidirectional_iterator, it shouldn't be a problem at all.

    static_assert(!has_is_palindrome<decltype(1), decltype(2)>, "");
}
