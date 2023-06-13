#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;

    while (low < high) {

        mid = (low + high) / 2;

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return arr[low];
}