#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
	int height;
	int leftIndex;
	int rightIndex;
} 
Node;

#include <queue>

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	queue<Node> q;
	Node init;

	init.height = 0;
	init.leftIndex = 0;
	init.rightIndex = N - 1;

	q.push(init);
      
	int pos[N+1];

	for(int i = 0; i < N; i++){
		pos[inorder[i]] = i;
	}

	int maxHeight = 0;

	for(int i = 0; i < N; i++){
		int curr = levelOrder[i];

		Node now = q.front();

		q.pop();

		int currPos = pos[levelOrder[i]];
		
		if(currPos > now.leftIndex){
			Node newNode;

			newNode.height = now.height + 1;

			maxHeight = max(maxHeight, newNode.height);

			newNode.leftIndex = now.leftIndex;
			newNode.rightIndex = currPos - 1;

			q.push(newNode);
		}

		if(currPos < now.rightIndex){
			Node newNode;
			newNode.height = now.height + 1;
			maxHeight = max(maxHeight, newNode.height);

			newNode.leftIndex = currPos + 1;
			newNode.rightIndex = now.rightIndex;

			q.push(newNode);
		}
	}

	return maxHeight;
}