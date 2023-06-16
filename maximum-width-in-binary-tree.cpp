#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode<int> *> q;
    q.push(root);

    int maxWidth = 0;
    while (q.empty() == false)
    {
        int currWidth = q.size();
        if (maxWidth < currWidth)
        {
            maxWidth = currWidth;
        }
        while (currWidth > 0)
        {
            TreeNode<int> *currNode = q.front();
            q.pop();
            if (currNode->left != NULL)
            {
                q.push(currNode->left);
            }
            if (currNode->right != NULL)
            {
                q.push(currNode->right);
            }

            currWidth = currWidth - 1;
        }
    }

    return maxWidth;
}