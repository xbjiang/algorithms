// 30_KLeastNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/Array.h"
#include <set>
#include <vector>
#include <functional>

void GetKLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
	if (input == NULL || n <= 0 || output == NULL || k <= 0 || n < k)
		return;

	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; i++)
		output[i] = input[i];
}

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator SetInterator;
using std::vector;

void GetKLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k <= 0 || data.size() < k)
		return;

	vector<int>::const_iterator iter = data.cbegin();
	for (; iter != data.cend(); iter++)
	{
		if (leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
		else
		{
			SetInterator greatestIter = leastNumbers.begin();
			if (*iter < *greatestIter)
			{
				leastNumbers.erase(greatestIter);
				leastNumbers.insert(*iter);
			}
		}
	}

}

void Test(char* testname, int* input, int n, int* expectedResult, int k)
{
	if (testname != NULL)
		printf("%s begins:\n", testname);

	if (expectedResult == NULL)
	{
		printf("The input is invalid. We don't expect any result!\n");
	}
	else
	{
		printf("Expected result: \n");
		for (int i = 0; i < k; i++)
			printf("%d\t", expectedResult[i]);
		printf("\n");
	}

	printf("Result for solution 1:\n");
	int* output = new int[k];
	GetKLeastNumbers_Solution1(input, n, output, k);
	if (expectedResult != NULL)
	{
		for (int i = 0; i < k; i++)
			printf("%d\t", output[i]);
		printf("\n");
	}
	
	delete[] output;

	printf("Result for solution 2:\n");
	vector<int> data;
	for (int i = 0; i < n; i++)
		data.push_back(input[i]);
	intSet leastNumbers;
	GetKLeastNumbers_Solution2(data, leastNumbers, k);
	for (const auto& num : leastNumbers)
		printf("%d\t", num);

	printf("\n\n");
}

void Test1()
{
	int data[] = {4,5,1,6,2,7,3,8};
	int expected[] = {1,2,3,4};
	Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test2()
{
	int data[] = {4,5,1,6,2,7,3,8};
	int expected[] = {1,2,3,4,5,6,7,8};
	Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test3()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = NULL;
	Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

void Test4()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1 };
	Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test5()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = NULL;
	Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

void Test6()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
	int expected[] = { 1, 2 };
	Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void Test7()
{
	int* expected = NULL;
	Test("Test7", NULL, 0, expected, 0);
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
	return 0;
}

