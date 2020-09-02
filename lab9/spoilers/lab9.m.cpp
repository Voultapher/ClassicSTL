#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <string_view>

bool isPalindrome(std::string_view text) {
    std::string reversed(text);
    std::reverse(reversed.begin(), reversed.end());
    return text == reversed;
}

void openFile(const std::string& fname) {
    FILE *fp = fopen(fname.c_str(), "r");
    if (fp != nullptr) fclose(fp);
}

void printOld(std::string_view text) {
    printf("%.*s\n", static_cast<int>(text.size()), text.data());
}

void printNew(std::string_view text) {
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
