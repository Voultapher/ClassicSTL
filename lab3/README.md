## Lab 3: Stream Iterators

In this lab, you'll practice using input and output iterators.
It should take you less than 15 minutes.

Your code should make proper use of

    - `istream_iterator`

    - `ostream_iterator`

    - `std::copy` to an output iterator


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab3.m.cpp`
and immediately complain about the syntax error on line 35.

Complete the `std::copy` call on line 34 so that it uses `std::istream_iterator`
and `std::ostream_iterator` to print the words in the string, separated
by spaces. (There will be a trailing space, too, but I don't mind.)

Also edit line 43 to pass `std::istream_iterator` and `std::ostream_iterator`
to your `ten_longest_words` algorithm. If you do it correctly, the code should
compile and when you run `./lab3` you should see this output:

    The words in the string are:
    now is the time for all good men to come to the aid of their country

    The ten longest words in the string (ties broken alphabetically) are:
    country their come good time aid all for men now
