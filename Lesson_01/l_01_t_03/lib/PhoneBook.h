#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include "Person.h"
#include "PhoneNumber.h"

//3. Создайте класс PhoneBook,
//который будет в контейнере хранить пары: Человек – Номер телефона.
//Конструктор этого класса должен принимать параметр
//типа ifstream – поток данных, полученных из файла.
//В теле конструктора происходит считывание данных из
//файла и заполнение контейнера. Класс PhoneBook должен
//содержать перегруженный оператор вывода,
//для вывода всех данных из контейнера в консоль.

//В классе PhoneBook реализуйте метод SortByName,
//который должен сортировать элементы контейнера по фамилии
//людей в алфавитном порядке. Если фамилии будут одинаковыми,
//то сортировка должна выполняться по именам, если имена будут одинаковы,
//то сортировка производится по отчествам. Используйте алгоритмическую функцию sort.
//Реализуйте метод SortByPhone, который должен сортировать элементы
//контейнера по номерам телефонов. Используйте алгоритмическую функцию sort.
//Реализуйте метод GetPhoneNumber, который принимает фамилию человека,
//а возвращает кортеж из строки и PhoneNumber. Строка должна быть пустой,
//если найден ровно один человек с заданном фамилией в списке.
//Если не найден ни один человек с заданной фамилией, то в строке
//должна быть запись «not found», если было найдено больше одного
//человека, то в строке должно быть «found more than 1».
//Реализуйте метод ChangePhoneNumber, который принимает человека
//и новый номер телефона и, если находит заданного человека в контейнере,
//то меняет его номер телефона на новый, иначе ничего не делает.
//Функция main будет выглядеть так:

class PhoneBook
{
private:
	std::vector<std::pair<Person, PhoneNumber>> PBook;

public:
	PhoneBook(std::ifstream& f);
	void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string &surname);
    void ChangePhoneNumber(const Person &person, const PhoneNumber &phonenumber);
	friend std::ostream& operator<<(std::ostream& os, const PhoneBook& PhBook);
};
