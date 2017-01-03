// 13_DeleteNodeInList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/List.h"

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (pHead == NULL || (*pHead) == NULL || pToBeDeleted == NULL)
		return;

	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		
		delete pNext;
		pNext = NULL;
	}
	else if (pToBeDeleted == *pHead)
	{
		delete (*pHead);
		*pHead = NULL;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

void test(ListNode** pHead, ListNode* pToBeDeleted)
{
	printf("The original list is:\n");
	PrintList(*pHead);
	printf("\n");
	
	printf("The node to be deleted is: %d\n", pToBeDeleted->m_nValue);
	DeleteNode(pHead, pToBeDeleted);
	
	printf("The current list is:\n");
	PrintList(*pHead);
	printf("\n");
}

void test1()
{
	printf("Test1 begins:\n");
	int arr[5] = {1,2,3,4,5};
	ListNode* pHead = CreateList(arr, 5);
	ListNode* pToBeDeleted = pHead->m_pNext;
	test(&pHead, pToBeDeleted);
	DestroyList(pHead);
}

void test2()
{
	printf("Test2 begins:\n");
	int arr[5] = { 1, 2, 3, 4, 5 };
	ListNode* pHead = CreateList(arr, 5);
	ListNode* pNode = pHead;
	while (pNode->m_pNext != NULL)
		pNode = pNode->m_pNext;
	test(&pHead, pNode);
	DestroyList(pHead);
}

void test3()
{
	printf("Test3 begins:\n");
	ListNode* pHead = CreateListNode(1);
	test(&pHead, pHead);
	DestroyList(pHead);
}

void test4()
{
	printf("Test4 begins:\n");
	int arr[5] = { 1, 2, 3, 4, 5 };
	ListNode* pHead = CreateList(arr, 5);
	ListNode* pToBeDeleted = pHead;
	test(&pHead, pToBeDeleted);
	DestroyList(pHead);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}

