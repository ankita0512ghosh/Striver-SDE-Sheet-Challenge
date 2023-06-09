#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();

    vector<int> majorityElement;

    int firstCandidate = 0, secondCandidate = 0;

    int firstCount = 0, secondCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
        else if (firstCount == 0)
        {
            firstCandidate = arr[i];
            firstCount = 1;
        }

        else if (secondCount == 0)
        {
            secondCandidate = arr[i];
            secondCount = 1;
        }

        else
        {
            firstCount = firstCount - 1;
            secondCount = secondCount - 1;
        }
    }

    firstCount = 0;
    secondCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == firstCandidate)
        {
            firstCount = firstCount + 1;
        }

        else if (arr[i] == secondCandidate)
        {
            secondCount = secondCount + 1;
        }
    }

    if (firstCount > n / 3)
    {
        majorityElement.push_back(firstCandidate);
    }
    if (secondCount > n / 3)
    {
        majorityElement.push_back(secondCandidate);
    }

    return majorityElement;
}
