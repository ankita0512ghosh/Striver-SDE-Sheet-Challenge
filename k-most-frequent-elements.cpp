#include <iostream>
#include <vector>
using namespace std;
#include<map>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> mp;
    for (int ele : arr) {

        mp[ele]++;
    }

    vector<int> bucket[n+1];

    for (auto x : mp) {

        int freq = x.second;
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;
    for (int i = n; i > 0 && k > 0; i--) {

        if (bucket[i].size() == 0) {
            continue;
        }

        for (int num : bucket[i]) {

            ans[cur++] = num;
            k--;
            if(k == 0){
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}