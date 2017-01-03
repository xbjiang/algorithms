// 35_FirstNotRepeatingChar.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ����������ԣ�����ֻ����һ�ε��ַ�
	Test("google", 'l');

	// ����������ԣ�������ֻ����һ�ε��ַ�
	Test("aabccdbd", '\0');

	// ����������ԣ������ַ���ֻ����һ��
	Test("abcdefg", 'a');

	// ³���Բ��ԣ�����NULL
	Test(NULL, '\0');

	return 0;
}

