#include <iostream>
using namespace std;
#include <vector>
int findDuplicate(vector<int> &arr, int n)
{

    for(int i = 0; i < n; i++) 
    {

            int index = abs(arr[i]) - 1;
            
            arr[index] *= -1;
            
            if(arr[index] > 0)
            {
                
                return abs(arr[i]);
            }   
    } 
    
    return -1;
}

