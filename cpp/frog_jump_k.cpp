#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int frogJumpKTable(int n, int k, vector<int> &heights)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);

    for (int i = 2; i < n; i++)
    {
        ll height = heights[i];
        ll minimum = dp[i - 1] + abs(height - heights[i - 1]);
        int j = 2;

        while (j <= min(k, i))
        {
            minimum = min(minimum, dp[i - k] + abs(height - heights[i - k]));
            j++;
        }

        dp[i] = minimum;
    }

    return dp[n - 1];
}

int main(void)
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = heights.size(), k = 2;
    cout << frogJumpKTable(n, k, heights);
    return 0;
}
