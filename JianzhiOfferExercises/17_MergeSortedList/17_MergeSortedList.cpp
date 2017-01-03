// 17_MergeSortedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/List.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* pDummyHead = CreateListNode(0);
	ListNode* pCurrent = pDummyHead;

	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->m_nValue < pHead2->m_nValue)
		{
			pCurrent->m_pNext = pHead1;
			pCurrent = pCurrent->m_pNext;
			pHead1 = pHead1->m_pNext;
		}
		else
		{
			pCurrent->m_pNext = pHead2;
			pCurrent = pCurrent->m_pNext;
			pHead2 = pHead2->m_pNext;
		}
	}

	if (pHead1 != NULL)
		pCurrent->m_pNext = pHead1;

	if (pHead2 != NULL)
		pCurrent->m_pNext = pHead2;

	pCurrent = pDummyHead->m_pNext;
	delete pDummyHead;
	pDummyHead = NULL;
	
	return pCurrent;
}

ListNode* Merge_Recursively(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pMergedHead = NULL;

	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergedHead = pHead1;
		pMergedHead->m_pNext = Merge_Recursively(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->m_pNext = Merge_Recursively(pHead1, pHead2->m_pNext);
	}
	return pMergedHead;
}

void test(ListNode* pHead1, ListNode* pHead2)
{
	printf("The first list is: ");
	PrintList(pHead1);
	printf("\n");

	printf("The second list is: ");
	PrintList(pHead2);
	printf("\n");

	//ListNode* pMerged = Merge(pHead1, pHead2);
	ListNode* pMerged = Merge_Recursively(pHead1, pHead2);
	printf("The merged list is: ");
	PrintList(pMerged);
	printf("\n");

	DestroyList(pMerged);
}

void test1()
{
	printf("Test1 begins:\n");
	
	int arr1[5] = {1,3,5,7,9};
	int arr2[5] = {2,4,6,8,10};
	
	ListNode* pHead1 = CreateList(arr1, 5);
	ListNode* pHead2 = CreateList(arr2, 5);
	test(pHead1, pHead2);

}

void test2()
{
	printf("Test2 begins:\n");

	int arr1[5] = { 1, 3, 5, 6, 7 };
	int arr2[5] = { 2, 4, 8, 9, 10 };

	ListNode* pHead1 = CreateList(arr1, 5);
	ListNode* pHead2 = CreateList(arr2, 5);
	test(pHead1, pHead2);

}

void test3()
{
	printf("Test3 begins:\n");

	int arr1[3] = { 1, 3, 5 };
	int arr2[5] = { 2, 4, 6, 8, 10 };

	ListNode* pHead1 = CreateList(arr1, 3);
	ListNode* pHead2 = CreateList(arr2, 5);
	test(pHead1, pHead2);

}

void test4()
{
	printf("Test4 begins:\n");

	int arr1[5] = { 1, 3, 5, 7, 9 };
	

	ListNode* pHead1 = CreateList(arr1, 5);
	
	test(pHead1, NULL);

}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}

