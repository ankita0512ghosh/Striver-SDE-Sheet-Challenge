#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root) {
    BinaryTreeNode<int> *startNode = root;

    while(startNode != NULL) {

        BinaryTreeNode<int> *ptr = startNode;
        BinaryTreeNode<int> *previous = NULL;
        startNode = NULL;
        
        while(ptr != NULL) {

            if(ptr->left != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->left;
                }

                if(startNode == NULL) {
                    startNode = ptr->left;
                }

                previous = ptr->left;
            }

            if(ptr->right != NULL) {

                if(previous != NULL) {
                    previous->next = ptr->right;
                }

                if(startNode == NULL) {
                    startNode = ptr->right;
                }

                previous = ptr->right;
            }

            ptr = ptr->next;
        }
    }
}