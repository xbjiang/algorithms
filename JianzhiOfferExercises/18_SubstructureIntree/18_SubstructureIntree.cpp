// 18_SubstructureIntree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/BinaryTreeNode.h"

bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		result = DoesTree1HasTree2(pRoot1, pRoot2);

		if (!result)
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);

		if (!result)
			result = HasSubtree(pRoot1->m_pRight, pRoot2);
	}
	return result;
}

bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{ 
	if (pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
		DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

void test(char* testname, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
	bool result = HasSubtree(pRoot1, pRoot2);
	if (result == expected)
		printf("%s passed!\n", testname);
	else
		printf("%s failed!\n", testname);
}

//树B是树A的子树
//               8                  8
//             /   \               / \
//            8     7             9   2
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

	BinaryTreeNode* b11 = CreateBinaryTreeNode(8);
	BinaryTreeNode* b21 = CreateBinaryTreeNode(9);
	BinaryTreeNode* b22 = CreateBinaryTreeNode(2);

	connectBinaryTreeNode(b11, b21, b22);
	
	test("Test1", a11, b11, true);

	destroyTree(a11);
	destroyTree(b11);
}

//树B不是树A的子树
//               8                  8
//             /   \               / \
//            8     7             9   3
//           / \
//          9   2
//             / \
//            4   7
void test2()
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

	BinaryTreeNode* b11 = CreateBinaryTreeNode(8);
	BinaryTreeNode* b21 = CreateBinaryTreeNode(9);
	BinaryTreeNode* b22 = CreateBinaryTreeNode(3);

	connectBinaryTreeNode(b11, b21, b22);

	test("Test2", a11, b11, false);

	destroyTree(a11);
	destroyTree(b11);
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	return 0;
}

