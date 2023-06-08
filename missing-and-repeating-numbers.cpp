#include <iostream>
using namespace std;
#include <algorithm>
#include<vector>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int m, r;
	
	for(int i = 0; i < n; i += 1)
	{
		if( arr[abs(arr[i]) - 1] > 0 )
		{
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
		else  		
		{
			r = abs(arr[i]);
		}
	}
	
	
	for(int i = 0; i < n; i += 1)
	{
		if( arr[i] > 0 )
		{
			m = i + 1;
			break;
		}
	}
	
	pair<int, int>ans;
	
	ans.first = m;
	ans.second = r;
	
	return ans;
	 
}
