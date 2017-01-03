// 34_UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

bool isUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		number++;

		if (isUgly(number))
			uglyFound++;
	}

	return number;
}

int Min(int num1, int num2, int num3)
{
	int minimum = num1 < num2 ? num1 : num2;
	
	minimum = minimum < num3 ? minimum : num3;
	
	return minimum;
}

int GetUglyNumber_Solution2(int index)
{
	int* uglyNumber = new int[index];
	
	int* pMultiply2 = uglyNumber;
	int* pMultiply3 = uglyNumber;
	int* pMultiply5 = uglyNumber;

	/*int nextUglyIndex = 0;
	uglyNumber[nextUglyIndex++] = 1;
	while (nextUglyIndex < index)
	{
		int Minimum = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		uglyNumber[nextUglyIndex] = Minimum;

		while (*pMultiply2 * 2 <= uglyNumber[nextUglyIndex])
			pMultiply2++;
		while (*pMultiply3 * 3 <= uglyNumber[nextUglyIndex])
			pMultiply3++;
		while (*pMultiply5 * 5 <= uglyNumber[nextUglyIndex])
			pMultiply5++;

		nextUglyIndex++;
	}
	int result = uglyNumber[nextUglyIndex - 1];*/

	int i = 0;
	uglyNumber[i] = 1;
	for (i = 1; i < index; i++)
	{
		int Minimum = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		uglyNumber[i] = Minimum;

		while (*pMultiply2 * 2 <= uglyNumber[i])
			pMultiply2++;
		while (*pMultiply3 * 3 <= uglyNumber[i])
			pMultiply3++;
		while (*pMultiply5 * 5 <= uglyNumber[i])
			pMultiply5++;
	}
	int result = uglyNumber[index - 1];
	
	delete[] uglyNumber;

	return result;
}

void Test(int index, int expected)
{
/*
	if (GetUglyNumber_Solution1(index) == expected)
		printf("solution1 passed\n");
	else
		printf("solution1 failed\n");*/

	if (GetUglyNumber_Solution2(index) == expected)
		printf("solution2 passed\n");
	else
		printf("solution2 failed\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);

	return 0;
}

