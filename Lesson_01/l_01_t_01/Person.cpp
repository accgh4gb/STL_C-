#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& P)
{
	os << P.firstName << " " << P.secondName << " ";
	if (P.patronymic.has_value())
	{
		os << P.patronymic.value() << std::endl;
	}

	return os;
}

bool operator<(const Person& P1, const Person& P2)
{
	return std::tie(P1.firstName, P1.secondName, P1.patronymic) < std::tie(P2.firstName, P2.secondName, P2.patronymic);
}

bool operator==(const Person& P1, const Person& P2)
{
	return std::tie(P1.firstName, P1.secondName, P1.patronymic) == std::tie(P2.firstName, P2.secondName, P2.patronymic);
}
