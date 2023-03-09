#pragma once
#include <iostream>
class CPoly
{
private:
	int degree;  // 最高项次数，比如：3*x^2 - x +4的最高项次数是2
	double coef[10];  //各项系数, coef[0]=4, coef[1]=-1, coef[2]=3
public:
	CPoly(double c1, double c0); //构造一次多项式，c1为一次项系数，c0为常数项
	CPoly(double c2, double c1, double c0); //构造二次多项式，c2为二次项系数，c1为一次项系数，c0为常数项
	CPoly(CPoly&);  //复制构造函数
	CPoly(void);
	void Print(); //打印多项式
	friend CPoly operator+(CPoly,CPoly);     
	friend CPoly operator-(CPoly, CPoly);     
	friend CPoly operator*(CPoly, CPoly);
	friend CPoly operator+=(CPoly&, CPoly);   
};
CPoly::CPoly(void)
{
	degree = 0;
	for (int i = 0; i < 10; ++i)
	{
		coef[i] = 0;
	}
}
CPoly::CPoly(double c1, double c0)
{
	degree = 1;
	coef[0] = c0;
	coef[1] = c1;
	for (int i = 2; i < 10; ++i)
	{
		coef[i] = 0;
	}
}
CPoly::CPoly(double c2, double c1, double c0)
{
	degree = 2;
	coef[0] = c0;
	coef[1] = c1;
	coef[2] = c2;
	for (int i = 3; i < 10; ++i)
	{
		coef[i] = 0;
	}
}
CPoly::CPoly(CPoly& cp)
{
	degree = cp.degree;
	for (int i = 0; i < 10; ++i)
	{
		coef[i] = cp.coef[i];
	}
}
void CPoly::Print(void)
{
	for (int i = degree; i >= 0; --i)
	{
		if (coef[i] == 0)
		{
			if (i == 0)
			{
				std::cout << std::endl;
			}
			continue;
		}
		if (coef[i] < 0)
		{
			if (i == 1)
			{
				std::cout << coef[i] << "*X";
				continue;
			}
			if (i == 0)
			{
				std::cout << coef[i] << std::endl;
				return;
			}
			std::cout << coef[i] << "*X^" << i;
		}
		if (coef[i] > 0)
		{
			if (i == 1 && i != degree)
			{
				std::cout << "+" << coef[i] << "*X";
				continue;
			}
			if (i == degree)
			{
				if (degree != 1)
				{
					std::cout << coef[i] << "*X^" << degree;
					continue;
				}
				else
				{
					std::cout << coef[i] << "*X";
					continue;
				}
			}
			if (i == 0)
			{
				std::cout << "+" << coef[i] << std::endl;
				return;
			}
			if (i == degree)
			{
				std::cout << coef[i] << "*X^" << i;
				continue;
			}
			else
			{
				std::cout << "+" << coef[i] << "*X^" << i;
			}
		}

	}
}
CPoly operator+(CPoly a, CPoly cp)
{
	CPoly temp;
	if (a.degree <= cp.degree)
	{
		temp.degree = cp.degree;
	}
	else
	{
		temp.degree = a.degree;
	}
	for (int i = 0; i < 10; ++i)
	{
		temp.coef[i] = cp.coef[i] + a.coef[i];
	}
	return temp;
}      
CPoly operator-(CPoly a, CPoly cp)
{
	CPoly temp;
	if (a.degree <= cp.degree)
	{
		temp.degree = cp.degree;
	}
	else
	{
		temp.degree = a.degree;
	}
	for (int i = 0; i < 10; ++i)
	{
		temp.coef[i] = a.coef[i] - cp.coef[i];
	}
	return temp;
}
CPoly operator*(CPoly a, CPoly cp)
{
	CPoly temp;
	CPoly* pte = &temp;
	pte->degree = a.degree + cp.degree;
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			(pte->coef[i]) += a.coef[j] * cp.coef[i - j] + a.coef[i - j] * cp.coef[j];


		}
		(pte->coef[i]) /= 2.0;
	}
	return *pte;
}
CPoly operator+=(CPoly& a, CPoly cp)
{
	CPoly temp;
	if (a.degree >= cp.degree)
	{
		temp.degree = a.degree;
	}
	else
	{
		temp.degree = cp.degree;
		a.degree = cp.degree;
	}
	for (int i = 0; i < 10; ++i)
	{
		temp.coef[i] = a.coef[i] + cp.coef[i];
		a.coef[i] = a.coef[i] + cp.coef[i];
	}
	return temp;
}