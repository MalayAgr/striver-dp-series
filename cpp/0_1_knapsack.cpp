#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int w, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    if (i == 0)
        return dp[i][w] = (weights[0] <= w) ? values[0] : 0;

    int picked = 0;

    if (w - weights[i] >= 0)
        picked = topDown(i - 1, w - weights[i], weights, values, dp) + values[i];

    int notPicked = topDown(i - 1, w, weights, values, dp);

    return dp[i][w] = max(picked, notPicked);
}

int knapsack(vector<int> &weights, vector<int> &values, int W)
{
    int n = weights.size();

    if (n == 1)
        return (weights[0] <= W) ? values[0] : 0;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    return topDown(n - 1, W, weights, values, dp);
}

int main(void)
{
    vector<int> weights{25, 4,  25, 49, 9,  11, 31, 5,  37, 7,  11, 47, 37, 1,  33, 25, 29, 11,
                        1,  41, 19, 14, 43, 21, 1,  21, 23, 37, 12, 11, 45, 13, 36, 11, 17};
    vector<int> values{86, 55, 17, 31, 88, 82, 27, 57, 18, 1,  61, 56, 36, 82, 51, 85, 55, 21,
                       11, 76, 91, 36, 85, 32, 99, 43, 41, 61, 41, 28, 83, 27, 35, 61, 16};
    int W = 869;
    cout << knapsack(weights, values, W) << newl;
    return 0;
}
