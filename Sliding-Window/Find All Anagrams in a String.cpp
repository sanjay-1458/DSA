class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),k=p.size();
        vector<int> freq(26,0);
        vector<int> v;
        for(int i=0;i<k;++i){
            freq[p[i]-'a']++;
        }
        vector<int> vec(26,0);
        int i=0,j=0;
        while(j<n){
            vec[s[j]-'a']++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(vec==freq){
                    v.push_back(i);
                }
                vec[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return v;
    }
};
