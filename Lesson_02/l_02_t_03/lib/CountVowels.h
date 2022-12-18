#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

class CountVowels
{
public:
    CountVowels(const char* name):
        file(name, std::ios::in){}
    void readToVec();
    int forFor();
    int counIfFind();
    int countIfFor();
    int countIfForfor();
    int forFind();

    ~CountVowels(){file.close();}
private:
    std::ifstream file;
    std::vector<std::string> book;
};

