#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

bool topDown(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k < 0)
        return false;

    if (k == 0)
        return true;

    if (dp[i][k] != -1)
        return dp[i][k];

    if (i == 0)
        return dp[i][k] = (arr[0] == k);

    bool picked = topDown(i - 1, k - arr[i], arr, dp);
    bool notPicked = topDown(i - 1, k, arr, dp);

    return dp[i][k] = (picked || notPicked);
}

bool subsetSumK(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (n == 1)
        return arr[0] == k;

    return topDown(n - 1, k, arr, dp);
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    if (n == 1)
        return arr[0];

    if (n == 2)
        return abs(arr[0] - arr[1]);

    int summation = 0;

    for (int i = 0; i < n; i++)
        summation += arr[i];

    int half = summation / 2;

    vector<vector<int>> dp(n, vector<int>(half + 1, -1));

    for (int k = half; k >= 0; k--)
    {
        bool hasSubset = subsetSumK(n, k, arr, dp);

        if (hasSubset)
            return abs(summation - 2 * k);
    }

    return 0;
}

int main(void)
{
    vector<int> arr{1, 2, 3, 4};
    int n = arr.size();
    cout << minSubsetSumDifference(arr, n) << newl;
    return 0;
}
