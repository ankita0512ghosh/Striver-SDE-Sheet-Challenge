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
vector<int> getPreOrderTraversal(TreeNode *root)
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
        if (current->left == NULL)
        {
            answer.push_back(current->data);

            current = current->right;
        }
        else
        {
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == current)
            {
                predecessor->right = NULL;
                current = current->right;
            }

            else
            {
                answer.push_back(current->data);

                predecessor->right = current;

                current = current->left;
            }
        }
    }

    return answer;
}