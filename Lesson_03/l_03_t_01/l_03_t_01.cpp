#include <iostream>
#include <list>

void AddAverage(std::list<double>& myList)
{
	double value1{0};
	int value2{0};
	std::list<double>::const_iterator it = myList.begin();
	while (it != myList.end())
	{
		value1 = value1 + *it;
		++value2;
		++it;
	}
	if (value2 != 0)
	{
		myList.push_back(value1 / myList.size());
	}
}

void printlst(const std::list<double>& myList)
{
	for (auto it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::list<double> MyList = { 3.24, 25.82, 0.13, 84.61, 5.15, 36.60 };
    printlst(MyList);
    AddAverage(MyList);
    printlst(MyList);
	return 0;
}
