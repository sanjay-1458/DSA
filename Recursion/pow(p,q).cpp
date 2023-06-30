#include <bits/stdc++.h>

using namespace std;

int f(int p, int q)
{
    if (q == 0)
    {
        return 1;
    }
    int ans = f(p, q / 2);
    ans = ans * ans;
    if (q % 2 == 0)
    {
        return ans;
    }
    else
    {
        return ans * p;
    }
}

int main()
{
    int p, q;
    cin >> p >> q;
    int ans = f(p, q);
    cout << ans;
}
