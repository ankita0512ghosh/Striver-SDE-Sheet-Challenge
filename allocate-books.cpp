#include <iostream>
#include <vector>
using namespace std; 

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    long long sum = 0;

    int maxTime = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    long long l = maxTime, r = sum, answer = sum;

    while (l <= r)
    {
        
        long long mid = (l + r) / 2;
        long days = 1;
        long long currentTime = 0;

        for (int i = 0; i < m; i++)
        {
            currentTime += time[i];
            if (currentTime > mid)
            {
                days++;
                currentTime = time[i];
            }

        }
        if (days <= n)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }

    return answer;
}