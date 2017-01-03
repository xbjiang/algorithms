#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

__declspec(dllexport) ListNode* CreateListNode(int value);
__declspec(dllexport) void ConnectListNodes(ListNode* pNode1, ListNode* pNode2);
__declspec(dllexport) ListNode* CreateList(int* arr, int n);
__declspec(dllexport) void PrintList(ListNode* pHead);
__declspec(dllexport) void DestroyList(ListNode* pHead);
