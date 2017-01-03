// 19_MirrorOfBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/BinaryTreeNode.h"
#include <stack>

void Mirror_Recursively(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	BinaryTreeNode* pTemp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTemp;
	pTemp = NULL;
	
	Mirror_Recursively(pRoot->m_pLeft);
	Mirror_Recursively(pRoot->m_pRight);
}

void Mirror_Iteratively(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;

	std::stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);

	while (stackTreeNode.size() > 0)
	{
		BinaryTreeNode* pNode = stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode* temp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = temp;

		if (pNode->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);

		if (pNode->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}
}

void test(char* testname, BinaryTreeNode* pRoot)
{
	printf("%s begins: \n", testname);
	
	printf("The original tree: \n");
	printTree(pRoot);

	printf("The mirror tree: \n");
	//Mirror_Recursively(pRoot);
	Mirror_Iteratively(pRoot);
	printTree(pRoot);

}

//               8                  
//             /   \               
//            8     7              
//           / \
//          9   2
//             / \
//            4   7
void test1()
{
	BinaryTreeNode* a11 = CreateBinaryTreeNode(8);
	BinaryTreeNode* a21 = CreateBinaryTreeNode(8);
	BinaryTreeNode* a22 = CreateBinaryTreeNode(7);
	BinaryTreeNode* a31 = CreateBinaryTreeNode(9);
	BinaryTreeNode* a32 = CreateBinaryTreeNode(2);
	BinaryTreeNode* a41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* a42 = CreateBinaryTreeNode(7);

	connectBinaryTreeNode(a11, a21, a22);
	connectBinaryTreeNode(a21, a31, a32);
	connectBinaryTreeNode(a32, a41, a42);

	test("Test1", a11);

	destroyTree(a11);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	return 0;
}

