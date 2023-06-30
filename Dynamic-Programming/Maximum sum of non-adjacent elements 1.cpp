#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int recursive(int n, vector<int> arr)
{
    if (n <= 0)
        return 0;
    return max(recursive(n - 1, arr), arr[n - 1] + recursive(n - 2, arr));
}

vector<int> memo(20, -1);

int memoization(int n, vector<int> arr)
{
    if (n <= 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = max(memoization(n - 1, arr), arr[n - 1] + memoization(n - 2, arr));
}

int tabulation(int n, vector<int> arr)
{
    vector<int> dp(n + 3, 0);
    for (int i = 2; i <= n + 1; ++i)
        dp[i] = max(dp[i - 1], arr[i - 2] + dp[i - 2]);
    return dp[n + 1];
}

int32_t main()
{
    vector<int> arr = {1,0,2,3};
    cout << recursive(arr.size(), arr) << endl;
    cout << memoization(arr.size(), arr) << endl;
    cout << tabulation(arr.size(), arr) << endl;
}
