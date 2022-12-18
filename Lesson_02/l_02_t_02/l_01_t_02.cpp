#include "SortPointers.h"

int main()
{
	std::vector<int*> v;
    for(int i = 0; i < 100; i++)
    {
        int *c = new int;
        *c = rand()%1000;
        v.push_back(c);
    }	
	
	printf("Initialized vector: ");
	for (const auto& it: v)
	{
	    printf("%d ", *it);
	}
	printf("\n\n");
	
	SortPointers(v);

	printf("Sorted vector: ");
	for (const auto& it: v)
	{
	    printf("%d ", *it);
	}
	printf("\n");
	
	return 0;
}
