#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<climits>

TreeNode<int>* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    if (currNode > startRange && currNode < endRange){
        TreeNode<int>* root = new TreeNode<int>(currNode);

        preIndex += 1;

        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

        return root;
    }

    return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int preIndex = 0;

    return util(preOrder, preIndex, INT_MIN, INT_MAX);
}