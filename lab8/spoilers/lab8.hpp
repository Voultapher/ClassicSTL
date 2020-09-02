#pragma once

#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

namespace lab8 {

template<class T, class A, class Pred = std::equal_to<T>>
void unique(std::deque<T, A>& v, Pred p = Pred()) {
    v.erase(std::unique(v.begin(), v.end(), p), v.end());
}

template<class T, class A, class Pred = std::equal_to<T>>
void unique(std::forward_list<T, A>& v, Pred p = Pred()) {
    v.unique(p);
}

template<class T, class A, class Pred = std::equal_to<T>>
void unique(std::list<T, A>& v, Pred p = Pred()) {
    v.unique(p);
}

template<class T, class A>
void unique(std::multiset<T, std::less<T>, A>& v) {
    if (v.empty()) return;
    auto last = v.begin();
    auto it = v.begin();
    ++it;
    while (it != v.end()) {
        if (*last == *it) {
            it = v.erase(it);
        } else {
            last = it;
            ++it;
        }
    }
}

template<class T, class A>
void unique(std::set<T, std::less<T>, A>&) {
    // do nothing, it's already uniqued
}

template<class T, class H, class A>
void unique(std::unordered_multiset<T, H, std::equal_to<T>, A>& v) {
    if (v.empty()) return;
    auto last = v.begin();
    auto it = v.begin();
    ++it;
    while (it != v.end()) {
        if (*last == *it) {
            it = v.erase(it);
        } else {
            last = it;
            ++it;
        }
    }
}

template<class T, class H, class A>
void unique(std::unordered_set<T, H, std::equal_to<T>, A>&) {
    // do nothing, it's already uniqued
}

template<class T, class A, class Pred = std::equal_to<T>>
void unique(std::vector<T, A>& v, Pred p = Pred()) {
    v.erase(std::unique(v.begin(), v.end(), p), v.end());
}

} // namespace lab8
