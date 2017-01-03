// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

void print(int A[], int n)
{
	for (int i = 0; i < n; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}

void exchange(int A[], int i, int j)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j] < x)  exchange(A, ++i, j);
	}
	exchange(A, ++i, r);
	return i;
}

void QuickSort(int A[], int p, int r)
{
	if (p < r) {
		int q = partition(A, p, r);
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
}

int main()
{
	int n;
	std::cout << "Please input the number of elements to sort: " << std::endl;
	std::cin >> n;
	int* A = new int[n];
	std::cout << std::endl;
	std::cout << "Please input the array to sort: " << std::endl; 
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}

	print(A, n);
	QuickSort(A, 0, n-1);
	print(A, n);

	delete[] A;
	return 0;
}
