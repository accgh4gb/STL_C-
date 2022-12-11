#include <iostream>
#include <sstream>
#include <optional>
#include <tuple>

//2. Создайте структуру PhoneNumber с 4 полями:
//   · код страны (целое число)
//   · код города (целое число)
//   · номер (строка)
//   · добавочный номер (целое число, опциональный тип)
//Для этой структуры перегрузите оператор вывода.
//Необходимо, чтобы номер телефона выводился в формате:
//+7(911)1234567 12, где 7 – это номер страны,
//911 – номер города, 1234567 – номер,
//12 – добавочный номер. Если добавочного номера нет,
//то его выводить не надо.
//Также перегрузите операторы < и == (используйте tie)

struct PhoneNumber
{
	int countryCode;
	int cityCode;
	std::string number;
	std::optional<int> additionalPhoneNumber;

	PhoneNumber(const int& m_countryCode = 0, const int& m_cityCode = 0,
			const std::string& m_number = "", std::optional<int> m_additionalPhoneNumber = std::nullopt);
	~PhoneNumber() {}
	friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& PN);
	friend bool operator<(const PhoneNumber& PN1, const PhoneNumber& PN2);
	friend bool operator==(const PhoneNumber& PN1, const PhoneNumber& PN2);
};
