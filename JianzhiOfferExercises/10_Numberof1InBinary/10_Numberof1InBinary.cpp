// 10_Numberof1InBinary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int Numberof1(int n)
{
	int count = 0;
	int mask = 0x1;
	while (mask)
	{
		if (n & mask)
			count++;
		mask <<= 1;
	}
	return count;
}

int Numberof1_2(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}
	return count;
	
}

void test(int n)
{
	printf("Number of 1 in %x is %d and %d.\n", n, Numberof1(n), Numberof1_2(n));
}

int _tmain(int argc, _TCHAR* argv[])
{
	test(0xFFFFFFFF);
	test(0x80000000);
	test(0x7FFFFFFF);
	test(0x0);
	return 0;
}

