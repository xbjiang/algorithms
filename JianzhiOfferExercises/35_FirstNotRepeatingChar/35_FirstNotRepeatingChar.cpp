// 35_FirstNotRepeatingChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

char FirstNotRepeatingChar(char* pString)
{
	if (pString == NULL)
		return '\0';

	const int size = 256;
	unsigned int hashTable[size] = {0};

	char* pHashKey = pString;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}




void Test(char* pString, char expected)
{
	if (FirstNotRepeatingChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 常规输入测试，存在只出现一次的字符
	Test("google", 'l');

	// 常规输入测试，不存在只出现一次的字符
	Test("aabccdbd", '\0');

	// 常规输入测试，所有字符都只出现一次
	Test("abcdefg", 'a');

	// 鲁棒性测试，输入NULL
	Test(NULL, '\0');

	return 0;
}

