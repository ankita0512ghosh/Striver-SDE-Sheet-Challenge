#include <iostream>
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

int helperMethod(BinaryTreeNode<int>* root){
    if(!root){
        return 0;
    }

    int leftValue = helperMethod(root->left);
    int rightValue = helperMethod(root->right);

    if(leftValue == -1 or rightValue == -1){
        return -1;
    }

    if(abs(leftValue-rightValue) <= 1){
        return max(leftValue, rightValue)+1;
    }

    return -1;
}

bool isBalancedBT(BinaryTreeNode<int>* root){
    if(!root){
        return true;
    }

    if (helperMethod(root) != -1){
        return true;
    }
    else{
        return false;
    }
}