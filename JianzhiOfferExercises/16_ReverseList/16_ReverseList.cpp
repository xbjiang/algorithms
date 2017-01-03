// 16_ReverseList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/List.h"

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ListNode* pPrevious = NULL;
	ListNode* pNode = pHead;
	
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		pNode->m_pNext = pPrevious;
		
		if (pNext == NULL)
			return pNode;
		
		pPrevious = pNode;
		pNode = pNext;
	}

}

ListNode* ReverseList2(ListNode* pHead)
{
	ListNode* pPrevious = NULL;
	ListNode* pNode = pHead;
	ListNode* pReversedHead = NULL;

	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;

		if (pNext == NULL)
			pReversedHead = pNode;

		pNode->m_pNext = pPrevious;

		pPrevious = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}

void test(int* arr, int n)
{
	ListNode* pHead = CreateList(arr, n);
	ListNode* pCopy = CreateList(arr, n);

	printf("The original list is: ");
	PrintList(pHead);
	printf("\n");

	ListNode* pReversedHead = ReverseList(pHead);
	ListNode* pReversedCopy = ReverseList2(pCopy);

	printf("The reversed list1 is: ");
	PrintList(pReversedHead);
	printf("\n");

	printf("The reversed list2 is: ");
	PrintList(pReversedCopy);
	printf("\n");

	DestroyList(pReversedHead);
	DestroyList(pReversedCopy);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[1] = { 1 };
	int arr2[5] = {1,2,3,4,5};
	
	test(arr, 1);
	test(arr2, 5);
	test(NULL, 0);
	return 0;
}

