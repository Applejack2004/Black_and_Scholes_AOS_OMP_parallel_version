#include<iostream>
#include"Option.h"
#include <chrono>
#include "Functor_for_array.h"
int N;
Option* mas;
float Price = 0.0f;// ОБЩАЯ ЦЕНА ОПЦИОНА ЗА ВСЕ 
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
	const char* num_threads_str = std::getenv("OMP_NUM_THREADS");//возвращает указатель на переменную окружения.
	int num_threads;
	if (num_threads_str != nullptr) {
		 num_threads = std::atoi(num_threads_str);
		std::cout <<"Значение переменной окружения OMP_NUM_THREADS: " << num_threads << std::endl;
	}
	else {
		std::cout << "Переменная окружения OMP_NUM_THREADS не установлена" << std::endl;
	}

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