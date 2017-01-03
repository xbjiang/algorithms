// 24_SequenceOfBST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

bool VerifySequenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
		return false;

	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > sequence[length - 1])
			break;
	}

	for (int j = i; j < length - 1; j++)
	{
		if (sequence[j] < sequence[length - 1])
			return false;
	}

	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(sequence, i);

	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}

void test(char* testname, int sequence[], int length, bool expected)
{
	printf("%s begins: ", testname);
	if (VerifySequenceOfBST(sequence, length) == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void test1()
{
	int sequence[] = {4,8,6,12,16,14,10};
	test("Test1", sequence, sizeof(sequence)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void test2()
{
	int sequence[] = {4,6,7,5};
	test("Test2", sequence, sizeof(sequence)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void test3()
{
	int sequence[] = {1,2,3,4,5};
	test("Test3", sequence, sizeof(sequence)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void test4()
{
	int sequence[] = {5,4,3,2,1};
	test("Test4", sequence, sizeof(sequence)/sizeof(int), true);
}

void test5()
{
	int sequence[] = {1};
	test("Test5", sequence, sizeof(sequence)/sizeof(int), true);
}

void test6()
{
	int data[] = { 7, 4, 6, 5 };
	test("Test6", data, sizeof(data) / sizeof(int), false);
}

void test7()
{
	int data[] = { 4, 6, 12, 8, 16, 14, 10 };
	test("Test7", data, sizeof(data) / sizeof(int), false);
}

void test8()
{
	test("Test8", NULL, 0, false);
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
	test8();
	return 0;
}

