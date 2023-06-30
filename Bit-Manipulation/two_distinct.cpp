#include <bits/stdc++.h>

using namespace std;
using bin = bitset<12>;

int main()
{
    int arr[] = {5, 4, 1, 4, 3, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = res ^ arr[i];
    }
    int ind = 0;
    while ((res & 1) != 1)
    {
        ind++;
        res = res >> 1;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
    {
        int mask = 1 << ind;
        if (arr[i] & mask)
        {
            a = a ^ arr[i];
        }
        else
        {
            b = b ^ arr[i];
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
