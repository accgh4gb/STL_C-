#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

std::mutex pcoutM;

template <typename T>
void pcout(T data)
{
       std::lock_guard<std::mutex> lock{pcoutM};
       std::cout << data;
}

void Process(int value)
{
	std::this_thread::sleep_for(1s);
	pcout(value);
	std::cout << std::endl;
}

int main()
{
	std::thread th1(Process, 1);
	std::thread th2(Process, 2);
	std::thread th3(Process, 3);
	std::thread th4(Process, 4);
	th1.join();
	th2.join();
	th3.join();
	th4.join();

	//pcout(5);
	
	return 0;
}
