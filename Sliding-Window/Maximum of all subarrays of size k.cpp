#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
vector<int> maxofsubarray1(vector<int> arr, int k)
{
    vector<int> v;
    int n = arr.size();
    for (int i = 0; i < n - k + 1; ++i)
    {
        int mx = INT_MIN;
        for (int j = i; j < i + k; ++j)
        {
            mx = max(mx, arr[j]);
        }
        v.push_back(mx);
    }
    return v;
}

// TC: O(n)
// SC: O(n-k+1)
vector<int> maxofsubarray2(vector<int> arr, int k)
{
    vector<int> v;
    int i = 0, j = 0, n = arr.size();
    deque<int> dq;
    while (j < n)
    {
        if (dq.empty())
        {
            dq.push_back(arr[j]);
        }
        else if (dq.back() < arr[j])
        {
            while (dq.size() > 0 && dq.back() < arr[j])
            {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
        }
        else
        {
            dq.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            v.push_back(dq.front());
            if (arr[i] == dq.front())
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}

int32_t main()
{
    vector<int> arr = {1, 2, 3, 1, 3, 5, 3, 1, 4};
    cout << maxofsubarray(arr, 3);
}
