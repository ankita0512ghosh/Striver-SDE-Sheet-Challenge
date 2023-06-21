#include <iostream>
#include <vector>
#include <string>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    long **ways = new long *[n];

    for (int i = 0; i < n; i++)
    {
        ways[i] = new long[value + 1];
        ways[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= value; j++)
        {
            long count1 = 0;
            
            if (i + 1 <= n - 1)
            {
                count1 = ways[i + 1][j];
            }

            long count2 = 0;
            
            if (j - denominations[i] >= 0)
            {
                count2 = ways[i][j - denominations[i]];
            }

            ways[i][j] = count1 + count2;
        }
    }

    return ways[0][value];
}