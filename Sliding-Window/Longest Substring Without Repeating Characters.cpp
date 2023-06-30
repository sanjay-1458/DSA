class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,n=s.size();
        vector<int> freq(256,0);
        int i=0,j=0;
        while(j<n){
            freq[s[j]]++;
            if(freq[s[j]]==1){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(freq[s[j]]>1){
                while(freq[s[j]]>1){
                    freq[s[i]]--;
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};
