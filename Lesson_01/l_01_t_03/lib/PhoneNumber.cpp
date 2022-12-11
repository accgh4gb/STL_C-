#include "PhoneNumber.h"
#include <string>

PhoneNumber::PhoneNumber(const int& m_countryCode, const int& m_cityCode, const std::string& m_number,
	   	std::optional<int> m_additionalPhoneNumber)
{
	if(m_countryCode == 8)
	{
		countryCode = 7;
	}
	else
	{
		countryCode = m_countryCode;
	}

	cityCode = m_cityCode;
	
	if (m_number.size() != 7)
	{
		std::cout << "Wrong number dialed. Please, try again." << std::endl;
	}
	else
	{
		for (int i = 0; i < 7; ++i)
		{
			if (m_number[i] < '0' || m_number[i] > '9')
			{
				std::cout << "Wrong number dialed. Your number contains a character. Please, try again" << std::endl;
				break;
			}
		}
		number = m_number;
	}
	additionalPhoneNumber = m_additionalPhoneNumber;
}

std::ostream& operator<<(std::ostream& os, const PhoneNumber& PN)                                                                         
{
	os << "+" << PN.countryCode << "(" << PN.cityCode << ")" << PN.number << " ";
	if(PN.additionalPhoneNumber.has_value())
	{
		os << PN.additionalPhoneNumber.value() << std::endl;
	}
	return os;
}

bool operator<(const PhoneNumber& PN1, const PhoneNumber& PN2)
{
	return std::tie(PN1.countryCode, PN1.cityCode, PN1.number, PN1.additionalPhoneNumber) < std::tie(PN2.countryCode, PN2.cityCode, PN2.number, PN2.additionalPhoneNumber);
}

bool operator==(const PhoneNumber& PN1, const PhoneNumber& PN2)
{
	return std::tie(PN1.countryCode, PN1.cityCode, PN1.number, PN1.additionalPhoneNumber) == std::tie(PN2.countryCode, PN2.cityCode, PN2.number, PN2.additionalPhoneNumber);

}
