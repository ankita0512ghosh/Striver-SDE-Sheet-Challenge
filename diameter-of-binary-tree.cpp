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

int getDiameter(TreeNode<int> *root, int &height)
{
    if (root == NULL)
    {
        height = 0;
        return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;

    int leftDiameter = getDiameter(root->left, leftHeight);

    int rightDiameter = getDiameter(root->right, rightHeight);

    height = max(leftHeight, rightHeight) + 1;

    int diameter = max(leftDiameter, max(rightDiameter, leftHeight + rightHeight));

    return diameter;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int height = 0;

    return getDiameter(root, height);
}

