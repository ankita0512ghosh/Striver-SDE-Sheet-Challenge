#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());

    int mx = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {

        if (i > 0 && (arr[i] == arr[i - 1] + 1)) {
            count++;
        }

        else if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        else {
            count = 1;
        }

        mx = max(mx, count);
        
    }

    return mx;
}