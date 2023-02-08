#include <iostream>
#include <iomanip>
using namespace std;
void move(char source, char target);
void resolve(int n, char source, char temp, char target);
#define N 4              //the number of plates
int movetimes = 0;
int main(void)
{
	resolve(N, 'A', 'B', 'C');
	cout << endl;
	cout << "moved " << movetimes << " times" << endl;
	return 0;
}
void move(char source, char target)
{
	++movetimes;
	cout << source << "->" << target << setw(4);
	return;
}
void resolve(int n, char source, char temp, char target)
{
	if (n == 1)
	{
		move(source, target);
		return;
	}
	else
	{
		resolve(n - 1, source, target, temp);
		move(source, target);
		resolve(n - 1, temp, source, target);
	}
	
}