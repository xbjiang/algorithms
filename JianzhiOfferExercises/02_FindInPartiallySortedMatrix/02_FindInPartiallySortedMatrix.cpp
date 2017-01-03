// 02_FindInPartiallySortedMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>

bool find(int* matrix, int rows, int cols, int number)
{
	if (matrix == NULL || rows <= 0 || cols <= 0)
		//throw std::exception("Invalid input!");
		return false;
	int row = 0;
	int col = cols - 1;
	bool found = false;
	while (row < rows && col >= 0)
	{
		if (number == matrix[row*cols + col])
		{
			found = true;
			break;
		}
			
		else if (number > matrix[row*cols + col])
			row++;
		else
			col--;
	}
	return found;
}

//==========================测试代码===========================
void test(char* testname, int* matrix, int rows, int cols, int number, bool expected)
{
	if (testname != NULL)
		printf("%s begins :\n", testname);
	
	bool found = find(matrix, rows, cols, number);
	
	if (found == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

//要找的数在数组中
// 1	2	8	9
// 2	4	9	12
// 4	7	10	13
// 6	8	11	15
void test1()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, {6, 8, 11, 15} };
	char* testname = "Test1";
	test(testname, (int*)matrix, 4, 4, 7, true);
}

//不在数组中
void test2()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test2";
	test(testname, (int*)matrix, 4, 4, 5, false);
}

//最小的数
void test3()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test3";
	test(testname, (int*)matrix, 4, 4, 1, true);
}

//最大的数
void test4()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test4";
	test(testname, (int*)matrix, 4, 4, 15, true);
}

//比最小的数小
void test5()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test5";
	test(testname, (int*)matrix, 4, 4, 0, false);
}

//比最大的数大
void test6()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test6";
	test(testname, (int*)matrix, 4, 4, 16, false);
}

//鲁棒性测试，输入空指针
void test7()
{
	int matrix[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	char* testname = "Test7";
	test(testname, NULL, 4, 4, 7, false);
}
int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}

