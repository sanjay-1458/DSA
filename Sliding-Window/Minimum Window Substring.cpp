class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0, start = -1, end = -1, ans = INT_MAX;
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < t.size(); ++i)
        {
            mp[t[i]]++;
        }
        int c = t.size();
        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
            {
                if (mp[s[j]] > 0)
                {
                    c--;
                }
                mp[s[j]]--;
            }
            if (c > 0)
            {
                j++;
            }
            else if (c == 0)
            {
                if (ans > j - i + 1)
                {
                    start = i;
                    end = j;
                    ans = j - i + 1;
                }
                while (c == 0)
                {
                    if (mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if (mp[s[i]] > 0)
                        {
                            c++;
                        }
                    }
                    if (ans > j - i + 1)
                    {
                        start = i;
                        end = j;
                        ans = j - i + 1;
                    }
                    i++;
                }
                j++;
            }
        }
        string w = "";
        if (ans == INT_MAX)
        {
            return w;
        }
        else
        {
            for (int i = start; i <= end; ++i)
            {
                w += s[i];
            }
            return w;
        }
    }
};
