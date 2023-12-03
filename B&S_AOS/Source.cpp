#include<iostream>
#include"Option.h"
#include <chrono>
#include "Functor_for_array.h"
int N;
Option* mas;
float Price = 0.0f;// Œ¡Ÿ¿ﬂ ÷≈Õ¿ Œœ÷»ŒÕ¿ «¿ ¬—≈ 
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	if (argc == 1)
	{
		std::cout << "no arguments!" << std::endl;
	}
	else
	{
		for (int i = 0; i < argc; i++)
		{
			std::cout << argv[i] << std::endl;
		}
		N = std::atoi(argv[1]);
	}
	/*std::cout << "Enter the size of array of structures:" << std::endl;
	std::cin >> N;*/
	mas = new Option[N];
	Functor_for_array FUNC;
	if (N >= 10)
	{
		FUNC(mas,N);
	}
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			std::cin >> mas[i];
		}
	}
	const std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
	Get_option_price(mas, N);
	const std::chrono::time_point<std::chrono::system_clock> t2 = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << " The option price has been calculated!" << std::endl;

	for (size_t i = 0; i < N; i++)
	{

		Price += mas[i].Get_out_price();
	}
	std::cout << "The fair option price for all shares: " << Price << "$" << std::endl;
	std::cout << "Elapsed time:" << time << " ms" << std::endl;
	delete[]  mas;
}