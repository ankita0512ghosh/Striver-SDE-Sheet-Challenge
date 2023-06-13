#include <iostream>
#include <vector>
using namespace std; 

int chessTournament( vector<int> &positions, int n , int c) 
{
	sort(positions.begin(),positions.end());   
	
	int ans=0 , l=1 , r = positions[n-1]; 
	
	while(l<=r)
    { 
		int mid=(l+r)/2; 
		
        int count=1 , previousRoom=positions[0]; 
        
		for(int i = 1 ; i < n ; i++) 
        {
			if(positions[i]-previousRoom >= mid) 
            {  
				count++;
				previousRoom=positions[i];
			}
		}

		if(count >= c)
        { 
			ans=mid;
			l=mid+1;
		}

		else 
        {  
			r=mid-1;
		}
	}
 
	return ans;
}



