#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

// int topDown(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     if (i < 0 || j < 0)
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s[i - 1] == t[j - 1])
//         return dp[i][j] = 1 + topDown(i - 1, j - 1, s, t, dp);

//     int s_left = topDown(i - 1, j, s, t, dp);
//     int t_left = topDown(i, j - 1, s, t, dp);

//     return dp[i][j] = max(s_left, t_left);
// }

vector<vector<int>> lcs(string &s, string &t)
{
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp;
}

string findSupersequence(int i, int j, vector<vector<int>> &grid, string &s, string &t)
{
    if (i == 0 || j == 0)
    {
        int k = 0;

        string res = "";

        while (k < i)
        {
            res += s[k];
            k++;
        }

        while (k < j)
        {
            res += t[k];
            k++;
        }

        return res;
    }

    if (s[i - 1] == t[j - 1])
        return findSupersequence(i - 1, j - 1, grid, s, t) + s[i - 1];

    if (grid[i - 1][j] > grid[i][j - 1])
        return findSupersequence(i - 1, j, grid, s, t) + s[i - 1];

    return findSupersequence(i, j - 1, grid, s, t) + t[j - 1];
}

string shortestSupersequence(string str1, string str2)
{
    vector<vector<int>> grid = lcs(str1, str2);

    string ss = findSupersequence(str1.length(), str2.length(), grid, str1, str2);

    return ss;
}

int main(int argc, char const *argv[])
{
    string str1 = "aaaaaaaa";
    string str2 = "aaaaaaaa";

    cout << shortestSupersequence(str1, str2) << newl;

    return 0;
}
