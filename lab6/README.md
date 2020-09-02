## Lab 6: Weighted Longest Words

In this lab, you'll practice mutating a non-trivial STL container
and "nesting" STL algorithms. It should take you about an hour.


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab6.m.cpp`
and immediately complain about the syntax error on line 13, where
`ten_heaviest_words` is unimplemented.

Add code to `ten_heaviest_words` that will select the "heaviest" 10 words
in the source text (ties broken alphabetically), **subject to a new wrinkle
in the rules**. Keep reading:


### The new rule

Read the words from the input in sequence. Each word's initial "weight" is
equal to its length; for example, the initial weight of `"hello"` is 5.

However, each time you read a word, you should increment the weight of
each and every word _lexicographically less-than_ the current word.

For example, with the sample input

    "now is the time for all good men to come to the aid of their country"

the words with their current weights at each step would be:

    now (3)
    is(2) now(3)
    is(3) now(4) the(3)
    is(4) now(5) the(4) time(4)
    for(3) is (4) now(5) the(4) time(4)
    all(3) for(3) is(4) now(5) the(4) time(4)
    all(4) for(4) good(4) is(4) now(5) the(4) time(4)
    all(5) for(5) good(5) is(5) men(3) now(5) the(4) time(4)
    all(6) for(6) good(6) is(6) men(4) now(6) the(5) time(5) to(2)
    ...

and the final output should be

    "all for good is now come men the country aid"

in that exact order. Even though `"all"` is of length 3, its weight
has been increased by 1 for each of the words after it (except `"aid"`),
giving it a final weight of 12. The words "for," "good," "is," and "now"
each have weight 10 and appear in alphabetical order. The word "aid"
has weight 6 (3 for its initial length, plus 1 for each of the following
three words).


### Hint

This is a fairly open-ended problem; you might reasonably come up with
a solution that does not resemble the sample solution. The sample solution
uses a `std::multimap` to store the words with their current weights;
`std::for_each` word, we insert it into the map and then increment the
weight of each word less than it. As usual for this series
of labs, we use `std::partial_sort_copy` to extract the highest-weight
words (ties broken alphabetically). Finally, we use `std::transform`
to replace each weighted string-int pair with just its string part.

Another option would be to use a `std::multiset` of weighted words
sorted lexicographically, and practice using the node-handle API
`.extract` and `.insert` to update the weights. (But in real life,
you would just make the "weight" field a `mutable` data member.)
