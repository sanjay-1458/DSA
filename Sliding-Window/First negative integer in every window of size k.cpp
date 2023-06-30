#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
vector<int> firstnegative1(vector<int> arr, int k)
{
    vector<int> v;
    int n = arr.size();
    for (int i = 0; i < n - k + 1; ++i)
    {
        bool flag = true;
        for (int j = i; j < i + k; ++j)
        {
            if (arr[j] < 0)
            {
                flag = false;
                v.push_back(arr[j]);
                break;
            }
        }
        if (flag)
        {
            v.push_back(0);
        }
    }
    return v;
}

// TC: O(n)
// SC: O(n-k+1)
vector<int> firstnegative2(vector<int> arr, int k)
{
    int i = 0, j = 0, n = arr.size();
    vector<int> v;
    queue<int> qu;
    while (j < n)
    {
        if (arr[j] < 0)
        {
            qu.push(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (qu.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(qu.front());
            }
            if (arr[i] == qu.front())
            {
                qu.pop();
            }
            i++;
            j++;
        }
    }
    return v;
}

int32_t main()
{
    vector<int> arr = {1, 1, 4, 6, -1, -5, 8, -99, 1, 3, 1, 3, 1, -7, 4, 0, 2};
    firstnegative(arr, 3);
}
