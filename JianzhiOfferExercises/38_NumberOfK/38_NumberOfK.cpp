// 38_NumberOfK.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int GetFirstK(int* numbers, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	int midNum = numbers[mid];
	if (midNum == k)
	{
		if ((mid > 0 && numbers[mid - 1] != k)
			|| mid == 0)
			return mid;
		else
			end = mid - 1;
	}
	else if (midNum > k)
		end = mid - 1;
	else
		start = mid + 1;

	return GetFirstK(numbers, length, k, start, end);
}

int GetLastK(int* numbers, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	int midNum = numbers[mid];
	if (midNum == k)
	{
		if ((mid < length - 1 && numbers[mid + 1] != k)
			|| mid == length - 1)
			return mid;
		else
			start = mid + 1;
	}
	else if (midNum > k)
		end = mid - 1;
	else
		start = mid + 1;

	return GetLastK(numbers, length, k, start, end);
	
}

int GetNumberOfK(int* numbers, int length, int k)
{
	int count = 0;
	if (numbers != NULL && length > 0)
	{
		int first = GetFirstK(numbers, length, k, 0, length - 1);
		int last = GetLastK(numbers, length, k, 0, length - 1);
		
		if (first > -1 && last > -1)
			count = last - first + 1;
	}
	return count;
}

void Test(char* testName, int data[], int length, int k, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	int result = GetNumberOfK(data, length, k);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// ���ҵ����ֳ�����������м�
void Test1()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
	int data[] = { 3, 3, 3, 3, 4, 5 };
	Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ľ�β
void Test3()
{
	int data[] = { 1, 2, 3, 3, 3, 3 };
	Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ����ֲ�����
void Test4()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
	int data[] = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
	int data[] = { 3, 3, 3, 3 };
	Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
	int data[] = { 3, 3, 3, 3 };
	Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
	int data[] = { 3 };
	Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
	int data[] = { 3 };
	Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// ³���Բ��ԣ������ָ��
void Test11()
{
	Test("Test11", NULL, 0, 0, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();

	return 0;
}

