#include <iostream>
#include <vector>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

#include <deque>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    vector<int> answer;

    if (root == NULL) {
        return answer;
    }

    deque<BinaryTreeNode<int>*> d;
    d.push_back(root);

    int level = 1;

    while (!d.empty())
    {
        int n = d.size();

        while (n--)
        {
            if (level % 2 == 1)
            {
                BinaryTreeNode<int>* backNode = d.front();
                d.pop_front();
                answer.push_back(backNode->data);

                if (backNode->left != NULL)
                {
                    d.push_back(backNode->left);
                }
                if (backNode->right != NULL)
                {
                    d.push_back(backNode->right);
                }

            }
            else
            {
                BinaryTreeNode<int>* backNode = d.back();
                d.pop_back();
                answer.push_back(backNode->data);

                if (backNode->right != NULL)
                {
                    d.push_front(backNode->right);
                }
                if (backNode->left != NULL)
                {
                    d.push_front(backNode->left);
                }
            }
        }

        level++;
    }
    return answer;
}
