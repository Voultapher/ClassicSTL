#pragma once

#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

namespace lab8 {

// YOUR CODE GOES HERE

// lab8::unique(deque&)

// lab8::unique(forward_list&)

// lab8::unique(list&)

// lab8::unique(multiset&)

// lab8::unique(set&)

// lab8::unique(unordered_multiset&)

// lab8::unique(unordered_set&)

template<class T>
void unique(std::vector<T>& v) {
    v.erase(std::unique(v.begin(), v.end()), v.end());
}

} // namespace lab8
