// 14_ReorderArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>

bool isEven(int number)
{
	return (number & 1) == 0;
}

void Reorder(int arr[], int n, bool (*func)(int))
{
	if (arr == NULL || n <= 0)
	{
		printf("Invalid input!");
		exit(1);
	}

	int i = -1;
	for (int j = 0; j < n; j++)
		if (!func(arr[j]))
			std::swap(arr[j], arr[++i]);
}

void ReorderArray2(int arr[], int n)
{
	Reorder(arr, n, isEven);
}

void ReorderArray(int arr[], int n)
{
	if (arr == NULL || n <= 0)
	{
		printf("Invalid input!");
		exit(1);
	}

	int i = -1;
	for (int j = 0; j < n; j++)
		if (arr[j] & 0x1)
			std::swap(arr[j], arr[++i]);
}

void test(int arr[], int n)
{
	int* copy = new int[n];
	for (int i = 0; i < n; i++)
		copy[i] = arr[i];

	printf("The original array is: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ReorderArray(arr, n);
	printf("The reordered array using 1st method is: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ReorderArray2(copy, n);
	printf("The reordered array using 2nd method is: ");
	for (int i = 0; i < n; i++)
		printf("%d ", copy[i]);
	printf("\n");

}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr1[5] = { 1, 2, 3, 4, 5 };
	int arr2[5] = { 1, 1, 1, 1, 1 };
	int arr3[5] = { 2, 2, 2, 2, 2 };

	test(arr1, 5);
	test(arr2, 5);
	test(arr3, 5);
	return 0;
}

