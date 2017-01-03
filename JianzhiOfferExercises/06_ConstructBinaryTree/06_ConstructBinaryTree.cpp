// 06_ConstructBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Utilities/BinaryTreeNode.h"

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	
	int* rootInorder = startInorder;
	while (rootInorder < endInorder && *rootInorder != rootValue)
		rootInorder++;
	if (rootInorder == endInorder && *rootInorder != rootValue)
	{
		printf("Can't find root in the inorder series! Invalid input!\n");
		exit(1);
	}

	BinaryTreeNode* root = CreateBinaryTreeNode(rootValue);

	if (startPreorder == endPreorder)
		return root;

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if (leftLength < endInorder - startInorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}

	return root;

}

//================测试代码==========================
/*
        2
       / \
      /   \
     /     \
    /       \
    7       5
   / \     / \
  /   \   /   \
  2   6   3   6
 / \ / \ / \ / \
 5 8 4 5 8 4 5 8
*/
void testPrintBinaryTree()
{
	printf("testing the printTree() function!\n");

	BinaryTreeNode* root = CreateBinaryTreeNode(2);
	BinaryTreeNode* n11 = CreateBinaryTreeNode(7);
	BinaryTreeNode* n12 = CreateBinaryTreeNode(5);
	BinaryTreeNode* n21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* n22 = CreateBinaryTreeNode(6);
	BinaryTreeNode* n23 = CreateBinaryTreeNode(3);
	BinaryTreeNode* n24 = CreateBinaryTreeNode(6);
	BinaryTreeNode* n31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* n32 = CreateBinaryTreeNode(8);
	BinaryTreeNode* n33 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n34 = CreateBinaryTreeNode(5);
	BinaryTreeNode* n35 = CreateBinaryTreeNode(8);
	BinaryTreeNode* n36 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n37 = CreateBinaryTreeNode(5);
	BinaryTreeNode* n38 = CreateBinaryTreeNode(5);

	connectBinaryTreeNode(root, n11, n12);
	connectBinaryTreeNode(n11, n21, n22);
	connectBinaryTreeNode(n12, n23, n24);
	connectBinaryTreeNode(n21, n31, n32);
	connectBinaryTreeNode(n22, n33, n34);
	connectBinaryTreeNode(n23, n35, n36);
	connectBinaryTreeNode(n24, n37, n38);

	printTree(root);
	destroyTree(root);

}

/*
       2
      / \
     /   \
    /     \
   /       \
   7       5
  / \       \
 /   \       \
 2   6       3    
    / \     /  
    4 5     4 
*/
void testPrintBinaryTree2()
{
	printf("testing the printTree() function!\n");

	BinaryTreeNode* root = CreateBinaryTreeNode(2);
	BinaryTreeNode* n11 = CreateBinaryTreeNode(7);
	BinaryTreeNode* n12 = CreateBinaryTreeNode(5);
	
	BinaryTreeNode* n21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* n22 = CreateBinaryTreeNode(6);
	BinaryTreeNode* n23 = CreateBinaryTreeNode(3);
	
	
	BinaryTreeNode* n33 = CreateBinaryTreeNode(4);
	BinaryTreeNode* n34 = CreateBinaryTreeNode(5);
	
	BinaryTreeNode* n36 = CreateBinaryTreeNode(4);
	

	connectBinaryTreeNode(root, n11, n12);
	connectBinaryTreeNode(n11, n21, n22);
	connectBinaryTreeNode(n12, NULL, n23);
	
	connectBinaryTreeNode(n22, n33, n34);
	connectBinaryTreeNode(n23, n36, NULL);
	

	printTree(root);
	destroyTree(root);

}


//                  1
//                 / \
//                /   \
//               /     \
//              /       \
//              2       3
//             /       / \
//            /       /   \
//            4       5   6
//             \         /
//             7         8
void test1()
{
	int preorder[8] = {1,2,4,7,3,5,6,8};
	int inorder[8] = {4,7,2,1,5,3,8,6};
    
	printf("test1 begins:\n");
	BinaryTreeNode* root = Construct(preorder, inorder, 8);
	printTree(root);
	destroyTree(root);
}

//只有左子树
//                 1
//                /
//               2
//              /
//             3
//            /
//           4
void test2()
{
	int preorder[4] = {1,2,3,4};
	int inorder[4] = {4,3,2,1};

	printf("test2 begins:\n");
	BinaryTreeNode* root = Construct(preorder, inorder, 4);
	printTree(root);
	destroyTree(root);
}

//只有右子树
//  1
//   \
//    2
//     \
//      3
//       \
//        4
void test3()
{
	int preorder[4] = {1,2,3,4};
	int inorder[4] = {1,2,3,4};

	printf("test3 begins:\n");
	BinaryTreeNode* root = Construct(preorder, inorder, 4);
	printTree(root);
	destroyTree(root);
}

//输入空指针
void test4()
{
	printf("test4 begins:\n");
	BinaryTreeNode* root = Construct(NULL, NULL, 0);
	printTree(root);
	destroyTree(root);
}

// 只有一个节点
void test5()
{
	printf("test5 begins:\n");
	int preorder[1] = {2};
	int inorder[1] = {2};

	BinaryTreeNode* root = Construct(preorder, inorder, 1);
	printTree(root);
	destroyTree(root);
}

// 输入的序列不匹配
void test6()
{
	printf("test6 begins:\n");
	int preorder[7] = {1,2,4,5,3,6,7};
	int inorder[7] = {4,2,8,1,6,3,7};

	BinaryTreeNode* root = Construct(preorder, inorder, 7);
	printTree(root);
	destroyTree(root);
}




int _tmain(int argc, _TCHAR* argv[])
{
	testPrintBinaryTree();
	testPrintBinaryTree2();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}

