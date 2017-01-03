// 11_Power.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>

bool g_IsInvalidInput = false;
bool isEqual(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_IsInvalidInput = false;

	if (isEqual(base, 0.0) && exponent < 0)
	{
		//printf("Invalid input!\n");
		g_IsInvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1.0;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;

	return result;
}

bool isEqual(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) 
		&& (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

void test(double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	//printf("%lf\n", result);
	if (abs(result - expectedResult) < 0.00000001 &&
		g_IsInvalidInput == expectedFlag)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	test(2, 3, 8, false);
	test(-2, 3, -8, false);
	test(2, -3, 0.125, false);
	test(2, 0, 1, false);
	test(0, 0, 1, false);
	test(0, 4, 0, false);
	test(0, -4, 0, true);

	return 0;
}

