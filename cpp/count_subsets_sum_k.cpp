#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k < 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    if (i == 0)
    {
        if (k == 0 && arr[0] == 0)
            return dp[i][k] = 2;

        if (k == 0 || arr[0] == k)
            return dp[i][k] = 1;

        return dp[i][k] = 0;
    }

    int picked = topDown(i - 1, k - arr[i], arr, dp);
    int notPicked = topDown(i - 1, k, arr, dp);

    return dp[i][k] = picked + notPicked;
}

int countSubsetSumK(int n, int k, vector<int> &arr)
{
    if (n == 1)
        return (arr[0] == k) ? 1 : 0;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return topDown(n - 1, k, arr, dp);
}

int main(void)
{
    vector<int> arr{0, 0, 1};
    int n = arr.size(), k = 3;
    cout << countSubsetSumK(n, k, arr) << newl;
    return 0;
}
