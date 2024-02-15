#include "Option.h"


void Get_option_price(Option* mas, int Size)
{

	const float Volatility = 0.2f;
	const float Interest_rest = 0.13f;



	#pragma omp parallel 
	{

#pragma omp for simd
 for (int i = 0; i < Size; i++)
	{
		float d1 = (std::log(mas[i].S0 / mas[i].K) + (Interest_rest + (Volatility * Volatility / 2.0f) * mas[i].T) / Volatility * std::sqrtf(mas[i].T));
		float d2 = (std::log(mas[i].S0 / mas[i].K) + (Interest_rest - (Volatility * Volatility / 2.0f) * mas[i].T) / Volatility * std::sqrtf(mas[i].T));
		float cdfnorm1 = 0.5f + std::erf(d1 / std::sqrtf(2.0f)) / 2.0f;
		float cdfnorm2 = 0.5f + std::erf(d2 / std::sqrtf(2.0f)) / 2.0f;
		mas[i].C = mas[i].S0 * cdfnorm1 - mas[i].K * std::exp((-1.0f) * Interest_rest * mas[i].T) * cdfnorm2;

	}
	}
}
