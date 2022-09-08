#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 1 + topDown(i - 1, j - 1, s, t, dp);

    int s_left = topDown(i - 1, j, s, t, dp);
    int t_left = topDown(i, j - 1, s, t, dp);

    return dp[i][j] = max(s_left, t_left);
}

int lcs(string &s, string &t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return topDown(n - 1, m - 1, s, t, dp);
}

int min_ops(string &s1, string &s2)
{
    int lcs_len = lcs(s1, s2);

    return s1.length() + s2.length() - 2 * lcs_len;
}
