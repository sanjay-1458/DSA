#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(n)
int longestUniqueSubsttr(string s)
{
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i)
    {
        set<int> st;
        for (int j = i; j < n; ++j)
        {
            st.insert(s[j]);
            if (st.size() == j - i + 1)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

// TC: O(n)
// SC: O(n)
int longestUniqueSubsttr(string s)
{
    int n = s.size();
    int i = 0, j = 0, k = 0, ans = 0;
    map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        k = j - i + 1;
        if (mp.size() == k)
        {
            ans = max(ans, k);
            j++;
        }
        else if (mp.size() < k)
        {
            while (mp.size() < k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
                k--;
            }
            if (mp.size() == k)
            {
                ans = max(ans, k);
            }
            j++;
        }
    }
    return ans;
}

// TC: O(n)
// SC: O(26)
int longestUniqueSubsttr(string s)
{
    int n = s.size();
    int i = 0, j = 0, k = 0, ans = 0;
    vector<int> vec(26, 0);
    while (j < n)
    {
        vec[s[j] - 'a']++;
        if (vec[s[j] - 'a'] == 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (vec[s[j] - 'a'] > 1)
        {
            while (vec[s[j] - 'a'] > 1)
            {
                vec[s[i] - 'a']--;
                i++;
            }
            if (vec[s[j] - 'a'] == 1)
            {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
    }
    return ans;
}

// TC: O(n)
// SC: O(26)
int longestUniqueSubsttr(string s){
    vector<int> vec(26,0);
    int i=0,n=s.size(),j=0,ans=0;
    while(j<n){
        vec[s[j]-'a']++;
        if(vec[s[j]-'a']==1){
            ans=max(ans,j-i+1);
            j++;
        }
        else if(vec[s[j]-'a']>1){
            while(s[i]!=s[j]){
                vec[s[i]-'a']--;
                i++;
            }
            vec[s[i]-'a']--;
            i++;
            if(vec[s[j]-'a']==1){
                ans=max(ans,j-i+1);
                j++;
            }
        }
    }
    return ans;
}
int32_t main()
{
    string s = "abebabebsdbe";
    longestUniqueSubsttr(s);
}
