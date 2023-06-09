#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end) {
        
        int mid = start + (end - start) / 2;
        int val = mat[mid / n][mid % n];

        if (target < val) {
            end = mid - 1;
        } else if (target > val) {
            start = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}