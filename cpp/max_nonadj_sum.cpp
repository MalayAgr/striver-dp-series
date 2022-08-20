#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(vector<int> &arr, int i, vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];

    if (i == 0)
    {
        dp[0] = arr[0];
        return dp[0];
    }

    if (i == 1)
    {
        dp[1] = max(arr[0], arr[1]);
        return dp[1];
    }

    ll picked = topDown(arr, i - 2, dp) + arr[i];
    ll notPicked = topDown(arr, i - 1, dp);

    dp[i] = max(picked, notPicked);

    return dp[i];
}

int maximumNonAdjacentSumTopDown(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return topDown(arr, n - 1, dp);
}

int maximumNonAdjacentSumBottomUp(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];

    vector<int> dp(n, -1);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);

    return dp[n - 1];
}

int maximumNonAdjacentSumSpace(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];

    ll prev2 = arr[0];
    ll prev1 = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        ll curr = max(prev2 + arr[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(void)
{
    vector<int> arr{4, 0, 8, 1, 10};
    cout << maximumNonAdjacentSumTopDown(arr) << newl;
    cout << maximumNonAdjacentSumBottomUp(arr) << newl;
    cout << maximumNonAdjacentSumSpace(arr) << newl;
    return 0;
}
