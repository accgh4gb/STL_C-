#include "Container.h"

int main()
{
	Container example;
    for (auto temp : example)
	{
        std::cout << temp << " ";
    }
	
	return 0;
}
