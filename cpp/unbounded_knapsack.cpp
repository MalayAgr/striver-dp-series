#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int x, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (x == 0)
        return 0;

    if (dp[i][x] != -1)
        return dp[i][x];

    if (i == 0)
        return dp[i][x] = profit[0] * (x / weight[0]);

    int picked = 0;
    int w = weight[i];

    if (w <= x)
        picked = topDown(i, x - w, profit, weight, dp) + profit[i];

    int notPicked = topDown(i - 1, x, profit, weight, dp);

    return dp[i][x] = max(picked, notPicked);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    if (n == 1)
        return profit[0] * (w / weight[0]);

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    return topDown(n - 1, w, profit, weight, dp);
}

int main(void)
{
    vector<int> weight{2, 4, 6};
    vector<int> profit{5, 11, 13};
    int w = 10, n = weight.size();
    cout << unboundedKnapsack(n, w, profit, weight) << newl;
    return 0;
}
