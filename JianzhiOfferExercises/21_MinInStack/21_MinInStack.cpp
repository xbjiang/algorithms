// 21_MinInStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "StackWithMin.h"

void test(char* testname, const StackWithMin<int>& stack, int expected)
{
	if (testname != NULL)
		printf("%s begins:\n", testname);

	if (stack.min() == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	StackWithMin<int> stack;
	
	stack.push(3);
	test("Test1", stack, 3);

	stack.push(4);
	test("Test2", stack, 3);

	stack.push(2);
	test("Test3", stack, 2);

	stack.push(3);
	test("Test4", stack, 2);

	stack.pop();
	test("Test5", stack, 2);

	stack.pop();
	test("Test6", stack, 3);

	stack.pop();
	test("Test7", stack, 3);

	stack.push(1);
	test("Test8", stack, 1);



	return 0;
}

