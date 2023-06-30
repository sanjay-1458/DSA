#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int countanagram1(string txt, string pat)
{
    int n = txt.size(), k = pat.size(), cnt = 0;
    map<char, int> mp1;
    for (int i = 0; i < k; ++i)
    {
        mp1[pat[i]]++;
    }
    for (auto x : mp1)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
    for (int i = 0; i < n - k + 1; ++i)
    {
        map<char, int> mp2;
        for (int j = i; j < k + i; ++j)
        {
            mp2[txt[j]]++;
        }
        if (mp1 == mp2)
        {
            cnt++;
        }
    }
    cout << cnt;
}

int countanagram2(string txt, string pat)
{
    int k = pat.size(), n = txt.size(), c = 0;
    map<char, int> mp1;
    for (int i = 0; i < k; ++i)
    {
        mp1[pat[i]]++;
    }
    int i = 0, j = 0;
    map<char, int> mp2;
    while (j < n)
    {
        mp2[txt[j]]++;
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (mp1 == mp2)
            {
                c++;
            }
            mp2[txt[i]]--;
            if (mp2[txt[i]] == 0)
            {
                mp2.erase(txt[i]);
            }
            i++;
            j++;
        }
    }
    return c;
}

int countanagram3(string txt, string pat)
{
    int k = pat.size(), n = txt.size(), c = 0;
    map<char, int> mp;
    for (int i = 0; i < k; ++i)
    {
        mp[pat[i]]++;
    }
    int i = 0, j = 0;
    int ans = 0;
    c = mp.size();
    while (j < n)
    {
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
            {
                c--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (c == 0)
            {
                ans++;
            }
            if (mp.find(txt[i]) != mp.end())
            {
                if (mp[txt[i]] == 0)
                {
                    c++;
                }
                mp[txt[i]]++;
            }
            i++;
            j++;
        }
    }
    return ans;
}

int32_t main()
{
    string txt = "forxxorfxdofr";
    string pat = "for";
    cout << countanagram(txt, pat);
}
