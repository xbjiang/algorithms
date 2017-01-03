// 12_Print1ToMaxOfNDigits.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>

bool Increment(char* number, int n);
void PrintNumber(char* number, int n);

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n+1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number, n))
	{
		PrintNumber(number, n);
		printf(" ");
	}
	printf("\n");
	delete[] number;
}

bool Increment(char* number, int n)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int digit;

	for (int i = n - 1; i >= 0; i--)
	{
		digit = number[i] - '0' + nTakeOver;
		if (i == n - 1)
			digit++;
		
		if (digit >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
				break;
			}
			digit -= 10;
			number[i] = '0' + digit;
			nTakeOver = 1;
		}
		else
		{
			number[i] = '0' + digit;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number, int n)
{
	bool isBeginning0 = true;
	for (int i = 0; i < n; i++)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
			printf("%c", number[i]);
	}

}

void test(int n)
{
	printf("Test for %d digits begins:\n", n);
	Print1ToMaxOfNDigits(n);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test(3);
	test(2);
	test(1);
	test(0);
	test(-1);
	return 0;
}

