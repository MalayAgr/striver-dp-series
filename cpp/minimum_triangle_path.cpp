#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

vector<vector<int>> initDP(int n)
{
    vector<vector<int>> dp(n);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < i + 1; j++)
            dp[i].push_back(-1);

    return dp;
}

int topDown(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == n || j == n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return dp[n - 1][j] = triangle[n - 1][j];

    int down = topDown(i + 1, j, n, triangle, dp);
    int diagonal = topDown(i + 1, j + 1, n, triangle, dp);

    int weight = triangle[i][j];

    return dp[i][j] = min(down + weight, diagonal + weight);
}

int minPathSumTopDown(vector<vector<int>> &triangle, int n)
{
    if (n == 1)
        return triangle[0][0];

    vector<vector<int>> dp = initDP(n);

    return topDown(0, 0, n, triangle, dp);
}

int minPathSumBottomUp(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp = initDP(n);

    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int val = triangle[i][j];
            int down = dp[i + 1][j] + val;
            int diagonal = dp[i + 1][j + 1] + val;
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

int minPathSumSpace(vector<vector<int>> &triangle, int n)
{
    vector<int> row;

    for (int j = 0; j < n; j++)
        row.push_back(triangle[n - 1][j]);

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp;

        for (int j = 0; j <= i; j++)
        {
            int val = triangle[i][j];
            int down = row[j] + val;
            int diagonal = row[j + 1] + val;
            temp.push_back(min(down, diagonal));
        }

        row = temp;
    }

    return row[0];
}

int main(void)
{
    vector<vector<int>> triangle{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    int n = triangle.size();
    cout << minPathSumTopDown(triangle, n) << newl;
    cout << minPathSumBottomUp(triangle, n) << newl;
    cout << minPathSumSpace(triangle, n) << newl;
    return 0;
}
