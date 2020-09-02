## Lab 7: Library Management

In this lab, you'll practice writing your own hasher and your own
specialization of `std::hash`. This lab is divided into three parts;
each part should take you about 20 minutes.

Your code should make proper use of:

    - Specializing std::hash for user-defined types

    - Knowing when NOT to specialize std::hash

    - Using a custom hasher for library types


### Getting started

A partial solution (missing only some lines from the middle) is present
in the `partial/` directory. You should start there.

Run `make` to build the project. The compiler will try to compile `lab7.m.cpp`,
and it should compile and run just fine, except that the compiler may give
a warning about "control reaches end of non-void function" `Book::hash()`.

Read through the unit tests in `lab7.m.cpp`, and study the three data structures
inside `class Library` to see how they are managed. (In real life, there's a
lot of redundant information stored in these data structures, and we'd probably
try to "normalize" them a lot more than we did in this lab!)

Now modify `library.hpp` in the following ways. Finish part 1 *before*
proceeding to part 2, and finish part 2 *before* proceeding to part 3.
This will help keep you from getting lost in the spew of compiler error messages.


### Part 1: Replace `multiset<Book, ByAuthor>` with `unordered_multiset`

`class Library` defines a data member `std::multiset<Book, ByAuthor> books_` —
that is, a tree set of books, kept sorted by author, allowing "duplicate" books
with the same author.

Change the type of `books_` to `std::unordered_multiset`, and update its template
parameters, so that it is now a *hash set* of books, kept *hashed* by author (alone).
Use a hash function that depends only on the book's author, not its title.


### Part 2: Replace `std::map<Book, std::string> isbn_by_book_` with `unordered_map`

`class Library` defines a data member `std::map<Book, std::string> isbn_by_book_` —
that is, a tree map of books to strings. Look at the definition of `operator<` in
`book.hpp`. See that it depends on both the author and the title of the book,
and is consistent with `operator==`.

Change the type of `isbn_by_book_` to `std::unordered_map<Book, std::string>`.
Use the STL's defaults for both the hasher and the key-equivalence function.

You'll have to write a hash function for `Book`. Define `size_t Book::hash() const`
so that it is a valid hash function that depends on both the author and the title of
the book, and is consistent with `operator==`. To hash the title and author individually,
delegate to `std::hash<std::string>`. To combine the two hashes, for the purposes of
this lab, it's fine to use a simple `+` or `^`.

After defining `Book::hash()`, write a template specialization for `std::hash<Book>`.
It should go in `book.hpp`, because it is conceptually part of the global public API
of `class Book`.


### Part 3: Replace `std::map<std::pair<std::string, std::string>, Book const*>` with `unordered_map`

Finally, replace `Library`'s data member `book_by_title_and_author_` with an
`unordered_map`. Try compiling the program again. Notice that `std::pair<std::string, std::string>`
is not a valid key type for `unordered_map`, because it has no STL-provided `std::hash`
specialization.

You aren't allowed to specialize `std::hash` for the library type `std::pair<std::string, std::string>`.
So, write your own hasher type, similar to the hasher type you wrote in part 1,
but taking `pair<string, string>` instead of `Book`. Define your hasher type in
`library.hpp`, as an implementation detail of `class Library`.

Instantiate `unordered_map` with your new hasher type.
Think: Do you need to provide a custom key-equivalence function as well?
