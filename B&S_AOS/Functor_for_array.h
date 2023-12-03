#pragma once
#include "Option.h"

class Functor_for_array
{
public:
	void operator() (Option* mas,int size)
	{
		
		
#pragma omp parallel num_threads(12)
		{
			std::default_random_engine rd(0);//генератор случайных чисел
			std::uniform_real_distribution<float> dist1(10.0f, 100.0f);
			std::uniform_real_distribution<float> dist2(5.0f, 30.0f);
#pragma omp for simd
			for (int i = 0; i < size; i++)
			{

				mas[i].S0 = dist1(rd);
				mas[i].K = mas[i].S0 + dist2(rd);
				mas[i].T = dist2(rd);
			}
		}
	}
};

