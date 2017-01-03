// 23_PrintTreeFromTopToBottom.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/BinaryTreeNode.h"
#include <vector>

void PrintCore(std::vector<BinaryTreeNode*>& currentLevel);

void PrintTreeLevelwisely(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		std::vector<BinaryTreeNode*> firstLevel;
		firstLevel.push_back(pRoot);

		PrintCore(firstLevel);
	}
}

void PrintCore(std::vector<BinaryTreeNode*>& currentLevel)
{
	if (currentLevel.empty())
		return;

	std::vector<BinaryTreeNode*> nextLevel;

	for (const auto node : currentLevel)
	{
		printf("%d ", node->m_nValue);
		
		if (node->m_pLeft)
			nextLevel.push_back(node->m_pLeft);
		
		if (node->m_pRight)
			nextLevel.push_back(node->m_pRight);
	}
	printf("\n");

	PrintCore(nextLevel);
}

void test(char* testname, BinaryTreeNode* pRoot)
{
	printf("%s begins: \n", testname);
	PrintTreeLevelwisely(pRoot);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16

void test1()
{
	BinaryTreeNode* n11 = CreateBinaryTreeNode(10);
	BinaryTreeNode* n21 = CreateBinaryTreeNode(6);
	BinaryTreeNode* n22 = CreateBinaryTreeNode(14);
	BinaryTreeNode* n31 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n32 = CreateBinaryTreeNode(8);
	BinaryTreeNode* n33 = CreateBinaryTreeNode(12);
	BinaryTreeNode* n34 = CreateBinaryTreeNode(16);

	connectBinaryTreeNode(n11, n21, n22);
	connectBinaryTreeNode(n21, n31, n32);
	connectBinaryTreeNode(n22, n33, n34);

	test("Test1", n11);

	destroyTree(n11);
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
void test2()
{
	BinaryTreeNode* n1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* n2 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* n4 = CreateBinaryTreeNode(2);
	BinaryTreeNode* n5 = CreateBinaryTreeNode(1);
	

	connectBinaryTreeNode(n1, n2, NULL);
	connectBinaryTreeNode(n2, n3, NULL);
	connectBinaryTreeNode(n3, n4, NULL);
	connectBinaryTreeNode(n4, n5, NULL);

	test("Test2", n1);

	destroyTree(n1);
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
void test3()
{
	BinaryTreeNode* n1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* n2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* n3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* n4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n5 = CreateBinaryTreeNode(5);


	connectBinaryTreeNode(n1, NULL, n2);
	connectBinaryTreeNode(n2, NULL, n3);
	connectBinaryTreeNode(n3, NULL, n4);
	connectBinaryTreeNode(n4, NULL, n5);

	test("Test3", n1);

	destroyTree(n1);
}

void test4()
{
	BinaryTreeNode* pNode = CreateBinaryTreeNode(1);
	test("Test4", pNode);

	destroyTree(pNode);
}

void test5()
{
	test("Test5", NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}

