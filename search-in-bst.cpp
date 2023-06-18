#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*
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
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *ptr = root;
    
    while(ptr != NULL) {
        if(ptr->data == x) {
            return true;
        } else if(ptr->data > x) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;   
        }
    }

    return false;
}