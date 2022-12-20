#include "Matrix.h"

int main()
{
    Matrix m(3);
    m.FillMatrix();
    std::cout<<"matrix: "<<std::endl;
    m.PrintMatrix();
    std::cout<<std::endl<<"Determinant is "<<m.Determinant()<<std::endl;
    m.Determinant();
	return 0;
}
