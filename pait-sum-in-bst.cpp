/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#include<unordered_set>

bool helper(BinaryTreeNode<int> *root, int k, unordered_set<int> &hashSet)
{
    if (root == NULL)
    {
        return false;
    }

    if (hashSet.count(k - root->data))
    {
        return true;
    }

    hashSet.insert(root -> data);

    return (helper(root -> left, k, hashSet) || helper(root -> right, k, hashSet));
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> hashSet;
    
    return helper(root, k, hashSet);
}