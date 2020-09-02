## Lab 2: Longest Words

In this lab, you'll practice using a comparator with `std::priority_queue`.

Your code should make proper use of

    - defining a custom comparator type

    - overloading `operator()`


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab2.m.cpp`
and immediately complain about the incomplete syntax in `ten_longest_words()`.

Add code to `lab2.m.cpp` that will select the longest 10 words in the
source text (ties broken alphabetically). For example, with the sample
input

    "now is the time for all good men to come to the aid of their country"

it should produce the words

    "country", "their", "come", "good", "time",
    "aid", "all", "for", "men", "now"

in that exact order.

You should do this by reading words into a `priority_queue` and then popping
from the top of the heap ten times. Remember that a `priority_queue` is a
max-heap, so that if you used the default comparator `std::less<std::string>`,
the elements would pop in reverse alphabetical order. So your custom
comparator should be a predicate `p(a,b)` that returns `true` when `a` is
*shorter* than `b` (ties broken alphabetically).

I recommend the name `ByShortestThenReverseAlphabetical` for your
comparator type.


### Bonus

Could you use `std::partial_sort_copy` to accomplish the same task more
efficiently? Rewrite your code to use `partial_sort_copy`.

Does using `partial_sort_copy` change the "contract" of your algorithm at all,
with respect to what the caller can expect from it? Why or why not?
(This may depend on exactly how you decided to use it.)
