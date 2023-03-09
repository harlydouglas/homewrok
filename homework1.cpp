#include <ctime>
#include <cstdlib>
#include "homework1.h"
using namespace std;
int main()
{
	srand((int)time(0));
	CPoly p1((rand() % 10) - 5, (rand() % 10) - 5), p2 = p1;
	CPoly p3((rand() % 10) - 5, (rand() % 10) - 5, (rand() % 10) - 5);
	CPoly sum, dif, prod;

	cout << "p1 = "; p1.Print();
	cout << "p2 = "; p2.Print();  //检查p2是否与p1相同
	cout << "p3 = "; p3.Print();

	cout << endl;
	sum = p1.Add(p2);
	cout << "sum = p1+p2 = "; sum.Print();   //检查sum是否是p1与p2的和
	cout << "p1 = "; p1.Print();  //检查p1是否不变
	cout << "p2 = "; p2.Print();  //检查p2是否不变

	cout << endl;
	dif = sum.Sub(p3);
	cout << "dif = sum-p3 = "; dif.Print(); //检查dif是否是sum和p3的差
	cout << "sum = "; sum.Print(); //检查sum是否不变
	cout << "p3 = "; p3.Print();  //检查p3是否不变

	cout << endl;
	prod = sum.Mul(dif);
	cout << "prod = sum*dif = "; prod.Print(); //检查prod是否是sum和dif的乘积
	cout << "sum = "; sum.Print(); //检查sum是否不变
	cout << "dif = "; dif.Print(); //检查dif是否不变

	return 0;
}
