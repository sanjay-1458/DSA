/*
Printing the magic square pattern in C++
4 4 4 4 4 4 4 
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = -1;
    for (int i = 1; i <= 2 * n - 1; ++i)
    {
        if (i <= n)
        {
            d++;
        }
        else
        {
            d--;
        }
        int res1 = n - d, res2 = n - d - 1;
        int r1 = d, k1 = n, r2 = d, k2;
        while (r1 != 0)
        {
            cout << k1 << " ";
            k1--;
            r1--;
        }
        k2 = k1;
        while (res1 != 0)
        {
            cout << k1 << " ";
            res1--;
        }
        while (res2 != 0)
        {
            cout << k2 << " ";
            res2--;
        }
        k2++;
        while (r2 != 0)
        {
            cout << k2 << " ";
            r2--;
            k2++;
        }
        cout << endl;
    }
    return 0;
}
