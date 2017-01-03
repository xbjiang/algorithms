// insertSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void insertSort(int* A, int length)
{
	if (A == NULL || length <= 0)
	{
		cout << "Invalid Input" << endl;
		exit(1);
	}

	for (int i = 1; i < length; i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void print(int* A, int length)
{
	if (A == NULL || length <= 0)
	{
		cout << "Invalid Input" << endl;
		exit(1);
	}
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


void test()
{
	int A[5] = {3,4,2,5,1};
	print(A, 5);
	insertSort(A, 5);
	print(A, 5);
	
}



int _tmain(int argc, _TCHAR* argv[])
{
	test();
	return 0;
}

