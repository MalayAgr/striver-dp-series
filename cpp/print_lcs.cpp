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

vector<vector<int>> lcs(string &s, string &t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int res = topDown(n - 1, m - 1, s, t, dp);

    return dp;
}

string findLCS(int i, int j, vector<vector<int>> &grid, string &s, string &t)
{
    if (i < 0 || j < 0)
        return "";

    if (s[i] == t[j])
        return findLCS(i - 1, j - 1, grid, s, t) + s[i];

    if (grid[i - 1][j] > grid[i][j - 1])
        return findLCS(i - 1, j, grid, s, t);

    return findLCS(i, j - 1, grid, s, t);
}

int main(void)
{
    string s = "abcde";
    string t = "bdgek";

    vector<vector<int>> grid = lcs(s, t);

    string res = findLCS(s.length() - 1, t.length() - 1, grid, s, t);

    cout << res << newl;
    return 0;
}
