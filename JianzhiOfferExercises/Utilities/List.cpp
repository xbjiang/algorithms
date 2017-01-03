#include "stdafx.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;

	return pNode;
}

void ConnectListNodes(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode1 == NULL)
	{
		printf("The first node can't be NULL");
		exit(1);
	}

	if (pNode2 != NULL)
		pNode1->m_pNext = pNode2;
}

ListNode* CreateList(int* arr, int n)
{
	if (arr == NULL || n <= 0)
		return NULL;

	ListNode* pHead = CreateListNode(arr[0]);
	ListNode* pCurrent = pHead;
	ListNode* pNext;

	for (int i = 1; i < n; i++)
	{
		pNext = CreateListNode(arr[i]);
		ConnectListNodes(pCurrent, pNext);
		pCurrent = pNext;
	}

	return pHead;

}

void PrintList(ListNode* pHead)
{
	if (pHead == NULL)
		return;

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
		
}

void DestroyList(ListNode* pHead)
{
	
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
	
}