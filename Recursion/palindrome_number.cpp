#include <bits/stdc++.h>

using namespace std;

int f(int num, int temp, int n)
{
    if (num == 0 || n == 0)
    {
        return 1;
    }
    int res = temp / pow(10, n);
    if (num % 10 != (res % 10))
    {
        return -1;
    }
    return f(num / 10, temp, n - 1);
}

int count(int n)
{
    int c = 0;
    while(n != 0)
    {
        c++;
        n = n/10;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        int temp = num;
        int n = count(num)-1;
        cout << f(num, temp, n) << endl;
    }
    return 0;
}
