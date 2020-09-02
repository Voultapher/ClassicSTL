#include <cassert>
#include <forward_list>
#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

#include "lab8.hpp"

template<class Container>
void test_sequence()
{
    std::cout << "Testing container " << __PRETTY_FUNCTION__ << "...\n";

    Container ctr;
    lab8::unique(ctr);  // try it on an empty container
    assert(ctr == Container{} && __PRETTY_FUNCTION__);

    ctr = {3,1,1,4,1,5,5,5,9,2,2,6,6,5,5,5,3,5,5};
    lab8::unique(ctr);  // try it on an empty container
    assert((ctr == Container{3,1,4,1,5,9,2,6,5,3,5}) && __PRETTY_FUNCTION__);
}

template<class Container>
void test_associative()
{
    std::cout << "Testing container " << __PRETTY_FUNCTION__ << "...\n";

    Container ctr;
    lab8::unique(ctr);  // try it on an empty container
    assert(ctr == Container{} && __PRETTY_FUNCTION__);

    ctr = {3,1,1,4,1,5,5,5,9,2,2,6,6,5,5,5,3,5,5};
    lab8::unique(ctr);  // try it on an empty container
    assert((ctr == Container{1,2,3,4,5,6,9}) && __PRETTY_FUNCTION__);
}

int main()
{
    test_sequence<std::list<int>>();
    test_sequence<std::forward_list<int>>();
    test_sequence<std::vector<int>>();
    test_sequence<std::deque<int>>();
    test_associative<std::set<int>>();
    test_associative<std::multiset<int>>();
    test_associative<std::unordered_set<int>>();
    test_associative<std::unordered_multiset<int>>();

    std::cout << "All tests passed!\n";
}
