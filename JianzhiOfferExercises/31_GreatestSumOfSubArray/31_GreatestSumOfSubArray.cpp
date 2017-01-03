// 31_GreatestSumOfSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int* arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;
	int curSum = 0;
	//int greatestSum = 0x80000000;
	int greatestSum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (curSum < 0)
			curSum = arr[i];
		else
			curSum += arr[i];

		if (curSum > greatestSum)
			greatestSum = curSum;
	}
	return greatestSum;
}

void Test(char* testname, int* arr, int n, int expected, bool expectedFlag)
{
	if (testname != NULL)
		printf("%s begins:\n", testname);

	int result = FindGreatestSumOfSubArray(arr, n);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
	Test("Test4", NULL, 0, 0, true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}

