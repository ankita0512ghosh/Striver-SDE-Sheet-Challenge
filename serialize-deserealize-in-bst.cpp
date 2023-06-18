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
#include <iostream>
#include <queue>
#include <string>
using namespace std;

string serializeTree(TreeNode<int> *root)
{
    string serialized = "";
    queue<TreeNode<int> *> level;
    level.push(root);

    while (level.empty() == false)
    {
        TreeNode<int> *curr = level.front();
        level.pop();
        if (curr != NULL)
        {
            serialized.append(to_string(curr->data));
            serialized.push_back(',');
            level.push(curr->left);
            level.push(curr->right);
        }
        else
        {
            serialized.append("-1,");
        }
    }
    return serialized;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    int ptr = 0;
    string firstVal = "";
    while (ptr < serialized.length() && serialized[ptr] != ',')
    {
        firstVal.push_back(serialized[ptr]);
        ptr++;
    }
    ptr++;
    int val = stoi(firstVal);
    if (val == -1)
    {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(val);

    queue<TreeNode<int> *> level;

    level.push(root);

    while (level.empty() == false)
    {
        TreeNode<int> *curr = level.front();
        level.pop();

        string leftChild = "";

        while (ptr < serialized.length() && serialized[ptr] != ',')
        {
            leftChild.push_back(serialized[ptr]);
            ptr++;
        }
        ptr++;
        string rightChild = "";

        while (ptr < serialized.length() && serialized[ptr] != ',')
        {
            rightChild.push_back(serialized[ptr]);
            ptr++;
        }
        ptr++;

        int leftChildValue = stoi(leftChild);
        int rightChildValue = stoi(rightChild);

        if (leftChildValue != -1)
        {
            TreeNode<int> *leftNode = new TreeNode<int>(leftChildValue);
            curr->left = leftNode;
            level.push(curr->left);
        }

        if (rightChildValue != -1)
        {
            TreeNode<int> *rightNode = new TreeNode<int>(rightChildValue);
            curr->right = rightNode;

            level.push(curr->right);
        }
    }

    return root;
}