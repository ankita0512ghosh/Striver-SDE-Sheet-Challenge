#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct info 
{
	bool isValid;
	int size, min, max;
};

info maxSize(TreeNode<int>* currNode, int &maxBST)
{
	if (currNode == NULL)
	{
		return {true, 0, INT_MAX, INT_MIN};
	}


	info left = maxSize(currNode -> left, maxBST);
	info right = maxSize(currNode -> right, maxBST);


	info currInfo;

	currInfo.size = left.size + right.size + 1;
	
	currInfo.isValid = left.isValid & right.isValid;
	
	currInfo.isValid &= (currNode -> data > left.max);
	currInfo.isValid &= (currNode -> data < right.min);
	
	currInfo.min = min(min(left.min, right.min), currNode -> data);
	currInfo.max = max(max(left.max, right.max), currNode -> data);


	if (currInfo.isValid == true)
	{
		maxBST = max(maxBST, currInfo.size);
	}

	return currInfo;
}


int largestBST(TreeNode<int>* root)
{
	int maxBST = 0;

	maxSize(root, maxBST);

	return maxBST;
}