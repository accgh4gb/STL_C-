#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>

void insert_sorted_vect(std::vector<int> &vectIn, const int insertion)
{
    std::vector<int>::iterator it;
    if(vectIn.front()<vectIn.back())
        it=std::lower_bound(vectIn.begin(),vectIn.end(), insertion);
    else
        it=(std::lower_bound(vectIn.rbegin(),vectIn.rend(), insertion)).base();

    vectIn.insert(it, insertion);
}

template <class CONTAINER, typename T>
void insert_sorted(CONTAINER& cntnr, const T insertion)
{
    typename CONTAINER::iterator it;
    if(cntnr.front()<cntnr.back())
	{
        it=std::lower_bound(cntnr.begin(),cntnr.end(), insertion);
	}
    else
	{
        it = (std::lower_bound(cntnr.rbegin(),cntnr.rend(), insertion)).base();
	}
    cntnr.insert(it, insertion);
}
