#include <deque>
#include <numeric>
#include "InsertSorted.h"

namespace container
{
template <class CONTEINER>
	void cout(CONTEINER& forOutput)
	{
	    for(auto element:forOutput)
		{
	        std::cout<<element<<" ";
		}
	    std::cout<<std::endl;
	}
}

int main()
{
    std::vector<int> vect1 ={1,2,3,4,5,7,9,0};
    int n=5;
    std::cout<<"vector1:"<<std::endl;
    std::sort(vect1.rbegin(),vect1.rend());
    container::cout(vect1);
    insert_sorted_vect(vect1,n);
    container::cout(vect1);

    std::cout<<"vector:"<<std::endl;
    insert_sorted(vect1,n);
    container::cout(vect1);

    std::cout<<"list:"<<std::endl;
    std::list <int> list={3,5,7};
    insert_sorted(list,n);
    container::cout(list);

    std::cout<<"deque:"<<std::endl;
    std::deque <int> deque={7,3,5,2,0};
    std::sort(deque.begin(),deque.end());
    insert_sorted(deque,n);
    container::cout(deque);

    return 0;
}
