#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <vector>

template<class It, class T>
void fill_container(It first, It last, T value)
{
    using SomeType = typename std::iterator_traits<It>::reference;

    std::for_each(
        first,
        last,
        [&](SomeType elt) {
            elt = value;
        }
    );

    // These are the five versions that work correctly.

    std::fill(first, last, value);

    std::for_each(first, last, [&](auto&& elt) { elt = value; });
    std::for_each(first, last, [&](SomeType elt) { elt = value; });

    for (auto&& elt : std::ranges::subrange(first, last)) { elt = value; }
    for (SomeType elt : std::ranges::subrange(first, last)) { elt = value; }
}

int main()
{
    std::vector<int> vi(10);
    fill_container(vi.begin(), vi.end(), 42);

    std::vector<bool> vb(10);
    fill_container(vb.begin(), vb.end(), true);

    std::array<bool, 10> ab {};
    fill_container(std::begin(ab), std::end(ab), true);

    assert(std::all_of(vi.begin(), vi.end(), [](auto&& x) { return x == 42; }));
    assert(std::all_of(vb.begin(), vb.end(), [](auto&& x) { return x == true; }));
    assert(std::all_of(std::begin(ab), std::end(ab), [](auto&& x) { return x == true; }));
}
