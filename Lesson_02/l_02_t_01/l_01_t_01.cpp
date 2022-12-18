#include "Swap.h"

int main()
{
	int val1 = 10;
    int* ptr1 = &val1;
    int val2 = 20;
    int* ptr2 = &val2;

    printf("val1 = %d. *ptr1 = %d\n", val1, *ptr1);
    printf("val2 = %d. *ptr2 = %d\n", val2, *ptr2);

    Swap<int>(ptr1, ptr2);

    printf("val1 = %d. swapped *ptr1 = %d\n", val1, *ptr1);
    printf("val2 = %d. swapped *ptr2 = %d\n", val2, *ptr2);

    printf("\n");
	return 0;
}
