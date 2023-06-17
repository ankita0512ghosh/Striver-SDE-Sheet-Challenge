#include <vector>
#include <iostream>
using namespace std;
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <unordered_map>

TreeNode<int> *constructTree(int inStart, int inEnd, int &pIndex, unordered_map<int, int> &inorderIndex, vector<int> &preorder)
{
	if (inStart > inEnd)
	{
		return NULL;
	}

	int rootNode = preorder[pIndex];

	pIndex = pIndex + 1;

	TreeNode<int> *root = new TreeNode<int>(rootNode);

	if (inStart == inEnd)
	{
		return root;
	}
	else
	{
		int inIndex = inorderIndex[root->data];

		TreeNode<int> *leftChild = constructTree(inStart, inIndex - 1, pIndex, inorderIndex, preorder);

		TreeNode<int> *rightChild = constructTree(inIndex + 1, inEnd, pIndex, inorderIndex, preorder);

		root->left = leftChild;
		root->right = rightChild;

		return root;
	}
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int, int> inorderIndex;

	for (int i = 0; i < inorder.size(); i++)
	{
		inorderIndex[inorder[i]] = i;
	}

	int pIndex = 0;

	return constructTree(0, inorder.size() - 1, pIndex, inorderIndex, preorder);
}