class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int> ans;
        int n=temperatures.size();
        for(int i=n-1;i>=0;--i){
            if(stk.empty()){
                stk.push({temperatures[i],i});
                ans.push_back(-1);
            }
            else if(temperatures[i]<stk.top().first){
                ans.push_back(stk.top().second);
                stk.push({temperatures[i],i});
            }
            else{
                while(!stk.empty() && temperatures[i]>=stk.top().first){
                    stk.pop();
                }
                if(stk.empty()){
                    stk.push({temperatures[i],i});
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(stk.top().second);
                    stk.push({temperatures[i],i});
                }
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;++i){
            if(ans[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=ans[i]-i;
            }
        }
        return ans;
    }
};
