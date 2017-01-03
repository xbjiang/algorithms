// 07_QueueWithTwoStacks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Queue.h"

void test(char actual, char expected)
{
	if (actual == expected)
		printf("Passed!\n");
	else
		printf("Failed!\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	test('a', head);

	queue.appendTail('d');
	queue.appendTail('e');

	head = queue.deleteHead();
	test('b', head);

	head = queue.deleteHead();
	test('c', head);
	
	head = queue.deleteHead();
	test('d', head);

	head = queue.deleteHead();
	test('e', head);

	return 0;
}

