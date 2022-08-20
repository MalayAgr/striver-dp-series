#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 == m || j2 == m)
        return 0;

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    if (i == n - 1)
    {
        if (j1 == j2)
            return dp[i][j1][j2] = grid[i][j1];

        return dp[i][j1][j2] = (grid[i][j1] + grid[i][j2]);
    }

    int maximum = 0;

    int j1_chocs = grid[i][j1];
    int j2_chocs = grid[i][j2];

    for (int k1 = j1 - 1; k1 <= j1 + 1; k1++)
        for (int k2 = j2 - 1; k2 <= j2 + 1; k2++)
        {
            int max_choc = topDown(i + 1, k1, k2, n, m, grid, dp) + j1_chocs;

            if (j1 != j2)
                max_choc += j2_chocs;

            maximum = max(maximum, max_choc);
        }

    return dp[i][j1][j2] = maximum;
}

int maxChocolates(int n, int m, vector<vector<int>> &grid)
{
    if (n == 1 && m == 1)
        return grid[0][0];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return topDown(0, 0, m - 1, n, m, grid, dp);
}

int main(void)
{
    int n = 3, m = 4;
    vector<vector<int>> grid{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout << maxChocolates(n, m, grid) << newl;
    return 0;
}
