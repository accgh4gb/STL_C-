#include <iostream>
#include <vector>
#include "Swap.h"
//Реализуйте шаблонную функцию SortPointers,
//которая принимает вектор указателей и сортирует
//указатели по значениям, на которые они указывают

template<typename T>
void SortPointers(std::vector<T*> &ptrVec)
{
    size_t size = ptrVec.size();
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
		{
            if (*ptrVec[j] > *ptrVec[j + 1])
			{
                Swap(ptrVec[j], ptrVec[j + 1]);
			}			
		}
    }
}
