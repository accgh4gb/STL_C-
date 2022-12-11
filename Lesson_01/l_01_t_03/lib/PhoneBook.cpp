#include "PhoneBook.h"
#include <string>

PhoneBook::PhoneBook(std::ifstream& f)
{
	if (!f.is_open())
	{
		std::cout << "File is not open!" << std::endl;
	}
	else
	{
		std::string str;
		while (std::getline(f, str))
		{
			std::string name;
			std::string	sname;
			std::string number;
			std::string	addNumber;
			std::string	patronymic;

			int countryCode;
			int cityCode;
			std::istringstream strStream(str);
			strStream >> sname >> name >> patronymic >> countryCode >> cityCode >> number >> addNumber;
			std::optional<std::string>  oPatronymic;
			std::optional<int> oAddNumber;

			if(patronymic == "-")
			{
				oPatronymic = std::nullopt;
			}
			else
			{
				oPatronymic=patronymic;
			}
			if (addNumber == "-")
			{
				oAddNumber = std::nullopt ;
			}
			else
			{
				oAddNumber = atoi(addNumber.c_str());
			}

			PBook.push_back(std::make_pair(Person(sname, name, oPatronymic), PhoneNumber(countryCode, cityCode, number, oAddNumber)));
       }
	}
	f.close();
}

void PhoneBook::ChangePhoneNumber(const Person &person, const PhoneNumber &phonenumber)
{

    for_each(PBook.begin(), PBook.end(), [&](std::pair<Person,PhoneNumber> &note)mutable
    {
        if (note.first==person)
        {
            note.second=phonenumber;
        }
    });
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string &surname)
{

    int count=0;
    PhoneNumber phN(0,0," ",0);

    for_each(PBook.begin(), PBook.end(), [&count, &phN, &surname](const std::pair<Person,PhoneNumber> &note)
    {
        if (note.first.secondName == surname)
        {
            count++;
            phN = note.second;
        }
    });

    if(count == 0)
	{
        return {"not found", 0 };
	}
    else if(count == 1)
	{
        return {"", phN};
	}
    return {"found more than 1",0};


}

void PhoneBook::SortByName()
{
    std::sort(PBook.begin(), PBook.end(), [](const std::pair<Person,PhoneNumber> &p1, const std::pair<Person,PhoneNumber> &p2) {
        return p1.first < p2.first;
    });
}

void PhoneBook::SortByPhone()
{
    std::sort(PBook.begin(), PBook.end(), [](const std::pair<Person,PhoneNumber> &p1, const std::pair<Person,PhoneNumber> &p2) {
        return p1.second < p2.second;
    });
}


std::ostream& operator<<(std::ostream& os, const PhoneBook& PhBook)
{
	for (const auto& [person, number] : PhBook.PBook)
	{
		os << person << " " << number << std::endl;	
	}
	return os;
}
