#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int t, vector<int> &arr, vector<vector<int>> &dp)
{
    if (t < 0)
        t = -t;

    if (dp[i][t] != -1)
        return dp[i][t];

    if (i == 0)
    {
        if (arr[0] == 0 && t == 0)
            return dp[i][t] = 2;

        return dp[i][t] = (arr[0] == t || -arr[0] == t) ? 1 : 0;
    }

    int val = arr[i];

    int plus = topDown(i - 1, t - val, arr, dp);

    if (val == 0)
        return dp[i][t] = 2 * plus;

    int minus = topDown(i - 1, t + arr[i], arr, dp);

    return dp[i][t] = plus + minus;
}

int targetSum(int n, int target, vector<int> &arr)
{
    if (n == 1)
        return (arr[0] == target || -arr[0] == target) ? 1 : 0;

    if (target < 0)
        target = -target;

    int sum = 0;

    for (int i = 1; i < n; i++)
        sum += arr[i];

    vector<vector<int>> dp(n, vector<int>(sum + target + 1, -1));

    return topDown(n - 1, target, arr, dp);
}

int main(void)
{
    vector<int> arr{0, 13, 18, 14, 15, 19, 21, 2, 8, 1};
    int n = arr.size();
    int target = -39;
    cout << targetSum(n, target, arr) << newl;
    return 0;
}
