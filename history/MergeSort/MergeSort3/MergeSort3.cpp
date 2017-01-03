// MergeSort2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void MergeSortCore(int* data, int* copy, int start, int end);

void MergeSort(int* data, int length)
{
	if (data == NULL || length <= 0)
		return;

	int* copy = new int[length];
	/*for (int i = 0; i < length; i++)
		copy[i] = data[i];*/

	MergeSortCore(data, copy, 0, length - 1);

	delete[] copy;
}

void MergeSortCore(int* data, int* copy, int start, int end)
{
	if (start == end)
		return;

	int length = (end - start) / 2;
	MergeSortCore(data, copy, start, start + length);
	MergeSortCore(data,copy, start + length + 1, end);

	int i = start;
	int j = start + length + 1;
	int index = start;

	while (i <= start + length && j <= end)
	{
		if (data[i] < data[j])
			copy[index++] = data[i++];
		else
			copy[index++] = data[j++];
	}

	while (i <= start + length)
		copy[index++] = data[i++];

	while (j <= end)
		copy[index++] = data[j++];

	for (i = start; i <= end; i++)
		data[i] = copy[i];
}

void Test(int* data, int length)
{
	printf("Original array: ");
	for (int i = 0; i < length; i++)
		printf("%d ", data[i]);
	printf("\n");

	MergeSort(data, length);

	printf("Sorted array: ");
	for (int i = 0; i < length; i++)
		printf("%d ", data[i]);
	printf("\n");
}

void Test1()
{
	int data[] = { 3, 2, 1, 4, 6, 5, 7, 9 };
	Test(data, sizeof(data) / sizeof(int));
}

void Test2()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Test(data, sizeof(data) / sizeof(int));
}

void Test3()
{
	int data[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	Test(data, sizeof(data) / sizeof(int));
}

void Test4()
{
	Test(NULL, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}

