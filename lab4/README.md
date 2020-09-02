## Lab 4: Vector of Bool

In this lab, you'll explore the reason for `iterator_traits<It>::reference`.

### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab4.m.cpp`
and immediately complain that `SomeType` is not defined.

Complete the typedef on line 10 by delegating to `iterator_traits`.

Now, uncomment each of the commented-out lines one by one. Which ones
give you error messages at compile time? Which ones compile but give the
wrong behavior at runtime?
