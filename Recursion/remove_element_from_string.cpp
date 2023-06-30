#include <bits/stdc++.h>

using namespace std;

string f2(string &s, char ch, int ind)
{
    if (ind == s.size())
    {
        return "";
    }
    if (s[ind] != ch)
    {
        return s[ind] + f2(s, ch, ind + 1);
    }
    else
    {
        return f2(s, ch, ind + 1);
    }
}

void f1(string &s, char ch, int ind)
{
    if (ind == s.size())
    {
        return;
    }
    if (s[ind] == ch)
    {
        s.erase(s.begin() + ind);
        f1(s, ch, ind);
    }
    else
        f1(s, ch, ind + 1);
}

int main()
{
    string s = "caca";
    char ch = 'a';
    f(s, ch, 0);
    cout << s;
    return 0;
}
