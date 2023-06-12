#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findMinimumCoins(int amount) 
{
	vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	
    int coinsCount = 0; 
    int n = denominations.size();

    for (int i = n - 1; i >= 0; i--) 
    {
        coinsCount += amount / denominations[i];
        amount %= denominations[i];
    }

    return coinsCount; 
} 
