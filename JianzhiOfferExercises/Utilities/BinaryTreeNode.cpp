#include "stdafx.h"
#include "BinaryTreeNode.h"
#include <algorithm>

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;

	return pNode;
}

void connectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent == NULL)
	{
		printf("Parent node can't be NULL");
		exit(1);
	}

	pParent->m_pLeft = pLeft;
	pParent->m_pRight = pRight;
}

void destroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		destroyTree(pLeft);
		destroyTree(pRight);
	}
}


void printTree(BinaryTreeNode* pRoot)
{
	int maxLevel = getMaxLevel(pRoot);
	std::vector<BinaryTreeNode*> nodes;
	nodes.push_back(pRoot);

	printTreeInternal(nodes, 1, maxLevel);

}

void printTreeInternal(std::vector<BinaryTreeNode*> nodes, int level, int maxLevel)
{
	if (nodes.empty() || isAllElementsNull(nodes))
		return;
	
	int floor = maxLevel - level;
	int edgeLines = (int) pow(2, max(floor - 1, 0));
	int firstSpaces = (int) pow(2, floor) - 1;
	int betweenSpaces = (int)pow(2, floor + 1) - 1;

	printWhiteSpaces(firstSpaces);

	std::vector<BinaryTreeNode*> newNodes;
	for (auto node : nodes)
	{
		if (node != NULL)
		{
			printf("%d", node->m_nValue);
			newNodes.push_back(node->m_pLeft);
			newNodes.push_back(node->m_pRight);
		}
		else
		{
			newNodes.push_back(NULL);
			newNodes.push_back(NULL);
			printf(" ");
		}
		printWhiteSpaces(betweenSpaces);
	}
	printf("\n");

	for (int i = 1; i <= edgeLines; i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			printWhiteSpaces(firstSpaces - i);
			if (nodes[j] == NULL)
			{
				printWhiteSpaces(2*edgeLines+i+1);
				continue;
			}

			if (nodes[j]->m_pLeft != NULL)
				printf("/");
			else
				printf(" ");

			printWhiteSpaces(2*i-1);

			if (nodes[j]->m_pRight != NULL)
				printf("\\");
			else
				printf(" ");

			printWhiteSpaces(2*edgeLines-i);
		}
		printf("\n");
	}

	printTreeInternal(newNodes, level+1, maxLevel);

}

void printWhiteSpaces(int count)
{
	for (int i = 0; i < count; i++)
		printf(" ");
}

int getMaxLevel(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
		return 0;

	return max(getMaxLevel(pNode->m_pLeft), getMaxLevel(pNode->m_pRight)) + 1;
}

bool isAllElementsNull(std::vector<BinaryTreeNode*> nodes)
{
	for (auto node : nodes)
	{
		if (node != NULL)
			return false;
	}

	return true;
}