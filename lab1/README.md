## Lab 1: Palindrome Detection

In this lab, you'll write an STL-style generic algorithm using
bidirectional iterators.

Your code should make proper use of

    - iterator idioms such as pass-by-value

    - passing iterators to STL algorithms


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab1.m.cpp`
and immediately complain that the function `is_palindrome` does not exist.

You should add one function template to `lab1.m.cpp`:

- `bool is_palindrome(Iterator first, Iterator last)` should return true
    if the input range is a palindrome, such as "ABA" or "RACECAR".

Use raw iterator operations like `++first`, `--last`, and `first != last`
in the implementation of your algorithm.


### Easy Bonus: Mandate bidirectional iterators

Add a `static_assert` at the top of your function template's body,
which asserts that the type of `first` and `last` is a bidirectional
iterator type. You should use `iterator_traits` here, and then pass the
resulting iterator-category tag type to `std::is_base_of` (from
C++11's `<type_traits>` header).


### Hard Bonus: Constrain your template

Cut and paste your implementation into `lab1-bonus.m.cpp`,
and try `make lab1-bonus`. (Modify the Makefile to pass `-std=c++20`,
if you have a compiler that supports C++20 Concepts.)

Modify the interface of your `is_palindrome` algorithm until it passes
these new tests. It should correctly "SFINAE away," so that the compiler
understands that expressions such as `is_palindrome(flst.begin(), flst.end())`
are supposed to be ill-formed.

If you have access to C++20, you will find it much easier to use
_constrained template_ syntax such as

    bool is_palindrome(std::bidirectional_iterator auto first, std::bidirectional_iterator auto last)

or

    template<class It> requires std::bidirectional_iterator<It>
    bool is_palindrome(It first, It last)

If you are not using C++20, you might use `enable_if` metaprogramming.
In that case, the very last test case in `lab1-bonus.m.cpp` will be very
difficult (but possible). Consider commenting it out and just working
on the other test cases.
