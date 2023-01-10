#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

bool isPrime(int num)
{
    if (num==2)
	{
	   	return true;
	}
    if ((num<2)||(num%2==0))
	{
		return false;
	}
    for(int i=3;i<num/2;i=i+2)
	{
        if (num%i==0) return false;
	}
    return true;
}

std::mutex m;

void primeNumber(int val) {
	std::vector<int> primes;
	for (int i = 0; i < val; ++i)
	{
		if (isPrime(i))
		{
			std::lock_guard lg(m);
			primes.push_back(i);
		}
	}
	std::cout << primes.size() << "th primary number is: " << primes.back() << std::endl;
}

void progress()
{
	std::lock_guard lg(m);
	double progress = 0.0;
	while (progress < 1.0)
	{
		int barWidth = 50;
		std::cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i)
		{
			if (i < pos)
			{
				std::cout << "=";
			}
			else if (i == pos)
			{
				std::cout << ">";
			}
			else
			{
			   	std::cout << " ";
			}
		}
		std::cout << "] " << (int(progress * 100.0) + 1) << " %\r";
		std::cout.flush();
		progress += 0.01;
	}
	std::cout << std::endl;
}

int main()
{
	std::thread th1(progress);
	std::thread th2(primeNumber, 1000000);
	th1.join();
	th2.join();
	return 0;
}
