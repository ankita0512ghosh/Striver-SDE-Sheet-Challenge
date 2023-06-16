#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
/************************************************************

    Following is the TreeNode class structure:

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

#include <queue>

void getBreadth(TreeNode<int> *root, int hrDistance, int &minLeft, int &maxRight) {	
	if (root == NULL){
		return;
	}
	getBreadth(root->left, hrDistance - 1, minLeft, maxRight);
	getBreadth(root->right, hrDistance + 1, minLeft, maxRight);
	minLeft = min(minLeft, hrDistance);
	maxRight = max(maxRight, hrDistance);
}

vector<int> getTopView(TreeNode<int> *root) {
	vector<int> topView;
	if (root == NULL) {
		return topView;
	}
	int minLeft = 0, maxRight = 0;
	getBreadth(root, 0, minLeft, maxRight);
	vector<int> visited(maxRight - minLeft + 1, -1);
	int offset = abs(minLeft);
	queue<pair<TreeNode<int> *, int>> level;
	level.push({root, 0});
	while (level.size() != 0) {
		int levelSize = level.size();
		while (levelSize != 0){
			pair<TreeNode<int> *, int> curr = level.front();
			level.pop();
			int hrDistance = curr.second;
			TreeNode<int> *currNode = curr.first;
			if (visited[hrDistance + offset] == -1) {
				visited[hrDistance + offset] = currNode->val;
			}
			if (currNode->left != NULL) {
				level.push({currNode->left, hrDistance - 1});
			}
			if (currNode->right != NULL) {
				level.push({currNode->right, hrDistance + 1});
			}
			levelSize = levelSize - 1;
		}
	}

	for (auto x : visited) {
		if (x != -1) {
			topView.push_back(x);
		}
	}
	return topView;
}