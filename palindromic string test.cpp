#include <iostream>
#include <string>
using namespace std;
inline void canc(string& a);
inline string reverse2(string a);

int main()
{
	string tar;
	getline(cin, tar, '\n');
	canc(tar);
	cout << "the native string:" << tar << endl;
	string reverse1 = reverse2(tar);
	cout << "the reversed string:" << reverse1<<endl;
	if (reverse1 == tar)
	{
		cout << "this is a palindromic string" << endl;
	}
	else
	{
		cout << "this is not a palindromic string" << endl;
	}
	return 0;
}
void canc(string& a)
{
	for (int i = 0;i < a.length();i++)
	{
		if (a.at(i) >= 'A' && a.at(i) <= 'Z')
		{
			a.at(i) = (char)(a.at(i) + 32);
		}
		else
		{
			if (a.at(i) < 'A' || a.at(i) > 'z' || (a.at(i) < 'a' && a.at(i) > 'Z'))
			{
				a.erase(i, 1);
				i--;
			}
		}
	}
	return;
}
string reverse2(const string a)
{
	int start = 0, end = a.length();
	string temp(a);
	while (start < end)
	{
		end--;
		swap(temp[start], temp[end]);
		start++;
	}
	return temp;
}