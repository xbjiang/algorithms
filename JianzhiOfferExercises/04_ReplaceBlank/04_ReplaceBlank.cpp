// 04_ReplaceBlank.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void ReplaceBlank(char* str)
{
	if (str == NULL) return;

	int length;
	int iter = 0;
	int count = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] == ' ')
			count++;
		iter++;
	}
	length = iter;
	//printf("count:%d\n", count);
	int newlength = length + count * 2;
	while (length >= 0 && newlength > length)
	{
		if (str[length] == ' ')
		{
			str[newlength--] = '0';
			str[newlength--] = '2';
			str[newlength--] = '%';
		}
		else
			str[newlength--] = str[length];
		length--;
	}

}

//测试代码
void test1()
{
	printf("Test1 begins:\n");

	char str[80] = "We ";

	printf("The original string is :%s\n", str);

	ReplaceBlank(str);

	printf("The new string is :%s\n", str);
}

void test2()
{
	printf("Test2 begins:\n");

	char str[80] = " We";

	printf("The original string is :%s\n", str);

	ReplaceBlank(str);

	printf("The new string is :%s\n", str);
}

void test3()
{
	printf("Test3 begins:\n");

	char str[80] = "We are";

	printf("The original string is :%s\n", str);

	ReplaceBlank(str);

	printf("The new string is :%s\n", str);
}

void test4()
{
	printf("Test4 begins:\n");

	char str[80] = "We are happy";

	printf("The original string is :%s\n", str);

	ReplaceBlank(str);

	printf("The new string is :%s\n", str);
}

void test5()
{
	printf("Test5 begins:\n");

	printf("Input is a NULL.\n");

	ReplaceBlank(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}

