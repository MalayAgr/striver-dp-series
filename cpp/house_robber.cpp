#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

ll topDown(vector<int> &arr, int i, vector<ll> &dp)
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

ll robTopDown(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];

    vector<int> withFirst, withLast;
    vector<ll> dp(n, -1);

    withFirst.push_back(arr[0]);

    for (size_t i = 1; i < n - 1; i++)
    {
        int val = arr[i];
        withFirst.push_back(val);
        withLast.push_back(val);
    }

    withLast.push_back(arr[n - 1]);

    ll first = topDown(withFirst, n - 2, dp);

    fill(dp.begin(), dp.end(), -1);

    ll second = topDown(withLast, n - 2, dp);

    return max(first, second);
}

ll bottomUp(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];

    vector<ll> dp(n, -1);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (size_t i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);

    return dp[n - 1];
}

ll robBottomUp(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];

    vector<int> withFirst, withLast;

    withFirst.push_back(arr[0]);

    for (size_t i = 1; i < n - 1; i++)
    {
        int val = arr[i];
        withFirst.push_back(val);
        withLast.push_back(val);
    }

    withLast.push_back(arr[n - 1]);

    return max(bottomUp(n - 1, withFirst), bottomUp(n - 1, withLast));
}

ll space(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];

    ll prev1 = max(arr[0], arr[1]);
    ll prev2 = arr[0];

    for (size_t i = 2; i < n; i++)
    {
        ll val = max(prev2 + arr[i], prev1);
        prev2 = prev1;
        prev1 = val;
    }

    return prev1;
}

ll robSpace(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];

    vector<int> withFirst, withLast;

    withFirst.push_back(arr[0]);

    for (size_t i = 1; i < n - 1; i++)
    {
        int val = arr[i];
        withFirst.push_back(val);
        withLast.push_back(val);
    }

    withLast.push_back(arr[n - 1]);

    return max(space(n - 1, withFirst), space(n - 1, withLast));
}

int main(void)
{
    vector<int> arr{1, 5, 2, 1, 6};
    int n = arr.size();
    cout << robTopDown(n, arr) << newl;
    cout << robBottomUp(n, arr) << newl;
    cout << robSpace(n, arr) << newl;
    return 0;
}
