#include <iostream>
#include "CountVowels.h"

int main()
{
	std::cout<<"Операции с данными из вектора: "<<std::endl;
    CountVowels Text("./War_and_peace.txt");
    std::vector<int> count;
    Text.readToVec();
    count.push_back(Text.counIfFind());
    count.push_back(Text.countIfFor());
    count.push_back(Text.countIfForfor());
    count.push_back(Text.forFind());
    count.push_back(Text.forFor());

	return 0;

}
