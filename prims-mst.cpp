#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <limits.h>
#include <queue>

vector<pair<pair<int, int>,int>> primsMST(vector<pair<int, int>> *adjList, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int src = 0;

	int *weight = new int[n];

	int *parent = new int[n];

	bool *inMST = new bool[n];
	for (int i = 0; i < n; i++)
	{
		weight[i] = INT_MAX;
		parent[i] = -1;
		inMST[i] = false;
	}
	inMST[src] = true;

	pq.push(make_pair(0, src));

	weight[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		inMST[u] = true;

		for (auto x : adjList[u])
		{
			int v = x.first;
			int wt = x.second;

			if (!inMST[v] && weight[v] > wt)
			{
				weight[v] = wt;

				pq.push(make_pair(weight[v], v));

				parent[v] = u;
			}
		}
	}

	delete[] adjList;

	vector<pair<pair<int, int>, int>> result;

	for (int i = 1; i < n; i++)
	{
		result.push_back({{min(parent[i]+1, i+1),max(parent[i]+1, i+1)}, weight[i]});
	}

	return result;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
	
	vector<pair<int, int>> *adjList = new vector<pair<int, int>>[n];

	for (int i = 0; i < m; i++)
	{
		adjList[g[i].first.first-1].push_back(make_pair(g[i].first.second-1, g[i].second));
		adjList[g[i].first.second-1].push_back(make_pair(g[i].first.first-1, g[i].second));
	}

	return primsMST(adjList, n);
}

