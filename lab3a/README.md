## Bonus Lab 3a: Regex Token Iterators

The C++11 `<regex>` header wasn't part of the original STL, but it follows
some classic STL principles; for instance, it is based on iterators.
In this bonus lab — which is optional and may depend on how much time we have
left in today's schedule! — you will modify the previous lab's code to use
the facilities defined in `<regex>`.

Your code should make proper use of

    - `sregex_token_iterator`

    - `ostream_iterator`

    - `std::copy` to an output iterator

    - using an output iterator with a non-`copy` algorithm


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab3a.m.cpp`
and immediately complain about the syntax error on line 39.

Complete the `std::copy` call on line 38 so that it uses `std::sregex_token_iterator`
and `std::ostream_iterator` to print the words in the string, separated
by spaces. (There will be a trailing space, too, but I don't mind.)

Also edit line 46 to pass `std::sregex_token_iterator` and `std::ostream_iterator`
to your `ten_longest_words` algorithm. If you do it correctly, the code should
compile and when you run `./lab3a` you should see this output:

    The words in the string are:
    now is the time for all good men to come to the aid of their country

    The ten longest words in the string (ties broken alphabetically) are:
    country their come good time aid all for men now

To find out how to use `sregex_token_iterator`, practice using https://en.cppreference.com.
