#include <cassert>
#include <stdexcept>

#include "book.hpp"
#include "library.hpp"

using namespace lab7;

void test_bookcount()
{
    Library library;
    assert(library.bookCount() == 0);

    library.addBook("Moby-Dick", "Melville", "1");
    library.addBook("Nicholas Nickleby", "Dickens", "4");
    library.addBook("Oliver Twist", "Dickens", "5");

    assert(library.bookCount() == 3);
}

void test_get_isbn()
{
    Library library;
    library.addBook("Moby-Dick", "Melville", "1");
    library.addBook("Nicholas Nickleby", "Dickens", "4");
    library.addBook("Oliver Twist", "Dickens", "5");

    assert(library.getISBN(Book("Moby-Dick", "Melville")) == "1");
    assert(library.getISBN(Book("Nicholas Nickleby", "Dickens")) == "4");
    assert(library.getISBN(Book("Oliver Twist", "Dickens")) == "5");
    assert(library.getISBN(Book("Oliver Shout", "Dickens")) == "---");
}

void test_get_book()
{
    Library library;
    library.addBook("Moby-Dick", "Melville", "1");
    library.addBook("Nicholas Nickleby", "Dickens", "4");
    library.addBook("Oliver Twist", "Dickens", "5");

    assert(library.getBook("Moby-Dick", "Melville") == Book("Moby-Dick", "Melville"));
    assert(library.getBook("Oliver Twist", "Dickens") == Book("Oliver Twist", "Dickens"));
    assert(library.getBook("Nicholas Nickleby", "Dickens") == Book("Nicholas Nickleby", "Dickens"));
    try {
        (void) library.getBook("Oliver Shout", "Dickens");
        assert(false);  // we expected an exception to be thrown
    } catch (const std::out_of_range&) {
        // OK: we expect this exception
    }
}

void test_removal()
{
    Library library;
    library.addBook("Moby-Dick", "Melville", "1");
    library.addBook("Nicholas Nickleby", "Dickens", "4");
    library.addBook("Oliver Twist", "Dickens", "5");

    library.removeBooksByAuthor("Dickens");
    assert(library.bookCount() == 1);
    assert(library.getISBN(Book("Moby-Dick", "Melville")) == "1");
    assert(library.getISBN(Book("Nicholas Nickleby", "Dickens")) == "---");
    assert(library.getISBN(Book("Oliver Twist", "Dickens")) == "---");

    assert(library.getBook("Moby-Dick", "Melville") == Book("Moby-Dick", "Melville"));
    try {
        (void) library.getBook("Nicholas Nickleby", "Dickens");
        assert(false);  // we expected an exception to be thrown
    } catch (const std::out_of_range&) {
        // OK: we expect this exception
    }
    try {
        (void) library.getBook("Oliver Twist", "Dickens");
        assert(false);  // we expected an exception to be thrown
    } catch (const std::out_of_range&) {
        // OK: we expect this exception
    }
}

void test_change_isbn()
{
    Library library;
    library.addBook("Moby-Dick", "Melville", "1");
    library.addBook("Nicholas Nickleby", "Dickens", "4");
    library.addBook("Oliver Twist", "Dickens", "5");

    library.changeISBN(Book("Nicholas Nickleby", "Dickens"), "2");
    library.changeISBN(Book("Oliver Twist", "Dickens"), "3");
    assert(library.getISBN(Book("Moby-Dick", "Melville")) == "1");
    assert(library.getISBN(Book("Nicholas Nickleby", "Dickens")) == "2");
    assert(library.getISBN(Book("Oliver Twist", "Dickens")) == "3");
}

int main()
{
    test_bookcount();
    test_get_isbn();
    test_get_book();
    test_removal();
    test_change_isbn();

    puts("All tests passed!");
}
