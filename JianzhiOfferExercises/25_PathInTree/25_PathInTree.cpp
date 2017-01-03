// 25_PathInTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include "../Utilities/BinaryTreeNode.h"

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& Path, int& currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == NULL)
		return;

	int currentSum = 0;
	std::vector<int> Path;
	FindPath(pRoot, expectedSum, Path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& Path, int& currentSum)
{
	Path.push_back(pRoot->m_nValue);
	currentSum += pRoot->m_nValue;

	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf)
	{
		std::vector<int>::const_iterator itr = Path.cbegin();
		for (; itr != Path.cend(); itr++)
		{
			printf("%d ", *itr);
		}
		printf("\n");
	}

	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, Path, currentSum);

	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, Path, currentSum);

	currentSum -= pRoot->m_nValue;
	Path.pop_back();
}

void Test(char* testname, BinaryTreeNode* pRoot, int expectedSum)
{
	if (testname != NULL)
		printf("%s begins: \n", testname);

	FindPath(pRoot, expectedSum);
	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	connectBinaryTreeNode(pNode10, pNode5, pNode12);
	connectBinaryTreeNode(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test1.\n");
	Test("Test1", pNode10, 22);

	destroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void Test2()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	connectBinaryTreeNode(pNode10, pNode5, pNode12);
	connectBinaryTreeNode(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test2.\n");
	Test("Test2", pNode10, 15);

	destroyTree(pNode10);
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
// 有一条路径上面的结点和为15
void Test3()
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

	printf("One path should be found in Test3.\n");
	Test("Test3", pNode5, 15);

	destroyTree(pNode5);
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
// 没有路径上面的结点和为16
void Test4()
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

	printf("No paths should be found in Test4.\n");
	Test("Test4", pNode1, 16);

	destroyTree(pNode1);
}

// 树中只有1个结点
void Test5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	printf("One path should be found in Test5.\n");
	Test("Test5", pNode1, 1);

	destroyTree(pNode1);
}

// 树中没有结点
void Test6()
{
	printf("No paths should be found in Test6.\n");
	Test("Test6", NULL, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	return 0;
}

