#include "Person.h"
#include <string>

std::ostream& operator<<(std::ostream& os, const Person& P)
{
	os << P.secondName << " " << P.firstName << " ";
	if (P.patronymic.has_value())
	{
		os << P.patronymic.value();
	}

	return os;
}

Person::Person(std::stringstream& str)
{
	std::string tmp_patron;
	str >> secondName >> firstName >> tmp_patron;
	if (!tmp_patron.empty())
	{
		patronymic = tmp_patron;
	}
}

bool operator<(const Person& P1, const Person& P2)
{
	return std::tie(P1.secondName, P1.firstName, P1.patronymic) < std::tie(P2.secondName, P2.firstName, P2.patronymic);
}

bool operator==(const Person& P1, const Person& P2)
{
	return std::tie(P1.secondName, P1.firstName, P1.patronymic) == std::tie(P2.secondName, P2.firstName, P2.patronymic);
}
