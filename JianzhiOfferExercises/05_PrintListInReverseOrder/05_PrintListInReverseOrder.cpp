// 05_PrintListInReverseOrder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../Utilities/List.h"
#include <stack>

void PrintListReversely_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> Nodes;
	ListNode* pNode = pHead;
	
	while (pNode != NULL)
	{
		Nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (Nodes.size() != 0)
	{
		pNode = Nodes.top();
		printf("%d ", pNode->m_nValue);
		Nodes.pop();
	}
	printf("\n");
}

void PrintListReversely_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		PrintListReversely_Recursively(pHead->m_pNext);
		printf("%d ", pHead->m_nValue);
	}
	
}

//===================���Դ���==================
void test(ListNode* pHead)
{
	printf("Normal order: ");
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	printf("\n");

	printf("Reverse order1: ");
	PrintListReversely_Iteratively(pHead);
	printf("Reverse order2: ");
	PrintListReversely_Recursively(pHead);
	printf("\n");
}

// 1 -> 2 -> 3 -> 4 -> 5

void test1()
{
	printf("test1 begins:\n");
	int arr[5] = {1,2,3,4,5};
	ListNode* list = CreateList(arr, 5);
	test(list);
	DestroyListNode(list);
}

// ֻ��һ��Ԫ��1
void test2()
{
	printf("test2 begins:\n");

	ListNode* list = CreateListNode(1);
	test(list);
	DestroyListNode(list);
}

//�����ָ��
void test3()
{
	printf("test3 begins:\n");
	test(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	return 0;
}

