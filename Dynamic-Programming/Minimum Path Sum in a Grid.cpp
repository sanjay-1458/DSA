#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC : O((n+m-2)C(m-1))
// We have (n-1) moves from top to bottom & (m-1) moves from left to right

int recursive(vector<vector<int>> grid, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return INF;
    }
    return grid[i][j] + min(recursive(grid, i - 1, j), recursive(grid, i, j - 1));
}

int memo[100][100];

int memoization(vector<vector<int>> grid, int i, int j)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return INF;
    }
    int left = 0, right = 0;
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    return memo[i][j] = grid[i][j] + min(memoization(grid, i - 1, j), memoization(grid, i, j - 1));
}

int tabulation(vector<vector<int>> grid)
{
    int i = 0, j = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
            }
            else
            {
                int sum1 = grid[i][j];
                int sum2 = grid[i][j];
                if (i > 0)
                {
                    sum1 += dp[i - 1][j];
                }
                else
                {
                    sum1 += INF;
                }
                if (j > 0)
                {
                    sum2 += dp[i][j - 1];
                }
                else
                {
                    sum2 += INF;
                }
                dp[i][j] = min(sum1, sum2);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    cout << recursive(grid, n - 1, m - 1) << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            memo[i][j] = -1;
        }
    }
    cout << memoization(grid, n - 1, m - 1) << endl;
    cout << tabulation(grid) << endl;
}
