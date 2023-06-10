#include <iostream>
using namespace std;
#include <unordered_map>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();

    unordered_map<int, int> prefXor;

    int ans = 0;

    int currXor = 0;

    prefXor[0]++;

    for (int i = 0; i < n; i++)
    {
        currXor = currXor ^ arr[i];

        int req = x ^ currXor;

        ans += prefXor[req];

        prefXor[currXor]++;
    }

    return ans;
}