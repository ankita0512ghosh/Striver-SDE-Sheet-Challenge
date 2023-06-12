#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    int platforms[2361] = {0};

    int minNumOfPlatforms = 1;

    for (int i = 0; i < n; i++)
    {

        ++platforms[at[i]];

        --platforms[dt[i] + 1];
    }

    for (int i = 1; i < 2361; i++)
    {
        platforms[i] = platforms[i] + platforms[i - 1];

        minNumOfPlatforms = max(minNumOfPlatforms, platforms[i]);
    }

    return minNumOfPlatforms;
}