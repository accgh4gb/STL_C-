#include <iostream>
#include <optional>
#include <tuple>

//Имеется база сотрудников и номеров их телефонов.
//Требуется написать соответствующие структуры для хранения данных,
//и заполнить контейнер записями из базы.
//Затем необходимо реализовать методы обработки данных,
//а также вывести на экран всю необходимую информацию.

//Важно! Имена переменным, классам и функциям давайте осознанные,
//состоящие из слов на английском языке.

//1. Создайте структуру Person с 3 полями: фамилия, имя, отчество.
//Поле отчество должно быть опционального типа,
//т.к. не у всех людей есть отчество.
//Перегрузите оператор вывода данных для этой структуры.
//Также перегрузите операторы < и == (используйте tie).


struct Person
{
	std::string firstName;
	std::string secondName;
	std::optional<std::string> patronymic;
	
	Person(std::string m_Name = "", std::string m_sName = "", std::optional<std::string> m_patronymic = "") : firstName(m_Name),
	secondName(m_sName), patronymic(m_patronymic) {}
	
	friend std::ostream& operator<<(std::ostream& os, const Person& P);
	friend bool operator<(const Person& P1, const Person& P2);
	friend bool operator==(const Person& P1, const Person& P2);
};
