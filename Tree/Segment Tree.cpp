#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void build_max(int low, int high, int ind, vector<int> &v, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build_max(low, mid, 2 * ind + 1, v, seg);
    build_max(mid + 1, high, 2 * ind + 2, v, seg);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query_max(int low, int high, int ind, int l, int h, vector<int> &seg)
{
    if (l <= low && high <= h)
    {
        return seg[ind];
    }
    if (high < l || h < low)
    {
        return INT_MIN;
    }
    int left = query_max(low, (low + high) / 2, 2 * ind + 1, l, h, seg);
    int right = query_max((low + high) / 2 + 1, high, 2 * ind + 2, l, h, seg);
    return max(left, right);
}

void build_sum(int low, int high, int ind, vector<int> &v, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build_sum(low, mid, 2 * ind + 1, v, seg);
    build_sum(mid + 1, high, 2 * ind + 2, v, seg);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query_sum(int low, int high, int ind, int l, int h, vector<int> &seg)
{
    if (l <= low && high <= h)
    {
        return seg[ind];
    }
    if (l > high || h < low)
    {
        return 0;
    }
    int mid = (low + high) / 2;
    int left = query_sum(low, mid, 2 * ind + 1, l, h, seg);
    int right = query_sum(mid + 1, high, 2 * ind + 2, l, h, seg);
    return left + right;
}

void pointUpdate(int low, int high, int ind, int node, int val, vector<int> &seg)
{
    if (low == high)
    {
        seg[ind] += val;
    }
    else
    {
        int mid = (low + high) >> 1;
        if (node <= mid && node >= low)
        {
            pointUpdate(low, mid, 2 * ind + 1, node, val, seg);
        }
        else
        {
            pointUpdate(mid + 1, high, 2 * ind + 2, node, val, seg);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
}

void rangeUpdate(int ind, int low, int high, int l, int r, int val, vector<int> &lazy, vector<int> &seg)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
        return;
    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        return;
    }
    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val, lazy, seg);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val, lazy, seg);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int querySumLazy(int ind, int low, int high, int l, int r, int val, vector<int> &lazy, vector<int> &seg)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
        return 0;
    if (low >= l && high <= r)
        return seg[ind];
    int mid = (low + high) >> 1;
    int left = querySumLazy(2 * ind + 1, low, mid, l, r, val, lazy, seg);
    int right = querySumLazy(2 * ind + 2, mid + 1, high, l, r, val, lazy, seg);
    return left + right;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> seg(4 * n);
}
