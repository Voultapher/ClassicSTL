## Lab 9: Upgrading to `string_view`

In this lab, you'll explore `std::string_view` and the notion of "`.c_str`-correctness."
It should take you about 15 minutes.


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. It should build fine.
Open up `lab9.m.cpp` and look at the functions it defines.
Each of them takes a `const std::string&` parameter.

For each function, ask yourself:

- Could this function take `std::string_view` instead of `const std::string&`?

- Semantically, does this function rely on null-termination?
    If so, it should not take `std::string_view`.

Prefer to use `.c_str()` to retrieve a `const char*` that must be null-terminated.
Prefer to use `.data()/.size()` to retrieve the buffer in cases
where null-termination isn't significant to the semantics.

Rewrite the signatures of these functions to take `string_view`
wherever possible. If you have a C++17 compiler, test them and
make sure your rewrites compile correctly.
