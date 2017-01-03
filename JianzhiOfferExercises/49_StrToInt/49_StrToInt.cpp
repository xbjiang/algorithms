// 49_StrToInt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

long long StrToIntCore(const char* str, bool minus);

enum Status {Valid = 0, Invalid};
int g_nStatus = Valid;

int StrToInt(const char* str)
{
	g_nStatus = Invalid;
	long long num = 0;
	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}

long long StrToIntCore(const char* str, bool minus)
{
	long long num = 0;
	int flag = minus ? -1 : 1;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			num = 10 * num + flag * (*str - '0');
		else
		{
			num = 0;
			break;
		}

		if ((!minus && num > 0x7fffffff) ||
			(minus && num < (signed int)0x80000000))
		{
			num = 0;
			break;
		}
		str++;
	}

	if (*str == '\0')
	{
		g_nStatus = Valid;
	}
	return num;
}

void Test(char* string)
{
	int num = StrToInt(string);
	if (num == 0 && g_nStatus == Invalid)
		printf("The input %s is invalid!\n", string);
	else
		printf("Number for %s is: %d.\n", string, num);
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test(NULL);
	Test("");
	Test("123");
	Test("+123");
	Test("-123");
	Test("2147483647");
	Test("2147483648");
	Test("+2147483648");
	Test("-2147483648");
	Test("-2147483649");
	Test("+0");
	Test("-0");
	Test("+");
	Test("-");
	Test("1a23");
	return 0;
}

