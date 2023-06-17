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
int findLCA(TreeNode<int> *root, int x, int y)
{

	if (root == NULL)
	{
		return -1;
	}
	else if (root->data == x || root->data == y)
	{
		return root->data;
	}
	else
	{
		int leftLCA = findLCA(root->left, x, y);

		int rightLCA = findLCA(root->right, x, y);

		if (leftLCA != -1 && rightLCA != -1)
		{
			return root->data;
		}
		else if (leftLCA != -1)
		{
			return leftLCA;
		}
		else
		{
			return rightLCA;
		}
	}
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	return findLCA(root, x, y);
}