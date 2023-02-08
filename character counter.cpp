#include <iostream>
#include <fstream>
using namespace std;
ifstream ifile;
int main()
{
	ifile.open("data.txt");
	for (;;)
	{
		if (!ifile.is_open())
		{
			cout << "can not open the file" << endl;
			cout << "press any Enter to go back" << endl;
			cin.get();
			return 0;
		}
		else
			break;
	}
	int chnum[26] = { 0 };
	int nunum[10] = { 0 };
	int parnum = 0;
	for(;;)
	{
		char ch;
		ifile.get(ch);
		if (ifile.eof())
			break;
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))        //sum char
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				chnum[ch + 32 - 97]++;
			}
			else
			{
				chnum[ch - 97]++;
			}
		}

		if (ch >= '0' && ch <= '9')                                      //sum number
		{
			nunum[ch - '0']++;
		}

		if (ch == '\n')   //sum paragraph
		{
			parnum++;
		}
		
	} 
	for (int i = 0; i <= 25; i++)
	{
		if (chnum[i] != 0)
		{
			cout << (char)('a' + i) << "   " << chnum[i] << endl;
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		if (nunum[i] != 0)
		{
			cout << i << "   " << nunum[i] << endl;
		}
	}
	cout << "line   " << parnum << endl;
	ifile.close();
	return 0;




}
