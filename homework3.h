#pragma once
#include <iostream>
class CPoly
{
private:
	int degree;  // �������������磺3*x^2 - x +4������������2
	double coef[10];  //����ϵ��, coef[0]=4, coef[1]=-1, coef[2]=3
public:
	CPoly(double c1, double c0); //����һ�ζ���ʽ��c1Ϊһ����ϵ����c0Ϊ������
	CPoly(double c2, double c1, double c0); //������ζ���ʽ��c2Ϊ������ϵ����c1Ϊһ����ϵ����c0Ϊ������
	CPoly(CPoly&);  //���ƹ��캯��
	CPoly(void);
	void Print(); //��ӡ����ʽ
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