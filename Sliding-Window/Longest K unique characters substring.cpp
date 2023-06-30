#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(n)
int Kuniquecharacter(string s, int k)
{
    int i = 0, j = 0, ans = -1, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        set<int> st;
        for (int j = i; j < n; ++j)
        {
            st.insert(s[j]);
            if (st.size() == k)
            {
                ans = max(ans, j - i + 1);
            }
            if (st.size() > k)
            {
                break;
            }
        }
    }
    return ans;
}

// TC: O(n)
// SC: O(n)
int Kuniquecharacter(string s, int k)
{
    int i = 0, j = 0, ans = -1, n = s.size();
    map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            if (j - i + 1 > ans)
            {
                ans = j - i + 1;
            }
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            if (mp.size() == k)
            {
                if (j - i + 1 > ans)
                {
                    ans = j - i + 1;
                }
            }
            j++;
        }
    }
    return ans;
}

int32_t main()
{
    string s = "abebabebsdbe";
    Kuniquecharacter(s, 3);
}
