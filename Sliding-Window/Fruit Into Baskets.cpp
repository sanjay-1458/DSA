class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size(),ans=1;
        unordered_map<int,int> mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                if(mp.size()<=2){
                    ans=max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};
