#include <iostream>
#include <vector>
using namespace std;
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> output;

    if (root == NULL)
    {
        return output;
    }

    queue<BinaryTreeNode<int> *> level;

    level.push(root);

    while (!level.empty())
    {
        int levelSize = level.size();

        while (levelSize != 0)
        {
            BinaryTreeNode<int> *curr = level.front();
            level.pop();

            output.push_back(curr->val);

            if (curr->left != NULL)
            {
                level.push(curr->left);
            }

            if (curr->right != NULL)
            {
                level.push(curr->right);
            }
            levelSize = levelSize - 1;
        }
    }

    return output;
}
