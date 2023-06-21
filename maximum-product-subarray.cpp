#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <algorithm>

int maximumProduct(vector<int> &arr, int n){
    
    int ans = INT_MIN;

    int productFromFront = 1, productFromBack = 1;

    for(int i = 0; i < n; i++){
        productFromFront = productFromFront * arr[i];
        productFromBack = productFromBack * arr[n-i-1];

        ans = max({ans, productFromFront, productFromBack});

        if(productFromFront == 0){
            productFromFront = 1;
        }
        if(productFromBack == 0){
            productFromBack = 1;
        }
    }

    return ans;
}
