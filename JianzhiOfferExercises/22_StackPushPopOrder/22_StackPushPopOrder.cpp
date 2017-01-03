// 22_StackPushPopOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

bool isPopOrder(const int* pPush, const int* pPop, int length)
{
	bool result = false;
	
	if (pPush != NULL && pPop != NULL && length > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		std::stack<int> stackData;

		while (pNextPop - pPop < length)
		{
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush == length)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop - pPop == length)
			result = true;
	}
	return result;
}

void test(char* testname, const int* pPush, const int* pPop, int length, bool expected)
{
	bool result = isPopOrder(pPush, pPop, length);
	printf("%s begins: ", testname);
	if (result == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

void test1()
{
	const int length = 5;
	int pPush[length] = { 1, 2, 3, 4, 5 };
	int pPop[length] = { 4, 5, 3, 2, 1 };
	test("Test1", pPush, pPop, length, true);
}

void test2()
{
	const int length = 5;
	int pPush[length] = { 1, 2, 3, 4, 5 };
	int pPop[length] = { 3, 5, 4, 2, 1 };
	test("Test2", pPush, pPop, length, true);
}

void test3()
{
	const int length = 5;
	int pPush[length] = {1,2,3,4,5};
	int pPop[length] = {3,5,4,1,2};
	test("Test3", pPush, pPop, length, false);
}

void test4()
{
	const int length = 1;
	int pPush[length] = {1};
	int pPop[length] = {2};
	test("Test4", pPush, pPop, length, false);
}

void test5()
{
	const int length = 1;
	int pPush[length] = { 1 };
	int pPop[length] = { 1 };
	test("Test5", pPush, pPop, length, true);
}

void test6()
{
	test("Test6", NULL, NULL, 0, false);
}


int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}

