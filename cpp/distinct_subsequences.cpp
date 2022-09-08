#include <bits/stdc++.h>

#define newl "\n"

typedef unsigned long long ull;

using namespace std;

int distinctSubsequences(string s, string t)
{
    int m = s.length();
    int n = t.length();

    if (n > m)
        return 0;

    vector<vector<ull>> dp(m + 1, vector<ull>(n + 1, -1));

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;

    for (int i = 0; i < m + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}

int main(int argc, char const *argv[])
{
    string s1 = "babgbag";
    string s2 = "bag";
    cout << distinctSubsequences(s1, s2) << newl;
    return 0;
}
