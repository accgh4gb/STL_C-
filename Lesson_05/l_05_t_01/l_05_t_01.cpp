#include <iostream>
#include <list>
#include "UniqueWords.h"

int main()
{
    std::vector<std::string> str{ "the", "hi", "good", "a", "what", "hi", "hi", "good"};
    std::cout << "Vector is: ";
    print(str);
    std::cout << "Unique words: ";
    UniqueWords<std::string>(str.begin(), str.end());

    std::list<std::string> lst{ "the", "hi", "good", "a", "what", "hi", "hi", "ok", "a"};
    std::cout << "List is: ";
    print(lst);
    std::cout << "Unique words: ";
    UniqueWords<std::string>(lst.begin(), lst.end());

    return 0;
}
