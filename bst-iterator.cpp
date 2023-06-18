#include <bits/stdc++.h> 
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
#include <stack>

class BSTiterator
{
public:
    stack<TreeNode<int> *> st;

    BSTiterator(TreeNode<int> *root)
    {
        leftMostInorder(root);
    }

    int next()
    {
        TreeNode<int> *top = st.top();
        st.pop();
        
        if (top->right != NULL)
        {
            leftMostInorder(top->right);
        }
        return top->data;
    }

    bool hasNext()
    {
        if (st.size() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void leftMostInorder(TreeNode<int> *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};