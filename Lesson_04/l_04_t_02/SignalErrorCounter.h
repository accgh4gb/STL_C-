#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

double SignalErrorCounter(std::vector<float>& analogSignal,std::vector<int>& digitalSignal)
{

    return std::inner_product(analogSignal.begin(),analogSignal.end(),
                              digitalSignal.begin(), 0.0,
                              std::plus<float>{},
                              [](float_t aSgnl, int dSgnl)
                              {return pow((aSgnl-dSgnl),2);});
}
