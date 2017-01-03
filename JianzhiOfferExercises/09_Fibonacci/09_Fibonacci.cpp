// 09_Fibonacci.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

long long Fibonacci(int n)
{
	long long previous2 = 0;
	long long previous1 = 1;
	long long current;
	if (n == 0)
		return previous2;
	if (n == 1)
		return previous1;

	for (int i = 1; i <= n; i++)
	{
		current = previous2 + previous1;
		previous2 = previous1;
		previous1 = current;
		
	}

	return current;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	std::cout << "Please input the number of Fibinacci series:";
	std::cin >> n;
	
	std::cout << "The Fibonacci series is as follows:" << std::endl;
	for (int i = 0; i <= n; i++)
	{
		std::cout << Fibonacci(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}

