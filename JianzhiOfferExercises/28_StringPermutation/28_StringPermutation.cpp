// 28_StringPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void permutation(char* str, char* pBegin);

void permutation(char* str)
{
	if (str == NULL)
		return;

	permutation(str, str);
}

void permutation(char* str, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", str);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			permutation(str, pBegin+1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Test(char* pStr)
{
	if (pStr == NULL)
		printf("Test for NULL begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	permutation(pStr);

	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test(NULL);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	char string5[] = "abcd";
	Test(string5);

	return 0;
}

