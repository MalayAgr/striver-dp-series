#include <bits/stdc++.h>

#define ll long long int
#define newl "\n"

using namespace std;

int topDown(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == n || j == m || j < 0)
        return -1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
        return matrix[n - 1][j];

    int weight = matrix[i][j];

    int down = topDown(i + 1, j, n, m, matrix, dp) + weight;
    int leftDiag = topDown(i + 1, j - 1, n, m, matrix, dp) + weight;
    int rightDiag = topDown(i + 1, j + 1, n, m, matrix, dp) + weight;

    int maximum = max(down, max(leftDiag, rightDiag));

    return dp[i][j] = maximum;
}

int maximumFallingSumTopDown(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (n == 1 && m == 1)
        return matrix[0][0];

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int max = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int max_sum = topDown(0, j, n, m, matrix, dp);

        if (max_sum > max)
            max = max_sum;
    }

    return max;
}

int main(void)
{
    vector<vector<int>> matrix{{-9999, -9888, -9777, -9666, -9555},
                               {1, 10, 2, 4, 5},
                               {-9999, -9888, -9777, -9666, -9555},
                               {0, 0, 0, 0, 0},
                               {-99, -98, -97, -96, -95}};
    cout << maximumFallingSumTopDown(matrix) << newl;
    return 0;
}
