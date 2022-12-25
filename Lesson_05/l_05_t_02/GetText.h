#include <map>
#include <string>
#include <iostream>
#include <algorithm>

std::string SpecialSymbols(const std::string& input)
{
	std::string ignore(" \n\t\r");
	const auto begin = input.find_first_not_of(ignore);
	const auto end = input.find_last_not_of(ignore);
	return (begin != std::string::npos) ? input.substr(begin, end - begin + 1) : std::string{};
}

std::multimap<uint32_t, std::string> GetText(std::string& input)
{
	std::multimap<uint32_t, std::string> text;
	auto endIt = end(input);
	auto beginIt = begin(input);
	auto symbolsIt = std::find(beginIt, endIt, '.');
	while (beginIt != endIt && std::distance(beginIt, symbolsIt))
	{
		std::string str = SpecialSymbols({ beginIt, symbolsIt });
		uint32_t counter = std::count(str.begin(), str.end(), ' ') + 1;
		text.insert(std::make_pair(counter, std::move(str)));
		beginIt = std::next(symbolsIt, 1);
		symbolsIt = std::find(beginIt, endIt, '.');
		if (symbolsIt == endIt) break;
	}
	return text;
}
