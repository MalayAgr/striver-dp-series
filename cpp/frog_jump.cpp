#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int frogJumpTable(int n, vector<int> &heights)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);

    for (size_t i = 2; i < n; i++)
    {
        ll oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        ll twoJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneJump, twoJump);
    }

    return dp[n - 1];
}

int frogJumpNoTable(int n, vector<int> &heights)
{
    ll prev1 = abs(heights[0] - heights[1]);
    ll prev2 = 0;

    for (size_t i = 2; i < n; i++)
    {
        ll oneJump = prev1 + abs(heights[i] - heights[i - 1]);
        ll twoJump = prev2 + abs(heights[i] - heights[i - 2]);
        prev2 = prev1;
        prev1 = min(oneJump, twoJump);
    }

    return prev1;
}

int main(void)
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = heights.size();
    cout << frogJumpTable(n, heights) << newl;
    cout << frogJumpNoTable(n, heights) << newl;
    return 0;
}
