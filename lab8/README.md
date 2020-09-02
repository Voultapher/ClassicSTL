## Lab 8: Uniqueness

In this lab, you'll practice the different idioms for erasing from a container.
It should take you about 45 minutes.

Your code should make proper use of

    - std::list::unique

    - the erase-remove idiom

    - using the iterator returned from erase()


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. The compiler will try to compile `lab8.m.cpp`
and immediately complain that `lab8::unique` does not exist.

Add code to `lab8.hpp` that implements the following overload set:

    lab8::unique(deque);
    lab8::unique(forward_list);
    lab8::unique(list);
    lab8::unique(multiset);
    lab8::unique(set);
    lab8::unique(unordered_multiset);
    lab8::unique(unordered_set);
    lab8::unique(vector);

For `vector` and `deque`, use the erase-remove idiom.

For `list` and `forward_list`, use their "special" member function `.unique()`.

For `set` and `unordered_set`, your function should be a no-op — it should do nothing, in O(1) time.

For `multiset` and `unordered_multiset`, use `it = ctr.erase(it)` in a loop.


### Philosophical bonus

Does our operation really even make sense for the associative containers?

Make the case that the operation makes _more_ sense for `unordered_multiset`
than for `unordered_set`.

Add a `Predicate pred` parameter to all of your overloads.
What should its default be in each case?
