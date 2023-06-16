#include <iostream>
#include <queue>
#include <vector>
using namespace std;  
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


bool isPresent(TreeNode<int> *temp, int x, vector<int> &ans)
{
    if (temp == NULL)
    {
        return false;
    }
    if (temp->data == x)
    {
        return true;
    }
    if (isPresent(temp->left, x, ans))
    {
        ans.push_back(temp->left->data);
        return true;
    }
    if (isPresent(temp->right, x, ans))
    {
        ans.push_back(temp->right->data);
        return true;
    }
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;

    isPresent(root, x, ans);
    ans.push_back(root->data);
    reverse(ans.begin(), ans.end());
    return ans;
}
