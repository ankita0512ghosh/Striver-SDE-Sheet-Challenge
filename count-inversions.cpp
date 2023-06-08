#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void fenwickUpdate(int index, int siz, vector<long long> &fenwick)
{
    while (index <= siz)
    {
        fenwick[index] += 1;

        index = index + (index & (-index));
    }
}
long long fenwickSum(int index, vector<long long> &fenwick)
{
    long long sum = 0;
    while (index > 0)
    {
        sum += fenwick[index];

        index = index - (index & (-index));
    }
    return sum;
}

long long getInversions(long long *arr, int n) {

    vector<vector<int>> mapping(n, vector<int>(2));

    vector<long long> fenwick(n + 1, 0), mask(n);

    for (int i = 0; i < n; i++) {
        mapping[i][0] = arr[i];
        mapping[i][1] = i;
    }

    sort(mapping.begin(), mapping.end());
    for (int i = 0; i < n; i++) {
        mask[mapping[i][1]] = i + 1;
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {

        answer += fenwickSum(mask[i] - 1, fenwick);

        fenwickUpdate(mask[i], n, fenwick);
    }
    return answer;
}