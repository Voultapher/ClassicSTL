#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <string_view>

// Which of these functions could use std::string_view instead?

bool isPalindrome(const std::string& text) {
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    return text == reversed;
}

void openFile(const std::string& fname) {
    FILE *fp = fopen(fname.c_str(), "r");
    if (fp != nullptr) fclose(fp);
}

void printOld(const std::string& text) {
    printf("%s\n", text.c_str());
}

void printNew(const std::string& text) {
    std::ostringstream oss;
    oss << text << "\n";
}

int toInt(const std::string& text) {
    return std::stoi(text);
}


int main()
{
    std::string s = "42";
    const char *p = "42";

    (void) isPalindrome(s);
    (void) isPalindrome(p);
    (void) isPalindrome("racecar");

    openFile(s);
    openFile(p);
    openFile("hello.txt");

    printOld(s);
    printOld(p);
    printOld("hello world");

    printNew(s);
    printNew(p);
    printNew("hello world");

    (void) toInt(s);
    (void) toInt(p);
    (void) toInt("42");
}
