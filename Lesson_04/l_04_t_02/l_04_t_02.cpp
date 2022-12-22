#include <iostream>
#include <deque>
#include <list>
#include <numeric>
#include "SignalErrorCounter.h"

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
    std::vector<float> analogSignal(100);
    std::generate(analogSignal.begin(), analogSignal.end(), [] () mutable { return (std::rand()%100)/3.5; });
    container::cout(analogSignal);

    std::vector<int> digitalSignal(analogSignal.begin(), analogSignal.end());
    container::cout(digitalSignal);
    std::cout<<"Error between digital signal and analog signal: " << SignalErrorCounter(analogSignal,digitalSignal)<<std::endl;
    return 0;
}
