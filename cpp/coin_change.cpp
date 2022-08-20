#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"
#define MAX 1e9

using namespace std;

int topDown(int i, int x, vector<int> &denoms, vector<vector<int>> &dp)
{
    if (x == 0)
        return 0;

    if (dp[i][x] != -1)
        return dp[i][x];

    if (i == 0)
    {
        if (x % denoms[0] != 0)
            return dp[0][x] = MAX;

        return dp[0][x] = x / denoms[0];
    }

    int picked = MAX;

    if (x >= denoms[i])
        picked = topDown(i, x - denoms[i], denoms, dp) + 1;

    int notPicked = topDown(i - 1, x, denoms, dp);

    return dp[i][x] = min(picked, notPicked);
}

int minCoins(vector<int> &denoms, int X)
{
    int n = denoms.size();

    if (n == 1)
        return (X % denoms[0] == 0) ? X / denoms[0] : -1;

    vector<vector<int>> dp(n, vector<int>(X + 1, -1));

    int res = topDown(n - 1, X, denoms, dp);

    if (res >= MAX)
        return -1;

    return res;
}

int main(void)
{
    vector<int> denoms{1, 2, 3};
    int X = 7;
    cout << minCoins(denoms, X) << newl;
    return 0;
}
