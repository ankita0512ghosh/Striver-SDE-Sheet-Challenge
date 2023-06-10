#include <iostream>
using namespace std;
#include <unordered_map>

int uniqueSubstrings(string input) 
{
    int n = input.length();

    unordered_map<char, int> set;

    int ans = 0, i = 0, j = 0;

    while (i < n && j < n) 
    {
        if (set.find(input[j]) == set.end()) 
        {
            set[input[j]] = 1;
            ans = max(ans, j - i + 1);
            j++;
        } else 
        {
            set.erase(input[i]);
            i++;
        }
    }

    return ans;
}