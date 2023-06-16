#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> answer;

    if (root == NULL)
    {
        return answer;
    }

    TreeNode *current, *predecessor;

    current = root;

    while (current != NULL)
    {
        if (current->right == NULL)
        {
            answer.push_back(current->data);

            current = current->left;
        }
        else
        {
            predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current)
            {
                predecessor = predecessor->left;
            }
            if (predecessor->left == current)
            {
                predecessor->left = NULL;
                current = current->left;
            }

            else
            {
                answer.push_back(current->data);

                predecessor->left = current;

                current = current->right;
            }
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}