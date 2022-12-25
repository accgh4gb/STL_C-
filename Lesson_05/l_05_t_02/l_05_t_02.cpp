#include <iostream>
#include "GetText.h"

int main()
{
    std::cout << std::endl << "Enter text: ";
    std::string example;

    std::cin.unsetf(std::ios::skipws);
    std::getline(std::cin, example);
   
    for (const auto& [counter, sentence] : GetText(example))
	{
        std::cout << '[' << counter << "] words: " << sentence << std::endl;
    }

    return 0;
}
