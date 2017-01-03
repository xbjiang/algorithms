// MergeSort.cpp : 定义控制台应用程序的入口点。
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

void Merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 2];

	for (int i = 0; i < n1; i++) {
		L[i] = A[p+i];
	}
	
	for (int i = 0; i < n2; i++) {
		R[i] = A[q+1+i];
	}
	
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if (L[i] < R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}

	delete[] L;
	delete[] R;
}

void MergeSort(int A[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

int main()
{
	int n;
	std::cout << "please input the number of elements to sort: ";
	std::cin >> n;
	int* A = new int[n];
	std::cout << std::endl;
	
	std::cout << "please input the array to sort:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	std::cout << std::endl;
	
	print(A, n);
	MergeSort(A, 0, n-1);
	print(A, n);

	delete[] A;
	
	return 0;
	
}



