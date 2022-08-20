#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"
#define MAX 1e9

using namespace std;

long topDown(int i, int x, vector<int> &denominations, vector<vector<long>> &dp)
{
    if (x == 0)
        return 1;

    if (dp[i][x] != -1)
        return dp[i][x];

    if (i == 0)
    {
        if (x % denominations[0] != 0)
            return dp[0][x] = 0;

        return dp[0][x] = 1;
    }

    long picked = 0;

    if (x >= denominations[i])
        picked = topDown(i, x - denominations[i], denominations, dp);

    long notPicked = topDown(i - 1, x, denominations, dp);

    return dp[i][x] = picked + notPicked;
}

int countChangeWays(vector<int> &denominations, int X)
{
    int n = denominations.size();

    if (n == 1)
        return (X % denominations[0] == 0) ? 1 : 0;

    vector<vector<long>> dp(n, vector<long>(X + 1, -1));

    return topDown(n - 1, X, denominations, dp);
}

int main(void)
{
    vector<int> denoms{1, 2, 3};
    int X = 7;
    cout << countChangeWays(denoms, X) << newl;
    return 0;
}
