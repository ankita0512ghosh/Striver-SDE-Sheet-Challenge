#include <iostream>
using namespace std;
/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool checkSymmetricity(BinaryTreeNode<int>* firstRoot, BinaryTreeNode<int>* secondRoot)
{
    if(firstRoot == NULL && secondRoot == NULL)
    {
        return true;
    }
    if( (firstRoot == NULL && secondRoot != NULL) || (firstRoot != NULL && secondRoot == NULL) )
    {
        return false;
    }
    if(firstRoot->data != secondRoot->data)
    {
        return false;
    }
    return checkSymmetricity(firstRoot->right, secondRoot->left) && checkSymmetricity(firstRoot->left, secondRoot->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return checkSymmetricity(root, root); 
}