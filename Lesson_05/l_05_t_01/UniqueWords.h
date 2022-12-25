#include <vector>
#include <iostream>
#include <set>
#include <iterator>

template<typename T, typename it>
void UniqueWords(const it& itBegin, const it& itEnd)
{
	std::set<T> itSet;
	std::copy(itBegin, itEnd, std::inserter(itSet, itSet.end()));
	std::copy(itSet.begin(), itSet.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << std::endl;
}

template<typename T>
void print(T& val)
{
	for (auto out : val)
	{
		std::cout << out << " ";
	}
	std::cout << std::endl;
}

