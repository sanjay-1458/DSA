#include <bits/stdc++.h>

using namespace std;

int fun(int num)
{
    if (num <= 9)
    {
        return num;
    }
    return num % 10 + fun(num / 10);
}

int main()
{
    int num;
    cin >> num;
    int sum = fun(num);
    cout << sum << endl;
}
