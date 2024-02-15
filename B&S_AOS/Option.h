#pragma once
#include <omp.h>
#include <cmath>
#include <iostream>
#include <random>


class Option
{
public:
	float T;//�����
	float S0;//��������� ���� �����
	float K;// ���� ���������� ��� ������
	float C = 0.0f;//���� �������
	/*static const float Volatility;
	static const float Interest_rest;*/
	Option(float _T, float _S0, float _K)
	{
		T = _T;
		S0 = _S0;
		K = _K;

	}
	Option()
	{
		T = 0.0f;//�����
		S0 = 0.0f;//��������� ���� �����
		K = 0.0f;// ���� ���������� ��� ������

	}

	float Get_out_price()
	{
		return C;
	}
	friend std::istream& operator>>(std::istream& is, Option& op)
	{

		std::cout << "Enter the inital stock price" << std::endl;
		is >>op.S0;
		std::cout << "Enter the strike" << std::endl;
		is >> op.K;
		std::cout << "Enter the time" << std::endl;
		is >> op.T;
		return is;

	}
	

};
 void Get_option_price(Option* mas, int Size);

