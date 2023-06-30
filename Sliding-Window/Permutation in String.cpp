class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(),n=s2.size();
        vector<int> freq(26,0);
        vector<int> window(26,0);
        for(int i=0;i<k;++i){
            freq[s1[i]-'a']++;
        }
        int i=0,j=0;
        while(j<n){
            window[s2[j]-'a']++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(freq==window){
                    return true;
                }
                window[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
