#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
int sumsubarrayk1(vector<int> arr, int k)
{
    int res = 0, n = arr.size();
    for (int i = 0; i < n - k + 1; ++i)
    {
        int sum = 0;
        for (int j = i; j < i + k; ++j)
        {
            sum += arr[j];
        }
        res = max(res, sum);
    }
    return res;
}

// TC: O(n)
// SC: O(1)
int sumsubarrayk2(vector<int> arr, int k)
{
    int res = 0, n = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    while (j < n)
    {                                    // include the calculation of new element (calculation for new element)
        sum = sum + arr[j];
        if (j - i + 1 < k)                // if window size is less than the required window size -> increase the size of window
        {
            j++;
        }
        else if (j - i + 1 == k)        // if window size == required size -> perform calculation and slide the window
        {
            res = max(res, sum);
            sum = sum - arr[i];           // remove the calculation of the ith element
            i++;
            j++;
        }
    }
    return res;
}

int32_t main()
{
    vector<int> arr = {1, 1, 4, 6, -1, -5, 8, -99, 1, 3, 1, 3, 1, -7, 4, 0, 2};
    sumsubarrayk(arr, 3);
}
