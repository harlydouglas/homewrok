#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#define N 8          //the number of queens
void show(int queens[]);
void resolve(int queens[], int begin, int end);
int totalsolution = 0;
ofstream ofile;
int main()
{
	ofile.open("queenssolution.txt");
	int queens[N];
	for (int i = 0; i <= N - 1; i++)
	{
		queens[i] = i ;
	}
	resolve(queens, 0, N );
	cout << '\n' << totalsolution << endl;
	ofile.close();
	return 0;
}
void resolve(int queens[],int begin,int end)
{
	if (begin == end-1)
	{
		for (int i = 0; i <= N - 1; i++)
		{
			for (int j = i+1; j <= N - 1; j++)
			{
				if (abs(queens[i] - queens[j]) == j-i)
				{
					return;
				}
			}
		}
		show(queens);
		return;
	
	}
	else
	{
		for (int i = begin; i < end; i++)
		{
			swap(queens[i], queens[begin]);
			resolve(queens, begin + 1, end);
			swap(queens[i], queens[begin]);
		}
	}
	return;
}
void show(int queens[])
{
	for (int i = 0; i <= N - 1; i++)
	{
		cout << queens[i];
		ofile << queens[i];
	}
	cout << '\t'; totalsolution++;
	ofile << '\t';
	if (totalsolution % 5 == 0)
	{
		cout << endl;
		ofile << endl;
	}
	return;
}