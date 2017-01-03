#pragma once 
#include <vector>

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*     m_pLeft;
	BinaryTreeNode*		m_pRight;
};

__declspec(dllexport) BinaryTreeNode* CreateBinaryTreeNode(int value);
__declspec(dllexport) void connectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
__declspec(dllexport) void printTree(BinaryTreeNode* pRoot);
__declspec(dllexport) void destroyTree(BinaryTreeNode* pRoot);
void printTreeInternal(std::vector<BinaryTreeNode*> nodes, int level, int maxLevel);
void printWhiteSpaces(int count);
int getMaxLevel(BinaryTreeNode* pNode);
bool isAllElementsNull(std::vector<BinaryTreeNode*> nodes);
