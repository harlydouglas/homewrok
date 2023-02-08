#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
int binarysearch(int A[], int start, int end, int target);

int main()
{
	int A[12] = {1,2,3,4,7,8,9,10,23,45,67,89};
	int target = 45;
	cout<<binarysearch(A, 0, sizeof(A) / sizeof(int) - 1, target);
	return 0;
}

int binarysearch(int A[], int start, int end,int target)
{
	int mid = (start + end) / 2;
	if (A[mid] == target)
	{
		return mid;
	}
	if (start == end)
	{
		return -1;
	}
	bool dir = target > A[mid] ? 1 : 0;
	if (dir)
	{
		binarysearch(A, mid + 1, end, target);
	}
	else
	{
		binarysearch(A, start, mid - 1, target);
	}
	

}