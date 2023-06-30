#include <bits/stdc++.h>

using namespace std;

string f(string &s, int l, int h)
{
    if (l <= h)
    {
        if (s[l] != s[h])
        {
            return "NO";
        }
        else
            return f(s, l + 1, h - 1);
    }
    else
    {
        return "YES";
    }
}

int main()
{
    string s = "123321";
    cout << f(s, 0, s.size() - 1);
    return 0;
}
