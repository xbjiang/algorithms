// 27_ConvertBSTToList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/BinaryTreeNode.h"

void Convert(BinaryTreeNode* & pPrev, BinaryTreeNode* pCurrent);

BinaryTreeNode* ConvertBSTToList(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return NULL;

	BinaryTreeNode* pPrev = NULL;
	BinaryTreeNode* pCurrent = pRoot;

	Convert(pPrev, pCurrent);

	while (pPrev->m_pLeft != NULL)
		pPrev = pPrev->m_pLeft;

	return pPrev;
}

void Convert(BinaryTreeNode* & pPrev, BinaryTreeNode* pCurrent)
{
	if (pCurrent->m_pLeft != NULL)
		Convert(pPrev, pCurrent->m_pLeft);

	if (pPrev != NULL)
		pPrev->m_pRight = pCurrent;
	pCurrent->m_pLeft = pPrev;
	pPrev = pCurrent;
	
	if (pCurrent->m_pRight != NULL)
		Convert(pPrev, pCurrent->m_pRight);
}

void DestroyDoubleList(BinaryTreeNode* pHead)
{

	BinaryTreeNode* pNode = pHead;
	while (pNode != NULL)
	{
		pNode = pNode->m_pRight;
		delete pHead;
		pHead = pNode;
	}

}

void PrintDoubleList(BinaryTreeNode* pHead)
{
	if (pHead == NULL)
		return;

	BinaryTreeNode* pNode = pHead;
	printf("Double list from left to right: \n");
	while (pNode->m_pRight != NULL)
	{
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pRight;
	}
	printf("%d\n", pNode->m_nValue);

	printf("Double list from right to left:\n");
	while (pNode != NULL)
	{
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pLeft;
	}
	printf("\n");
}

void Test(char* testname, BinaryTreeNode* pRoot)
{
	if (testname != NULL)
		printf("%s begins:\n", testname);

	BinaryTreeNode* pHead = ConvertBSTToList(pRoot);
	PrintDoubleList(pHead);
	DestroyDoubleList(pHead);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	connectBinaryTreeNode(pNode10, pNode6, pNode14);
	connectBinaryTreeNode(pNode6, pNode4, pNode8);
	connectBinaryTreeNode(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);

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
void Test2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	connectBinaryTreeNode(pNode5, pNode4, NULL);
	connectBinaryTreeNode(pNode4, pNode3, NULL);
	connectBinaryTreeNode(pNode3, pNode2, NULL);
	connectBinaryTreeNode(pNode2, pNode1, NULL);

	Test("Test2", pNode5);

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
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	connectBinaryTreeNode(pNode1, NULL, pNode2);
	connectBinaryTreeNode(pNode2, NULL, pNode3);
	connectBinaryTreeNode(pNode3, NULL, pNode4);
	connectBinaryTreeNode(pNode4, NULL, pNode5);

	Test("Test3", pNode1);

}

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1);

}

// 树中没有结点
void Test5()
{
	Test("Test5", NULL);
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}

