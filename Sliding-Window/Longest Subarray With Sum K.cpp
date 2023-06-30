#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n3)
// SC: O(1)
int longestSubarrayWithSumK(vector<int> arr, int k)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += arr[k];
            }
            if (sum == k)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

// TC: O(n2)
// SC: O(1)
int longestSubarrayWithSumK(vector<int> arr, int k)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            if (sum == k)
            {
                ans = max(j - i + 1, ans);
            }
        }
    }
    return ans;
}

// TC: O(n)
// SC: O(1)
int longestSubarrayWithSumK(vector<int> arr, int k)
{
    int n = arr.size();
    int i = 0, j = 0, ans = 0;
    long long sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
    }
    return ans;
}

int32_t main()
{
    vector<int> arr = {1, 2, 3, 1, 3, 1, 3, 1, 3};
    cout << longestSubarrayWithSumK(arr, 3);
}
