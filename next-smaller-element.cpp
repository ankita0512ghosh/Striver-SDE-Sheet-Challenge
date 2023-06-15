#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <stack>

vector<int> nextSmallerElement(vector<int>& arr, int n) 
{
    vector<int> ans(n);

    stack < int > stk;
    stk.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (stk.top() >= arr[i])
        {
            stk.pop();
        }

        ans[i] = stk.top();

        stk.push(arr[i]);
    }

    return ans;
}