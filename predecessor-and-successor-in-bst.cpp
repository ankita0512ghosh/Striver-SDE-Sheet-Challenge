#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = -1;
    int successor = -1;

    while (root -> data != key)
    {
        if (key > root -> data)
        {
            predecessor = root -> data;
            root = root -> right;
        }
        else
        {
            successor = root -> data;
            root = root -> left;
        }
    }

    
    BinaryTreeNode<int>* rightSubtree = root -> right;

    while (rightSubtree != NULL)
    {
        successor = rightSubtree -> data;
        rightSubtree = rightSubtree -> left;
    }


    BinaryTreeNode<int>* leftSubtree = root -> left;

    while (leftSubtree != NULL)
    {
        predecessor = leftSubtree -> data;
        leftSubtree = leftSubtree -> right;
    }

    return {predecessor, successor};
}
