#pragma once

#include <iterator>

namespace lab5 {

template<class It, class T>
It reverse_find(It first, It last, T value) {
    auto rend = std::make_reverse_iterator(first);
    auto rit = std::find(
        std::make_reverse_iterator(last),
        rend,
        value
    );
    return (rit == rend) ? last : rit.base();
}

template<class It, class Predicate>
It reverse_find_if(It first, It last, Predicate predicate) {
    auto rend = std::make_reverse_iterator(first);
    auto rit = std::find_if(
        std::make_reverse_iterator(last),
        rend,
        predicate
    );
    return (rit == rend) ? last : rit.base();
}

} // namespace lab4
