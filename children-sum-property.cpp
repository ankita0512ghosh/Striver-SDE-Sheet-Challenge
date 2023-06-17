#include <iostream>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int> *root) {

    // Base Cases.
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        return;
    }

    // Calculate the difference between the root and its children.
    int difference = root->data - ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));

    /*
        if the differnce is positive, increment either
        left or right child node.
    */
    if (difference > 0) {
        if (root->left) {
            root->left->data += difference;
        }
        else {
            root->right->data += difference;
        }
    }

    // Call this function again for the left and right subtree.
    changeTree(root->left);
    changeTree(root->right);

    // Update root with the sum of the left and right child's data.
    root->data =  ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));
}