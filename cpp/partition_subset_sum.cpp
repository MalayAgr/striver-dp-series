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

bool subsetSumK(int n, int k, vector<int> &arr)
{
    if (n == 1)
        return false;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return topDown(n - 1, k, arr, dp);
}

bool partitionSum(vector<int> &arr, int n)
{
    int summation = 0;

    for (int i = 0; i < arr.size(); i++)
        summation += arr[i];

    if (summation % 2 == 1)
        return false;

    int k = summation / 2;

    return subsetSumK(n, k, arr);
}

int main(void)
{
    vector<int> arr{100};
    int n = arr.size();
    cout << partitionSum(arr, n) << newl;
    return 0;
}
