// 08_MinNumberInRotatedArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int minInorder(int arr[], int length);
int findMinNumber(int arr[], int length)
{
	if (arr == NULL || length <= 0)
	{
		printf("Invalid input!");
		exit(1);
	}

	if (arr[0] < arr[length - 1])
		return arr[0];

	int start = 0;
	int end = length - 1;
	int mid = (end + start) / 2;
	while (start < end - 1)
	{
		if (arr[mid] == arr[start] && arr[mid] == arr[end])
			return minInorder(arr+start, end - start + 1);

		if (arr[mid] >= arr[start])
			start = mid;
		else if (arr[mid] <= arr[end])
			end = mid;
		mid = (start + end) / 2;
	}
	return arr[end];
}

int minInorder(int arr[], int length)
{
	int minNumber = arr[0];
	for (int i = 0; i < length; i++)
	{
		if (arr[i] <= minNumber)
			minNumber = arr[i];
	}
	return minNumber;

}

void test(int arr[], int length)
{
	printf("Array:");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int minNumber = findMinNumber(arr, length);
	printf("Min number: %d\n", minNumber);
}

void test1()
{
	printf("Test1 begins:\n");
	int arr[7] = { 4, 5, 6, 7, 1, 2, 3 };
	test(arr, 7);
}

void test2()
{
	printf("Test2 begins:\n");
	int arr[7] = { 1, 1, 1, 1, 0, 1, 1 };
	test(arr, 7);
}

void test3()
{
	printf("Test3 begins:\n");
	int arr[7] = { 1, 1, 0, 1, 1, 1, 1 };
	test(arr, 7);
}

void test4()
{
	printf("Test4 begins:\n");
	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	test(arr, 7);
}

void test5()
{
	printf("Test5 begin:\n");
	int arr[7] = {3,4,5,1,2,3,3};
	test(arr, 7);
}

void test6()
{
	printf("Test6 begins:\n");
	int arr[1] = {2};
	test(arr, 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}

