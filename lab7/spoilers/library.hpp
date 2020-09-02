#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "book.hpp"

namespace lab7 {

class Library {
    struct HashAuthor {
        size_t operator()(const Book& a) const {
            return std::hash<std::string>()(a.author());
        }
    };

    struct HashPair {
        template<class T, class U>
        size_t operator()(const std::pair<T, U>& pair) const {
            return std::hash<T>()(pair.first) + std::hash<U>()(pair.second);
        }
    };

    struct SameAuthor {
        bool operator()(const Book& a, const Book& b) const {
            return a.author() == b.author();
        }
    };

    std::unordered_multiset<Book, HashAuthor, SameAuthor> books_;
    std::unordered_map<Book, std::string> isbn_by_book_;
    std::unordered_map<std::pair<std::string, std::string>, Book const*, HashPair> book_by_title_and_author_;

public:
    explicit Library() = default;

    int bookCount() const { return books_.size(); }

    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        // You can assume that the same title+author will not be added more than once.
        // We may insert both "Hamlet" and "Macbeth", but won't insert "Hamlet" twice.
        auto it = books_.emplace(title, author);
        isbn_by_book_[*it] = isbn;
        book_by_title_and_author_.emplace(std::make_pair(title, author), std::addressof(*it));
    }

    void removeBooksByAuthor(const std::string& author) {
        auto dummy = Book("dummy", author);
        auto lohi = books_.equal_range(dummy);
        std::for_each(lohi.first, lohi.second, [&](const Book& book) {
            book_by_title_and_author_.erase(std::make_pair(book.title(), book.author()));
            isbn_by_book_.erase(book);
        });
        books_.erase(lohi.first, lohi.second);
    }

    const Book& getBook(const std::string& title, const std::string& author) const {
        return *book_by_title_and_author_.at({ title, author });
    }

    std::string getISBN(const Book& book) const {
        try {
            return isbn_by_book_.at(book);
        } catch (const std::out_of_range&) {
            return "---";
        }
    }

    void changeISBN(const Book& book, const std::string& isbn) {
        // In C++17, you can do isbn_by_book_.insert_or_assign(book, isbn)
        isbn_by_book_[book] = isbn;
    }
};

} // namespace lab7
