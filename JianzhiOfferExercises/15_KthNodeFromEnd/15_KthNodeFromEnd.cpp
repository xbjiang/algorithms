// 15_KthNodeFromEnd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/List.h"
#include <stdlib.h>

ListNode* FindKthToTail(ListNode* pHead, int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;

	ListNode* pFirst = pHead;
	ListNode* pSecond = pHead;

	for (int i = 1; i < k; i++)
	{
		pFirst = pFirst->m_pNext;
		if (pFirst == NULL)
		{
			printf("The number of nodes in the list is less than %d!", k);
			exit(1);
		}
	}

	while (pFirst->m_pNext != NULL)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}

	return pSecond;
}

void test(int arr[], int n, int k)
{
	ListNode* pHead = CreateList(arr, n);
	printf("The list is: ");
	PrintList(pHead);
	printf("\n");

	ListNode* pFound = FindKthToTail(pHead, k);

	printf("The node to be found: %d\n", arr[n-k]);
	printf("Found node:%d\n", pFound->m_nValue);

	DestroyList(pHead);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[5] = {1,2,3,4,5};
	test(arr, 5, 1);
	test(arr, 5, 2);
	test(arr, 5, 5);
	test(arr, 5, 6);
	return 0;
}

