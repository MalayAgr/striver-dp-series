#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, vector<int> &profit, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int maximum = 0;

    for (int j = 1; j <= i; j++)
    {
        int max_prof = topDown(i - j, profit, dp) + profit[j - 1];
        maximum = max(maximum, max_prof);
    }

    return dp[i] = maximum;
}

int rodCutting(int n, vector<int> &profit)
{
    vector<int> dp(n + 1, -1);
    return topDown(n, profit, dp);
}

int main(void)
{
    vector<int> profit{2, 5, 7, 8, 10};
    int n = profit.size();
    cout << rodCutting(n, profit) << newl;
    return 0;
}
