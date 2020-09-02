#pragma once

#include <functional>
#include <string>
#include <utility>

namespace lab7 {

class Book {
    std::string title_;
    std::string author_;

public:
    explicit Book(std::string title, std::string author) :
        title_(std::move(title)), author_(std::move(author)) {}

    std::string title() const { return title_; }
    std::string author() const { return author_; }

    friend bool operator<(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) < std::tie(b.title_, b.author_);
    }
    friend bool operator<=(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) <= std::tie(b.title_, b.author_);
    }
    friend bool operator>(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) > std::tie(b.title_, b.author_);
    }
    friend bool operator>=(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) >= std::tie(b.title_, b.author_);
    }
    friend bool operator==(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) == std::tie(b.title_, b.author_);
    }
    friend bool operator!=(const Book& a, const Book& b) {
        return std::tie(a.title_, a.author_) != std::tie(b.title_, b.author_);
    }

    size_t hash() const {
        // YOUR CODE GOES HERE to hash both the title and the author
    }
};

} // namespace lab7
