#include <cstdlib>
#include "homework2.h"
#include <ctime>
using namespace std;






int main()
{
	srand((int)time(0));
	CPoly p1((rand() % 10) - 5, (rand() % 10) - 5), p2;
	CPoly p3((rand() % 10) - 5, (rand() % 10) - 5, (rand() % 10) - 5);
	CPoly sum, dif, prod, result;

	p2 = p1;
	cout << "p1 = "; p1.Print();
	cout << "p2 = "; p2.Print();   //���p2�Ƿ���p1��ͬ
	cout << "p3 = "; p3.Print();

	cout << endl;
	sum = p1 + p2;
	cout << "sum = p1+p2 = "; sum.Print(); //���sum�Ƿ���p1��p2�ĺ�
	cout << "p1 = "; p1.Print(); //���p1�Ƿ񲻱�
	cout << "p2 = "; p2.Print(); //���p2�Ƿ񲻱�

	cout << endl;
	dif = sum - p3;
	cout << "dif = sum-p3 = "; dif.Print(); //���dif�Ƿ���sum��p3�Ĳ�
	cout << "sum = "; sum.Print(); //���sum�Ƿ񲻱�
	cout << "p3 = "; p3.Print(); //���dif�Ƿ񲻱�

	cout << endl;
	result = prod = sum * dif;
	cout << "prod = sum*dif = "; prod.Print(); //���prod�Ƿ���sum��dif�ĳ˻�
	cout << "result = prod = "; result.Print(); //���result�Ƿ���prod��ͬ
	cout << "sum = "; sum.Print(); //���sum�Ƿ񲻱�
	cout << "dif = "; dif.Print(); //���dif�Ƿ񲻱�

	cout << endl;
	result = sum += prod;
	/*cout << endl;
	sum.Print();
	cout << endl;*/
	cout << "sum += prod = "; sum.Print();  //���sum�Ƿ���sum��prod�ĺ�
	cout << "result = sum = "; result.Print(); //���result�Ƿ���sum��ͬ
	cout << "prod = "; prod.Print(); //���prod�Ƿ񲻱�

	return 0;
}
