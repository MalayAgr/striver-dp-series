#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int j, string &s, vector<vector<int>> &dp)
{
    if (j < i)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j])
    {
        if (i == j)
            return dp[i][j] = 1;

        return dp[i][j] = 2 + topDown(i + 1, j - 1, s, dp);
    }

    int left = topDown(i + 1, j, s, dp);
    int right = topDown(i, j - 1, s, dp);

    return dp[i][j] = max(left, right);
}

int longestPalindromeSubsequence(string s)
{
    int length = s.size();

    vector<vector<int>> dp(length, vector<int>(length, -1));

    return topDown(0, length - 1, s, dp);
}

int main(int argc, char const *argv[])
{
    string s = "bbbab";
    cout << longestPalindromeSubsequence(s) << newl;
    return 0;
}
