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
	cout << "p2 = "; p2.Print();  //���p2�Ƿ���p1��ͬ
	cout << "p3 = "; p3.Print();

	cout << endl;
	sum = p1.Add(p2);
	cout << "sum = p1+p2 = "; sum.Print();   //���sum�Ƿ���p1��p2�ĺ�
	cout << "p1 = "; p1.Print();  //���p1�Ƿ񲻱�
	cout << "p2 = "; p2.Print();  //���p2�Ƿ񲻱�

	cout << endl;
	dif = sum.Sub(p3);
	cout << "dif = sum-p3 = "; dif.Print(); //���dif�Ƿ���sum��p3�Ĳ�
	cout << "sum = "; sum.Print(); //���sum�Ƿ񲻱�
	cout << "p3 = "; p3.Print();  //���p3�Ƿ񲻱�

	cout << endl;
	prod = sum.Mul(dif);
	cout << "prod = sum*dif = "; prod.Print(); //���prod�Ƿ���sum��dif�ĳ˻�
	cout << "sum = "; sum.Print(); //���sum�Ƿ񲻱�
	cout << "dif = "; dif.Print(); //���dif�Ƿ񲻱�

	return 0;
}
