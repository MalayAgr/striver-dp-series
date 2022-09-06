#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int longestCommonSubstring(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maximum = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maximum = max(maximum, dp[i][j]);
            }
        }
    }

    return maximum;
}

int main(void)
{
    string str1 = "iddg";
    string str2 = "dgi";
    cout << longestCommonSubstring(str1, str2) << newl;
    return 0;
}
