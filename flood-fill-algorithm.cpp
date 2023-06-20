#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];
    int m = image.size();
    int n = image[0].size();
    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty())
    {
        pair<int, int> currentPixel = q.front();
        q.pop();
        int i = currentPixel.first;
        int j = currentPixel.second;
        if (i >= 0 && i < m && j >= 0 && j < n)
        {
            if (image[i][j] == oldColor && image[i][j] != newColor)
            {
                image[i][j] = newColor;
                q.push({i, j + 1});
                q.push({i, j - 1});
                q.push({i + 1, j});
                q.push({i - 1, j});
            }
        }
    }

    return image;
}