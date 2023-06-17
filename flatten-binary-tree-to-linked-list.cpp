#include <iostream>
using namespace std;
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *currentNode = root;

    while (currentNode != NULL)
    {
        if (currentNode->left != NULL)
        {
            TreeNode<int> *predecessor = currentNode->left;

            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            predecessor->right = currentNode->right;
            currentNode->right = currentNode->left;

            currentNode->left = NULL;
        }
        currentNode = currentNode->right;
    }

    return root;
}
