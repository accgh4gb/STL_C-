#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"

//Создать класс, представляющий матрицу.
//Реализовать в нем метод, вычисляющий определитель матрицы.
//Для реализации используйте контейнеры из STL

class Matrix
{
public:
    Matrix(int matixSize);
    void PrintMatrix();
    void FillMatrix();
    int Determinant();
private:
    int m_size;
    int m_determinant;
    int getDeterminant(std::vector<std::vector <int>> matrix,int size);
    std::vector<std::vector <int>>matrix;

};
